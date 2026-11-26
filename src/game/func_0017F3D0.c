#include "common.h"
typedef struct { char p0[0x28]; f32 x28; char p2c[0x14]; f32 x40; char p44[4]; u8 b48; char p49[3]; } E;
extern E D_00486990[];
f32 fabsf(f32);
s32 func_0017F3D0(s32 i) {
    s32 r = fabsf(D_00486990[i].x40 - D_00486990[i].x28) < 0.01f;
    if (r) { E *e = &D_00486990[i]; r = (e->b48 & 1) != 0; }
    return r;
}
