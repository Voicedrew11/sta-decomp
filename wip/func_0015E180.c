#include "common.h"
void func_00102A60(Vec *, Vec *);
void func_00102A70(Mtx *, Mtx *);

void func_0015E180(Mtx *out, Vec *q) {
    Mtx m;
    f32 w;
    f32 x;
    Vec v;
    f32 y;
    f32 z;
    func_00102A60(&v, q);
    x = v.x; y = v.y; z = v.z; w = v.w;
    m.m[0].x = 1.0f - 2.0f * (y * y + z * z);
    m.m[0].y = 2.0f * (x * y + z * w);
    m.m[1].x = 2.0f * (x * y - z * w);
    m.m[1].y = 1.0f - 2.0f * (x * x + z * z);
    m.m[2].z = 1.0f - 2.0f * (x * x + y * y);
    m.m[0].z = 2.0f * (x * z - y * w);
    m.m[2].x = 2.0f * (x * z + y * w);
    m.m[1].z = 2.0f * (y * z + x * w);
    m.m[2].y = 2.0f * (y * z - x * w);
    m.m[0].w = 0.0f;
    m.m[1].w = 0.0f;
    m.m[2].w = 0.0f;
    m.m[3].w = 1.0f;
    m.m[3].x = 0.0f;
    m.m[3].y = 0.0f;
    m.m[3].z = 0.0f;
    func_00102A70(out, &m);
}
