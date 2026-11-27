#include "m2c.h"
typedef struct { u8 pad[0x2C]; u8 lo:3; u8 mid:3; u8 hi:2; } T;
typedef struct { u8 pad[2]; u16 x2; u8 pad4[0x4B0]; T *tbl[1]; } A;
typedef struct { u8 pad[0x390]; s16 *r; u8 pad394[8]; u8 x39C; u8 pad39D[0x3CD - 0x39D]; s8 x3CD; u8 pad3CE[0x3E0 - 0x3CE]; u16 ids[8]; } S;
extern s8 *D_002022E4;
void Player_ApplyDamage_2_001C8320(s32, s32, s32, s32);
s32 Player_GetStat_2_001CD450(s32, void *, s32, s32);
s32 ItemType_IsWeapon_0_001D1D50(u8);
s32 Enemy_IsDead_1_0013EEE0(A *);
u32 Enemy_GetMaxHp_2_0013F700(A *);
void Equip_DamageOnHit_0_001CC6F0(s32, s32);
void Player_PlayHitEnemySe_0_001CA7B0(s8, s32);
static inline f32 u2f(u32 x) { return x; }
static inline f32 getf(A *a) { return Enemy_GetMaxHp_2_0013F700(a); }
static inline S *get(void) {
    S *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    return r;
}

void Player_OnHitEnemy_0_001C73C0(A *a0, u32 a1, u8 a2, s32 a3) {
    S *s;
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
        s = (S *)(base + 0x180);
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
