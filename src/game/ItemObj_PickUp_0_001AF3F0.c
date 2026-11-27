#include "obj3d.h"
s32 MapState_GetField_0_001A9D50(u32, u16);
void MapState_SetField_0_001A9E10(s32, u16, u8);
void MapState_SetBit_0_001A9CA0(s32, s16);
void ItemObj_Free_1_001AF4A0(Obj3D *);
void ItemObj_SaveState_1_001AE510(void);
void ItemObj_PickUp_0_001AF3F0(Obj3D *o) {
    if (o->x9E == 0) {
        s32 *p = *o->x8C;
        if (o->xA9.f.b2) {
            MapState_SetField_0_001A9E10(*p, o->xAC, MapState_GetField_0_001A9D50(*p, o->xAC) | 2);
        } else {
            MapState_SetBit_0_001A9CA0(*p, o->xAC);
        }
    }
    ItemObj_Free_1_001AF4A0(o);
    if (o->x9E == 1) ItemObj_SaveState_1_001AE510();
}
