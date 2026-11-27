#include "m2c.h"

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
