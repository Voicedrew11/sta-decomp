#include "m2c.h"
M2C_UNK func_00180810(s32);                         /* extern */
extern s8 D_00486990[];

void func_0017F5C0(void) {
    M2C_UNK (*temp_v0)(s32);
    s32 var_s1;
    s8 *var_s0;

    var_s1 = 0;
    var_s0 = D_00486990;
    do {
        if (M2C_FIELD(var_s0, u8 *, 0x48) & 1) {
            temp_v0 = M2C_FIELD(var_s0, M2C_UNK (**)(s32), 0x34);
            if (temp_v0 != NULL) {
                temp_v0(var_s1);
            } else {
                func_00180810(var_s1);
            }
            func_0017F650(var_s0, var_s0 + 0x20);
        }
        var_s1 += 1;
        var_s0 += 0x4C;
    } while (var_s1 < 0x18);
}
