#include "common.h"
f32 func_0011D778(f32);                             /* extern */
f32 func_0011DA18(f32);                             /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
void func_0015E500(void *arg0, void *arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;

    temp_f20 = 0.5f * fparg0;
    temp_f0 = func_0011DA18(temp_f20);
    M2C_FIELD(arg0, f32 *, 0) = (f32) (M2C_FIELD(arg1, f32 *, 0) * temp_f0);
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) * temp_f0);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (M2C_FIELD(arg1, f32 *, 8) * temp_f0);
    M2C_FIELD(arg0, f32 *, 0xC) = func_0011D778(temp_f20);
}
