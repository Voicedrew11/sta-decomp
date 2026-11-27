#include "common.h"
extern s32 D_00202290;
extern s32 D_002022A0;

void ItemObj_SetPools_0_001AF970(s32 arg0, s32 arg1) {
    D_00202290 = arg0;
    D_002022A0 = arg1;
    ItemObj_ClearTables_1_001AFA20();
}
