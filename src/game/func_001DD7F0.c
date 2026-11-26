#include "m2c.h"
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { u8 pad[0x28]; L *l; } O;
O *func_00189050(s32);
s8 *func_00189020(s32);
void func_00187B20(s32);
f32 func_00187460(V2 *, V2 *);
f32 func_0011DA18(f32);
f32 func_0011D778(f32);
f32 sqrtf(f32);
void func_001DDA20(void);
void func_001829B0(Ent *, s8 *, void (*)(void), s32);
extern s32 D_00202378;

void func_001DD7F0(s32 arg, s32 arg1, f32 ang) {
    u32 i;
    L *l;
    s8 *base;
    Ent e;
    V2 q;
f32 d, a, t, dx, dy;
    l = func_00189050(2)->l;
    base = func_00189020(2);
    func_00187B20(0);
    if (arg1 == -1) {
        D_00202378 = -1;
    } else {
        D_00202378 = arg1;
    }
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang / 2.0f;
        e.x = 735.0f + d * func_0011DA18(a);
        e.y = 129.0f + d * func_0011D778(a);
        }
        func_001829B0(&e, base + l->p[i].idx * 8, func_001DDA20, arg);
    }
}
