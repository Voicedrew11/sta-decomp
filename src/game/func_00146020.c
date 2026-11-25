#include "common.h"
void func_00102A70(Mtx *, void *);
void func_00102870(Vec *, Vec *);
f32 func_0011D850(f32);
void func_00102A60(void *, void *);
void func_00102828(Vec *, void *, Vec *);
extern s8 D_001F2130[];
extern s8 D_001F2140[];
extern s8 D_001F2160[];
extern s8 D_001F2170[];

void func_00146020(Mtx *m, f32 x, f32 y, f32 z) {
    Vec u;
    Vec s;
    Vec d;

    if (x == 0.0f && y == 0.0f && z == 0.0f) {
        func_00102A70(m, D_001F2170);
        return;
    }
    d.x = x;
    d.y = y;
    d.z = z;
    *(s32 *)&d.w = 0;
    func_00102870(&d, &d);
    if (0.9999f < func_0011D850(d.y)) {
        func_00102A60(&u, D_001F2130);
    } else {
        func_00102828(&u, D_001F2140, &d);
    }
    func_00102870(&u, &u);
    func_00102828(&s, &d, &u);
    func_00102A60(&m->m[0], &u);
    func_00102A60(&m->m[1], &s);
    func_00102A60(&m->m[2], &d);
    func_00102A60(&m->m[3], D_001F2160);
}
