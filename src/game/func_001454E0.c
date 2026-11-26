#include "common.h"
typedef struct { u32 w; u32 pad; } W;
typedef struct { W x0; W x8; W x10; W x18; } Arg;
u8 *func_00165130(Arg *, s32);
void *func_00179DB0(u16, u16);
u8 func_0018AC90(void *, s32);

void func_001454E0(Arg *a) {
    u32 v = a->x8.w;
    u8 *p = func_00165130(a, 1);
    u8 k = a->x18.w;
    void *o = func_00179DB0(v / 1000, v % 1000);
    if (o) {
        if (k == 0) *p = func_0018AC90(o, 0);
        if (k == 1) *p = func_0018AC90(o, -1);
    } else {
        *p = 3;
    }
}
