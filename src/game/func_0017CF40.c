#include "m2c.h"
extern s8 *D_002022E4;

void func_0017CF40(s8 *arg0) {
    s8 *temp_a2;

    temp_a2 = (signed char *)(M2C_FIELD(D_002022E4, s32 *, 0x518) + 0x180);
    if (temp_a2 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_a2, s8 **, 0x18), f32 *, 0x20) = (f32) ((3.1415927f * M2C_FIELD(arg0, f32 *, 8)) / 180.0f);
        M2C_FIELD(M2C_FIELD(temp_a2, s8 **, 0x18), f32 *, 0x24) = (f32) ((3.1415927f * M2C_FIELD(arg0, f32 *, 0x10)) / 180.0f);
        M2C_FIELD(M2C_FIELD(temp_a2, s8 **, 0x18), f32 *, 0x28) = (f32) ((3.1415927f * M2C_FIELD(arg0, f32 *, 0x18)) / 180.0f);
    }
}
