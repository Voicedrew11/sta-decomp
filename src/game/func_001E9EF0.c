#include "common.h"
s32 DIntr(void);
s32 EIntr(void);
s32 RotateThreadReadyQueue(s32);
void sceMpegReset(void *);
s32 sceMpegGetPicture(void *, u8 *, s32);
s32 sceMpegIsEnd(void *);
extern u8 *D_004BDEC0[];
extern u8 *D_004BDEC4[];
extern volatile s32 D_004BDEC8[];
extern s32 D_004BDECC[];
extern s32 D_004BDED0[];
typedef struct { u8 pad[0xA8]; s32 xA8; } M;

static inline u8 *getbuf(void) {
    if ((u8)(D_004BDECC[0] == D_004BDED0[0]) == 0) return D_004BDEC0[0] + D_004BDEC8[0] * 0x118000; return 0;
}

s32 func_001E9EF0(M *mp) {
    s32 r = 1;
    u8 *p;
    while (!sceMpegIsEnd(mp)) {
        if (mp->xA8 == 1) { r = -1; break; }
        while ((p = getbuf()) == 0) RotateThreadReadyQueue(1);
        sceMpegGetPicture(mp, p, 0x460);
        DIntr();
        *(s32 *)(D_004BDEC4[0] + D_004BDEC8[0] * 0x35640) = 2;
        D_004BDECC[0]++;
        D_004BDEC8[0] = (D_004BDEC8[0] + 1) % D_004BDED0[0];
        EIntr();
        RotateThreadReadyQueue(1);
    }
    sceMpegReset(mp);
    return r;
}
