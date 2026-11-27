#include "common.h"
typedef struct { u8 pad[8]; u8 x8; u8 p9[7]; u8 x10; u8 p11[7]; u8 x18; u8 p19[7]; u8 x20; u8 p21[7]; u32 x28; } Arg;
void ScreenFx_SetFadeTarget_0_00159400(f32, Vec *);
static inline f32 u2f(u32 x) { return x; }

void MapCmd_FadeTo_1_0017A650(Arg *a0) {
    Vec v;
    f32 t;

    t = (f32)a0->x28 / 30.0f;
    v.x = u2f(a0->x8);
    v.y = u2f(a0->x10);
    v.z = u2f(a0->x18);
    v.w = u2f(a0->x20);
    ScreenFx_SetFadeTarget_0_00159400(t, &v);
}
