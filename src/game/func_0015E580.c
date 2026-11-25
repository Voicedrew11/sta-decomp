#include "common.h"

void func_0015E580(f32 *m, Vec *q) {
    f32 s, n;
    f32 xs, ys, zs;
    f32 wx, wy, wz, xx, xy, xz, yy, yz, zz;
    f32 x, y, z, w;
    x = q->x; y = q->y; z = q->z; w = q->w;
    n = x * x + y * y + z * z + w * w;
    s = n > 1e-5f ? 2.0f / n : 0.0f;
    xs = x * s; ys = y * s; zs = z * s;
    wx = w * xs; xx = x * xs; wy = w * ys; wz = w * zs;
    xy = x * ys; xz = x * zs; zz = z * zs; yy = y * ys; yz = y * zs;
    m[0] = 1.0f - (yy + zz);
    m[4] = xy - wz;
    m[8] = xz + wy;
    m[1] = xy + wz;
    m[5] = 1.0f - (xx + zz);
    m[9] = yz - wx;
    m[2] = xz - wy;
    m[6] = yz + wx;
    m[10] = 1.0f - (xx + yy);
    m[14] = 0.0f;
    m[13] = 0.0f;
    m[12] = 0.0f;
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
}
