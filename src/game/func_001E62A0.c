#include "common.h"
extern s32 D_002023B8;
extern s32 D_002023CC;
extern s32 D_002023D0;
extern s32 D_002023D4;
extern s32 D_002023D8;
extern s32 D_002023DC;
extern s32 D_002023E4;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; u8 pad[0x3A0]; s32 x3C0; u8 pad2[0x3C]; } S;
extern S D_004BC380[];
static inline s32 st(void) { if (D_004BC380[D_002023E4].x4 == 0) return 1; if (D_004BC380[D_002023E4].x8 != 0) return 0; return 2; }

s32 func_001E62A0(s32 a0, s32 a1, s32 a2) {
    s32 a; s32 z; s32 ok; s32 n; s32 lim;
    if (a0 < -1 || a0 > 7) return -3;
    a = D_002023DC != 2; z = st() == 0;
    ok = D_002023B8 && (a || !z);
    if (!ok) return -1;
    if (!((D_004BC380[D_002023E4].x3C0 >> (a0 + 4)) & 1)) {
        lim = D_004BC380[D_002023E4].x14;
        n = a2 + 0x800;
        if (D_004BC380[D_002023E4].xC == 0) n += 0x15E70;
        if (n >= lim << 10) return -2;
    }
    D_002023D0 = a1;
    D_002023D4 = a0;
    D_002023CC = a2;
    D_002023D8 = 0;
    D_002023DC = 5;
    D_004BC380[D_002023E4].x18 = 5; D_004BC380[D_002023E4].x1C = 2;
    return 0;
}
