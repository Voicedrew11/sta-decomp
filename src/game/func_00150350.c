#include "common.h"
typedef struct { Vec p; Vec q; } Obj;
typedef struct { Obj *a; Obj *b; } Pair;
typedef struct { u8 pad[0xC]; f32 xC; u8 pad2[0x18]; s32 x28; } Tgt;
f32 func_00102848(Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102870(Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
void func_00151E50(Tgt *, Obj *, Obj *, Obj *, Obj *);

s32 func_00150350(Tgt *t, Pair *a, Pair *b, f32 s, f32 len, f32 f) {
    Vec av[2];
    Vec bv[2];
    Obj m[2];
    f32 d1;
    f32 d2;
    s32 r; f32 h;
    func_00102A60(&av[0], &a->a->q);
    av[0].w = 0.0f;
    func_00102A60(&av[1], &a->b->q);
    av[1].w = 0.0f;
    func_00102A60(&bv[0], &b->a->q);
    bv[0].w = 0.0f;
    func_00102A60(&bv[1], &b->b->q);
    bv[1].w = 0.0f;
    d1 = func_00102848(&av[0], &av[1]);
    d2 = func_00102848(&bv[0], &bv[1]);
    if ((d1 < f || d2 < f) && !(len <= 0.1f)) {
        Pair p1 = {0};
        p1.a = a->a;
        p1.b = &m[0];
        {
            Pair p2 = {0};
            p2.a = b->a;
            p2.b = &m[1];
            {
                Pair p3 = {0};
                p3.a = &m[0];
                p3.b = a->b;
                {
                    Pair p4 = {0};
                    p4.a = &m[1];
                    p4.b = b->b;
                    func_001029D0(&m[0].p, &a->a->p, &a->b->p);
                    func_001029D0(&m[0].q, &a->a->q, &a->b->q);
                    m[0].q.w = 0.0f;
                    func_00102A18(&m[0].p, &m[0].p, 0.5f);
                    func_00102870(&m[0].q, &m[0].q);
                    m[0].p.w = a->a->p.w;
                    m[0].q.w = 0.5f * (a->a->q.w + a->b->q.w);
                    func_001029D0(&m[1].p, &b->a->p, &b->b->p);
                    func_001029D0(&m[1].q, &b->a->q, &b->b->q);
                    m[1].q.w = 0.0f;
                    func_00102A18(&m[1].p, &m[1].p, 0.5f);
                    func_00102870(&m[1].q, &m[1].q);
                    m[1].p.w = b->a->p.w;
                    m[1].q.w = 0.5f * (b->a->q.w + b->b->q.w);
                    h = 0.5f * len;
                    if ((r = func_00150350(t, &p1, &p2, s, h, f)) != 0) return r;
                    if (t->x28 == 2) return 2;
                    if ((r = func_00150350(t, &p3, &p4, s + h, h, f)) != 0) return r;
                }
            }
        }
    } else {
        func_00151E50(t, a->a, a->b, b->a, b->b);
        if (t->x28 == 2) {
            t->xC = s;
            return 2;
        }
        if (t->x28 == 1) {
            t->xC = s + t->xC * len;
            return 1;
        }
    }
    return 0;
}
