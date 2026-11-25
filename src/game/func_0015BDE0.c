#include "common.h"
typedef struct { Vec a; f32 x10; f32 x14; f32 x18; u8 b1C; u8 b1D; u8 b1E; u8 b1F; u16 h20; u8 b22; } Ent;
extern f32 D_0030C420[];
extern f32 D_0030C424[];
extern f32 D_0030C428[];
extern f32 D_0030C42C[];
extern f32 D_0030C430[];
extern f32 D_0030C434[];
extern Vec D_0030C3E0;
extern Vec D_001F2150;
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, Vec *, Vec *);
void func_00102870(Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
f32 func_0011DBF0(f32, f32);
f32 sqrtf(f32);

f32 func_0015BDE0(Ent *e) {
    Vec v;
    Vec n;
    f32 k = 0.01f * e->x10;
    f32 s = e->x18;
    f32 d;
    f32 r;

    func_00102A60(&v, &e->a);
    v.w = 1.0f;
    func_001027B0(&v, &D_0030C3E0, &v);
    func_00102870(&n, &v);
    d = func_00102848(&n, &D_001F2150);
    d += s;
    if (d < 0.0f) return 0.0f;
    k *= d / (1.0f + s);
    r = sqrtf(func_00102848(&v, &v));
    if (e->a.w < r) return 0.0f;
    k *= func_0011DBF0(1.0f - r / e->a.w, e->x14);
    D_0030C420[0] += e->b1C * k;
    D_0030C424[0] += e->b1D * k;
    D_0030C428[0] += e->b1E * k;
    D_0030C42C[0] += e->b1F * k;
    D_0030C430[0] += e->h20 * k;
    D_0030C434[0] += e->b22 * k;
    return k;
}
