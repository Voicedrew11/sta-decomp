#include "common.h"
s32 func_00166F80(void *, s32, void *);
s8 func_00166C10(void *, s32);
void func_00164FF0(void *, u8, s32, f32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)
void func_001419C0(Obj *a0, f32 f) {
    s32 id;
    id = func_00166F80(H(a0), 0x2012, a0);
    func_00164FF0(H(a0), id, 0, f);
    while (func_00166C10(H(a0), id) != 0) {}
}
