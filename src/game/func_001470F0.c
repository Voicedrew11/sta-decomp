#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
s32 func_00145D10(Vec *, Vec *, s32, s32, Vec *);
s32 func_00145A80(Vec *, Vec *, s32, s32, Vec *);
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
float sqrtf(float);

s32 func_001470F0(Vec *a0, Vec *a1, u8 flags, s32 a3, s32 t0, Vec *out) {
    Vec h1[4];
    Vec h2[4];
    Vec d1;
    Vec d2;
    s32 r1;
    s32 r2;
    f32 l;
    r1 = (flags & 1) ? func_00145D10(a0, a1, a3, t0, h1) : 0;
    r2 = (flags & 2) ? func_00145A80(a0, a1, a3, t0, h2) : 0;
    if (r1 && r2) {
        func_001029E8(&d1, h1, a0);
        d1.w = 0.0f;
        func_001029E8(&d2, h2, a0);
        d2.w = 0.0f;
        l = sqrtf(func_00102848(&d2, &d2));
        if (l < sqrtf(func_00102848(&d1, &d1))) {
            func_00102A60(out, h2);
        } else {
            func_00102A60(out, h1);
        }
        out->w = 1.0f;
    } else if (r1) {
        func_00102A60(out, h1);
    } else if (r2) {
        func_00102A60(out, h2);
    }
    return r1 || r2;
}
