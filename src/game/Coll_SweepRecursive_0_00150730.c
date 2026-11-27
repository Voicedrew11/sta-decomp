#include "common.h"
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; u8 pad[4]; } Res;
typedef struct { Seg *a; Seg *b; } Pair;
typedef struct { Res *a; Res *b; } RPair __attribute__((aligned(16)));
typedef struct { Vec a; Vec b; f32 x20; f32 x24; } Out;
extern s32 D_00201F24;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0InterVector(Vec *, Vec *, Vec *, f32);
void sceVu0Normalize(Vec *, Vec *);
void Seg_ClosestPoints_3_00151B20(Res *, Seg *, Seg *);

s32 Coll_SweepRecursive_0_00150730(Out *o, Pair *p1, Pair *p2, f32 t0, f32 dt, RPair *p3, s32 *state, f32 *best, f32 eps) {
    Seg m1;
    Seg m2;
    Res r;
    s32 ret;
    u32 flags;
    f32 v;
    f32 d0;
    f32 d1;
    f32 mid;
    f32 h;

    ret = 0;
    flags = 0;
    sceVu0InterVector(&m1.p, &p1->a->p, &p1->b->p, 0.5f);
    sceVu0InterVector(&m2.p, &p2->a->p, &p2->b->p, 0.5f);
    sceVu0InterVector(&m1.d, &p1->a->d, &p1->b->d, 0.5f);
    sceVu0InterVector(&m2.d, &p2->a->d, &p2->b->d, 0.5f);
    sceVu0Normalize(&m1.d, &m1.d);
    sceVu0Normalize(&m2.d, &m2.d);
    m1.d.w = p1->a->d.w;
    m2.d.w = p2->a->d.w;
    D_00201F24++;
    Seg_ClosestPoints_3_00151B20(&r, &m1, &m2);
    if (r.hit) {
        *state = 2;
        v = t0 + 0.5f * dt;
        if (v < *best) {
            *best = v;
            sceVu0InterVector(&o->a, &r.a, &r.b, r.b.w);
            o->a.w = *best;
            o->x20 = r.a.w;
            o->x24 = r.b.w;
            sceVu0SubVector(&o->b, &r.b, &r.a);
        }
    }
    h = 0.5f * dt;
    if (h < eps) {
        if (*state == 1) {
            sceVu0InterVector(&o->a, &r.a, &r.b, r.b.w);
            o->a.w = *best;
            o->x20 = r.a.w;
            o->x24 = r.b.w;
            sceVu0SubVector(&o->b, &r.b, &r.a);
        }
        return 1;
    }
    if (r.hit) {
        flags = 1;
    } else {
        d0 = sceVu0InnerProduct(&p3->a->c, &r.c);
        d1 = sceVu0InnerProduct(&p3->b->c, &r.c);
        if (d0 > 0.0f && d1 > 0.0f) {
            flags = 3;
        } else {
            if (d1 < d0) flags |= 2;
            if (!(d1 <= d0)) flags |= 1;
        }
    }
    if (flags & 1) {
        Pair q1 = {0};
        q1.a = p1->a;
        q1.b = &m1;
        {
            Pair q2 = {0};
            q2.a = p2->a;
            q2.b = &m2;
            {
                RPair q3 = {0};
                q3.a = p3->a;
                q3.b = &r;
                ret = Coll_SweepRecursive_0_00150730(o, &q1, &q2, t0, h, &q3, state, best, eps);
            }
        }
    }
    mid = t0 + h;
    if (!(*best <= mid) && (flags & 2)) {
        Pair q1 = {0};
        q1.a = &m1;
        q1.b = p1->b;
        {
            Pair q2 = {0};
            q2.a = &m2;
            q2.b = p2->b;
            {
                RPair q3 = {0};
                q3.a = &r;
                q3.b = p3->b;
                ret = Coll_SweepRecursive_0_00150730(o, &q1, &q2, mid, h, &q3, state, best, eps);
            }
        }
    }
    if (ret == 1) ret = 2;
    return ret;
}
