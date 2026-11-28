#include "common.h"
typedef struct { s32 type; s32 a; s32 b; s32 c; f32 x, y, z, w; f32 h; f32 p; f32 r; s32 f; } Msg;
typedef struct { s32 x0; s32 x4; s32 x8; u8 padC[0x10]; f32 x1C; u8 pad20[0xC]; s32 x2C; } Q;
typedef struct { u8 pad[0xE]; u16 xE; } E1;
typedef struct { u8 pad[0x1A]; u16 x1A; } E2;
typedef struct { u8 pad[0xC]; s32 *xC; } E3;
extern u16 D_00317238[];
extern u8 D_00202030;
s32 Event_FindEnemyByMotion_0_00179E50(s32 arg0, s32 arg1);
s32 Event_CheckTalk_0_00179F10(void);
s32 Event_CheckTrigger_0_00179F80(Q *q);
s32 Event_IsPlayerFacing_0_0017A480(char *a0, f32 *a1, f32 *a2);
s32 Enemy_GetTargetHandle_0_0013EDE0(u8 *);
s32 Ent_IsNull0_1_0013EE30(u8 *);
E1* MapObj_GetNodeFlags_0_001B76C0(s32, s32);
E2* MapObj_GetNode_0_001B77A0(s32, s32);
E3* MapObj_Find_1_001B19A0(s32);
s32 Script_SendEvent_2_00166F80(s32, s32, s32);
s8* ActorList_Next_2_001A5460(s32 *);
void ActorList_SetCount_1_001A5440(s8 *);
u32 Enemy_Get5B1b1_1_0013EA70(s8 *);
u8 EnemyScr_Event2014_1_00141610(s8 *);
f32 sqrtf(f32);
void Enemy_GetParamAngles_0_0013DD50(char *, f32 *, f32 *);
void Player_CopyVec_0_00145780(Vec *);
void Enemy_CopyPosition_2_00140470(char *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 cosf(f32);
void Player_GetForwardVector_2_001456B0(Vec *);
void Enemy_GetForwardVector_2_001403D0(char *, Vec *);

/* Event_FindEnemyByMotion_0_00179E50 */
#define ActorList_Next_2_001A5460 ActorList_Next_2_001A5460__as_Event_FindEnemyByMotion_0_00179E50
int ActorList_Next_2_001A5460__as_Event_FindEnemyByMotion_0_00179E50();

s32 Event_FindEnemyByMotion_0_00179E50(s32 arg0, s32 arg1) {
    u8 *var_16;
    s32 temp_3;
    s32 temp_19;
    s32 sp5C;

    sp5C = 0;
    var_16 = (u8 *) (ActorList_Next_2_001A5460(&sp5C));
    if (var_16 != NULL) {
loop_1:
        if (Ent_IsNull0_1_0013EE30(var_16) == 0) {
            temp_19 = Enemy_GetMotionId_0_0013ED20(var_16) & 0xFF;
            temp_3 = Enemy_GetTargetHandle_0_0013EDE0(var_16) & 0xFF;
            if (((temp_19 & 0xFF) == arg1) && ((temp_3 & 0xFF) == arg0)) {
                return (s32) var_16;
            }
        }
        var_16 = (u8 *) (ActorList_Next_2_001A5460(&sp5C));
        if (var_16 == NULL) {
            goto block_7;
        }
        goto loop_1;
    }
block_7:
    return 0;
}
#undef ActorList_Next_2_001A5460

/* Event_CheckTalk_0_00179F10 */
#define Event_CheckTrigger_0_00179F80 Event_CheckTrigger_0_00179F80__as_Event_CheckTalk_0_00179F10
s32 Event_CheckTrigger_0_00179F80__as_Event_CheckTalk_0_00179F10(Msg *);
s32 Event_CheckTalk_0_00179F10(void) {
    Msg msg;
    msg.type = 4;
    msg.r = 0.0f;
    msg.c = -1;
    msg.b = -1;
    msg.a = -1;
    msg.p = 0.0f;
    msg.h = 0.0f;
    msg.w = 0.0f;
    msg.z = 0.0f;
    msg.y = 0.0f;
    msg.x = 0.0f;
    msg.f = (D_00317238[0] & 0x2000) != 0;
    Event_CheckTrigger_0_00179F80(&msg);
    return 0;
}
#undef Event_CheckTrigger_0_00179F80

/* Event_CheckTrigger_0_00179F80 */
#define Event_IsPlayerFacing_0_0017A480 Event_IsPlayerFacing_0_0017A480__as_Event_CheckTrigger_0_00179F80
s32 Event_IsPlayerFacing_0_0017A480__as_Event_CheckTrigger_0_00179F80(s8 *, f32 *, f32 *);
static inline f32 u2f(u32 x) { return x; }
static inline s32 lt(f32 a, u32 b) { s32 r = 0; if (a < u2f(b)) r = 1; return r; }
static inline s32 chk(s32 b, s32 a, s32 bit, s32 off) {
    s32 r = -1;
    if ((MapObj_GetNode_0_001B77A0(b, a)->x1A / 100) & bit) {
        r = Script_SendEvent_2_00166F80(*MapObj_Find_1_001B19A0(b)->xC, a + off, 0);
    }
    return r;
}
static inline s32 h5(Q *q, s32 d) {
    s32 a = q->x4;
    E3 *p = MapObj_Find_1_001B19A0(q->x8);
    if (a == 0) { return d; }
    d = Script_SendEvent_2_00166F80(*p->xC, a, 0);
    return d;
}

s32 Event_CheckTrigger_0_00179F80(Q *q) {
    s32 r = -1;
    f32 f;

    switch (q->x0) {
    case 0:
        f = q->x1C;
        if (lt(f, MapObj_GetNodeFlags_0_001B76C0(q->x8, q->x4)->xE)) {
            r = chk(q->x8, q->x4, 2, 0xC8);
        }
        break;
    case 7:
        if (chk(q->x8, q->x4, 4, 0x190) != -1) r = 1;
        break;
    case 8:
        if (chk(q->x8, q->x4, 8, 0x320) != -1) r = 1;
        break;
    case 1:
        if (chk(q->x8, q->x4, 1, 0x64) != -1) r = 1;
        break;
    case 2:
        if (chk(q->x8, q->x4, 0x10, 0x640) != -1) r = 1;
        break;
    case 3: {
        s32 c = D_00202030;
        if ((c >= 31 && c <= 49) || (q->x4 == 99 && c == 1)) {
            if (chk(q->x8, q->x4, 0x20, 0xC80) != -1) r = 1;
        }
        break;
    }
    case 4: {
        f32 d;
        f32 e;
        s32 it = 0;
        s8 *a;
        for (a = ActorList_Next_2_001A5460(&it); a; a = ActorList_Next_2_001A5460(&it)) {
            ActorList_SetCount_1_001A5440(a);
            if (Event_IsPlayerFacing_0_0017A480(a, &d, &e) && Enemy_Get5B1b1_1_0013EA70(a) && q->x2C && EnemyScr_Event2014_1_00141610(a) == 1) r = 1;
        }
        break;
    }
    case 5: {
        if (h5(q, r) != -1) r = 1;
        break;
    }
    case 6:
        break;
    }
    return r != -1;
}
#undef Event_IsPlayerFacing_0_0017A480

/* Event_IsPlayerFacing_0_0017A480 */
s32 Event_IsPlayerFacing_0_0017A480(char *a0, f32 *a1, f32 *a2) {
    f32 bc;
    f32 b8;
    Vec va0;
    Vec v90;
    Vec v80;
    Vec v70;
    Vec v60;
    f32 len;
    f32 c;
    f32 d;
    u8 r = 0;

    Enemy_GetParamAngles_0_0013DD50(a0, &bc, &b8);
    Player_CopyVec_0_00145780(&va0);
    Enemy_CopyPosition_2_00140470(a0, &v90);
    va0.y = 0.0f;
    v90.y = 0.0f;
    sceVu0SubVector(&v80, &v90, &va0);
    len = sqrtf(sceVu0InnerProduct(&v80, &v80));
    if (a1) *a1 = len;
    if (len < bc) {
        c = cosf(1.0471976f);
        Player_GetForwardVector_2_001456B0(&v70);
        if (!(len <= 0.0f)) {
            v80.x /= len;
            v80.y /= len;
            v80.z /= len;
        }
        d = sceVu0InnerProduct(&v80, &v70);
        if (a2) *a2 = d;
        if (!(d <= c)) {
            c = cosf(1.0471976f);
            v80.x = -v80.x;
            v80.y = -v80.y;
            v80.z = -v80.z;
            Enemy_GetForwardVector_2_001403D0(a0, &v60);
            if (!(sceVu0InnerProduct(&v80, &v60) <= c)) r = 1;
        }
    }
    return r;
}
