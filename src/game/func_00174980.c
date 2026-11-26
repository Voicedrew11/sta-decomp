#include "common.h"
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C;
    s32 x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 x44;
    s32 x48;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } f4C;
    u8 pad4D[3];
} Buf;
typedef struct { u8 pad[0x10]; u16 x10; u16 x12; } T;
typedef struct { u8 A:2; u8 B:2; u8 C:2; u8 D:2; } Al;
typedef struct {
    u8 pad[0xC]; s16 xC; s16 xE; u8 pad10[4]; s32 x14; u8 pad18[0x10];
    Al x28; u8 x29; struct { u8 b0:1; } x2A;
} M;
typedef struct { f32 x0, x4; u8 pad8[8]; f32 x10, x14, x18, x1C; s32 x20; u8 pad24[4]; u16 x28; } P;
void memset(void *, s32, s32);
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_001544C0(void);
void func_00176BC0(s32);
void func_00155BD0(Buf *);
f32 func_0011DA18(f32);
static inline f32 u2f(u32 x) { return x; }
#define WRAP(x) (((3.1415927f + (x)) - 6.2831855f * (f32)(s32)(0.15915494f * (3.1415927f + (x))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void func_00174980(T *t, s32 flag, M *m, P *p) {
    Buf b;
    s32 im;
    f32 sx, sy, ox, oy;
    f32 c0, c1, c2, c3;
    f32 u0, u1, x0, x1;
    s32 i, j, i1m;
    u64 al;
    u64 fog;

    fog = m->x2A.b0;
    memset(&b, 0, 0x50);
    b.f4C.b0 = 1;
    b.f4C.b1 = 1;
    al = (u64)m->x28.A | ((u64)m->x28.B << 2) | ((u64)m->x28.C << 4) | ((u64)m->x28.D << 6) | ((u64)m->x29 << 32);
    if (flag == 0) {
        b.f4C.b2 = 0;
    } else {
        b.f4C.b2 = 1;
    }
    func_001545D0();
    func_001543E0(0x42, al);
    func_001543E0(0x49, fog);
    func_001544C0();
    func_00176BC0(p->x20);
    b.x44 = m->x14;
    if (p->x28 != 0) {
        sx = u2f(t->x10) / 4.0f;
        sy = u2f(t->x12) / 4.0f;
        ox = p->x18 / 4.0f;
        oy = p->x1C / 4.0f;
        for (i = 0; i < 4; i++) {
            j = 0;
            im = i % 4;
            i1m = (i + 1) % 4;
            u0 = sx * i;
            x0 = ox * i;
            u1 = sx * (i + 1);
            x1 = ox * (i + 1);
            for (; j < 4; j++) {
                c0 = func_0011DA18(WRAP(p->x10 + im));
                c1 = func_0011DA18(WRAP(p->x14 + j % 4));
                c2 = func_0011DA18(WRAP(p->x10 + i1m));
                c3 = func_0011DA18(WRAP(p->x14 + (j + 1) % 4));
                c0 *= c0;
                c2 *= c2;
                c1 *= c1;
                c3 *= c3;
                c0 *= m->xC;
                c2 *= m->xC;
                c1 *= m->xE;
                c3 *= m->xE;
                b.x0 = (s32)((0x800 - (s32)((u32)t->x10 >> 1)) + u0) << 4;
                b.x4 = (s32)((0x800 - (s32)((u32)t->x12 >> 1)) + sy * j) << 4;
                b.x8 = 0;
                b.x10 = (s32)((0x800 - (s32)((u32)t->x10 >> 1)) + u1) << 4;
                b.x14 = (s32)((0x800 - (s32)((u32)t->x12 >> 1)) + sy * (j + 1)) << 4;
                b.x18 = 0;
                b.x20 = c0 + (p->x0 + x0);
                b.x24 = c1 + (p->x4 + oy * j);
                b.x30 = c2 + (p->x0 + x1);
                b.x34 = c3 + (p->x4 + oy * (j + 1));
                func_00155BD0(&b);
            }
        }
    } else {
        b.x0 = (0x800 - (s32)((u32)t->x10 >> 1)) << 4;
        b.x4 = (0x800 - (s32)((u32)t->x12 >> 1)) << 4;
        b.x8 = 0;
        b.x10 = ((s32)((u32)t->x10 >> 1) + 0x800) << 4;
        b.x14 = ((s32)((u32)t->x12 >> 1) + 0x800) << 4;
        b.x18 = 0;
        b.x20 = p->x0;
        b.x24 = p->x4;
        b.x30 = p->x0 + p->x18;
        b.x34 = p->x4 + p->x1C;
        func_00155BD0(&b);
    }
}
