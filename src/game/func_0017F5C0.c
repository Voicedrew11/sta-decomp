#include "common.h"
extern u8 D_00486990[];

void func_0017F5C0(void) {
    s32 (*temp_2)(s32);
    s32 var_17;
    u8 *var_16;

    var_17 = 0;
    var_16 = D_00486990;
    do {
        if (M2C_FIELD(var_16, u8 *, 0x48) & 1) {
            temp_2 = M2C_FIELD(var_16, s32 (**)(s32), 0x34);
            if (temp_2 != NULL) {
                temp_2(var_17);
            } else {
                func_00180810(var_17);
            }
            func_0017F650(var_16, var_16 + 0x20);
        }
        var_17 += 1;
        var_16 += 0x4C;
    } while (var_17 < 0x18);
}
