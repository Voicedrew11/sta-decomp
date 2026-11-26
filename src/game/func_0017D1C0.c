#include "common.h"
s32 *func_00165130(void *, s32);
void func_0017D1C0(u8 *a0) {
    s32 *p = func_00165130(a0, 0);
    s32 *q = func_00165130(a0, 1);
    s32 m = *(s32 *)(a0 + 0x18);
    if (m == 0) *p = *(f32 *)q;
    if (m == 1) *(f32 *)q = *p;
}

