#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C;
    u8 x2D;
    u8 x2E;
    u8 x2F;
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O;
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R;
typedef struct { u8 pad0[0x7C]; R *x7C; } G;
void func_00181680(s32, void *, void *, void *, S *, u32);
G *func_00189020(s32);
f32 func_0011D850(f32);
f32 func_0011DA18(f32);
extern S D_001F2700 __attribute__((aligned(16)));
extern f32 D_00202084;
extern f32 D_002020B0;
extern f32 D_002020B4;
extern f32 D_002020B8;
extern f32 D_002020BC;
extern f32 D_002020D4;
static inline void glow(O *o, R *r, S *buf, u32 mode) {
    s32 k;
    buf->x = o->x38;
    buf->y = o->x3C;
    buf->m[3] = 1.0f;
    buf->m[0] = 1.0f;
    k = 96.0f + func_0011D850(128.0f * func_0011DA18(0.05f * D_002020D4));
    o->x2C = o->x2C * k / 128;
    o->x2D = o->x2D * k / 128;
    o->x2E = o->x2E * k / 128;
    func_00181680(r->x4, r->x10, r->x20, &o->x2C, buf, mode);
}

void func_00185030(O *o, s32 a1, u32 mode, u32 a3) {
    S buf __attribute__((aligned(16)));
    R *r;
    s32 n;

    buf = D_001F2700;
    D_00202084 += 0.01f;
    if (mode < 2000) {
        buf.x = o->x30;
        buf.y = o->x34;
        if (mode == 0) {
            o->x2C = 0x40;
            o->x2D = 0x40;
            o->x2E = 0x40;
        }
        func_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
    }
    if (a3 == mode - 1500) {
        D_002020B4 = o->x38;
        D_002020B0 = o->x3C;
        r = func_00189020(0)->x7C;
        glow(o, r, &buf, mode);
    }
    if (a3 == mode - 500) {
        D_002020BC = o->x38;
        D_002020B8 = o->x3C;
        if (a3 != 4) {
            D_002020B4 = o->x38;
            D_002020B0 = o->x3C;
        }
        n = 0;
        switch (a3) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            D_002020BC -= 4.0f;
            D_002020B8 -= 4.0f;
            D_002020B4 -= 4.0f;
            D_002020B0 -= 4.0f;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            n = 1;
            break;
        }
        r = func_00189020(0)->x7C + n;
        glow(o, r, &buf, mode);
    }
}
