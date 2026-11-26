#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef union { u128 q; Vec v; } QV;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);
Vec *func_00145770(void);
f32 func_0013E440(s8 *);
void func_0015E730(Vec *, Vec *, Vec *, f32);
float sqrtf(float);
extern QV D_001F1C80;

void func_00136DB0(s8 *a0, Vec *mat) {
    Vec e;
    QV up;
    Vec m[4];
    Vec t80;
    Vec t70;
    f32 d;
    f32 c, s, t;
    f32 xx, yy, zz, xy, yz, zx, xs, ys, zs; f32 x, y, z;
    f32 r;
    up = D_001F1C80;
    sceVu0SubVector(&m[2], &mat[3], func_00145770());
    sceVu0Normalize(&m[2], &m[2]);
    sceVu0Normalize(&e, &mat[2]);
    d = sceVu0InnerProduct(&e, &m[2]);
    if (d < 0.0f) {
        sceVu0ScaleVector(&t80, &e, -2.0f * d);
        sceVu0AddVector(&m[2], &m[2], &t80);
        sceVu0Normalize(&m[2], &m[2]);
        d = sceVu0InnerProduct(&e, &m[2]);
    }
    if (d < 0.5f) {
        sceVu0OuterProduct(&t70, &e, &m[2]);
        sceVu0Normalize(&t70, &t70);
        x = t70.x; y = t70.y; z = t70.z;
        m[2].x = e.x * (0.5f + 0.5f * (x * x)) + e.y * (0.5f * (y * x) - z * 0.8660254f) + e.z * (y * 0.8660254f + 0.5f * (z * x));
        m[2].y = e.x * (z * 0.8660254f + 0.5f * (y * x)) + e.y * (0.5f + 0.5f * (y * y)) + e.z * (0.5f * (z * y) - x * 0.8660254f);
        m[2].z = e.x * (0.5f * (z * x) - y * 0.8660254f) + e.y * (x * 0.8660254f + 0.5f * (z * y)) + e.z * (0.5f + 0.5f * (z * z));
        sceVu0Normalize(&m[2], &m[2]);
    }
    sceVu0OuterProduct(&m[0], &up.v, &m[2]);
    sceVu0Normalize(&m[0], &m[0]);
    sceVu0OuterProduct(&m[1], &m[2], &m[0]);
    sceVu0CopyVector(&m[3], &mat[3]);
    m[0].w = 0.0f;
    m[1].w = 0.0f;
    m[2].w = 0.0f;
    sceVu0ScaleVector(&m[0], &m[0], sqrtf(sceVu0InnerProduct(&mat[0], &mat[0])));
    sceVu0ScaleVector(&m[1], &m[1], sqrtf(sceVu0InnerProduct(&mat[1], &mat[1])));
    sceVu0ScaleVector(&m[2], &m[2], sqrtf(sceVu0InnerProduct(&mat[2], &mat[2])));
    r = func_0013E440(a0);
    sceVu0CopyVector(&m[3], &mat[3]);
    func_0015E730(mat, mat, m, 1.0f - r);
}
