#include "m2c.h"
s8 *func_00165130(s8 *, s32);                         /* extern */
s8 *func_001C9B60();                              /* extern */

void func_0017D0E0(s8 *arg0) {
    s8 *temp_s0;
    s8 *temp_v0;

    temp_s0 = func_00165130(arg0, 0);
    temp_v0 = func_001C9B60();
    if (temp_v0 != NULL) {
        *temp_s0 = (s8) ((u64) ((s64) M2C_FIELD(temp_v0, u8 *, 0x3A1) << 0x3A) >> 0x3F);
        return;
    }
    *temp_s0 = 0;
}
