#include "common.h"
typedef union { u32 w; struct { Flags8 a, b, c, d; } f; } Key;
typedef struct { u128 q[10]; } Big;
typedef struct { f32 x, y, z; s16 rx, ry, rz; u16 sx, sy, sz; s16 x18; u8 pad1A[6]; u8 x20; s8 x21; u8 pad22[2]; u8 x24; s8 x25; u8 pad26[2]; Flags8 f28; u8 pad29[3]; Key x2C; } E;
typedef struct { s32 **h; Flags8 f; u8 pad[3]; } P8;
typedef struct { u8 pad[0xC0]; Mtx m0; Mtx m1; } N;
typedef struct O O;
struct O {
    u8 pad0[0x6C];
    u16 n;
    u8 pad6E[0x88 - 0x6E];
    u16 x88;
    u8 pad8A[2];
    s16 x8C;
    s16 x8E;
    u8 pad90[0x134 - 0x90];
    E *x134;
    u8 pad138[0x154 - 0x138];
    u32 *x154;
    u8 pad158[0x178 - 0x158];
    P8 *x178;
    u8 pad17C[0x188 - 0x17C];
    Big *x188;
    u8 pad18C[0x1D8 - 0x18C];
    Flags8 f1D8;
};
extern O **D_002022BC;
extern s32 D_002022B8;
extern Big D_0030D0E0;
extern Vec D_003139A0;
s8 *func_001715B0(s32 **);
void func_00173FD0(Mtx *, f32 *, f32 *, f32 *);
void func_001C93A0(Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
s8 *func_001B7300(O *, s32);
void func_0015B6B0(Vec *, s8 *);
void func_0015B1C0(Vec *, s8 *);
void func_0015B270(void);
void func_001B3710(s32, s8 *, s32, Vec *, f32 *);
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, f32 *, Vec *);
void func_0016B960(s8 *, Big *, Vec *, f32 *, s32, s32);
void func_0016D830(s32, s32 *, s8 *, s32, Key);
void func_001549D0(void);
void func_001B8A60(O *, s32 (*)(s32 **, Key), u32, u32, s16);
typedef struct { Mtx m[5]; } El;
static inline f32 u2f(u32 x) { return x; }
typedef struct { f32 p[3]; s16 r[3]; u16 s[3]; } EA;
static inline void mk(E *e, N *s1, s32 i, s32 j) {
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    u32 k;
    for (k = 0; k < 3; k++) {
        pos[k] = ((f32 *)e)[k];
        rot[k] = 0.00024414062f * ((s16 *)e)[k + 6];
        scl[k] = 0.00024414062f * u2f(((u16 *)e)[k + 9]);
    }
    pos[3] = 1.0f;
    rot[3] = 0.0f;
    scl[3] = 1.0f;
    func_00173FD0(&((El *)s1)[i + 1].m[j], pos, rot, scl);
}
static inline void mk2(E *e, N *s1, s32 i, s32 j) {
    f32 pos[4];
    f32 rot[4];
    f32 scl[4];
    s32 k;
    for (k = 0; k < 3; k++) {
        pos[k] = (&e->x)[k];
        rot[k] = 0.00024414062f * (&e->rx)[k];
        scl[k] = 0.00024414062f * u2f((&e->sx)[k]);
    }
    pos[3] = 1.0f;
    rot[3] = 0.0f;
    scl[3] = 1.0f;
    func_00173FD0(&((El *)s1)[i + 1].m[j], pos, rot, scl);
}

void func_001B37F0(O *o, s32 (*cb)(s32 **, Key)) {
    u32 *tb;
    u32 m1;
    u32 m2;
    u32 m3;
    s16 id;
    s32 c0;
    s32 k;
    s32 **fp;
    s32 i;
    N *s1;
    E *e;
    P8 *p;
    O *a;
    s16 j;
    u32 bit;
    s8 *r;
    s32 s4;
    El *b;
    Key key;
    Vec V;
    Vec X;
    Vec D;
    f32 B[12];
    Vec A;
    Vec C;

    tb = o->x154;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    if (!o->f1D8.f.b0) return;
    id = o->x8C;
    if (o->x8E != -2) id = o->x8E;
    k = id;
    if (k != -1) m1 = tb[k];
    if (D_002022BC != 0 && (a = *D_002022BC) != 0 && a != o) {
        j = a->x8C;
        if (a->x8E != -2) j = a->x8E;
        if (j != -1) m2 = a->x154[j + 0x20];
    }
    fp = o->x178->h;
    s1 = (N *)func_001715B0(fp);
    e = o->x134;
    p = o->x178;
    c0 = **(s32 **)*fp;
    for (i = 0; i < o->n; i++, e++, p++) {
        key.w = e->x2C.w;
        if (e->x18 == -1) continue;
        if (e->f28.f.b0) continue;
        if (!p->f.f.b0) continue;
        e->f28.f.b4 = 0;
        if (k == -1) {
            if (!key.f.b.f.b5) continue;
            if (e->x24 != 0 && D_002022B8 != e->x24) continue;
            bit = 1 << e->x20;
            if (!(m2 & bit)) continue;
        } else {
            bit = 1 << e->x20;
            if (!(m1 & bit)) continue;
        }
        m3 |= bit;
        e->f28.f.b4 = 1;
        if (cb(fp, key) != 0) continue;
        if (e->f28.f.b2) {
            mk(e, s1, i, 5);
            mk2(e, s1, i, 3);
            b = &((El *)s1)[i + 1];
            func_001C93A0(&V);
            func_001029D0(&(&b[1].m[0])->m[3], &(&b[1].m[0])->m[3], &V);
            func_001029D0(&(&b->m[3])->m[3], &(&b->m[3])->m[3], &V);
            ((El *)s1)[i + 2].m[0].m[3].w = 1.0f;
            ((El *)s1)[i + 1].m[3].m[3].w = 1.0f;
        }
        r = e->f28.f.b5 ? func_001B7300(o, e->x25) : 0;
        if (r != 0) {
            func_0015B6B0(&X, r + 0x20);
            func_0015B1C0(&X, r + 0x10);
        } else {
            func_0015B270();
        }
        s4 = e->x21;
        func_001B3710(c0, (s8 *)s1, i + 1, &A, B);
        func_00102A60(&C, &D);
        func_00102A60(&D, &D_003139A0);
        {
            f32 w;
            D.w = 1.0f;
            w = A.w;
            A.w = 1.0f;
            func_001027B0(&A, B, &A);
            A.w = w;
        }
        func_00102A60(&D, &C);
        if ((s8)s4 == -1) {
            func_0016B960((s8 *)s1, &D_0030D0E0, &A, B, 0xC, 0);
        } else {
            func_0016B960((s8 *)s1, &o->x188[(s8)s4], &A, B, 0xC, 0);
        }
        func_0016D830(**(s32 **)*fp, *fp, (s8 *)s1, i + 1, key);
        o->x88++;
    }
    func_001549D0();
    func_001B8A60(o, cb, m1, m3, id);
}
