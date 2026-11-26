#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad1C[0x370 - 0x1C]; f32 f370; u8 p374[0x39C - 0x374]; u8 b39C; u8 p39D[0x3A1 - 0x39D]; u8 r:5; u8 b5:1; u8 r2:2; u8 p3A2[2]; f32 f3A4; u8 p3A8[0x3D0 - 0x3A8]; f32 f3D0; u8 p3D4[0x430 - 0x3D4]; f32 f430; f32 f434; u8 p438[0x454 - 0x438]; f32 f454; } P;
void sceVu0CopyMatrix(MtxF *, MtxF *);
void sceVu0RotMatrixX(MtxF *, MtxF *, f32);
void sceVu0RotMatrixZ(MtxF *, MtxF *, f32);
void sceVu0RotMatrixY(MtxF *, MtxF *, f32);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0SubVector(Vec *, s8 *, Vec *);
void sceVu0ApplyMatrix(Vec *, MtxF *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0CameraMatrix(void *, Vec *, Vec *, Vec *);
s32 func_001D1E00(u8);
extern MtxF D_001F2170;
extern Vec D_001F2140;
extern f32 D_00222A40[];
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

void func_001C8F90(void *a0) {
    P *p;
    MtxF m;
    Vec v;
    Vec t;


    p = cur();
    if (p == 0) return;
    sceVu0CopyMatrix(&m, &D_001F2170);
    sceVu0RotMatrixX(&m, &m, p->f3A4 + WRAP(*(f32 *)(p->o + 0x30)));
    sceVu0RotMatrixZ(&m, &m, WRAP(*(f32 *)(p->o + 0x38)));
    sceVu0RotMatrixY(&m, &m, WRAP(3.1415927f + *(f32 *)(p->o + 0x34)));
    sceVu0ScaleVector(&v, &D_001F2140, p->f370);
    sceVu0SubVector(&v, p->o, &v);
    if (p->b5) {
        v.y += 4.0f * p->f454;
    } else {
        v.y += 2.0f * p->f454;
    }
    t.x = p->f430;
    t.y = p->f434;
    t.w = 1.0f;
    t.z = 0.0f;
    sceVu0ApplyMatrix(&t, &m, &t);
    sceVu0AddVector(&v, &v, &t);
    sceVu0CameraMatrix(a0, &v, (Vec *)m.m[2], (Vec *)m.m[1]);
    if (func_001D1E00(p->b39C)) {
        D_00222A40[0] = 75.0f * (1.0f - -0.6f * (p->f3D0 / -0.17453294f));
    } else {
        D_00222A40[0] = 75.0f;
    }
}
