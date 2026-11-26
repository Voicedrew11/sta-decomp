#include "common.h"
typedef struct { u8 b0 : 3; u8 b3 : 1; u8 b4 : 4; } F;
extern F D_00222A53[];
typedef struct { char p[0x290]; f32 x290; } Q;
typedef struct { char p[0x4B0]; Q *q; char p2[0x5BC - 0x4B4]; f32 x5BC; f32 x5C0; char p3[0x10]; f32 x5D4; } A;
f32 func_0013D6C0(A *a) {
    f32 r;
    if (D_00222A53[0].b3) {
        r = (1.0f - (1.0f - a->q->x290) * (1.0f - a->x5D4)) * (a->x5BC * a->x5C0);
    } else {
        r = a->x5BC * a->x5C0;
    }
    if (r > 1.0f) r = 1.0f;
    if (r < 0.0f) r = 0.0f;
    return r;
}
