#include "common.h"
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[8]; u8 x2A; u8 pad2B[2]; Flags8 x2D; } Part;
typedef struct { u8 pad[0x15C]; u16 x15C; u8 pad15E[2]; Flags8 x160; u8 pad161[0xF]; } Ent;
typedef struct { u8 pad[0xB0]; s32 **xB0; u8 padB4[0xB8]; u32 x16C; u8 pad170[0x3C]; u8 *x1AC; } Sub;
typedef struct { u8 pad[6]; u16 h6; } Hdr;
typedef struct {
    u8 pad[0x78];
    u32 x78;
    u8 pad7C[0x1E];
    u8 x9A[0x416];
    u16 *x4B0;
    Part *tbl[0x19];
    Sub *x518;
    Ent *x51C;
    u8 pad520[0x90];
    Flags8 f5B0;
    u8 pad5B1[3];
    Flags8 f5B4;
    u8 pad5B5[0x54];
    s8 x609;
    u8 pad60A[0xB0];
    s16 x6BA;
} A;
extern s32 D_00201F2C;
void func_001A8B10(A *, u8);
void func_001A8700(A *, u8);
void func_00141DA0(A *);
void func_00142010(A *, u8);
void func_001BC320(u8 *, s32);

static inline s32 clamp(s32 v, s32 hi) {
    if (v < 0) v = 0;
    if (hi < v) v = hi;
    return v;
}

static inline void upd(Ent *e, s32 lim) {
    e->x15C = clamp(e->x15C - lim, lim);
}

static inline void upd3(A *a, u8 k) { Ent *e = &a->x51C[k]; e->x15C = clamp(e->x15C - a->tbl[k]->x20, a->tbl[k]->x20); }

void func_0013F210(A *a, u8 idx, s32 flag) {
    u8 k;
    Part *p;
    Part **pp;
    Ent *e;
    u8 i;
    u8 *base;
    u8 *t;
    u8 m, n;
    s32 lim;
    s32 neg;
    u32 *f;
    Hdr *h;
    u8 *b0;
    u8 *b1;

    k = a->x9A[0x300 + a->tbl[idx]->x2A];
    p = a->tbl[k];
    pp = &a->tbl[k];
    e = &a->x51C[k];
    a->f5B4.f.b7 = 1;
    e->x160.f.b0 = 1;
    e->x160.f.b2 = 1;
    base = a->x518->x1AC + 0xC0;
    for (i = 1; i < a->x78 + 1; i++) {
        t = base + i * 0x140;
        m = a->x9A[t[0x130]];
        n = a->x9A[(base + t[0x131] * 0x140)[0x130]];
        if (n != 0xFF && m != 0xFF && a->x51C[n].x160.f.b0) {
            e = &a->x51C[m];
            e->x160.f.b0 = 1;
            e->x160.f.b2 = 1;
            upd(&a->x51C[m], a->tbl[m]->x20);
        }
    }
    if (flag) {
        upd3(a, k);
        neg = -(*pp)->x20;
        f = &a->x518->x16C;
        *f = (u16)clamp(*(u16 *)f + neg, *a->x4B0);
        a->x6BA = neg;
        func_001A8B10(a, k);
        if ((*pp)->x2D.f.b1) {
            a->f5B0.f.b0 = 1;
            func_00141DA0(a);
        }
    } else {
        h = (Hdr *)*a->x518->xB0;
        b0 = (u8 *)((s32)h + 0x40) + D_00201F2C * (h->h6 * 0x140 + 0x200);
        b1 = (u8 *)((s32)h + 0x40) + !D_00201F2C * (h->h6 * 0x140 + 0x200);
        func_001BC320(b1 + (b0 + (*pp)->x2A * 0x140)[0x331] * 0x140 + 0xF0, a->x609);
        if (p->x2D.f.b2) {
            func_001A8700(a, k);
        } else {
            func_001A8B10(a, k);
        }
    }
    func_00142010(a, k);
}
