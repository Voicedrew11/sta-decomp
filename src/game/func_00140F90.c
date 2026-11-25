#include "m2c.h"
s8 *func_001A5460(s32 *);
s32 func_0013EE30(s8 *);
s32 func_0013EDE0(s8 *);
s32 func_0013ED20(s8 *);
void func_00165070(void *, u8, s32, u32);
s32 func_00166C10(void *, s32);
s32 func_00166F80(void *, s32, void *);
#define H(o) (**(void ***)((o) + 0x4A4))

void func_00140F90(u8 a, u8 b, u32 c, u32 d) {
    s32 it;
    s8 *o;
    s32 h;
    it = 0;
    o = func_001A5460(&it);
    while (o != NULL) {
        if (!func_0013EE30(o) && a == func_0013EDE0(o) && b == (u8)func_0013ED20(o)) {
            h = func_00166F80(H(o), 0x2019, o);
            func_00165070(H(o), h, 0, c);
            func_00165070(H(o), h, 1, d);
            while ((s8)func_00166C10(H(o), h)) {
            }
            return;
        }
        o = func_001A5460(&it);
    }
}
