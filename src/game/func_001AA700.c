#include "m2c.h"
s8 *func_001C9BA0();                              /* extern */
extern s8 *D_00201DC0;

void func_001AA700(s8 arg0) {
    s8 *temp_v0;

    temp_v0 = func_001C9BA0();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8 *, 0xE) = arg0;
    }
    M2C_FIELD(D_00201DC0, s8 *, 0x2E) = arg0;
}
