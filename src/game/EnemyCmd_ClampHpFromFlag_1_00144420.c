#include "common.h"
typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u16 GameFlag_GetHalf_0_0013D560(u8, u8);
u16 Enemy_GetHp_2_0013F750(void *p);
void Enemy_AddHp_2_0013F710(void *, s32);
void EnemyCmd_ClampHpFromFlag_1_00144420(u8 *o) {
    void *p = D_00201FA8->p;
    u16 a = GameFlag_GetHalf_0_0013D560(o[8], o[0x10]);
    u16 b = Enemy_GetHp_2_0013F750(p);
    if (a < b && a > 0) {
        Enemy_AddHp_2_0013F710(p, a - b);
    }
}
