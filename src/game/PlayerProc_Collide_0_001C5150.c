#include "actor.h"
#include "m2c.h"
typedef struct { f32 m[4][4]; } MtxF;
typedef struct {
    u8 pad0[0x10];
    s8 *x10;
    u8 pad14[4];
    s8 *o;
    u8 pad1C[0x40 - 0x1C];
    Vec pos;
    u8 pad50[0xB0 - 0x50];
    Vec vB0;
    Vec vC0;
    MtxF mD0;
    Vec v110;
    Vec v120;
    Vec m130;
    Vec v140;
    u8 pad150[4];
    s32 x154;
    u8 pad158[0x3A2 - 0x158];
    u8 b0:1; u8 b1:7;
} P_PlayerProc_Collide_0_001C5150;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
typedef struct {
    u8 pad0[0x18]; s8 *x18; u8 pad1[0x39C - 0x1C]; u8 x39C; u8 pad2[0x3D6 - 0x39D]; BF f;
} Sub;
typedef struct { u8 pad[0x518]; s8 *x518; } Obj;
typedef struct { u8 pad[8]; u16 mode; } Arg;
typedef struct { f32 x, y, z; } Vec_PlayerProc_Attack_0_001C55A0;
typedef struct { u8 pad[8]; u16 id; u8 pad2[2]; f32 xC; f32 x10; f32 x14; } Mdl;
typedef struct { u8 pad0[0x30]; f32 x30; u8 pad34[0x2C]; Vec v60; } S18;
typedef struct { u8 pad0[0x280]; Vec v280; u8 pad290[0x3C0 - 0x290]; Vec v3C0; u8 pad3D0[0x20]; f32 x3F0; f32 x3F4; f32 x3F8; } S2C;
typedef struct { u8 pad0[0x94]; u8 b0:1; } S390;
typedef struct {
    u8 pad0[0xC];
    s32 *xC;
    u8 pad10[8];
    S18 *x18;
    u8 pad1C[0xC];
    Mdl *x28;
    S2C *x2C;
    u8 pad30[0x380 - 0x30];
    f32 x380;
    u8 pad384[0x390 - 0x384];
    S390 *x390;
    u8 pad394[0x39C - 0x394];
    u8 x39C;
    u8 pad39D[4];
    u8 a0:5; u8 a5:1; u8 a6:2;
    u8 pad3A2[0x3AD - 0x3A2];
    s8 x3AD;
    s8 x3AE;
    u8 pad3AF[0x3CC - 0x3AF];
    u8 x3CC;
    u8 x3CD;
    u8 x3CE;
    u8 x3CF;
    u8 pad3D0[4];
    u8 x3D4;
    u8 x3D5;
    u8 c0:1; u8 c1:1; u8 c2:1; u8 c3:1; u8 c4:1; u8 c5:1; u8 c6:1; u8 c7:1;
    u8 d0:1; u8 d1:2;
} P_PlayerProc_Animate_0_001C5750;
extern s32 D_00201E80;
extern s32 D_002022BC;
extern s32 D_002022D8;
extern Mtx D_001F2170;
void PlayerProc_Collide_0_001C5150(Actor *a);
void PlayerProc_Attack_0_001C55A0(s32 a0, s32 a1, s32 a2, Arg *a3, s32 a4, s32 a5);
void PlayerProc_Animate_0_001C5750(Actor *a, f32 dt);
void sceVu0CopyVector(void *, void *);
void memset(void *, s32, s32);
void sceVu0SubVector(Vec *, Vec *, void *);
void sceVu0AddVector(Vec *, void *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
f32 Vec_DistXZ_2_0015DEE0(Vec *, void *);
f32 Vec_DistB_3_0015DF50(Vec *, void *);
s32 MapColl_SphereCastAll_0_001B34B0(s8 *, Vec *, Vec *, s32, s32);
s32 MapColl_SphereCast_0_001B2B90(s8 *, Vec *, Vec *, u16, s32, s32);
s32 MapColl_CapsuleCastAll_1_001B3240(s8 *, Vec *, Vec *, s32, s32);
s32 MapColl_CapsuleCast_1_001B2800(s8 *, Vec *, Vec *, u16, s32, s32);
void Attack_PlaySe_0_001D1E80(s32, s32, Arg *, s32, s32);
s32 Attack_SpawnSfx_0_001D1F20(s32, s8 *, s32, s32, Arg *, s32, s32);
void Sfx_SetOwner_1_00167600(s32, Obj *);
void Combat_UpdateAttackWrap_0_0013B950(s32, s32, s32, Arg *, s32, s32);
void MapObj_SnapToGround_0_001B9F10(void *, s8 *, f32, f32);
f32 Mdl_GetMotionLength_0_00173F70(s32, u16);
s32 ItemType_IsGun_0_001D1DD0(u8);
s32 rand(void);
void Mdl_AnimateWrap_0_00171B70(Mdl *, u16, f32);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0CopyMatrix(void *, void *);
s32 Option_GetMoveEffect_2_001A9440(void);
void sceVu0MulMatrix(Vec *, Mtx *, Vec *);
void Mdl_UpdateBoneMatricesCur_0_00171540(Mdl *, Mtx *);
s32 ItemType_IsWeapon_0_001D1D50(u8);
s32 ItemType_IsShield_0_001D1DA0(u8);
void Player_UpdateMagicState_0_001C6250(Actor *);
void Player_UpdateAttackState_0_001C5FB0(Actor *);
void Player_UpdateSwitchState_0_001C6470(Actor *);
void Player_PlayNullSe_0_001CA950(void);
void Snd_StopStream3_0_0012DA80(void);
void Player_RecalcStats_1_001CEDC0(s32);
void Player_UpdateEquipModel_0_001CE7D0(P_PlayerProc_Animate_0_001C5750 *, s32);
void Hud_ClearTimers_0_0019A840(void);

/* PlayerProc_Collide_0_001C5150 */
#define sceVu0CopyVector sceVu0CopyVector__as_PlayerProc_Collide_0_001C5150
void sceVu0CopyVector__as_PlayerProc_Collide_0_001C5150(Vec *, Vec *);

void PlayerProc_Collide_0_001C5150(Actor *a) {
    P_PlayerProc_Collide_0_001C5150 *p;
    s32 close;
    s32 hit;
    s32 i1; s8 ***q1; s32 j2; s8 *n2; s8 ***q2; s32 i2; s8 ***q3; s32 i3; s8 *n4; s8 ***q4; s32 i4; s32 j4;
    f32 d;
    f32 t;
    f32 end;
    Vec v;
    Vec dir;

    p = (P_PlayerProc_Collide_0_001C5150 *)(a->unk518 + 0x180);
    if (D_002022BC == (&D_00201E80)[2]) D_002022D8 = 0;
    if (D_002022BC == (&D_00201E80)[3]) D_002022D8 = 1;
    memset(&p->m130, 0, 0x40);
    close = 0;
    sceVu0SubVector(&dir, &p->pos, p->o + 0x10);
    sceVu0Normalize(&dir, &dir);
    if (Vec_DistXZ_2_0015DEE0(&p->pos, p->o + 0x10) < 20.0f && !p->b0) close = 1;
    d = Vec_DistB_3_0015DF50(&p->pos, p->o + 0x10);
    if (close) t = d; else t = 20.0f;
    for (end = 20.0f + d; t < end; t += 20.0f) {
        if (!(t <= d)) t = d;
        sceVu0ScaleVector(&v, &dir, t);
        sceVu0AddVector(&p->v110, p->o + 0x10, &v);
        p->v110.y = p->v110.y + 220.0f;
        p->v110.y = p->v110.y - 100.0f;
        p->v110.w = 100.0f;
        hit = 0;
        for (i1 = 0, q1 = (s8 ***)(&D_00201E80 + 2); i1 < 2; i1++, q1++) {
            if (*q1 != 0 && **q1 != 0 && MapColl_SphereCastAll_0_001B34B0(**q1, &p->m130, &p->v110, 3, 0)) hit = 1;
        }
        for (i2 = 0, q2 = (s8 ***)(&D_00201E80 + 2); i2 < 2; i2++, q2++) {
            if (*q2 != 0 && (n2 = **q2) != 0) {
                for (j2 = 0; j2 < *(u16 *)(n2 + 0x6E); j2++) {
                    if (MapColl_SphereCast_0_001B2B90(n2, &p->m130, &p->v110, j2, 3, 0)) hit = 1;
                }
            }
        }
        if (hit) break;
    }
    if (p->x154) {
        sceVu0ScaleVector(&p->vB0, &p->v140, 100.0f);
        sceVu0AddVector(&p->vB0, &p->vB0, &p->m130);
        p->vB0.w = 1.0f;
        sceVu0CopyVector(&p->vC0, &p->vB0);
        p->vB0.y = *(f32 *)(p->x10 + 0x14);
        p->vB0.y = p->vB0.y + 220.0f;
        p->vB0.y = p->vB0.y - 80.0f;
        p->vC0.y = p->vC0.y + 103.0f;
    } else {
        sceVu0CopyVector(&p->vB0, &p->pos);
        p->vB0.w = 1.0f;
        sceVu0CopyVector(&p->vC0, &p->pos);
        p->vC0.w = 1.0f;
        p->vB0.y = *(f32 *)(p->x10 + 0x14);
        p->vB0.y = p->vB0.y + 220.0f;
        p->vB0.y = p->vB0.y - 80.0f;
        p->vC0.y = p->vC0.y + 223.0f;
    }
    memset(&p->mD0, 0, 0x40);
    for (i3 = 0, q3 = (s8 ***)(&D_00201E80 + 2); i3 < 2; i3++, q3++) {
        if (*q3 != 0 && **q3 != 0) MapColl_CapsuleCastAll_1_001B3240(**q3, (Vec *)&p->mD0, &p->vB0, 4, 0);
    }
    for (i4 = 0, q4 = (s8 ***)(&D_00201E80 + 2); i4 < 2; i4++, q4++) {
        if (*q4 != 0 && (n4 = **q4) != 0) {
            for (j4 = 0; j4 < *(u16 *)(n4 + 0x6E); j4++) {
                MapColl_CapsuleCast_1_001B2800(n4, (Vec *)&p->mD0, &p->vB0, j4, 4, 0);
            }
        }
    }
}
#undef sceVu0CopyVector

/* PlayerProc_Attack_0_001C55A0 */
#define D_002022E4 D_002022E4__as_PlayerProc_Attack_0_001C55A0
extern Obj *D_002022E4__as_PlayerProc_Attack_0_001C55A0;
static inline Sub *getsub(void) {
    Obj *o = D_002022E4;
    if (o == NULL) return NULL;
    if (o->x518 == NULL) return NULL;
    return (Sub *)(o->x518 + 0x180);
}
void PlayerProc_Attack_0_001C55A0(s32 a0, s32 a1, s32 a2, Arg *a3, s32 a4, s32 a5) {
    Sub *s = getsub();
    s32 v;
    Vec_PlayerProc_Attack_0_001C55A0 pos;
    if (s != NULL) {
        switch (a3->mode) {
        case 0:
            if (a5 != 0) Attack_PlaySe_0_001D1E80(a0, a2, a3, a4, a5);
            break;
        case 1:
            if (a5 != 0) {
                v = Attack_SpawnSfx_0_001D1F20(a0, (s8 *)D_002022E4 + 0x580, a1, a2, a3, a4, a5);
                if (v != 0) Sfx_SetOwner_1_00167600(v, D_002022E4);
            }
            break;
        case 2:
            Combat_UpdateAttackWrap_0_0013B950(a0, a1, a2, a3, a4, a5);
            if (s->x39C != 0) {
                Sub *p = getsub();
                if (p != NULL) sceVu0CopyVector(&pos, (s8 *)p + 0x40);
                pos.y += 220.0f;
                MapObj_SnapToGround_0_001B9F10(&pos, s->x18 + 0x20, 300.0f, 500.0f);
            }
            s->f.b2 = 1;
            break;
        case 3:
            break;
        }
    }
}
#undef D_002022E4

/* PlayerProc_Animate_0_001C5750 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void PlayerProc_Animate_0_001C5750(Actor *a, f32 dt) {
    Mtx m1;
    Mtx m2;
    P_PlayerProc_Animate_0_001C5750 *p;
    s32 r;
    f32 lim;
    s32 *h;

    p = (P_PlayerProc_Animate_0_001C5750 *)(a->unk518 + 0x180);
    h = p->xC;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    if (p->d1 < 2) {
        lim = Mdl_GetMotionLength_0_00173F70(*h, p->x28->id);
        p->x28->x10 = p->x28->xC;
        if (p->d0) {
            p->x28->xC -= dt * p->x28->x14;
            if (p->c7) {
                if (p->x28->xC < 0.0f) {
                    do {
                        p->x28->xC += lim;
                    } while (p->x28->xC < 0.0f);
                }
            } else if (p->x28->xC < 0.0f) {
                p->x28->xC = 0.0f;
                p->d1++;
            }
        } else {
            p->x28->xC += dt * p->x28->x14;
            if (p->c7) {
                while (p->x28->xC > lim) {
                    p->x28->xC -= lim;
                }
            } else if (!(p->x28->xC <= lim)) {
                p->x28->xC = lim;
                p->d1++;
            }
        }
    }
    if (ItemType_IsGun_0_001D1DD0(p->x39C) && p->x3D5 == 4) {
        r = rand() % 2;
        p->x3AD = r * -(rand() % 2);
        r = rand() % 2;
        p->x3AE = r * -(rand() % 2);
    }
    Mdl_AnimateWrap_0_00171B70(p->x28, p->x28->id, p->x28->xC);
    p->x2C->x3F4 += 25.0f;
    p->x2C->x3F8 += -5.0f;
    p->x2C->x3F0 += p->x3AD;
    p->x2C->x3F4 += p->x3AE;
    sceVu0RotMatrixX(&m1, &D_001F2170, WRAP(WRAP(-1.0f * p->x18->x30)));
    m1.m[3].w = 1.0f;
    sceVu0CopyMatrix(&m2, &D_001F2170);
    if (Option_GetMoveEffect_2_001A9440()) {
        if (p->a5) {
            m2.m[3].y += 2.0f * p->x380;
        } else {
            m2.m[3].y += p->x380;
        }
    }
    if (p->x390->b0) {
        p->x2C->v3C0.x *= -1.0f;
    }
    sceVu0MulMatrix(&p->x2C->v3C0, &m1, &p->x2C->v3C0);
    sceVu0MulMatrix(&p->x2C->v3C0, &m2, &p->x2C->v3C0);
    sceVu0CopyMatrix(&p->x2C->v280, &p->x18->v60);
    Mdl_UpdateBoneMatricesCur_0_00171540(p->x28, &D_001F2170);
    if (ItemType_IsWeapon_0_001D1D50(p->x39C)) {
        if (ItemType_IsShield_0_001D1DA0(p->x39C)) {
            Player_UpdateMagicState_0_001C6250(a);
        } else {
            Player_UpdateAttackState_0_001C5FB0(a);
        }
    } else {
        Player_UpdateSwitchState_0_001C6470(a);
    }
    if (p->c3 && p->x3D5 == 0) {
        p->x390->b0 ^= 1;
        p->c3 = 0;
        p->c4 = 1;
        p->x3D4 = 0;
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        Player_PlayNullSe_0_001CA950();
        Snd_StopStream3_0_0012DA80();
        Player_RecalcStats_1_001CEDC0(3);
        Player_UpdateEquipModel_0_001CE7D0(p, 1);
        Hud_ClearTimers_0_0019A840();
    }
}
