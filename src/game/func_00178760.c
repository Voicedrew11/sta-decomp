#include "common.h"

extern volatile s32 D_00202020, D_0020201C, D_00202024;

void func_00178760(void)
{
    D_0020201C += *(volatile s32 *)0x10000000 + D_00202020 * 5000;
    *(volatile s32 *)0x10000000 = 0;
    D_00202020 = 0;
    D_00202024 = 0;
}
