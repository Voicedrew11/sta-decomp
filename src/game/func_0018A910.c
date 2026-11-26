#include "m2c.h"
f32 func_0011D850(f32);
void func_00186E70(f32);
void func_00186F20(f32);
void func_00186FD0(f32);
void func_00187080(f32);
f32 func_00187770(f32, f32, f32);
extern f32 D_001F29E0[];
extern f32 D_001F29E4[];
extern f32 D_001F29E8[];
extern f32 D_001F29EC[];
extern s32 D_002020F0;

void func_0018A910(void) {
    s32 bit;
    f32 *p;

    bit = 1;
    p = D_001F29E0;
    do {
        if (D_002020F0 & bit) {
            *p = func_00187770(*p, -0.01f, 3.5f);
        } else {
            *p = func_00187770(*p, -2.89f, 3.5f);
        }
        bit += bit;
        p++;
    } while (bit < 0x10);
    if (!(func_0011D850(D_001F29E0[0] - -2.89f) <= 0.005f)) {
        func_00186F20(0.7f + D_001F29E0[0]);
    }
    if (!(func_0011D850(D_001F29E4[0] - -2.89f) <= 0.005f)) {
        func_00186E70(-D_001F29E4[0]);
    }
    if (!(func_0011D850(D_001F29E8[0] - -2.89f) <= 0.005f)) {
        func_00187080(D_001F29E8[0]);
    }
    if (!(func_0011D850(D_001F29EC[0] - -2.89f) <= 0.005f)) {
        func_00186FD0(-D_001F29EC[0]);
    }
    D_002020F0 = 0;
}
