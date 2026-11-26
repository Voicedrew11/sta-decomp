#include "common.h"
typedef struct { u8 pad[0xE]; s16 hE; Vec v10; Vec v20; } S1;
extern s32 D_00201E94;
typedef struct { f32 v[3]; } F3 __attribute__((aligned(8)));
extern F3 D_001F2020;
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, Mtx *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029E8(Vec *, Vec *, Vec *);
void func_00102870(Vec *, Vec *);
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
    func_00102A60(&P, &s1->v20);
    P.w = 1.0f;
    func_001027B0(&P, m, &P);
    P.w = s1->v20.w;
    func_00102A60(&D, &s1->v10);
    D.w = 0.0f;
    func_001027B0(&D, m, &D);
    if (flag && !(func_00102848(&D, &s3[1]) <= 0.0f)) {
        func_00102A18(&D, &D, -1.0f);
    }
    D.w = s1->v10.w;
    if (!func_00150C00(s3, &P, &D, &Q, &tA, &tB)) return 0;
    func_001029E8(&E[0], &tri[0], &Q);
    func_001029E8(&E[2], &tri[1], &Q);
    func_001029E8(&E[1], &tri[2], &Q);
    E[0].w = 0.0f;
    E[1].w = 0.0f;
    E[2].w = 0.0f;
    func_00102870(&E[0], &E[0]);
    func_00102870(&E[1], &E[1]);
    func_00102870(&E[2], &E[2]);
    best = func_00102848(&E[0], &E[1]);
    best += func_00102848(&E[1], &E[2]);
    best += func_00102848(&E[2], &E[0]);
    if (best < -1.0f) {
        func_00102A60(out, &Q);
        out->w = tA;
        func_00102A60(&out[1], &D);
        out[1].w = tB;
        s1->hE = D_00201E94 - 1;
        return 1;
    }
    d = D_001F2020;
    k = -1;
    best = 2.0f;
    a = &tri[idx % 3];
    b = &tri[(idx + 1) % 3];
    func_001029E8(&E[0], b, a);
    c = &tri[(idx + 2) % 3];
    func_001029E8(&E[1], c, b);
    func_001029E8(&E[2], a, c);
    func_001511C0(s3, a, &E[0], &R[0], &S[0], &d.v[0]);
    func_001511C0(s3, b, &E[1], &R[1], &S[1], &d.v[1]);
    func_001511C0(s3, c, &E[2], &R[2], &S[2], &d.v[2]);
    if (d.v[0] < 2.0f) { best = d.v[0]; k = 0; }
    if (d.v[1] < best) { best = d.v[1]; k = 1; }
    if (d.v[2] < best) { best = d.v[2]; k = 2; }
    if (k == -1) return 0;
    func_00102A60(out, &R[k]);
    out->w = best;
    func_00102A60(&out[1], &S[k]);
    best = s3->w - sqrtf(func_00102848(&out[1], &out[1]));
    if (best < 0.0f) best = 0.0f;
    func_00102870(&out[1], &out[1]);
    out[1].w = best;
    s1->hE = D_00201E94 - 1;
    return 1;
}
