#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
extern Mtx D_001F2340;
void func_00102A70(Mtx *, Mtx *);
void func_00102C20(Mtx *, Mtx *, f32);
void func_00102B78(Mtx *, Mtx *, f32);
void func_00102CC8(Mtx *, Mtx *, f32);
void func_00102A30(Mtx *, Mtx *, Vec *);

void func_00173FD0(Mtx *m, Vec *t, Vec *r, Vec *s) {
    func_00102A70(m, &D_001F2340);
    m->m[0].x = s->x;
    m->m[1].y = s->y;
    m->m[2].z = s->z;
    func_00102C20(m, m, WRAP(r->x));
    func_00102B78(m, m, WRAP(r->z));
    func_00102CC8(m, m, WRAP(r->y));
    func_00102A30(m, m, t);
}
