#include "m2c.h"
typedef struct { f32 p0[4]; f32 p1[4]; } Ray;
typedef struct { f32 x0; f32 x4; s32 pad8[7]; s32 hit; s32 pad28[6]; } Res;
typedef struct { u8 p:6; u8 v:1; } BF6;
typedef struct {
    u8 pad0[0x30];
    f32 pos[4];
    u8 pad40[0x34];
    f32 x74;
    u8 pad78[0x24];
    s16 x9C;
    u8 pad9E[0xA];
    BF6 xA8;
    u8 padA9[7];
    f32 xB0;
} Obj;
void sceVu0CopyVector(f32 *, f32 *);
void memset(void *, s32, s32);
void func_001B2180(s32, Res *, Ray *, s32, s32);
extern s32 D_00201E80;

void func_001AE0E0(s32 arg0, Obj *obj) {
    Res res;
    Ray ray;
    s32 i;
    s32 side;

    side = 0;
    if (obj == 0) {
        return;
    }
    if (obj->x9C == -1) {
        return;
    }
    sceVu0CopyVector(ray.p0, obj->pos);
    ray.p0[3] = 1.0f;
    sceVu0CopyVector(ray.p1, obj->pos);
    ray.p1[3] = 1.0f;
    ray.p1[1] += 60000.0f;
    memset(&res, 0, 0x40);
    if (arg0 == (&D_00201E80)[2]) {
        side = 0;
    }
    if (arg0 == (&D_00201E80)[3]) {
        side = 1;
    }
    for (i = 0; i < 2; i++) {
        s32 *p = ((s32 **)(&D_00201E80 + 2))[side];
        if (p != 0) {
            func_001B2180(*p, &res, &ray, 6, 3);
            if (res.hit != 0) {
                break;
            }
        }
        side = !side;
    }
    if (res.hit != 0) {
        obj->xB0 = res.x4 - obj->x74;
    } else {
        obj->xB0 = 50000.0f;
    }
    obj->xA8.v = 1;
}
