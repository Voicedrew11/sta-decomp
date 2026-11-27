#include "m2c.h"
typedef struct { u8 pad[8]; s32 x8; u8 p0[4]; s32 x10; u8 p1[4]; s32 x18; u8 p2[4]; s32 x20; u8 p3[4]; f32 x28; } Arg;
s16 Map_GetLightIndex_0_001B0BC0(s32, s32);
f32 *LightGroup_Get_0_0015B900(s32);

void MapCmd_FadeLight_0_0017C6F0(volatile Arg *a) {
    f32 t;
    f32 u;
    s32 b;
    s32 c;
    s32 o;
    f32 *d;
    f32 *e;
    f32 *f;
    t = a->x28;
    b = a->x18;
    c = a->x20;
    o = a->x8;

    u = 1.0f - t;
    d = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, a->x10));
    e = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, b));
    f = LightGroup_Get_0_0015B900(Map_GetLightIndex_0_001B0BC0(o, c));
    if (d && e && f) {
        d[3] = e[3] * u + f[3] * t;
        d[4] = e[4] * u + f[4] * t;
        d[5] = e[5] * u + f[5] * t;
        d[6] = e[6] * u + f[6] * t;
        d[7] = e[7] * u + f[7] * t;
        d[8] = e[8] * u + f[8] * t;
        d[9] = e[9] * u + f[9] * t;
        d[10] = e[10] * u + f[10] * t;
        d[11] = e[11] * u + f[11] * t;
        d[12] = e[12] * u + f[12] * t;
        d[13] = e[13] * u + f[13] * t;
    }
}
