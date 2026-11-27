#include "common.h"
typedef union { f32 f; struct { Flags8 b0; Flags8 b1; Flags8 b2; u8 b3; } s; } P;
typedef struct {
    Mtx m;
    Vec x40;
    Vec x50;
    Vec x60;
    Vec x70;
    P x80;
    s8 **x84;
    s32 x88;
    s8 **x8C;
    u8 pad90[0xC];
    s16 x9C;
    s16 x9E;
    u8 padA0[6];
    s8 xA6;
    s8 xA7;
    Flags8 xA8;
    Flags8 xA9;
    u16 xAA;
    s16 xAC;
    s16 xAE;
    s32 xB0;
    f32 xB4;
    s8 *xB8;
    s8 *xBC;
    s8 *xC0[2][2];
} O;
extern s8 D_0030D0E0[];
void Sfx_SetFlag_0_00167640(s8 *, s32);
void Sfx_SetOwnerFlag_0_0016B200(s8 *, s32);
s32 Player_IsCrouching_0_001C9A20(void);
void GsPkt_SetLayer_1_00154700(s32, s32);
s8 *Map_FindSfxEntry_0_001B7300(s8 *, s32);
void Light_CopyColor_0_0015B6B0(Vec *, s8 *);
void Fog_SetReg_0_0015B1C0(Vec *, s8 *);
void Fog_ApplyDefault_0_0015B270(void);
s8 *Mdl_GetFrameData_0_001715B0(s8 **);
s8 *Player_GetCameraData_0_001C9B40(void);
void memcpy(void *, void *, s32);
void Mtx_ScaleRotation_0_0015CC40(void *, f32);
void Mdl_DrawLit_0_0016B970(s8 *, void *, s32, s8 *, s32, s32, s32);
void Mdl_DrawLitWrap_0_0016B960(s8 *, void *, s32, s8 *, s32, s32);
void Mdl_DrawMeshes_1_0016C7E0(s32, s8 *, s8 *, P);
void Mdl_DrawMeshesB_1_0016CD80(s32, s8 *, s8 *, P);
void GsPkt_EndLayer_1_00155900(void);
void Map_UpdateTexAnim_0_001B40B0(s8 *);
s32 ItemObj_TestVisible_0_001ACD90(s8 **, s16);

void ItemObj_DrawAll_0_001AC820(O *o, s32 (*cb)(s8 **, P), s32 chk) {
    s32 i;
    Flags8 *f;
    s8 **pp;
    s8 *q;
    s8 **h;
    s32 id;
    s8 *r;
    s8 *v;
    Vec buf;
    u8 buf2[0xA0];
    P p;

    if (o->x9C != -1 && o->xA8.f.b0) {
    if (o->xB8 != NULL) Sfx_SetFlag_0_00167640(o->xB8, 0);
    if (o->xBC != NULL) Sfx_SetFlag_0_00167640(o->xBC, 0);
    for (i = 0; i < 4; i++) {
        if (o->xC0[i / 2][i % 2] != NULL) Sfx_SetFlag_0_00167640(o->xC0[i / 2][i % 2], 0);
    }
    if (o->xA8.f.b7 && !cb(o->x84, o->x80) && (chk == 0 || ItemObj_TestVisible_0_001ACD90(o->x8C, o->xAE))) {
    if (o->x8C != NULL && *o->x8C != NULL) Map_UpdateTexAnim_0_001B40B0(*o->x8C);
    p = o->x80;
    f = &p.s.b2;
    f->f.b4 = 0;
    if (o->xB4 < 1.0f) {
        p.s.b0.f.b4 = 1;
        f->f.b4 = 1;
    }
    if (o->xB8 != NULL) {
        Sfx_SetFlag_0_00167640(o->xB8, 1);
        if (o->xA8.f.b2) Sfx_SetOwnerFlag_0_0016B200(o->xB8, 1);
    }
    if (o->xBC != NULL && Player_IsCrouching_0_001C9A20()) {
        Sfx_SetFlag_0_00167640(o->xBC, 1);
        Sfx_SetOwnerFlag_0_0016B200(o->xBC, 1);
    }
    for (i = 0; i < 4; i++) {
        pp = &o->xC0[i / 2][i % 2];
        if (*pp != NULL) {
            Sfx_SetFlag_0_00167640(*pp, 1);
            if (o->xA8.f.b2) Sfx_SetOwnerFlag_0_0016B200(*pp, 1);
        }
    }
    if (o->xA8.f.b2) {
        GsPkt_SetLayer_1_00154700(5, 0);
        if (o->x9C / 100 == 3) f->f.b5 = 1;
    }
    q = NULL;
    if (o->xA7 != -1 && o->x8C != NULL) q = Map_FindSfxEntry_0_001B7300(*o->x8C, o->xA7);
    if (q != NULL) {
        Light_CopyColor_0_0015B6B0(&buf, q + 0x20);
        Fog_SetReg_0_0015B1C0(&buf, q + 0x10);
    } else {
        Fog_ApplyDefault_0_0015B270();
    }
    h = o->x84;
    id = ***(s32 ***)h;
    r = Mdl_GetFrameData_0_001715B0(h);
    if (o->xA8.f.b2 && o->x9C == 0x14A) {
        ((Flags8 *)(r + 0x5B8))->f.b3 = 1;
        ((Flags8 *)(r + 0x1738))->f.b3 = 1;
    }
    if (o->xA8.f.b2) {
        if (o->x8C != NULL && *o->x8C != NULL && o->xA6 != -1) {
            v = *(s8 **)(*o->x8C + 0x188) + o->xA6 * 0xA0;
        } else {
            v = Player_GetCameraData_0_001C9B40();
        }
    } else if (o->xA6 == -1 || o->x8C == NULL) {
        v = D_0030D0E0;
    } else {
        v = *(s8 **)(*o->x8C + 0x188) + o->xA6 * 0xA0;
    }
    if (o->xB4 < 1.0f) {
        memcpy(buf2, v, 0xA0);
        Mtx_ScaleRotation_0_0015CC40(buf2, o->xB4);
        Mdl_DrawLit_0_0016B970(r, buf2, id, r + 0x200, 0, 2, 1);
    } else {
        Mdl_DrawLitWrap_0_0016B960(r, v, id, r + 0x200, 0, 2);
    }
    if (o->x80.s.b1.f.b7) {
        Mdl_DrawMeshes_1_0016C7E0(id, *h, r, p);
    } else {
        Mdl_DrawMeshesB_1_0016CD80(id, *h, r, p);
    }
    if (o->xA8.f.b2) GsPkt_EndLayer_1_00155900();
    }
    }
}
