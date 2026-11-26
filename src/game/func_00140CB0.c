#include "m2c.h"
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
void func_00164FF0(void *, u8, s32, f32);
s8 func_00166C10(void *, s32);
u8 func_00164FC0(void *, u8, s32);
f32 func_00164F60(void *, u8, s32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

void func_00140CB0(Obj *a0, u8 *pa, f32 *pb, f32 *pc) {
    s32 h;
    h = func_00166F80(H(a0), 0x2023, a0);
    func_00165070(H(a0), h, 0, 0);
    func_00164FF0(H(a0), h, 1, 2.0f);
    func_00164FF0(H(a0), h, 2, 0.0f);
    while (func_00166C10(H(a0), h) != 0) {}
    if (pa) *pa = func_00164FC0(H(a0), h, 0);
    if (pb) *pb = func_00164F60(H(a0), h, 1);
    if (pc) *pc = func_00164F60(H(a0), h, 2);
}
