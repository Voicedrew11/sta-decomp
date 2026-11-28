#include "m2c.h"
#include "common.h"
typedef struct { u8 pad[8]; u16 x8; u8 pada[6]; u8 x10[0x20]; u8 lo:4; u8 hi:4; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } X;
typedef struct { u8 pad[0x390]; s16 *r; u8 pad394[0x462 - 0x394]; u16 st[7]; } S_Player_TakeHit_1_001C7DC0;
typedef struct { s16 p0; s16 a[3]; s16 p8; s16 b[3]; } Buf;
typedef struct { s16 x0; s16 x2; s16 x4; } R_Player_TakeHit_1_001C7DC0_;
typedef struct { u8 pad[0x390]; R_Player_TakeHit_1_001C7DC0_ *x390; u8 pad394[0x462 - 0x394]; u16 x462, x464, x466, x468, x46A, x46C, x46E; } S_Player_TakeHitB_1_001C8070;
typedef struct { u8 pad[0xC]; u8 v:3; } T;
typedef struct { u8 pad[0x4B0]; T *x4B0; } A;
typedef struct { u8 pad[8]; u16 x8; u8 padA[6]; u32 x10[8]; u8 p30:4; u8 pad30:4; u8 a:2; u8 v:1; } B;
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
extern s8 *D_002022E4;
extern u32 D_001F3880[][8];
extern u8 D_00222A53[];
extern G *D_00201E20;
extern u32 D_001F3860[][8];
extern Flags8 D_00222A53__as_Player_AddStatus_1_001C88E0[];
s32 Player_TakeHit_1_001C7DC0(X *a0);
s32 Player_TakeHitB_1_001C8070(B *a0, A *a1);
s32 Player_ApplyDamage_2_001C8320(s32 n, s32 a1, s32 a2, s32 a3);
s32 Player_RollStatusEffect_1_001C8570(u32 *arg0);
void Player_AddStatus_1_001C88E0(s32 a, u32 b);
s32 Player_GetStat_2_001CD450(s32, void *, s32, s32);
s32 Combat_SumResist_0_001AB500(void *, void *);
void Equip_DamageArmor_0_001CC830(s32, u32, s32, s32);
s32 Combat_SumResist_0_001AB500__as_Player_TakeHit_1_001C7DC0(X *, Buf *);
s32 Combat_SumResist_0_001AB500__as_Player_TakeHitB_1_001C8070(B *, u16 *);
void Equip_DamageArmor_0_001CC830__as_Player_TakeHitB_1_001C8070(s32, u16, s32, s32);
void Player_RollStatusEffect_1_001C8570__as_Player_TakeHitB_1_001C8070(u32 *);
s32 Game_GetBusy_0_0012C020(void);
void Player_AddExp_0_001CEAA0(s32);
void Vibe_StartB_0_0015FE20(f32, f32, f32, f32, f32);
void Vibe_StartA_0_0015FD90(f32, f32, f32, f32, f32);
void Player_PlayHurtSe_0_001CA2B0(s32);
void Player_ApplyDamage_2_001C8320__as_Player_TakeHit_1_001C7DC0_(s32, s32, s32, s32);
u16 Rand_Next_3_0015ED20(u32);
s32 Equip_FindSlot_0_001CD2D0(s32);
s32 Player_GetStat_2_001CD450__as_Player_AddStatus_1_001C88E0(s32, s32, s32, s32);

/* Player_TakeHit_1_001C7DC0__ */
#define Player_RollStatusEffect_1_001C8570 Player_RollStatusEffect_1_001C8570__as_Player_TakeHit_1_001C7DC0__
void Player_RollStatusEffect_1_001C8570__as_Player_TakeHit_1_001C7DC0__(void *);

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
static inline s32 calc_Player_TakeHit_1_001C7DC0(X *a0, s32 k) {
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

s32 Player_TakeHit_1_001C7DC0(X *a0) {
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
    Player_RollStatusEffect_1_001C8570(a0->x10);
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
static inline s32 calc_Player_TakeHitB_1_001C8070(B *a0, s32 bit) {
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

s32 Player_TakeHitB_1_001C8070(B *a0, A *a1) {
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
static inline S_Player_TakeHit_1_001C7DC0_ *get(void) {
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

    s = get();
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
        t = get();
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
#undef Player_RollStatusEffect_1_001C8570

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
