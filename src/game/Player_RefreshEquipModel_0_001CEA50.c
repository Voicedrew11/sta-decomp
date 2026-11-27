#include "common.h"
void Player_RefreshEquipModel_0_001CEA50(s32 arg0) {
    s32 temp_2;

    temp_2 = Player_GetBodyState_1_001C9B60();
    if (temp_2 != 0) {
        Player_UpdateEquipModel_0_001CE7D0((void *) temp_2, arg0);
        Player_UpdateEquipModelA_1_001CE660((void *) temp_2, arg0);
    }
}
