#include "common.h"

void GameFlag_SetBit_2_0013D5C0(u8 arg0, u8 arg1);

void EnemyCmd_SetGameFlag_2_00145070(u8 *arg0)
{
    GameFlag_SetBit_2_0013D5C0(arg0[8], arg0[0x10]);
}
