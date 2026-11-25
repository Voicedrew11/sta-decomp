#include "m2c.h"
void func_00128A60(void *, s32, s32, s32);
s32 func_00174620(void *, void *);
void func_0015ED70(void);
void func_00146C00(void);
void func_00159DD0(s32, s8 *, void *, s32 *);
void func_0016AE30(void);
void func_001E1200(void);
void func_0016AB50(void);
extern s32 D_00222B64[];
extern s32 D_00222B84[];
extern s8 D_0042D850[];
extern s8 D_0042D7E0[];
extern s8 *D_00201FC0;
extern u32 D_00201FAC;
extern s8 *D_00201FD0;
extern s8 *D_00201FD4;
extern s32 D_00201FE8;

s32 func_0016AD10(s32 a0, u32 a1, s32 a2) {
    s32 t;
    func_00128A60(D_0042D850, D_00222B64[0], D_00222B84[0], 0x200);
    if (!func_00174620(D_0042D7E0, D_0042D850)) {
        return 0;
    }
    D_00201FC0 = (s8 *)a0;
    D_00201FAC = a1 / 390;
    D_00201FD0 = D_00201FC0 + D_00201FAC * 0x120;
    D_00201FD4 = D_00201FD0 + D_00201FAC * 0x60;
    func_0015ED70();
    func_00146C00();
    func_00159DD0(a2, D_0042D850, &D_00201FE8, &t);
    func_0016AE30();
    func_001E1200();
    func_0016AB50();
    return 1;
}
