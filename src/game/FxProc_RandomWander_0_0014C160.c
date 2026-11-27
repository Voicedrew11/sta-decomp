#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5C[4];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[0x34];
    u8 xC0[0x54];
    Bits f114;
} O;
u16 Rand_Next_3_0015ED20(void);
s32 Map_LineTest_1_001470F0(Vec *, Vec *, s32, s32, s32, O *);
void sceVu0RotMatrixZ(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0CopyMatrix(void *, Mtx *);
extern Mtx D_001F2170;
static inline f32 u2f(u32 x) { return x; }

void FxProc_RandomWander_0_0014C160(O *o) {
    Mtx m;
    Vec lo;
    Vec hi;
    s32 ok;
    f32 up;
    f32 dn;
    f32 a;
    f32 rx;

    o->p.x += o->x50 * ((0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()) - 0.5f);
    o->p.z += o->x58 * ((0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20()) - 0.5f);
    if (o->x68) {
        ok = 1;
    } else {
        up = (0.0f < o->x64) ? o->x64 : 1000.0f;
        dn = (0.0f < o->x64) ? o->x64 : 1000.0f;
        lo.x = o->p.x;
        lo.y = o->p.y - dn;
        lo.z = o->p.z;
        hi.x = o->p.x;
        hi.y = o->p.y + up;
        hi.z = o->p.z;
        hi.w = 1.0f;
        lo.w = 1.0f;
        ok = Map_LineTest_1_001470F0(&lo, &hi, 3, 4, 1, o);
    }
    o->p.y += o->x54;
    if (!ok) {
        o->x88 = u2f(o->f114.b1 = 0);
        return;
    }
    rx = 0.0f;
    if (rx == o->x60) return;
    rx = (o->x60 != rx) ? 0.01745f * o->x60 : rx;
    a = 0.5f * rx;
    sceVu0RotMatrixZ(&m, &D_001F2170, WRAP(a * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20())));
    sceVu0RotMatrixY(&m, &m, WRAP(6.2831855f * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20())));
    sceVu0CopyMatrix(o->xC0, &m);
}
