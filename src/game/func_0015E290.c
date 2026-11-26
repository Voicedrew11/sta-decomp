#include "m2c.h"
f32 sqrtf(f32);
void sceVu0Normalize(f32 *, f32 *);
void sceVu0CopyVector(f32 *, f32 *);
extern f32 D_003139A0[4];
static inline f32 hs(f32 *d, f32 x) {
    *d = sqrtf(x) / 2.0f;
    return 1.0f / (4.0f * *d);
}

void func_0015E290(f32 *out, f32 (*a)[4]) {
    f32 m[4][4];
    f32 q[4];
    f32 t;
    f32 s;
    f32 f;
    s32 i;
    s32 j;
    s32 k;

    sceVu0Normalize(m[0], a[0]);
    sceVu0Normalize(m[1], a[1]);
    sceVu0Normalize(m[2], a[2]);
    sceVu0CopyVector(m[3], D_003139A0);
    m[3][3] = 1.0f;
    t = m[0][0] + m[1][1] + m[2][2] + 1.0f;
    if (!(t < 1.0f)) {
        f = hs(&q[3], t);
        q[0] = f * (m[1][2] - m[2][1]);
        q[1] = f * (m[2][0] - m[0][2]);
        q[2] = f * (m[0][1] - m[1][0]);
    } else {
        if (m[0][0] < m[1][1]) {
            if (m[1][1] < m[2][2]) {
                i = 2;
            } else {
                i = 1;
            }
        } else {
            if (m[0][0] < m[2][2]) {
                i = 2;
            } else {
                i = 0;
            }
        }
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        f = hs(&q[i], m[i][i] - m[j][j] - m[k][k] + 1.0f);
        q[j] = f * (m[i][j] + m[j][i]);
        q[k] = f * (m[i][k] + m[k][i]);
        q[3] = f * (m[j][k] - m[k][j]);
    }
    sceVu0CopyVector(out, q);
}
