#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
void func_00145760(Vec *);
void sceVu0SubVector(Vec *, Vec *, s8 *);
f32 func_0011DBC0(f32, f32);

f32 func_00140160(Actor *a) {
    f32 r;
    f32 d;
    Vec v;
    r = *(f32 *)(*(s8 **)(a->unk518 + 0x198) + 0x24);
    func_00145760(&v);
    sceVu0SubVector(&v, &v, *(s8 **)(a->unk518 + 0x198));
    d = 3.1415927f + func_0011DBC0(v.x, v.z);
    d = WRAP(d) - r;
    if (!(d <= 3.1415927f)) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    d /= 3.1415927f;
    return d;
}
