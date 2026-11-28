#include "common.h"
void Quat_FromAxisAngle_2_0015E500(void *arg0, void *arg1, f32 fparg0);
void Quat_ToMatrixB_2_0015E580(f32 *m, Vec *q);
f32 cosf(f32);
f32 sinf(f32);

/* Quat_FromAxisAngle_2_0015E500 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
void Quat_FromAxisAngle_2_0015E500(void *arg0, void *arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;

    temp_f20 = 0.5f * fparg0;
    temp_f0 = sinf(temp_f20);
    M2C_FIELD(arg0, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) * temp_f0);
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) * temp_f0);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) * temp_f0);
    M2C_FIELD(arg0, f32 *, 0xC) = cosf(temp_f20);
}

/* Quat_ToMatrixB_2_0015E580 */
void Quat_ToMatrixB_2_0015E580(f32 *m, Vec *q) {
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
