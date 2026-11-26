#include "m2c.h"
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
void func_001650F0(void *, u8, s32, u32);
s8 func_00166C10(void *, s32);
s32 func_00164FC0(void *, u8, s32);
static inline u32 cv(f32 x) { return (u32)x; }
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

u8 func_00140480(Obj *a0, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 id;
    id = func_00166F80(H(a0), 0x2026, a0);
    func_00165070(H(a0), id, 0, a1);
    if (f0 > 1.0f) f0 = 1.0f;
    if (f0 < 0.0f) f0 = 0.0f;
    func_00165070(H(a0), id, 1, cv(100.0f * f0));
    if (f1 > 1.2f) f1 = 1.2f;
    func_00165070(H(a0), id, 2, cv(100.0f * f1));
    if (f2 > 1.2f) f2 = 1.2f;
    func_00165070(H(a0), id, 3, cv(100.0f * f2));
    func_001650F0(H(a0), id, 4, (u32)f3);
    func_00165070(H(a0), id, 5, a2);
    while (func_00166C10(H(a0), id) != 0) {}
    return func_00164FC0(H(a0), id, 0);
}
