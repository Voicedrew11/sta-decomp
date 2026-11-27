#include "actor.h"
#include "obj3d.h"
typedef struct { u8 pad[0x94]; Flags8 f94; } R;
typedef struct {
    u8 pad[0x390];
    R *x390;
    u8 pad394[2];
    u8 x396;
    u8 pad397[0x39C - 0x397];
    u8 x39C;
    u8 pad39D[0x3C0 - 0x39D];
    Obj3D *x3C0;
    Obj3D *x3C4;
    Obj3D *x3C8;
    u8 pad3CC[0x3D5 - 0x3CC];
    u8 x3D5;
} S;
s32 Snd_BindMapSe_0_0012DA90(void);
s32 Equip_GetSlotItem_1_001CCD90(s32);
u8 Item_GetType_0_001CCDE0(s32);
s32 ItemType_IsWeapon_0_001D1D50(u8);
u8 *PlayerData_GetEquipEntry_0_001D1E10(void);

void Player_UpdateEquipSounds_0_001BF940(Actor *a0) {
    S *s = (S *)(a0->unk518 + 0x180);
    Obj3D *o;
    Obj3D *p;

    if (s->x390->f94.f.b0) {
        p = s->x3C0;
    } else {
        p = s->x3C4;
    }
    if (p != NULL) {
        p->xA8.f.b7 = 0;
        p->xA8.f.b2 = 1;
        p->xA9.f.b3 = 0;
    }
    if (s->x390->f94.f.b0) {
        o = s->x3C4;
    } else {
        o = s->x3C0;
    }
    if (o != NULL && o->xA8.f.b0) {
        if (s->x3D5 == 0) {
            o->xA8.f.b7 = 0;
        } else {
            o->xA8.f.b7 = 1;
        }
        o->xA8.f.b2 = 1;
        if (!o->xA9.f.b3 && !Snd_BindMapSe_0_0012DA90()) {
            o->xA9.f.b3 = 1;
        }
    }
    p = s->x3C8;
    if (p != NULL) {
        p->xA8.f.b7 = 1;
        p->xA8.f.b2 = 1;
        p->xA9.f.b0 = 1;
        p->xA9.f.b3 = 0;
    }
    s->x39C = Item_GetType_0_001CCDE0(Equip_GetSlotItem_1_001CCD90(s->x390->f94.f.b0));
    if (ItemType_IsWeapon_0_001D1D50(s->x39C)) {
        s->x396 = PlayerData_GetEquipEntry_0_001D1E10()[3];
    }
}
