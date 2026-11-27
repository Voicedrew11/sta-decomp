#include "m2c.h"
void ItemObj_Free_1_001AF4A0(s8 *);
s8 *ItemObj_SpawnAt_0_001AE620(s32, s32, s32);
void Player_GetHandMatrix_1_001C0660(void *, s8 *, s32, s32);
void sceVu0CopyVector(void *, void *);
void ItemObj_GetMatrix_0_001ADC60(s8 *, s8 *);
void Inventory_ChangeCount_1_001CBED0(s32, s32, s32, s32);
extern s32 D_00201E94;
extern s32 D_002022BC;
extern s8 *D_002022F0;
extern s32 D_002022F4;
extern s32 D_002022F8;
extern s8 D_004B5DB0[];
extern s8 D_004B5DC0[];

s32 Player_HoldItem_0_001CAB20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp80[4];
    s32 sp50[12];

    if (D_002022F0 != NULL) {
        ItemObj_Free_1_001AF4A0(D_002022F0);
    }
    D_002022F0 = ItemObj_SpawnAt_0_001AE620(arg0, arg2, arg3);
    if (D_002022F0 != NULL) {
        Player_GetHandMatrix_1_001C0660(sp50, D_002022F0, 1, D_00201E94);
        sceVu0CopyVector(D_002022F0 + 0x40, sp80);
        ItemObj_GetMatrix_0_001ADC60(D_002022F0, D_002022F0);
        sceVu0CopyVector(D_004B5DB0, (void *) arg2);
        sceVu0CopyVector(D_004B5DC0, (void *) arg3);
        { s32 t = D_002022BC; M2C_FIELD(D_002022F0, s32 *, 0x8C) = t;
        D_002022F4 = 1;
        D_002022F8 = 0;
        Inventory_ChangeCount_1_001CBED0(arg0, -arg1, 0, t); }
        return 0;
    }
    D_002022F4 = 0;
    D_002022F8 = 0;
    return -1;
}
