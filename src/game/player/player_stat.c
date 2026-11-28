#include "common.h"
extern void *D_00201DC0;

void Player_SetStatByte_0_001AA700(s8 arg0) {
    s32 temp_2;

    temp_2 = PlayerData_Get_2_001C9BA0();
    if (temp_2 != 0) {
        M2C_FIELD(temp_2, s8 *, 0xE) = arg0;
    }
    M2C_FIELD(D_00201DC0, s8 *, 0x2E) = arg0;
}
