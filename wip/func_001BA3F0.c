#include "m2c.h"
typedef struct { u8 p:2; u8 v:1; } BF2;
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 p:4; u8 v:1; } BF4;
typedef struct { u8 p:6; u8 v:1; } BF6;
typedef struct { u8 p:2; u8 v:2; } BF2_2;
s32 func_001715B0(s32);
s32 func_001B9E00(s32, s32, f32);
void func_001B87C0(s8 *, u32, s32, s32, f32, f32);
void func_001BA680(s8 *, u32, f32, f32);
void func_001BA850(s8 *, f32, u32, f32);

static inline f32 u2f(u32 x) {
    return x;
}

void func_001BA3F0(s8 *p, u32 i, f32 dt, f32 x) {
    s8 *e30;
    s8 *e;
    s8 *t;
    s32 r;
    f32 a;
    f32 b;

    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    e = *(s8 **)(p + 0x180) + (i << 7);
    t = *(s8 **)(p + 0x170) + (*(u16 *)(e30 + 0x18) << 6);
    r = func_001715B0(*(s32 *)(e + 0x40));
    if (((BF2 *)(e + 0x53))->v) {
        func_001BA680(p, i, dt, x);
        return;
    }
    a = 0.00024414062f * u2f(*(u16 *)(e30 + 0x12));
    b = 0.00024414062f * u2f(*(u16 *)(e30 + 0x16));
    if (a < b) {
        b = b;
    } else {
        b = a;
    }
    if (func_001B9E00(r + 0x230, ((BF3 *)(t + 0x13))->v, b * u2f(*(u16 *)(t + 0xE)))) {
        if (!((BF6 *)(e + 0x52))->v) {
            ((BF6 *)(e + 0x52))->v = 1;
            func_001B87C0(p, i, 0xB, 0, 0.0f, 1.0f);
            return;
        }
    } else {
        ((BF6 *)(e + 0x52))->v = 0;
    }
    if ((*(u8 *)(t + 0x12) & 1) && ((BF2_2 *)(e30 + 0x24))->v == 1 && ((BF4 *)(e + 0x50))->v) {
        func_001B87C0(p, i, 0, 0x80, 0.0f, 1.0f);
        return;
    }
    func_001BA850(p, dt, i, x);
}
