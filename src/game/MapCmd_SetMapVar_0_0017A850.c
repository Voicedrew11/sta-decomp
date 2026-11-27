#include "common.h"
void MapCmd_SetMapVar_0_0017A850(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_3 < 0xC9) {
        Map_SetVar_0_001B0B30(temp_3, M2C_FIELD(arg0, s16 *, 0x10));
    }
}
