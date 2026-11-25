#include "m2c.h"
#include "actor.h"
extern s32 D_00202274;
extern s8 **D_004A4570[];

s8 **func_001A55E0(void) {
    s32 var_a1;
    u8 temp_v1;
    s8 ***var_a0;
    s8 **temp_v0;

    D_00202274 = 0;
    var_a1 = 0;
    var_a0 = D_004A4570;
loop_1:
    temp_v0 = *var_a0;
    if ((temp_v0 != NULL) && ((temp_v1 = M2C_FIELD(*temp_v0, u8 *, 0x5A0), ((temp_v1 & 1) != 0)) || (((u64) ((s64) temp_v1 << 0x3E) >> 0x3F) != 0))) {
        D_00202274 = var_a1 + 1;
        return (D_004A4570)[var_a1];
    }
    var_a1 += 1;
    var_a0 += 1;
    if (var_a1 >= 0x81) {
        return NULL;
    }
    goto loop_1;
}
