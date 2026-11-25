#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u8 func_0013EDE0(void *p);
s32 func_0013ED20(void *p);
void func_00140F90(u8 x, u8 a, u8 y, u8 b);

void func_001442F0(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    void *p = D_00201FA8->p;
    u8 x = func_0013EDE0(p);
    func_00140F90(x, a, (u8)func_0013ED20(p), b);
}
