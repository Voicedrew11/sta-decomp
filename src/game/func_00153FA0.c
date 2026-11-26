#include "m2c.h"
extern s32 D_00201F28;
extern f32 D_00201C60;
extern f32 D_00201F58, D_00201F5C, D_00201F60, D_00201F64, D_00201F68, D_00201F6C, D_00201F70, D_00201F74;
extern f32 D_002F1600[4][4];
extern f32 D_002F1640[4][4];
void sceVu0CopyVector(f32 *, f32 *);
void sceVu0ApplyMatrix(f32 *, f32 (*)[4], f32 *);

s32 func_00153FA0(f32 *s) {
    f32 v[4] __attribute__((aligned(16)));
    f32 *w;
    f32 r;
    f32 p0, p1, p2, p3, p4, p5, p6, p7;

    r = s[3];
    sceVu0CopyVector(v, s);
    w = &v[3];
    *w = 1.0f;
    if (D_00201F28 != 0) {
        sceVu0ApplyMatrix(v, D_002F1600, v);
    } else {
        sceVu0ApplyMatrix(v, D_002F1640, v);
    }
    p0 = v[0] * D_00201F70 + *w * D_00201F74;
    p1 = v[0] * -D_00201F70 + *w * D_00201F74;
    p2 = v[1] * D_00201F68 + *w * D_00201F6C;
    p3 = v[1] * -D_00201F68 + *w * D_00201F6C;
    p4 = v[0] * D_00201F60 + *w * D_00201F64;
    p5 = v[0] * -D_00201F60 + *w * D_00201F64;
    p6 = v[1] * D_00201F58 + *w * D_00201F5C;
    p7 = v[1] * -D_00201F58 + *w * D_00201F5C;
    if (p0 + r < 0.0f) return -1;
    if (p1 + r < 0.0f) return -1;
    if (p2 + r < 0.0f) return -1;
    if (p3 + r < 0.0f) return -1;
    if (*w + r < 0.0f) return -1;
    if (!(*w - r <= D_00201C60)) return -1;
    if (!(p0 - r <= 0.0f || p1 - r <= 0.0f || p2 - r <= 0.0f || p3 - r <= 0.0f)) return 0;
    if (!(p4 - r <= 0.0f || p5 - r <= 0.0f || p6 - r <= 0.0f || p7 - r <= 0.0f)) return 1;
    return 2;
}
