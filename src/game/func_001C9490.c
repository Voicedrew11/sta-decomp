#include "m2c.h"
M2C_UNK func_00102A60(s8 *, s32);
extern s8 *D_002022E4;

void func_001C9490(s8 *arg0) {
    s32 temp_v1;
    s32 var_v1;

    if (D_002022E4 == NULL) {
        var_v1 = 0;
    } else {
        temp_v1 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_v1 == 0) {
            var_v1 = 0;
        } else {
            var_v1 = temp_v1 + 0x180;
        }
    }
    if (var_v1 != 0) {
        func_00102A60(arg0, var_v1 + 0x40);
    }
}
