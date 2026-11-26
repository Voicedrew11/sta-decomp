#include "m2c.h"
typedef union { u128 q; f32 f[4]; } V;
void sceVu0ApplyMatrix(f32 *, f32 *, f32 *);
void sceVu0InversMatrix(f32 *, f32 *);
void sceVu0CopyMatrix(f32 *, f32 *);
extern V D_001F2040[];
extern f32 D_002F16C0[];
extern f32 D_002F1840[];
extern f32 D_002F19E0[];
extern f32 D_002F2080[];
extern f32 D_002F20BC[];

void func_00159160(s32 *arg0, s32 *arg1) {
    V c;
    f32 m[16];
    f32 b[4];
    f32 a[4];
    f32 w;

    if (D_002F20BC[0] == 0.0f) {
        *arg0 = 0;
        *arg1 = 0;
        sceVu0CopyMatrix(D_002F2080, D_002F16C0);
        return;
    }
    c = D_001F2040[0];
    c.f[2] = D_002F19E0[0];
    sceVu0InversMatrix(m, D_002F2080);
    sceVu0ApplyMatrix(b, m, c.f);
    sceVu0ApplyMatrix(a, D_002F1840, b);
    w = 1.0f / a[3];
    a[0] = a[0] * w - 2048.0f;
    a[1] = a[1] * w - 2048.0f;
    *arg0 = 8.0f * a[0];
    *arg1 = 8.0f * a[1];
    if (*arg0 < -0x80) {
        *arg0 = -0x80;
    }
    if (*arg0 > 0x80) {
        *arg0 = 0x80;
    }
    if (*arg1 < -0x80) {
        *arg1 = -0x80;
    }
    if (*arg1 > 0x80) {
        *arg1 = 0x80;
    }
    sceVu0CopyMatrix(D_002F2080, D_002F16C0);
}
