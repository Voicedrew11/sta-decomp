#include "m2c.h"
typedef union { u64 d; u32 w[2]; } T;
s8 *func_001C9B60(void);
s8 *func_001C9BA0(void);
void func_001CA1C0(s32);
void func_00131600(s32, s32);
void func_0015FD90(f32, f32, f32, f32, f32);
extern T D_00201E30;
extern u32 D_00201E94;

void func_001C9FF0(void) {
    T t;
    s8 *s0;
    s8 *p;
    u32 v;
    s8 a;
    s16 *q;
    s32 n;
    s32 m;
    s32 vol;

    s0 = func_001C9B60();
    t = D_00201E30;
    if (s0 != 0) {
        p = func_001C9BA0();
        if (*(s32 *)(p + 0x58) == 0 && *(u32 *)(p + 0x38) != 0) {
            v = *(u32 *)(p + 0x38) >> 24;
        } else {
            v = 0;
        }
        if (v != 0 && D_00201E94 % t.w[v - 1] == 0) {
            func_001CA1C0(2);
        }
        a = s0[0x420];
        if (a != -1) {
            if (D_00201E94 % t.w[s0[0x421] - 1] == 0) {
                func_001CA1C0(a);
            }
        }
        q = *(s16 **)(s0 + 0x390);
        n = 0.3f * q[0];
        if (n == 0) {
            n = 1;
        }
        m = q[2];
        if (m <= n) {
            vol = 0x7F - (m << 6) / n;
            if (D_00201E94 % (m * 10 / n + 20) == 0) {
                func_00131600(300, vol);
                func_0015FD90(0.8f, 1.0f, 0.0f, 0.2f, 2.0f);
            }
        }
    }
}
