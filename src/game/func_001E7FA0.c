#include "common.h"
void func_001D6910(s32, s32);
void func_001D6BB8(s32, s32);
s32 func_001D6E48(s32, s32);
s32 func_001D70A8(void);
extern s32 D_002023B4;
extern s32 D_002023D8;
extern s32 D_002023E0;
extern s32 D_002023E4;
extern s32 D_004BC380[];
extern s32 D_004BC384[];
extern s32 D_004BC388[];
extern s32 D_004BC38C[];
extern s32 D_004BC390[];
extern s32 D_004BC394[];
extern s32 D_004BC39C[];
extern s32 D_004BC3A0[];
extern s32 D_004BC740[];
extern s32 D_004BC744[];

void func_001E7FA0(void) {
    s32 r;
    s32 t;

    switch (D_002023D8) {
    case 0:
        func_001D6910(D_002023E4, D_002023E0);
        D_002023D8 += 1;
        break;
    case 1:
        switch (func_001D70A8()) {
        case 3:
            if (++D_002023B4 >= 5) { D_002023B4 = 0; D_002023D8 += 1; }
            break;
        default:
            t = D_002023E4 << 8;
            D_004BC384[t] = 0;
            D_004BC388[t] = 0;
            D_004BC380[t] = 0;
            D_004BC390[t] = 0;
            D_004BC394[t] = -1;
            D_004BC39C[t] = 1;
            D_002023D8 = -1;
            break;
        }
        break;
    case 2:
        if (func_001D6E48(D_002023E4, 0) < 0) {
            t = D_002023E4 << 8;
            D_004BC384[t] = 0;
            D_004BC388[t] = 0;
            D_004BC380[t] = 0;
            D_004BC390[t] = 0;
            D_004BC394[t] = -1;
            D_004BC39C[t] = 1;
            D_002023D8 = -1;
            break;
        }
        func_001D6BB8(D_002023E4, D_002023E0);
        D_002023D8 += 1;
        break;
    case 3:
        r = func_001D70A8();
        if (r == 0x32) {
            t = D_002023E4 << 8;
            D_004BC388[t] = 0;
            D_002023D8 = -1;
            D_004BC39C[t] = 1;
        } else if (r != 0x33) {
            t = D_002023E4 << 8;
            D_004BC380[t] = 1;
            D_004BC384[t] = 1;
            D_004BC388[t] = 1;
            D_004BC38C[t] = 0;
            D_004BC390[t] = 1;
            D_004BC39C[t] = 0;
            D_004BC3A0[t] = 0;
            D_004BC740[t] = 0;
            D_004BC744[t] = 0;
            D_002023D8 = -1;
        }
        break;
    }
}
