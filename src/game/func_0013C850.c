#include "actor.h"
u32 func_0013E750(Actor *);
u8 func_00142530(Actor *, s16);
void func_0013C360(Actor *, s16, s32, s32, s32);
void func_0013E920(Actor *, u8);
s16 func_0013E0C0(Actor *, u8);
u8 func_001425F0(Actor *, u8, s32);

u8 func_0013C850(Actor *a) {
    u8 r;
    s16 v;
    v = (a->flags5B0.f.b0 << 5) + 0x19;
    if ((u8)func_0013E750(a) == 2) {
        v = (a->flags5B0.f.b0 << 5) + 0x17;
        a->flags5B6.f.b0 = 1;
    } else if ((u8)func_0013E750(a) == 1) {
        v = (a->flags5B0.f.b0 << 5) + 0x17;
    }
    r = func_00142530(a, v);
    if (r == 0) {
        func_0013C360(a, v, 0, 0, 2);
    }
    func_0013E920(a, 1);
    return r;
}

u8 func_0013C950(Actor *a, u8 b, u8 c) {
    u8 r;
    s16 v;
    if (b == 0xFF) {
        v = (a->flags5B0.f.b0 << 5) + 0x18;
    } else {
        v = func_0013E0C0(a, b);
        v += (s16)(a->flags5B0.f.b0 + 2 + c * 2);
    }
    r = func_001425F0(a, v, (u8)b);
    if (r == 0) {
        func_0013C360(a, v, 0, 0, 2);
    }
    func_0013E920(a, 1);
    return r;
}
