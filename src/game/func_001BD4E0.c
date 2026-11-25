#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { f32 m[4][4]; } MtxF;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { u8 pad0[0x36]; u8 x36[0xB6 - 0x36]; u8 xB6, xB7, xB8, xB9; u8 padBA[4]; u16 xBE; u16 xC0; u8 xC2; } T158;
typedef struct { s32 x0; u8 pad4[0x154]; T158 *x158; u8 pad15C[0x2C]; u8 *x188; } M;
typedef struct { u8 pad0[0x1E]; s16 x1E; u8 pad20; s8 x21; s8 x22; u8 pad23[5]; u8 b0:3; u8 b3:1; } N;
typedef struct { u8 pad0[0x26]; s16 x26; } C8;
typedef struct { u8 pad0[0xC0]; M *xC0; u8 padC4[4]; C8 *xC8; } Q;
typedef struct { u8 pad0[0xC]; u8 lo:4; u8 hi:4; u8 m:3; } S1;
typedef struct { u8 pad0[0x10]; Q *x10; u8 pad14[0xD0 - 0x14]; u8 xD0[0x2C]; S1 *xFC; u8 pad100[0x3BF - 0x100]; u8 x3BF; } P;
extern M **D_00201E80;
#define E80 (&D_00201E80)
extern M **D_002022BC;
extern s32 D_002022B8;
extern f32 D_002022DC;
extern u32 D_00201C5C;
extern u8 D_00201E24;
extern f32 D_001F2080[], D_001F2084[], D_001F208C[], D_001F2090[], D_001F2094[], D_001F209C[];
extern f32 D_001F20C0[], D_001F20C4[], D_001F20C8[], D_001F20D0[], D_001F20D4[], D_001F20D8[];
extern Vec D_001F2070[], D_001F2100[];
extern f32 D_001F210C[];
extern MtxF D_001F2170;
extern Vec D_004B4CE0[];
extern f32 D_004B4CEC[];
extern Vec D_004B4C40[], D_004B4C50[], D_004B4C60[], D_004B4C70[], D_004B4C80[], D_004B4C90[], D_004B4CA0[], D_004B4CB0[], D_004B4CC0[], D_004B4CD0[];
extern f32 D_004B4CDC[];
extern u8 D_0030D0E0[];
N *func_001B1D00(M *, void *);
void func_001B51F0(M *, u8 *, s32);
M **func_001B0AE0(M *);
void func_001B0A80(M *, s32);
void func_001AA4C0(s32);
f32 func_0015DF90(f32, f32, f32);
f32 *func_001B40F0(M *, s32);
void func_001029A8(Vec *, void *, Vec *, f32);
void func_00102C20(MtxF *, MtxF *, f32);
void func_00102CC8(MtxF *, MtxF *, f32);
void func_001027B0(Vec *, MtxF *, Vec *);
static inline f32 wrap(f32 x) { f32 t = 3.1415927f + x; return ((t - 6.2831855f * (s32)(0.15915494f * t)) + (t < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f; }
static inline f32 u2f(u32 x) { return x; }
static inline f32 rad(u32 d) { f32 f = d; return 3.1415927f * f / 180.0f; }

void func_001BD4E0(Actor *a) {
    P *p;
    N *n;
    S1 *s1;
    M *m;
    M *mm;
    u8 *e;
    f32 *k;
    f32 f;
    Col col;
    MtxF mt;
    Vec v;

    p = (P *)(a->unk518 + 0x180);
    n = 0;
    if (*(s32 *)(a->unk518 + 0x274) == 0) return;
    s1 = p->xFC;
    D_002022BC = 0;
    if (E80[2] != 0) {
        n = func_001B1D00(*E80[2], p->xD0);
        if (n != 0) D_002022BC = E80[2];
    }
    if (E80[3] != 0 && n == 0) {
        n = func_001B1D00(*E80[3], p->xD0);
        if (n != 0) D_002022BC = E80[3];
    }
    if (n != 0) {
        M **h;
        e = 0;
        h = D_002022BC;
        if (n->x1E != -1) e = &(*h)->x158->x36[n->x1E * 8];
        if (e != 0) func_001B51F0(*h, e, n->b3);
    } else if (p->x10->xC8 != 0) {
        mm = p->x10->xC0;
        e = 0;
        D_002022BC = func_001B0AE0(mm);
        if (p->x10->xC8->x26 != -1) e = &mm->x158->x36[p->x10->xC8->x26 * 8];
        if (e != 0) func_001B51F0(mm, e, 0);
    }
    if (D_002022BC != 0 && (m = *D_002022BC) != 0) {
        if (D_002022B8 != m->x0) {
            if (E80[2] != 0 && *E80[2] != 0 && E80[2] != D_002022BC) func_001B0A80(*E80[2], 0);
            if (E80[3] != 0 && *E80[3] != 0 && E80[3] != D_002022BC) func_001B0A80(*E80[3], 0);
            func_001B0A80(m, 1);
            func_001AA4C0(m->x0);
            D_002022DC = 0.0f;
        }
        D_002022B8 = m->x0;
        if (D_002022DC >= 60.0f) f = 1.0f; else f = 1.0f / (60.0f - D_002022DC);
        col.w = D_00201C5C;
        col.c.r = func_0015DF90(u2f(col.c.r), u2f(m->x158->xB6), f);
        col.c.g = func_0015DF90(u2f(col.c.g), u2f(m->x158->xB7), f);
        col.c.b = func_0015DF90(u2f(col.c.b), u2f(m->x158->xB8), f);
        col.c.a = func_0015DF90(u2f(col.c.a), u2f(m->x158->xB9), f);
        D_00201C5C = col.w;
        k = func_001B40F0(m, 0);
        D_001F2080[0] = func_0015DF90(D_001F2080[0], k[0], f);
        D_001F2084[0] = func_0015DF90(D_001F2084[0], k[1], f);
        D_001F208C[0] = func_0015DF90(D_001F208C[0], k[3], f);
        D_001F2090[0] = func_0015DF90(D_001F2090[0], k[8], f);
        D_001F2094[0] = func_0015DF90(D_001F2094[0], k[9], f);
        D_001F209C[0] = func_0015DF90(D_001F209C[0], k[11], f);
        D_001F20C0[0] = func_0015DF90(D_001F20C0[0], k[4], f);
        D_001F20C4[0] = func_0015DF90(D_001F20C4[0], k[5], f);
        D_001F20C8[0] = func_0015DF90(D_001F20C8[0], k[6], f);
        D_001F20D0[0] = func_0015DF90(D_001F20D0[0], k[4], f);
        D_001F20D4[0] = func_0015DF90(D_001F20D4[0], k[5], f);
        D_001F20D8[0] = func_0015DF90(D_001F20D8[0], k[6], f);
        func_001029A8(D_001F2070, k + 0x14, D_001F2070, f);
        func_001029A8(D_001F2100, k + 0x10, D_001F2100, f);
        D_001F210C[0] = 127.9f;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 1.0f;
        v.w = 1.0f;
        func_00102C20(&mt, &D_001F2170, WRAP(-(3.1415927f * (f32)(u32)m->x158->xBE / 180.0f)));
        func_00102CC8(&mt, &mt, WRAP(3.1415927f * (f32)(u32)m->x158->xC0 / 180.0f));
        func_001027B0(&v, &mt, &v);
        func_001029A8(D_004B4CE0, &v, D_004B4CE0, f);
        D_004B4CEC[0] = 1.0f;
        D_00201E24 = func_0015DF90(u2f(D_00201E24), u2f(m->x158->xC2), f);
        D_002022DC += 1.0f;
        if (n != 0) {
            if (n->x22 != -1) e = m->x188 + n->x22 * 0xA0;
            else if (n->x21 != -1) e = m->x188 + n->x21 * 0xA0;
            else e = D_0030D0E0;
            func_001029A8(D_004B4C40, e, D_004B4C40, 0.2f);
            func_001029A8(D_004B4C50, e + 0x10, D_004B4C50, 0.2f);
            func_001029A8(D_004B4C60, e + 0x20, D_004B4C60, 0.2f);
            func_001029A8(D_004B4C70, e + 0x30, D_004B4C70, 0.2f);
            func_001029A8(D_004B4C80, e + 0x40, D_004B4C80, 0.2f);
            func_001029A8(D_004B4C90, e + 0x50, D_004B4C90, 0.2f);
            func_001029A8(D_004B4CA0, e + 0x60, D_004B4CA0, 0.2f);
            func_001029A8(D_004B4CB0, e + 0x70, D_004B4CB0, 0.2f);
            func_001029A8(D_004B4CC0, e + 0x80, D_004B4CC0, 0.2f);
            func_001029A8(D_004B4CD0, e + 0x90, D_004B4CD0, 0.2f);
            D_004B4CDC[0] = 127.9f;
        }
    }
    if (s1->m == 2) p->x3BF = s1->lo;
}
