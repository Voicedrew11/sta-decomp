#include "common.h"
void Script_SendEvent_2_00166F80(s32, s32, s32);       /* extern */

void MapObj_SendEvent_1_001B0A80(void *arg0, s32 arg1) {
    s32 *temp_6;

    if (arg0 != NULL) {
        temp_6 = M2C_FIELD(arg0, s32 **, 0xC);
        if ((temp_6 != NULL) && (M2C_FIELD(arg0, u8 *, 0x1D8) & 1)) {
            Script_SendEvent_2_00166F80(*temp_6, (arg1 != 0) ? 0x7FFE : 0x7FFD, 0);
        }
    }
}
