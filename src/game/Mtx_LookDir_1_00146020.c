#include "common.h"
void sceVu0CopyMatrix(Mtx *, void *);
void sceVu0Normalize(Vec *, Vec *);
f32 fabsf(f32);
void sceVu0CopyVector(void *, void *);
void sceVu0OuterProduct(Vec *, void *, Vec *);
extern s8 D_001F2130[];
extern s8 D_001F2140[];
extern s8 D_001F2160[];
extern s8 D_001F2170[];

void Mtx_LookDir_1_00146020(Mtx *m, f32 x, f32 y, f32 z) {
    Vec u;
    Vec s;
    Vec d;

    if (x == 0.0f && y == 0.0f && z == 0.0f) {
        sceVu0CopyMatrix(m, D_001F2170);
        return;
    }
    d.x = x;
    d.y = y;
    d.z = z;
    *(s32 *)&d.w = 0;
    sceVu0Normalize(&d, &d);
    if (0.9999f < fabsf(d.y)) {
        sceVu0CopyVector(&u, D_001F2130);
    } else {
        sceVu0OuterProduct(&u, D_001F2140, &d);
    }
    sceVu0Normalize(&u, &u);
    sceVu0OuterProduct(&s, &d, &u);
    sceVu0CopyVector(&m->m[0], &u);
    sceVu0CopyVector(&m->m[1], &s);
    sceVu0CopyVector(&m->m[2], &d);
    sceVu0CopyVector(&m->m[3], D_001F2160);
}
