#include "common.h"
void sceVu0CopyVector(s32, s32);                 /* extern */
extern void *D_002022E4;

void func_001C92C0(s32 arg0) {
    s32 temp_3;
    s32 var_3;

    if (D_002022E4 == NULL) {
        var_3 = 0;
    } else {
        temp_3 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_3 == 0) {
            var_3 = 0;
        } else {
            var_3 = temp_3 + 0x180;
        }
    }
    if (var_3 != 0) {
        sceVu0CopyVector(var_3 + 0x3F0, arg0);
    }
}
