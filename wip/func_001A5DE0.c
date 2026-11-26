


#include "common.h"
typedef union { f32 f; Flags8 f8; } Col;
typedef struct { Vec p; Vec r; u8 pad[0x40]; Col c; } P;
typedef struct { u8 pad[0x160]; Flags8 f; u8 pad2[3]; s32 h; u8 pad3[8]; } E;
typedef struct { u8 pad[0x240]; Col c; } C;
typedef struct { u16 **pp; u8 pad[0x20]; Flags8 f; } H2;
typedef struct { H2 *h; } H;
typedef struct { u128 q[10]; } Big;
typedef struct { u8 pad[0x20]; u8 x20; s8 x21; u8 pad22[2]; u8 x24; u8 pad25[8]; Flags8 x2D; } A;
typedef struct { u8 pad[0xBC]; u8 xBC; } G2;
typedef struct {
    u8 pad0[0x8C];
    s16 x8C;
    s16 x8E;
    u8 pad90[0x154 - 0x90];
    s32 *x154;
    G2 *x158;
    u8 pad15C[0x188 - 0x15C];
    Big *x188;
} G;
typedef struct { u8 pad[0xC0]; G *xC0; A *xC4; A *xC8; } X;
typedef struct { u8 pad[0x10]; X *x10; } B;
typedef struct { u8 pad[0xB0]; H *xB0; u8 padB4[0x180 - 0xB4]; B x180; } S;
typedef struct {
    u8 pad0[0x78];
    s32 n;
    u8 pad7C[0x19A - 0x7C];
    u8 a[0x100];
    u8 b[0x100];
    u8 pad39A[0x4A8 - 0x39A];
    G **x4A8;
    u8 pad4AC[2];
    s16 x4AE;
    C *x4B0;
    P *tbl[0x19];
    S *x518;
    E *x51C;
    u8 pad520[0x30];
    Vec x550;
    Vec x560;
    u8 pad570[0x30];
    Flags8 f5A0;
    Flags8 f5A1;
} O;
typedef struct { Vec m[2]; } M;
extern Flags8 D_00222A50[];
extern G **D_00201E80[2];
extern G **D_002022BC;
extern u32 D_002022B8;
extern f32 D_00201DAC;
extern Big D_0030D0E0;
extern Vec D_001F37A0;
extern f32 D_001FD910[];
extern f32 D_001FD914[];
extern f32 D_001FD918[];
extern f32 D_001FD91C[];
extern f32 D_001FD950[];
s8 *func_001715B0(H *);
void func_001A7030(O *, s32, s32);
s32 func_0016B360(H *, Col, u8);
void func_0016B480(Col, u8);
void func_0016B960(s8 *, s32, u16 *, s8 *, s32, s32);
void func_0015B6B0(Vec *, Vec *);
void func_0015B1C0(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
void func_0016D380(u16 *, H2 *, s8 *, s32, Col, u8);
void func_001502A0(M *, P *, Vec *, f32);
void func_00167670(s32, M *);
void func_001677C0(s32, s8 *);
void func_001549D0(void);
s32 func_0013E5E0(O *);
f32 func_0013E460(O *);
u8 func_0013E4E0(O *);
s32 func_0013D1E0(O *);
void func_0013D1C0(O *);
f32 func_0013D6C0(O *);
void func_0015CC80(s8 *, Vec *, f32);
void func_0015CC40(s8 *, f32);
void func_001C9C00(Vec *);
void func_0016C350(u16 *, H2 *, s8 *, Vec *);

static inline f32 lp(f32 a, f32 b, f32 f, f32 u) { return f * a + b * u; }
void func_001A5DE0(O *o) {
    Col c;
    Col c3;
    Col c2;
    u32 sv;
    u8 fl;
    u16 *x;
    s32 i;
    P *p;
    u8 low;
    H *h;
    s8 *r;
    E *ee;
    B *b;
    G *g;
    X *e;
    A *a3;
    A *a2;
    G **pp;
    G *t;
    s32 *tb;
    s32 m1;
    s32 m0;
    s16 sel;
    s16 idx;
    u8 k;
    f32 f;
    f32 u;
    Vec q;
    Vec pv;
    Vec v;
    Vec cv;
    M m;
    Vec buf;

    fl = 0;
    low = 0;
    sv = D_00222A50[0].f.b3;
    if (o == NULL) return;
    h = o->x518->xB0;
    x = *h->h->pp;
    r = func_001715B0(h);
    b = &o->x518->x180;
    if (!h->h->f.f.b1) return;
    g = NULL;
    idx = -1;
    if (o->x4A8 != NULL) {
        g = *o->x4A8;
        m0 = 0;
        e = b->x10;
        a3 = e->xC4;
        a2 = e->xC8;
        m1 = 0;
        if (D_00201E80[2] != NULL && *D_00201E80[2] != NULL && *D_00201E80[2] == e->xC0) g = e->xC0;
        if (D_00201E80[3] != NULL && *D_00201E80[3] != NULL && *D_00201E80[3] == e->xC0) g = e->xC0;
        tb = g->x154;
        sel = g->x8C;
        if (g->x8E != -2) sel = g->x8E;
        if (sel != -1) m1 = tb[sel];
        if ((pp = D_002022BC) != NULL && (t = *pp) != NULL && t != g && t->x8C != -1) m0 = t->x154[t->x8C + 0x20];
        if (sel == -1) {
            if (a3 != NULL) {
                if (!a3->x2D.f.b5) return;
                if (a3->x24 != 0 && D_002022B8 != a3->x24) return;
                if (!(m0 & (1 << a3->x20))) return;
            }
            if (a2 != NULL && !(m0 & (1 << a2->x20))) return;
        } else {
            if (a3 != NULL && !(m1 & (1 << a3->x20))) return;
            if (a2 != NULL && !(m1 & (1 << a2->x20))) return;
        }
        idx = o->x4AE;
        if (idx == -1) {
            if (a3 != NULL) idx = a3->x21;
            if (a2 != NULL) idx = a2->x21;
        }
        if (g != NULL) low = g->x158->xBC & 1;
    }
    if (idx == -1 || g == NULL) {
        *(Big *)(r + 0x10) = D_0030D0E0;
    } else {
        *(Big *)(r + 0x10) = g->x188[idx];
    }
    func_001A7030(o, 1, 0);
    o->f5A1.f.b6 = 1;
    if (low) {
        func_0016B360(h, o->x4B0->c, 0);
        func_0016B960(r, 0, x, r + 0x280, 0, 2);
        func_0015B6B0(&v, &o->x560);
        func_0015B1C0(&v, &o->x550);
        for (i = 0; i < o->n; i++) {
            k = o->a[i];
            if (k == 0xFF) {
                c = o->x4B0->c;
            } else {
                c = o->tbl[k]->c;
            }
            if (func_0016B360(h, c, 0)) func_0016B960(r, 0, x, r + 0x280, 0, 2);
            if (c.f8.f.b2) func_0016D380(*h->h->pp, h->h, r, i, c, 0);
        }
        func_001549D0();
    }
    c2 = o->x4B0->c;
    func_0016B360(h, c2, 3);
    func_0016B960(r, 0, x, r + 0x280, 0, 2);
    if (func_0013E5E0(o)) {
        u8 j;
        f = func_0013E460(o);
        j = func_0013E4E0(o);
        if (!(f <= 1.0f)) f = 2.0f - f;
        u = 1.0f - f;
        q.x = lp(D_001FD910[j * 4], o->x550.x, f, u);
        q.y = lp(D_001FD914[j * 4], o->x550.y, f, u);
        q.z = lp(D_001FD918[j * 4], o->x550.z, f, u);
        q.w = lp(D_001FD91C[j * 4], o->x550.w, f, u);
        pv.x = o->x560.x;
        pv.y = o->x560.y;
        pv.z = lp(D_001FD950[j], o->x560.z, f, u);
        pv.w = lp(D_001FD950[j], o->x560.w, f, u);
        func_0015B6B0(&pv, &pv);
        func_0015B1C0(&pv, &q);
    } else {
        func_0015B6B0(&pv, &o->x560);
        sceVu0CopyVector(&q, &o->x550);
        func_0015B1C0(&pv, &q);
    }
    if (func_0013D1E0(o)) {
        cv = D_001F37A0;
        cv.x *= D_00201DAC;
        cv.y *= D_00201DAC;
        cv.z *= D_00201DAC;
        func_0015CC80(r + 0x10, &cv, 1.0f);
        D_00201DAC -= 0.05f;
        if (D_00201DAC < 0.0f) D_00201DAC = 1.0f;
        func_0013D1C0(o);
    }
    f = func_0013D6C0(o);
    func_0015CC40(r + 0x10, f);
    if (f < 1.0f) fl = 1;
    for (i = 0; i < o->n; i++) {
        k = o->a[i];
        p = o->tbl[k];
        if (k == 0xFF) {
            c2 = o->x4B0->c;
        } else {
            c2 = p->c;
        }
        c2.f8.f.b4 |= fl;
        if (func_0016B360(h, c2, 3)) {
            func_0015B1C0(&pv, &q);
            func_0016B960(r, 0, x, r + 0x280, 0, 2);
        }
        if (!c2.f8.f.b3) func_0016D380(*h->h->pp, h->h, r, i, c2, fl);
        k = o->b[i];
        p = o->tbl[k];
        ee = &o->x51C[k];
        if (k == 0xFF) continue;
        if (ee->h == 0) continue;
        if (ee->f.f.b2) continue;
        func_001502A0(&m, p, &p->r, p->p.w);
        func_00167670(ee->h, &m);
        func_001677C0(ee->h, (r + (i + 1) * 0x140) + 0xC0);
    }
    func_001549D0();
    if (!D_00222A50[0].f.b6 && !(f <= 0.5f) && x[0xF] != 0) {
        c3 = c2;
        c3.f8.f.b4 = 0;
        func_0016B480(c3, 4);
        func_001C9C00(&buf);
        func_0016C350(*h->h->pp, h->h, r, &buf);
        func_001549D0();
    }
    D_00222A50[0].f.b3 = sv;
}


