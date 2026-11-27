#include "common.h"
typedef struct { u16 x0; u16 x2; u16 x4; u16 x6; u16 x8; u8 pada[0xA]; u16 x14; } Prm;
typedef struct { u8 pad[0x24]; s32 x24; u8 pad28[0x18]; } Hit;
extern s32 D_00201E80;
#define C (((s32 **)&D_00201E80)[2])
#define D (((s32 **)&D_00201E80)[3])
f32 sqrtf(f32);
Prm *Enemy_GetParamPtr270_1_0013DE60(s8 *);
void Enemy_Set5B6b4_1_0013EA80(s8 *, s32);
void EnemyScr_Event2011GetWeights_1_00141A50(s8 *, f32 *, f32 *, f32 *, f32 *, f32 *);
Vec *Player_GetPosition_1_00145730(void);
Vec *Enemy_GetPositionPtr_2_00140460(s8 *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void Enemy_GetForwardVector_2_001403D0(s8 *, Vec *);
s32 Player_IsCrouching_0_001C9A20(void);
s32 Player_IsMoving_0_001C9A80(void);
s32 Player_GetFlag521b5_1_00145620(void);
s32 Enemy_Get5B4b2_1_0013E660(s8 *);
s32 Enemy_Get5B4b4_1_0013E610(s8 *);
f32 cosf(f32);
void memset(void *, s32, s32);
void Enemy_RaycastMapB_0_0013D320(s32, Hit *, Vec *, s32, s32);
void Player_CopyPosition_1_00145760(s8 *);
void Player_CopyRotation_1_00145720(s8 *);
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
