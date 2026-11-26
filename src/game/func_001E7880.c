#include "common.h"
extern s32 D_002023D8;
extern s32 D_002023E0;
extern s32 D_002023E4;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; s32 x20; u8 pad24[0x1C]; s8 x40[0x380]; s32 x3C0; s32 x3C4; u8 q[0x38]; } S;
extern S D_004BC380[];
extern s8 D_00201760[];
extern s8 D_00201770[];
extern s8 D_004BCB80[];
extern s8 D_004BCBC0[];
void func_001D6910(s32, s32);
s32 func_001D6E48(s32, s32);
s32 func_001D7008(s32, s32);
s32 func_001D70A8(void);
s32 func_001D7098(void);
void func_001D6958(u32, u32, s8 *, s32, s32, s8 *);
void func_001E8310(s32, s32 *, s32 *);
void sprintf(s8 *, s8 *, s8 *);

void func_001E7880(void) {
    s32 r; s32 c;

    switch (D_002023D8) {
    case 0:
        func_001D6910(D_002023E4, D_002023E0);
        D_002023D8++;
        break;
    case 1:
        r = func_001D70A8();
        D_004BC380[D_002023E4].x4 = 1;
        D_004BC380[D_002023E4].x8 = 1;
        switch (r) {
        case 3:
            D_004BC380[D_002023E4].x8 = 0;
        }
        r = func_001D6E48(D_002023E4, 0);
        if (r < 0) {
            D_004BC380[D_002023E4].x4 = 0;
            D_004BC380[D_002023E4].x8 = 0;
        } else if (r == 2) {
            D_004BC380[D_002023E4].x4 = 1;
            D_004BC380[D_002023E4].x8 = 0;
        }
        D_004BC380[D_002023E4].x14 = func_001D7008(D_002023E4, D_002023E0);
        D_004BC380[D_002023E4].x0 = 1;
        if (D_004BC380[D_002023E4].x8 == 0) {
            D_002023D8 = -1;
            D_004BC380[D_002023E4].x1C = 1;
            break;
        }
        func_001D6958(D_002023E4, D_002023E0, D_00201760, 0, 0xE, D_004BCBC0);
        D_002023D8++;
        break;
    case 2:
        if (func_001D70A8() == 0x64) {
            D_002023D8 = -1;
            D_004BC380[D_002023E4].x1C = 1;
            break;
        }
        c = func_001D7098() > 0; D_004BC380[D_002023E4].xC = c;
        if (c == 0) {
            D_002023D8 = -1;
            D_004BC380[D_002023E4].x10 = 1;
            D_004BC380[D_002023E4].x1C = 0;
            break;
        }
        sprintf(D_004BCB80, D_00201770, D_00201760);
        func_001D6958(D_002023E4, D_002023E0, D_004BCB80, 0, 0xE, D_004BC380[D_002023E4].x40);
        D_002023D8++;
        break;
    case 3:
        if (func_001D70A8() == 0x64) {
            D_002023D8 = -1;
            D_004BC380[D_002023E4].x1C = 1;
            break;
        }
        r = func_001D7098();
        D_004BC380[D_002023E4].x20 = r;
        D_004BC380[D_002023E4].x10 = 1;
        func_001E8310(D_002023E4, &D_004BC380[D_002023E4].x3C0, &D_004BC380[D_002023E4].x3C4);
        D_004BC380[D_002023E4].x1C = 0;
        D_002023D8 = -1;
        break;
    }
}
