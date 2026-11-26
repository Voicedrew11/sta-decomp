#include "common.h"
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
s8 func_00166C10(void *, s32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
f32 func_0013DD40(Obj *);
void func_0013E430(Obj *, f32);
void func_0013EF50(Obj *);
#define H(a) (*(a)->p)
void func_00142320(Obj *a0, s32 a1, s32 a2) {
    s32 id;
    id = func_00166F80(H(a0), 0x200C, a0);
    func_00165070(H(a0), id, 0, a1);
    func_00165070(H(a0), id, 1, a2);
    while (func_00166C10(H(a0), id) != 0) {}
    func_0013E430(a0, func_0013DD40(a0));
    func_0013EF50(a0);
}
