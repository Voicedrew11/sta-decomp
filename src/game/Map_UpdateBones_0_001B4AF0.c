#include "common.h"
typedef struct { s32 **obj; } P8;
typedef struct { u8 pad[0x178]; P8 *x178; } S;
extern s32 D_001F2170[];
void Mdl_UpdateBoneMatricesCur_0_00171540(s32 *, s32 *);
void MapObj_ResetBones_0_001BAAA0(S *);
void Map_UpdateBones_0_001B4AF0(S *a) {
    if (a == NULL || a->x178 == NULL) return;
    Mdl_UpdateBoneMatricesCur_0_00171540(*a->x178->obj, D_001F2170);
    MapObj_ResetBones_0_001BAAA0(a);
}
