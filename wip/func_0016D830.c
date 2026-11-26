#include "common.h"
typedef union { u32 w; struct { u16 a:7; u16 f:4; u16 g:1; u16 h:1; u16 r:3; u16 hi; } s; } U;
typedef union { u32 w; struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } f; } FL;
typedef struct { s32 x0; s32 x4; } Hdr;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } Ent;
typedef struct { u8 pad[0x10]; Hdr *x10; u8 pad2[0x10]; s32 x24; u8 pad3[0x14]; Flags8 f3C; u8 pad4[3]; Ent tbl[1]; } O;
typedef struct { u8 pad[0x24]; Flags8_6x2 f24; } P;
typedef struct { u8 pad[0x130]; u8 x130; u8 p1[3]; f32 f134; u8 pad2[8]; } E;
typedef struct { u8 pad[0xA]; u16 hA; u8 pad2[3]; u8 xF; Vec v10; } Q;
extern Flags8 D_00222A50[];
extern s32 D_00202008;
extern s32 D_00201F4C;
extern s32 D_00201F48;
void func_0016F280(U);
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, s8 *, Vec *);
s32 func_00153FA0(Vec *);
void func_0016DC70(Q *, P *, s8 *, s32, U);
void func_0016F440(O *, P *, s32, s32, FL *);
void func_0016EF70(Q *, s8 *, s32, s32, s32, FL);
void func_0016EB70(Q *, s8 *, s32, s32, s8 *, s32, s32, FL);
void func_0016E760(Q *, s8 *, s32, s32, s8 *, s32, s32, s32, O *, P *, FL);

void func_0016D830(O *o, P *p, s8 *a2, s32 idx, U u) {
    s32 size;
    s32 x0;
    E *m;
    s32 j;
    u16 hv;
    s32 off;
    Ent *tbl;
    s32 k;
    Q *e;
    s8 *q;
    s32 r;
    Hdr *h;
    s32 base;
    s32 w;
    Vec v;
    FL fl;
    U u2;
    FL fl2;

    tbl = o->tbl;
    h = o->x10;
    m = (E *)(a2 + 0xC0);
    x0 = h->x0;
    size = h->x4 - x0;
    base = x0 + o->x24;
    fl.w = 0;
    fl.f.b0 = 1;
    fl.f.b1 = 0;
    fl.f.b2 = 0;
    fl.f.b3 = 0;
    fl.f.b4 = 1;
    fl.f.b5 = 0;
    fl.f.b6 = D_00222A50[0].f.b4;
    fl.f.b7 = 0;
    k = 2;
    if (p->f24.f.b6 != 0) return;
    u2 = u;
    D_00202008 = D_00201F4C;
    if (!D_00222A50[0].f.b1) {
        if ((u2.s.f | u2.s.g | u2.s.h) == 0 && o->f3C.f.b6) D_00202008 = D_00201F48;
    }
    if (!p->f24.f.b1) return;
        j = m[idx].x130;
    q = (s8 *)(x0 + tbl[j].x0);
    e = (Q *)q;
    r = x0 + tbl[j].x4;
    w = *(u16 *)q;
    if (j == 0xFF) return;
    if (((Flags8 *)(a2 + idx * 0x140 + 0x1F8))->f.b3) return;
    if (((Flags8 *)(a2 + idx * 0x140 + 0x1F8))->f.b5) return;
    func_0016F280(u);
    q += 0x10;
    if (e->xF & 1) {
        if (D_00222A50[0].f.b3) {
            k = 2;
        } else {
            func_00102A60(&v, &e->v10);
            v.w = 1.0f;
            func_001027B0(&v, (s8 *)&m[idx], &v);
            v.w = e->v10.w * m[idx].f134;
            k = func_00153FA0(&v);
        }
        if (k < 0) return;
        q += 0x10;
    }
    func_0016DC70(e, p, a2, idx, u);
    if ((hv = e->hA) != 0xFFFF || !p->f24.f.b3) {
        func_0016F440(o, p, base + hv * 64, size, &fl);
        fl2 = fl;
        if (k < 2 && !fl2.f.b5) {
            func_0016EF70(e, q, r, w, size, fl2);
        } else {
            func_0016EB70(e, q, r, w, (s8 *)&m[idx], k, size, fl2);
        }
    } else {
        func_0016E760(e, q, r, w, (s8 *)&m[idx], k, size, base, o, p, fl);
    }
}
