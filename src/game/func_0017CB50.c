#include "m2c.h"
s32 func_0015ED20();                                /* extern */
s32 *func_00165130(s8 *, s32);                        /* extern */

void func_0017CB50(s8 *arg0) {
    s32 *temp_s0;
    s32 var_v1;

    temp_s0 = func_00165130(arg0, 0);
    var_v1 = func_0015ED20();
    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }
    *temp_s0 = var_v1;
}
