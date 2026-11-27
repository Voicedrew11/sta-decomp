#include "common.h"
void memcpy(s32, s32, s32);           /* extern */
extern s32 D_00201E20;

void PlayerData_Load_1_001C9BB0(s32 arg0) {
    memcpy(D_00201E20, arg0, 0x10A0);
    Player_RecalcStats_1_001CEDC0(3);
    Player_RefreshEquipModel_0_001CEA50(0);
}
