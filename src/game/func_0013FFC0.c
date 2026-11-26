#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
Vec *func_00145710(void);
void func_00145760(Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 func_0011DBC0(f32, f32);

f32 func_0013FFC0(s8 *a0) {
 Vec v; f32 y; f32 d; f32 a;
 y = func_00145710()->y;
 func_00145760(&v);
 sceVu0SubVector(&v, *(Vec **)(*(s8 **)(a0 + 0x518) + 0x198), &v);
 a = 3.1415927f + func_0011DBC0(v.x, v.z); a = WRAP(a); y = WRAP(y); y = a - y;
 if (y > 3.1415927f) y -= 6.2831855f;
 if (y < -3.1415927f) y += 6.2831855f;
 y /= 3.1415927f; return y;
}
