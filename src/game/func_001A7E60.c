#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + *(volatile f32 *)&(x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define WRAPV(x, y) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (y)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct {
    Vec v0;
    Vec v10;
    Vec rot;
    Vec v30;
    Vec v40;
    f32 s50, s54, s58, s5C;
    Mtx m;
    u8 padA0[0x10];
    s32 *xB0;
} N;
typedef struct {
    u8 pad[0x244];
    u16 x244, x246, x248;
} I;
typedef struct {
    f32 x0, x4, x8;
    s32 xC;
    N *x10;
    s32 x14;
    N *x18;
    I *x1C;
    s32 x20;
    s32 *x24;
    s32 x28;
    s8 *x2C;
    u8 pad30[0x10];
    Vec v40;
    Vec v50;
    Mtx m;
    Vec vA0;
    u8 padB0[0x44];
    s32 xF4;
} P;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x4A8];
    I *x4B0;
    u8 pad4B4[0x60];
    s32 x514;
    s8 *x518;
    s32 x51C;
} A;
extern Mtx D_001F2170;
extern Vec D_003139A0;
s8 *func_001715B0(s32 *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
static inline f32 u2f(u32 x) { return x; }

void func_001A7E60(A *a) {
    P *p;
    f32 *r;

    if (a == NULL || a->x518 == NULL) {
        return;
    }
    p = (P *)(a->x518 + 0x180);
    p->xC = a->x4;
    p->x10 = (N *)a->x518;
    p->x14 = a->x51C;
    p->x18 = p->x10;
    p->x1C = a->x4B0;
    p->x20 = a->x514;
    p->x24 = p->x10->xB0;
    if (p->x24 != NULL) {
        p->x28 = *p->x24;
    }
    p->x2C = func_001715B0(p->x24);
    r = &p->x10->rot.x;
    *r = WRAPV(p->x10->rot.x, *r);
    r = &p->x10->rot.y;
    *r = WRAPV(p->x10->rot.y, *r);
    r = &p->x10->rot.z;
    *r = WRAPV(p->x10->rot.z, *r);
    sceVu0CopyVector(&p->x10->v10, &p->x10->v0);
    sceVu0CopyVector(&p->x10->v30, &p->x10->rot);
    sceVu0CopyMatrix(&p->x18->m, &D_001F2170);
    p->x0 = (f32)(u32)a->x4B0->x244 * p->x18->s50 / 4096.0f;
    p->x4 = (f32)(u32)a->x4B0->x246 * p->x18->s54 / 4096.0f;
    p->x8 = (f32)(u32)a->x4B0->x248 * p->x18->s58 / 4096.0f;
    p->x18->m.m[0].x = p->x0;
    p->x18->m.m[1].y = p->x4;
    p->x18->m.m[2].z = p->x8;
    sceVu0RotMatrixY(&p->m, &p->x18->m, WRAP(p->x18->rot.y));
    sceVu0CopyMatrix(&p->x18->m, &p->m);
    sceVu0CopyVector(&p->x18->m.m[3], &p->x18->v0);
    p->x18->m.m[3].w = 1.0f;
    sceVu0CopyVector(&p->v40, &p->x10->v0);
    sceVu0CopyVector(&p->v50, &p->x10->v40);
    sceVu0CopyVector(&p->vA0, &D_003139A0);
    p->xF4 = 0;
}
