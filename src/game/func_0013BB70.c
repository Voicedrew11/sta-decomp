#include "m2c.h"
M2C_UNK func_00171610(s32);                         /* extern */
s8 *func_001A5460(s32 *);                         /* extern */

void func_0013BB70(void) {
    s32 sp1C;
    s8 *var_v0;

    sp1C = 0;
    var_v0 = func_001A5460(&sp1C);
    if (var_v0 != NULL) {
        do {
            func_00171610(M2C_FIELD(M2C_FIELD(var_v0, s8 **, 0x518), s32 *, 0x1A4));
            var_v0 = func_001A5460(&sp1C);
        } while (var_v0 != NULL);
    }
}
