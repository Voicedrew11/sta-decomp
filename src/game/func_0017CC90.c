#include "common.h"
s32 *func_00165130(s32, s32);                   /* extern */
s16 *func_001C9BA0();                               /* extern */

void func_0017CC90(s32 arg0) {
    s16 *temp_16;
    s32 *temp_2;

    temp_16 = func_001C9BA0();
    temp_2 = func_00165130(arg0, 0);
    if (temp_16 != NULL) {
        *temp_2 = (s32) *temp_16;
    }
}
