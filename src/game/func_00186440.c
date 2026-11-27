#include "m2c.h"
#include "common.h"
typedef struct { s32 idx; s32 x4; u8 pad[0x24]; f32 x2C; f32 x30; u8 pad34[0xC]; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x10]; List *list; } Ctx;
typedef struct { f32 x, y; } V2;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C;
typedef struct { u8 a:3; u8 b:5; } BF;
typedef struct {
    f32 x0;
    f32 x4;
    BF x8;
    u8 pad9[0xB];
    f32 x14;
    u8 pad18[8];
    f32 x20;
    f32 x24;
    s8 *x28;
} T;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C[4];
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O;
typedef struct { u8 pad0[4]; s32 x4; u8 pad8[8]; u8 x10[0x10]; u8 x20[0x10]; } R;
typedef struct { u8 pad0[0x54]; R *x54; u8 pad58[4]; R *x5C; } G;
typedef struct { s16 lo; s16 hi; } P;
extern S D_001F2630 __attribute__((aligned(16)));
extern S D_001F2650 __attribute__((aligned(16)));
extern S D_001F2670 __attribute__((aligned(16)));
extern s32 D_0048CF40[];
extern s32 D_0048CFC0[];
extern s32 D_0048CF80[];
extern s32 D_0048D000[];
extern s8 D_0048CE40[];
extern s8 D_001FCA80[];
extern s8 D_001FCA88[];
extern s8 D_001FCB80[];
extern s8 D_001FCB88[];
extern s8 D_001FCB90[];
void func_00186440(s32 a0, s32 a1, s32 a2, s32 a3, f32 f);
u32 func_001866B0(s32 a0, u16 *a1, u16 *a2, u16 *a3, u16 *t0);
void func_00186990(O *o, s32 id, u32 mode, u32 p);
Ctx* func_00189050(s32);
s32 func_00189020(s32);
f32 atanf(f32);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(float);
void func_001829B0(Elem *, s32, void (*)(), s32);
void func_00181680(s32, void *, void *, void *, S *, u32);
void sprintf(void *, void *, s32);
u32 strlen(void *);
void func_00187A90(void *, void *, u64);
s32 func_00188010(void *, C);

/* func_00186440 */
#define func_001866B0 func_001866B0__as_func_00186440
s32 func_001866B0__as_func_00186440(s32, s32, s32, s32, s32);
static inline f32 d2d(f32 x, f32 y, f32 cx, f32 cy) { f32 u = x - cx; f32 v = y - cy; return sqrtf(u * u + v * v); }

void func_00186440(s32 a0, s32 a1, s32 a2, s32 a3, f32 f) {
    Elem el;
    u32 i;
    List *list;
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
        V2 c = {0};
        c.x = -70.0f;
        c.y = 276.0f;
        px = el.x2C;
        py = el.x30;
        dist = d2d(px, py, -70.0f, 276.0f);
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
        func_001829B0(&el, base + list->e[i].idx * 8, func_00186990, func_001866B0(el.x4, a0, a1, a2, a3));
    }
}
#undef func_001866B0

/* func_001866B0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
static inline u32 get(u16 *p, s32 i) { return p ? p[i] : 0; }
static inline u32 mk(u32 lo, u32 hi) { return (u16)lo | ((u16)hi << 16); }

u32 func_001866B0(s32 a0, u16 *a1, u16 *a2, u16 *a3, u16 *t0) {
    u32 t;
    u16 lo, hi;
    switch (a0) {
    case 3001:
        return mk(get(a1, 0), get(a3, 0));
    case 3002:
        return mk(get(a1, 1), get(a3, 1));
    case 3003:
        return mk(get(a1, 2), get(a3, 2));
    case 3004:
        return mk(get(a1, 3), get(a3, 3));
    case 3005:
        return mk(get(a1, 4), get(a3, 4));
    case 3006:
        return mk(get(a1, 5), get(a3, 5));
    case 3007:
        return mk(get(a1, 6), get(a3, 6));
    case 3008:
        return mk(get(a1, 7), get(a3, 7));
    case 3011:
        return mk(get(a2, 0), get(t0, 0));
    case 3012:
        return mk(get(a2, 1), get(t0, 1));
    case 3013:
        return mk(get(a2, 2), get(t0, 2));
    case 3014:
        return mk(get(a2, 3), get(t0, 3));
    case 3015:
        return mk(get(a2, 4), get(t0, 4));
    case 3016:
        return mk(get(a2, 5), get(t0, 5));
    case 3009: case 3010:
    default:
        return 0;
    }
}

/* func_00186990 */
#define func_00189020 func_00189020__as_func_00186990
G *func_00189020__as_func_00186990(s32);
static inline void draw(f32 x, f32 y, s8 *str, C col, f32 sc) {
    T t;
    if (str == 0) {
        return;
    }
    func_00187A90(&t, str, strlen(str));
    t.x8.a = 0;
    t.x24 = 1.0f;
    t.x20 = sc;
    t.x14 = 4096.0f;
    t.x0 = x;
    t.x4 = y;
    func_00188010(&t, col);
}

void func_00186990(O *o, s32 id, u32 mode, u32 p) {
    S buf __attribute__((aligned(16)));
    C col;
    s32 lo;
    s32 hi;
    s32 idx;
    s32 *cnt;

    buf = D_001F2630;
    lo = (s16)(p & 0xFFFF);
    hi = (s16)((p >> 16) & 0xFFFF);
    idx = id - 0xBB9;
    if (mode < 100) {
        S b2 __attribute__((aligned(16)));
        b2 = D_001F2650;
        b2.x = o->x30;
        b2.y = o->x34;
        func_00181680(o->x28, o, o->x10, o->x2C, &b2, mode);
        return;
    }
    switch (mode) {
    case 100: {
        S b3 __attribute__((aligned(16)));
        R *r;
        b3 = D_001F2670;
        r = &func_00189020(0)->x54[id - 0xBB9];
        col.w = (0x30808080);
        b3.x = o->x38;
        b3.y = o->x3C;
        func_00181680(r->x4, r->x10, r->x20, &col, &b3, mode);
        break;
    }
    case 101: {
        R *r;
        r = &func_00189020(0)->x5C[id - 0xBB9];
        col.w = 0x30808080;
        buf.m[0] = 1.1f;
        buf.m[3] = 1.0f;
        buf.x = o->x38 - 5.0f;
        buf.y = o->x3C - 4.0f;
        func_00181680(r->x4, r->x10, r->x20, &col, &buf, mode);
        break;
    }
    case 102: {
        s32 v = (s16)lo;
        if (v != D_0048CF40[idx]) {
            D_0048CFC0[idx] = 0;
            D_0048CF40[idx] = v;
        }
        if (D_0048CFC0[idx] < 0x80) {
            D_0048CFC0[idx] += 0x10;
        }
        col.w = 0x80808080;
        col.c.a = D_0048CFC0[idx];
        if (v >= 0) {
            sprintf(D_0048CE40, D_001FCA80, v);
        } else {
            sprintf(D_0048CE40, D_001FCA88, v);
        }
        draw(o->x38, o->x3C, D_0048CE40, col, 0.9f);
        break;
    }
    case 103: {
        s32 v = (s16)hi;
        if (v != D_0048CF80[idx]) {
            D_0048D000[idx] = 0;
            D_0048CF80[idx] = v;
        }
        cnt = &D_0048D000[idx];
        if (*cnt < 0x80) {
            *cnt += 0x10;
        }
        if (v < 0) {
            col.w = 0x80404080;
            sprintf(D_0048CE40, D_001FCB80, v);
        } else if (v > 0) {
            col.w = 0x80804040;
            sprintf(D_0048CE40, D_001FCB88, v);
        } else {
            col.w = 0x80808080;
            sprintf(D_0048CE40, D_001FCB90, v);
        }
        col.c.a = *cnt;
        draw(o->x38, o->x3C, D_0048CE40, col, 0.8f);
        break;
    }
    }
}
#undef func_00189020
