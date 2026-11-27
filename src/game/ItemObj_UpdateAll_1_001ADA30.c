#include "obj3d.h"
void ItemObj_Animate_0_001AD4E0(Obj3D *, f32);
void ItemObj_Free_1_001AF4A0(Obj3D *);
void ItemObj_SaveState_1_001AE510(void);

void ItemObj_UpdateAll_1_001ADA30(f32 arg0) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        ItemObj_Animate_0_001AD4E0(&D_004AE370[0][i], arg0);
        ItemObj_Animate_0_001AD4E0(&D_004AE370[1][i], arg0);
    }
    for (i = 0; i < 0x10; i++) {
        ItemObj_Animate_0_001AD4E0(&D_004AC970[0][i], arg0);
        ItemObj_Animate_0_001AD4E0(&D_004AC970[1][i], arg0);
    }
    for (i = 0; i < 4; i++) {
        ItemObj_Animate_0_001AD4E0(&D_004AC630[i], arg0);
    }
    for (i = 0; i < 0x10; i++) {
        if (D_004AC970[0][i].x9C != -1 && !(D_004AC970[0][i].x40.y < 29000.0f)) {
            ItemObj_Free_1_001AF4A0(&D_004AC970[0][i]);
            ItemObj_SaveState_1_001AE510();
        }
        if (D_004AC970[1][i].x9C != -1 && !(D_004AC970[1][i].x40.y < 29000.0f)) {
            ItemObj_Free_1_001AF4A0(&D_004AC970[1][i]);
            ItemObj_SaveState_1_001AE510();
        }
    }
    ItemObj_SaveState_1_001AE510();
}
