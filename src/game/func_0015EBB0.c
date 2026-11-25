#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
f32 func_0011D778(f32);
f32 func_0011DA18(f32);
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_00102A70(f32 *, f32 *);
float sqrtf(float);
extern f32 D_001F2170[];

void func_0015EBB0(f32 *m, Vec *axis, f32 ang) {
    Vec v;
    f32 c, s, t;
    f32 xx, yy, zz, xy, yz, zx, xs, ys, zs; f32 x, y, z;
    c = func_0011D778(ang);
    s = func_0011DA18(ang);
    t = 1.0f - c;
    if (sqrtf(func_00102848(axis, axis)) < 1e-5f) {
        func_00102A70(m, D_001F2170);
        return;
    }
    func_00102870(&v, axis);
    x = v.x; y = v.y; z = v.z;
    xx = x * x; yy = y * y; zz = z * z; xy = x * y; yz = y * z; zx = z * x; xs = x * s; ys = y * s; zs = z * s;
    m[0] = c + t * xx;
    m[4] = t * xy - zs;
    m[8] = ys + t * zx;
    m[1] = zs + t * xy;
    m[5] = c + t * yy;
    m[9] = t * yz - xs;
    m[2] = t * zx - ys;
    m[6] = xs + t * yz;
    m[10] = c + t * zz;
    m[14] = 0.0f;
    m[13] = 0.0f;
    m[12] = 0.0f;
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
}
