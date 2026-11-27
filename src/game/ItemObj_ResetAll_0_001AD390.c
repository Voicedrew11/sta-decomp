#include "obj3d.h"

void ItemObj_ResetAll_0_001AD390(void) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        if (D_004AE370[0][i].x9C != -1 && (D_004AE370[0][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AE370[0][i].x84);
        }
        if (D_004AE370[1][i].x9C != -1 && (D_004AE370[1][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AE370[1][i].x84);
        }
    }
    for (i = 0; i < 0x10; i++) {
        if (D_004AC970[0][i].x9C != -1 && (D_004AC970[0][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AC970[0][i].x84);
        }
        if (D_004AC970[1][i].x9C != -1 && (D_004AC970[1][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AC970[1][i].x84);
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_004AC630[i].x9C != -1 && (D_004AC630[i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AC630[i].x84);
        }
    }
}
