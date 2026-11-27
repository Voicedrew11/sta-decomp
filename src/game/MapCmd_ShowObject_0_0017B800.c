#include "common.h"
typedef struct { char pad[0x50]; unsigned char : 3; unsigned char f : 1; } BF_50_3_1;
s32 MapObj_GetNodeIndex_0_001B7840(s32, s32);                        /* extern */

void MapCmd_ShowObject_0_0017B800(u8 *arg0) {
    s32 temp_18;
    s32 temp_17;
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_6;

    temp_18 = M2C_FIELD(arg0, s32 *, 8);
    temp_17 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_2 = MapObj_GetNodeIndex_0_001B7840(temp_18, M2C_FIELD(arg0, s32 *, 0x10));
    if (temp_2 >= 0) {
        temp_2_2 = (u8 *) (MapObj_Find_1_001B19A0(temp_18));
        if (temp_2_2 != NULL) {
            temp_6 = (u8 *) (M2C_FIELD(temp_2_2, s32 *, 0x180) + (temp_2 << 7));
            if ((temp_6 != NULL) && (temp_6 != NULL)) {
                ((BF_50_3_1 *)temp_6)->f = temp_17;
            }
        }
    }
}
