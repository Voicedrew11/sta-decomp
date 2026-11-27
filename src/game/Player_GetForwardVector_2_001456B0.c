#include "common.h"
f32 cosf(f32);                             /* extern */
f32 sinf(f32);                             /* extern */
extern void *D_002022E4;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void Player_GetForwardVector_2_001456B0(void *arg0) {
    f32 temp_f20;

    temp_f20 = M2C_FIELD(M2C_FIELD(D_002022E4, void **, 0x518), f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0) = (f32) -sinf(temp_f20);
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, f32 *, 8) = (f32) -cosf(temp_f20);
}
