#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0x6B0]; u16 x6B0; u16 x6B2; } O;
typedef struct { u8 pad[0x5B7]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; } A;
extern s8 D_001FABD0[4][6][7];
extern s8 D_001FABD7[4][6][7];
void Combat_CalcDamage_1_00132DB0(O *o, s32 a1, u8 *pa, u8 *pb, u8 *pc, u8 *pd);
f32 Combat_CalcHitAngle_0_00133D00(s8 *a, f32 *o1, f32 *o2, f32 *o3);
void Combat_RollStatusEffects_2_00133FD0(A *arg0, s8 *arg1, u8 *arg2);
u16 Enemy_GetSelPartValue_1_0013E410(O *);
f32 Enemy_GetDistSqToPlayer_1_001402A0(O *);
f32 Enemy_GetAngleToPlayer_1_0013FFC0(O *);
f32 Enemy_GetYawToPlayer_1_00140160(O *);
s32 Rand_Range_3_0013D500(s32);
void EnemyScr_Event2025_1_00140770(O *, s8 *, u8, u8, u8);
s32 Enemy_Get5B4m1_1_0013E6C0(O *);
void Enemy_Set5B4b0_1_0013E6A0(O *, s32);
s32 Enemy_Get5B4b1_1_0013E690(O *);
void Enemy_Set5B4b1_1_0013E670(O *, s32);
s32 Enemy_Get6B8_1_0013EF40(O *);
s32 Enemy_Get6B9_1_0013EF00(O *);
u32 Enemy_GetMaxHp_2_0013F700(O *);
u32 Enemy_GetHp_2_0013F750(O *);
s32 Player_IsCrouching_0_001C9A20(void);
void Enemy_SelectMotion_0_0013C420(O *, u8, u8, s32);
void Enemy_Set5B1b5_1_0013E920(O *, u8);
void Enemy_Set5B3b7_1_0013E6D0(O *, u8);
f32 Enemy_Get6BC_1_0013FCB0(s8 *);
void Enemy_GetScreenSize_0_0013FEB0(s8 *, f32 *, f32 *);
Vec* Enemy_PtrVec660_1_00140340(s8 *);
Vec* Enemy_GetPositionPtr_2_00140460(s8 *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 sqrtf(float);
void Enemy_AddStatusFlags_1_0013E4F0(A *, s32);

/* Combat_CalcDamage_1_00132DB0 */
static inline f32 u2f_Combat_CalcDamage_1_00132DB0(u32 x) { return x; }
static inline u8 cls(f32 f) {
    if (!(f <= -0.3f) && f < 0.3f) return 0;
    if (!(f <= -0.6f) && f < 0.6f) {
        if (f < 0.0f) return 1;
        return 2;
    }
    return 3;
}

void Combat_CalcDamage_1_00132DB0(O *o, s32 a1, u8 *pa, u8 *pb, u8 *pc, u8 *pd) {
    u8 l120 = 0;
    u8 l110 = 0;
    u16 m;
    f32 f24, f23, f22, f21, f20;
    s16 v[7];
    s8 w[7];
    u8 i;
    u8 a, b, mode, n, d;
    s32 c;
    s8 *t;
    u32 q;
    s32 x;
    f32 r;
    u8 bi;
    s8 mx;

    m = Enemy_GetSelPartValue_1_0013E410(o);
    f24 = Enemy_GetDistSqToPlayer_1_001402A0(o);
    f23 = Enemy_GetAngleToPlayer_1_0013FFC0(o);
    f22 = Enemy_GetYawToPlayer_1_00140160(o);
    f21 = u2f_Combat_CalcDamage_1_00132DB0(o->x6B0);
    f20 = u2f_Combat_CalcDamage_1_00132DB0(o->x6B2);
    for (i = 0; i < 7; i++) v[i] = Rand_Range_3_0013D500(16) - 8;
    v[3] -= 6; v[4] -= 6; v[5] -= 6;
    *pa = 0;
    *pb = 0;
    *pc = 0;
    *pd = 0;
    a = cls(f23);
    b = cls(f22);
    if (!(f24 <= f20)) {
        t = D_001FABD0[a][0];
        v[0] += t[0];
        for (i = 1; i < 7; i++) v[i] += t[i];
        mode = 2;
    } else if (!(f24 <= (f21 + f20) / 2.0f)) {
        t = D_001FABD7[a][0];
        v[0] += t[0];
        for (i = 1; i < 7; i++) v[i] += t[i];
        mode = 1;
    } else {
        t = ((s8 (*)[7])D_001FABD0)[a * 6 + 2 + b];
        v[0] += t[0];
        for (i = 1; i < 7; i++) v[i] += t[i];
        mode = 0;
    }
    for (i = 0; i < 7; i++) w[i] = 0;
    EnemyScr_Event2025_1_00140770(o, w, a, b, mode);
    for (i = 0; i < 1; i++) v[0] += w[i];
    for (i = 1; i < 7; i++) v[i] += w[i];
    if (mode < 2 && w[0] <= 0) v[0] = -127;
    if ((u8)Enemy_Get5B4m1_1_0013E6C0(o)) {
        v[0] += 4; v[1] -= 4; v[2] -= 4;
        v[3] += 4; v[4] += 4; v[5] += 4;
        v[6] += 2;
    }
    Enemy_Set5B4b0_1_0013E6A0(o, 0);
    if ((u8)Enemy_Get5B4b1_1_0013E690(o)) {
        v[0] -= 2; v[1] += 4; v[2] -= 2;
        v[3] -= 4; v[4] -= 4; v[5] -= 4;
        v[6] -= 2;
    }
    Enemy_Set5B4b1_1_0013E670(o, 0);
    n = Enemy_Get6B8_1_0013EF40(o);
    if (n > 0) {
        x = (u16)Enemy_GetMaxHp_2_0013F700(o);
        q = (u16)((x - (u16)Enemy_GetHp_2_0013F750(o)) / n);
        if (u2f_Combat_CalcDamage_1_00132DB0(q) / (f32)Enemy_GetMaxHp_2_0013F700(o) < 0.15f) {
            v[0] += 2; v[1] += 2; v[2] += 2;
            v[3] -= 2; v[4] -= 2; v[5] -= 2;
            v[6] -= 2;
        } else {
            v[0] -= 1; v[1] -= 1; v[2] -= 2;
            v[3] += 2; v[4] += 2; v[5] += 2;
            v[6] += 2;
        }
    }
    c = (u8)Enemy_Get6B8_1_0013EF40(o);
    d = Enemy_Get6B9_1_0013EF00(o);
    r = u2f_Combat_CalcDamage_1_00132DB0(d);
    if ((u8)c > 0) r = u2f_Combat_CalcDamage_1_00132DB0(d) / u2f_Combat_CalcDamage_1_00132DB0(c);
    if (r < 0.5f) {
        v[0] -= 1; v[1] -= 1; v[2] -= 2;
        v[3] += 2; v[4] += 2; v[5] += 2;
        v[6] += 1;
    } else if (r < 1.0f) {
        v[0] -= 1; v[1] -= 1; v[2] -= 1;
        v[3] += 1; v[4] -= 1; v[5] -= 1;
        v[6] -= 1;
    } else {
        v[0] += 4; v[1] += 2; v[2] -= 2;
        v[3] -= 4; v[4] -= 4; v[5] -= 4;
        v[6] -= 4;
    }
    if (!(m & 1)) v[1] = -127;
    if (!(m & 7)) v[2] = -127;
    if (!(m & 0x38)) v[3] = -127;
    if (!(m & 0x38)) v[4] = -127;
    if (!(m & 0x1C0)) v[5] = -127;
    v[6] = -127;
    if (Player_IsCrouching_0_001C9A20() == 0) v[6] = -127;
    bi = 0;
    mx = -126;
    for (i = 0; i < 7; i++) {
        if (mx < v[i]) {
            mx = v[i];
            bi = i;
        }
    }
    switch (bi) {
    case 0:
        *pa = 0; *pb = 0; l120 = 0; *pc = 0; l110 = 0; *pd = 0;
        break;
    case 1:
        if (m & 1) { *pa = 3; *pb = 0; *pc = 0; *pd = 2; l120 = 0; l110 = 0; }
        break;
    case 2:
        if (m & 2) { *pa = 3; *pb = 1; *pc = 0; *pd = 3; l120 = 0; l110 = 0; }
        else if (m & 4) { *pa = 3; *pb = 1; *pc = 0; *pd = 3; l120 = 1; l110 = 0; }
        else if (m & 1) { *pa = 3; *pb = 0; *pc = 0; *pd = 2; l120 = 0; l110 = 0; }
        break;
    case 3:
    case 4:
        if (m & 8) { *pa = 0xD; *pb = 0; *pc = 0; *pd = 3; l120 = 0; l110 = 0; }
        else if (m & 0x10) { *pa = 0xD; *pb = 0; *pc = 0; *pd = 3; l120 = 0; l110 = 0; }
        else if (m & 0x20) { *pa = 0xD; *pb = 0; *pc = 0; *pd = 3; l120 = 1; l110 = 0; }
        if (bi == 4 && *pa == 0xD) *pa = 0xE;
        break;
    case 5:
        if (m & 0x40) { *pa = 0xF; *pb = 0; *pc = 0; *pd = 2; l120 = 0; l110 = 0; }
        else if (m & 0x80) { *pa = 0xF; *pb = 0; *pc = 0; *pd = 2; l120 = 0; l110 = 0; }
        else if (m & 0x100) { *pa = 0xF; *pb = 0; *pc = 0; *pd = 2; l120 = 1; l110 = 0; }
        break;
    case 6:
        if (m & 0x200) { *pa = 2; *pb = 0; *pc = 0; *pd = 3; l120 = 1; l110 = l120; }
        break;
    }
    Enemy_SelectMotion_0_0013C420(o, *pa, *(volatile u8 *)pb, 1);
    Enemy_Set5B1b5_1_0013E920(o, l120);
    Enemy_Set5B3b7_1_0013E6D0(o, l110);
}

/* Combat_CalcHitAngle_0_00133D00 */
static inline f32 u2f_Combat_CalcHitAngle_0_00133D00(u32 x) { return x; }

f32 Combat_CalcHitAngle_0_00133D00(s8 *a, f32 *o1, f32 *o2, f32 *o3) {
    Vec d1;
    Vec d2;
    Vec d3;
    Vec h;
    f32 sx;
    f32 sy;
    f32 l1, l2;
    f32 len;
    f32 t;
    f32 y;
    f32 hl;
    f32 r;
    f32 m0, m1;
    Vec *p;
    t = Enemy_Get6BC_1_0013FCB0(a);
    sx = 0.0f;
    sy = 0.0f;
    Enemy_GetScreenSize_0_0013FEB0(a, &sx, &sy);
    sceVu0SubVector(&d1, (Vec *)(a + 0x680), Enemy_PtrVec660_1_00140340(a));
    p = Enemy_GetPositionPtr_2_00140460(a);
    sceVu0SubVector(&d2, p, Enemy_PtrVec660_1_00140340(a));
    sceVu0SubVector(&d3, (Vec *)(a + 0x680), Enemy_GetPositionPtr_2_00140460(a));
    l1 = sqrtf(sceVu0InnerProduct(&d1, &d1));
    l2 = sqrtf(sceVu0InnerProduct(&d2, &d2));
    len = sqrtf(sceVu0InnerProduct(&d3, &d3));
    sceVu0CopyVector(&h, &d1);
    y = h.y;
    y = (y < 0.0f) ? -y : y;
    h.y = 0.0f;
    hl = sqrtf(sceVu0InnerProduct(&h, &h)) / sx;
    m0 = y / sy;
    if (hl < m0) {
        hl = m0;
    }
    if (hl < t) {
        r = 1.0f;
    } else if (t < 0.3f) {
        r = 0.9f;
    } else if (hl < 0.8f) {
        r = 0.8f;
    } else {
        m1 = u2f_Combat_CalcHitAngle_0_00133D00(*(u16 *)(a + 0x6B2));
        m0 = u2f_Combat_CalcHitAngle_0_00133D00(*(u16 *)(a + 0x6B0));
        if (len < m0) {
            r = 0.8f;
        } else if (len < m1) {
            r = 0.5f;
        } else {
            r = 0.2f;
        }
    }
    if (o1) {
        *o1 = t;
    }
    if (o2) {
        *o2 = hl;
    }
    if (o3) {
        *o3 = len;
    }
    return r;
}

/* Combat_RollStatusEffects_2_00133FD0 */
void Combat_RollStatusEffects_2_00133FD0(A *arg0, s8 *arg1, u8 *arg2) {
    s32 t;
    t = M2C_FIELD(arg1, s32 *, 0x10) - arg2[0x24];
    if (Rand_Range_3_0013D500(0x63) < t) Enemy_AddStatusFlags_1_0013E4F0(arg0, 1);
    t = M2C_FIELD(arg1, s32 *, 0x18) - arg2[0x25];
    if (Rand_Range_3_0013D500(0x63) < t) Enemy_AddStatusFlags_1_0013E4F0(arg0, 2);
    t = M2C_FIELD(arg1, s32 *, 0x1C) - arg2[0x26];
    if (Rand_Range_3_0013D500(0x63) < t) Enemy_AddStatusFlags_1_0013E4F0(arg0, 4);
    t = M2C_FIELD(arg1, s32 *, 0x24) - arg2[0x27];
    if (Rand_Range_3_0013D500(0x63) < t) Enemy_AddStatusFlags_1_0013E4F0(arg0, 8);
    if (arg2[0x24] < 0x64 && arg0->b2) Enemy_AddStatusFlags_1_0013E4F0(arg0, 1);
    if (arg2[0x25] < 0x64 && arg0->b3) Enemy_AddStatusFlags_1_0013E4F0(arg0, 2);
    if (arg2[0x26] < 0x64 && arg0->b4) Enemy_AddStatusFlags_1_0013E4F0(arg0, 4);
    if (arg2[0x27] < 0x64 && arg0->b5) Enemy_AddStatusFlags_1_0013E4F0(arg0, 8);
}
