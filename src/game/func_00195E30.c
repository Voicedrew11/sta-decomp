#include "m2c.h"
typedef union { u32 w; u8 b[4]; } Col;
void func_0018A310(s32);
f32 func_00187770(f32, f32, f32);
s32 func_00195900(s32);
void func_001875C0(s32, s32, Col, f32, f32, f32);
void func_0017F5C0(void);
void func_00196070(s32, f32);
void func_00195F70(f32);
s32 func_001A9EC0(s16);
extern f32 D_00201D34;
extern s32 D_004A11A0[];
extern s32 D_004A13E0[];

void func_00195E30(u8 *arg0) {
    Col c;
    s32 h;
    s32 id;

    id = D_004A11A0[D_004A13E0[0]];
    func_0018A310(0xE);
    if (arg0[8] == 0x1A) {
        D_00201D34 = func_00187770(D_00201D34, -0.02f, 3.5f);
    } else {
        D_00201D34 = func_00187770(D_00201D34, -2.99f, 3.5f);
    }
    func_0017F5C0();
    if (!(D_00201D34 <= -2.99f)) {
        func_00196070(id, D_00201D34);
        func_00195F70(D_00201D34);
    }
    h = func_00195900(id);
    c.w = 0x80FFFFFF;
    if (func_001A9EC0(id)) {
        func_001875C0(h, 2, c, 622.0f, 17.0f, 1.0f);
    }
}
