#include "m2c.h"
extern u8 D_00222A54[];
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */

f32 func_001C2640(s8 *arg0) {
    f32 var_f20;
    s32 temp_v0;
    s32 temp_v0_2;
    s8 *temp_v1;
    s8 *p;

    temp_v1 = M2C_FIELD(arg0, s8 **, 0x518);
    p = temp_v1 + 0x180;
    var_f20 = 1.0f;
    if ((((u64) ((s64) M2C_FIELD(temp_v1, u8 *, 0x521) << 0x38) >> 0x3F) != 0) && (func_001CD450(0x10, NULL, 0, 1) == 0)) {
        var_f20 = 0.5f;
    }
    if ((M2C_FIELD(p, u8 *, 0x3BF) == 7) && !(var_f20 <= 0.5f)) {
        var_f20 = 0.5f;
    }
    if (!(D_00222A54[0] & 1)) {
        temp_v0 = func_001CDEC0();
        if (temp_v0 >= 2) {
            if (!(var_f20 <= 0.33333334f)) {
                var_f20 = 0.33333334f;
            }
        } else if ((temp_v0 == 1) && !(var_f20 <= 0.6666667f)) {
            var_f20 = 0.6666667f;
        }
    }
    temp_v0_2 = func_001CE200(3);
    if (temp_v0_2 >= 2) {
        if (!(var_f20 <= 0.33333334f)) {
            var_f20 = 0.33333334f;
        }
    } else if ((temp_v0_2 == 1) && !(var_f20 <= 0.6666667f)) {
        var_f20 = 0.6666667f;
    }
    return var_f20;
}
