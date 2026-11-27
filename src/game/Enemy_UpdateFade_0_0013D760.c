#include "m2c.h"
#include "common.h"
typedef struct { u8 pad[0x294]; f32 x294; } Sub;
typedef struct {
    u8 pad[0x4B0]; Sub *x4B0; u8 p4B4[0x100]; Flags8 f5B4; u8 p5B5[0x1F]; f32 x5D4; f32 x5D8;
} O;
s32 EnemyScr_Event2020_1_00140EF0(O *);

void Enemy_UpdateFade_0_0013D760(O *o, f32 dt) {
    f32 v;
    f32 t;
    f32 d;

    t = o->x5D8;
    v = o->x5D4;
    if (t > dt) t -= dt; else t = 0.0f;
    o->x5D8 = t;
    if (t > 0.0f) {
        v = 1.0f;
    } else if (o->f5B4.f.b6 || o->f5B4.f.b7 || !(u8)EnemyScr_Event2020_1_00140EF0(o)) {
        v += dt / 1.5f;
        if (v > 1.0f) v = 1.0f;
    } else {
        d = o->x4B0->x294;
        if (d == 0.0f) {
            v = 0.0f;
        } else {
            v -= dt / d;
            if (v < 0.0f) v = 0.0f;
        }
    }
    o->x5D4 = v;
}
