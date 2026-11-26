/* libdma.a.  The archive's member boundaries in this build are not known,
 * so this file is the archive's whole run. */
#include <stdio.h>
#include <eeregs.h>
#include <libdma.h>
#include <libvu0_internal.h>
#include <eekernel.h>

/* SAB: SDK 2.5's sections: .data holds the build stamp and dch, .rodata
 * (after the timeout message) the four constant tables, and .bss
 * sceDmaCurrentEnv.  sceDmaDebugMode is gone. */
/* libdma.a's build stamp, exactly sixteen characters with no terminator. */
static char sceDmaVersion[16] = "PsIIlibdma  2500"; /* derived name */

/* The ten channel register blocks, VIF0 to toSPR. */
DmaChan *dch[10] = {
    (DmaChan *)D0_CHCR, (DmaChan *)D1_CHCR, (DmaChan *)D2_CHCR, (DmaChan *)D3_CHCR,
    (DmaChan *)D4_CHCR, (DmaChan *)D5_CHCR, (DmaChan *)D6_CHCR, (DmaChan *)D7_CHCR,
    (DmaChan *)D8_CHCR, (DmaChan *)D9_CHCR,
};

/* An uninitialized global, common under ee-gcc; mwldps2 gave it the member's
   .bss, which ld only does for a .bss symbol. */
DmaEnv sceDmaCurrentEnv __attribute__((section(".bss")));

/* SAB: SDK 2.5's libdma waits through these helpers, which pause a channel
   that times out, and maps scratchpad addresses to the DMAC's SPR flag. */
int sceDmaPause(DmaChan *ch);

static void _sceDmaWait(DmaChan *ch) /* derived name */
{
    int n = 0x1000000;

    while (ch->chcr & 0x100) {
        if (--n < 0) {
            scePrintf("libdma: sync timeout\n");
            sceDmaPause(ch);
        }
    }
}

static void _sceDmaWaitAddr(DmaChan *ch, unsigned int addr, int n) /* derived name */
{
    n = n ? n : 0x1000000;
    while (*(volatile unsigned int *)&ch->madr < addr) {
        if (--n < 0) {
            scePrintf("libdma: sync timeout\n");
            sceDmaPause(ch);
        }
    }
}

/* The constant tables follow the timeout message in the member's .rodata. */
/* Which channels sceDmaReset clears: all but the three SIF channels. */
static const int resetChan[10] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 1}; /* derived name */

/* sceDmaPutEnv's lookups from the DmaEnv's first three bytes to the D_CTRL
 * MFD, STS and STD field codes. */
static const unsigned char mfdCode[16] = {0, 0, 0, 3, 0, 1, 0, 0, 2}; /* derived name */

static const unsigned char stsCode[16] = {0, 1, 2, 0, 0, 0, 3}; /* derived name */

static const unsigned char stdCode[16] = {0, 2, 3}; /* derived name */

static unsigned int _sceDmaAddr(unsigned int addr) /* derived name */
{
    if ((addr >> 28) == 7) {
        addr &= 0x0FFFFFFF;
        addr |= 0x80000000;
    }
    return addr;
}

static void _sceDmaClear(void *p, int n) /* derived name */
{
    char *c = p;

    while (n--) {
        *c++ = 0;
    }
}

DmaChan *sceDmaGetChan(unsigned int id)
{
    if (id < 0xA) {
        return dch[id];
    }
    return 0;
}

int sceDmaReset(int mode)
{
    DmaEnv env;
    int old;
    int i;

    old = *D_CTRL & 1;
    for (i = 0; i < 10; i++) {
        if (resetChan[i] != 0) {
            int *ch = (int *)dch[i];
            ch[0x00 / 4] = 0;
            ch[0x30 / 4] = 0;
            ch[0x10 / 4] = 0;
            ch[0x50 / 4] = 0;
            ch[0x40 / 4] = 0;
            ch[0x80 / 4] = 0;
        }
    }
    *D_STAT = 0xFF1F;
    *(int *)D_STAT = *D_STAT & 0xFF1F0000;
    _sceDmaClear(&env, 0x14);
    sceDmaPutEnv(&env);
    if (mode == 1) {
        *D_CTRL = *D_CTRL | 1;
    }
    return old;
}

int sceDmaPutEnv(DmaEnv *env)
{
    int ctrl = *D_CTRL;
    int pcr = *D_PCR;
    int sqwc = *D_SQWC;
    int rbor = *D_RBOR;
    int rbsr = *D_RBSR;

    if (env->mfd >= 10) {
        return -1;
    }
    if (env->sts >= 10) {
        return -2;
    }
    if (env->std >= 10) {
        return -3;
    }
    if (env->rcyc >= 7) {
        return -4;
    }
    ctrl = (ctrl & 0xFFFFFFCF) | (mfdCode[env->mfd] << 4);
    ctrl = (ctrl & 0xFFFFFF3F) | (stsCode[env->sts] << 6);
    ctrl = (ctrl & 0xFFFFFFF3) | (stdCode[env->std] << 2);
    if (env->rcyc != 0) {
        ctrl |= 2;
        ctrl = (ctrl & 0xFFFFFCFF) | ((env->rcyc - 1) << 8);
    } else {
        ctrl &= 0xFFFFFFFD;
    }
    pcr = (env->cde << 16) | env->cpc;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbor = (int)env->rbadr;
    rbsr = env->rbsize;
    *D_CTRL = ctrl;
    *D_PCR = pcr;
    *D_SQWC = sqwc;
    *D_RBOR = rbor;
    *D_RBSR = rbsr;
    sceDmaCurrentEnv = *env;
    return 0;
}

DmaEnv *sceDmaGetEnv(DmaEnv *env)
{
    *env = sceDmaCurrentEnv;
    return env;
}

/* 0x1000E060 is the DMAC stall address register (D_STADR). */
int sceDmaPutStallAddr(unsigned int addr)
{
    int old = *D_STADR;

    *D_STADR = addr;
    return old;
}

void sceDmaSend(DmaChan *ch, unsigned int addr)
{
    addr = _sceDmaAddr(addr);
    _sceDmaWait(ch);
    if ((unsigned int)ch->tadr != 0xFFFFFFFF) {
        ch->tadr = addr;
    }
    ch->qwc = 0;
    ch->chcr = (ch->chcr & ~0xC) | 0x105;
}

void sceDmaSendN(DmaChan *ch, unsigned int addr, int size)
{
    addr = _sceDmaAddr(addr);
    _sceDmaWait(ch);
    if ((unsigned int)ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    ch->chcr = (ch->chcr & ~0xC) | 0x101;
}

void sceDmaSendI(DmaChan *ch, unsigned int addr, int size)
{
    addr = _sceDmaAddr(addr);
    _sceDmaWait(ch);
    if ((unsigned int)ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    ch->chcr = (ch->chcr & ~0xC) | 0x109;
}

void sceDmaRecv(DmaChan *ch)
{
    _sceDmaWait(ch);
    ch->qwc = 0;
    ch->chcr = ((((ch->chcr & ~0xC) | 4) & ~1) | 0x100);
}

void sceDmaRecvN(DmaChan *ch, unsigned int addr, int size)
{
    int c;

    addr = _sceDmaAddr(addr);
    _sceDmaWait(ch);
    if ((unsigned int)ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    c = ch->chcr;
    c &= ~0xC;
    c &= ~1;
    c |= 0x100;
    ch->chcr = c;
}

void sceDmaRecvI(DmaChan *ch, unsigned int addr, int size)
{
    addr = _sceDmaAddr(addr);
    _sceDmaWait(ch);
    if ((unsigned int)ch->madr != 0xFFFFFFFF) {
        ch->madr = addr;
    }
    ch->qwc = size;
    ch->chcr = (((ch->chcr & ~0xC) | 8) & ~1) | 0x100;
}

int sceDmaSync(DmaChan *ch, int mode, int n)
{
    if (mode == 1) {
        return ((unsigned int)ch->chcr >> 8) & 1;
    }
    _sceDmaWait(ch);
    return 0;
}

int sceDmaWatch(DmaChan *ch, unsigned int addr, int mode, int n)
{
    if (mode == 1) {
        return (unsigned int)ch->madr < addr;
    }
    _sceDmaWaitAddr(ch, addr, n);
    return 0;
}

/* SAB: SDK 2.5 stops a channel with the DMAC's channel enable held */
int sceDmaPause(DmaChan *ch)
{
    int intr;
    int en;
    int v;

    intr = DIntr();
    en = *D_ENABLER;
    if (!(en & 0x10000)) {
        *D_ENABLEW = en | 0x10000;
    }
    *D_CTRL;
    v = ch->chcr;
    ch->chcr = v & 0xFFFFFEFF;
    *D_ENABLEW = en;
    if (intr) {
        EIntr();
    }
    return v;
}

int sceDmaRestart(DmaChan *ch, int chcr)
{
    int v = ch->chcr;

    ch->chcr = chcr;
    return ((unsigned int)v >> 8) & 1;
}
