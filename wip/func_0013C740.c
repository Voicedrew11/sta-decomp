/* NEAR: retail calls func_0013E920 without setting $a0 after func_0013C360 (no reload of o).
 * Maybe the same translation unit as func_0013C360 (callee known to keep $a0)? */
#include "common.h"
typedef struct { u8 pad[0x5B0]; u8 x5B0; } O;
u32 func_0013E940(O *);
void func_0013C360(O *, s16, s32, s32, s32);
void func_0013E920(O *, u8);

s32 func_0013C740(O *o) {
    if (func_0013E940(o) == 0) {
        func_0013C360(o, (o->x5B0 & 1) * 32 + 0x13, 0, 0, 2);
        func_0013E920(o, 1);
    }
    return 0;
}
