#include "m2c.h"
f32 func_0011DBA8(f32);
f32 func_0011DBC0(f32, f32);
void func_001465C0(s32, f32 *);

void func_00145F40(s32 a0, f32 *a1, f32 *a2) {
    f32 v[3];

    func_001465C0(a0, v);
    if (a1 != NULL) {
        *a1 = func_0011DBC0(v[0], v[2]);
    }
    if (a2 != NULL) {
        *a2 = -func_0011DBA8(v[1]);
    }
}
