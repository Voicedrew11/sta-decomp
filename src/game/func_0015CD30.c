#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define DEG(d) (3.1415927f * (d) / 180.0f)
typedef struct {
    Vec x0;
    Vec x10;
    Vec x20;
    Vec x30;
    Vec x40;
    Vec x50;
    Vec x60;
    Vec x70;
    Vec x80;
    Vec x90;
} O;
extern Mtx D_001F2170;
void func_00102B78(f32, Mtx *, Mtx *);
void func_00102CC8(f32, Mtx *, Mtx *);
void func_00102A60(Vec *, Vec *);

void func_0015CD30(O *o, Vec *a, Vec *b, Vec *c, Vec *d, Vec *pa, Vec *pb, Vec *pc, Vec *q0, Vec *q1, Vec *q2) {
    Mtx m1;
    Mtx m2;
    Mtx m3;
    Mtx m4;

    func_00102B78(WRAP(DEG(a->y)), &m1, &D_001F2170);
    func_00102CC8(WRAP(DEG(a->x)), &m1, &m1);
    o->x10.x = m1.m[0].x;
    o->x10.y = m1.m[0].y;
    o->x10.z = m1.m[0].z;
    o->x10.w = a->w;
    func_00102A60(&o->x50, pa);
    func_00102B78(WRAP(DEG(b->y)), &m2, &D_001F2170);
    func_00102CC8(WRAP(DEG(b->x)), &m2, &m2);
    o->x20.x = m2.m[0].x;
    o->x20.y = m2.m[0].y;
    o->x20.z = m2.m[0].z;
    o->x20.w = b->w;
    func_00102A60(&o->x60, pb);
    func_00102B78(WRAP(DEG(c->y)), &m3, &D_001F2170);
    func_00102CC8(WRAP(DEG(c->x)), &m3, &m3);
    o->x30.x = m3.m[0].x;
    o->x30.y = m3.m[0].y;
    o->x30.z = m3.m[0].z;
    o->x30.w = c->w;
    func_00102A60(&o->x70, pc);
    func_00102B78(WRAP(DEG(d->y)), &m4, &D_001F2170);
    func_00102CC8(WRAP(DEG(d->x)), &m4, &m4);
    o->x40.x = m4.m[0].x;
    o->x40.y = m4.m[0].y;
    o->x40.z = m4.m[0].z;
    o->x40.w = d->w;
    func_00102A60(&o->x80, q0);
    func_00102A60(&o->x0, q1);
    func_00102A60(&o->x90, q2);
}
