#include "common.h"
typedef struct { Vec a; Vec b; } Pair;
typedef struct { Pair p[2]; Vec x40; Flags8 x50; u8 pad[3]; f32 x54; f32 x58; u8 pad2[4]; } E60;
extern E60 D_0030D9A0[];
void func_00102A60(void *, void *);

void func_0015D800(s32 idx, Vec *a, Vec *b, f32 f, f32 g) {
    E60 *e;
    f32 h;
    s32 i;
    Pair *p;
    e = &D_0030D9A0[idx];
    if (!e->x50.f.b0) {
        g = -1.0f;
    }
    h = -1.0f / (f * f);
    for (i = 0, p = e->p; i < 2; i++, p++) {
        func_00102A60(&p->a, a);
        func_00102A60(&p->b, b);
        p->a.w = h;
        p->b.w = g;
    }
    func_00102A60(&e->x40, e);
    e->x54 = f;
    e->x58 = g;
}
