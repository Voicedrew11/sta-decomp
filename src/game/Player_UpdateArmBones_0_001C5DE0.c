#include "actor.h"
#include "m2c.h"
#include "common.h"
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
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { u8 b0:1; u8 f1:2; u8 r:5; } B7;
typedef struct {
    u8 pad[0x3A1]; B8 m3A1; u8 pad2[0x3D5 - 0x3A2]; u8 m3D5; B8 m3D6; B7 m3D7;
} S_Player_UpdateMagicState_0_001C6250;
typedef struct {
    u8 p[0x3CD]; s8 x3CD; s8 x3CE; u8 p3CF[6]; u8 x3D5;
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:2; u8 c3:5;
} S_Player_UpdateSwitchState_0_001C6470;
typedef struct { u8 pad[0x16]; u16 n; } H;
typedef struct { u16 lo:5; u16 mid:5; u16 rest:6; } B_Player_UpdateArmBones_0_001C5DE0__;
typedef struct { u8 a; u8 b; B_Player_UpdateArmBones_0_001C5DE0__ q; } E;
typedef struct { u8 pad[0xC]; f32 c; f32 x10; u8 pad14[0xC]; f32 x20; } R;
typedef struct {
    u8 pad0[0xC];
    H **h;
    u8 pad10[8];
    s8 *x18;
    u8 pad1C[4];
    E *tbl;
    u8 pad24[4];
    R *r;
    u8 pad2C[0x3AA];
    Flags8 f3D6;
    Flags8 f3D7;
} S_Player_StartSwitchMotion_1_001C6D40;
typedef union {
    u8 b;
    struct { u8 b0:1; u8 b1:2; u8 b3:5; } f;
} F3;
typedef struct { u8 pad[0x3E0]; u16 ids[8]; } S_Player_IsHitTarget_0_001C7320;
typedef struct { u8 pad[0x2C]; u8 lo:3; u8 mid:3; u8 hi:2; } T_Player_UpdateArmBones_0_001C5DE0__;
typedef struct { u8 pad[2]; u16 x2; u8 pad4[0x4B0]; T_Player_UpdateArmBones_0_001C5DE0__ *tbl[1]; } A_Player_OnHitEnemy_0_001C73C0;
typedef struct { u8 pad[0x390]; s16 *r; u8 pad394[8]; u8 x39C; u8 pad39D[0x3CD - 0x39D]; s8 x3CD; u8 pad3CE[0x3E0 - 0x3CE]; u16 ids[8]; } S_Player_OnHitEnemy_0_001C73C0;
typedef struct {
    u8 p[0x3CD]; s8 x3CD; s8 x3CE; u8 p3CF[6]; u8 x3D5;
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:2; u8 c3:5;
} S_Player_OnHitObject_0_001C7730;
typedef struct { u8 p[0x30]; s32 x30; s32 x34; } A_Player_OnHitObject_0_001C7730;
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { Q a; Q b; } Ray;
typedef struct { s32 w[16]; } Res;
typedef struct { u8 pad[0x94]; u8 x94; } S390;
typedef struct { u8 pad1C[0x390]; S390 *x390; u8 pad394[0x3CD - 0x394]; s8 x3CD; } P;
typedef struct { u8 b0:4; u8 f:3; u8 b7:1; } F30;
typedef struct { u16 h[6]; u8 padC[4]; u8 y[0x20]; F30 f30; u8 pad31[0xF]; } X_Player_UpdateArmBones_0_001C5DE0__;
typedef union { u128 q[2]; f32 f[8]; } M;
typedef struct { u8 pad[0x30]; f32 x30; } O18;
typedef struct { u8 pad[0x18]; O18 *x18; } S;
typedef struct { u8 pad[8]; u16 x8; u8 pada[6]; u8 x10[0x20]; u8 lo:4; u8 hi:4; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } X_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x390]; s16 *r; u8 pad394[0x462 - 0x394]; u16 st[7]; } S_Player_TakeHit_1_001C7DC0;
typedef struct { s16 p0; s16 a[3]; s16 p8; s16 b[3]; } Buf;
typedef struct { s16 x0; s16 x2; s16 x4; } R_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x390]; R_Player_TakeHit_1_001C7DC0_ *x390; u8 pad394[0x462 - 0x394]; u16 x462, x464, x466, x468, x46A, x46C, x46E; } S_Player_TakeHitB_1_001C8070;
typedef struct { u8 pad[0xC]; u8 v:3; } T_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x4B0]; T_Player_TakeHit_1_001C7DC0_ *x4B0; } A;
typedef struct { u8 pad[8]; u16 x8; u8 padA[6]; u32 x10[8]; u8 p30:4; u8 pad30:4; u8 a:2; u8 v:1; } B_Player_TakeHit_1_001C7DC0_;
typedef struct {
    u8 pad[0x390];
    R_Player_TakeHit_1_001C7DC0_ *x390;
    u8 pad394[0x39E - 0x394];
    union { struct { u16 a:6; u16 b:6; u16 c:4; } h; struct { u8 lo; u8 b0:4; u8 b4:1; } c; } x39E;
    u8 pad3A0;
    u8 b0:6; u8 b6:1; u8 b7:1;
    u8 pad3A2[0x3BE - 0x3A2];
    u8 x3BE;
    u8 pad3BF[0x410 - 0x3BF];
    s32 x410;
    u8 pad414[0x430 - 0x414];
    f32 x430, x434, x438, x43C, x440, x444;
} S_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x30]; u32 a[8]; u32 b[6]; } R_Player_RollStatusEffect_1_001C8570;
typedef struct { u8 pad[0x390]; R_Player_RollStatusEffect_1_001C8570 *r; u8 pad2[0x46C - 0x394]; u16 x; u16 y; u8 pad3[0x4A0 - 0x470]; u32 c[6]; } S_Player_RollStatusEffect_1_001C8570;
typedef struct { u8 pad[0x30]; u32 x30[8]; s32 x50[8]; } G;
extern f32 D_001F2170[];
extern s8 *D_002022E4__as_Player_UpdateSwitchState_0_001C6470;
extern u8 D_003139A0[];
extern s32 D_00201E80;
extern s8 *D_002022E4__as_Player_OnHitEnemy_0_001C73C0;
extern u32 D_001F3880[][8];
extern u8 D_00222A53[];
extern G *D_00201E20;
extern u32 D_001F3860[][8];
extern Flags8 D_00222A53__as_Player_AddStatus_1_001C88E0[];
void Player_UpdateArmBones_0_001C5DE0(Actor *a0);
void Player_UpdateAttackState_0_001C5FB0(void);
inline s8* get_Player_UpdateMagicState_0_001C6250(void);
void Player_UpdateMagicState_0_001C6250(void);
void Player_UpdateSwitchState_0_001C6470(void);
inline s8* get_Player_StartAttackMotion_1_001C6590(void);
void Player_StartAttackMotion_1_001C6590(u8 a0);
inline s8* get_Player_StartMagicMotion_0_001C69A0(void);
void Player_StartMagicMotion_0_001C69A0(u8 a0);
inline s8* get_Player_UpdateArmBones_0_001C5DE0_(void);
void Player_StartSwitchMotion_1_001C6D40(u8 a0);
void Player_SetArmMotion_1_001C7020(u16 idx, f32 t, s32 flags, f32 b, f32 c);
s32 Player_IsHitTarget_0_001C7320(u16 *a0);
void Player_Nop_2_001C73B0(void);
void Player_OnHitEnemy_0_001C73C0(A_Player_OnHitEnemy_0_001C73C0 *a0, u32 a1, u8 a2, s32 a3);
void Player_OnHitObject_0_001C7730(A_Player_OnHitObject_0_001C7730 *a, s32 b);
s32 Player_TraceAttack_0_001C7850(s8 *a0, s32 a1);
void Player_InitAttack_0_001C79B0(X_Player_UpdateArmBones_0_001C5DE0__ *x);
inline s8* get_Player_UpdateArmBones_0_001C5DE0__(void);
s32 Player_GetWeaponSegment_0_001C7A70(M *out);
f32 Player_ClampPitch_0_001C7CA0(f32 a);
s32 Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *a0);
s32 Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *a0, A *a1);
s32 Player_ApplyDamage_2_001C8320(s32 n, s32 a1, s32 a2, s32 a3);
s32 Player_RollStatusEffect_1_001C8570(u32 *arg0);
void Player_AddStatus_1_001C88E0(s32 a, u32 b);
void sceVu0CopyMatrix(void *, void *);
void sceVu0MulMatrix(void *, void *, void *);
s8* Mdl_GetFrameData_0_001715B0(s8 **);
s32 Item_GetType_0_001CCDE0(s32);
s32 Game_GetBusy_0_0012C020(void);
void Equip_DamageAmmo_0_001CC5E0(void);
void ItemObj_SetRotation_0_001AD0C0(s32, s32);
void ItemObj_SetAnim_0_001AD1C0(s32, s32);
void Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(s32);
s32 Equip_GetSlotItem_1_001CCD90(s32);
s32 Item_GetMotionId_0_001CC390(s16);
void Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(s32);
void Mdl_SetBoneRotation_0_001710D0(R *, s16, f32, f32, f32);
void sceVu0CopyVector(void *, void *);
f32 Mdl_GetMotionLength_0_00173F70(H *, u16);
void Player_SetArmMotion_1_001C7020__as_Player_StartSwitchMotion_1_001C6D40(f32, u16, s32, f32, f32);
void Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(u16);
void Player_SetArmMotion_1_001C7020__as_Player_UpdateArmBones_0_001C5DE0__(f32, f32, u16, s32, f32);
s32 Player_GetStat_2_001CD450(s32, void *, s32, s32);
s32 ItemType_IsWeapon_0_001D1D50(u8);
s32 Enemy_IsDead_1_0013EEE0(A_Player_OnHitEnemy_0_001C73C0 *);
u32 Enemy_GetMaxHp_2_0013F700(A_Player_OnHitEnemy_0_001C73C0 *);
void Equip_DamageOnHit_0_001CC6F0(s32, s32);
void Player_PlayHitEnemySe_0_001CA7B0(s8, s32);
s32 MapObj_Hit_0_001B85B0(s32, A_Player_OnHitObject_0_001C7730 *);
u8 MapObj_IsSame_0_001B8F30(s32, s32);
void Player_PlayHitObjectSe_0_001CA700(s32, s32);
void Coll_ClosestPointB_0_00150160(Ray *, s8 *, s8 *);
s32 MapColl_RayCast_0_001B23E0(s8 *, Res *, Ray *, u16, s32, s32);
s32 MapColl_RayCastAll_0_001B2F30(s32, Res *, Ray *, s32, s32);
void Player_OnHitObject_0_001C7730__as_Player_TraceAttack_0_001C7850(Res *, s32);
void memset(void *, s32, s32);
void Player_CalcAttack_1_001CEBF0(X_Player_UpdateArmBones_0_001C5DE0__ *, u8 *, s8);
s32 Equip_CheckAmmo_0_001CC250(s32);
void Seg_Init_1_001502A0(f32, M *, f32 *, f32 *);
f32 fabsf(f32);
void sceVu0CopyVector__as_Player_UpdateArmBones_0_001C5DE0___(s8 *, void *);
void sceVu0CopyVector__as_Player_GetWeaponSegment_0_001C7A70(f32 *, s8 *);
s32 Combat_SumResist_0_001AB500(void *, void *);
void Equip_DamageArmor_0_001CC830(s32, u32, s32, s32);
s32 Combat_SumResist_0_001AB500__as_Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *, Buf *);
s32 Combat_SumResist_0_001AB500__as_Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *, u16 *);
void Equip_DamageArmor_0_001CC830__as_Player_TakeHitB_1_001C8070(s32, u16, s32, s32);
void Player_RollStatusEffect_1_001C8570__as_Player_TakeHitB_1_001C8070(u32 *);
void Player_AddExp_0_001CEAA0(s32);
void Vibe_StartB_0_0015FE20(f32, f32, f32, f32, f32);
void Vibe_StartA_0_0015FD90(f32, f32, f32, f32, f32);
void Player_PlayHurtSe_0_001CA2B0(s32);
void Player_ApplyDamage_2_001C8320__as_Player_TakeHit_1_001C7DC0_(s32, s32, s32, s32);
u16 Rand_Next_3_0015ED20(u32);
s32 Equip_FindSlot_0_001CD2D0(s32);
s32 Player_GetStat_2_001CD450__as_Player_AddStatus_1_001C88E0(s32, s32, s32, s32);
void Player_RollStatusEffect_1_001C8570__as_Player_TakeHit_1_001C7DC0__(void *);

/* Player_UpdateArmBones_0_001C5DE0____ */
#define Player_ApplyDamage_2_001C8320 Player_ApplyDamage_2_001C8320__as_Player_UpdateArmBones_0_001C5DE0____
void Player_ApplyDamage_2_001C8320__as_Player_UpdateArmBones_0_001C5DE0____(s32, s32, s32, s32);

/* Player_UpdateArmBones_0_001C5DE0___ */

/* Player_UpdateArmBones_0_001C5DE0___ */
/* Player_UpdateArmBones_0_001C5DE0__ */

/* Player_UpdateArmBones_0_001C5DE0_ */

/* Player_UpdateArmBones_0_001C5DE0 */

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
static inline Obj *get_Player_UpdateArmBones_0_001C5DE0(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return (Obj *)(D_002022E4->unk518 + 0x180);
}

void Player_UpdateAttackState_0_001C5FB0(void) {
    Obj *p = get_Player_UpdateArmBones_0_001C5DE0();
    if (p == NULL) return;
    switch (p->u3D5) {
    case 0: break;
    case 1:
        if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(8);
            else Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(7); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(2);
        } else if (p->f3D7.f.b1) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(3);
        }
        break;
    case 2: break;
    case 3:
        if (Game_GetBusy_0_0012C020()) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(6);
        } else if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(8);
            else Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(6); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(6);
        }
        break;
    case 4:
        p->f3D6.f.b0 = 1;
        if (p->f3D7.f.b1) {
            Equip_DamageAmmo_0_001CC5E0();
            if (p->u39C == 0x12) {
                Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(0);
                p->u3D4 = 0;
            } else {
                Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(3);
            }
        }
        break;
    case 5:
        p->f3D6.f.b1 = 1;
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(3);
        break;
    case 6:
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(0);
        break;
    case 7:
        if (p->f3D7.f.b1) Player_StartAttackMotion_1_001C6590__as_Player_UpdateArmBones_0_001C5DE0(0);
        break;
    }
}

/* Player_UpdateMagicState_0_001C6250 */
/* Player_UpdateMagicState_0_001C6250 */
inline s8 *get_Player_UpdateMagicState_0_001C6250(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

void Player_UpdateMagicState_0_001C6250(void) {
    S_Player_UpdateMagicState_0_001C6250 *s = (S_Player_UpdateMagicState_0_001C6250 *)get_Player_UpdateMagicState_0_001C6250();
    if (s != NULL) {
        switch (s->m3D5) {
        case 0: break;
        case 1:
            if (s->m3A1.b6) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(2);
            } else if (s->m3D6.b3) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(2);
            } else if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(3);
            }
            break;
        case 2:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        case 3:
            if (Game_GetBusy_0_0012C020()) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(5);
            } else if (s->m3A1.b6) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(5);
            } else if (s->m3D6.b3) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(5);
            }
            break;
        case 4:
            s->m3D6.b0 = 1;
            if (s->m3D7.f1) {
                Equip_DamageAmmo_0_001CC5E0();
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        case 5: break;
        case 6:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        case 7:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0__as_Player_UpdateArmBones_0_001C5DE0_(0);
            }
            break;
        }
    }
}

/* Player_UpdateSwitchState_0_001C6470 */

void Player_UpdateSwitchState_0_001C6470(void) {
    s32 t;
    S_Player_UpdateSwitchState_0_001C6470 *s;
    if (D_002022E4__as_Player_UpdateSwitchState_0_001C6470 == NULL) {
        s = NULL;
    } else {
        t = M2C_FIELD(D_002022E4__as_Player_UpdateSwitchState_0_001C6470, s32 *, 0x518);
        if (t == 0) {
            s = NULL;
        } else {
            s = (S_Player_UpdateSwitchState_0_001C6470 *)(t + 0x180);
        }
    }
    if (s != NULL) {
        switch (s->x3D5) {
        case 4:
            if (s->b5) {
                Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(5);
                s->b5 = 0;
                return;
            }
            s->x3CE = s->x3CD;
            s->b0 = 1;
            if (s->c1) {
                Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(0);
            }
            break;
        case 8:
            if (s->c1) {
                Player_StartSwitchMotion_1_001C6D40__as_Player_UpdateArmBones_0_001C5DE0__(0);
            }
            break;
        }
    }
}

/* Player_StartAttackMotion_1_001C6590 */
inline s8 *get_Player_StartAttackMotion_1_001C6590(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}
#define SEL(p) ((*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) ? *(s32 *)(p + 0x3C4) : *(s32 *)(p + 0x3C0))

void Player_StartAttackMotion_1_001C6590(u8 a0) {
    s8 *p;
    u16 base;
    s32 k;
    f32 g;
    f32 f;
    f32 s;
    s8 *q; Flags8 *fl;

    p = get_Player_StartAttackMotion_1_001C6590();
    k = 0;
    g = 0.0f;
    f = g;
    s = 1.0f;
    if (p != NULL) {
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            *(s8 *)(p + 0x3D4) = 0;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 1;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 2);
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            *(s8 *)(p + 0x3D4) = 0;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 3;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 1);
            break;
        case 5:
            *(s8 *)(p + 0x3CF) = 4;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 5;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                if (*(u8 *)(p + 0x39C) == 10) {
                    ItemObj_SetAnim_0_001AD1C0(*(s32 *)(p + 0x3C4), 5);
                } else {
                    ItemObj_SetAnim_0_001AD1C0(*(s32 *)(p + 0x3C4), 4);
                }
            } else {
                ItemObj_SetAnim_0_001AD1C0(*(s32 *)(p + 0x3C0), 4);
            }
            break;
        case 6:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 6;
            *(s8 *)(p + 0x3D4) = 0;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 3);
            break;
        case 7:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            *(s8 *)(p + 0x3D4) = 0;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 8:
            *(s8 *)(p + 0x3CF) = 0;
            f = -1.0f;
            *(s8 *)(p + 0x3CD) = 0;
            *(s8 *)(p + 0x3D5) = 0;
            *(s8 *)(p + 0x3D4) = 0;
            base = 0;
            g = 30.0f;
            s = 2.0f;
            q = *(s8 **)(p + 0x3C0);
            if (q != NULL) { Flags8 *fl = (Flags8 *)(q + 0xA8); if (!fl->f.b5) fl->f.b5 = 1; }
            break;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        Player_SetArmMotion_1_001C7020__as_Player_UpdateArmBones_0_001C5DE0__(f, g, base, k, s);
    }
}

/* Player_StartMagicMotion_0_001C69A0 */
inline s8 *get_Player_StartMagicMotion_0_001C69A0(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}
#define SEL(p) ((*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) ? *(s32 *)(p + 0x3C4) : *(s32 *)(p + 0x3C0))

void Player_StartMagicMotion_0_001C69A0(u8 a0) {
    s8 *p;
    f32 g;
    f32 f;
    f32 s;
    s32 i;
    s32 n;
    u16 base;
    f32 c = 0.01f;
    s32 k;

    p = get_Player_StartMagicMotion_0_001C69A0();
    k = 0;
    f = g = 0.0f;
    s = 1.0f;
    if (p != NULL) {
        i = (s16)Equip_GetSlotItem_1_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1);
        if (i != -1) {
            n = Item_GetMotionId_0_001CC390(i);
        } else {
            n = 0;
        }
        if (n > 3) {
            n += 25;
        }
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 1;
            s -= n * c;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 2);
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 2;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 3);
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 3;
            k = 2;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 1);
            break;
        case 5:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 6;
            ItemObj_SetAnim_0_001AD1C0(SEL(p), 3);
            break;
        case 6:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            g = 5.0f;
            k = 1;
            ItemObj_SetRotation_0_001AD0C0(SEL(p), 0);
            break;
        }
        if (s < 0.25f) {
            s = 0.25f;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        Player_SetArmMotion_1_001C7020__as_Player_UpdateArmBones_0_001C5DE0__(f, g, base, k, s);
    }
}

/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40 */
inline s8 *get_Player_UpdateArmBones_0_001C5DE0_(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

void Player_StartSwitchMotion_1_001C6D40(u8 a0) {
    s8 *p;
    s32 k;
    f32 f;
    f32 s;
    s32 i;
    s32 n;
    f32 c = 0.01f;
    u16 base;

    p = get_Player_UpdateArmBones_0_001C5DE0_();
    k = 0;
    f = 0.0f;
    s = 1.0f;
    if (p != NULL) {
        i = (s16)Equip_GetSlotItem_1_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1);
        if (i != -1) {
            n = Item_GetMotionId_0_001CC390(i);
        } else {
            n = 0;
        }
        if (n > 3) {
            n += 25;
        }
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            k = 2;
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 2;
            } else {
                *(s8 *)(p + 0x3CD) = 4;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 1;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 4;
            } else {
                *(s8 *)(p + 0x3CD) = 2;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 5:
            *(s8 *)(p + 0x3D5) = 8;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            break;
        }
        if (s < 0.25f) {
            s = 0.25f;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        Player_SetArmMotion_1_001C7020__as_Player_StartSwitchMotion_1_001C6D40(f, base, k, 0.0f, s);
    }
}

/* Player_SetArmMotion_1_001C7020 */
static inline f32 u2f_Player_UpdateArmBones_0_001C5DE0_(u32 x) { return x; }

void Player_SetArmMotion_1_001C7020(u16 idx, f32 t, s32 flags, f32 b, f32 c) {
    H **h;
    S_Player_StartSwitchMotion_1_001C6D40 *s;
    B_Player_UpdateArmBones_0_001C5DE0__ *q;
    u8 a;
    E *e;
    f32 res;

    if (D_002022E4 == NULL) {
        s = NULL;
    } else if (D_002022E4->unk518 == NULL) {
        s = NULL;
    } else {
        s = (S_Player_StartSwitchMotion_1_001C6D40 *)(D_002022E4->unk518 + 0x180);
    }
    if (s == NULL) {
        return;
    }
    h = s->h;
    if (h == NULL || *h == NULL) {
        return;
    }
    if ((*h)->n <= 0) {
        return;
    }
    e = &s->tbl[idx];
    a = e->a;
    if (a == 0xFF) {
        return;
    }
    q = &e->q;
    Mdl_SetBoneRotation_0_001710D0(s->r, a, c * (0.0078125f * u2f_Player_UpdateArmBones_0_001C5DE0_(e->b)), 0.033333335f * (b + u2f_Player_UpdateArmBones_0_001C5DE0_(q->lo)), 0.033333335f * u2f_Player_UpdateArmBones_0_001C5DE0_(q->mid));
    sceVu0CopyVector__as_Player_UpdateArmBones_0_001C5DE0___(s->x18 + 0xA0, D_003139A0);
    if (flags & 2) {
        s->f3D6.f.b7 = 1;
    } else {
        s->f3D6.f.b7 = 0;
    }
    if (flags & 4) {
        s->f3D7.f.b0 = 1;
    } else {
        s->f3D7.f.b0 = 0;
    }
    res = Mdl_GetMotionLength_0_00173F70(*h, s->tbl[idx].a);
    if (!(flags & 1)) {
        s->r->c = t;
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    } else {
        s->r->c = res - t;
        if (s->r->c < 0.0f) {
            s->r->c = 0.0f;
        }
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    }
    ((F3 *)&s->f3D7)->f.b1 = 0;
}

/* Player_IsHitTarget_0_001C7320 */
static inline S_Player_IsHitTarget_0_001C7320 *getp(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (S_Player_IsHitTarget_0_001C7320 *)(D_002022E4->unk518 + 0x180);
}
s32 Player_IsHitTarget_0_001C7320(u16 *a0) {
    S_Player_IsHitTarget_0_001C7320 *p;
    s32 i;
    p = getp();
    if (p == 0) return 0;
    for (i = 0; i < 8; i++) {
        if (p->ids[i] == a0[1]) return 1;
    }
    return 0;
}

/* Player_Nop_2_001C73B0 */
void Player_Nop_2_001C73B0(void) {

}

/* Player_OnHitEnemy_0_001C73C0_ */
/* Player_OnHitEnemy_0_001C73C0 */

/* Player_OnHitEnemy_0_001C73C0 */
/* Player_OnHitEnemy_0_001C73C0 */
static inline f32 u2f_Player_OnHitEnemy_0_001C73C0(u32 x) { return x; }
static inline f32 getf(A_Player_OnHitEnemy_0_001C73C0 *a) { return Enemy_GetMaxHp_2_0013F700(a); }
static inline S_Player_OnHitEnemy_0_001C73C0 *get_Player_OnHitEnemy_0_001C73C0(void) {
    S_Player_OnHitEnemy_0_001C73C0 *r;
    s8 *base;
    if (D_002022E4__as_Player_OnHitEnemy_0_001C73C0 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4__as_Player_OnHitEnemy_0_001C73C0 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_OnHitEnemy_0_001C73C0 *)(base + 0x180);
    }
    return r;
}

void Player_OnHitEnemy_0_001C73C0(A_Player_OnHitEnemy_0_001C73C0 *a0, u32 a1, u8 a2, s32 a3) {
    S_Player_OnHitEnemy_0_001C73C0 *s;
    s16 *r;
    s16 *p;
    f32 d;
    u8 b;
    s32 k;
    f32 f;
    s32 i;
    s8 *base;
    T_Player_UpdateArmBones_0_001C5DE0__ **t;

    if (D_002022E4__as_Player_OnHitEnemy_0_001C73C0 == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(D_002022E4__as_Player_OnHitEnemy_0_001C73C0 + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S_Player_OnHitEnemy_0_001C73C0 *)(base + 0x180);
    }
    if (s == NULL) return;
    if (s->x39C == 0) {
        r = s->r;
        if ((f32)r[2] / (f32)r[0] > 0.01f) {
            Player_ApplyDamage_2_001C8320((s32)(0.01f * (f32)r[0]), 0, 0, 0);
        }
    }
    if (Player_GetStat_2_001CD450(10, &b, 1, 1)) {
        s->r[2] += (s16)((a1 * b) / 100);
        r = s->r;
        p = &r[2];
        if (r[0] < *p) *p = r[0];
    }
    if (Player_GetStat_2_001CD450(13, &b, 1, 1)) {
        s->r[3] += (s16)((a1 * b) / 100);
        r = s->r;
        p = &r[3];
        if (r[1] < *p) *p = r[1];
    }
    if (ItemType_IsWeapon_0_001D1D50(s->x39C) == 0) {
        if (Enemy_IsDead_1_0013EEE0(a0)) {
            k = 1;
        } else {
            f = 100.0f * u2f_Player_OnHitEnemy_0_001C73C0(a1) / getf(a0);
            if (!(f < 30.0f)) {
                k = 2;
            } else {
                k = 4;
            }
        }
        if (a3) k = 8;
        t = (T_Player_UpdateArmBones_0_001C5DE0__ **)((u8 *)a0 + 0x4B4) + a2;
        Equip_DamageOnHit_0_001CC6F0(k, (*t)->mid);
        Player_PlayHitEnemySe_0_001CA7B0(s->x3CD, (*t)->mid);
    }
    s = get_Player_OnHitEnemy_0_001C73C0();
    if (s == NULL) return;
    for (i = 0; i < 8; i++) {
        if (s->ids[i] == 0xFFFF) {
            s->ids[i] = a0->x2;
            return;
        }
    }
}

/* Player_OnHitObject_0_001C7730 */
void Player_OnHitObject_0_001C7730(A_Player_OnHitObject_0_001C7730 *a, s32 b) {
    s32 r;
    s32 t;
    s32 m;
    S_Player_OnHitObject_0_001C7730 *s;
    if (D_002022E4__as_Player_OnHitEnemy_0_001C73C0 == NULL) {
        s = NULL;
    } else {
        t = M2C_FIELD(D_002022E4__as_Player_OnHitEnemy_0_001C73C0, s32 *, 0x518);
        if (t == 0) {
            s = NULL;
        } else {
            s = (S_Player_OnHitObject_0_001C7730 *)(t + 0x180);
        }
    }
    if (s != NULL) {
        s->b5 = 1;
        if (a->x34 != 0) {
            if (MapObj_Hit_0_001B85B0(b, a) != 0) {
                m = 1;
                s->b5 = 0;
            } else {
                m = 8;
            }
            r = MapObj_IsSame_0_001B8F30(a->x30, a->x34);
            Equip_DamageOnHit_0_001CC6F0(m, r);
        } else {
            r = 2;
        }
        if (s->b5) {
            Player_PlayHitObjectSe_0_001CA700(s->x3CD, r);
        }
    }
}

/* Player_TraceAttack_0_001C7850 */

s32 Player_TraceAttack_0_001C7850(s8 *a0, s32 a1) {
    Res res;
    Ray ray;
    s8 *o;
    s32 j;
    s32 i;
    s8 ***pp;
    s32 **q;

    Coll_ClosestPointB_0_00150160(&ray, a0 + 0x60, a0 + 0x40);
    for (i = 0, pp = (s8 ***)(&D_00201E80 + 2); i < 2; i++, pp++) {
        if (*pp != 0) {
            o = **pp;
            if (o != 0) {
                for (j = 0; j < *(u16 *)(o + 0x6E); j++) {
                    if (MapColl_RayCast_0_001B23E0(o, &res, &ray, j, 2, 1) != 0) {
                        Player_OnHitObject_0_001C7730__as_Player_TraceAttack_0_001C7850(&res, a1);
                    }
                }
            }
        }
    }
    ray = *(Ray *)(a0 + 0x40);
    for (i = 0, q = (s32 **)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && MapColl_RayCastAll_0_001B2F30(**q, &res, &ray, 2, 1) != 0) {
            Player_OnHitObject_0_001C7730__as_Player_TraceAttack_0_001C7850(&res, a1);
            return 1;
        }
    }
    return 0;
}

/* Player_InitAttack_0_001C79B0 */
void Player_InitAttack_0_001C79B0(X_Player_UpdateArmBones_0_001C5DE0__ *x) {
    P *c;
    if (D_002022E4 == NULL) {
        c = NULL;
    } else {
        s8 *p = D_002022E4->unk518;
        if (p == NULL) c = NULL;
        else c = (P *)(p + 0x180);
    }
    if (c != 0) {
        memset(x, 0, 0x40);
        Player_CalcAttack_1_001CEBF0(x, x->y, c->x3CD);
        x->f30.f = Equip_CheckAmmo_0_001CC250(Equip_GetSlotItem_1_001CCD90(c->x390->x94 & 1));
    }
}

/* Player_GetWeaponSegment_0_001C7A70 */

/* Player_GetWeaponSegment_0_001C7A70 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
inline s8 *get_Player_UpdateArmBones_0_001C5DE0__(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

s32 Player_GetWeaponSegment_0_001C7A70(M *out) {
    M m;
    f32 a[4];
    f32 b[4];
    s8 *p;
    s8 *q;
    s8 *r;
    f32 *pf;
    f32 x;
    f32 c;
    f32 d;

    p = get_Player_UpdateArmBones_0_001C5DE0__();
    if (p == NULL) {
        return 0;
    }
    if ((s16)Equip_GetSlotItem_1_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) == -1) {
        return 0;
    }
    if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
        q = *(s8 **)(p + 0x3C4);
    } else {
        q = *(s8 **)(p + 0x3C0);
    }
    if (q != NULL && *(s32 *)(q + 0x84) != 0) {
        r = *(s8 **)(q + 0x88);
        if (r != NULL) {
            sceVu0CopyVector__as_Player_GetWeaponSegment_0_001C7A70(a, r);
            sceVu0CopyVector__as_Player_GetWeaponSegment_0_001C7A70(b, r + 0x10);
            Seg_Init_1_001502A0(a[3], &m, b, a);
            pf = &m.f[7];
            x = *pf;
            p = get_Player_UpdateArmBones_0_001C5DE0__();
            if (p != NULL) {
                c = fabsf(-1.0471976f);
                d = fabsf(WRAP(*(f32 *)(*(s8 **)(p + 0x18) + 0x30)));
                if (!(d <= c)) {
                    d = c;
                }
                x *= 1.0f + d / c;
            }
            *pf = x;
            *out = m;
            return 1;
        }
    }
    return 0;
}

/* Player_ClampPitch_0_001C7CA0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

f32 Player_ClampPitch_0_001C7CA0(f32 a) {
    S *s;
    f32 lim;
    f32 c;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else if (D_002022E4->unk518 == NULL) {
        s = NULL;
    } else {
        s = (S *)((u8 *)D_002022E4->unk518 + 0x180);
    }
    if (s) {
        lim = fabsf(-1.0471976f);
        c = fabsf(WRAP(s->x18->x30));
        if (!(c <= lim)) c = lim;
        a *= 1.0f + c / lim;
    }
    return a;
}
#undef Player_ApplyDamage_2_001C8320

/* Player_TakeHit_1_001C7DC0___ */
#define D_002022E4 D_002022E4__as_Player_TakeHit_1_001C7DC0___
extern s8 *D_002022E4__as_Player_TakeHit_1_001C7DC0___;

/* Player_TakeHit_1_001C7DC0__ */

/* Player_TakeHit_1_001C7DC0_ */

/* Player_TakeHit_1_001C7DC0 */
static inline S_Player_TakeHit_1_001C7DC0 *get_Player_TakeHit_1_001C7DC0(void) {
    S_Player_TakeHit_1_001C7DC0 *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_TakeHit_1_001C7DC0 *)(base + 0x180);
    }
    return r;
}
static inline s32 calc_Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *a0, s32 k) {
    S_Player_TakeHit_1_001C7DC0 *s;
    s32 v;
    s16 *r;
    Buf buf;
    s8 *base;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S_Player_TakeHit_1_001C7DC0 *)(base + 0x180);
    }
    v = 0;
    if (s == NULL) return v;
    if (k) {
        r = s->r;
        v = r[0] / 100;
        if (v < r[2]) v = r[2] - v;
        return v;
    }
    buf.a[0] = s->st[0] / 5;
    buf.a[1] = s->st[1] / 5;
    buf.a[2] = s->st[2] / 5;
    buf.b[0] = s->st[4] / 5;
    buf.b[1] = s->st[5] / 5;
    buf.b[2] = s->st[6] / 5;
    return Combat_SumResist_0_001AB500__as_Player_TakeHit_1_001C7DC0(a0, &buf);
}

s32 Player_TakeHit_1_001C7DC0(X_Player_TakeHit_1_001C7DC0_ *a0) {
    S_Player_TakeHit_1_001C7DC0 *s;
    s32 v;
    s16 *r;
    Buf buf;
    u8 b;
    s32 k;

    if (get_Player_TakeHit_1_001C7DC0() == NULL) return 0;
    if (!a0->b3) {
        k = a0->b2;
        v = calc_Player_TakeHit_1_001C7DC0(a0, k);
        if (!a0->b2 && Player_GetStat_2_001CD450(0x12, &b, 0, 1)) {
            v -= v * b / 100;
            if (v < 0) v = 0;
        }
    } else {
        v = 9999;
    }
    Equip_DamageArmor_0_001CC830(v, a0->x8, 0, a0->lo);
    Player_RollStatusEffect_1_001C8570__as_Player_TakeHit_1_001C7DC0__(a0->x10);
    Player_ApplyDamage_2_001C8320__as_Player_TakeHit_1_001C7DC0_(v, 1, 1, 1);
    return v;
}

/* Player_TakeHitB_1_001C8070 */
static inline S_Player_TakeHitB_1_001C8070 *get_Player_TakeHitB_1_001C8070(void) {
    S_Player_TakeHitB_1_001C8070 *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_TakeHitB_1_001C8070 *)(base + 0x180);
    }
    return r;
}
static inline s32 calc_Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *a0, s32 bit) {
    S_Player_TakeHitB_1_001C8070 *s;
    s32 n;
    u16 buf[8];
    R_Player_TakeHit_1_001C7DC0_ *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S_Player_TakeHitB_1_001C8070 *)(base + 0x180);
    }
    n = 0;
    if (s == NULL) return n;
    if (bit) {
        r = s->x390;
        n = r->x0 / 100;
        if (n < r->x4) n = r->x4 - n;
        return n;
    }
    buf[1] = s->x462 / 5;
    buf[2] = s->x464 / 5;
    buf[3] = s->x466 / 5;
    buf[5] = s->x46A / 5;
    buf[6] = s->x46C / 5;
    buf[7] = s->x46E / 5;
    n = Combat_SumResist_0_001AB500__as_Player_TakeHitB_1_001C8070(a0, buf);
    return n;
}

s32 Player_TakeHitB_1_001C8070(B_Player_TakeHit_1_001C7DC0_ *a0, A *a1) {
    s32 n;
    u8 k;

    if (get_Player_TakeHitB_1_001C8070() == NULL) return 1;
    if (a1 == NULL) return 1;
    n = calc_Player_TakeHitB_1_001C8070(a0, a0->v);
    if (!a0->v && Player_GetStat_2_001CD450(0x11, &k, 0, 1)) {
        n -= n * k / 100;
        if (n < 0) n = 0;
    }
    Equip_DamageArmor_0_001CC830__as_Player_TakeHitB_1_001C8070(n, a0->x8, a1->x4B0->v, a0->p30);
    Player_RollStatusEffect_1_001C8570__as_Player_TakeHitB_1_001C8070(a0->x10);
    Player_ApplyDamage_2_001C8320__as_Player_TakeHit_1_001C7DC0_(n, 1, 1, 1);
    return 1;
}

/* Player_ApplyDamage_2_001C8320 */
static inline S_Player_TakeHit_1_001C7DC0_ *get_Player_TakeHit_1_001C7DC0_(void) {
    S_Player_TakeHit_1_001C7DC0_ *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_TakeHit_1_001C7DC0_ *)(base + 0x180);
    }
    return r;
}

s32 Player_ApplyDamage_2_001C8320(s32 n, s32 a1, s32 a2, s32 a3) {
    S_Player_TakeHit_1_001C7DC0_ *s;
    S_Player_TakeHit_1_001C7DC0_ *t;

    s = get_Player_TakeHit_1_001C7DC0_();
    if (s == NULL) return 0;
    if (s->x390->x4 <= 0) return 0;
    if (Game_GetBusy_0_0012C020()) return 0;
    Player_AddExp_0_001CEAA0(-n);
    s->b6 = 1;
    s->x410 = n;
    if (a1) s->x3BE = 15;
    if (a2) {
        Vibe_StartB_0_0015FE20(1.0f, n / 100.0f, 0.0f, 1.0f, 16.0f);
        Vibe_StartA_0_0015FD90(1.0f, n / 10.0f, 0.0f, 1.0f, 16.0f);
    }
    if (a3) Player_PlayHurtSe_0_001CA2B0(n);
    if (n * 100 / s->x390->x0 >= 30) {
        t = get_Player_TakeHit_1_001C7DC0_();
        if (t != NULL) {
            t->x438 = 10.0f;
            t->x43C = 30.0f;
            t->x440 = 0.9f;
            t->x444 = 10.0f;
            t->x434 = 0.0f;
            t->x430 = 0.0f;
        }
    }
    s->x39E.c.b4 = 0;
    s->x39E.h.b = 0;
    return s->x390->x4;
}

/* Player_RollStatusEffect_1_001C8570 */
/* Player_RollStatusEffect_1_001C8570 */
s32 Player_RollStatusEffect_1_001C8570(u32 *arg0) {
    S_Player_RollStatusEffect_1_001C8570 *s6;
    s32 ret;
    R_Player_RollStatusEffect_1_001C8570 *r;
    u32 *pa;
    u32 *pb;
    s32 i;
    u32 lvl;
    f32 f;
    f32 g;
    s8 *base;

    if (D_002022E4 == NULL) {
        s6 = NULL;
    } else if ((base = M2C_FIELD(D_002022E4, s8 **, 0x518)) == NULL) {
        s6 = NULL;
    } else {
        s6 = (S_Player_RollStatusEffect_1_001C8570 *)(base + 0x180);
    }
    ret = 0;
    if (s6 == NULL) return 0;
    if (((u64)((s64)D_00222A53[0] << 0x38) >> 0x3F) != 0) return 0;
    if (Player_GetStat_2_001CD450(7, NULL, 0, 1) != 0) return 0;
    r = s6->r;
    pa = r->a;
    pb = r->b;
    for (i = 0; i <= 5; i++) {
        if (arg0[i] != 0 && pb[i] == 0) {
            g = (1.0f - 0.01f * (f32)s6->c[i]) * ((1.0f - 0.0005f * (f32)(u32)s6->x) * (f32)arg0[i]);
            if (100.0f * (0.000015259022f * (f32)(u32)Rand_Next_3_0015ED20(arg0[i])) <= g) {
                lvl = pa[i] >> 24;
                if (lvl < 2) {
                    f = (1.0f - 0.0005f * (f32)(u32)s6->y) * (f32)D_001F3880[lvl][i];
                    pa[i] = (u32)f | ((lvl + 1) << 24);
                    ret = 1;
                }
            }
        }
    }
    return ret;
}

/* Player_AddStatus_1_001C88E0 */

void Player_AddStatus_1_001C88E0(s32 a, u32 b) {
    G *g;
    u32 v;
    g = D_00201E20;
    if (a < 0 || a > 5) return;
    if (b == 1 || b == 2) {
        if (!D_00222A53__as_Player_AddStatus_1_001C88E0[0].f.b7 && !Player_GetStat_2_001CD450__as_Player_AddStatus_1_001C88E0(7, 0, 0, 1) && !Equip_FindSlot_0_001CD2D0(a)) {
            v = g->x30[a] >> 24;
            if (v < 2 && v < b) {
                v = D_001F3860[b][a];
                g->x30[a] = v | (b << 24);
                g->x50[a] = 0;
            }
        }
    }
}
#undef D_002022E4
