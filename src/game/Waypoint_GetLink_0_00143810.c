#include "common.h"
#include "m2c.h"
u8 Waypoint_GetLink_0_00143810(s32 arg0, s32 arg1, s32 arg2);
s32 Waypoint_Get_0_00143840(s32 arg0, s32 arg1);

/* Waypoint_GetLink_0_00143810 */
u8 Waypoint_GetLink_0_00143810(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_2;
    s32 temp_3;

    temp_2 = arg1 & 0xFF;
    temp_3 = arg2 & 0xFF;
    if (temp_2 == temp_3) {
        return 0xFFU;
    }
    return M2C_FIELD((temp_3 + ((temp_2 << 8) + arg0)), u8 *, 0x10);
}

/* Waypoint_Get_0_00143840 */
s32 Waypoint_Get_0_00143840(s32 arg0, s32 arg1) {
    s32 var_v0;
    s8 *temp_v1;

    temp_v1 = (signed char *)(arg0 + ((arg1 & 0xFF) * 0x10));
    var_v0 = (int)(temp_v1 + 0x10010);
    if (M2C_FIELD(temp_v1, f32 *, 0x1001C) <= 0.0f) {
        var_v0 = 0;
    }
    return var_v0;
}
