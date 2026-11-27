#include "common.h"
typedef struct { char p[0x94]; u8 b0 : 1; u8 b1 : 1; } I;
typedef struct { char p[0x30]; Vec t; char p2[0x1D0]; I *x210; } O;
typedef struct { char p[0x20]; f32 x20; f32 x24; f32 x28; char p2[4]; Vec t; } M;
void Mtx_RotateToward_0_00146140(void *, f32, f32);
void sceVu0CopyMatrix(void *, void *);
void sceVu0CopyVector(Vec *, Vec *);
void Sfx_SetMatrixOrAim_0_00167740(void *a, void *b) {
M *arg1 = b; O *arg0 = a; if (a != NULL) { if (arg0->x210->b1) { Mtx_RotateToward_0_00146140(arg0, arg1->x20, arg1->x28); sceVu0CopyVector(&arg0->t, &arg1->t); return; } sceVu0CopyMatrix(arg0, arg1); }
}
