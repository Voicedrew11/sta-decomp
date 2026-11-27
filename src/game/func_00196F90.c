#include "m2c.h"

/* func_00196F90 */
void memset(void *, s32, s32);
void func_00185390(f32, s32, s32, s32);
void func_00186440(f32, f32 *, f32 *, f32 *, f32 *);
f32 func_00187770(f32, f32, f32);
void func_0019A370(f32 *, f32 *, f32 *, f32 *, s32);
s32 func_001A9B40(s16);
void func_001DF470(f32, s32);
extern s32 D_00201D38;
extern s32 *D_00201D3C;
extern s32 D_00202198;
extern f32 D_0020219C;
extern f32 D_002021A0;
extern s32 D_004A1430[];
extern s32 D_004A1434[];

void func_00196F90(f32 arg0) {
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    s32 id;
    s32 ok;
    s32 m;
    f32 t;

    func_0019A370(a, b, c, d, D_00201D3C[D_004A1430[0]]);
    id = D_00201D3C[D_004A1430[0]];
    if (id < 0) {
        ok = 0;
    } else {
        ok = func_001A9B40(id);
    }
    if (ok != 0) {
        func_00186440(arg0, a, b, c, d);
    } else {
        memset(a, -1, 0x10);
        memset(b, -1, 0x10);
        func_00186440(arg0, a, b, NULL, NULL);
    }
    if (D_004A1434[0] == 1) {
        D_002021A0 = 10.0f;
    }
    if (!(D_002021A0 <= 0.0f)) {
        D_002021A0 -= 1.0f;
        D_0020219C = func_00187770(D_0020219C, -2.99f, 3.5f);
    } else {
        D_0020219C = func_00187770(D_0020219C, -0.02f, 3.5f);
    }
    func_00185390(arg0 + D_0020219C, 1, D_00202198, D_004A1430[0]);
    t = arg0 + D_0020219C;
    m = D_00201D38;
    func_001DF470(t, m == 1 ? -1 : m);
}

/* func_00197130 */
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { u8 pad[0x20]; L *l; } O;
O *func_00189050(s32);
s8 *func_00189020(s32);
void func_00187B20(s32);
f32 func_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void func_001973F0(void);
void func_001829B0(Ent *, s8 *, void (*)(void), s32);

void func_00197130(s32 arg, f32 ang) {
    u32 i;
    L *l;
    s8 *base;
    Ent e;
    V2 q;
f32 d, a, t, dx, dy;
    l = func_00189050(2)->l;
    base = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
        if (e.f4 == 100) {
            p.x = -70.0f;
            p.y = 276.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - -70.0f;
        dy = e.y - 276.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang;
        e.x = -70.0f + d * sinf(a);
        e.y = 276.0f + d * cosf(a);
        } else {
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang;
        e.x = 735.0f + d * sinf(a);
        e.y = 129.0f + d * cosf(a);
        }
        }
        func_001829B0(&e, base + l->p[i].idx * 8, func_001973F0, arg);
    }
}
