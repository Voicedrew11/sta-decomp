#include "common.h"
typedef struct { s8 x0[3]; s8 x3; s32 x4; s32 x8; s32 xC; } H;
static inline s32 inner(H *h) {
    s32 c = h->xC; s32 b = h->x8; if ((u8)(h->x3 - 0x30)) return (c - (b + 1)) & ~0xF; return 0;
}
s32 Lz_StreamDone_0_00178FD0(H **p) {
    H *h;
    if (p == NULL) return 0; h = *p; if (h == NULL) return 0; return inner(h);
}
