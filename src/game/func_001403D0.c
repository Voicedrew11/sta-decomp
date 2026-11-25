#include "common.h"
f32 func_0011D778(f32);                             /* extern */
f32 func_0011DA18(f32);                             /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void func_001403D0(void *arg0, void *arg1) {
    f32 temp_f20;

    temp_f20 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void **, 0x198), f32 *, 0x24);
    M2C_FIELD(arg1, f32 *, 0) = (f32) -func_0011DA18(temp_f20);
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, f32 *, 8) = (f32) -func_0011D778(temp_f20);
}
