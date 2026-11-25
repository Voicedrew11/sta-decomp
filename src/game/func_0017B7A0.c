#include "common.h"
s32 *func_00165130(s32 a, s32 b);
extern s32 **D_002022BC;

void func_0017B7A0(s32 a) {
    s32 *temp_2;
    s32 var_3;
    s32 var_5;

    temp_2 = func_00165130(a, 0);
    if (temp_2 != NULL) {
        var_5 = 0;
        if ((D_002022BC != NULL) && (*D_002022BC != NULL)) {
            var_5 = 1;
        }
        var_3 = 0;
        if (var_5 != 0) {
            var_3 = **D_002022BC;
        }
        *temp_2 = var_3;
    }
}
