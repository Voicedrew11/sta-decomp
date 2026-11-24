#include "m2c.h"
M2C_UNK func_00102A60(s32, s32);                    /* extern */
extern s8 *D_002022E4;

void func_001C92C0(s32 arg0) {
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
        func_00102A60(var_v1 + 0x3F0, arg0);
    }
}
