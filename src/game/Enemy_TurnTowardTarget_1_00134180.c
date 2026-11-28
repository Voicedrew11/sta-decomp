#include "common.h"
#include "m2c.h"
typedef struct { u8 pad0[0x5B5]; Flags8 x5B5; u8 pad5B6[0x5C]; u8 x612; u8 pad613[0x2D]; Vec x640; u8 pad650[0x30]; Vec x680; u8 pad690[0x10]; Vec x6A0; u8 pad6B0[0x10]; u8 x6C0; } O;
typedef struct { f32 x, y, z, w; } V;
typedef struct { u16 v[4]; } Ids __attribute__((aligned(8)));
typedef struct { u16 x0; u16 x2; u16 x4; u16 x6; u16 x8; u8 pada[0xA]; u16 x14; } Prm;
typedef struct { u8 pad[0x24]; s32 x24; u8 pad28[0x18]; } Hit;
extern u8 D_00201C48;
extern Ids D_00201C40;
extern s32 D_00201E80;
s32 Enemy_TurnTowardTarget_1_00134180(O *o, f32 rate);
void Enemy_CalcAimOffset_1_00134620(s8 *a, Vec *pos, Vec *tgt);
u8 Enemy_UpdateMovement_1_00134960(s8 *a);
void Enemy_ExecMoveCmd_1_00134D70(s8 *a0, s32 a1);
void Enemy_ExecMoveCmdInt_1_00135240(s8 *a0, s32 a1);
u8 Enemy_SelectAttack_1_00135490(s8 *a, f32 *pl, f32 *pc, f32 *py);
u8 Enemy_EvalAttackRange_1_00135990(s8 *a, f32 *pl, f32 *pc, f32 *py);
f32 Enemy_GetTurnRateRad_1_0013DE20(O *);
s32 EnemyScr_Event2020_1_00140EF0(O *);
Vec* Enemy_GetPositionPtr_2_00140460(void *);
void sceVu0SubVector(void *, void *, void *);
s32 Enemy_Get5B4b1_1_0013E690(O *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0InterVector(f32, Vec *, Vec *, Vec *);
f32 Vec_YawAngle_2_0013FC10(void *);
Vec* Enemy_GetRotationPtr_1_00140430(void *);
s32 Enemy_GetModelParam174_1_0013DD10(O *);
s32 Enemy_GetModelData_1_0013DCE0(O *);
s32 Enemy_IsWaypointReachable_0_001434F0(s32, s32, Vec *, u8);
f32 sqrtf(f32);
void Enemy_GetForwardVector_2_001403D0(s8 *, Vec *);
f32 sinf(f32);
f32 cosf(f32);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(void *, void *, s8*);
void Enemy_CopyRotation_2_00140440(s8*, void *);
u8 Enemy_PickNearestWaypointToward_1_001435D0(s8 *, s8 *, Vec *);
u8 Waypoint_GetLink_0_00143810(s8 *, u8, u8);
s32 Enemy_PickWaypointDir_1_00143290(s8 *, s8 *, Vec *, u8, u8);
Vec* Waypoint_Get_0_00143840(s8 *, u8);
u16 EnemyScr_Event2024GetMove_1_001409A0(s8 *, s32, f32 *, f32 *, f32 *);
void Player_CopyPosition_1_00145760(s8 *);
void Enemy_CopyPosition_2_00140470(s8 *, s8 *);
void Enemy_CopyVec660_1_00140350(s8 *, s8 *);
void Enemy_CopyVec680_1_00140310(s8 *, s8 *);
void Player_GetForwardVector_2_001456B0(Vec *);
void Player_GetRightVector_1_00145640(Vec *);
void Enemy_GetRightVector_1_00140360(s8 *, Vec *);
u8 Enemy_PickWaypointToward_1_00143150(s8 *, s8 *, s8 *);
void Player_CopyRotation_1_00145720(s8 *);
s8* Player_GetPosition_1_00145730(void);
void Enemy_CopyVec670_1_00140330(s8 *, s8 *);
void Enemy_CopyVec690_1_00140300(s8 *, s8 *);
u16 EnemyScr_Event2013GetMove_1_001416B0(s8 *, s32, s32 *, s32 *, s32 *);
u8 Enemy_Get60B_1_0013E240(s8 *);
void Enemy_Set5B6b4_1_0013EA80(s8 *, s32);
u16 Enemy_GetCurrentParamIdx_0_0013E110(s8 *);
s8* ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(s8 *);
s32 Enemy_IsDead_1_0013EEE0(s8 *);
s32 Ent_GetTypeByte_1_0013E220(s8 *);
s8 Enemy_Get608_1_0013E290(s8 *);
Vec* Player_GetPosition_1_00145730__as_Enemy_SelectAttack_1_00135490(void);
Prm* Enemy_GetParamPtr270_1_0013DE60(s8 *);
void EnemyScr_Event2011GetWeights_1_00141A50(s8 *, f32 *, f32 *, f32 *, f32 *, f32 *);
s32 Player_IsCrouching_0_001C9A20(void);
s32 Player_IsMoving_0_001C9A80(void);
s32 Player_GetFlag521b5_1_00145620(void);
s32 Enemy_Get5B4b2_1_0013E660(s8 *);
s32 Enemy_Get5B4b4_1_0013E610(s8 *);
void memset(void *, s32, s32);
void Enemy_RaycastMapB_0_0013D320(s32, Hit *, Vec *, s32, s32);

/* Enemy_TurnTowardTarget_1_00134180 */
#define Enemy_GetPositionPtr_2_00140460 Enemy_GetPositionPtr_2_00140460__as_Enemy_TurnTowardTarget_1_00134180
Vec *Enemy_GetPositionPtr_2_00140460__as_Enemy_TurnTowardTarget_1_00134180(O *);
#define sceVu0SubVector sceVu0SubVector__as_Enemy_TurnTowardTarget_1_00134180
void sceVu0SubVector__as_Enemy_TurnTowardTarget_1_00134180(Vec *, Vec *, Vec *);
#define Vec_YawAngle_2_0013FC10 Vec_YawAngle_2_0013FC10__as_Enemy_TurnTowardTarget_1_00134180
f32 Vec_YawAngle_2_0013FC10__as_Enemy_TurnTowardTarget_1_00134180(Vec *);
#define Enemy_GetRotationPtr_1_00140430 Enemy_GetRotationPtr_1_00140430__as_Enemy_TurnTowardTarget_1_00134180
Vec *Enemy_GetRotationPtr_1_00140430__as_Enemy_TurnTowardTarget_1_00134180(O *);
#define PI 3.1415927f
#define TWOPI 6.2831855f
#define INV 0.15915494f
#define WRAP(x) ((((x) + PI) - TWOPI * (s32)(INV * ((x) + PI))) + (((x) + PI) < 0.0f ? TWOPI : 0.0f) - PI)

s32 Enemy_TurnTowardTarget_1_00134180(O *o, f32 rate) {
    Vec d;
    Vec a;
    Vec b;
    f32 sp;
    f32 mult;
    f32 ang;
    f32 lim;
    f32 dist;
    f32 w;
    f32 t;
    f32 diff;
    s32 p;
    s32 q;

    sp = Enemy_GetTurnRateRad_1_0013DE20(o);
    mult = 0.0f;
    switch (o->x612) {
    case 0:
        mult = 0.0f;
        break;
    case 1:
        mult = 0.5f;
        break;
    case 2:
        mult = 1.0f;
        break;
    case 3:
        mult = 1.5f;
        break;
    }
    if (o->x5B5.f.b6 && EnemyScr_Event2020_1_00140EF0(o)) {
        sceVu0SubVector(&d, &o->x680, Enemy_GetPositionPtr_2_00140460(o));
    } else {
        sceVu0SubVector(&d, &o->x640, Enemy_GetPositionPtr_2_00140460(o));
    }
    if (Enemy_Get5B4b1_1_0013E690(o)) {
        if (!(sceVu0InnerProduct(&o->x6A0, &o->x6A0) <= 0.1f)) {
            sceVu0Normalize(&a, &d);
            sceVu0Normalize(&b, &o->x6A0);
            sceVu0InterVector(0.7f, &a, &a, &b);
            ang = Vec_YawAngle_2_0013FC10(&a);
        } else {
            ang = Vec_YawAngle_2_0013FC10(&d);
        }
    } else {
        ang = Vec_YawAngle_2_0013FC10(&d);
    }
    diff = WRAP(ang);
    if (Enemy_GetRotationPtr_1_00140430(o)->y + PI < 0.0f) w = TWOPI; else w = 0.0f;
    t = (Enemy_GetRotationPtr_1_00140430(o)->y + PI) - TWOPI * (s32)(INV * (Enemy_GetRotationPtr_1_00140430(o)->y + PI));
    diff -= t + w - PI;
    if (!(diff <= PI)) diff -= TWOPI;
    if (diff < -PI) diff += TWOPI;
    lim = mult * (sp * rate);
    if (!(diff <= lim)) diff = lim;
    if (diff < -lim) diff = -lim;
    diff = WRAP(diff);
    Enemy_GetRotationPtr_1_00140430(o)->y += diff;
    if (o->x6C0 == 0xFF) {
        d.y = 0.0f;
        dist = sqrtf(sceVu0InnerProduct(&d, &d));
        if (dist < 100.0f) return 2;
        if (dist < 300.0f) return 1;
    } else {
        p = Enemy_GetModelParam174_1_0013DD10(o);
        q = Enemy_GetModelData_1_0013DCE0(o);
        if ((u8)Enemy_IsWaypointReachable_0_001434F0(p, q, Enemy_GetPositionPtr_2_00140460(o), *(volatile u8 *)&o->x6C0)) return 2;
    }
    return 0;
}
#undef Enemy_GetPositionPtr_2_00140460
#undef sceVu0SubVector
#undef Vec_YawAngle_2_0013FC10
#undef Enemy_GetRotationPtr_1_00140430
#undef PI
#undef TWOPI
#undef INV

/* Enemy_CalcAimOffset_1_00134620 */
#define Enemy_GetPositionPtr_2_00140460 Enemy_GetPositionPtr_2_00140460__as_Enemy_CalcAimOffset_1_00134620
Vec* Enemy_GetPositionPtr_2_00140460__as_Enemy_CalcAimOffset_1_00134620(s8 *);
#define Enemy_GetRotationPtr_1_00140430 Enemy_GetRotationPtr_1_00140430__as_Enemy_CalcAimOffset_1_00134620
Vec* Enemy_GetRotationPtr_1_00140430__as_Enemy_CalcAimOffset_1_00134620(s8 *);
#define Enemy_GetModelParam174_1_0013DD10 Enemy_GetModelParam174_1_0013DD10__as_Enemy_CalcAimOffset_1_00134620
s8* Enemy_GetModelParam174_1_0013DD10__as_Enemy_CalcAimOffset_1_00134620(s8 *);
#define Enemy_GetModelData_1_0013DCE0 Enemy_GetModelData_1_0013DCE0__as_Enemy_CalcAimOffset_1_00134620
s8* Enemy_GetModelData_1_0013DCE0__as_Enemy_CalcAimOffset_1_00134620(s8 *);

/* Enemy_CalcAimOffset_1_00134620 */

void Enemy_CalcAimOffset_1_00134620(s8 *a, Vec *pos, Vec *tgt) {
    Vec d;
    Vec r;
    Vec m;
    f32 len;
    f32 dy;
    f32 dot;

    sceVu0SubVector(&d, pos, Enemy_GetPositionPtr_2_00140460(a));
    d.y = 0.0f;
    len = sqrtf(sceVu0InnerProduct(&d, &d));
    dy = tgt->y - Enemy_GetRotationPtr_1_00140430(a)->y;
    if (len == 0.0f) {
        if (dy == 0.0f) return;
    } else {
        d.x /= len;
        d.y /= len;
        d.z /= len;
    }
    Enemy_GetForwardVector_2_001403D0(a, &m);
    if (D_00201C48 == 0) {
        r.x = sinf(tgt->y);
        r.y = 0.0f;
        r.z = cosf(tgt->y);
    }
    if (D_00201C48 == 1) {
        r.x = -sinf(tgt->y);
        r.y = 0.0f;
        r.z = -cosf(tgt->y);
    }
    if (D_00201C48 == 2) {
        r.x = cosf(tgt->y);
        r.y = 0.0f;
        r.z = -sinf(tgt->y);
    }
    if (D_00201C48 == 3) {
        r.x = -cosf(tgt->y);
        r.y = 0.0f;
        r.z = sinf(tgt->y);
    }
    dot = sceVu0InnerProduct(&r, &d);
    if (dot < -0.70710677f) {
        r.y = r.x;
        r.x = -r.z;
        r.z = r.y;
        r.y = 0.0f;
        dot = sceVu0InnerProduct(&r, &d);
        if (len < 300.0f) len = 500.0f;
        if (!(len <= 600.0f)) len = 400.0f;
        if (dot < 0.0f) {
            pos->x += r.x * len;
            pos->z += r.z * len;
        } else {
            pos->x -= r.x * len;
            pos->z -= r.z * len;
        }
    } else if (dot < 0.70710677f) {
        if (len < 300.0f) len = 500.0f;
        if (!(len <= 600.0f)) len = 400.0f;
        pos->x -= r.x * len;
        pos->z -= r.z * len;
    }
}

/* Enemy_UpdateMovement_1_00134960 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

u8 Enemy_UpdateMovement_1_00134960(s8 *a) {
    Vec p;
    Vec r;
    Vec d;
    s8 *o;
    s8 *g;
    u8 k0;
    u8 k1;
    u8 k;
    f32 dist;

    sceVu0CopyVector(&p, (Vec *)(a + 0x620));
    sceVu0CopyVector(&r, (Vec *)(a + 0x630));
    switch (*(u8 *)(a + 0x610)) {
    case 0:
        Enemy_CopyRotation_2_00140440(a, &r);
        break;
    case 1:
        Enemy_CalcAimOffset_1_00134620(a, &p, &r);
        break;
    case 2: {
        f32 ang;
        f32 x;
        f32 y;
        f32 z;
        ang = Enemy_GetRotationPtr_1_00140430(a)->y + 0.17453293f;
        x = 200.0f * sinf(ang - 3.1415927f);
        y = p.y;
        z = 200.0f * cosf(ang - 3.1415927f);
        p.x = x;
        p.y = y;
        p.z = z;
        r.y = WRAP(ang);
        break;
    }
    case 3: {
        Vec e;
        f32 len;
        sceVu0SubVector(&e, &p, Enemy_GetPositionPtr_2_00140460(a));
        *(s32 *)&e.y = 0;
        len = sqrtf(sceVu0InnerProduct(&e, &e));
        e.x /= len;
        e.y /= len;
        e.z /= len;
        e.x *= 8.0f;
        e.y *= 8.0f;
        e.z *= 8.0f;
        sceVu0SubVector(&p, Enemy_GetPositionPtr_2_00140460(a), &e);
        break;
    }
    }
    o = Enemy_GetModelParam174_1_0013DD10(a);
    g = Enemy_GetModelData_1_0013DCE0(a);
    if (o) {
        k0 = Enemy_PickNearestWaypointToward_1_001435D0(o, g, Enemy_GetPositionPtr_2_00140460(a));
        k1 = Enemy_PickNearestWaypointToward_1_001435D0(o, g, &p);
        if (k0 != 0xFF && k1 != 0xFF && k0 != k1) {
            k = Waypoint_GetLink_0_00143810(o, k0, k1);
            if (!Enemy_PickWaypointDir_1_00143290(o, g, Enemy_GetPositionPtr_2_00140460(a), k0, k)) k = k0;
            if (k == k1) k = 0xFF;
            if (k != 0xFF) {
                Vec *q = Waypoint_Get_0_00143840(o, k);
                if (q) sceVu0AddVector(&p, q, g);
            }
            *(u8 *)(a + 0x6C0) = k;
        } else {
            *(u8 *)(a + 0x6C0) = 0xFF;
        }
    } else {
        *(u8 *)(a + 0x6C0) = 0xFF;
    }
    sceVu0CopyVector((Vec *)(a + 0x640), &p);
    sceVu0CopyVector((Vec *)(a + 0x650), &r);
    sceVu0SubVector(&d, (Vec *)(a + 0x620), Enemy_GetPositionPtr_2_00140460(a));
    *(s32 *)&d.y = 0;
    dist = sqrtf(sceVu0InnerProduct(&d, &d));
    if (dist < 100.0f) return 2;
    if (!(dist < 300.0f)) return 0;
    return 1;
}

/* Enemy_ExecMoveCmd_1_00134D70 */
#define F(o) (*(f32 *)(a0 + (o)))

void Enemy_ExecMoveCmd_1_00134D70(s8 *a0, s32 a1) {
    f32 x, y, z;
    u16 r;
    u8 lo, hi;
    r = EnemyScr_Event2024GetMove_1_001409A0(a0, a1, &x, &y, &z);
    lo = r & 0xFF;
    hi = r >> 8;
    switch (lo) {
    case 0: {
        f32 *p;
        Enemy_CopyPosition_2_00140470(a0, a0 + 0x620);
        p = Enemy_GetModelData_1_0013DCE0(a0);
        F(0x620) = x;
        F(0x628) = y;
        if (p) {
            F(0x620) += p[0];
            F(0x628) += p[2];
        }
        break;
    }
    case 1:
        Player_CopyPosition_1_00145760(a0 + 0x620);
        break;
    case 2:
        Enemy_CopyPosition_2_00140470(a0, a0 + 0x620);
        break;
    case 3:
        Player_CopyPosition_1_00145760(a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 4:
        Enemy_CopyPosition_2_00140470(a0, a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 5: {
        Vec v;
        Player_CopyPosition_1_00145760(a0 + 0x620);
        Player_GetForwardVector_2_001456B0(&v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        Player_GetRightVector_1_00145640(&v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 6: {
        Vec v;
        Enemy_CopyPosition_2_00140470(a0, a0 + 0x620);
        Enemy_GetForwardVector_2_001403D0(a0, &v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        Enemy_GetRightVector_1_00140360(a0, &v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 7:
        break;
    case 8:
        Enemy_CopyVec660_1_00140350(a0, a0 + 0x620);
        break;
    case 9:
        Enemy_CopyVec660_1_00140350(a0, a0 + 0x620);
        F(0x620) += x;
        F(0x628) += y;
        break;
    case 10: {
        Vec v;
        Enemy_CopyVec660_1_00140350(a0, a0 + 0x620);
        Enemy_GetForwardVector_2_001403D0(a0, &v);
        F(0x620) += v.x * x;
        F(0x628) += v.z * x;
        Enemy_GetRightVector_1_00140360(a0, &v);
        F(0x620) += v.x * y;
        F(0x628) += v.z * y;
        break;
    }
    case 11:
        Enemy_CopyVec680_1_00140310(a0, a0 + 0x620);
        break;
    case 12: {
        s8 *s3 = Enemy_GetModelParam174_1_0013DD10(a0);
        s8 *s2 = (s8 *)Enemy_GetModelData_1_0013DCE0(a0);
        Enemy_CopyVec660_1_00140350(a0, a0 + 0x620);
        if (s3) {
            u8 k = Enemy_PickWaypointToward_1_00143150(s3, s2, Enemy_GetPositionPtr_2_00140460(a0));
            if (k != 0xFF) {
                sceVu0AddVector(a0 + 0x620, Waypoint_Get_0_00143840(s3, k), s2);
            }
        }
        break;
    }
    }
    switch (hi) {
    case 0:
        Enemy_CopyRotation_2_00140440(a0, a0 + 0x630);
        F(0x634) = z;
        break;
    case 1:
        Player_CopyRotation_1_00145720(a0 + 0x630);
        break;
    case 2:
        Enemy_CopyRotation_2_00140440(a0, a0 + 0x630);
        break;
    case 3: {
        Vec v;
        s8 *p = Player_GetPosition_1_00145730();
        sceVu0SubVector(&v, p, Enemy_GetPositionPtr_2_00140460(a0));
        *(s32 *)&v.y = 0;
        F(0x634) = Vec_YawAngle_2_0013FC10(&v);
        break;
    }
    case 4: {
        Vec v;
        sceVu0SubVector(&v, Enemy_GetPositionPtr_2_00140460(a0), Player_GetPosition_1_00145730());
        *(s32 *)&v.y = 0;
        F(0x634) = Vec_YawAngle_2_0013FC10(&v);
        break;
    }
    case 5:
        break;
    case 6:
        Enemy_CopyVec670_1_00140330(a0, a0 + 0x630);
        break;
    case 7:
        Enemy_CopyVec690_1_00140300(a0, a0 + 0x630);
        break;
    }
}

/* Enemy_ExecMoveCmdInt_1_00135240 */

void Enemy_ExecMoveCmdInt_1_00135240(s8 *a0, s32 a1) {
    s32 x, y, z;
    u16 r;
    u8 lo, hi;
    r = EnemyScr_Event2013GetMove_1_001416B0(a0, a1, &x, &y, &z);
    lo = r & 0xFF;
    hi = r >> 8;
    switch (lo) {
    case 1:
        Player_CopyPosition_1_00145760(a0 + 0x620);
        break;
    case 2:
        Enemy_CopyPosition_2_00140470(a0, a0 + 0x620);
        break;
    case 7:
        break;
    case 8:
        Enemy_CopyVec660_1_00140350(a0, a0 + 0x620);
        break;
    case 11:
        Enemy_CopyVec680_1_00140310(a0, a0 + 0x620);
        break;
    case 12: {
        s8 *s3 = Enemy_GetModelParam174_1_0013DD10(a0);
        s8 *s2 = Enemy_GetModelData_1_0013DCE0(a0);
        Enemy_CopyVec660_1_00140350(a0, a0 + 0x620);
        if (s3) {
            u8 k = Enemy_PickWaypointToward_1_00143150(s3, s2, Enemy_GetPositionPtr_2_00140460(a0));
            if (k != 0xFF) {
                sceVu0AddVector(a0 + 0x620, Waypoint_Get_0_00143840(s3, k), s2);
            }
        }
        break;
    }
    }
    switch (hi) {
    case 0:
        break;
    case 1:
        Player_CopyRotation_1_00145720(a0 + 0x630);
        break;
    case 2:
        Enemy_CopyRotation_2_00140440(a0, a0 + 0x630);
        break;
    case 3: {
        V v;
        s8 *p = Player_GetPosition_1_00145730();
        sceVu0SubVector(&v, p, Enemy_GetPositionPtr_2_00140460(a0));
        *(s32 *)&v.y = 0;
        *(f32 *)(a0 + 0x634) = Vec_YawAngle_2_0013FC10(&v);
        break;
    }
    case 4: {
        V v;
        sceVu0SubVector(&v, Enemy_GetPositionPtr_2_00140460(a0), Player_GetPosition_1_00145730());
        *(s32 *)&v.y = 0;
        *(f32 *)(a0 + 0x634) = Vec_YawAngle_2_0013FC10(&v);
        break;
    }
    case 5:
        break;
    case 6:
        Enemy_CopyVec670_1_00140330(a0, a0 + 0x630);
        break;
    case 7:
        Enemy_CopyVec690_1_00140300(a0, a0 + 0x630);
        break;
    }
}

/* Enemy_SelectAttack_1_00135490 */

u8 Enemy_SelectAttack_1_00135490(s8 *a, f32 *pl, f32 *pc, f32 *py) {
    s32 it;
    s32 it2;
    Ids ids;
    Vec d;
    Vec d2;
    Vec m;
    u8 t;
    u8 i;
    s8 *e;
    s8 *best;
    u16 id;
    u16 id2;
    s8 *e2;
    u8 k;
    f32 min;
    f32 dist;
    f32 len;
    f32 cs;
    f32 dy;

    t = Enemy_Get60B_1_0013E240(a);
    if (t == 0) return Enemy_EvalAttackRange_1_00135990(a, pl, pc, py);
    best = NULL;
    Enemy_Set5B6b4_1_0013EA80(a, 0);
    if (t == 1) {
        id = Enemy_GetCurrentParamIdx_0_0013E110(a);
        ids = D_00201C40;
        switch (id) {
        case 0x1068:
        case 0x1069:
            ids.v[0] = 0x106C;
            ids.v[1] = 0x106D;
            break;
        case 0x106A:
        case 0x106B:
            ids.v[0] = 0x106D;
            ids.v[1] = 0x106C;
            break;
        case 0x106C:
            ids.v[0] = 0x106B;
            ids.v[1] = 0x1068;
            ids.v[2] = 0x1069;
            ids.v[3] = 0x106A;
            break;
        case 0x106D:
            ids.v[0] = 0x106B;
            ids.v[1] = 0x106A;
            ids.v[2] = 0x1069;
            ids.v[3] = 0x1068;
            break;
        case 0x1078:
            ids.v[0] = 0x1079;
            break;
        case 0x1079:
            ids.v[0] = 0x1078;
            break;
        }
        it = 0;
        for (e = ActorList_Next_2_001A5460(&it); e != NULL; e = ActorList_Next_2_001A5460(&it)) {
            if (!Ent_IsNull0_1_0013EE30(e) && !Enemy_IsDead_1_0013EEE0(e)) {
                id2 = Enemy_GetCurrentParamIdx_0_0013E110(e);
                for (i = 0; i < 4; i++) {
                    if (id2 == ids.v[i]) {
                        best = e;
                        Enemy_CopyPosition_2_00140470(e, a + 0x680);
                        Enemy_CopyRotation_2_00140440(e, a + 0x690);
                        break;
                    }
                }
            }
            if (best) break;
        }
    } else if (t == 2) {
        min = 4000000.0f;
        it2 = 0;
        for (e2 = ActorList_Next_2_001A5460(&it2); e2 != NULL; e2 = ActorList_Next_2_001A5460(&it2)) {
            if (!Ent_IsNull0_1_0013EE30(e2) && !Enemy_IsDead_1_0013EEE0(e2)) {
                k = Ent_GetTypeByte_1_0013E220(e2);
                if (k >= 0x33 && k < 0x36 && Enemy_Get608_1_0013E290(e2) == 0xF) {
                    sceVu0SubVector(&d, Enemy_GetPositionPtr_2_00140460(e2), Enemy_GetPositionPtr_2_00140460(a));
                    dist = sceVu0InnerProduct(&d, &d);
                    if (dist < min) {
                        min = dist;
                        best = e2;
                        Enemy_CopyPosition_2_00140470(e2, a + 0x680);
                        Enemy_CopyRotation_2_00140440(e2, a + 0x690);
                    }
                }
            }
        }
    }
    if (best != NULL) {
    sceVu0SubVector(&d2, Enemy_GetPositionPtr_2_00140460(best), Enemy_GetPositionPtr_2_00140460(a));
    sqrtf(sceVu0InnerProduct(&d2, &d2));
    dy = d2.y;
    dy = dy < 0.0f ? -dy : dy;
    *(s32 *)&d2.y = 0;
    len = sqrtf(sceVu0InnerProduct(&d2, &d2));
    if (len > 0.0f) {
        d2.x /= len;
        d2.y /= len;
        d2.z /= len;
    }
    Enemy_GetForwardVector_2_001403D0(a, &m);
    cs = sceVu0InnerProduct(&d2, &m);
    if (pl) *pl = len;
    if (pc) *pc = cs;
    if (py) *py = dy;
    if (t == 1) {
        dy = Enemy_GetPositionPtr_2_00140460(a)->y - Player_GetPosition_1_00145730__as_Enemy_SelectAttack_1_00135490()->y;
        if (dy < -500.0f || !(dy <= 500.0f)) return 0;
    }
    return 1;
    }
    return Enemy_EvalAttackRange_1_00135990(a, pl, pc, py);
}
#undef Enemy_GetPositionPtr_2_00140460
#undef Enemy_GetRotationPtr_1_00140430
#undef Enemy_GetModelParam174_1_0013DD10
#undef Enemy_GetModelData_1_0013DCE0

/* Enemy_EvalAttackRange_1_00135990 */
#define C (((s32 **)&D_00201E80)[2])
#define D (((s32 **)&D_00201E80)[3])
#define Player_GetPosition_1_00145730 Player_GetPosition_1_00145730__as_Enemy_EvalAttackRange_1_00135990
Vec *Player_GetPosition_1_00145730__as_Enemy_EvalAttackRange_1_00135990(void);
#define Enemy_GetPositionPtr_2_00140460 Enemy_GetPositionPtr_2_00140460__as_Enemy_EvalAttackRange_1_00135990
Vec *Enemy_GetPositionPtr_2_00140460__as_Enemy_EvalAttackRange_1_00135990(s8 *);
#define sceVu0SubVector sceVu0SubVector__as_Enemy_EvalAttackRange_1_00135990
void sceVu0SubVector__as_Enemy_EvalAttackRange_1_00135990(Vec *, Vec *, Vec *);
static inline f32 u2f(u32 x) { return x; }
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

u8 Enemy_EvalAttackRange_1_00135990(s8 *a, f32 *pl, f32 *pc, f32 *py) {
    f32 v12C;
    f32 v128;
    f32 v124;
    f32 v120;
    f32 v11C;
    Vec d;
    Vec m;
    Hit h;
    Vec seg[2];
    u8 r;
    Prm *p;
    f32 full;
    f32 len;
    f32 cs;
    f32 dy;

    r = 0;
    p = Enemy_GetParamPtr270_1_0013DE60(a);
    Enemy_Set5B6b4_1_0013EA80(a, 1);
    EnemyScr_Event2011GetWeights_1_00141A50(a, &v12C, &v128, &v124, &v120, &v11C);
    sceVu0SubVector(&d, Player_GetPosition_1_00145730(), Enemy_GetPositionPtr_2_00140460(a));
    full = sqrtf(sceVu0InnerProduct(&d, &d));
    dy = d.y;
    dy = dy < 0.0f ? -dy : dy;
    *(s32 *)&d.y = 0;
    len = sqrtf(sceVu0InnerProduct(&d, &d));
    if (len > 0.0f) {
        d.x /= len;
        d.y /= len;
        d.z /= len;
    }
    Enemy_GetForwardVector_2_001403D0(a, &m);
    cs = sceVu0InnerProduct(&d, &m);
    if (full < mu(p->x14, v11C)) r = 1;
    if (r == 0) {
        if (Player_IsCrouching_0_001C9A20() || Player_IsMoving_0_001C9A80() || Player_GetFlag521b5_1_00145620()) {
            if (full < mu(p->x8, v128)) r = 1;
        }
    }
    if (r == 0 && Enemy_Get5B4b2_1_0013E660(a)) {
        if (len < mu(p->x0, v12C) && dy < u2f(p->x4) && !(cs <= cosf(3.1415927f * u2f(p->x2) / 180.0f))) {
            sceVu0CopyVector(&seg[0], Enemy_GetPositionPtr_2_00140460(a));
            seg[0].y -= 100.0f;
            seg[0].w = 1.0f;
            sceVu0CopyVector(&seg[1], Player_GetPosition_1_00145730());
            seg[1].y -= 100.0f;
            seg[1].w = 1.0f;
            memset(&h, 0, 0x40);
            if (C) Enemy_RaycastMapB_0_0013D320(*C, &h, seg, 6, 7);
            if (h.x24 == 0 && D) Enemy_RaycastMapB_0_0013D320(*D, &h, seg, 6, 7);
            if (h.x24 == 0) r = 1;
        }
    }
    if (pl) *pl = len;
    if (pc) *pc = cs;
    if (py) *py = dy;
    if (Enemy_Get5B4b4_1_0013E610(a)) r = 0;
    Player_CopyPosition_1_00145760(a + 0x680);
    Player_CopyRotation_1_00145720(a + 0x690);
    return r;
}
#undef Player_GetPosition_1_00145730
#undef Enemy_GetPositionPtr_2_00140460
#undef sceVu0SubVector
#undef C
#undef D
