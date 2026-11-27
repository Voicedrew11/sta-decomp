#include "common.h"
extern volatile s32 D_00202020;
void Timer_IntrHandler_2_001787C0(void)
{
    D_00202020++;
    *(volatile s32 *)0x10000010 |= 0x400;
    asm("sync");
    asm("ei");
}
