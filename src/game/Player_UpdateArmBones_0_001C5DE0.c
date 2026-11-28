#include "actor.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
typedef struct {
    u8 pad[0x39C];
    u8 u39C;
    u8 pad2[4];
    Flags8 f3A1;
    u8 pad3[0x3D4 - 0x3A2];
    u8 u3D4;
    u8 u3D5;
    Flags8 f3D6;
    union { u8 b; struct { u8 b0:1; u8 b1:2; u8 r:5; } f; } f3D7;
} Obj;
extern f32 D_001F2170[];
void Player_UpdateArmBones_0_001C5DE0(Actor *a0);
void Player_UpdateAttackState_0_001C5FB0(void);
void sceVu0CopyMatrix(void *, void *);
void sceVu0MulMatrix(void *, void *, void *);
s8* Mdl_GetFrameData_0_001715B0(s8 **);
s32 Item_GetType_0_001CCDE0(s32);
void Player_StartAttackMotion_1_001C6590(s32);
s32 Game_GetBusy_0_0012C020(void);
void Equip_DamageAmmo_0_001CC5E0(void);

/* Player_UpdateArmBones_0_001C5DE0 */
void Player_UpdateArmBones_0_001C5DE0(Actor *a0) {
    s8 *p;
    s32 i;
    s8 *e;
    s8 **h;
    s8 *o;
    s32 off;
    s8 **l;
    s32 c;
    f32 v[16];

    p = a0->unk518 + 0x180;
    o = *(s8 **)(a0->unk518 + 0x540);
    if (o != NULL) {
        if (Item_GetType_0_001CCDE0(*(s16 *)(o + 0x9C)) == 9 || Item_GetType_0_001CCDE0(*(s16 *)(o + 0x9C)) == 0xC) {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x14C0);
        } else {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x2640);
        }
    }
    o = *(s8 **)(p + 0x3C4);
    if (o != NULL) {
        if (*(u8 *)(p + 0x39C) == 0xA || *(u8 *)(p + 0x39C) == 0xE) {
            sceVu0CopyMatrix(v, D_001F2170);
            v[0] = -1.0f;
            sceVu0MulMatrix(o, *(s8 **)(p + 0x2C) + 0x2640, v);
        } else {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x2640);
        }
    }
    o = *(s8 **)(p + 0x3C8);
    if (o != NULL) {
        l = *(s8 ***)(o + 0x84);
        if (l != NULL) {
            h = (s8 **)*l;
            e = Mdl_GetFrameData_0_001715B0(l);
            c = 0;
            i = 0;
            if (i < *(u16 *)(*(s8 **)*h + 0x14)) {
                off = 0;
                do {
                    sceVu0CopyMatrix(e + 0xC0, *(s8 **)(p + 0x2C) + off + 0xC0);
                    ((BF *)(e + 0x1F8))->b5 = c;
                    ((BF *)(e + 0x1F8))->b2 = c;
                    i++;
                    off += 0x140;
                    e += 0x140;
                } while (i < *(u16 *)(*(s8 **)*h + 0x14));
            }
            ((BF *)((s8 *)h + 0x25))->b0 = 1;
        }
    }
}

/* Player_UpdateAttackState_0_001C5FB0 */
static inline Obj *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return (Obj *)(D_002022E4->unk518 + 0x180);
}

void Player_UpdateAttackState_0_001C5FB0(void) {
    Obj *p = get();
    if (p == NULL) return;
    switch (p->u3D5) {
    case 0: break;
    case 1:
        if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) Player_StartAttackMotion_1_001C6590(8);
            else Player_StartAttackMotion_1_001C6590(7); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            Player_StartAttackMotion_1_001C6590(2);
        } else if (p->f3D7.f.b1) {
            Player_StartAttackMotion_1_001C6590(3);
        }
        break;
    case 2: break;
    case 3:
        if (Game_GetBusy_0_0012C020()) {
            Player_StartAttackMotion_1_001C6590(6);
        } else if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) Player_StartAttackMotion_1_001C6590(8);
            else Player_StartAttackMotion_1_001C6590(6); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            Player_StartAttackMotion_1_001C6590(6);
        }
        break;
    case 4:
        p->f3D6.f.b0 = 1;
        if (p->f3D7.f.b1) {
            Equip_DamageAmmo_0_001CC5E0();
            if (p->u39C == 0x12) {
                Player_StartAttackMotion_1_001C6590(0);
                p->u3D4 = 0;
            } else {
                Player_StartAttackMotion_1_001C6590(3);
            }
        }
        break;
    case 5:
        p->f3D6.f.b1 = 1;
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590(3);
        break;
    case 6:
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590(0);
        break;
    case 7:
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590(0);
        break;
    }
}
