#include "m2c.h"
M2C_UNK func_001D7350();                            /* extern */
M2C_UNK func_001D7D90(u32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0015F540(u32);                         /* static */

void func_0015FC10(void) {
    u32 var_s0;

    func_001D7350();
    var_s0 = 0;
    do {
        func_001D7D90(var_s0, 0, 1);
        func_0015F540(var_s0);
        var_s0 += 1;
    } while (var_s0 < 2U);
}
