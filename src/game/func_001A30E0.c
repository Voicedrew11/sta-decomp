#include "m2c.h"
void func_0018A310(s32);
f32 func_00187770(f32, f32, f32);
void func_001875C0(s32, s32, u32, f32, f32, f32);
s32 func_00195B10(s32);
void func_001A31E0(u8 *, f32);
extern f32 D_00201D90;
extern s32 D_004A4350[];
typedef union { u32 w; u8 b[4]; } Col;

void func_001A30E0(u8 *arg0) {
    Col c;

    func_0018A310(0xC);
    if (!(D_00201D90 <= -2.49f)) {
        func_001A31E0(arg0, D_00201D90);
    }
    if (arg0[8] == 0x1F) {
        D_00201D90 = func_00187770(D_00201D90, -0.02f, 3.5f);
        c.w = 0x80FFFFFF;
        if (D_004A4350[0] >= 0) {
            func_001875C0(func_00195B10(D_004A4350[0] + 0x8C), 2, *(u32 *)&c, 622.0f, 17.0f, 1.0f);
        }
    } else {
        D_00201D90 = func_00187770(D_00201D90, -2.99f, 3.5f);
    }
}
