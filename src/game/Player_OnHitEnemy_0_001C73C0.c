#include "m2c.h"
#include "common.h"
#include "actor.h"
typedef struct { u8 pad[0x2C]; u8 lo:3; u8 mid:3; u8 hi:2; } T;
typedef struct { u8 pad[2]; u16 x2; u8 pad4[0x4B0]; T *tbl[1]; } A_Player_OnHitEnemy_0_001C73C0;
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
typedef struct { u16 h[6]; u8 padC[4]; u8 y[0x20]; F30 f30; u8 pad31[0xF]; } X;
extern s32 D_00201E80;
void Player_OnHitEnemy_0_001C73C0(A_Player_OnHitEnemy_0_001C73C0 *a0, u32 a1, u8 a2, s32 a3);
void Player_OnHitObject_0_001C7730(A_Player_OnHitObject_0_001C7730 *a, s32 b);
s32 Player_TraceAttack_0_001C7850(s8 *a0, s32 a1);
void Player_InitAttack_0_001C79B0(X *x);
void Player_ApplyDamage_2_001C8320(s32, s32, s32, s32);
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
s32 Equip_GetSlotItem_1_001CCD90(s32);
void memset(void *, s32, s32);
void Player_CalcAttack_1_001CEBF0(X *, u8 *, s8);
s32 Equip_CheckAmmo_0_001CC250(s32);

/* Player_OnHitEnemy_0_001C73C0 */
#define D_002022E4 D_002022E4__as_Player_OnHitEnemy_0_001C73C0
extern s8 *D_002022E4__as_Player_OnHitEnemy_0_001C73C0;

/* Player_OnHitEnemy_0_001C73C0 */
/* Player_OnHitEnemy_0_001C73C0 */
static inline f32 u2f(u32 x) { return x; }
static inline f32 getf(A_Player_OnHitEnemy_0_001C73C0 *a) { return Enemy_GetMaxHp_2_0013F700(a); }
static inline S_Player_OnHitEnemy_0_001C73C0 *get(void) {
    S_Player_OnHitEnemy_0_001C73C0 *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
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
    T **t;

    if (D_002022E4 == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
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
            f = 100.0f * u2f(a1) / getf(a0);
            if (!(f < 30.0f)) {
                k = 2;
            } else {
                k = 4;
            }
        }
        if (a3) k = 8;
        t = (T **)((u8 *)a0 + 0x4B4) + a2;
        Equip_DamageOnHit_0_001CC6F0(k, (*t)->mid);
        Player_PlayHitEnemySe_0_001CA7B0(s->x3CD, (*t)->mid);
    }
    s = get();
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
    if (D_002022E4 == NULL) {
        s = NULL;
    } else {
        t = M2C_FIELD(D_002022E4, s32 *, 0x518);
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
#undef D_002022E4

/* Player_InitAttack_0_001C79B0 */
void Player_InitAttack_0_001C79B0(X *x) {
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
