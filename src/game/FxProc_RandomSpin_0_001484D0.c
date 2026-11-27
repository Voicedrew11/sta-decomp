#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct {
    u8 pad0[0x10];
    Vec v;
    u8 pad20[0x30];
    f32 x50[3];
    u8 pad5C[4];
    f32 x60[3];
    f32 x6C;
    u8 pad70[0x40];
    f32 xB0[3];
    u8 padBC[4];
    u8 xC0[0x20];
    Vec xE0;
} O;
extern Mtx D_001F2170;
u16 Rand_Next_3_0015ED20(void);
void sceVu0RotMatrixY(f32, Mtx *, Mtx *);
void sceVu0RotMatrixX(f32, Mtx *, Mtx *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
f32 sqrtf(f32);
#define RND() (0.000015259022f * (f32)(u32)(Rand_Next_3_0015ED20)())

void FxProc_RandomSpin_0_001484D0(O *o) {
    f32 a;
    f32 b;

    a = o->x50[0];
    b = o->x60[0];
    o->xB0[0] = b + b * (-a + (a + a) * RND());
    a = o->x50[1];
    b = o->x60[1];
    o->xB0[1] = b + b * (-a + (a + a) * RND());
    a = o->x50[2];
    b = o->x60[2];
    o->xB0[2] = b + b * (-a + (a + a) * RND());
    if (o->x6C == 1.0f) {
        sceVu0RotMatrixX(WRAP(6.2831855f * RND()), (Mtx *)o->xC0, &D_001F2170);
        sceVu0RotMatrixY(WRAP(6.2831855f * RND()), (Mtx *)o->xC0, (Mtx *)o->xC0);
        sceVu0ScaleVector(&o->v, &o->xE0, sqrtf(sceVu0InnerProduct(&o->v, &o->v)));
    }
}
