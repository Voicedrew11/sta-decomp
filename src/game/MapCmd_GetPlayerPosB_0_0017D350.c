#include "common.h"

f32 *Script_GetArgPtr_2_00165130(void *o, s32 b);
void Player_GetPosB_0_001C9490(f32 *v);

void MapCmd_GetPlayerPosB_0_0017D350(void *o)
{
    f32 *x = Script_GetArgPtr_2_00165130(o, 0);
    f32 *y = Script_GetArgPtr_2_00165130(o, 1);
    f32 *z = Script_GetArgPtr_2_00165130(o, 2);
    f32 v[4];
    Player_GetPosB_0_001C9490(v);
    *x = v[0];
    *y = v[1];
    *z = v[2];
}
