#include "common.h"
extern s32 D_00201E20;
s32 PlayerData_Get_2_001C9BA0(void);
void PlayerData_Load_1_001C9BB0(s32 arg0);
void memcpy(s32, s32, s32);

/* PlayerData_Get_2_001C9BA0 */
s32 PlayerData_Get_2_001C9BA0(void) {
    return D_00201E20;
}

/* PlayerData_Load_1_001C9BB0 */
void PlayerData_Load_1_001C9BB0(s32 arg0) {
    memcpy(D_00201E20, arg0, 0x10A0);
    Player_RecalcStats_1_001CEDC0(3);
    Player_RefreshEquipModel_0_001CEA50(0);
}
