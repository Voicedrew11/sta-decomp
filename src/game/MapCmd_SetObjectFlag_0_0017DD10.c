#include "common.h"
typedef struct { char pad[0x53]; unsigned char : 1; unsigned char f : 1; } BF_53_1_1;
void MapCmd_SetObjectFlag_0_0017DD10(u8 *arg0) {
    u8 *temp_6;
    u8 *temp_2;
    s32 temp_17;
    s32 temp_16_2;
    s32 temp_16;

    temp_16 = M2C_FIELD(arg0, s32 *, 8);
    temp_17 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_16_2 = MapObj_GetNodeIndex_0_001B7840(temp_16, M2C_FIELD(arg0, s32 *, 0x10));
    temp_2 = (u8 *) (MapObj_Find_1_001B19A0(temp_16));
    if (temp_2 != NULL) {
        temp_6 = (u8 *) (M2C_FIELD(temp_2, s32 *, 0x180) + (temp_16_2 << 7));
        if (temp_6 != NULL) {
            ((BF_53_1_1 *)temp_6)->f = temp_17;
        }
    }
}
