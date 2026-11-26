#include "common.h"
s32 func_0013FFA0(s32);
void sceVu0CopyVector(Vec *, s32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sqrtf(f32);
extern s32 D_002022E4;
typedef struct { Vec v; char p[0xAC]; f32 xBC; } O;
void func_0014D410(O *arg0) {
    Vec sp30;
    Vec sp20;
    f32 d;
    sceVu0CopyVector(&sp20, func_0013FFA0(D_002022E4));
    sceVu0SubVector(&sp30, &sp20, &arg0->v);
    d = sqrtf(sp30.x * sp30.x + sp30.z * sp30.z);
    d = (0.05f - d) / 0.1f; d *= 0.001f; arg0->xBC = d;
}
