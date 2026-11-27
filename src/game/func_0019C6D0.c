#include "m2c.h"
typedef union { u128 q; u32 w[4]; } V;
typedef union { u32 w; u8 b[4]; } C;
typedef void (*Fn)(void);
typedef struct { s32 idx; s32 x4; s32 x8[9]; f32 f2C; s32 x30[4]; } A;
typedef struct { s32 idx; s32 x4; s32 x8; f32 fC; s32 x10[12]; } B;
typedef struct { u32 n; A *e; } LA;
typedef struct { u32 n; B *e; } LB;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { L *l; } O;
extern Fn D_001F28D0[];
extern V D_001F3120[];
extern V D_001F3130[];
extern f32 D_00201D70;
extern f32 D_00201D74;
extern s32 *D_00201D68;
extern s32 D_002021E4;
extern s32 D_002021E8;
extern s32 D_002021F8;
extern s32 D_00202200;
extern s32 D_004A3290[];
extern s8 D_004A32A0[];
extern S D_001F3100[] __attribute__((aligned(16)));
extern s8 D_001FD5B0[];
extern s8 D_004A3150[];
extern u8 D_004A329C[];
extern s32 D_002021E0;
extern s32 D_002021EC;
void func_0019C6D0(u8 *arg0);
void func_0019C9B0(f32 f);
void func_0019CB90(s8 *a0, s32 a1, u32 a2);
void func_0019CCF0(s32 arg, f32 ang);
void func_0018A310(s32);
f32 func_00187770(f32, f32, f32);
void func_001875C0(s32, s32, u32, f32, f32, f32);
void func_0017F5C0(void);
void func_00185390(f32, s32, s32, s32);
void func_00182080(s32, f32, V *, V *, C *, s32);
s32 func_001958A0(void);
s32 func_001957E0(s32, s32);
s8* func_00189050(s32);
s32 func_00189020(s32);
void func_00187B20(s32);
void func_001829B0(void *, s32, void (*)(), s32);
void func_00186990(void);
s32 func_001C9BA0(void);
s32 func_001866B0(s32, s32, s32, s8 *, s32);
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);
void func_00182EF0(s32, s32, s32, s32, f32, f32, f32);
void sprintf(s8 *, s8 *, s32);
f32 func_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void func_0019CEF0(void);

/* func_0019C6D0 */
#define func_0019CCF0 func_0019CCF0__as_func_0019C6D0
void func_0019CCF0__as_func_0019C6D0(f32, s32);
#define func_0019C9B0 func_0019C9B0__as_func_0019C6D0
void func_0019C9B0__as_func_0019C6D0(u8 *, f32);
static inline s32 get(s32 id) {
    s32 t = func_001958A0();
    if (id == 0) {
        return 0;
    }
    if (id == -1) {
        return 0;
    }
    if (t == 0) {
        return 0;
    }
    return func_001957E0(t, id);
}

void func_0019C6D0(u8 *arg0) {
    C c;
    C col;
    V a;
    V b;
    s32 id;
    s32 k;
    f32 f;

    D_001F28D0[0]();
    func_0018A310(0xC);
    if (arg0[8] == 0x15) {
        D_00201D70 = func_00187770(D_00201D70, -0.02f, 3.5f);
        id = D_00201D68[D_004A3290[0]];
        if (id > 0) {
            c.w = 0x80808080;
            func_001875C0(get(id), 2, *(u32 *)&c, 622.0f, 17.0f, 1.1f);
        }
    } else {
        D_00201D70 = func_00187770(D_00201D70, -2.99f, 3.5f);
    }
    if (!(D_00201D70 <= -2.89f)) {
        func_0017F5C0();
        D_002021E4 = 0;
        f = -D_00201D70 / 1.5f;
        k = D_00201D68[D_004A3290[0]];
        if (D_002021F8 <= 0) {
            k = -1;
        }
        func_0019CCF0(f, k);
        func_00185390(-f, 1, D_002021F8 - 1, D_004A3290[0]);
    }
    a = D_001F3120[0];
    b = D_001F3130[0];
    if (D_002021E8 == 1) {
        D_00201D74 = D_00201D74 - (D_00201D74 - 10.0f) / 4.0f;
        D_00202200 = D_00202200 - (D_00202200 - 64.0f) / 4.0f;
    } else {
        D_00201D74 = D_00201D74 - (D_00201D74 + 300.0f) / 4.0f;
        D_00202200 = D_00202200 - D_00202200 / 4.0f;
    }
    col.w = 0;
    col.b[3] = D_00202200;
    func_00182080(0, 0.0f, &a, &b, &col, 0);
    func_0019C9B0(arg0, D_00201D74);
}
#undef func_0019CCF0
#undef func_0019C9B0

/* func_0019C9B0 */
void func_0019C9B0(f32 f) {
    A a;
    B b;
    LB *lb;
    s32 base2;
    u32 i;
    LA *la;
    s32 t;
    s32 base;

    la = *(LA **)(func_00189050(2) + 4);
    base = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < la->n; i++) {
        a = la->e[i];
        a.f2C = f;
        func_001829B0(&a, base + la->e[i].idx * 8, (void (*)())func_0019CB90, 0);
    }
    lb = *(LB **)(func_00189050(0) + 0x2C);
    base2 = func_00189020(0);
    t = func_001C9BA0();
    func_00187B20(0);
    for (i = 0; i < lb->n; i++) {
        b = lb->e[i];
        b.fC = f;
        func_001829B0(&b, base2 + lb->e[i].idx * 8, func_00186990, func_001866B0(b.x4, t + 0x20, 0, D_004A32A0, 0));
    }
}

/* func_0019CB90 */
#define func_001875C0 func_001875C0__as_func_0019CB90
void func_001875C0__as_func_0019CB90(f32, f32, f32, s32, s32, Col);

void func_0019CB90(s8 *a0, s32 a1, u32 a2) {
    S t __attribute__((aligned(16)));
    Col col;

    if (a2 < 300) {
        t = D_001F3100[0];
        t.x = *(f32 *)(a0 + 0x30);
        t.y = *(f32 *)(a0 + 0x34);
        func_00181680(*(s32 *)(a0 + 0x28), a0, a0 + 0x10, a0 + 0x2C, &t, a2);
        return;
    }
    if ((D_004A329C[0] & 1) && D_002021E0 + 300 == a2) {
        func_00182EF0(*(f32 *)(a0 + 0x38) - 6.0f, *(f32 *)(a0 + 0x3C), 171.0f + *(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 0.0f, 0.0f, 128.0f);
    }
    if (a2 == 500) {
        sprintf(D_004A3150, D_001FD5B0, D_002021EC);
        *(u32 *)&col = 0x80808080;
        func_001875C0(*(f32 *)(a0 + 0x38), *(f32 *)(a0 + 0x3C), 1.1f, (s32)D_004A3150, 2, col);
    }
}
#undef func_001875C0

/* func_0019CCF0 */
#define func_00189050 func_00189050__as_func_0019CCF0
O *func_00189050__as_func_0019CCF0(s32);
#define func_00189020 func_00189020__as_func_0019CCF0
s8 *func_00189020__as_func_0019CCF0(s32);
#define func_001829B0 func_001829B0__as_func_0019CCF0
void func_001829B0__as_func_0019CCF0(Ent *, s8 *, void (*)(void), s32);

void func_0019CCF0(s32 arg, f32 ang) {
    u32 i; L *l; s8 *base; Ent e; V2 q; f32 d, a, t, dx, dy;
    l = func_00189050(2)->l;
    base = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = -70.0f;
            p.y = 276.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - -70.0f; dy = e.y - 276.0f; d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang;
        e.x = -70.0f + d * sinf(a);
        e.y = 276.0f + d * cosf(a);
        }
        func_001829B0(&e, base + l->p[i].idx * 8, func_0019CEF0, arg);
    }
}
#undef func_00189050
#undef func_00189020
#undef func_001829B0
