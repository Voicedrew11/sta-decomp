#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
s32 Enemy_GetHp_2_0013F750(void *p);
void GameFlag_GetWordWrap_0_0013D540(u8 a, u8 b, u16 c);

void EnemyCmd_StoreHpToFlag_1_00144490(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    GameFlag_GetWordWrap_0_0013D540(a, b, Enemy_GetHp_2_0013F750(D_00201FA8->p));
}
