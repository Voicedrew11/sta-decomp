#include "common.h"
typedef struct {
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:7;
    u8 pad[2];
} F;
typedef union { F f; u32 w; } FU;
typedef struct {
    u8 a0:1; u8 a1:1; u8 a2:1; u8 a3:1; u8 a4:1; u8 a5:1; u8 a6:1; u8 a7:1;
    u8 pad1;
    u8 c0:1; u8 c1:2; u8 c3:1; u8 c4:1; u8 c5:1; u8 c6:2;
    u8 pad3;
} Arg;
typedef struct {
    u16 x0:7; u16 x7:4; u16 x11:1; u16 x12:1; u16 x13:3;
    u8 pad[2];
} Arg2;
typedef union { Arg a; Arg2 b; } AU;
typedef struct { Mtx m; u8 pad[0x134 - 0x40]; f32 s; u8 f0:3; u8 f3:1; u8 f4:1; u8 f5:1; u8 f6:2; u8 pad2[7]; } J;
typedef struct { u8 pad[0xC0]; J j[1]; } K;
typedef struct { s32 x0; s32 x4; } T;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } Ent;
typedef struct { u16 x0; u8 pad[8]; u16 xA; u8 padC[3]; u8 xF; Vec v10; } Hd;
typedef struct {
    Vec v0;
    T *x10;
    u16 x14;
    u16 x16;
    u8 pad18[0xC];
    s32 x24;
    u8 pad28[0x14];
    u8 g0:6; u8 g6:1; u8 g7:1;
    u8 pad3D[3];
    Ent e[1];
} O;
typedef struct { u8 pad[0x24]; u8 g0:1; u8 g1:1; u8 g2:1; u8 g3:1; u8 g4:2; u8 g6:2; u8 h0:1; } S1;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
extern BF D_00222A50[];
extern s32 D_00202008;
extern s32 D_00201F4C;
extern s32 D_00201F48;
void sceVu0CopyVector(Vec *, void *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
s32 func_00153FA0(Vec *);
void func_0016F280(Arg);
void func_0016DED0(Hd *, S1 *, K *, Arg);
void func_0016F440(O *, S1 *, s8 *, s32, F *);
void func_0016EF70(Hd *, s8 *, s8 *, u32, s32, FU);
void func_0016EB70(Hd *, s8 *, s8 *, u32, J *, s32, s32, FU);
void func_0016E760(Hd *, s8 *, s8 *, u32, J *, s32, s32, s8 *, O *, S1 *, FU);

void func_0016CD80(O *o, S1 *s1, K *k2, Arg a) {
    Vec V;
    Vec W;
    FU fl;
    AU b;
    FU g;
    s8 *base;
    Ent *ents;
    s8 *hb;
    J *jt;
    s32 res;
    u32 hdr;
    u8 on;
    s8 *ji;
    s32 sz;
    u32 i;
    u8 k;
    s32 r;
    s8 *q;
    Hd *h;
    s8 *p;

    base = (s8 *)o->x10->x0;
    sz = o->x10->x4 - (s32)base;
    hb = base + o->x24;
    ents = o->e;
    jt = k2->j;
    res = 2;
    fl.w = 0;
    fl.f.b0 = 1;
    fl.f.b1 = 0;
    fl.f.b2 = 0;
    fl.f.b3 = 0;
    fl.f.b4 = 1;
    fl.f.b5 = 0;
    fl.f.b6 = D_00222A50[0].b4;
    fl.f.b7 = 0;
    fl.f.c0 = a.c5;
    if (s1->g6 == 0) {
        b.a = a;
        D_00202008 = D_00201F4C;
        if (!D_00222A50[0].b1 && !(b.b.x7 | b.b.x11 | b.b.x12) && o->g6) {
            D_00202008 = D_00201F48;
        }
        if (!s1->g1) return;
        if (o->x16 == 0 && !s1->h0) {
            if (D_00222A50[0].b3) {
                res = 2;
            } else {
                sceVu0CopyVector(&V, o);
                V.w = 1.0f;
                sceVu0ApplyMatrix(&V, &jt->m, &V);
                V.w = o->v0.w * jt->s;
                res = func_00153FA0(&V);
            }
            if (res < 0) return;
        }
        if (a.c4) {
            a.c1 = 0;
            a.a6 = 1;
            fl.f.b7 = 1;
        }
        func_0016F280(a);
        i = 0;
        if (i < o->x14) {
            on = a.c3;
            do {
                if (i == 0 && on) continue;
                r = res;
                k = i;
                ji = (s8 *)k2 + (k + 1) * 0x140;
                q = base + ents[k].x4;
                p = base + ents[k].x0;
                hdr = *(u16 *)p;
                if (((J *)(ji + 0xC0))->f3) continue;
                h = (Hd *)p;
                if (((J *)(ji + 0xC0))->f5) continue;
                p += 0x10;
                if (h->xF & 1) {
                    if (r == 2) {
                        if (D_00222A50[0].b3) {
                            r = 2;
                        } else {
                            sceVu0CopyVector(&W, &h->v10);
                            W.w = 1.0f;
                            sceVu0ApplyMatrix(&W, &((J *)(ji + 0xC0))->m, &W);
                            W.w = h->v10.w * (&k2->j[k] + 1)->s;
                            r = func_00153FA0(&W);
                        }
                        if (r < 0) continue;
                    }
                    p += 0x10;
                }
                func_0016DED0(h, s1, k2, a);
                if (h->xA != 0xFFFF || !s1->g3) {
                    func_0016F440(o, s1, hb + (u16)h->xA * 64, sz, &fl.f);
                    g = fl;
                    if (r < 2 && !g.f.b5) {
                        func_0016EF70(h, p, q, hdr, sz, g);
                    } else {
                        func_0016EB70(h, p, q, hdr, &jt[k] + 1, r, sz, g);
                    }
                } else {
                    func_0016E760(h, p, q, hdr, &jt[k] + 1, r, sz, hb, o, s1, fl);
                }
            } while (++i < o->x14);
        }
    }
}
