#include "m2c.h"
s32 *func_00165130(s32, M2C_UNK);                   /* extern */
s16 *func_001C9BA0();                               /* extern */

void func_0017CC90(s32 arg0) {
    s16 *temp_s0;
    s32 *temp_v0;

    temp_s0 = func_001C9BA0();
    temp_v0 = func_00165130(arg0, 0);
    if (temp_s0 != NULL) {
        *temp_v0 = (s32) *temp_s0;
    }
}
