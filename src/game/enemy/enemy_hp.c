#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0x15C]; u16 v; u8 pad2[0x170 - 0x15E]; } E;
typedef struct { u8 pad[0x20]; u16 max; } M;
typedef struct { u8 pad[0x4B4]; M *m[26]; E *e; } A_Enemy_AddPartValue_0_0013F5C0;
typedef struct { u8 pad[0x1A]; u16 val; u8 pad2[0x54-0x1C]; } Ent;
typedef struct { u8 pad[0x13C]; Ent *ents; } Tbl;
typedef struct { Tbl *tbl; } Hdr;
typedef struct {
    char pad[0x5B6];
    unsigned char : 5;
    unsigned char f : 1;
} Obj_Enemy_Set5B6b5_1_0013F8C0;
typedef struct { u8 b0:2; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:2; } B5B2;
typedef struct { u8 pad[0xBD]; u8 xBD; u8 pad2[5]; u8 xC3; } Stat;
typedef struct { u8 pad[0x158]; Stat *st; } Chr;
typedef struct { u8 pad[0x120]; u8 x120; } S190;
typedef struct { u8 pad[0x190]; S190 *p190; u8 pad194[4]; Vec *p198; } S518;
typedef struct {
    u16 x0;
    u8 pad2[0x4A6];
    Chr **p4A8;
    u8 pad4AC[0x6C];
    S518 *p518;
    u8 pad51C[0x96];
    B5B2 f5B2;
    u8 f5B3;
} Obj_Enemy_CheckReachable_0_0013F8E0;
typedef struct { u8 pad[0x81]; u8 unk81; u8 unk82[0x499]; s8 *unk51C; } A_Enemy_GetCollider_0_0013FB90;
s32 Enemy_AddPartValue_0_0013F5C0(A_Enemy_AddPartValue_0_0013F5C0 *a, u8 i, s32 d);
u32 Enemy_GetHpPercent_2_0013F620(s8 *a0);
u16 Enemy_GetMaxHp_2_0013F700(void *arg0);
u16 Enemy_AddHp_2_0013F710(s8 *a0, s32 v);
u16 Enemy_GetHp_2_0013F750(void *arg0);
void Enemy_UpdateParamFlags_0_0013F760(s8 *arg0, s32 a1);
u64 Enemy_Get5B6b5_1_0013F8B0(void *arg0);
void Enemy_Set5B6b5_1_0013F8C0(Obj_Enemy_Set5B6b5_1_0013F8C0 *o, int v);
s32 Enemy_CheckReachable_0_0013F8E0(Obj_Enemy_CheckReachable_0_0013F8E0 *a);
u8 Enemy_GetCollider_0_0013FB90(A_Enemy_GetCollider_0_0013FB90 *a0, s32 arg1, s32 *arg2, s32 *arg3);
u8 Enemy_Get81_1_0013FC00(void *arg0);
void MapState_IncCounter_0_001AA2A0(s32, s16);
void MapState_GetCounter_0_001AA1E0(s32, s16);
void MapState_IncVisits_0_001AA130(s32);
s32 EnemyScr_Event2021_1_00140E50(Obj_Enemy_CheckReachable_0_0013F8E0 *);
void Player_GetPos_1_001C9410(Vec *);
void Player_GetForwardVector_2_001456B0(Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);

/* Enemy_AddPartValue_0_0013F5C0 */
s32 Enemy_AddPartValue_0_0013F5C0(A_Enemy_AddPartValue_0_0013F5C0 *a, u8 i, s32 d) {
    E *e = &a->e[i];
    s32 v = e->v + d;
    s32 mx = a->m[i]->max;
    if (v < 0) v = 0;
    if (mx < v) v = mx;
    e->v = v;
    return (u16)v;
}

/* Enemy_GetHpPercent_2_0013F620 */
static inline f32 u2f_Enemy_GetHpPercent_2_0013F620(u32 x) { return x; }

u32 Enemy_GetHpPercent_2_0013F620(s8 *a0) {
    f32 a = u2f_Enemy_GetHpPercent_2_0013F620(*(u16 *)(*(s8 **)(a0 + 0x518) + 0x16C));
    f32 b = u2f_Enemy_GetHpPercent_2_0013F620(**(u16 **)(a0 + 0x4B0));
    return 0.5f + 100.0f * (a / b);
}

/* Enemy_GetMaxHp_2_0013F700 */
u16 Enemy_GetMaxHp_2_0013F700(void *arg0) {
    return *M2C_FIELD(arg0, u16 **, 0x4B0);
}

/* Enemy_AddHp_2_0013F710 */
u16 Enemy_AddHp_2_0013F710(s8 *a0, s32 v) {
    u16 *p;
    s32 n;
    s32 m;
    p = (u16 *)(*(s8 **)(a0 + 0x518) + 0x16C);
    n = *p + v;
    m = **(u16 **)(a0 + 0x4B0);
    if (n < 0) n = 0;
    if (m < n) n = m;
    *(u32 *)p = (u16)n;
    *(s16 *)(a0 + 0x6BA) = v;
    return n;
}

/* Enemy_GetHp_2_0013F750 */
u16 Enemy_GetHp_2_0013F750(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), u16 *, 0x16C);
}

/* Enemy_UpdateParamFlags_0_0013F760 */
void Enemy_UpdateParamFlags_0_0013F760(s8 *arg0, s32 a1) {
    u8 flag;
    u8 lo;
    s32 hi;
    u16 idx;
    Hdr *pp;
    Ent *q;
    flag = ((u64)((s64)*(u8 *)(arg0 + 0x5A1) << 0x3C) >> 0x3F);
    if (flag) lo = *(u16 *)(arg0 + 0x710) % 100;
    else {
        pp = *(Hdr **)(arg0 + 0x4A8); idx = *(u16 *)(arg0 + 0x4AC);
        q = pp ? &pp->tbl->ents[idx] : NULL;
        if (q) lo = q->val % 100; else lo = *(u16 *)(arg0 + 0x710) % 100;
    }
    if (flag) hi = *(u16 *)(arg0 + 0x712);
    else { pp = *(Hdr **)(arg0 + 0x4A8); if (pp) hi = *(s32 *)pp->tbl; else hi = 0; }
    MapState_IncCounter_0_001AA2A0(hi, lo);
    MapState_GetCounter_0_001AA1E0(hi, lo);
    if (a1) MapState_IncVisits_0_001AA130(hi);
}

/* Enemy_Get5B6b5_1_0013F8B0 */
u64 Enemy_Get5B6b5_1_0013F8B0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B6) << 0x3A) >> 0x3F;
}

/* Enemy_Set5B6b5_1_0013F8C0 */
/* Bitfield setter on an object's flag byte at 0x5B6. */


void Enemy_Set5B6b5_1_0013F8C0(Obj_Enemy_Set5B6b5_1_0013F8C0 *o, int v)
{
    o->f = v;
}

/* Enemy_CheckReachable_0_0013F8E0 */
static inline f32 u2f_Enemy_CheckReachable_0_0013F8E0(u32 x) { return x; }

s32 Enemy_CheckReachable_0_0013F8E0(Obj_Enemy_CheckReachable_0_0013F8E0 *a) {
    f32 r;
    Vec p;
    Vec d;
    Vec e;

    if ((u8)(a->x0 == 0)) {
        return 0;
    }
    if ((a->f5B3 & 3) < 3) {
        return 0;
    }
    if (a->f5B2.b2) {
        return 0;
    }
    if (a->f5B2.b6 == 2) {
        return 0;
    }
    if (a->f5B2.b6 == 1) {
        return 0;
    }
    if (a->f5B2.b6 == 0 && !a->f5B2.b5) {
        return 0;
    }
    if (a->p518->p190->x120 & 1) {
        return 0;
    }
    if (EnemyScr_Event2021_1_00140E50(a)) {
        return 0;
    }
    if ((a->f5B3 & 3) == 3) {
        r = 1000.0f;
        if (a->p4A8 && *a->p4A8) {
            r = 100.0f * u2f_Enemy_CheckReachable_0_0013F8E0((*a->p4A8)->st->xC3);
        }
        Player_GetPos_1_001C9410(&p);
        {
            f32 dy = p.y - a->p518->p198->y;
            if (dy < -r || !(dy <= r)) {
                return 1;
            }
        }
        r = 4000.0f;
        if (a->p4A8 && *a->p4A8) {
            r = 100.0f * u2f_Enemy_CheckReachable_0_0013F8E0((*a->p4A8)->st->xBD);
        }
        Player_GetForwardVector_2_001456B0(&d);
        sceVu0ScaleVector(&d, &d, 0.5f * r);
        sceVu0AddVector(&d, &d, &p);
        sceVu0SubVector(&e, a->p518->p198, &d);
        if (!(sceVu0InnerProduct(&e, &e) <= r * r)) {
            return 1;
        }
    }
    return 0;
}

/* Enemy_GetCollider_0_0013FB90 */
u8 Enemy_GetCollider_0_0013FB90(A_Enemy_GetCollider_0_0013FB90 *a0, s32 arg1, s32 *arg2, s32 *arg3) {
    u8 r = 0;
    s8 *p;
    if (a0->unk81 == 0) {
        *arg2 = 0;
        *arg3 = 0;
        return r;
    }
    p = a0->unk51C + a0->unk82[arg1 & 0xFF] * 0x170;
    *arg2 = (s32)(p + 0x90);
    *arg3 = (s32)(p + 0x80);
    if (!(((u8 *)p)[0x160] & 1)) {
        r = 1;
    }
    return r;
}

/* Enemy_Get81_1_0013FC00 */
u8 Enemy_Get81_1_0013FC00(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x81);
}
