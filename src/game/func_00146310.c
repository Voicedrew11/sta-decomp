#include "common.h"
void func_001029E8(Vec *, f32 *, f32 *);
void func_00102870(Vec *, Vec *);
f32 func_0011DBC0(f32, f32);
f32 func_0011DBA8(f32);

void func_00146310(f32 *p0, f32 *p1, f32 *p2, f32 *o1, f32 *o2) {
    Vec r;
    f32 a, c, b, e, d, w;

    func_001029E8(&r, p2, p0);
    func_00102870(&r, &r);
    a = func_0011DBC0(p1[0], p1[2]);
    c = -func_0011DBA8(p1[1]);
    b = func_0011DBC0(r.x, r.z);
    e = -func_0011DBA8(r.y);
    if (o1 != NULL) {
        d = b - a;
        w = d - 6.2831855f * (s32)(d / 6.2831855f);
        if (w > 3.1415927f) {
            w -= 6.2831855f;
        } else if (w < -3.1415927f) {
            w += 6.2831855f;
        }
        *o1 = w;
    }
    if (o2 != NULL) {
        d = e - c;
        w = d - 6.2831855f * (s32)(d / 6.2831855f);
        if (w > 3.1415927f) {
            w -= 6.2831855f;
        } else if (w < -3.1415927f) {
            w += 6.2831855f;
        }
        *o2 = w;
    }
}
