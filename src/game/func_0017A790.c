#include "common.h"
s32 func_0013ED20(void *p);
u8 func_0013EDE0(void *p);
s32 func_0013EE30(s8 *);
s8 *func_001A5460(s32 *);
void func_00141510(s8 *, u8, u8, u8);
void func_0017A790(u8 *o) {
    s32 it;
    s8 *p;
    it = 0;
    for (p = func_001A5460(&it); p != NULL; p = func_001A5460(&it)) {
        if (func_0013EE30(p) == 0) {
            u8 a = func_0013ED20(p);
            u8 b = func_0013EDE0(p);
            if (a == o[0x10] && b == o[8]) func_00141510(p, o[8], o[0x18], o[0x20]);
        }
    }
}
