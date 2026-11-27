#include "common.h"
void Equip_SetSlot_0_001CCF00(s32, s32);            /* extern */
void memset(u8 *, s32, s32);           /* extern */
extern u8 *D_00201E20;

void PlayerData_InitNew_0_001C9EA0(void) {
    s32 var_3;
    s32 var_2;

    memset(D_00201E20, 0, 0x10A0);
    var_3 = 0;
    var_2 = 0;
    M2C_FIELD(D_00201E20, s16 *, 0x20) = 0xF;
    M2C_FIELD(D_00201E20, s16 *, 0x22) = 0xC;
    M2C_FIELD(D_00201E20, s16 *, 0x24) = 0xC;
    M2C_FIELD(D_00201E20, s16 *, 0x26) = 0xA;
    M2C_FIELD(D_00201E20, s16 *, 0x28) = 0xC;
    M2C_FIELD(D_00201E20, s16 *, 0x2A) = 8;
    M2C_FIELD(D_00201E20, s16 *, 0x2C) = 8;
    M2C_FIELD(D_00201E20, s16 *, 0x2E) = 8;
    M2C_FIELD(D_00201E20, s16 *, 4) = 0x270F;
    M2C_FIELD(D_00201E20, s16 *, 6) = 0x270F;
    do {
        var_3 += 5;
        M2C_FIELD((D_00201E20 + var_2), s16 *, 0x80) = -1;
        M2C_FIELD((D_00201E20 + var_2), s16 *, 0x82) = -1;
        M2C_FIELD((D_00201E20 + var_2), s16 *, 0x84) = -1;
        M2C_FIELD((D_00201E20 + var_2), s16 *, 0x86) = -1;
        M2C_FIELD((D_00201E20 + var_2), s16 *, 0x88) = -1;
        var_2 += 0xA;
    } while (var_3 < 0xA);
    Inventory_ChangeCount_1_001CBED0(0x14, 4, 0);
    Inventory_Give_0_001CBCD0(0x3B6);
    Equip_SetSlot_0_001CCF00(0, 0x3B6);
}
