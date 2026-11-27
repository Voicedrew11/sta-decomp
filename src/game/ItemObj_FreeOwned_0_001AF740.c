#include "common.h"
#include "obj3d.h"
void ItemObj_Free_1_001AF4A0(Obj3D *);
extern s32 *D_00201E80[2];
extern s16 D_004AC5A0[];
extern s16 D_004AC5A4[];

void ItemObj_FreeOwned_0_001AF740(s32 *a0) {
    s32 k;
    s32 i;
    Obj3D *o;
    k = -1;
    if (D_00201E80[2] == a0) k = 0;
    if (D_00201E80[3] == a0) k = 1;
    for (i = 0, o = D_004AE370[k]; i < 64; i++, o++) ItemObj_Free_1_001AF4A0(o);
    for (i = 0, o = D_004AC970[k]; i < 16; i++, o++) ItemObj_Free_1_001AF4A0(o);
    D_004AC5A0[k] = 0;
    D_004AC5A4[k] = 0;
}
