#include "actor.h"
typedef struct { Vec a, b; Mtx m; u32 col; } Buf;
typedef struct { Vec v0; Vec v10; u8 pad[0xA]; u8 x2A; u8 x2B; u8 x2C; Flags8 f2D; u8 pad2[0x72]; Vec vA0; } Pt;
typedef struct { u8 pad[0x160]; u8 x160; } Ent;
typedef struct { Vec a, b, c, d; u8 pad[0x130]; } Bone;
typedef struct { u8 pad[0xB6]; u8 xB6; u8 xB7; } S18;
typedef struct { u8 pad[0x16]; u16 x16; } S0C;
typedef struct { u8 pad[4]; f32 f4; u8 pad8[4]; S0C **pC; u8 pad10[4]; Bone *p14; S18 *p18; u8 pad1C[0x10]; s8 *p2C; } Sub;
typedef struct { Vec *p; } __attribute__((aligned(16))) PV;
typedef struct { u8 r:7; u8 b7:1; } F7;
extern F7 D_00222A51[];
extern Mtx D_001F2170;
s32 func_0013EE30(Actor *);
void func_0013ACE0(Actor *, f32);
void func_0013AB00(Actor *, f32);
u8 func_0013FC00(Actor *);
s32 func_0013FB90(Actor *, u8, Vec **, Vec **);
Pt *func_0013DCA0(Actor *, u8);
Ent *func_0013DC70(Actor *, u8);
void func_00102A70(Mtx *, void *);
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, Mtx *, Vec *);
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_00156920(Buf *);
f32 sqrtf(f32);

void func_0013B4F0(Actor *a, s32 flag, f32 f) {
    Mtx M;
    PV P;
    PV Q;
    Vec V;
    Buf L1;
    Mtx M3;
    Buf L2;
    Sub *s;
    u8 i;
    u8 n;
    Pt *e;
    u32 j;
    Bone *g;
    Vec *b;

    s = (Sub *)(a->unk518 + 0x180);
    if (!func_0013EE30(a) && flag) return;
    func_0013ACE0(a, f);
    if ((*s->pC)->x16 == 0) return;
    func_0013AB00(a, f);
    n = func_0013FC00(a);
    for (i = 0; i < n; i++) {
        P.p = 0;
        Q.p = 0;
        if ((u8)func_0013FB90(a, i, &P.p, &Q.p)) {
            e = func_0013DCA0(a, a->unk82[i]);
            func_00102A70(&M, s->p2C + (e->x2A + 1) * 0x140 + 0xC0);
            func_00102A60(Q.p, P.p);
            func_00102A60(&V, &e->vA0);
            V.w = 1.0f;
            func_001027B0(P.p, &M, &V);
            P.p->w = e->vA0.w * s->f4;
            Q.p->w < 0.0f ? func_00102A60(Q.p, P.p) : (void)0;
            if (D_00222A51[0].b7 && !func_0013EE30(a)) {
                func_00102A70(&L1.m, &D_001F2170);
                L1.col = 0x4000FF00;
                func_00102A60(&L1.a, Q.p);
                func_001029E8(&L1.b, P.p, Q.p);
                L1.b.w = sqrtf(func_00102848(&L1.b, &L1.b));
                func_00102870(&L1.b, &L1.b);
                func_00156920(&L1);
            }
        } else {
            if (P.p) P.p->w = -100.0f;
            if (Q.p) Q.p->w = -100.0f;
        }
    }
        for (j = 0; j < *(u32 *)(a->pad000 + 0x7C); j++) {
            e = func_0013DCA0(a, j);
            if (e->f2D.f.b5) {
                func_00102A60(&s->p14[j].c, &s->p14[j].a);
                func_00102A60(&s->p14[j].d, &s->p14[j].b);
                g = &s->p14[j];
                b = &g->b;
                func_00102A70(&M3, s->p2C + (e->x2A + 1) * 0x140 + 0xC0);
                func_00102A60(&g->a, &e->v0);
                g->a.w = 1.0f;
                func_00102A60(b, &e->v10);
                b->w = 1.0f;
                func_001027B0(&g->a, &M3, &g->a);
                func_001027B0(b, &M3, b);
                func_001029E8(b, b, &g->a);
                b->w = 0.0f;
                f = sqrtf(func_00102848(b, b));
                func_00102870(b, b);
                g->a.w = e->v0.w * s->f4;
                b->w = f;
                if (D_00222A51[0].b7 && !func_0013EE30(a) && !(func_0013DC70(a, j)->x160 & 1) &&
                    j != s->p18->xB7 && j != s->p18->xB6) {
                    func_00102A70(&L2.m, &D_001F2170);
                    L2.col = 0x40FFFFFF;
                    func_00102A60(&L2.a, &g->a);
                    func_00102A60(&L2.b, b);
                    func_00156920(&L2);
                }
            }
        }
}
