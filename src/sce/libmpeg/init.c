/* libmpeg.a(init.o): the decoder state resets, the error reporting, the
 * bitstream DMA and the sequence-level header parsers.  SAB: SDK 2.5: every
 * function takes the decoder record, which holds what SDK 2.2 kept in
 * globals, and the member has no data of its own. */
#define LIBMPEG25
#include <libmpeg.h>
#include <libmpeg_internal.h>
#include <eeregs.h>
#include <eekernel.h>
#include <stdio.h>
#include <libipu.h>

void _initSeqAgain(MpegSys *p)
{
    p->isMpeg2 = 0;
    _ipuSetMPEG1(1);
}

void _lastFrame(MpegSys *p)
{
    int frame = p->totalFrames;

    if (p->isSecondField) {
        _Error(p, "the second field is missing");
        p->isSecondField = 0;
        return;
    }
    if (p->picture_structure == 3) {
        _dispRefImage(p, p->backFrame, frame - 1);
    } else {
        _dispRefImageField(p, p->backTop, p->backBot, frame - 1);
    }
    p->isSecondField = 0;
}

/* the macroblock buffers live in scratchpad */
void _clearOnce(MpegSys *p)
{
    int v = 0x70000000;

    _ipuSetMPEG1(1);
    p->mbcont.rec[0].refBuf = v;
    p->mbcont.rec[0].ipuBuf = v + 0x1800;
    p->mbcont.rec[1].refBuf = v + 0x1B00;
    p->mbcont.rec[1].ipuBuf = v + 0x3300;
    p->mbcont.cur = 0;
}

void _clearEach(MpegSys *p)
{
    int intr;

    p->isTop32dirty = 1;
    p->sp_dcr = 0;
    intr = DIntr();
    *D_ENABLEW = *D_ENABLER | 0x10000;
    *D3_CHCR = 0;
    *D4_CHCR = 0;
    *D9_CHCR = 0;
    *D_ENABLEW = *D_ENABLER & 0xFFFEFFFF;
    if (intr) {
        EIntr();
    }
    *D3_QWC = 0;
    *D4_QWC = 0;
    *D9_QWC = 0;
    *IPU_CTRL = 0x40000000;
    sceIpuSync(0, 0);
}

void _ErrMessage(char *msg)
{
    scePrintf("[MPEG ERROR]%s\n", msg); /* SAB: SDK 2.5 prints through scePrintf */
}

void _Error1(MpegSys *p, char *fmt, int val)
{
    char buf[0x100];
    sprintf(buf, fmt, val);
    _Error(p, buf);
}

void _Error(MpegSys *p, char *msg)
{
    sceMpeg *mp = p->mp;

    if (mp != 0 && p != 0 && p->cb[0].func != 0) {
        int local[2];
        local[0] = 0;
        local[1] = (int)msg;
        _dispatchMpegCallback(mp, local);
        return;
    }
    _ErrMessage(msg);
}

/* the bitstream goes to the IPU by a DMA chain built in the record */
void _sendDataToIPU(MpegSys *p, int data, int size)
{
    long long *tags = (long long *)(((unsigned int)p->tagBuf + 15) >> 4 << 4);
    long long *tag = tags;
    int a = data;
    int n = size;
    int intr;

    while (n > 0) {
        int len = n > 0xFFF40 ? 0xFFF40 : n;
        int addr = a & 0x0FFFFFFF;
        int id;
        int qwc;

        n -= len;
        id = n != 0 ? 3 : 0;
        qwc = (len + 15) / 16;
        *tag = ((long long)addr << 32) | ((long long)id << 28) | (unsigned int)qwc;
        __asm__ __volatile__("sync");
        a += len;
        tag += 2;
    }
    FlushCache(0);
    intr = DIntr();
    *D4_TADR = (int)tags & 0x0FFFFFFF;
    *D4_QWC = 0;
    *D4_CHCR = 0x105;
    if (intr) {
        EIntr();
    }
}

int _RefImageInit(int *img, int width, int height)
{
    img[0x4 / 4] = width;
    img[0x8 / 4] = height;
    img[0xC / 4] = width >> 4;
    img[0x10 / 4] = height >> 4;
    return 1;
}

void _sequenceHeader(MpegSys *p)
{
    unsigned int v;

    p->picStructure = 0;
    v = _nextBit(p, 32);
    p->vertical_size = (v >> 8) & 0xFFF;
    p->horizontal_size = v >> 20;
    if (p->vertical_size >= 0xAF1) {
        _Error(p, "vertical size > 2800");
    }
    v = _nextBit(p, 30);
    p->vbv_buffer_size_value = (v >> 1) & 0x3FF;
    p->bit_rate_value = v >> 12;
    if ((p->load_intra_quantizer_matrix = _nextBit(p, 1)) != 0) {
        _waitIpuIdle(p);
        _sendIpuCommand(p, 0x50000000);
        _waitIpuIdle(p);
    } else {
        _setDefaultQM(p, 0x50000000, _defIQM);
    }
    if ((p->load_non_intra_quantizer_matrix = _nextBit(p, 1)) != 0) {
        _waitIpuIdle(p);
        _sendIpuCommand(p, 0x58000000);
        _waitIpuIdle(p);
    } else {
        _setDefaultQM(p, 0x58000000, _defNIQM);
    }
    _extensionAndUserData(p);
    _initSeq(p->mp);
}

void _initSeq(sceMpeg *mp)
{
    MpegSys *r = mp->sys;
    MpegHeap *heap;
    unsigned int size;
    int w, h;

    if (r->isMpeg2 == 0) {
        r->progressive_sequence = 1;
        r->chroma_format = 1;
        r->progressive_frame = 1;
        r->picture_structure = 3;
        r->frame_pred_frame_dct = 1;
        r->matrix_coefficients = 5;
    }
    r->widthMB = (r->horizontal_size + 15) >> 4;
    r->heightMB = (r->isMpeg2 != 0 && r->progressive_sequence == 0)
                      ? ((r->vertical_size + 31) >> 5) * 2
                      : (r->vertical_size + 15) >> 4;
    w = r->widthMB * 16;
    h = r->heightMB * 16;
    if (w != mp->width || h != mp->height) {
        mp->width = w;
        mp->height = h;
        heap = &r->heap;
        size = (unsigned int)(w * 0x180 * h) >> 8;
        _alalcFree(heap);
        r->frameBuff[0] = _alalcAlloc(r, heap, size, 64);
        r->frameBuff[1] = _alalcAlloc(r, heap, size, 64);
        r->frameBuff[2] = _alalcAlloc(r, heap, size, 64);
        _initRefImages(r->refFrame0, r->refFrame1, r->refFrame2, r->refTop0, r->refTop1,
                       r->refTop2, r->refBot0, r->refBot1, r->refBot2, r->frameBuff[0],
                       r->frameBuff[1], r->frameBuff[2], w, h);
        _RefImageInit(r->refFrame0, w, h);
        _RefImageInit(r->refFrame1, w, h);
        _RefImageInit(r->refFrame2, w, h);
        _RefImageInit(r->refTop0, w, h / 2);
        _RefImageInit(r->refTop1, w, h / 2);
        _RefImageInit(r->refTop2, w, h / 2);
        _RefImageInit(r->refBot0, w, h / 2);
        _RefImageInit(r->refBot1, w, h / 2);
        _RefImageInit(r->refBot2, w, h / 2);
    }
}

/* The uncached-accelerated alias of a frame buffer address, an inline helper
 * computed afresh at each of its three uses; the helper's name is ours. */
static inline int _uncachedAddr(int addr)
{
    return (addr & 0x0FFFFFFF) | 0x20000000;
}

void _initRefImages(int *frame0, int *frame1, int *frame2, int *top0, int *top1, int *top2,
                    int *bot0, int *bot1, int *bot2, int y, int cb, int cr, int width, int height)
{
    int size = width * height;

    *frame0 = _uncachedAddr(y);
    *frame1 = _uncachedAddr(cb);
    *frame2 = _uncachedAddr(cr);
    *top0 = _uncachedAddr(y);
    *top1 = _uncachedAddr(cb);
    *top2 = _uncachedAddr(cr);
    *bot0 = _uncachedAddr(y + size / 512 * 384);
    *bot1 = _uncachedAddr(cb + size / 512 * 384);
    *bot2 = _uncachedAddr(cr + size / 512 * 384);
}

void _setDefaultQM(MpegSys *p, int cmd, unsigned char *qm)
{
    int buf[8];
    int intr;

    buf[0] = 2;
    _dispatchMpegCallback(p->mp, buf);
    _waitIpuIdle(p);
    *IPU_CMD = 0;
    _waitIpuIdle(p);
    /* channel 4 (to IPU) sends the four quadwords of the matrix */
    intr = DIntr();
    *D4_MADR = (int)qm & 0x0FFFFFFF;
    *D4_QWC = 4;
    *D4_CHCR = 0x101;
    if (intr) {
        EIntr();
    }
    _sendIpuCommand(p, cmd);
    _waitIpuIdle(p);
    buf[0] = 3;
    _dispatchMpegCallback(p->mp, buf);
}

void _sequenceExtension(MpegSys *p)
{
    unsigned int v;
    int horiz_ext;
    int vert_ext;
    int bit_rate_ext;
    int vbv_ext;
    int profile;

    p->isMpeg2 = 1;
    _ipuSetMPEG1(0);
    v = _nextBit(p, 28);
    bit_rate_ext = (v >> 1) & 0xFFF;
    p->chroma_format = (v >> 17) & 3;
    vert_ext = (v >> 13) & 3;
    horiz_ext = (v >> 15) & 3;
    if (p->chroma_format != 1) {
        _Error(p, "_chroma_format needs to be 1: 420");
    }
    p->progressive_sequence = (v >> 19) & 1;
    profile = v >> 20;
    v = _nextBit(p, 16);
    vbv_ext = v >> 8;
    if (profile != 0x48 && profile != 0x58 && profile != 0x44) {
        _Error(p, "Unsupported profile/level");
    }
    p->horizontal_size = (horiz_ext << 12) | (p->horizontal_size & 0xFFF);
    p->vertical_size = (vert_ext << 12) | (p->vertical_size & 0xFFF);
    p->bit_rate_value = p->bit_rate_value + (bit_rate_ext << 18);
    p->vbv_buffer_size_value = p->vbv_buffer_size_value + (vbv_ext << 10);
}

void _sequenceDisplayExtension(MpegSys *p)
{
    _nextBit(p, 3);
    if (_nextBit(p, 1) != 0) {
        _nextBit(p, 8);
        _nextBit(p, 8);
        p->matrix_coefficients = _nextBit(p, 8);
    }
    p->display_horizontal_size = _nextBit(p, 14);
    _nextBit(p, 1);
    p->display_vertical_size = _nextBit(p, 14);
}

void _sequenceScalableExtension(MpegSys *p)
{
    _Error(p, "_sequenceScalableExtension() is not implemented");
}

void _unknown_extension(MpegSys *p)
{
    _Error(p, "Unknown Extension");
}

void _pictureSpatialScalableExtension(MpegSys *p)
{
    _Error(p, "_pictureSpatialScalableExtension is not supported");
}

void _pictureTemporalScalableExtension(MpegSys *p)
{
    _Error(p, "_pictureTemporalScalableExtension is not supported");
}
