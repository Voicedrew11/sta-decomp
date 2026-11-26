#include "common.h"
typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u16 func_0013D560(u8, u8);
u16 func_0013F750(void *p);
void func_0013F710(void *, s32);
void func_00144420(u8 *o) {
    void *p = D_00201FA8->p;
    u16 a = func_0013D560(o[8], o[0x10]);
    u16 b = func_0013F750(p);
    if (a < b && a > 0) {
        func_0013F710(p, a - b);
    }
}
