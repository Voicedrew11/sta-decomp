#include "m2c.h"
#include "actor.h"
M2C_UNK sceVu0InterVector(f32, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK sceVu0CopyVector(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK Weather_Update_0_00157D50(f32);                         /* extern */
extern M2C_UNK D_002F1AA0[];
extern M2C_UNK D_002F1AB0[];
extern M2C_UNK D_002F1AC0[];
extern f32 D_002F1AD0[];
extern f32 D_002F1AD4[];
extern u8 D_002F2078[];
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14], gap at: 0x8. */

void ScreenFx_Update_1_00159970(f32 arg0) {
    f32 temp_f1;

    temp_f1 = D_002F1AD0[0] + arg0;
    D_002F1AD0[0] = temp_f1;
    if (!(temp_f1 <= D_002F1AD4[0])) {
        D_002F1AD4[0] = 0.0f;
    }
    if (D_002F1AD4[0] == 0.0f) {
        sceVu0CopyVector(D_002F1AA0, D_002F1AB0);
    } else {
        sceVu0InterVector(1.0f - (D_002F1AD0[0] / D_002F1AD4[0]), D_002F1AA0, D_002F1AC0, D_002F1AB0);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x39) >> 0x3F) != 0) {
        Weather_Update_0_00157D50(arg0);
    }
}
