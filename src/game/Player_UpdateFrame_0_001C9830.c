#include "m2c.h"
typedef struct { u8 pad[0xF]; s8 b; s16 h[5]; } S1E20;
typedef struct { u8 pad[0x10]; f32 x, y, z; } P;
extern S1E20 *D_00201E20;
extern s32 D_002022B8;
extern P **D_002022BC;
extern s8 *D_002022E4;

void Player_UpdateFrame_0_001C9830(void) {
    s8 *v;
    if (D_002022E4 == NULL) {
        v = NULL;
    } else if (M2C_FIELD(D_002022E4, s32 *, 0x518) == 0) {
        v = NULL;
    } else {
        v = (s8 *)(M2C_FIELD(D_002022E4, s32 *, 0x518) + 0x180);
    }
    if (v != NULL) {
        D_00201E20->b = D_002022B8;
        if (D_002022BC != NULL && *D_002022BC != NULL) {
            D_00201E20->h[0] = (s32)(M2C_FIELD(v, f32 *, 0x40) - (*D_002022BC)->x);
            D_00201E20->h[1] = (s32)(M2C_FIELD(v, f32 *, 0x44) - (*D_002022BC)->y);
            D_00201E20->h[2] = (s32)(M2C_FIELD(v, f32 *, 0x48) - (*D_002022BC)->z);
        } else {
            D_00201E20->h[0] = (s32)M2C_FIELD(v, f32 *, 0x40);
            D_00201E20->h[1] = (s32)M2C_FIELD(v, f32 *, 0x44);
            D_00201E20->h[2] = (s32)M2C_FIELD(v, f32 *, 0x48);
        }
        D_00201E20->h[3] = (s32)(4096.0f * M2C_FIELD(M2C_FIELD(v, s8 * *, 0x18), f32 *, 0x20));
        D_00201E20->h[4] = (s32)(4096.0f * M2C_FIELD(M2C_FIELD(v, s8 * *, 0x18), f32 *, 0x24));
    }
}
