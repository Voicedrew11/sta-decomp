#include "m2c.h"

void func_0015B6B0(s8 *arg0, s8 *arg1) {
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return;
    }
    M2C_FIELD(arg0, f32 *, 0) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (0.5f * (0.999999f - M2C_FIELD(arg1, f32 *, 8)));
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) (0.5f * (1.0f - M2C_FIELD(arg1, f32 *, 0xC)));
}
