#include "common.h"
extern s32 D_002023D8;
extern s32 D_002023E0;
extern s32 D_002023E8;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; s32 x20; u8 pad[0x39C]; s32 x3C0; s32 x3C4; u8 q[0x38]; } S;
extern S D_004BC380[];
void func_001D6910(s32, s32);
s32 func_001D7008(s32, s32);
s32 func_001D70A8(void);
void func_001E7C10(void) {
    s32 r;

    switch (D_002023D8) {
    case 0:
        func_001D6910(D_002023E8, D_002023E0);
        D_002023D8++;
        break;
    case 1:
        r = func_001D70A8();
        if (r == 1) {
            D_004BC380[D_002023E8].x4 = 0;
            D_004BC380[D_002023E8].x8 = 0;
            D_004BC380[D_002023E8].x10 = 0;
            D_004BC380[D_002023E8].x20 = 0;
            D_004BC380[D_002023E8].x3C0 = 0;
            D_004BC380[D_002023E8].x3C4 = 0;
        } else if (r == 3 || r == 4 || r == 0x15) {
            D_004BC380[D_002023E8].x4 = 1;
            D_004BC380[D_002023E8].x8 = 0;
            D_004BC380[D_002023E8].x10 = 0;
            D_004BC380[D_002023E8].x20 = 0;
            D_004BC380[D_002023E8].x3C0 = 0;
            D_004BC380[D_002023E8].x3C4 = 0;
        } else {
            D_004BC380[D_002023E8].x4 = 1;
            D_004BC380[D_002023E8].x8 = 1;
        }
        D_004BC380[D_002023E8].x14 = func_001D7008(D_002023E8, D_002023E0);
        D_004BC380[D_002023E8].x0 = 1;
        D_002023D8 = -1;
        D_002023E8 = !(D_002023E8 != 0);
        break;
    }
}
