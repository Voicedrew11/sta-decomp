#include "m2c.h"
typedef struct { s16 x0; s16 x2; s16 x4; s16 x6; } S9BA0;
void Player_AddStatus_1_001C88E0(s32, s32, s32);
void Player_AddExp_0_001CEAA0(s32);
s32 Player_GetStat_2_001CD450(s32, u8 *, s32, s32);
S9BA0 *PlayerData_Get_2_001C9BA0(void);
extern u32 D_00201E94;

void Player_UpdateRegen_1_001CD6C0(void) {
    u8 c;
    S9BA0 *p;

    if (Player_GetStat_2_001CD450(8, &c, 0, 0) && c && D_00201E94 % c == 0) {
        Player_AddExp_0_001CEAA0(1);
    }
    if (Player_GetStat_2_001CD450(9, &c, 0, 0) && c && D_00201E94 % c == 0) {
        Player_AddExp_0_001CEAA0(-1);
    }
    if (Player_GetStat_2_001CD450(0xB, &c, 0, 0) && c && D_00201E94 % c == 0) {
        p = PlayerData_Get_2_001C9BA0();
        p->x6++;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (Player_GetStat_2_001CD450(0xC, &c, 0, 0) && c && D_00201E94 % c == 0) {
        p = PlayerData_Get_2_001C9BA0();
        p->x6--;
        if (p->x6 < 0) {
            p->x6 = 0;
        }
        if (p->x2 < p->x6) {
            p->x6 = p->x2;
        }
    }
    if (Player_GetStat_2_001CD450(1, NULL, 0, 1)) Player_AddStatus_1_001C88E0(0, 1, 0);
    if (Player_GetStat_2_001CD450(2, NULL, 0, 1)) Player_AddStatus_1_001C88E0(1, 1, 0);
    if (Player_GetStat_2_001CD450(3, NULL, 0, 1)) Player_AddStatus_1_001C88E0(2, 1, 0);
    if (Player_GetStat_2_001CD450(4, NULL, 0, 1)) Player_AddStatus_1_001C88E0(4, 1, 0);
    if (Player_GetStat_2_001CD450(5, NULL, 0, 1)) Player_AddStatus_1_001C88E0(3, 1, 0);
    if (Player_GetStat_2_001CD450(6, NULL, 0, 1)) Player_AddStatus_1_001C88E0(5, 1, 0);
}
