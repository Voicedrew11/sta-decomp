#include "common.h"
extern s32 D_002023B8;
extern s32 D_002023D8;
extern s32 D_002023DC;
extern s32 D_002023E4;
typedef struct { s32 x0; s32 x4; s32 x8; s32 pC[3]; s32 x18; s32 x1C; s32 x20; u8 p24[0x1C]; u8 x40[0x3C0]; } S;
extern S D_004BC380[];
static inline s32 st(void) { if (D_004BC380[D_002023E4].x4 == 0) return 1; if (D_004BC380[D_002023E4].x8 != 0) return 0; return 2; }

s32 SaveSys_StartRead_0_001E5F30(u8 **arg0, s32 *arg1) {
    s32 a = D_002023DC != 2; s32 z = st() == 0; s32 ok;
    ok = D_002023B8 && (a || !z);
    if (!ok) return -1;
    D_002023D8 = 0;
    D_002023DC = 2;
    D_004BC380[D_002023E4].x18 = 2; D_004BC380[D_002023E4].x1C = 2;
    if (arg0 != NULL) *arg0 = D_004BC380[D_002023E4].x40;
    if (arg1 != NULL) *arg1 = D_004BC380[D_002023E4].x20;
    return 0;
}
