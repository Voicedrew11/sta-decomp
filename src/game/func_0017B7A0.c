#include "m2c.h"
s32 *func_00165130(s8 *, s32);                        /* extern */
extern s32 **D_002022BC;

void func_0017B7A0(s8 *arg0) {
    s32 *temp_v0;
    s32 var_a1;
    s32 var_v1;

    temp_v0 = func_00165130(arg0, 0);
    if (temp_v0 != NULL) {
        var_a1 = 0;
        if ((D_002022BC != NULL) && (*D_002022BC != NULL)) {
            var_a1 = 1;
        }
        var_v1 = 0;
        if (var_a1 != 0) {
            var_v1 = **D_002022BC;
        }
        *temp_v0 = var_v1;
    }
}
