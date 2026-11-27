#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define DEG(d) (3.1415927f * (d) / 180.0f)
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[7];
    u16 h10;
    u8 pad12[6];
    f32 x18; f32 pad1c;
    f32 x20; f32 pad24;
    f32 x28; f32 pad2c;
    f32 x30; f32 pad34;
    f32 x38; f32 pad3c;
    f32 x40;
} O;
extern Mtx D_001F2170;
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0RotMatrixZ(f32, Mtx *, Mtx *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void MapObj_SetSfxMatrix_0_001B0EB0(u8, u16, Mtx *);
void MapObj_SetSfxFlag_0_001B11F0(u8, u16, s32);

void MapCmd_SetSfxTransform_0_0017E390(O *o) {
    Mtx m;

    sceVu0CopyMatrix(&m, &D_001F2170);
    sceVu0RotMatrixZ(WRAP(DEG(o->x30)), &m, &m);
    sceVu0RotMatrixX(WRAP(DEG(o->x38)), &m, &m);
    sceVu0RotMatrixY(WRAP(DEG(o->x40)), &m, &m);
    m.m[3].x = o->x18;
    m.m[3].y = o->x20;
    m.m[3].z = o->x28;
    MapObj_SetSfxMatrix_0_001B0EB0(o->b8, o->h10, &m);
    MapObj_SetSfxFlag_0_001B11F0(o->b8, o->h10, 1);
}
