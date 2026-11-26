#include "m2c.h"
typedef struct {
    f32 m[12];
    f32 pos[4];
    u8 pad40[0x48];
    s8 *x88;
    u8 pad8C[0x10];
    s16 x9C;
    u8 pad9E[6];
    u8 xA4;
    u8 padA5[3];
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } xA8;
} Obj;
extern f32 D_00222850[];
void memcpy(void *, void *, s32);
void sceVu0InterVector(f32, f32 *, f32 *, f32 *);
void sceVu0ApplyMatrix(f32 *, void *, f32 *);
void sceVu0CopyVector(f32 *, f32 *);
f32 fabsf(f32);

void func_001AC200(Obj *o, Obj **best, f32 *dist) {
    f32 v[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 x, y, z, d;
    if (o->x9C != -1 && o->xA8.b0 && !o->xA8.b2 && o->xA4 == 0) {
        if (o->x88 != 0) {
            memcpy(a, o->x88, 0x10);
            memcpy(b, o->x88 + 0x40, 0x10);
            sceVu0InterVector(0.5f, v, a, b);
            v[3] = 1.0f;
            sceVu0ApplyMatrix(v, o, v);
        } else {
            sceVu0CopyVector(v, o->pos);
        }
        sceVu0ApplyMatrix(v, D_00222850, v);
        z = v[2];
        x = v[0];
        y = v[1];
        if (!(z < 0.0f) && z <= 330.0f) {
            if (!(fabsf(x) <= 150.0f) || !(fabsf(y) <= 100.0f)) return;
            z = 2.0f * z + 10.0f * fabsf(x);
            d = z + 10.0f * fabsf(y);
            if (d < *dist) {
                *dist = d;
                *best = o;
            }
        }
    }
}
