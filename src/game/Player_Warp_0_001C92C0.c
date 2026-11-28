#include "common.h"
#include "actor.h"
#include "m2c.h"
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetHeadPos_0_001C93A0;
typedef struct { char p[0x10]; f32 v[4]; } V;
typedef struct { char pad[0x18]; V *v; } T_Player_GetHeadPos_0_001C93A0;
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetPos_1_001C9410;
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetPosB_0_001C9490;
typedef struct { u8 pad[0x18]; s8 *o; } P_Player_SetPosAndGround_0_001C94F0;
typedef struct { char pad[0x518]; u8 *p; } S_Player_SetStartPos_0_001C9630;
typedef struct { char pad[0x18]; f32 *m; } T_Player_SetStartPos_0_001C9630;
typedef struct { u8 pad[0x18]; Vec *m; } S_Player_LoadStartPos_0_001C96F0;
typedef struct { u8 pad[0xF]; s8 b; s16 h[5]; } S1E20;
typedef struct { u8 pad[0x10]; f32 x, y, z; } P_Player_UpdateFrame_0_001C9830;
typedef struct { char pad[0x518]; u8 *p; } S_Player_GetHpS16_0_001C99C0;
typedef struct { char p[4]; s16 h; } U;
typedef struct { char pad[0x518]; u8 *p; } S_Player_IsCrouching_0_001C9A20;
typedef struct { char pad[0x518]; u8 *p; } S_Player_IsMoving_0_001C9A80;
typedef struct { unsigned int : 3; unsigned int f : 1; } B_Player_IsMoving_0_001C9A80;
typedef struct { char pad[0x518]; u8 *p; } S_Player_IsActionLocked_0_001C9AE0;
typedef struct { unsigned int : 14; unsigned int f : 4; } B_Player_IsActionLocked_0_001C9AE0;
extern s8 D_003139A0[];
extern S1E20 *D_00201E20;
extern s32 D_002022B8;
extern P_Player_UpdateFrame_0_001C9830 **D_002022BC;
extern s32 D_004B4C40[];
extern s32 D_002022D8;
void Player_Warp_0_001C92C0(s32 arg0);
void Player_SetPosition_0_001C9320(u8 *arg0);
void Player_GetHeadPos_0_001C93A0(f32 *out);
void Player_GetPos_1_001C9410(f32 *v);
void Player_GetPosB_0_001C9490(f32 *v);
void Player_SetPosAndGround_0_001C94F0(f32 *a0);
void Player_SetStartPos_0_001C9630(f32 *a, f32 *b);
void Player_LoadStartPos_0_001C96F0(s8 *a0);
void Player_UpdateFrame_0_001C9830(void);
s32 Player_IsBusy_0_001C99A0(void);
s16 Player_GetHpS16_0_001C99C0(void);
u8 Player_IsCrouching_0_001C9A20(void);
u32 Player_IsMoving_0_001C9A80(void);
u32 Player_IsActionLocked_0_001C9AE0(void);
s32* Player_GetCameraData_0_001C9B40(void);
s32 Player_GetCameraMode_0_001C9B50(void);
s32 Player_GetBodyState_1_001C9B60(void);
void sceVu0CopyVector(s32, s32);
s32 Game_GetBusy_0_0012C020();

/* Player_Warp_0_001C92C0 */
#define D_002022E4 D_002022E4__as_Player_Warp_0_001C92C0
extern void *D_002022E4__as_Player_Warp_0_001C92C0;

void Player_Warp_0_001C92C0(s32 arg0) {
    s32 temp_3;
    s32 var_3;

    if (D_002022E4 == NULL) {
        var_3 = 0;
    } else {
        temp_3 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_3 == 0) {
            var_3 = 0;
        } else {
            var_3 = temp_3 + 0x180;
        }
    }
    if (var_3 != 0) {
        sceVu0CopyVector(var_3 + 0x3F0, arg0);
    }
}
#undef D_002022E4

/* Player_SetPosition_0_001C9320 */
#define sceVu0CopyVector sceVu0CopyVector__as_Player_SetPosition_0_001C9320
void sceVu0CopyVector__as_Player_SetPosition_0_001C9320(u8 *, s32);
#define D_002022E4 D_002022E4__as_Player_SetPosition_0_001C9320
extern u8 *D_002022E4__as_Player_SetPosition_0_001C9320;

void Player_SetPosition_0_001C9320(u8 *arg0) {
    u8 *var_3;
    s32 temp_3;

    if (D_002022E4 == NULL) {
        var_3 = (u8 *) (NULL);
    } else {
        temp_3 = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (temp_3 == 0) {
            var_3 = (u8 *) (NULL);
        } else {
            var_3 = (u8 *) (temp_3 + 0x180);
        }
    }
    if (var_3 != NULL) {
        sceVu0CopyVector(arg0, M2C_FIELD(var_3, s32 *, 0x18) + 0x10);
    }
    M2C_FIELD(arg0, f32 *, 4) += 220.0f;
}
#undef sceVu0CopyVector
#undef D_002022E4

/* Player_GetHeadPos_0_001C93A0 */
#define D_002022E4 D_002022E4__as_Player_GetHeadPos_0_001C93A0
extern S_Player_GetHeadPos_0_001C93A0 *D_002022E4__as_Player_GetHeadPos_0_001C93A0;
#define sceVu0CopyVector sceVu0CopyVector__as_Player_GetHeadPos_0_001C93A0
void sceVu0CopyVector__as_Player_GetHeadPos_0_001C93A0(f32 *v0, f32 *v1);

void Player_GetHeadPos_0_001C93A0(f32 *out)
{
    T_Player_GetHeadPos_0_001C93A0 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Player_GetHeadPos_0_001C93A0 *)(p + 0x180);
    }
    if (t != NULL)
        sceVu0CopyVector(out, t->v->v);
}
#undef sceVu0CopyVector
#undef D_002022E4

/* Player_GetPos_1_001C9410 */
#define D_002022E4 D_002022E4__as_Player_GetPos_1_001C9410
extern S_Player_GetPos_1_001C9410 *D_002022E4__as_Player_GetPos_1_001C9410;
#define sceVu0CopyVector sceVu0CopyVector__as_Player_GetPos_1_001C9410
void sceVu0CopyVector__as_Player_GetPos_1_001C9410(f32 *v0, f32 *v1);

void Player_GetPos_1_001C9410(f32 *v)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t != NULL)
        sceVu0CopyVector(v, (f32 *)(t + 0x40));
    v[1] += 220.0f;
}
#undef sceVu0CopyVector
#undef D_002022E4

/* Player_GetPosB_0_001C9490 */
#define D_002022E4 D_002022E4__as_Player_GetPosB_0_001C9490
extern S_Player_GetPosB_0_001C9490 *D_002022E4__as_Player_GetPosB_0_001C9490;
#define sceVu0CopyVector sceVu0CopyVector__as_Player_GetPosB_0_001C9490
void sceVu0CopyVector__as_Player_GetPosB_0_001C9490(f32 *v0, f32 *v1);

void Player_GetPosB_0_001C9490(f32 *v)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t != NULL)
        sceVu0CopyVector(v, (f32 *)(t + 0x40));
}
#undef sceVu0CopyVector
#undef D_002022E4

/* Player_SetPosAndGround_0_001C94F0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0CopyVector sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0
void sceVu0CopyVector__as_Player_SetPosAndGround_0_001C94F0(void *, void *);
static inline P_Player_SetPosAndGround_0_001C94F0 *cur_Player_SetPosAndGround_0_001C94F0(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P_Player_SetPosAndGround_0_001C94F0 *)(D_002022E4->unk518 + 0x180);
}

void Player_SetPosAndGround_0_001C94F0(f32 *a0) {
    P_Player_SetPosAndGround_0_001C94F0 *p;
    Vec v;
    p = cur_Player_SetPosAndGround_0_001C94F0();
    if (p == 0) return;
    v.x = 0.0f;
    v.y = WRAP(a0[3]);
    v.z = v.w = 0.0f;
    sceVu0CopyVector(p->o, a0);
    sceVu0CopyVector(p->o + 0x10, a0);
    sceVu0CopyVector(p->o + 0x20, &v);
    sceVu0CopyVector(p->o + 0x30, &v);
    sceVu0CopyVector(p->o + 0x40, D_003139A0);
}
#undef sceVu0CopyVector

/* Player_SetStartPos_0_001C9630 */
#define D_002022E4 D_002022E4__as_Player_SetStartPos_0_001C9630
extern S_Player_SetStartPos_0_001C9630 *D_002022E4__as_Player_SetStartPos_0_001C9630;
#define D_003139A0 D_003139A0__as_Player_SetStartPos_0_001C9630
extern f32 D_003139A0__as_Player_SetStartPos_0_001C9630[];
#define sceVu0CopyVector sceVu0CopyVector__as_Player_SetStartPos_0_001C9630
void sceVu0CopyVector__as_Player_SetStartPos_0_001C9630(f32 *v0, f32 *v1);
void Player_SetStartPos_0_001C9630(f32 *a, f32 *b)
{
    T_Player_SetStartPos_0_001C9630 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Player_SetStartPos_0_001C9630 *)(p + 0x180);
    }
    if (t != NULL) {
        sceVu0CopyVector(t->m, a);
        sceVu0CopyVector(t->m + 4, a);
        sceVu0CopyVector(t->m + 8, b);
        sceVu0CopyVector(t->m + 12, b);
        sceVu0CopyVector(t->m + 16, D_003139A0);
    }
}
#undef sceVu0CopyVector
#undef D_002022E4
#undef D_003139A0

/* Player_LoadStartPos_0_001C96F0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0CopyVector sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0
void sceVu0CopyVector__as_Player_LoadStartPos_0_001C96F0(Vec *, Vec *);
#define D_003139A0 D_003139A0__as_Player_LoadStartPos_0_001C96F0
extern Vec D_003139A0__as_Player_LoadStartPos_0_001C96F0;
static inline S_Player_LoadStartPos_0_001C96F0 *cur_Player_LoadStartPos_0_001C96F0(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (S_Player_LoadStartPos_0_001C96F0 *)(D_002022E4->unk518 + 0x180);
}

void Player_LoadStartPos_0_001C96F0(s8 *a0) {
    Vec *r;
    S_Player_LoadStartPos_0_001C96F0 *s;
    Vec v;
    if (a0 != NULL) {
        r = *(Vec **)(a0 + 0x158);
        s = cur_Player_LoadStartPos_0_001C96F0();
        if (s != NULL) {
            v.x = 0.0f;
            v.y = WRAP(r->w);
            v.w = 0.0f;
            v.z = 0.0f;
            sceVu0CopyVector(&s->m[0], r);
            sceVu0CopyVector(&s->m[1], r);
            sceVu0CopyVector(&s->m[2], &v);
            sceVu0CopyVector(&s->m[3], &v);
            sceVu0CopyVector(&s->m[4], &D_003139A0);
        }
    }
}
#undef sceVu0CopyVector
#undef D_003139A0

/* Player_UpdateFrame_0_001C9830 */
#define D_002022E4 D_002022E4__as_Player_UpdateFrame_0_001C9830
extern s8 *D_002022E4__as_Player_UpdateFrame_0_001C9830;

void Player_UpdateFrame_0_001C9830(void) {
    s8 *v;
    if (D_002022E4 == NULL) {
        v = NULL;
    } else if (M2C_FIELD(D_002022E4, s32 *, 0x518) == 0) {
        v = NULL;
    } else {
        v = (s8 *)(M2C_FIELD(D_002022E4, s32 *, 0x518) + 0x180);
    }
    if (v != NULL) {
        D_00201E20->b = D_002022B8;
        if (D_002022BC != NULL && *D_002022BC != NULL) {
            D_00201E20->h[0] = (s32)(M2C_FIELD(v, f32 *, 0x40) - (*D_002022BC)->x);
            D_00201E20->h[1] = (s32)(M2C_FIELD(v, f32 *, 0x44) - (*D_002022BC)->y);
            D_00201E20->h[2] = (s32)(M2C_FIELD(v, f32 *, 0x48) - (*D_002022BC)->z);
        } else {
            D_00201E20->h[0] = (s32)M2C_FIELD(v, f32 *, 0x40);
            D_00201E20->h[1] = (s32)M2C_FIELD(v, f32 *, 0x44);
            D_00201E20->h[2] = (s32)M2C_FIELD(v, f32 *, 0x48);
        }
        D_00201E20->h[3] = (s32)(4096.0f * M2C_FIELD(M2C_FIELD(v, s8 * *, 0x18), f32 *, 0x20));
        D_00201E20->h[4] = (s32)(4096.0f * M2C_FIELD(M2C_FIELD(v, s8 * *, 0x18), f32 *, 0x24));
    }
}
#undef D_002022E4

/* Player_IsBusy_0_001C99A0 */
s32 Player_IsBusy_0_001C99A0(void) {
    return Game_GetBusy_0_0012C020() != 0;
}

/* Player_GetHpS16_0_001C99C0 */
#define D_002022E4 D_002022E4__as_Player_GetHpS16_0_001C99C0
extern S_Player_GetHpS16_0_001C99C0 *D_002022E4__as_Player_GetHpS16_0_001C99C0;

s16 Player_GetHpS16_0_001C99C0(void)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return (*(U **)(t + 0x390))->h;
}
#undef D_002022E4

/* Player_IsCrouching_0_001C9A20 */
#define D_002022E4 D_002022E4__as_Player_IsCrouching_0_001C9A20
extern S_Player_IsCrouching_0_001C9A20 *D_002022E4__as_Player_IsCrouching_0_001C9A20;

u8 Player_IsCrouching_0_001C9A20(void)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return t[0x3D6] & 1;
}
#undef D_002022E4

/* Player_IsMoving_0_001C9A80 */
#define D_002022E4 D_002022E4__as_Player_IsMoving_0_001C9A80
extern S_Player_IsMoving_0_001C9A80 *D_002022E4__as_Player_IsMoving_0_001C9A80;

u32 Player_IsMoving_0_001C9A80(void)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return ((B_Player_IsMoving_0_001C9A80 *)(t + 0x3A2))->f;
}
#undef D_002022E4

/* Player_IsActionLocked_0_001C9AE0 */
#define D_002022E4 D_002022E4__as_Player_IsActionLocked_0_001C9AE0
extern S_Player_IsActionLocked_0_001C9AE0 *D_002022E4__as_Player_IsActionLocked_0_001C9AE0;

u32 Player_IsActionLocked_0_001C9AE0(void)
{
    u8 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = p + 0x180;
    }
    if (t == NULL)
        return 0;
    return ((B_Player_IsActionLocked_0_001C9AE0 *)(t + 0x39C))->f;
}
#undef D_002022E4

/* Player_GetCameraData_0_001C9B40 */
s32 *Player_GetCameraData_0_001C9B40(void) {
    return D_004B4C40;
}

/* Player_GetCameraMode_0_001C9B50 */
s32 Player_GetCameraMode_0_001C9B50(void) {
    return D_002022D8;
}

/* Player_GetBodyState_1_001C9B60 */
#define D_002022E4 D_002022E4__as_Player_GetBodyState_1_001C9B60
extern void *D_002022E4__as_Player_GetBodyState_1_001C9B60;

s32 Player_GetBodyState_1_001C9B60(void) {
    s32 temp_2;

    if (D_002022E4 == NULL) {
        return 0;
    }
    temp_2 = M2C_FIELD(D_002022E4, s32 *, 0x518);
    if (temp_2 == 0) {
        return 0;
    }
    return temp_2 + 0x180;
}
#undef D_002022E4
