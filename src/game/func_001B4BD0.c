#include "m2c.h"
typedef struct { u8 pad[0x30]; f32 v[4]; } T;
typedef struct {
    u8 pad[0x10];
    f32 v[3];
    s32 x1C;
    s32 x20;
    u8 pad24[0x154];
    T ***x178;
    u8 pad17C[0x5C];
    u8 b0:1;
} O;
void sceVu0CopyVector(f32 *, f32 *);
static inline f32 diff(f32 *a, f32 *b) {
    f32 d;
    if ((d = a[0] - b[0]) != 0.0f) return d;
    if ((d = a[1] - b[1]) != 0.0f) return d;
    d = a[2] - b[2];
    return d != 0.0f ? d : 0.0f;
}

void func_001B4BD0(O *o, f32 *v) {
    if (diff(o->v, v) != 0.0f) {
        sceVu0CopyVector(o->v, v);
        o->x1C = 0;
        o->x20 = 2;
        if (o->b0) {
            sceVu0CopyVector((**o->x178)->v, o->v);
        }
    }
}
