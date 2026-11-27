#include "common.h"
#include "m2c.h"
#include "actor.h"
typedef union { f32 f; Flags8 f8; } Col;
typedef struct { Vec p; Vec r; u8 pad[0x40]; Col c; } P_func_001A5DE0;
typedef struct { u8 pad[0x160]; Flags8 f; u8 pad2[3]; s32 h; u8 pad3[8]; } E_func_001A5DE0;
typedef struct { u8 pad[0x240]; Col c; } C;
typedef struct { u16 **pp; u8 pad[0x20]; Flags8 f; } H2;
typedef struct { H2 *h; } H;
typedef struct { u128 q[10]; } Big;
typedef struct { u8 pad[0x20]; u8 x20; s8 x21; u8 pad22[2]; u8 x24; u8 pad25[8]; Flags8 x2D; } A_func_001A5DE0;
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
typedef struct { u8 pad[0xC0]; G *xC0; A_func_001A5DE0 *xC4; A_func_001A5DE0 *xC8; } X;
typedef struct { u8 pad[0x10]; X *x10; } B_func_001A5DE0;
typedef struct { u8 pad[0xB0]; H *xB0; u8 padB4[0x180 - 0xB4]; B_func_001A5DE0 x180; } S_func_001A5DE0;
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
    P_func_001A5DE0 *tbl[0x19];
    S_func_001A5DE0 *x518;
    E_func_001A5DE0 *x51C;
    u8 pad520[0x30];
    Vec x550;
    Vec x560;
    u8 pad570[0x30];
    Flags8 f5A0;
    Flags8 f5A1;
} O_func_001A5DE0;
typedef struct { Vec m[2]; } M_func_001A5DE0;
typedef struct { u8 pad[0x1D8]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } R;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct {
    u16 v0;
    u8 pad2[0x4A6];
    R **r;
    u8 pad4ac[0x5A0 - 0x4AC];
    u8 f5a0;
    B8 f5a1;
} P_func_001A6770;
typedef struct { f32 x, y, z, w; } V;
typedef struct { u8 pad[0x10]; s32 *x10; } M_func_001A6950;
typedef struct A_func_001A6950 {
    u16 m0;
    u8 pad2[2];
    M_func_001A6950 **m4;
    s32 *m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18[0x19];
    s32 m7C;
    u8 pad80[0x4B0 - 0x80];
    s32 m4B0;
    s32 m4B4[0x18];
    s32 m514;
    s32 m518;
    s32 m51C;
    u8 pad520[0x80];
    Flags8 f5A0;
} A_func_001A6950;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x28]; B8 x3C; } Q_func_001A6A10;
typedef struct { u8 pad[0xC]; B8 xC; } F;
typedef struct { u8 pad[0xB0]; s32 xB0; u8 padB4[0x70]; s32 x124[8]; } S_func_001A6A10;
typedef struct { u8 pad[0x164]; s32 x164; u8 pad168[8]; } E_func_001A6A10;
typedef struct {
    u16 x0;
    u16 x2;
    Q_func_001A6A10 **x4;
    s32 x8;
    u8 padC[0x70];
    s32 x7C;
    u8 pad80[0x41C];
    s32 x49C;
    u8 pad4A0[4];
    s32 x4A4;
    u8 pad4A8[8];
    F *x4B0;
    u8 pad4B4[0x64];
    S_func_001A6A10 *x518;
    E_func_001A6A10 *x51C;
    u8 pad520[0x60];
    u8 x580[0x20];
    u16 pad5A0a:3;
    u16 x5A0:8;
} P_func_001A6A10;
typedef struct { u8 pad[0x5A0]; u8 b0:1; u8 b1:1; u8 b2:1; u8 r:5; } A_func_001A6C10;
typedef struct { char pad[0x5A1]; unsigned char : 4; unsigned char f : 1; } BF_5A1_4_1;
typedef struct { char pad[0x5A0]; unsigned char : 2; unsigned char f : 1; } BF_5A0_2_1;
typedef struct {
    u8 pad[0xB0];
    s32 *pB0;
    u8 padB4[0xC];
    u8 mC0[0x60];
    Flags8 f120;
    u8 pad121[0x23];
    u8 m144[0x28];
    s32 m16C;
} Sub_func_001A6DC0;
typedef struct {
    u8 m00[0x20];
    u8 m20[0x20];
    u8 m40[0x20];
    u8 m60[0x20];
    u8 pad80[0xC];
    s32 m8C;
    u8 pad90[0xC];
    s32 m9C;
    u8 padA0[0xBC];
    u16 m15C;
    u8 pad15E[2];
    Flags8 f160;
    u8 pad161[0xF];
} Ent_func_001A6DC0;
typedef struct { u8 pad[0x20]; u16 m20; u8 pad22[0x8A]; f32 mAC; } Src_func_001A6DC0;
typedef struct { char pad[0x2D]; s8 v; char rest[0x26]; } E_func_001A6FF0;
typedef struct { char pad[0x13C]; E_func_001A6FF0 *tbl; } T_func_001A6FF0;
typedef struct { T_func_001A6FF0 *t; } B_func_001A6FF0;
typedef struct { char pad[0x4A8]; B_func_001A6FF0 *b; u16 i; s16 v; } Obj;
typedef struct { u8 pad[0x160]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; u8 pad2[3]; void *h; u8 pad3[0x170-0x168]; } S_func_001A7030;
typedef struct { u8 pad[0x2E2]; u8 idx; u8 pad2[0x40-0x2E3+0x2E2]; } T_func_001A7030;
typedef struct { u8 pad[0x124]; void *h[8]; } U;
typedef struct { u8 pad[0x7C]; s32 n; u8 pad1[0x9A-0x80]; u8 map[0x4B0-0x9A]; T_func_001A7030 *t; u8 pad2[0x518-0x4B4]; s8 *u; S_func_001A7030 *s; } O_func_001A7030;
typedef struct { u8 pad[0x10]; s32 x10; } M_func_001A71B0;
typedef struct { M_func_001A71B0 *m; } MP;
typedef struct { u8 pad[0x2C]; u32 pad2:14; u32 id:10; } Def;
typedef struct { u8 pad[0x160]; u8 b0:1; u8 b1:1; u8 pad2[3]; s32 x164; u8 pad3[0x8]; } Ent_func_001A71B0;
typedef struct { u8 pad[0xC]; u8 c0:6; u8 c6:1; u8 pad2[0x2E0 - 0xD]; u16 id; u8 pad3[0x3E]; } T0;
typedef struct { u8 pad[0x120]; u16 a:2; u16 m:8; u16 pad1:6; u16 pad2; s32 x124[8]; } Q_func_001A71B0;
typedef struct {
    u8 pad[4];
    MP *mp;
    u8 pad8[0x74];
    s32 n;
    u8 pad80[0x4B0 - 0x80];
    u8 *t;
    Def *defs[(0x518 - 0x4B4) / 4];
    Q_func_001A71B0 *q;
    Ent_func_001A71B0 *ents;
    u8 pad520[0x60];
    u8 buf[1];
} O_func_001A71B0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct { u8 pad[6]; u16 m6; u8 pad8[0x1C]; Bits f24; u8 pad25[0x1B]; u8 m40[1]; } Mdl;
typedef struct {
    Vec m0;
    Vec m10;
    Vec m20;
    Vec m30;
    Vec m40;
    Vec m50;
    u8 pad60[0x50];
    Mdl **pB0;
    u8 mB4;
    u8 mB5;
    u8 mB6;
    u8 mB7;
    u8 padB8[0xB4];
    s32 m16C;
    f32 m170;
} Sub_func_001A7420;
typedef struct {
    u8 pad0[0x8C];
    s32 m8C;
    u8 pad90[0xC];
    s32 m9C;
    u8 padA0[0xBC];
    u16 m15C;
    u8 pad15E[6];
    s32 m164;
    u8 pad168[8];
} Ent_func_001A7420;
typedef struct { u8 pad[0x20]; u16 m20; u8 pad22[8]; u8 m2A; u8 pad2B; u8 m2C; u8 pad2D[0x7F]; f32 mAC; } Src_func_001A7420;
typedef struct A_func_001A7420 {
    u16 m0;
    u8 pad2[2];
    s32 ***m4;
    s32 **m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18[0x19];
    s32 m7C;
    u8 pad80;
    u8 m81;
    u8 m82[0x41A];
    s32 m49C;
    s32 m4A0;
    s32 m4A4;
    s32 *m4A8;
    u16 m4AC;
    u8 pad4AE[2];
    s32 m4B0;
    Src_func_001A7420 *m4B4[0x18];
    s32 m514;
    Sub_func_001A7420 *m518;
    s32 m51C;
    u8 pad520[0x80];
    Bits f5A0;
} A_func_001A7420;
typedef void (*Fn)(A_func_001A7420 *, f32);
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
extern P_func_001A6770 **D_004A4570[];
extern s16 D_004A4774[];
extern u16 D_004A4776[];
extern s32 D_00202278;
extern s32 D_00202280;
extern s8 D_001F2170[];
extern Fn D_001F33A0[];
extern Vec D_001F2120;
extern s32 D_00201F2C;
void func_001A5DE0(O_func_001A5DE0 *o);
void func_001A6770(void);
void func_001A6950(void);
void func_001A6A10(P_func_001A6A10 **a0);
void func_001A6C10(A_func_001A6C10 *a);
void func_001A6C90(u8 *arg0);
void func_001A6DC0(Actor *a0);
void func_001A6FF0(Obj *o, B_func_001A6FF0 *b, u16 i);
void func_001A7030(O_func_001A7030 *arg0, s32 arg1, s32 arg2);
void func_001A71B0(O_func_001A71B0 *o);
void func_001A7420(A_func_001A7420 **pp);
s8* func_001715B0(H *);
s32 func_0016B360(H *, Col, u8);
void func_0016B480(Col, u8);
void func_0016B960(s8 *, s32, u16 *, s8 *, s32, s32);
void func_0015B6B0(Vec *, Vec *);
void func_0015B1C0(Vec *, Vec *);
void sceVu0CopyVector(void *, void *);
void func_0016D380(u16 *, H2 *, s8 *, s32, Col, u8);
void func_001502A0(M_func_001A5DE0 *, P_func_001A5DE0 *, Vec *, f32);
void func_00167670(s32, M_func_001A5DE0 *);
void func_001677C0(s32, s8 *);
void func_001549D0(void);
s32 func_0013E5E0(O_func_001A5DE0 *);
f32 func_0013E460(O_func_001A5DE0 *);
u8 func_0013E4E0(O_func_001A5DE0 *);
s32 func_0013D1E0(O_func_001A5DE0 *);
void func_0013D1C0(O_func_001A5DE0 *);
f32 func_0013D6C0(O_func_001A5DE0 *);
void func_0015CC80(s8 *, Vec *, f32);
void func_0015CC40(s8 *, f32);
void func_001C9C00(Vec *);
void func_0016C350(u16 *, H2 *, s8 *, Vec *);
void func_001548F0(s32);
void func_001329D0(s32, s32, s32);
void func_00155900(void);
s32 func_0013E2B0(P_func_001A6770 *);
void func_00132930(V *);
void func_0016B280(void);
void func_00167030(s32);
void func_00178030(s32);
void func_001745D0(s32, s32);
void func_00128580(s32, void *);
void func_00169D00(void *, s32);
void func_001A5070(P_func_001A6A10 **);
void func_00167580(A_func_001A6C10 *);
void sceVu0AddVector(void *, void *, void *);
void memset(void *, s32, s32);
void func_001A8510(Actor *, u8);
void func_001A8670(Actor *, u8);
void func_00166F90(s32, s32, s32, s32);
void func_00171270(s32, s8 *, s32);
void func_00167640(void *, s32);
s32 func_00169BB0(s32);
s32 func_00169B50(s32, s32, s32, s32);
s32 func_00169BD0(s32, s32, void *, s32, s32, s32);
void func_00169D70(s32, void *, s32);
Mdl** func_00174230(s32, s32 ***, s32, s32);
void func_00171540(Mdl *, s8 *);
void func_001B59E0(s8 *, Vec *, Vec *, Vec *);
void func_00142930(u8, u8 *);
s32 func_001288C0(s32, s32);
void func_001A7E60(A_func_001A7420 *);

/* func_001A5DE0 */
#define func_001A7030 func_001A7030__as_func_001A5DE0
void func_001A7030__as_func_001A5DE0(O_func_001A5DE0 *, s32, s32);
#define sceVu0CopyVector sceVu0CopyVector__as_func_001A5DE0
void sceVu0CopyVector__as_func_001A5DE0(Vec *, Vec *);

static inline f32 lp(f32 a, f32 b, f32 f, f32 u) { return f * a + b * u; }
void func_001A5DE0(O_func_001A5DE0 *o) {
    Col c;
    Col c3;
    Col c2;
    u32 sv;
    u8 fl;
    u16 *x;
    s32 i;
    P_func_001A5DE0 *p;
    u8 low;
    H *h;
    s8 *r;
    E_func_001A5DE0 *ee;
    B_func_001A5DE0 *b;
    G *g;
    X *e;
    A_func_001A5DE0 *a3;
    A_func_001A5DE0 *a2;
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
    M_func_001A5DE0 m;
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
        s32 jj;
        f = func_0013E460(o);
        j = func_0013E4E0(o);
        if (!(f <= 1.0f)) f = 2.0f - f;
        u = 1.0f - f;
        jj = j;
        q.x = lp(D_001FD910[jj * 4], o->x550.x, f, u);
        q.y = lp(D_001FD914[jj * 4], o->x550.y, f, u);
        q.z = lp(D_001FD918[jj * 4], o->x550.z, f, u);
        q.w = lp(D_001FD91C[jj * 4], o->x550.w, f, u);
        pv.x = o->x560.x;
        pv.y = o->x560.y;
        pv.z = lp(D_001FD950[jj], o->x560.z, f, u);
        pv.w = lp(D_001FD950[jj], o->x560.w, f, u);
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
#undef func_001A7030
#undef sceVu0CopyVector

/* func_001A6770 */
#define D_00222A50 D_00222A50__as_func_001A6770
extern B8 D_00222A50__as_func_001A6770[];
#define func_001A7030 func_001A7030__as_func_001A6770
void func_001A7030__as_func_001A6770(P_func_001A6770 *, s32, s32);
#define func_001A5DE0 func_001A5DE0__as_func_001A6770
void func_001A5DE0__as_func_001A6770(P_func_001A6770 *);
#define func_001C9C00 func_001C9C00__as_func_001A6770
u32 func_001C9C00__as_func_001A6770(s32);
static inline void setb6(P_func_001A6770 *p, s32 v) { p->f5a1.b6 = v; }

void func_001A6770(void) {
    V v;
    s32 i;
    P_func_001A6770 ***pp;
    if (!D_00222A50[0].b6) {
        func_001548F0(4);
        func_001329D0(0x15E, 0x100, 0x100);
        func_00155900();
    }
    i = 0;
    pp = D_004A4570;
    for (; i < 0x81; i++, pp++) {
        P_func_001A6770 **q = *pp;
        if (q != NULL) {
            P_func_001A6770 *p = *q;
            if (p != NULL && p->v0 != 0) {
                func_001A7030(p, 0, 0);
                setb6(p, 0);
                if (!p->f5a1.b5) {
                    R **rr = p->r;
                    R *r;
                    if (rr == NULL || (r = *rr) == NULL || !r->b3) {
                        u8 f = p->f5a0;
                        if ((f & 1) && ((u64)((s64)f << 0x3D) >> 0x3F) && func_0013E2B0(p) != 0) {
                            func_001A5DE0(p);
                        }
                    }
                }
            }
        }
    }
    if (!D_00222A50[0].b6) {
        func_001548F0(4);
        v.w = (f32)func_001C9C00(0) / 255.0f;
        func_00132930(&v);
        func_00155900();
    }
    func_0016B280();
}
#undef func_001A7030
#undef func_001A5DE0
#undef func_001C9C00
#undef D_00222A50

/* func_001A6950 */
#define D_004A4570 D_004A4570__as_func_001A6950
extern A_func_001A6950 **D_004A4570__as_func_001A6950[];
void func_001A6950(void) {
    s32 i;
    for (i = 0; i < 0x81; i++) {
        A_func_001A6950 **p = D_004A4570[i];
        if (p) {
            A_func_001A6950 *a = *p;
            if (a->f5A0.b & 1) {
                s32 j;
                s32 base = *(*a->m4)->x10;
                a->m4B0 = base + a->m10;
                a->m514 = base + a->m14;
                for (j = 0; j < a->m7C; j++) {
                    a->m4B4[j] = base + a->m18[j];
                }
                a->m518 = *a->m8;
                a->m51C = a->m518 + 0x640;
            }
        }
    }
}
#undef D_004A4570

/* func_001A6A10 */
#define D_004A4570 D_004A4570__as_func_001A6A10
extern s32 D_004A4570__as_func_001A6A10[];

void func_001A6A10(P_func_001A6A10 **a0) {
    P_func_001A6A10 *p;
    Q_func_001A6A10 **q;
    s32 i;
    S_func_001A6A10 *s;

    p = *a0;
    q = p->x4;
    D_004A4570[p->x2] = 0;
    { u16 v = (*a0)->x2; s16 n = D_004A4774[0]++; D_004A4776[n] = v; }
    if (p->x8 != 0) {
        for (i = 0; i < p->x7C; i++) {
            if (p->x51C[i].x164 != 0) {
                func_00167030(p->x51C[i].x164);
            }
        }
        if ((*q)->x3C.b4) {
            func_00178030((*q)->x10);
        }
        if (p->x518->xB0 != 0) {
            func_001745D0(D_00202280, p->x518->xB0);
        }
        if (p->x49C != 0) {
            func_00128580(D_00202278, (void *)p->x49C);
        }
        if (p->x4A4 != 0) {
            func_00128580(D_00202278, (void *)p->x4A4);
        }
        func_00128580(D_00202278, (void *)p->x8);
    }
    if (p->x4B0 != NULL && (s = p->x518) != NULL && p->x4B0->xC.b6) {
        for (i = 0; i < 8; i++) {
            if (s->x124[i] != 0) {
                func_00167030(s->x124[i]);
            }
        }
    }
    func_00169D00(p->x580, 8);
    if (p->x5A0 != 0xFF) {
        func_001A5070(a0);
    }
    func_00128580(D_00202278, a0);
}
#undef D_004A4570

/* func_001A6C10 */
#define func_001A7030 func_001A7030__as_func_001A6C10
void func_001A7030__as_func_001A6C10(A_func_001A6C10 *, s32, s32);
void func_001A6C10(A_func_001A6C10 *a) {
    if (a != NULL) {
        if (!a->b0 || !a->b2) return;
        func_001A7030(a, 0, 1);
        func_00167580(a);
        a->b2 = 0;
    }
}
#undef func_001A7030

/* func_001A6C90 */
#define func_001A6DC0 func_001A6DC0__as_func_001A6C90
int func_001A6DC0__as_func_001A6C90();
#define func_001A7030 func_001A7030__as_func_001A6C90
int func_001A7030__as_func_001A6C90();
#define func_001B59E0 func_001B59E0__as_func_001A6C90
int func_001B59E0__as_func_001A6C90();
#define sceVu0AddVector sceVu0AddVector__as_func_001A6C90
void sceVu0AddVector__as_func_001A6C90(u8 *, u8 *, u8 *);
#define sceVu0CopyVector sceVu0CopyVector__as_func_001A6C90
void sceVu0CopyVector__as_func_001A6C90(u8 *, u8 *);

void func_001A6C90(u8 *arg0) {
    u8 *temp_17;
    u8 **temp_2;
    u8 *temp_16;

    if (arg0 != NULL) {
        if (!(M2C_FIELD(arg0, u8 *, 0x5A0) & 1)) {
            ((BF_5A1_4_1 *)arg0)->f = 1;
            return;
        }
        ((BF_5A1_4_1 *)arg0)->f = 0;
        ((BF_5A0_2_1 *)arg0)->f = 1;
        temp_2 = M2C_FIELD(arg0, u8 ***, 0x4A8);
        if (temp_2 != NULL) {
            temp_17 = *temp_2;
            temp_16 = M2C_FIELD(arg0, u8 **, 0x518);
            func_001B59E0(M2C_FIELD(temp_17, s32 *, 0x13C) + (M2C_FIELD(arg0, u16 *, 0x4AC) * 0x54), temp_16, temp_16 + 0x20, temp_16 + 0x50);
            sceVu0AddVector(temp_16, temp_16, temp_17 + 0x10);
            sceVu0CopyVector(temp_16 + 0x10, temp_16);
            sceVu0CopyVector(temp_16 + 0x30, temp_16 + 0x20);
        }
        func_001A6DC0(arg0);
        if (M2C_FIELD(arg0, u16 *, 0) != 0) {
            func_00136700(arg0);
            func_001A7030(arg0, 1, 0);
        }
    }
}
#undef sceVu0AddVector
#undef sceVu0CopyVector
#undef func_001A6DC0
#undef func_001A7030
#undef func_001B59E0

/* func_001A6DC0 */
void func_001A6DC0(Actor *a0) {
    Sub_func_001A6DC0 *b;
    u32 i;
    Src_func_001A6DC0 *e;
    Ent_func_001A6DC0 *ent;
    u16 *t;

    if (a0 != 0 && *(u16 *)a0 != 0) {
    t = (u16 *)a0->unk4B0;
    b = (Sub_func_001A6DC0 *)a0->unk518;
    b->m16C = *t;
    b->f120.f.b0 = 0;
    b->f120.f.b1 = 0;
    memset(b->mC0, 0, 0x60);
    memset(b->m144, 0, 0x28);
    for (i = 0; i < *(u32 *)(a0->pad000 + 0x7C); i++) {
        e = ((Src_func_001A6DC0 **)a0)[i + 0x12D];
        ent = &((Ent_func_001A6DC0 *)a0->unk51C)[i];
        ent->m15C = e->m20;
        ent->f160.f.b0 = 0;
        ent->f160.f.b2 = 0;
        memset(ent->m00, 0, 0x20);
        memset(ent->m20, 0, 0x20);
        memset(ent->m40, 0, 0x20);
        memset(ent->m60, 0, 0x20);
        if (!(e->mAC <= 0.0f)) {
            ent->m8C = 0xC2C80000;
            ent->m9C = 0xC2C80000;
        }
        func_001A8510(a0, i);
        func_001A8670(a0, i);
    }
    memset(a0->pad520, 0, 0x18);
    a0->pad000[0x80] = 0;
    a0->flags5A1.f.b5 = 0;
    func_00166F90(*(s32 *)(a0->pad000 + 0x4A4), *(s32 *)(a0->pad000 + 0xC), *(s32 *)(a0->pad000 + 0x4A0), 8);
    func_00171270(*b->pB0, D_001F2170, 0);
    func_00171270(*b->pB0, D_001F2170, 1);
    }
}

/* func_001A6FF0 */
void func_001A6FF0(Obj *o, B_func_001A6FF0 *b, u16 i)
{
    E_func_001A6FF0 *e = &b->t->tbl[i];
    o->b = b;
    o->i = i;
    o->v = e->v;
}

/* func_001A7030 */
void func_001A7030(O_func_001A7030 *arg0, s32 arg1, s32 arg2) {
    s8 *u;
    T_func_001A7030 *t;
    S_func_001A7030 *s;
    s32 i;

    u = (s8 *)arg0->u;
    t = arg0->t;
    if (arg0->s != NULL) {
        for (i = 0; i < arg0->n; i++) {
            s = &arg0->s[i];
            if (s != NULL && s->h != NULL) {
                if (s->b2 && arg2 == 0) {
                    func_00167640(s->h, 0);
                } else {
                    func_00167640(s->h, arg1);
                }
            }
        }
    }
    if (u != NULL && t != NULL) {
        for (i = 0; i < 8; i++, t = (T_func_001A7030 *)((s8 *)t + 0x40), u += 4) {
            s = &arg0->s[arg0->map[M2C_FIELD(t, u8 *, 0x2E2)]];
            if (M2C_FIELD(u, void **, 0x124) != NULL) {
                if (s != NULL && s->b2 && arg2 == 0) {
                    func_00167640(M2C_FIELD(u, void **, 0x124), 0);
                } else {
                    func_00167640(M2C_FIELD(u, void **, 0x124), arg1);
                }
            }
        }
    }
}

/* func_001A71B0 */
static inline s32 load(O_func_001A71B0 *o, u16 id, volatile s32 *flag) {
    s32 r;
    r = 0;
    if (id) {
        if (func_00169BB0(id)) {
            r = func_00169B50(id, 1, 0, 0);
            *flag = 1;
        } else {
            r = func_00169BD0(id, o->mp->m->x10, o->buf, 1, 0, 0);
            *flag = 0;
        }
    }
    return r;
}

void func_001A71B0(O_func_001A71B0 *o) {
    s32 i;
    Ent_func_001A71B0 *e;
    volatile s32 flag;
    s32 id;
    Q_func_001A71B0 *q;
    u16 id1;

    func_00169D70(o->mp->m->x10, o->buf, 8);
    for (i = 0; i < o->n; i++) {
        Def *d = o->defs[i];
        e = &o->ents[i];
        if (d->id) {
            e->x164 = load(o, d->id, &flag);
            e->b1 = flag;
        }
    }
    if (((T0 *)o->t)->c6) {
        q = o->q;
        q->m = 0;
        for (i = 0; i < 8; i++) {
            id = ((T0 *)(o->t + i * 0x40))->id;
            if (id) {
                s32 r = 0;
                if (id) {
                    if (func_00169BB0(id)) {
                        r = func_00169B50(id, 1, 0, 0);
                        flag = 1;
                    } else {
                        r = func_00169BD0(id, o->mp->m->x10, o->buf, 1, 0, 0);
                        flag = 0;
                    }
                }
                q->x124[i] = r;
                q->m |= (u16)(flag << i);
            }
        }
    }
}

/* func_001A7420 */
#define sceVu0CopyVector sceVu0CopyVector__as_func_001A7420
void sceVu0CopyVector__as_func_001A7420(Vec *, void *);
#define sceVu0AddVector sceVu0AddVector__as_func_001A7420
void sceVu0AddVector__as_func_001A7420(Vec *, Vec *, void *);
#define func_001A71B0 func_001A71B0__as_func_001A7420
void func_001A71B0__as_func_001A7420(A_func_001A7420 *);

void func_001A7420(A_func_001A7420 **pp) {
    Vec v0;
    Vec v1;
    u8 buf[0x100];
    A_func_001A7420 *a;
    Sub_func_001A7420 *b;
    s8 *base;
    s32 ***p4;
    s32 i;
    s32 bs;
    Src_func_001A7420 *e;
    Ent_func_001A7420 *ent;
    Mdl *m;

    a = *pp;
    p4 = a->m4;
    bs = *(*p4)[4];
    a->m4B0 = bs + a->m10;
    a->m514 = bs + a->m14;
    for (i = 0; i < a->m7C; i++) {
        a->m4B4[i] = (Src_func_001A7420 *)(bs + a->m18[i]);
    }
    a->m518 = (Sub_func_001A7420 *)a->m8[0];
    a->m51C = (s32)a->m518 + 0x640;
    b = a->m518;
    a->m518->pB0 = func_00174230(D_00202280, p4, -1, -1);
    a->m518->pB0[0]->f24.b2 = 0;
    a->m518->pB0[0]->f24.b5 = 1;
    a->m518->m0.y = -170.0f;
    b->m16C = *(u16 *)a->m4B0;
    a->m81 = 0;
    b->mB4 = 0xFF;
    b->mB5 = 0xFF;
    for (i = 0; i < a->m7C; i++) {
        e = ((Src_func_001A7420 **)a)[i + 0x12D];
        ent = &((Ent_func_001A7420 *)a->m51C)[i];
        switch (e->m2C & 7) {
        case 1:
            b->mB4 = e->m2A;
            b->mB6 = i;
            break;
        case 2:
            b->mB5 = e->m2A;
            b->mB7 = i;
            break;
        }
        ent->m15C = e->m20;
        ent->m164 = 0;
        if (!(e->mAC <= 0.0f)) {
            a->m82[a->m81] = i;
            a->m81++;
            ent->m8C = 0xC2C80000;
            ent->m9C = 0xC2C80000;
        }
    }
    m = b->pB0[0];
    base = (s8 *)(D_00201F2C * (m->m6 * 0x140 + 0x200) + (s32)m->m40);
    func_00171540(m, D_001F2170);
    sceVu0CopyVector(&v0, base + (b->mB5 + 1) * 0x140 + 0xF0);
    sceVu0CopyVector(&v1, base + (b->mB4 + 1) * 0x140 + 0xF0);
    b->m170 = v0.y - v1.y;
    if (D_001F33A0[a->m0] != 0) D_001F33A0[a->m0](a, 0.0f);
    if (a->m518->m50.x == 0.0f) sceVu0CopyVector(&a->m518->m50, &D_001F2120);
    if (a->m4A8 != 0) {
        s8 *s = (s8 *)*a->m4A8;
        Sub_func_001A7420 *t = a->m518;
        func_001B59E0(*(s8 **)(s + 0x13C) + a->m4AC * 0x54, &t->m0, &t->m20, &t->m50);
        sceVu0AddVector(&t->m0, &t->m0, s + 0x10);
        sceVu0CopyVector(&t->m10, &t->m0);
        sceVu0CopyVector(&t->m30, &t->m20);
    }
    a->m49C = 0;
    a->m4A4 = 0;
    if (a->m0 != 0) {
        func_00142930(a->m0, buf);
        a->m4A4 = func_001288C0(D_00202278, 0x1554);
        func_00166F90(a->m4A4, a->mC, a->m4A0, 8);
    }
    if (a->m0 != 0) func_001A7E60(a);
    func_001A71B0(a);
    a->f5A0.b1 = 0;
    a->f5A0.b0 = 1;
}
#undef sceVu0CopyVector
#undef sceVu0AddVector
#undef func_001A71B0
