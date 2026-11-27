#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 pad2[0x14]; u16 x20; u8 pad3[0x1A]; u8 x3C; u8 pad4[0x53]; } E;
typedef struct { s32 idx; u8 pad[0x28]; f32 x, z; u8 pad2[0xC]; } Obj;
typedef struct { u32 n; Obj *e; } L;
typedef struct { u8 pad[0x10]; L *l; } R_func_00184960;
typedef struct { f32 x, z; } V2_func_00184960;
typedef struct { u8 pad[0x14]; f32 x14; f32 x18; u8 pad1C[0x10]; f32 x2C; f32 x30; u8 pad34[8]; u32 x3C; } G_func_00184CF0;
typedef struct { u8 pad[0x10]; L *l; } R_func_00184DF0;
typedef struct { f32 x, z; } V2_func_00184DF0;
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
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R_func_00185030;
typedef struct { u8 pad0[0x7C]; R_func_00185030 *x7C; } G_func_00185030;
typedef struct { s32 idx; u8 pad[0x28]; f32 x2C; u8 pad30[0x10]; } Elem_func_00185390;
typedef struct { u32 n; Elem_func_00185390 *e; } List_func_00185390;
typedef struct { u8 pad[0x1C]; List_func_00185390 *list; } Ctx_func_00185390;
typedef union { u128 q; f32 f[4]; } V;
typedef struct { s32 idx; u8 pad[0x28]; f32 x2C; f32 x30; u8 pad34[0xC]; } Elem_func_00185510;
typedef struct { u32 n; Elem_func_00185510 *e; } List_func_00185510;
typedef struct { u8 pad[0x18]; List_func_00185510 *list; } Ctx_func_00185510;
typedef struct { f32 x, y; } V2_func_00185510;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 a:3; u8 b:5; } BF;
typedef struct { f32 x; f32 y; BF f8; u8 pad9[0xB]; f32 x14; u8 pad18[8]; f32 x20; f32 x24; u8 pad28[8]; } T;
typedef struct { s32 idx; u8 pad[0x28]; f32 x2C; f32 x30; u8 pad34[0xC]; } Elem_func_00185B40;
typedef struct { u32 n; Elem_func_00185B40 *e; } List_func_00185B40;
typedef struct { u8 pad[0x20]; List_func_00185B40 *list; } Ctx_func_00185B40;
typedef struct { f32 x, y; } V2_func_00185B40;
extern G_func_00184CF0 D_0048D060;
extern S D_001F2700 __attribute__((aligned(16)));
extern f32 D_00202084;
extern f32 D_002020B0;
extern f32 D_002020B4;
extern f32 D_002020B8;
extern f32 D_002020BC;
extern f32 D_002020D4;
extern V D_001F26F0[];
extern S D_001F26D0 __attribute__((aligned(16)));
extern char D_0048CE40[];
extern char D_001FCB08[];
extern char D_001FCB18[];
extern char D_001FCB28[];
extern char D_001FCB30[];
extern s32 D_0020207C;
extern s32 D_00202080;
s32 func_001848A0(s32 a);
void func_00184960(s32 a0, f32 ang);
void func_00184CF0(s8 *a0, s32 a1, u32 n);
void func_00184DF0(s32 a0, f32 ang);
void func_00185030(O *o, s32 a1, u32 mode, u32 a3);
void func_00185390(s32 a0, s32 a1, s32 a2, f32 f);
void func_00185510(s32 a0, f32 f);
void func_00185740(O *o, s32 a1, u32 mode, s16 *a3);
void func_00185B30(s32 arg0, s32 arg1);
void func_00185B40(s32 a0, f32 f);
E* func_001AFC90(void);
R_func_00184960* func_00189050(s32);
u8* func_00189020(s32);
void func_00187B20(s32);
f32 atanf(f32);
f32 sinf(f32);
f32 cosf(f32);
f32 fabsf(f32);
f32 func_00187770(f32, f32, f32);
void func_001829B0(Obj *, u8 *, void *, s32);
void func_00181420(void);
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_001544C0(void);
f32 sqrtf(f32);
void func_001832D0(G_func_00184CF0 *, s32, s32);
void func_00181680(s32, void *, void *, void *, S *, u32);
void func_00182C10(Elem_func_00185390 *, s32);
void func_00183090(V *, s32, s32, s32);
void sprintf(char *, char *, ...);
u32 strlen(void *);
void func_00187A90(void *, void *, u64);
s32 func_00188010(void *, Col);
void func_00185D70(void);

/* func_001848A0 */
s32 func_001848A0(s32 a) { s32 r = 0; E *e = func_001AFC90() + a; if (e == NULL || a == -1) return -1; if (e->xA == 1) { switch (e->x20) { case 5: case 6: r = 0; break; default: r = e->x3C; break; } } else if (e->xA == 2) { r = e->x3C; } return r; }

/* func_00184960 */
#define func_00184CF0 func_00184CF0__as_func_00184960
void func_00184CF0__as_func_00184960(void);
extern f32 D_00202088, D_0020208C, D_00202090, D_00202094, D_00202098, D_0020209C;
extern f32 D_002020B0, D_002020B4, D_002020B8, D_002020BC;

void func_00184960(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;
    f32 v;

    l = func_00189050(2)->l;
    t = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2_func_00184960 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 108.0f;
        c.z = 72.0f;
        fx = o.x; fz = o.z; ox = fx - 108.0f; oz = fz - 72.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = atanf(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 108.0f + d * sinf(r);
        o.z = 72.0f + d * cosf(r);
        }
        func_001829B0(&o, t + (l->e[i].idx << 3), func_00184CF0, a0);
    }
    func_00181420();
    func_001545D0();
    func_001543E0(0x42, 0x48);
    func_001544C0();
    func_00189020(0);
    v = D_0020208C;
    D_00202088 += v;
    D_0020208C = v - (v - (v - 1.0f) / 10.0f);
    D_00202090 = func_00187770(D_00202090, D_002020BC, 10.0f);
    D_00202094 = func_00187770(D_00202094, D_002020B8, 10.0f);
    if (!(fabsf(D_002020BC - D_00202090) <= 5.0f)) {
        D_0020208C = 0.0f;
    }
    cosf(D_00202088);
    sinf(D_00202088);
    D_00202098 = func_00187770(D_00202098, D_002020B4, 10.0f);
    D_0020209C = func_00187770(D_0020209C, D_002020B0, 10.0f);
    cosf(3.14f + D_00202088);
    sinf(3.14f + D_00202088);
    func_00181420();
    func_001545D0();
    func_001543E0(0x42, 0x44);
    func_001544C0();
}
#undef func_00184CF0

/* func_00184CF0 */
void func_00184CF0(s8 *a0, s32 a1, u32 n) {
    if (n >= 500) {
        D_0048D060.x2C = *(f32 *)(a0 + 0x38);
        D_0048D060.x30 = *(f32 *)(a0 + 0x3C);
        D_0048D060.x14 = 1.0f;
        D_0048D060.x18 = 1.0f;
        D_0048D060.x3C = 0x80FFFFFF;
        switch (n - 500) {
        case 0: case 1: case 2: case 3: case 4: case 5: break;
        case 6: case 7: case 8: case 9:
            D_0048D060.x2C = 3.0f + *(f32 *)(a0 + 0x38);
            D_0048D060.x30 = 3.0f + *(f32 *)(a0 + 0x3C);
            break;
        }
        if (n > 1000) func_001832D0(&D_0048D060, n - 1500, 1);
        else func_001832D0(&D_0048D060, n - 500, 0);
    }
}

/* func_00184DF0 */
#define func_00189050 func_00189050__as_func_00184DF0
R_func_00184DF0 *func_00189050__as_func_00184DF0(s32);
#define func_00185030 func_00185030__as_func_00184DF0
void func_00185030__as_func_00184DF0(void);

void func_00184DF0(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;

    l = func_00189050(2)->l;
    t = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2_func_00184DF0 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 108.0f;
        c.z = 72.0f;
        fx = o.x; fz = o.z; ox = fx - 108.0f; oz = fz - 72.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = atanf(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 108.0f + d * sinf(r);
        o.z = 72.0f + d * cosf(r);
        }
        func_001829B0(&o, t + (l->e[i].idx << 3), func_00185030, a0);
    }
}
#undef func_00189050
#undef func_00185030

/* func_00185030 */
#define func_00189020 func_00189020__as_func_00185030
G_func_00185030 *func_00189020__as_func_00185030(s32);
static inline void glow(O *o, R_func_00185030 *r, S *buf, u32 mode) {
    s32 k;
    buf->x = o->x38;
    buf->y = o->x3C;
    buf->m[3] = 1.0f;
    buf->m[0] = 1.0f;
    k = 96.0f + fabsf(128.0f * sinf(0.05f * D_002020D4));
    o->x2C = o->x2C * k / 128;
    o->x2D = o->x2D * k / 128;
    o->x2E = o->x2E * k / 128;
    func_00181680(r->x4, r->x10, r->x20, &o->x2C, buf, mode);
}

void func_00185030(O *o, s32 a1, u32 mode, u32 a3) {
    S buf __attribute__((aligned(16)));
    R_func_00185030 *r;
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
#undef func_00189020

/* func_00185390 */
#define func_00189050 func_00189050__as_func_00185390
Ctx_func_00185390 *func_00189050__as_func_00185390(s32);
#define func_00189020 func_00189020__as_func_00185390
s32 func_00189020__as_func_00185390(s32);

void func_00185390(s32 a0, s32 a1, s32 a2, f32 f) {
    Elem_func_00185390 el;
    V v;
    u32 i;
    List_func_00185390 *list;
    s32 base;

    list = func_00189050(0)->list;
    base = func_00189020(0);
    func_00187B20(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        el.x2C -= 40.0f * f;
        func_00182C10(&el, base + list->e[i].idx * 8);
    }
    v = D_001F26F0[0];
    v.f[0] -= 40.0f * f;
    v.f[2] -= 40.0f * f;
    func_00183090(&v, a0, a1, a2);
}
#undef func_00189050
#undef func_00189020

/* func_00185510 */
#define func_00189050 func_00189050__as_func_00185510
Ctx_func_00185510 *func_00189050__as_func_00185510(s32);
#define func_00189020 func_00189020__as_func_00185510
s32 func_00189020__as_func_00185510(s32);
#define func_001829B0 func_001829B0__as_func_00185510
void func_001829B0__as_func_00185510(Elem_func_00185510 *, s32, void (*)(), s32);
static inline f32 d2d_func_00185510(f32 x, f32 y, f32 cx, f32 cy) { f32 u = x - cx; f32 v = y - cy; return sqrtf(u * u + v * v); }

void func_00185510(s32 a0, f32 f) {
    Elem_func_00185510 el;
    u32 i;
    List_func_00185510 *list;
    s32 base;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 ang;
    f32 px;
    f32 py;

    list = func_00189050(0)->list;
    base = func_00189020(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        {
        V2_func_00185510 c = {0};
        c.x = -70.0f;
        c.y = 276.0f;
        px = el.x2C;
        py = el.x30;
        dist = d2d_func_00185510(px, py, -70.0f, 276.0f);
        dx = px - c.x;
        dy = py - c.y;
        if (dx == 0.0f) {
            ang = 0.0f;
        } else {
            ang = atanf(dx / dy);
        }
        if (dy < 0.0f) {
            ang += 3.141592f;
        }
        dy = ang + f;
        el.x2C = -70.0f + dist * sinf(dy);
        el.x30 = 276.0f + dist * cosf(dy);
        }
        func_001829B0(&el, base + list->e[i].idx * 8, func_00185740, a0);
    }
}
#undef func_00189050
#undef func_00189020
#undef func_001829B0

/* func_00185740 */
static inline void draw(char *s, f32 x, f32 y, Col *c) {
    T t;
    if (s) {
        func_00187A90(&t, s, strlen(s));
        t.f8.a = 0;
        t.x24 = 1.0f;
        t.x20 = 0.9f;
        t.x14 = 4096.0f;
        t.x = x;
        t.y = y;
        func_00188010(&t, *c);
    }
}

void func_00185740(O *o, s32 a1, u32 mode, s16 *a3) {
    Col c8;
    Col cb;
    Col ca;
    Col c9;
    f32 x;
    f32 y;
    s32 v;
    if (mode < 200) {
        S buf __attribute__((aligned(16)));
        buf = D_001F26D0;
        buf.x = o->x30;
        buf.y = o->x34;
        func_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 200:
        *(u32 *)&c8 = 0x80808080;
        sprintf(D_0048CE40, D_001FCB08, a3[2], a3[0]);
        *(f32 *)((s32)o + 0x38) += 4.0f;
        draw(D_0048CE40, o->x38, o->x3C, &c8);
        break;
    case 201:
        *(u32 *)&c9 = 0x80808080;
        sprintf(D_0048CE40, D_001FCB18, a3[3], a3[1]);
        draw(D_0048CE40, o->x38, o->x3C, &c9);
        break;
    case 202:
        v = D_0020207C;
        if (v == 0) break;
        if (v < 0) {
            *(u32 *)&ca = 0x80404080;
            sprintf(D_0048CE40, D_001FCB28, v);
        } else {
            *(u32 *)&ca = 0x80804040;
            sprintf(D_0048CE40, D_001FCB30, v);
        }
        x = o->x38 + 10.0f;
        y = o->x3C;
        draw(D_0048CE40, x, y, &ca);
        break;
    case 203:
        v = D_00202080;
        if (v == 0) break;
        if (v < 0) {
            *(u32 *)&cb = 0x80404080;
            sprintf(D_0048CE40, D_001FCB28, v);
        } else {
            *(u32 *)&cb = 0x80804040;
            sprintf(D_0048CE40, D_001FCB30, v);
        }
        x = o->x38 + 10.0f;
        y = o->x3C;
        draw(D_0048CE40, x, y, &cb);
        break;
    }
}

/* func_00185B30 */
void func_00185B30(s32 arg0, s32 arg1) {
    D_0020207C = arg0;
    D_00202080 = arg1;
}

/* func_00185B40 */
#define func_00189050 func_00189050__as_func_00185B40
Ctx_func_00185B40 *func_00189050__as_func_00185B40(s32);
#define func_00189020 func_00189020__as_func_00185B40
s32 func_00189020__as_func_00185B40(s32);
#define func_001829B0 func_001829B0__as_func_00185B40
void func_001829B0__as_func_00185B40(Elem_func_00185B40 *, s32, void (*)(), s32);
static inline f32 d2d_func_00185B40(f32 x, f32 y, f32 cx, f32 cy) { f32 u = x - cx; f32 v = y - cy; return sqrtf(u * u + v * v); }

void func_00185B40(s32 a0, f32 f) {
    Elem_func_00185B40 el;
    u32 i;
    List_func_00185B40 *list;
    s32 base;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 ang;
    f32 px;
    f32 py;

    list = func_00189050(0)->list;
    base = func_00189020(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        {
        V2_func_00185B40 c = {0};
        c.x = -70.0f;
        c.y = 276.0f;
        px = el.x2C;
        py = el.x30;
        dist = d2d_func_00185B40(px, py, -70.0f, 276.0f);
        dx = px - c.x;
        dy = py - c.y;
        if (dx == 0.0f) {
            ang = 0.0f;
        } else {
            ang = atanf(dx / dy);
        }
        if (dy < 0.0f) {
            ang += 3.141592f;
        }
        dy = ang + f;
        el.x2C = -70.0f + dist * sinf(dy);
        el.x30 = 276.0f + dist * cosf(dy);
        }
        func_001829B0(&el, base + list->e[i].idx * 8, func_00185D70, a0);
    }
}
#undef func_00189050
#undef func_00189020
#undef func_001829B0
