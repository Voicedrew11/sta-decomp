#include "common.h"
extern volatile s32 D_00202020;
extern volatile s32 D_0020201C;
extern volatile s32 D_00202024;
void Timer_Update_3_00178760(void);

/* Timer_Update_3_00178760 */
void Timer_Update_3_00178760(void)
{
    D_0020201C += *(volatile s32 *)0x10000000 + D_00202020 * 5000;
    *(volatile s32 *)0x10000000 = 0;
    D_00202020 = 0;
    D_00202024 = 0;
}

/* Timer_GetTicks_3_001787A0 */
 s32 Timer_GetTicks_3_001787A0(void) { return *(volatile s32 *)0x10000000 + D_00202020 * 5000; }
