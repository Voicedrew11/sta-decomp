#include "common.h"
void func_0018A310(s32);
f32 func_00187770(f32, f32, f32);
void func_0017F5C0(void);
void func_00199260(u8 *, f32);
extern f32 D_00201D5C;
typedef union { s32 w; Flags8 f; } FW;
extern FW D_004A28D0[];

void func_00199190(u8 *arg0) {
    func_0018A310(-1);
    if (arg0[8] == 0x16) {
        D_00201D5C = func_00187770(D_00201D5C, -0.02f, 3.5f);
    } else {
        D_00201D5C = func_00187770(D_00201D5C, -2.99f, 3.5f);
    }
    if (!D_004A28D0[0].f.f.b3) {
        func_0017F5C0();
    }
    if (!(D_00201D5C <= -2.99f)) {
        func_00199260(arg0, D_00201D5C);
    }
}
