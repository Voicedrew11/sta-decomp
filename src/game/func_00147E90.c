#include "m2c.h"
typedef struct { u8 pad0[0x170]; u8 **x170; } H;
typedef struct {
    u8 pad0[0x54];
    f32 x54;
    u8 pad58[4];
    f32 x5C;
    u8 pad60[4];
    f32 x64;
    u8 pad68[0x20];
    f32 x88;
    u8 pad8C[4];
    H *x90;
    u8 pad94[0x14];
    s32 xA8;
    u8 padAC[4];
    f32 xB0;
    f32 xB4;
    u8 padB8[0x5C];
    u8 b0:1;
    u8 b1:1;
} O;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; } F;
typedef union { u128 q[4]; f32 f[16]; } T;
f32 atan2f(f32, f32);
void func_00145FB0(T *, u8 *);
u8 *func_001468F0(u8 *, u32);
void func_00147710(f32, O *);

static inline u8 *target(O *o) {
    u8 **p = o->x90->x170;
    return p != 0 ? *p : 0;
}

static inline s32 is10(u16 v) {
    return v == 0x10;
}

static inline s32 is10or31(u16 v) {
    return v == 0x10 || v == 0x31;
}

static inline s32 ok(O *o) {
    u8 *s;
    u8 *e;
    u16 type;
    s32 a;
    s32 c;
    u16 sub;
    s32 b;

    s = target(o);
    if (s == 0) {
        return 0;
    }
    e = func_001468F0(s, (u32)o->x54);
    if (e == 0 || ((F *)(e + 0x138))->b6) {
        return 0;
    }
    type = *(u16 *)s;
    sub = *(u16 *)(s + 0x6D0);
    a = 0;
    if (type == 0x2F && !is10(sub) != 0) {
        a = 1;
    }
    b = 0;
    if (type == 0x43 && !is10or31(sub) != 0) {
        b = 1;
    }
    a = a + b;
    c = 0;
    if (type == 0x6C) {
        if (!is10(sub) != 0) {
            c = 1;
        } else {
            c = c;
        }
    }
    return !(a + c);
}

void func_00147E90(O *o) {
    volatile f32 ang;
    T t;
    u8 *e;

    if (!ok(o)) {
        o->x88 = (f32)(u32)(o->b1 = 0);
        return;
    }
    e = func_001468F0(target(o), (u32)o->x54);
    o->x5C = 1.0f;
    o->xB0 = o->x64;
    o->xA8 = 0;
    func_00145FB0(&t, e);
    o->xB4 = ang = atan2f(t.f[8], t.f[10]);
    func_00147710(0.0f, o);
}


