#include "actor.h"
u32 func_0013E750(Actor *);
s16 func_0013E0C0(Actor *, u8);
u8 func_001426C0(Actor *, s16);
void func_0013C360(Actor *, s16, s32, s32, s32);
void func_0013E920(Actor *, u8);

u8 func_0013CA40(Actor *a, u8 b) {
    s16 v;
    u8 r;
    if ((u8)func_0013E750(a) == 2) {
        v = a->flags5B0.f.b0 * 32 + 0x17;
    } else if ((u8)func_0013E750(a) == 1) {
        v = a->flags5B0.f.b0 * 32 + 0x17;
    } else if (b == 0xFF) {
        v = a->flags5B0.f.b0 * 32 + 0x18;
    } else {
        v = func_0013E0C0(a, b);
        v += a->flags5B0.b & 1;
    }
    r = func_001426C0(a, v);
    if (r == 0) {
        func_0013C360(a, v, 0, 0, 2);
    }
    func_0013E920(a, 1);
    if ((u8)func_0013E750(a) == 2) {
        a->flags5B6.f.b0 = 1;
    }
    return r;
}
