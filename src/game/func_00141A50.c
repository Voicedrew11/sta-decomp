#include "m2c.h"
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
s8 func_00166C10(void *, s32);
u8 func_00164FC0(void *, u8, s32);
u32 func_0013E5E0(void *);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

void func_00141A50(Obj *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *p4) {
    s32 h;
    u32 v0, v1, v2, v3, v4;
    h = func_00166F80(H(a0), 0x2011, a0);
    func_00165070(H(a0), h, 0, 100);
    func_00165070(H(a0), h, 1, 100);
    func_00165070(H(a0), h, 2, 100);
    func_00165070(H(a0), h, 3, 100);
    func_00165070(H(a0), h, 4, 100);
    while (func_00166C10(H(a0), h) != 0) {}
    v0 = func_00164FC0(H(a0), h, 0);
    v1 = func_00164FC0(H(a0), h, 1);
    v2 = func_00164FC0(H(a0), h, 2);
    v3 = func_00164FC0(H(a0), h, 3);
    v4 = func_00164FC0(H(a0), h, 4);
    if (p0) *p0 = v0 / 100.0f;
    if (p1) *p1 = v1 / 100.0f;
    if (p2) *p2 = v2 / 100.0f;
    if (p3) *p3 = v3 / 100.0f;
    if (p4) *p4 = v4 / 100.0f;
    if (((u8)func_0013E5E0(a0) & 2) && p0) *p0 /= 2.0f;
}
