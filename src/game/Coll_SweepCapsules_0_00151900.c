#include "common.h"
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; u8 pad[4]; } Res;
typedef struct { Vec p; f32 pad[3]; f32 r; } Obj;
typedef struct { Obj *a; Obj *b; } Pair;
typedef struct { u8 pad[0x28]; s32 x28; } Tgt;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);
void Seg_ClosestPoints_3_00151B20(Res *, Seg *, Seg *);
void Coll_SweepSegments_1_00150350(Tgt *, Pair *, Pair *, f32, f32, f32);
f32 sqrtf(f32);
static inline f32 fmax(f32 a, f32 b) { return (a <= b) ? b : a; }
static inline f32 fmax2(f32 a, f32 b) { if (a <= b) return b; return a; }

void Coll_SweepCapsules_0_00151900(Tgt *t, Obj *a1, Obj *a2, Obj *b1, Obj *b2, f32 f) {
    Res r;
    Seg A;
    Seg B;
    f32 len;
    t->x28 = 0;
    sceVu0CopyVector(&A.p, &a1->p);
    sceVu0SubVector(&A.d, &a2->p, &a1->p);
    len = sqrtf(sceVu0InnerProduct(&A.d, &A.d));
    sceVu0ScaleVector(&A.d, &A.d, 1.0f / len);
    A.d.w = len;
    if (!(a1->r <= a2->r)) A.p.w = a1->r; else A.p.w = a2->r;
    sceVu0CopyVector(&B.p, &b1->p);
    sceVu0SubVector(&B.d, &b2->p, &b1->p);
    len = sqrtf(sceVu0InnerProduct(&B.d, &B.d));
    sceVu0ScaleVector(&B.d, &B.d, 1.0f / len);
    B.d.w = len;
    if (!(b1->r <= b2->r)) B.p.w = b1->r; else B.p.w = b2->r;
    Seg_ClosestPoints_3_00151B20(&r, &A, &B);
    if (r.hit) {
        Pair p1 = {0};
        p1.a = a1;
        p1.b = a2;
        {
            Pair p2 = {0};
            p2.a = b1;
            p2.b = b2;
            Coll_SweepSegments_1_00150350(t, &p1, &p2, 0.0f, 1.0f, f);
        }
    }
}
