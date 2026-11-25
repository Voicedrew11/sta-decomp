#include "common.h"
f32 func_0011DBF0(f32, f32);
void func_001D7D08(s32, s32, u32);
void func_001D7D58(s32, s32, u16);
extern Flags8 D_003174E0[];
static inline s32 en(void) {
    return !D_003174E0[0].f.b1 && D_003174E0[0].f.b0;
}

void func_001601C0(s32 on) {
    D_003174E0[0].f.b1 = on != 0;
    if (on) {
        if (en()) {
            func_001D7D58(0, 0, 0);
        } else {
            func_001D7D58(0, 0, on - on);
        }
        if (D_003174E0[0].f.b1 || !D_003174E0[0].f.b0) {
            func_001D7D08(0, 0, 0);
        }
        func_001D7D08(0, 0, 255.0f * func_0011DBF0(0.0f, 0.5f));
    }
}
