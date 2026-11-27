#include "common.h"

u8 *Script_GetArgPtr_2_00165130(s32 a, s32 b);
u8 Game_GetBusy_0_0012C020(void);
u8 Player_IsActionLocked_0_001C9AE0(void);

void MapCmd_IsBusy_0_0017CA10(s32 a)
{
    u8 *p = Script_GetArgPtr_2_00165130(a, 0);
    u8 x = Game_GetBusy_0_0012C020();
    *p = x | Player_IsActionLocked_0_001C9AE0();
}
