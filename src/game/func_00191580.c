#include "m2c.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    u64 a, b;
    f32 x, y;
} S191110;
typedef struct { f32 x, y, z, w; } Vec;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A191110;
void func_00181680(s32, Vec *, Vec *, Col *, S191110 *, s32);
void func_00187B20(s32);
void func_00181420(void);
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_001544C0(void);
void func_001256E0(s8 *, s8 *, ...);
void func_001874F0(f32, f32, f32, s32, s8 *, s32, u32);
extern S191110 D_001F2C10 __attribute__((aligned(16)));
extern s8 D_001FD118[];
extern s8 D_001FD120[];

void func_00191580(A191110 *o, u32 kind, s32 alpha) {
    Col col;
    S191110 s __attribute__((aligned(16)));
    Vec v10;
    Vec v0;
    s8 buf[0x400];
    f32 f;

    s = D_001F2C10;
    switch (kind) {
    case 0xCD:
        col.c.b = 0x40;
        col.c.r = 0x40;
        col.c.a = 0x40;
        f = 0.015625f * alpha;
        col.c.g = 0x60;
        func_00187B20(0);
        func_00181420();
        func_001545D0();
        func_001543E0(0x42, 0x48);
        func_001544C0();
        s.x = o->x30;
        s.y = o->x34;
        v10 = o->v10;
        v0 = o->v0;
        o->v10.z = o->v10.z * f;
        o->v0.z = v0.x + f * (v0.z - v0.x);
        func_00181680(o->x28, &o->v0, &o->v10, &col, &s, 0);
        o->v10 = v10;
        o->v0 = v0;
        func_00187B20(0);
        func_00181420();
        func_001545D0();
        func_001543E0(0x42, 0x44);
        func_001544C0();
        break;
    case 0xCE:
        s.x = o->x30;
        s.y = o->x34;
        func_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, 0);
        break;
    case 0xCF:
        col.c.r = 0x80 - alpha;
        col.c.g = alpha + 0x80;
        col.c.b = alpha + 0x80;
        col.c.a = o->x2C.c.a * 2;
        if (alpha < 0x40) {
            func_001256E0(buf, D_001FD118);
        } else {
            func_001256E0(buf, D_001FD120);
        }
        func_001874F0(o->x38, o->x3C, 0.83333331f, -1, buf, 0, col.w);
        func_00187B20(0);
        break;
    }
}
