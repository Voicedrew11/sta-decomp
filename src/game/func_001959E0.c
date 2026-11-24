#include "m2c.h"
extern s8 **D_0020216C;

s16 func_001959E0(s32 arg0) {
    s32 var_a2;
    s8 *temp_a1;
    s8 *var_v1;

    var_a2 = 0;
    temp_a1 = *D_0020216C;
    var_v1 = temp_a1;
loop_1:
    if (arg0 == M2C_FIELD(var_v1, s16 *, 2)) {
        return *(s16 *)(temp_a1 + (var_a2 * 4));
    }
    var_a2 += 1;
    var_v1 += 4;
    if (var_a2 >= 0x18) {
        return -1;
    }
    goto loop_1;
}
