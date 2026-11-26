#include "common.h"

extern s32 D_00201CC0;
extern volatile s32 D_00202020, D_0020201C, D_00202024;
void func_001787C0(void);
s32 AddIntcHandler(s32 cause, void (*f)(void), s32 next);
void EnableIntc(s32 cause);

void func_001787F0(void)
{
    *(volatile s32 *)0x10000010 = 0x1C1;
    *(volatile s32 *)0x10000020 = 5000;
    D_00201CC0 = AddIntcHandler(9, func_001787C0, -1);
    EnableIntc(9);
    D_0020201C += *(volatile s32 *)0x10000000 + D_00202020 * 5000;
    *(volatile s32 *)0x10000000 = 0;
    D_00202020 = 0;
    D_00202024 = 0;
}
