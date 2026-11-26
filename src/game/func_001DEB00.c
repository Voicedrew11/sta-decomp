#include "m2c.h"
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xB]; s8 b3F; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { L *l; } O;
O *func_00189050(s32);
s8 *func_00189020(s32);
void func_00187B20(s32);
f32 func_00187460(V2 *, V2 *);
f32 func_0011DA18(f32);
f32 func_0011D778(f32);
f32 sqrtf(f32);
void func_001DED50(void);
void func_001829B0(Ent *, s8 *, void (*)(void), s32);
extern s32 D_00202378;
extern s32 D_0020237C;

void func_001DEB00(s32 arg, s32 arg1, f32 ang) {
    u32 i;
    L *l;
    s8 *base;
    Ent e;
    V2 q;
f32 d, a, t, dx, dy;
    s32 c;
    l = func_00189050(6)->l;
    base = func_00189020(6);
    func_00187B20(0);
    D_00202378 = arg1;
    D_0020237C = arg;
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 108.0f;
            p.y = 72.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 108.0f;
        dy = e.y - 72.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang;
        c = (s32)(256.0f * (ang / -2.99f)) + 0x80;
        if (c < 0) c = 0;
        if (c > 0x80) c = 0x80;
        e.b3F = c;
        e.x = 108.0f + d * func_0011DA18(a);
        e.y = 72.0f + d * func_0011D778(a);
        }
        func_001829B0(&e, base + l->p[i].idx * 8, func_001DED50, arg);
    }
}
