#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec p; Vec d; } Seg;
typedef struct { Vec a; Vec b; Vec c; s32 hit; f32 t1; f32 t2; } Res;
typedef struct { Vec a; Vec b; s32 x20; s32 x24; s32 x28; } Out;
typedef struct { Seg *a; Seg *b; } Pair;
typedef union { struct { Res *a; Res *b; } p; s32 w[4]; } RPair;
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_00102A60(Vec *, Vec *);
void func_00151B20(Res *, Seg *, Seg *);
void func_00150730(Out *, Seg **, Seg **, RPair *, s32 *, f32 *, f32, f32, f32);
float sqrtf(float);
extern Vec D_003139A0;
extern s32 D_00201F24;

static inline void inner(Out *out, Seg *a1, Seg *a2, Seg *a3, Seg *a4) {
    s32 flag;
    f32 f;
    Seg *A[2] = {a1, a2};
    Seg *B[2] = {a3, a4};
    Res r2;
    Res r1;
    Vec v80;
    Vec v70;
    Vec v60;
    Vec v50;
    f32 k;
    Res *rp;
    flag = 0;
    func_00151B20(&r1, A[0], B[0]);
    if (r1.hit) {
        func_00102A60(&out->a, &D_003139A0);
        func_00102A18(&v80, &r1.a, 0.5f);
        func_001029D0(&out->a, &v80, &out->a);
        func_00102A18(&v70, &r1.b, 0.5f);
        func_001029D0(&out->a, &v70, &out->a);
        func_00102A60(&out->b, &r1.c);
        out->x20 = 0;
        out->x24 = 0;
        out->x28 = 2;
    } else {
    rp = &r2;
    func_00151B20(rp, A[1], B[1]);
    if (rp->hit) flag = 1;
    while (flag == 0) {
        func_00102870(&v60, &r1.c);
        func_00102870(&v50, &r2.c);
        if (func_00102848(&v60, &v50) < 0.5f) break;
        return;
    }
    {
        RPair C = {{&r1, rp}};
        k = 2.0f / (sqrtf(func_00102848(&r1.c, &r1.c)) + sqrtf(func_00102848(&r2.c, &r2.c)));
        if (!(k <= 1.0f)) k = 0.1f;
        f = 1.0f;
        D_00201F24 = 0;
        func_00150730(out, A, B, &C, &flag, &f, 0.0f, 1.0f, k);
        if (flag) out->x28 = 1;
    }
    }
}




void func_00151E50(Out *out, Seg *a1, Seg *a2, Seg *a3, Seg *a4) {
    out->x28 = 0;
    inner(out, a1, a2, a3, a4);
}
