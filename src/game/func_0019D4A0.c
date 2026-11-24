#include "m2c.h"
s32 func_001957E0(s32, s32);                        /* extern */
s32 func_001958A0();                                /* extern */
s32 func_00195840(s32, s32);                        /* extern */

s32 func_0019D4A0(s32 arg0) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_001958A0();
    if (arg0 == 0) {
        return 0;
    }
    if (arg0 == -1) {
        return 0;
    }
    if (temp_v0 != 0) {
        var_v0 = func_001957E0(temp_v0, arg0);
    } else {
        var_v0 = 0;
    }
    return var_v0;
}

s32 func_0019D510(s32 arg0) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_001958A0();
    if (arg0 == 0) {
        return 0;
    }
    if (arg0 == -1) {
        return 0;
    }
    if (temp_v0 != 0) {
        var_v0 = func_00195840(temp_v0, arg0);
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
