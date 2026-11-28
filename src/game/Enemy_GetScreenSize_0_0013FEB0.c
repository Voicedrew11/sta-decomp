#include "m2c.h"
#include "common.h"
#include "actor.h"
typedef struct { u8 pad[0x22]; u16 x22; u16 x24; u8 pad2[0x54-0x26]; } Ent;
typedef struct { u8 pad[0x13C]; Ent *ents; } Tbl;
typedef struct { Tbl *tbl; } Hdr;
typedef struct { u8 pad[0x4A8]; Hdr *x4A8; u16 x4AC; u8 p4AE[0xF3]; Flags8 f5A1; } O;
typedef struct { char pad[0x198]; f32 *v; } B_Enemy_GetDistSqToPlayer_1_001402A0;
typedef struct { char pad[0x518]; B_Enemy_GetDistSqToPlayer_1_001402A0 *b; } Obj_Enemy_GetDistSqToPlayer_1_001402A0;
typedef struct { char pad[0x24]; f32 yaw; } C;
typedef struct { char pad[0x198]; C *c; } B_Enemy_GetRightVector_1_00140360;
typedef struct { char pad[0x518]; B_Enemy_GetRightVector_1_00140360 *b; } Obj_Enemy_GetRightVector_1_00140360;
void Enemy_GetScreenSize_0_0013FEB0(O *o, f32 *a1, f32 *a2);
s32 Enemy_Ptr700_1_0013FF90(s32 arg0);
s32 Enemy_Ptr6F0_1_0013FFA0(s32 arg0);
s32 Enemy_Ptr6E0_1_0013FFB0(s32 arg0);
f32 Enemy_GetAngleToPlayer_1_0013FFC0(s8 *a0);
f32 Enemy_GetYawToPlayer_1_00140160(Actor *a);
f32 Enemy_GetDistSqToPlayer_1_001402A0(Obj_Enemy_GetDistSqToPlayer_1_001402A0 *o);
void Enemy_CopyVec690_1_00140300(u8 *obj, f32 *v);
void Enemy_CopyVec680_1_00140310(u8 *obj, f32 *v);
s32 Enemy_PtrVec670_1_00140320(s32 arg0);
void Enemy_CopyVec670_1_00140330(u8 *obj, f32 *v);
s32 Enemy_PtrVec660_1_00140340(s32 arg0);
void Enemy_CopyVec660_1_00140350(u8 *obj, f32 *v);
void Enemy_GetRightVector_1_00140360(Obj_Enemy_GetRightVector_1_00140360 *o, f32 *v);
void Enemy_GetForwardVector_2_001403D0(void *arg0, void *arg1);
s32 Enemy_GetRotationPtr_1_00140430(void *arg0);
void Enemy_CopyRotation_2_00140440(void *arg0, s32 arg1);
s32 Enemy_GetPositionPtr_2_00140460(void *arg0);
void Enemy_CopyPosition_2_00140470(void *arg0, s32 arg1);
Vec* Player_GetRotationPtr_1_00145710(void);
void Player_CopyPosition_1_00145760(void *);
void sceVu0SubVector(void *, void *, void *);
f32 atan2f(f32, f32);
f32 sceVu0InnerProduct(f32 *v0, f32 *v1);
f32 sqrtf(f32 x);
void sceVu0CopyVector(f32 *v0, f32 *v1);
f32 cosf(f32 x);
f32 sinf(f32 x);

/* Enemy_GetScreenSize_0_0013FEB0 */
static inline f32 u2f(u32 x) { return x; }

void Enemy_GetScreenSize_0_0013FEB0(O *o, f32 *a1, f32 *a2) {
    f32 x;
    f32 y;
    Hdr *pp;
    u16 idx;
    Ent *q;

    y = x = 4000.0f;
    if (!o->f5A1.f.b3) {
        idx = o->x4AC;
        pp = o->x4A8;
        q = pp ? &pp->tbl->ents[idx] : NULL;
        if (q) {
            x = u2f(q->x22);
            y = u2f(q->x24);
        }
    }
    if (a1) *a1 = x;
    if (a2) *a2 = y;
}

/* Enemy_Ptr700_1_0013FF90 */
s32 Enemy_Ptr700_1_0013FF90(s32 arg0) {
    return arg0 + 0x700;
}

/* Enemy_Ptr6F0_1_0013FFA0 */
s32 Enemy_Ptr6F0_1_0013FFA0(s32 arg0) {
    return arg0 + 0x6F0;
}

/* Enemy_Ptr6E0_1_0013FFB0 */
s32 Enemy_Ptr6E0_1_0013FFB0(s32 arg0) {
    return arg0 + 0x6E0;
}

/* Enemy_GetAngleToPlayer_1_0013FFC0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define Player_CopyPosition_1_00145760 Player_CopyPosition_1_00145760__as_Enemy_GetAngleToPlayer_1_0013FFC0
void Player_CopyPosition_1_00145760__as_Enemy_GetAngleToPlayer_1_0013FFC0(Vec *);
#define sceVu0SubVector sceVu0SubVector__as_Enemy_GetAngleToPlayer_1_0013FFC0
void sceVu0SubVector__as_Enemy_GetAngleToPlayer_1_0013FFC0(Vec *, Vec *, Vec *);

f32 Enemy_GetAngleToPlayer_1_0013FFC0(s8 *a0) {
 Vec v; f32 y; f32 d; f32 a;
 y = Player_GetRotationPtr_1_00145710()->y;
 Player_CopyPosition_1_00145760(&v);
 sceVu0SubVector(&v, *(Vec **)(*(s8 **)(a0 + 0x518) + 0x198), &v);
 a = 3.1415927f + atan2f(v.x, v.z); a = WRAP(a); y = WRAP(y); y = a - y;
 if (y > 3.1415927f) y -= 6.2831855f;
 if (y < -3.1415927f) y += 6.2831855f;
 y /= 3.1415927f; return y;
}
#undef Player_CopyPosition_1_00145760
#undef sceVu0SubVector

/* Enemy_GetYawToPlayer_1_00140160 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define Player_CopyPosition_1_00145760 Player_CopyPosition_1_00145760__as_Enemy_GetYawToPlayer_1_00140160
void Player_CopyPosition_1_00145760__as_Enemy_GetYawToPlayer_1_00140160(Vec *);
#define sceVu0SubVector sceVu0SubVector__as_Enemy_GetYawToPlayer_1_00140160
void sceVu0SubVector__as_Enemy_GetYawToPlayer_1_00140160(Vec *, Vec *, s8 *);

f32 Enemy_GetYawToPlayer_1_00140160(Actor *a) {
    f32 r;
    f32 d;
    Vec v;
    r = *(f32 *)(*(s8 **)(a->unk518 + 0x198) + 0x24);
    Player_CopyPosition_1_00145760(&v);
    sceVu0SubVector(&v, &v, *(s8 **)(a->unk518 + 0x198));
    d = 3.1415927f + atan2f(v.x, v.z);
    d = WRAP(d) - r;
    if (!(d <= 3.1415927f)) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    d /= 3.1415927f;
    return d;
}
#undef Player_CopyPosition_1_00145760
#undef sceVu0SubVector

/* Enemy_GetDistSqToPlayer_1_001402A0 */
#define Player_CopyPosition_1_00145760 Player_CopyPosition_1_00145760__as_Enemy_GetDistSqToPlayer_1_001402A0
void Player_CopyPosition_1_00145760__as_Enemy_GetDistSqToPlayer_1_001402A0(f32 *v);
#define sceVu0SubVector sceVu0SubVector__as_Enemy_GetDistSqToPlayer_1_001402A0
void sceVu0SubVector__as_Enemy_GetDistSqToPlayer_1_001402A0(f32 *v0, f32 *v1, f32 *v2);

f32 Enemy_GetDistSqToPlayer_1_001402A0(Obj_Enemy_GetDistSqToPlayer_1_001402A0 *o)
{
    f32 v[4];
    Player_CopyPosition_1_00145760(v);
    sceVu0SubVector(v, v, o->b->v);
    return sqrtf(sceVu0InnerProduct(v, v));
}
#undef Player_CopyPosition_1_00145760
#undef sceVu0SubVector

/* Enemy_CopyVec690_1_00140300 */
void Enemy_CopyVec690_1_00140300(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x690));
}

/* Enemy_CopyVec680_1_00140310 */
void Enemy_CopyVec680_1_00140310(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x680));
}

/* Enemy_PtrVec670_1_00140320 */
s32 Enemy_PtrVec670_1_00140320(s32 arg0) {
    return arg0 + 0x670;
}

/* Enemy_CopyVec670_1_00140330 */
void Enemy_CopyVec670_1_00140330(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x670));
}

/* Enemy_PtrVec660_1_00140340 */
s32 Enemy_PtrVec660_1_00140340(s32 arg0) {
    return arg0 + 0x660;
}

/* Enemy_CopyVec660_1_00140350 */
void Enemy_CopyVec660_1_00140350(u8 *obj, f32 *v)
{
    sceVu0CopyVector(v, (f32 *)(obj + 0x660));
}

/* Enemy_GetRightVector_1_00140360 */
void Enemy_GetRightVector_1_00140360(Obj_Enemy_GetRightVector_1_00140360 *o, f32 *v)
{
    f32 a = o->b->c->yaw;
    a += 1.5707964f;
    v[0] = -sinf(a);
    v[1] = 0.0f;
    v[2] = -cosf(a);
}

/* Enemy_GetForwardVector_2_001403D0 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void Enemy_GetForwardVector_2_001403D0(void *arg0, void *arg1) {
    f32 temp_f20;

    temp_f20 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void **, 0x198), f32 *, 0x24);
    M2C_FIELD(arg1, f32 *, 0) = (f32) -sinf(temp_f20);
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, f32 *, 8) = (f32) -cosf(temp_f20);
}

/* Enemy_GetRotationPtr_1_00140430 */
s32 Enemy_GetRotationPtr_1_00140430(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198) + 0x20;
}

/* Enemy_CopyRotation_2_00140440 */
#define sceVu0CopyVector sceVu0CopyVector__as_Enemy_CopyRotation_2_00140440
void sceVu0CopyVector__as_Enemy_CopyRotation_2_00140440(s32, s32);

void Enemy_CopyRotation_2_00140440(void *arg0, s32 arg1) {
    sceVu0CopyVector(arg1, M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198) + 0x20);
}
#undef sceVu0CopyVector

/* Enemy_GetPositionPtr_2_00140460 */
s32 Enemy_GetPositionPtr_2_00140460(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198);
}

/* Enemy_CopyPosition_2_00140470 */
#define sceVu0CopyVector sceVu0CopyVector__as_Enemy_CopyPosition_2_00140470
void sceVu0CopyVector__as_Enemy_CopyPosition_2_00140470(s32, s32);

void Enemy_CopyPosition_2_00140470(void *arg0, s32 arg1) {
    sceVu0CopyVector(arg1, M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), s32 *, 0x198));
}
#undef sceVu0CopyVector
