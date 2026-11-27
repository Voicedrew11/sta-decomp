#include "actor.h"
#include "obj3d.h"
typedef struct { u8 pad[0x80]; s16 x80; s16 x82; u8 pad84[4]; s16 x88; u8 pad8A[0x94 - 0x8A]; Flags8 f94; } R;
typedef struct {
    u8 pad[0x390];
    R *x390;
    u8 pad394[0x3B8 - 0x394];
    s16 x3B8;
    s16 x3BA;
    s16 x3BC;
    u8 pad3BE[2];
    Obj3D *x3C0;
    Obj3D *x3C4;
    Obj3D *x3C8;
    s8 x3CC;
    s8 x3CD;
    s8 x3CE;
    s8 x3CF;
    u8 pad3D0[4];
    s8 x3D4;
    s8 x3D5;
    Flags8 f3D6;
} S;
void Player_SetArmMotion_1_001C7020(u16, f32, s32, f32, f32);
void Snd_StopStream3_0_0012DA80(void);
void ItemObj_Free_1_001AF4A0(Obj3D *);
Obj3D *ItemObj_Spawn_0_001AE7C0(s32);
s32 Item_GetType_0_001CCDE0(s32);
s32 ItemType_GetCategory_0_001D1CB0(s32);
static inline S *get(void) {
    S *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    return r;
}
static inline void reset(void) {
    S *p;
    s8 *base;
    if (D_002022E4 == NULL) {
        p = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        p = NULL;
    } else {
        p = (S *)(base + 0x180);
    }
    if (p != NULL) {
        Player_SetArmMotion_1_001C7020(0, 0.0f, 0, 0.0f, 1.0f);
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        p->x3D5 = 0;
        p->x3D4 = 0;
        p->f3D6.f.b5 = 0;
    }
}

s32 Player_UpdateHeldItem_0_001BFB70(Actor *a0) {
    S *s = (S *)(a0->unk518 + 0x180);
    s32 n;
    s16 m;

    n = s->x390->x80;
    if (n != s->x3B8 || s->x3C0 == NULL) {
        if (s->x3C0 != NULL) {
            if (!s->x390->f94.f.b0) Snd_StopStream3_0_0012DA80();
            ItemObj_Free_1_001AF4A0(s->x3C0);
            s->x3C0 = NULL;
        }
        if (n != -1) {
            s->x3C0 = ItemObj_Spawn_0_001AE7C0(n);
        } else {
            s->x3C0 = ItemObj_Spawn_0_001AE7C0(0x3FF);
        }
        s->x3B8 = n;
        if (!s->x390->f94.f.b0) reset();
    }
    n = s->x390->x82;
    if (ItemType_GetCategory_0_001D1CB0(Item_GetType_0_001CCDE0(s->x390->x80))) {
        if (s->x3C4 != NULL) {
            Snd_StopStream3_0_0012DA80();
            ItemObj_Free_1_001AF4A0(s->x3C4);
            s->x3C4 = NULL;
            if (s->x390->f94.f.b0) reset();
        }
        s->x3BA = n;
        s->x390->f94.f.b0 = 0;
    } else {
        m = n;
        if (m != s->x3BA || s->x3C4 == NULL) {
            if (s->x3C4 != NULL) {
                if (s->x390->f94.f.b0) Snd_StopStream3_0_0012DA80();
                ItemObj_Free_1_001AF4A0(s->x3C4);
                s->x3C4 = NULL;
            }
            if (m != -1) {
                s->x3C4 = ItemObj_Spawn_0_001AE7C0(n);
            } else {
                s->x3C4 = ItemObj_Spawn_0_001AE7C0(0x3FF);
            }
            s->x3BA = n;
            if (s->x390->f94.f.b0) reset();
        }
    }
    n = s->x390->x88;
    if (n != -1) {
        if (n != s->x3BC || s->x3C8 == NULL) {
            if (s->x3C8 != NULL) ItemObj_Free_1_001AF4A0(s->x3C8);
            s->x3C8 = ItemObj_Spawn_0_001AE7C0(n);
            reset();
        }
        s->x3BC = n;
    } else {
        if (s->x3C8 != NULL) {
            ItemObj_Free_1_001AF4A0(s->x3C8);
            s->x3C8 = NULL;
        }
        s->x3BC = -1;
    }
    return 0;
}
