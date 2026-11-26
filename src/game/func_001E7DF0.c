#include "common.h"
void func_001D6910(s32, s32);
s32 func_001D6E48(s32, s32);                    /* extern */
void sceMcSync(s32, s32, s32 *);         /* extern */
void sceMcUnformat(s32, s32);                    /* extern */
extern s32 D_002023D8;
extern s32 D_002023E0;
extern s32 D_002023E4;
extern s32 D_004BC380[];
extern s32 D_004BC384[];
extern s32 D_004BC388[];
extern s32 D_004BC390[];
extern s32 D_004BC394[];
extern s32 D_004BC39C[];
extern s32 D_004BC3A0[];
extern s32 D_004BC740[];
extern s32 D_004BC744[];

void func_001E7DF0(void) {
    s32 sp1C;
    s32 temp_11;
    s32 temp_12;

    switch (D_002023D8) {                           /* irregular */
    case 0:
        func_001D6910(D_002023E4, D_002023E0);
        D_002023D8 += 1;
        break;
    case 1:
        sp1C = func_001D6E48(D_002023E4, 0);
        if (sp1C < 0) {
            temp_11 = D_002023E4 << 8;
            D_004BC384[temp_11] = 0;
            D_004BC388[temp_11] = 0;
            D_004BC380[temp_11] = 0;
            D_004BC390[temp_11] = 0;
            D_004BC394[temp_11] = -1;
            D_004BC39C[temp_11] = 1;
            D_002023D8 = -1;
            break;
        }
        sceMcUnformat(D_002023E4, D_002023E0);
        sceMcSync(0, 0, &sp1C);
        D_002023D8 += 1;
        break;
    case 2:
        temp_12 = D_002023E4 << 8;
        D_004BC384[temp_12] = 1;
        D_004BC388[temp_12] = 0;
        D_004BC390[temp_12] = 0;
        D_004BC3A0[temp_12] = 0;
        D_004BC740[temp_12] = 0;
        D_004BC744[temp_12] = 0;
        D_004BC39C[temp_12] = 0;
        D_002023D8 = -1;
        break;
    }
}
