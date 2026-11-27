#include "common.h"
extern s32 D_002023B8;
extern s32 D_002023CC;
extern s32 D_002023D0;
extern s32 D_002023D4;
extern s32 D_002023D8;
extern s32 D_002023DC;
extern s32 D_002023E4;
typedef struct { s32 x0; s32 x4; s32 x8; s32 pC[3]; s32 x18; s32 x1C; u8 pad[0x3A0]; s32 x3C0; u8 q[0x3C]; } S;
extern S D_004BC380[];
static inline s32 st(void) { if (D_004BC380[D_002023E4].x4 == 0) return 1; if (D_004BC380[D_002023E4].x8 != 0) return 0; return 2; }
s32 SaveSys_StartWrite_0_001E6170(s32 arg0, s32 arg1, s32 arg2) {
    s32 a; s32 z; s32 ok;
    if (arg0 < -1 || arg0 > 7) return -3;
    a = D_002023DC != 2; z = st() == 0;
    ok = D_002023B8 && (a || !z);
    if (!ok) return -1;
    if (!((D_004BC380[D_002023E4].x3C0 >> (arg0 + 4)) & 1)) return -2;
    D_002023D0 = arg1;
    D_002023D4 = arg0;
    D_002023CC = arg2;
    D_002023D8 = 0;
    D_002023DC = 6;
    D_004BC380[D_002023E4].x18 = 6; D_004BC380[D_002023E4].x1C = 2;
    return 0;
}

