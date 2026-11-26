#include "common.h"
typedef struct { u8 pad[0xE]; s16 hE; Vec v10; Vec v20; } S1;
extern s32 D_00201E94;
typedef struct { f32 v[3]; } F3 __attribute__((aligned(8)));
extern F3 D_001F2020;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
s32 func_00150C00(Vec *, Vec *, Vec *, Vec *, f32 *, f32 *);
void func_001511C0(Vec *, Vec *, Vec *, Vec *, Vec *, f32 *);
f32 sqrtf(f32);

s32 func_00152D90(Vec *out, Vec *s3, Vec *tri, S1 *s1, Mtx *m, s32 idx, s32 flag) {
    Vec P;
    Vec D;
    Vec Q;
    Vec E[3];
    Vec R[3];
    Vec S[3];
    F3 d;
    f32 tA;
    f32 tB;
    f32 best;
    s32 k;
    Vec *b;
    Vec *a;
    Vec *c;

    tA = 0.0f;
    sceVu0CopyVector(&P, &s1->v20);
    P.w = 1.0f;
    sceVu0ApplyMatrix(&P, m, &P);
    P.w = s1->v20.w;
    sceVu0CopyVector(&D, &s1->v10);
    D.w = 0.0f;
    sceVu0ApplyMatrix(&D, m, &D);
    if (flag && !(sceVu0InnerProduct(&D, &s3[1]) <= 0.0f)) {
        sceVu0ScaleVector(&D, &D, -1.0f);
    }
    D.w = s1->v10.w;
    if (!func_00150C00(s3, &P, &D, &Q, &tA, &tB)) return 0;
    sceVu0SubVector(&E[0], &tri[0], &Q);
    sceVu0SubVector(&E[2], &tri[1], &Q);
    sceVu0SubVector(&E[1], &tri[2], &Q);
    E[0].w = 0.0f;
    E[1].w = 0.0f;
    E[2].w = 0.0f;
    sceVu0Normalize(&E[0], &E[0]);
    sceVu0Normalize(&E[1], &E[1]);
    sceVu0Normalize(&E[2], &E[2]);
    best = sceVu0InnerProduct(&E[0], &E[1]);
    best += sceVu0InnerProduct(&E[1], &E[2]);
    best += sceVu0InnerProduct(&E[2], &E[0]);
    if (best < -1.0f) {
        sceVu0CopyVector(out, &Q);
        out->w = tA;
        sceVu0CopyVector(&out[1], &D);
        out[1].w = tB;
        s1->hE = D_00201E94 - 1;
        return 1;
    }
    d = D_001F2020;
    k = -1;
    best = 2.0f;
    a = &tri[idx % 3];
    b = &tri[(idx + 1) % 3];
    sceVu0SubVector(&E[0], b, a);
    c = &tri[(idx + 2) % 3];
    sceVu0SubVector(&E[1], c, b);
    sceVu0SubVector(&E[2], a, c);
    func_001511C0(s3, a, &E[0], &R[0], &S[0], &d.v[0]);
    func_001511C0(s3, b, &E[1], &R[1], &S[1], &d.v[1]);
    func_001511C0(s3, c, &E[2], &R[2], &S[2], &d.v[2]);
    if (d.v[0] < 2.0f) { best = d.v[0]; k = 0; }
    if (d.v[1] < best) { best = d.v[1]; k = 1; }
    if (d.v[2] < best) { best = d.v[2]; k = 2; }
    if (k == -1) return 0;
    sceVu0CopyVector(out, &R[k]);
    out->w = best;
    sceVu0CopyVector(&out[1], &S[k]);
    best = s3->w - sqrtf(sceVu0InnerProduct(&out[1], &out[1]));
    if (best < 0.0f) best = 0.0f;
    sceVu0Normalize(&out[1], &out[1]);
    out[1].w = best;
    s1->hE = D_00201E94 - 1;
    return 1;
}
