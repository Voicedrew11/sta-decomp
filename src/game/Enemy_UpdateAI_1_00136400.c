#include "m2c.h"
typedef struct { u8 pad[0x613]; u8 b613; f32 f614; u8 pad2[0xA9]; u8 b6C1; } Obj613;
u32 Enemy_Get5B4b5_1_0013E4D0(Obj613 *);
s32 Enemy_IsDead_1_0013EEE0(Obj613 *);
s32 Enemy_IsOnScreen_0_0013FCC0(Obj613 *, s32);
s32 Enemy_SelectAttack_1_00135490(Obj613 *, f32 *, f32 *, f32 *);
void EnemyScr_Event200F_1_00141E10(Obj613 *, u8, f32, f32, f32, f32);
f32 Combat_CalcHitAngle_0_00133D00(Obj613 *, f32 *, f32 *, f32 *);
u32 Enemy_Get5B6b4_1_0013EAA0(Obj613 *);
u8 EnemyScr_Event2026_1_00140480(Obj613 *, u8, u32, f32, f32, f32, f32);
u32 Enemy_Get5B0b7_1_0013EB60(Obj613 *);
void Enemy_ExecMoveCmd_1_00134D70(Obj613 *, s32);
void Enemy_ExecMoveCmdInt_1_00135240(Obj613 *, s32);
void Enemy_CopyVec660_1_00140350(Obj613 *, s8 *);
void Enemy_CopyVec670_1_00140330(Obj613 *, s8 *);
u8 Enemy_UpdateMovement_1_00134960(Obj613 *);
s32 Enemy_TurnTowardTarget_1_00134180(Obj613 *, f32);
#define B613(a) ((a)->b613)
#define F614(a) ((a)->f614)
static inline f32 u2f(u32 x) { return x; }
static inline void g(Obj613 *a, s32 k) {
    if (Enemy_Get5B0b7_1_0013EB60(a)) {
        Enemy_ExecMoveCmd_1_00134D70(a, k);
    } else {
        Enemy_ExecMoveCmdInt_1_00135240(a, k);
    }
    Enemy_UpdateMovement_1_00134960(a);
    F614(a) = u2f(B613(a)) / 10.0f;
}

void Enemy_UpdateAI_1_00136400(Obj613 *a, f32 dt) {
    f32 x0, y0, z0;
    f32 x1, y1, z1;
    f32 r;
    s32 busy;
    u8 m;

    if (Enemy_Get5B4b5_1_0013E4D0(a) && Enemy_IsDead_1_0013EEE0(a)) {
        return;
    }
    busy = (u8)Enemy_IsOnScreen_0_0013FCC0(a, 0);
    EnemyScr_Event200F_1_00141E10(a, Enemy_SelectAttack_1_00135490(a, &x0, &y0, &z0), x0, y0, z0, dt);
    r = Combat_CalcHitAngle_0_00133D00(a, &x1, &y1, &z1);
    a->b6C1 = EnemyScr_Event2026_1_00140480(a, a->b6C1, Enemy_Get5B6b4_1_0013EAA0(a), r, x1, y1, z1);
    F614(a) -= dt;
    if (F614(a) <= 0.0f) {
        if (Enemy_Get5B0b7_1_0013EB60(a)) {
            Enemy_ExecMoveCmd_1_00134D70(a, 0);
        } else {
            Enemy_ExecMoveCmdInt_1_00135240(a, 0);
        }
        if (!Enemy_IsDead_1_0013EEE0(a) && !(u8)busy) {
            Enemy_CopyVec660_1_00140350(a, (s8 *)a + 0x620);
            Enemy_CopyVec670_1_00140330(a, (s8 *)a + 0x630);
            B613(a) = 0xFA;
        }
        Enemy_UpdateMovement_1_00134960(a);
        F614(a) = u2f(B613(a)) / 10.0f;
    }
    if ((u8)Enemy_TurnTowardTarget_1_00134180(a, dt)) {
        m = Enemy_UpdateMovement_1_00134960(a);
        if (m == 1) {
            g(a, 1);
        } else if (m == 2) {
            g(a, 2);
        }
    }
}
