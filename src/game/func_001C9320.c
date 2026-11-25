#include "common.h"
void sceVu0CopyVector(u8 *, s32);                /* extern */
extern u8 *D_002022E4;

void func_001C9320(u8 *arg0) {
    u8 *var_3;
    s32 temp_3;

    if (D_002022E4 == NULL) {
        var_3 = (u8 *) (NULL);
    } else {
        temp_3 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_3 == 0) {
            var_3 = (u8 *) (NULL);
        } else {
            var_3 = (u8 *) (temp_3 + 0x180);
        }
    }
    if (var_3 != NULL) {
        sceVu0CopyVector(arg0, M2C_FIELD(var_3, s32 *, 0x18) + 0x10);
    }
    M2C_FIELD(arg0, f32 *, 4) += 220.0f;
}
