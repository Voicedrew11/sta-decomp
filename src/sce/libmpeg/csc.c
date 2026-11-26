/* libmpeg.a(csc.o): the IPU colour space conversion and its DMA feeders. */
#define LIBMPEG25 /* STA: SDK 2.5 */
#include <libmpeg.h>
#include <libmpeg_internal.h>
#include <eeregs.h>
#include <eekernel.h>

/* STA: SDK 2.5.  Every function takes the decoder state (MpegSys, grown in
 * 2.5: the handle sits at +0x858), the globals the DMA handlers shared are
 * records on the caller's stack, handed over as AddDmacHandler2's argument,
 * and each DMA kick runs with interrupts off. */
#define SYS_MP(p) (*(sceMpeg **)((char *)(p) + 0x858)) /* SDK 2.5 MpegSys's handle */

int AddDmacHandler2(int ch, int (*handler)(int, void *, void *), int next, void *arg);

/* the conversion's state, which the channel-3 handler advances */
typedef struct { /* field names derived */
    volatile int dma; /* chunks finished: the handler bumps it while _doCSC2 polls */
    int error;  /* the handler found the channel still busy */
    int rest;   /* macroblocks left */
    int addr;   /* the next chunk's source */
    int chunks;
} CscRec; /* derived name */

/* the reference-image store's state, which the channel-4 handler advances */
typedef struct { /* field names derived */
    int qwc;
    int addr;
} StoreRec; /* derived name */

void _doCSC(MpegSys *p, int addr, int n)
{
    int buf[8];
    int intr;

    while (*IPU_CTRL < 0) {}
    intr = DIntr();
    *D3_MADR = addr & 0x0FFFFFFF;
    *D3_QWC = n << 6;
    *D3_CHCR = 0x100;
    if (intr) {
        EIntr();
    }
    _sendIpuCommand(p, n | 0x70000000);
    buf[0] = 4;
    _dispatchMpegCallback(SYS_MP(p), buf);
    while (((*(volatile unsigned int *)D3_CHCR) >> 8) & 1) {}
    while (*IPU_CTRL < 0) {}
}

int _ch3dmaCSC(int channel, CscRec *r)
{
    *D_STAT = 8;
    r->dma++;
    if (*D3_QWC != 0 || (*D3_CHCR & 0x100) != 0) {
        r->error = 1;
        return 0;
    }
    if (r->dma < r->chunks - 1) {
        *D3_MADR = r->addr;
        *D3_QWC = 0xFFC0;
        *D3_CHCR = 0x100;
        *IPU_CMD = 0x700003FF;
        r->addr = (r->addr + 0xFFC00) & 0x0FFFFFFF;
    } else if (r->dma == r->chunks - 1) {
        r->rest -= r->dma * 1023;
        *D3_MADR = r->addr;
        *D3_QWC = r->rest << 6;
        *D3_CHCR = 0x100;
        *IPU_CMD = r->rest | 0x70000000;
    }
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
    return 0;
}

/* More than 1023 macroblocks: the conversion runs in 1023-macroblock chunks,
 * the first kicked here and the rest by _ch3dmaCSC. */
void _doCSC2(MpegSys *p, int addr, int n)
{
    int buf[8];
    CscRec rec;
    int id;
    int intr;
    int qwc = 0xFFC0; /* the first chunk's quadword count */

    rec.chunks = n / 1023 + 1;
    rec.rest = n;
    rec.addr = (addr + 0xFFC00) & 0x0FFFFFFF;
    rec.error = 0;
    rec.dma = 0;
    while (*IPU_CTRL < 0) {}
    id = AddDmacHandler2(3, (int (*)(int, void *, void *))_ch3dmaCSC, 0, &rec);
    *D_STAT = 8;
    EnableDmac(3);
    intr = DIntr();
    *D3_MADR = addr & 0x0FFFFFFF;
    *D3_QWC = qwc;
    *D3_CHCR = 0x100;
    if (intr) {
        EIntr();
    }
    *IPU_CMD = 0x700003FF;
    buf[0] = 4;
    _dispatchMpegCallback(SYS_MP(p), buf);
    while (rec.dma < rec.chunks) {}
    if (rec.error != 0) {
        _Error(p, "CSC handler error\n");
    }
    while (*IPU_CTRL < 0) {}
    DisableDmac(3);
    RemoveDmacHandler(3, id);
}

int _ch4dma(int channel, StoreRec *r)
{
    *D_STAT = 0x10;
    if (r->qwc == 0)
        return 1;
    if ((unsigned int)r->qwc > 0xFFFF) {
        *D4_MADR = r->addr;
        *D4_QWC = 0xFFFF;
        *D4_CHCR = 0x101;
        r->addr = (r->addr + 0xFFFF0) & 0xFFFFFFF;
        r->qwc -= 0xFFFF;
    } else {
        *D4_MADR = r->addr;
        *D4_QWC = r->qwc;
        *D4_CHCR = 0x101;
        r->qwc = 0;
    }
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
    return 0;
}

void _csc_storeRefImage(MpegSys *p, int *img)
{
    int buf[8];
    StoreRec rec;
    int n;
    int hid;
    int intr;

    buf[0] = 2;
    n = img[0xC / 4] * img[0x10 / 4];
    _dispatchMpegCallback(SYS_MP(p), buf);
    if (*IPU_CTRL & 0x4000) {
        *(int *)IPU_CTRL = 0x40000000;
    }
    while (*IPU_CTRL < 0) {}
    _sendIpuCommand(p, 0);
    while (*IPU_CTRL < 0) {}
    rec.addr = img[0] & 0x0FFFFFFF;
    rec.qwc = n * 24;
    if ((unsigned int)rec.qwc > 0xFFFF) {
        hid = AddDmacHandler2(4, (int (*)(int, void *, void *))_ch4dma, 0, &rec);
        *D_STAT = 0x10;
        EnableDmac(4);
        intr = DIntr();
        *D4_MADR = rec.addr;
        *D4_QWC = 0xFFFF;
        *D4_CHCR = 0x101;
        if (intr) {
            EIntr();
        }
        rec.addr = (rec.addr + 0xFFFF0) & 0x0FFFFFFF;
        rec.qwc -= 0xFFFF;
        if (n < 1024) {
            _doCSC(p, p->imageBuff, n);
        } else {
            _doCSC2(p, p->imageBuff, n);
        }
        DisableDmac(4);
        RemoveDmacHandler(4, hid);
    } else {
        intr = DIntr();
        *D4_MADR = img[0] & 0x0FFFFFFF;
        *D4_QWC = rec.qwc;
        *D4_CHCR = 0x101;
        if (intr) {
            EIntr();
        }
        rec.qwc = 0;
        if (n < 1024) {
            _doCSC(p, p->imageBuff, n);
        } else {
            _doCSC2(p, p->imageBuff, n);
        }
    }
    buf[0] = 3;
    _dispatchMpegCallback(SYS_MP(p), buf);
}
