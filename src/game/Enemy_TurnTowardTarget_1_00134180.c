#include "common.h"
typedef struct { u8 pad0[0x5B5]; Flags8 x5B5; u8 pad5B6[0x5C]; u8 x612; u8 pad613[0x2D]; Vec x640; u8 pad650[0x30]; Vec x680; u8 pad690[0x10]; Vec x6A0; u8 pad6B0[0x10]; u8 x6C0; } O;
f32 Enemy_GetTurnRateRad_1_0013DE20(O *);
s32 EnemyScr_Event2020_1_00140EF0(O *);
Vec *Enemy_GetPositionPtr_2_00140460(O *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
s32 Enemy_Get5B4b1_1_0013E690(O *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0InterVector(f32, Vec *, Vec *, Vec *);
f32 Vec_YawAngle_2_0013FC10(Vec *);
Vec *Enemy_GetRotationPtr_1_00140430(O *);
s32 Enemy_GetModelParam174_1_0013DD10(O *);
s32 Enemy_GetModelData_1_0013DCE0(O *);
s32 Enemy_IsWaypointReachable_0_001434F0(s32, s32, Vec *, u8);
f32 sqrtf(f32);
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
