#include "common.h"
f32 func_00102848(Vec *, Vec *);
void func_00102870(Vec *, Vec *);
void func_001029A8(Vec *, Vec *, Vec *, f32);
void func_00102A18(Vec *, Vec *, f32);
float sqrtf(float);

void func_0015E970(Vec *out, Vec *a, Vec *b, f32 t) {
    Vec la, lb, ls;
    la.x = sqrtf(func_00102848(&a[0], &a[0]));
    la.y = sqrtf(func_00102848(&a[1], &a[1]));
    la.z = sqrtf(func_00102848(&a[2], &a[2]));
    lb.x = sqrtf(func_00102848(&b[0], &b[0]));
    lb.y = sqrtf(func_00102848(&b[1], &b[1]));
    lb.z = sqrtf(func_00102848(&b[2], &b[2]));
    func_001029A8(&ls, &la, &lb, t);
    func_001029A8(&out[0], &a[0], &b[0], t);
    func_001029A8(&out[1], &a[1], &b[1], t);
    func_001029A8(&out[2], &a[2], &b[2], t);
    func_001029A8(&out[3], &a[3], &b[3], t);
    out[3].w = 1.0f;
    func_00102870(&out[0], &out[0]);
    func_00102870(&out[1], &out[1]);
    func_00102870(&out[2], &out[2]);
    func_00102A18(&out[0], &out[0], ls.x);
    func_00102A18(&out[1], &out[1], ls.y);
    func_00102A18(&out[2], &out[2], ls.z);
}
