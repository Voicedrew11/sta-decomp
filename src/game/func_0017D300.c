#include "m2c.h"
s32 *func_00165130(s32, M2C_UNK);                   /* extern */
s8 *func_001C9BA0();                              /* extern */

void func_0017D300(s32 arg0) {
    s32 *temp_v0;
    s8 *temp_s0;

    temp_s0 = func_001C9BA0();
    temp_v0 = func_00165130(arg0, 0);
    if (temp_s0 != NULL) {
        *temp_v0 = (s32) M2C_FIELD(temp_s0, s16 *, 4);
    }
}
