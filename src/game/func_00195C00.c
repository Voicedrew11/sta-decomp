#include "m2c.h"
extern s8 D_001FD290[];
extern s8 D_001FD2A0[];
extern s8 D_001FD2B0[];
extern s8 D_001FD2C0[];
extern s8 D_001FD2D0[];
extern s8 D_001FD2E0[];
extern s8 D_001FD2F0[];
extern s8 D_001FD310[];
extern s8 * volatile D_00202158;
extern s8 *D_0020215C;
extern s8 *D_00202160;
extern s8 *D_00202164;
extern s8 *D_00202168;
extern s8 *D_0020216C;
extern s32 *D_00202170;
extern s32 D_00202174;
extern s32 *D_00202178;
extern s32 D_0020217C;
extern s8 *D_00202180;
s8 *func_00159D10(s8 *);
void func_00159DD0(s8 *, s8 *, void *, void *);

void func_00195C00(s8 *arg0) {
    u32 sp1C;

    D_00202158 = arg0;
    if (D_0020215C == NULL) {
        func_00159DD0(func_00159D10(D_001FD290), D_00202158, &D_0020215C, &sp1C);
    }
    if (D_00202164 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2A0), D_00202158, &D_00202164, &sp1C);
    }
    if (D_00202160 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2B0), D_00202158, &D_00202160, &sp1C);
    }
    if (D_00202180 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2C0), D_00202158, &D_00202180, &sp1C);
    }
    if (D_00202168 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2D0), D_00202158, &D_00202168, &sp1C);
    }
    if (D_0020216C == NULL) {
        func_00159DD0(func_00159D10(D_001FD2E0), D_00202158, &D_0020216C, &sp1C);
    }
    if (D_00202170 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2F0), D_00202158, &D_00202170, &sp1C);
        D_00202174 = *D_00202170;
    }
    if (D_00202178 == NULL) {
        func_00159DD0(func_00159D10(D_001FD310), D_00202158, &D_00202178, &sp1C);
        D_0020217C = *D_00202178;
    }
}
