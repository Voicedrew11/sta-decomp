#include "m2c.h"
typedef struct { u8 pad[0x9C]; s16 id; u8 pad2[0xA]; u8 b0:1; u8 b1:1; } O;
void Mtx_Lerp_2_0015EB20(f32, O *, O *, void *);
void Inventory_Give_0_001CBCD0(s16);
void Player_GetHandMatrix_1_001C0660(void *, O *, s32, s32);
void ItemObj_Free_1_001AF4A0(O *);
extern s32 D_00201E94;
extern O *D_002022F0;
extern s32 D_002022F4;
extern s32 D_002022F8;
extern u16 D_00317238[];

s32 Player_DropItem_0_001CAC30(void) {
    u8 buf[0x40];
    if (D_002022F0 == NULL) return -1;
    switch (D_002022F4) {
    case 1:
        if (!D_002022F0->b1 && D_002022F0->b0) D_002022F4++;
        D_002022F8 = 0;
        break;
    case 2:
        if (D_002022F8 < 0xF) D_002022F8++;
        Player_GetHandMatrix_1_001C0660(buf, D_002022F0, 0, D_00201E94);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)D_002022F8 / 15.0f, D_002022F0, D_002022F0, buf);
        if (D_00317238[0] & 0x2000) {
            Inventory_Give_0_001CBCD0(D_002022F0->id);
            D_002022F8 = 0;
            D_002022F4++;
        }
        break;
    case 3:
        Player_GetHandMatrix_1_001C0660(buf, D_002022F0, 1, D_00201E94);
        Mtx_Lerp_2_0015EB20(1.0f - (f32)D_002022F8 / 15.0f, D_002022F0, D_002022F0, buf);
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
