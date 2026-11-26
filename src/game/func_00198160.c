#include "m2c.h"
void func_0018A310(s32);
f32 func_00187770(f32, f32, f32);
s32 func_00195A30(s32);
typedef union { u32 w; u8 b[4]; } Col;
void func_001875C0(s32, s32, Col, f32, f32, f32);
void func_0017F5C0(void);
void func_001982A0(s32, f32);
void func_00185390(f32, s32, s32, s32);
extern f32 D_00201D44;
extern s32 D_002021A8;
extern s32 D_004A1450[];
extern s32 D_004A18B0[];

void func_00198160(u8 *arg0) {
    Col c;
    s32 s;

    s = D_004A1450[D_004A18B0[0]];
    func_0018A310(0xE);
    if (arg0[8] == 0x19) {
        D_00201D44 = func_00187770(D_00201D44, -0.02f, 3.5f);
    } else {
        D_00201D44 = func_00187770(D_00201D44, -2.99f, 3.5f);
    }
    if (!(D_00201D44 <= -2.99f)) {
        func_001982A0(s, D_00201D44);
    }
    if (s >= 0) {
        s32 h = func_00195A30(s);
        c.w = 0x80FFFFFF;
        func_001875C0(h, 2, c, 622.0f, 17.0f, 1.0f);
    }
    func_0017F5C0();
    func_00185390(D_00201D44, 1, D_002021A8, D_004A18B0[0]);
}
