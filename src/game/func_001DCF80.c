#include "common.h"
#include "m2c.h"
void func_001DD510(s8 *a0, s32 a1, s32 a2);

/* func_001DCF80 */
#define Col Col_func_001DCF80
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    u32 x2C;
    f32 x30, x34, x38, x3C;
} A;
void func_00181680(s32, void *, void *, void *, S*, u32);
void func_00181420(void);
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_001544C0(void);
s8 *func_00195B10(s32);
void func_001874F0(f32 x, s16 h, s8 *str, u32 a, Col col, f32 y, f32 sc);
extern S D_001F3A10 __attribute__((aligned(16)));
extern f32 D_00201E44;
extern f32 D_00201E48;
extern f32 D_00202334;
extern s16 D_0020233C;
extern s32 D_00202340;
extern f32 D_00202344;

static inline f32 u2f(u32 x) { return x; }
static inline f32 mu(u32 x, f32 k) { return x * k / 128.0f; }

void func_001DCF80(A *o, s32 idx, u32 kind) {
    f32 f;
    S s __attribute__((aligned(16)));
    Col col;

    s = D_001F3A10;
    f = D_00201E44;
    s.x = o->x30;
    s.y = o->x34;
    col.w = 0x80808080;
    f = f < 0.0f ? 0.0f : f;
    if (kind < 100) {
        col.w = o->x2C;
        col.c.a = mu(col.c.a, f);
        func_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    }
    switch (kind) {
    case 0x65:
        col.c.a = mu(col.c.a, f);
        func_001874F0(o->x38, -1, func_00195B10(0x80), 0, col, o->x3C, 0.75f);
        return;
    case 0x64:
        f = D_00201E48;
        col.w = o->x2C;
        f = f < 0.0f ? 0.0f : f;
        col.c.a = mu(col.c.a, f);
        func_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    case 0x66:
        func_00181420();
        func_001545D0();
        func_001543E0(0x42, 0x48);
        func_001544C0();
        col.w = o->x2C;
        col.c.a = col.c.a * D_0020233C / 127;
        if (D_00202334 < 30.0f) {
            col.c.r = col.c.g = col.c.b = 0x80;
        } else if (D_00202334 <= 60.0f) {
            col.c.r = col.c.g = col.c.b = 0x80;
        }
        if (D_00202340 == 0) {
            D_00202344 = D_00202344 - (D_00202344 - 32.0f) / 15.0f;
            col.c.a = D_00202344;
        } else {
            D_00202344 = u2f(col.c.a);
        }
        col.c.r = 0x96;
        col.c.g = 0xAA;
        col.c.b = 0x96;
        func_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        func_00181420();
        func_001545D0();
        func_001543E0(0x42, 0x44);
        func_001544C0();
        return;
    default:
        col.w = o->x2C;
        col.c.a = mu(col.c.a, f);
        func_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    }
}
#undef Col

/* func_001DD510 */
#define Col Col_func_001DD510
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { f32 x, y, z, w; } V4;
extern S D_001F39F0[] __attribute__((aligned(16)));
extern f32 D_002020D4;
extern s16 D_00202356;
extern s32 D_00201E4C;
void func_001875C0(s32, s32, f32, u32, f32, f32);
void func_00187960(f32, Col *);
void func_00181680(s32, void *, void *, void *, S*, u32);

void func_001DD510(s8 *a0, s32 a1, s32 a2) {
    S t __attribute__((aligned(16)));
    V4 v;
    Col col;

    t = D_001F39F0[0];
    t.x = *(f32 *)(a0 + 0x30);
    t.y = *(f32 *)(a0 + 0x34);
    col.w = 0x80808080;
    switch (a2) {
    case 0xC8:
        col.w = *(u32 *)(a0 + 0x2C);
        col.b[3] = col.b[3] * D_00202356 / 127;
        v.x = *(f32 *)(a0 + 0x0);
        v.z = *(f32 *)(a0 + 0x8);
        v.y = *(f32 *)(a0 + 0x4);
        v.w = *(f32 *)(a0 + 0xC);
        func_00187960(D_002020D4, &col);
        func_00181680(*(s32 *)(a0 + 0x28), &v, a0 + 0x10, &col, &t, a2);
        break;
    case 0xC9:
        col.b[3] = D_00202356;
        func_001875C0(D_00201E4C, 0, *(f32 *)(a0 + 0x38), col.w, *(f32 *)(a0 + 0x3C), 1.0f);
        break;
    }
}
#undef Col
