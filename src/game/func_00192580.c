#include "m2c.h"
typedef struct { u8 pad[0x2C]; f32 x2C; f32 x30; u8 pad34[8]; u8 c[4]; } Ent;
typedef struct { u32 n; Ent *tbl; } Tbl;
typedef struct { s32 x0; Tbl *t; } Res;
Res *func_00189050(s32);
static inline f32 u2f(u32 x) { return x; }

void func_00192580(f32 *a0, f32 *a1, u8 *a2, f32 t) {
    s32 i;
    Tbl *tb;
    Ent a;
    Ent b;
    f32 f;
    f32 g;
    f32 x;
    f32 y;

    i = (s32)t;
    tb = func_00189050(4)->t;
    a = tb->tbl[i % tb->n];
    b = tb->tbl[(i + 1) % tb->n];
    f = t - (f32)i;
    g = 1.0f - f;
    *a0 = a.x2C * f + b.x2C * g;
    *a1 = a.x30 * f + b.x30 * g;
    x = u2f(a.c[0]); y = u2f(b.c[0]); a2[0] = (s32)(x * f + y * g);
    x = u2f(a.c[1]); y = u2f(b.c[1]); a2[1] = (s32)(x * f + y * g);
    x = u2f(a.c[2]); y = u2f(b.c[2]); a2[2] = (s32)(x * f + y * g);
    x = u2f(a.c[3]); y = u2f(b.c[3]); a2[3] = (s32)(x * f + y * g);
    if (a2[0] == 0x7F) a2[0] = 0x80;
    if (a2[1] == 0x7F) a2[1] = 0x80;
    if (a2[2] == 0x7F) a2[2] = 0x80;
    if (a2[3] == 0x7F) a2[3] = 0x80;
}
