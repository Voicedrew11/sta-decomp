#include "m2c.h"
typedef f32 Mtx[4][4];
typedef struct { f32 x0[3]; f32 xC; f32 x10[3]; f32 x1C; Mtx x20; s32 x60; } S;
void sceVu0UnitMatrix(Mtx);
void sceVu0MulMatrix(Mtx, Mtx, Mtx);
void sceVu0CopyVector(f32 *, f32 *);
void sceVu0OuterProduct(f32 *, f32 *, f32 *);
f32 sceVu0InnerProduct(f32 *, f32 *);
void sceVu0Normalize(f32 *, f32 *);
void Draw_SelectionRing_0_00156450(Mtx, f32, s32);
float sqrtf(float);
extern f32 D_001F2140[];
extern f32 D_001F2130[];
extern Mtx D_002F1840;

void Draw_ShadowDisc_0_00156920(S *s) {
    Mtx a;
    Mtx b;
    Mtx d;
    Mtx c;
    sceVu0UnitMatrix(a);
    a[0][0] = s->xC;
    a[1][1] = s->xC;
    a[2][2] = s->xC;
    sceVu0UnitMatrix(b);
    b[0][0] = 1.0f;
    b[1][1] = 1.0f;
    b[2][2] = 1.0f;
    sceVu0CopyVector(b[2], s->x10);
    b[2][3] = 0.0f;
    sceVu0CopyVector(b[1], D_001F2140);
    sceVu0OuterProduct(b[0], b[1], b[2]);
    if (sqrtf(sceVu0InnerProduct(b[0], b[0])) < 1e-5f) {
        sceVu0CopyVector(b[0], D_001F2130);
    } else {
        sceVu0Normalize(b[0], b[0]);
    }
    sceVu0OuterProduct(b[1], b[2], b[0]);
    if (sqrtf(sceVu0InnerProduct(b[1], b[1])) < 1e-5f) {
        sceVu0CopyVector(b[0], D_001F2140);
    } else {
        sceVu0Normalize(b[1], b[1]);
    }
    sceVu0MulMatrix(a, a, b);
    sceVu0CopyVector(a[3], s->x0);
    a[3][3] = 1.0f;
    sceVu0MulMatrix(c, s->x20, a);
    sceVu0MulMatrix(d, D_002F1840, c);
    Draw_SelectionRing_0_00156450(d, s->x1C / s->xC, s->x60);
}
