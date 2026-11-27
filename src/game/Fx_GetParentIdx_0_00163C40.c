#include "common.h"
extern s32 D_00201FC0;

s32 Fx_GetParentIdx_0_00163C40(void *arg0) {
    u16 temp_4;

    temp_4 = M2C_FIELD(arg0, u16 *, 0xA0);
    if (temp_4 == 0xFFFF) {
        return 0;
    }
    return D_00201FC0 + (temp_4 * 0x120);
}
