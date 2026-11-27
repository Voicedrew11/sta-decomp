#include "m2c.h"
void func_00175C80(void);
void func_001643B0(void);
void func_0015DD90(void);
void func_0015BCA0(void);
void func_0015C8D0(void);
void func_00159A60(void);
void func_00159400(f32, void *);
s32 func_00159650(s32);
s32 func_00159620(s32);
s32 func_001595C0(s32);
s32 func_00159590(s32);
void func_001595F0(s32);
void func_00129EE0(void *);
void func_00181240(void);
void func_00160300(void);
void func_00128A60(void *, s32, s32, s32);
void func_00174620(void *, void *);
void func_0016AD10(s32, s32, s32);
void func_0016AB50(void);
void func_00128460(void *, s32);
void func_00169790(void);
void func_001B7470(void *, s32);
void func_001A82B0(void *, s32);
void func_001AF970(void *, s32);
void func_001AB290(s32);
u8 func_001AA750(void);
void func_0012AC00(s32);
u8 func_001A9470(void);
u8 func_001A9480(void);
u8 func_001A9460(void);
void func_0012C6C0(s32);
void func_0012C730(s32);
void func_0012DA60(s32);
extern s32 D_00201C10;
extern s32 D_00201C34;
extern s32 D_00201C5C;
extern s32 D_00201EA4;
extern s32 D_00201EAC;
extern s8 D_00222790[];
extern s32 D_00222A30[];
extern s32 D_00222A34[];
extern s32 D_00222A38[];
extern s32 D_00222A3C[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s8 D_00222A80[0x70];
extern s8 D_00222AF0[];
extern s8 D_00222B20[];
extern s32 D_00222B5C[];
extern s32 D_00222B60[];
extern s32 D_00222B7C[];
extern s32 D_00222B80[];
extern s8 D_003139A0[];

void func_0012B120(s32 arg0) {
    s32 v;
    func_00175C80();
    func_001643B0();
    func_0015DD90();
    func_0015BCA0();
    func_0015C8D0();
    func_00159A60();
    func_00159400(3.0f, D_003139A0);
    D_00222A30[0] = func_00159650(1);
    D_00222A34[0] = func_00159620(0);
    D_00222A38[0] = func_001595C0(1);
    D_00222A3C[0] = func_00159590(0);
    func_001595F0(1);
    func_00129EE0(D_00222790);
    func_00181240();
    func_00160300();
    D_00201C5C = 0x80000000;
    func_00128A60(D_00222AF0, D_00222B5C[0], D_00222B7C[0], 0x400);
    func_00174620(D_00222A80, D_00222AF0);
    if (D_00201EAC == 0) {
        func_0016AD10(D_00222B60[0], D_00222B80[0], 0x52BC6CE4);
        D_00201EAC = 1;
    }
    func_0016AB50();
    func_00128460(D_00222AF0, -1);
    func_00128460(D_00222B20, -1);
    func_00169790();
    func_001B7470(D_00222AF0, D_00201C10);
    func_001A82B0(D_00222AF0, D_00201C10);
    func_001AF970(D_00222AF0, D_00201C10);
    if (D_00201EA4 == 0) {
        func_001AB290(D_00201C34);
    } else {
        arg0 = func_001AA750();
    }
    func_0012AC00(arg0);
    v = func_001A9470() * 2;
    if (v > 0x7F) v = 0x7F;
    func_0012C6C0(v);
    v = func_001A9480() * 2;
    if (v > 0x7F) v = 0x7F;
    func_0012C730(v);
    func_0012DA60(func_001A9460());
}
