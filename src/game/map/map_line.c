#include "common.h"
#include "game/effect.h"
s32 Map_RaycastCapsule_0_00145D10(Vec *, Vec *, s32, s32, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
float sqrtf(float);

s32 Map_LineTest_1_001470F0(Vec *a0, Vec *a1, u8 flags, s32 a3, s32 t0, Vec *out) {
    Vec h1[4];
    Vec h2[4];
    Vec d1;
    Vec d2;
    s32 r1;
    s32 r2;
    f32 l;
    r1 = (flags & 1) ? Map_RaycastCapsule_0_00145D10(a0, a1, a3, t0, h1) : 0;
    r2 = (flags & 2) ? Map_RaycastSegment_0_00145A80(a0, a1, a3, t0, h2) : 0;
    if (r1 && r2) {
        sceVu0SubVector(&d1, h1, a0);
        d1.w = 0.0f;
        sceVu0SubVector(&d2, h2, a0);
        d2.w = 0.0f;
        l = sqrtf(sceVu0InnerProduct(&d2, &d2));
        if (l < sqrtf(sceVu0InnerProduct(&d1, &d1))) {
            sceVu0CopyVector(out, h2);
        } else {
            sceVu0CopyVector(out, h1);
        }
        out->w = 1.0f;
    } else if (r1) {
        sceVu0CopyVector(out, h1);
    } else if (r2) {
        sceVu0CopyVector(out, h2);
    }
    return r1 || r2;
}
