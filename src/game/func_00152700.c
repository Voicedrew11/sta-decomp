#include "common.h"

/* func_00152700 */
typedef struct { u8 pad[0xE]; s16 hE; Vec v10; Vec v20; } S1;
typedef struct { Vec v0; Vec v10; s32 x20; s32 x24; s32 x28; S1 *x2C; u8 pad30[0xC]; s32 x3C; } H;
extern s32 D_00201E94;
typedef struct { f32 v[3]; } F3 __attribute__((aligned(8)));
#pragma explicit_zero_data on
F3 D_001F2020 = { 2.0f, 2.0f, 2.0f };
F3 D_001F2030 = { 2.0f, 2.0f, 2.0f };
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
s32 func_00150C00(Vec *, Vec *, Vec *, Vec *, f32 *, f32 *);
void func_001511C0(Vec *, Vec *, Vec *, Vec *, Vec *, f32 *);
f32 sqrtf(f32);

s32 func_00152700(H *h, s32 **pp, Vec *s3, s32 a3, s32 *cnt, s32 max, H **cur, Vec *out, Vec *out1, Vec *tri,
                  s32 x24, s32 x28, S1 *s1, Mtx *m, f32 *best, s32 idx, s32 flag, s32 x3C) {
    Vec P;
    Vec D;
    Vec Q;
    Vec E[3];
    Vec G[3];
    Vec R[3];
    Vec S[3];
    F3 d;
    f32 tA;
    f32 tB;
    f32 sum;
    f32 r;
    s32 k;
    Vec *b;
    Vec *c;
    Vec *a;

    sum = 0.0f;
    tA = 0.0f;
    a = &tri[idx % 3];
    b = &tri[(idx + 1) % 3];
    sceVu0SubVector(&E[0], b, a);
    c = &tri[(idx + 2) % 3];
    sceVu0SubVector(&E[1], c, b);
    sceVu0SubVector(&E[2], a, c);
    sceVu0CopyVector(&P, &s1->v20);
    P.w = 1.0f;
    sceVu0ApplyMatrix(&P, m, &P);
    P.w = s1->v20.w;
    sceVu0CopyVector(&D, &s1->v10);
    D.w = 0.0f;
    sceVu0ApplyMatrix(&D, m, &D);
    if (flag && !(sceVu0InnerProduct(&D, &s3[1]) <= sum)) {
        sceVu0ScaleVector(&D, &D, -1.0f);
    }
    D.w = s1->v10.w;
    if (!func_00150C00(s3, &P, &D, &Q, &tA, &tB)) return 0;
    sceVu0SubVector(&G[0], &tri[0], &Q);
    sceVu0SubVector(&G[2], &tri[1], &Q);
    sceVu0SubVector(&G[1], &tri[2], &Q);
    G[0].w = 0.0f;
    G[1].w = 0.0f;
    G[2].w = 0.0f;
    sceVu0Normalize(&G[0], &G[0]);
    sceVu0Normalize(&G[1], &G[1]);
    sceVu0Normalize(&G[2], &G[2]);
    sum += sceVu0InnerProduct(&G[0], &G[1]);
    sum += sceVu0InnerProduct(&G[1], &G[2]);
    sum += sceVu0InnerProduct(&G[2], &G[0]);
    if (sum < -1.0f) {
        if (tA < *best) *best = tA;
        sceVu0CopyVector(out, &Q);
        sceVu0CopyVector(out1, &D);
        out->w = tA;
        out1->w = tB;
        h->x20 = **pp;
        h->x24 = x24;
        h->x28 = x28;
        h->x2C = s1;
        h->x3C = x3C;
        s1->hE = D_00201E94 - 1;
        if (a3 < -1 && *cur && *cnt < max) {
            (*cnt)++;
            (*cur)->x20 = **pp;
            sceVu0CopyVector(&(*cur)->v0, out);
            sceVu0CopyVector(&(*cur)->v10, out1);
            (*cur)->x24 = x24;
            (*cur)->x28 = x28;
            (*cur)->x2C = s1;
            (*cur)->x3C = x3C;
            (*cur)++;
        }
        if (a3 == 0 && *best < 1.0f) return 1;
    } else {
    d = D_001F2030;
    sum = 2.0f;
    k = -1;
    func_001511C0(s3, a, &E[0], &R[0], &S[0], &d.v[0]);
    func_001511C0(s3, b, &E[1], &R[1], &S[1], &d.v[1]);
    func_001511C0(s3, c, &E[2], &R[2], &S[2], &d.v[2]);
    if (d.v[0] < 2.0f) { sum = d.v[0]; k = 0; }
    if (d.v[1] < sum) { sum = d.v[1]; k = 1; }
    if (d.v[2] < sum) { sum = d.v[2]; k = 2; }
    if (k != -1) {
    if (!(a3 < -1) && !(sum <= *best)) return 0;
    *best = sum;
    sceVu0CopyVector(out, &R[k]);
    sceVu0CopyVector(out1, &S[k]);
    r = s3->w - sqrtf(sceVu0InnerProduct(out1, out1));
    if (r < 0.0f) r = 0.0f;
    sceVu0Normalize(out1, out1);
    out->w = sum;
    out1->w = r;
    h->x20 = **pp;
    h->x24 = x24;
    h->x28 = x28;
    h->x2C = s1;
    h->x3C = x3C;
    s1->hE = D_00201E94 - 1;
    if (a3 < -1 && *cur && *cnt < max) {
        (*cnt)++;
        sceVu0CopyVector(&(*cur)->v0, out);
        sceVu0CopyVector(&(*cur)->v10, out1);
        (*cur)->x20 = **pp;
        (*cur)->x24 = x24;
        (*cur)->x28 = x28;
        (*cur)->x2C = s1;
        (*cur)->x3C = x3C;
        (*cur)++;
    }
    if (a3 == 0 && *best < 1.0f) return 1;
    }
    }
    return 0;
}

/* func_00152D90 */
extern s32 D_00201E94;
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
