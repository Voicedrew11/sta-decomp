#include "common.h"
extern volatile s32 D_00202020; s32 Timer_GetTicks_3_001787A0(void) { return *(volatile s32 *)0x10000000 + D_00202020 * 5000; }
