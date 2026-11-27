#include "common.h"
typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u16 Enemy_GetMaxHp_2_0013F700(void *);
u16 Enemy_AddHp_2_0013F710(void *, s32);
void EnemyCmd_HealPercent_1_00144E40(u8 *o) {
    void *p;
    u8 pct;
    u16 hp;
    pct = o[8];
    p = D_00201FA8->p;
    hp = Enemy_GetMaxHp_2_0013F700(p);
    Enemy_AddHp_2_0013F710(p, -hp);
    if (pct > 100) pct = 100;
    Enemy_AddHp_2_0013F710(p, hp * pct / 100);
}
