#include "common.h"
typedef struct { s32 x0; s32 x4; u8 p8[8]; } E16;
typedef struct {
    u8 p0[0x10]; s32 *x10; u8 p14[0x10]; s32 x24; u8 p28[0x14]; Flags8 x3C; u8 p3D[3];
    E16 e[1];
} Obj;
typedef struct { u8 p0[0x24]; union { Flags8 f; struct { u8 lo:6; u8 hi:2; } h; } x24; } Oth;
typedef struct { u16 x0; u8 p2[8]; u16 xA; u8 pC[3]; u8 xF; Vec x10; } Ent;
typedef union {
    u32 w;
    struct { u16 a:7; u16 b:4; u16 c:1; u16 d:1; u16 e:3; u8 g0:1; u8 g1:2; u8 g3:5; u8 pad3; } f;
} P;
typedef union {
    u32 w;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; u8 pad[3]; } f;
} L;
typedef struct { u8 pad[0x134]; f32 x134; } M;
extern Flags8 D_00222A50[];
extern s32 D_00201F48;
extern s32 D_00201F4C;
extern s32 D_00202008;
void func_0016F280(P);
void func_0016DED0(Ent *, Oth *, s8 *, P);
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, s8 *, Vec *);
s32 func_00153FA0(Vec *);
void func_0016F440(Obj *, Oth *, s8 *, s32, L *);
void func_0016EF70(Ent *, s8 *, s8 *, u32, s32, L);
void func_0016EB70(Ent *, s8 *, s8 *, u32, s8 *, s32, s32, L);
void func_0016E760(Ent *, s8 *, s8 *, u32, s8 *, s32, s32, s8 *, Obj *, Oth *, L);

static inline s32 chk(P q) { return q.f.b | q.f.c | q.f.d; }

void func_0016D380(Obj *o, Oth *b, s8 *c, s32 n, P p, s32 flag) {
    s8 *base;
    E16 *e;
    E16 *ep;
    s8 *tbl;
    s8 *cc;
    u32 d0;
    s8 *ce;
    u8 idx;
    s32 len;
    s8 *fp;
    s32 r;
    s8 *s0;
    Ent *h;
    u16 k;
    L l;
    P sv;
    P q;
    L l2;
    Vec v;

    base = (s8 *)o->x10[0];
    ep = o->e;
    tbl = base + o->x24;
    len = o->x10[1] - (s32)base;
    l.w = 0; l.f.b0 = 1; l.f.b1 = 0; l.f.b2 = 0; l.f.b3 = 0; l.f.b4 = 1; l.f.b5 = 0; l.f.b6 = D_00222A50[0].f.b4; idx = flag; l.f.b7 = idx;
    cc = c + 0xC0;
    r = 2;
    if (b->x24.h.hi) return;
    q = p;
    D_00202008 = D_00201F4C;
    if (!D_00222A50[0].f.b1 && !(q.f.b | q.f.c | q.f.d) && o->x3C.f.b6) {
        D_00202008 = D_00201F48;
    }
    if (!b->x24.f.f.b1) return;
    if (flag) {
        sv = p;
        p.f.g1 = 0;
        func_0016F280(p);
        p = sv;
    } else {
        func_0016F280(p);
    }
    idx = n;
    e = ep + idx;
    ce = c + (idx + 1) * 0x140;
    s0 = base + e->x0;
    fp = base + e->x4;
    d0 = *(u16 *)s0;
    h = (Ent *)s0;
    if (((Flags8 *)(ce + 0x1F8))->f.b3) return;
    if (((Flags8 *)(ce + 0x1F8))->f.b5) return;
    s0 += 0x10;
    if (h->xF & 1) {
        if (D_00222A50[0].f.b3) {
            r = 2;
        } else {
            func_00102A60(&v, &h->x10);
            v.w = 1.0f;
            func_001027B0(&v, ce + 0xC0, &v);
            v.w = h->x10.w * *(f32 *)(idx * 0x140 + c + 0x334);
            r = func_00153FA0(&v);
        }
        if (r < 0) return;
        s0 += 0x10;
    }
    func_0016DED0(h, b, c, p);
    k = h->xA;
    if (k != 0xFFFF || !b->x24.f.f.b3) {
        func_0016F440(o, b, tbl + k * 64, len, &l);
        l2 = l;
        if (r < 2 && !l2.f.b5) {
            func_0016EF70(h, s0, fp, d0, len, l2);
        } else {
            func_0016EB70(h, s0, fp, d0, cc + idx * 0x140 + 0x140, r, len, l2);
        }
    } else {
        func_0016E760(h, s0, fp, d0, cc + idx * 0x140 + 0x140, r, len, tbl, o, b, l);
    }
}
