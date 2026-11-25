#include "common.h"

u8 *func_00165130(s32 a, s32 b);
u8 func_0012C020(void);
u8 func_001C9AE0(void);

void func_0017CA10(s32 a)
{
    u8 *p = func_00165130(a, 0);
    u8 x = func_0012C020();
    *p = x | func_001C9AE0();
}
