#include "common.h"
extern f32 D_00201D8C;
extern Flags8 D_004A4340[];
extern s32 D_004A331C[];
f32 func_00187770(f32, f32, f32);
void func_0018A310(s32);
void func_0017F5C0(void);
void func_001A1550(u8 *, f32);
void func_00181420(void);
void func_00187B20(s32);
void func_0019EF60(u8 *);

void func_001A1460(u8 *a) {
    func_0018A310(-1);
    if (a[8] == 0x22) {
        D_00201D8C = func_00187770(D_00201D8C, -0.02f, 3.5f);
    } else {
        D_00201D8C = func_00187770(D_00201D8C, -2.99f, 3.5f);
    }
    if (!D_004A4340[0].f.b2) {
        func_0017F5C0();
    }
    if (!(D_00201D8C <= -2.99f)) {
        func_001A1550(a, D_00201D8C);
    }
    func_00181420();
    func_00187B20(0);
    if (D_004A331C[0]) {
        func_0019EF60(a);
    }
}
