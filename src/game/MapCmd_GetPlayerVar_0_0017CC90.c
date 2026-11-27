#include "common.h"
s32 *Script_GetArgPtr_2_00165130(s32, s32);                   /* extern */
s16 *PlayerData_Get_2_001C9BA0();                               /* extern */

void MapCmd_GetPlayerVar_0_0017CC90(s32 arg0) {
    s16 *temp_16;
    s32 *temp_2;

    temp_16 = PlayerData_Get_2_001C9BA0();
    temp_2 = Script_GetArgPtr_2_00165130(arg0, 0);
    if (temp_16 != NULL) {
        *temp_2 = (s32) *temp_16;
    }
}
