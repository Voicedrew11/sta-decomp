#include "m2c.h"
s8 *ItemObj_SpawnAt_0_001AE620(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK ItemObj_Free_1_001AF4A0(s8 *);                      /* extern */
extern s32 D_002022BC;
extern s8 *D_002022F0;
extern s32 D_002022F4;
extern s32 D_002022F8;

s32 Player_PlaceItem_0_001CADF0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if (D_002022F0 != NULL) {
        ItemObj_Free_1_001AF4A0(D_002022F0);
    }
    D_002022F0 = ItemObj_SpawnAt_0_001AE620(arg0, arg1, arg2);
    if (D_002022F0 != NULL) {
        M2C_FIELD(D_002022F0, s32 *, 0x8C) = (s32) D_002022BC;
        D_002022F4 = 1;
        D_002022F8 = 0;
        return 0;
    }
    D_002022F4 = 0;
    D_002022F8 = 0;
    return -1;
}
