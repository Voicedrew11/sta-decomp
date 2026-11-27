#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } P;
typedef struct { u8 pad[0x18]; P *p; } Sub;
typedef struct { u8 pad[0x518]; u8 *x518; } A;
extern Mtx D_001F2170;
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
void sceVu0CopyVector(Vec *, P *);
void sceVu0CopyMatrix(Mtx *, Mtx *);

void Actor_BuildRotMatrix_0_00146600(A *a, Mtx *m) {
    Sub *s;
    if (a != NULL) {
        s = (Sub *)(a->x518 + 0x180);
        sceVu0RotMatrixX(WRAP(WRAP(s->p->x20)), m, &D_001F2170);
        sceVu0RotMatrixY(WRAP(WRAP(3.1415927f + s->p->x24)), m, m);
        sceVu0CopyVector(&m->m[3], s->p);
        m->m[3].w = 1.0f;
    } else {
        sceVu0CopyMatrix(m, &D_001F2170);
    }
}
