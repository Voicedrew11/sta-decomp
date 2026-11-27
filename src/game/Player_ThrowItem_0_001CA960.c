#include "m2c.h"
void Mtx_Lerp_2_0015EB20(f32, s8 *, s8 *, f32 *);
void Player_GetHandMatrix_1_001C0660(f32 *, s8 *, s32, s32);
void ItemObj_GetScale_0_001ADBA0(s8 *, f32 *);
void Mtx_Compose_2_00173FD0(f32 *, f32 *, f32 *, f32 *);
void ItemObj_Free_1_001AF4A0(s8 *);
extern s32 D_00201E94;
extern s8 *D_002022F0;
extern s32 D_002022F4;
extern s32 D_002022F8;
extern f32 D_004B5DB0[];
extern f32 D_004B5DC0[];

s32 Player_ThrowItem_0_001CA960(void) {
    f32 m[16];
    f32 v[4];
    u8 f;

    if (D_002022F0 == NULL) {
        return -1;
    }
    switch (D_002022F4) {
    case 1:
        f = M2C_FIELD(D_002022F0, u8 *, 0xA8);
        if (((u64)((s64)f << 0x3E) >> 0x3F) == 0 && (f & 1)) {
            D_002022F4++;
        }
        D_002022F8 = 0;
        break;
    case 2:
        Player_GetHandMatrix_1_001C0660(m, D_002022F0, 0, D_00201E94);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)D_002022F8 / 15.0f, D_002022F0, D_002022F0, m);
        if (D_002022F8 < 0xF) {
            D_002022F8++;
        } else {
            D_002022F8 = 0;
            D_002022F4++;
        }
        break;
    case 3:
        ItemObj_GetScale_0_001ADBA0(D_002022F0, v);
        Mtx_Compose_2_00173FD0(m, D_004B5DB0, D_004B5DC0, v);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)D_002022F8 / 15.0f, D_002022F0, D_002022F0, m);
        D_002022F8++;
        if (D_002022F8 >= 0xF) {
            ItemObj_Free_1_001AF4A0(D_002022F0);
            D_002022F0 = NULL;
            D_002022F4 = 0;
            D_002022F8 = 0;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
