#include "m2c.h"
s32 func_001C9B60();                                /* extern */
M2C_UNK func_001CE660(s32, s32);                    /* static */
M2C_UNK func_001CE7D0(s32, s32);                    /* static */

void func_001CEA50(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_001C9B60();
    if (temp_v0 != 0) {
        func_001CE7D0(temp_v0, arg0);
        func_001CE660(temp_v0, arg0);
    }
}
