#include "common.h"
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
void func_001650B0(void *, u8, s32, s32);
s8 func_00166C10(void *, s32);
s32 func_00164FC0(void *, u8, s32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)
u8 func_001426C0(Obj *a0, s32 a1) {
    s32 id;
    id = func_00166F80(H(a0), 0x2003, a0);
    func_00165070(H(a0), id, 0, 0);
    func_001650B0(H(a0), id, 1, a1);
    while (func_00166C10(H(a0), id) != 0) {}
    return func_00164FC0(H(a0), id, 0);
}
