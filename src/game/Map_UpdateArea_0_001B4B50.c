#include "common.h"
void Script_RunAll_1_00166CC0(s32);
void Mdl_UpdateBoneMatricesCur_0_00171540(s32, s32 *);
void Map_UpdateSfxVisibility_0_001B41C0(u8 *);
void Map_UpdateEnemySpawns_0_001B43A0(u8 *);
void MapObj_UpdateAll_0_001BAB70(u8 *, f32);
extern s32 D_001F2170[];
void Map_UpdateArea_0_001B4B50(u8 *arg0, f32 f) {
    s32 *t;
    Mdl_UpdateBoneMatricesCur_0_00171540(***(s32 ***)(arg0 + 0x178), D_001F2170);
    MapObj_UpdateAll_0_001BAB70(arg0, f);
    Map_UpdateEnemySpawns_0_001B43A0(arg0);
    Map_UpdateSfxVisibility_0_001B41C0(arg0);
    t = *(s32 **)(arg0 + 0xC);
    if (t != NULL) Script_RunAll_1_00166CC0(*t);
}
