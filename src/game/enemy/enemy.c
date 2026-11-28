#include "actor.h"
#include "common.h"
#include "m2c.h"
#include "game/enemy.h"
typedef struct { u8 pad[0x120]; Flags8 x120; } C_Enemy_UpdateBlend5CC_0_0013DA20;
typedef struct { u8 pad[0x190]; C_Enemy_UpdateBlend5CC_0_0013DA20 *x190; } B_Enemy_UpdateBlend5CC_0_0013DA20;
typedef struct { u8 pad[0x5B8]; f32 a; f32 b; } O;
typedef struct { char pad[0x4B4]; s32 v[1]; } S_Enemy_UpdateBlend5CC_0_0013DA20;
typedef struct { char pad[0x2A]; u8 idx; } Ent_Enemy_GetPartFlag_0_0013DCC0;
typedef struct { char pad[0x39A]; u8 b[0x11A]; Ent_Enemy_GetPartFlag_0_0013DCC0 *ents[1]; } Obj_Enemy_GetPartFlag_0_0013DCC0;
typedef struct { char pad[0x4A8]; int **q; } Hold;
typedef struct { u8 b:7; u8 flag:1; } BF;
typedef struct { char pad[0x24]; s16 h; } Ent_Enemy_GetPartAngle_1_0013E0C0;
typedef struct { char pad[0x4B4]; Ent_Enemy_GetPartAngle_1_0013E0C0 *ents[1]; } Obj_Enemy_GetPartAngle_1_0013E0C0;
typedef struct { u8 pad[0x1A]; u16 val; u8 pad2[0x54-0x1C]; } Ent_Enemy_GetCurrentParamIdx_0_0013E110;
typedef struct { u8 pad[0x13C]; Ent_Enemy_GetCurrentParamIdx_0_0013E110 *ents; } Tbl;
typedef struct { Tbl *tbl; } Hdr;
typedef struct { char pad[4]; f32 v; } C_Enemy_Get60B_1_0013E240_;
typedef struct { char pad[0x198]; C_Enemy_Get60B_1_0013E240_ *c; } B_Enemy_Get60B_1_0013E240_;
typedef struct { char pad[0x518]; B_Enemy_Get60B_1_0013E240_ *b; } Q;
typedef struct { char pad[0x5B2]; unsigned int : 5; unsigned int on : 1; unsigned int mode : 2; char p[0x29]; f32 v; } Obj_Enemy_Get60B_1_0013E240;
typedef struct { char pad[0x6B4]; s16 v[1]; } S_Enemy_Get60B_1_0013E240;
typedef struct { char pad[0x5B0]; u8 sel : 1; char pad2[0x103]; u16 v[2]; } S_Enemy_GetSelPartValue_1_0013E410;
typedef struct {
    char pad[0x5B4];
    unsigned char : 6;
    unsigned char f : 1;
} Obj_Enemy_Set5B4b6_1_0013E490;
typedef struct {
    char pad[0x5B4];
    unsigned char : 5;
    unsigned char f : 1;
} Obj_Enemy_Get60B_1_0013E240_;
typedef struct {
    u8 pad[0x5B4];
    u8 a0:7;
    u8 a7:1;
    u8 lo:4;
    u8 mid:2;
    u8 hi:2;
} S_Enemy_Get60B_1_0013E240_;
typedef struct {
    char pad[0x5B4];
    unsigned char : 4;
    unsigned char f : 1;
} Obj_Enemy_Set5B4b4_1_0013E5F0;
typedef struct {
    char pad[0x5B1];
    unsigned char a0 : 1, a1 : 1, a2 : 1, a3 : 1;
    char pad2[2];
    unsigned char b0 : 1, b1 : 1, b2 : 1, b3 : 1;
} Obj_Enemy_Set5B4b3_1_0013E620;
typedef struct {
    char pad[0x5B4];
    unsigned char : 2;
    unsigned char f : 1;
} Obj_Enemy_Set5B4b4_1_0013E5F0_;
typedef struct {
    char pad[0x5B4];
    unsigned char : 1;
    unsigned char f : 1;
} Obj_Enemy_Get60B_1_0013E240__;
typedef struct {
    char pad[0x5B1];
    unsigned char a0 : 1, a1 : 1, a2 : 1, a3 : 1;
    char pad2[2];
    unsigned char b0 : 1, b1 : 1, b2 : 1, b3 : 1;
} Obj_Enemy_Get5B4b1_1_0013E690;
typedef struct {
    char pad[0x5B4];
    unsigned char f : 1;
} Obj_Enemy_Set5B4b0_1_0013E6A0;
typedef struct {
    char pad[0x5B3];
    unsigned char : 7;
    unsigned char f : 1;
} Obj_Enemy_Set5B3b7_1_0013E6D0;
typedef struct {
    char pad[0x5B6];
    unsigned char : 1;
    unsigned char f : 1;
} Obj_Enemy_Get60B_1_0013E240___;
typedef struct {
    char pad[0x5B3];
    unsigned char : 6;
    unsigned char f : 1;
} Obj_Enemy_Set5B3b6_1_0013E710;
typedef struct {
    char pad[0x5B2];
    unsigned char : 6;
    unsigned char f : 2;
} Obj_Enemy_Set5B2b6w2_1_0013E730;
typedef struct {
    char pad[0x5B2];
    unsigned char : 5;
    unsigned char f : 1;
} Obj_Enemy_Set5B3b6_1_0013E710_;
typedef struct {
    char pad[0x5B2];
    unsigned char : 4;
    unsigned char f : 1;
} Obj_Enemy_Set5B2b4_1_0013E790;
typedef struct {
    char pad[0x5B3];
    unsigned char : 3;
    unsigned char f : 1;
} Obj_Enemy_Set5B3b3_1_0013E7C0;
typedef struct { char pad[0x5B3]; unsigned char : 2; unsigned char f : 1; char p[0xC]; f32 t; } Obj_Enemy_Get60B_1_0013E240____;
typedef struct {
    char pad[0x5B2];
    unsigned char : 2;
    unsigned char f : 1;
} Obj_Enemy_Set5B2b2_1_0013E840;
typedef struct {
    char pad[0x5B2];
    unsigned char : 1;
    unsigned char f : 1;
} Obj_Enemy_Set5B2b1_1_0013E860;
typedef struct {
    char pad[0x5B2];
    unsigned char f : 1;
} Obj_Enemy_Set5B2b2_1_0013E840_;
typedef struct {
    char pad[0x5B1];
    unsigned char : 7;
    unsigned char f : 1;
} Obj_Enemy_Set5B1b7_1_0013E8C0;
typedef struct {
    char pad[0x5B1];
    unsigned char : 6;
    unsigned char f : 1;
} Obj_Enemy_Set5B1b6_1_0013E8F0;
typedef struct {
    char pad[0x5B1];
    unsigned char : 5;
    unsigned char f : 1;
} Obj_Enemy_Get60B_1_0013E240_____;
typedef struct {
    char pad[0x5B5];
    unsigned char : 7;
    unsigned char f : 1;
} Obj_Enemy_Set5B5b7_1_0013E950;
typedef struct { char pad[0x5B1]; unsigned char : 4; unsigned char f : 1; unsigned char lock : 1; } Obj_Enemy_Set5B1b4IfUnlocked_0_0013E980;
typedef struct { char pad[0x5B1]; unsigned char : 3; unsigned char f : 1; unsigned char : 1; unsigned char lock : 1; } Obj_Enemy_Set5B5b7_1_0013E950_;
typedef struct {
    char pad[0x5B1];
    unsigned char : 2;
    unsigned char f : 1;
} Obj_Enemy_Get60B_1_0013E240______;
typedef struct {
    char pad[0x5B1];
    unsigned char a0 : 1, a1 : 1, a2 : 1, a3 : 1;
    char pad2[2];
    unsigned char b0 : 1, b1 : 1, b2 : 1, b3 : 1;
} Obj_Enemy_Get5B1b2_1_0013EA40;
typedef struct {
    char pad[0x5B1];
    unsigned char : 1;
    unsigned char f : 1;
} Obj_Enemy_Set5B1b1_1_0013EA50;
typedef struct {
    char pad[0x5B6];
    unsigned char : 4;
    unsigned char f : 1;
} Obj_Enemy_Set5B6b4_1_0013EA80;
typedef struct {
    char pad[0x5B6];
    unsigned char : 3;
    unsigned char f : 1;
} Obj_Enemy_Get60B_1_0013E240_______;
typedef struct {
    char pad[0x5B6];
    unsigned char : 2;
    unsigned char f : 1;
} Obj_Enemy_Set5B6b2_1_0013EAE0;
typedef struct {
    char pad[0x5B1];
    unsigned char f : 1;
} Obj_Enemy_Set5B1b0_1_0013EB10;
typedef struct {
    char pad[0x5B0];
    unsigned char : 7;
    unsigned char f : 1;
} Obj_Enemy_Set5B6b2_1_0013EAE0_;
typedef struct {
    char pad[0x5B0];
    unsigned char : 6;
    unsigned char f : 1;
} Obj_Enemy_Set5B0b6_1_0013EB70;
typedef struct { char pad[0x5B0]; unsigned char : 3; unsigned char a : 3; char p[2]; unsigned char : 4; unsigned char b : 2; } Obj_Enemy_SetMode_0_0013EBA0;
typedef struct {
    char pad[0x5B0];
    unsigned char : 2;
    unsigned char f : 1;
} Obj_Enemy_Get60B_1_0013E240________;
typedef struct {
    char pad[0x5B0];
    unsigned char : 1;
    unsigned char f : 1;
} Obj_Enemy_Set5B0b1_1_0013EC10;
typedef struct {
    char pad[0x5B0];
    unsigned char f : 1;
} Obj_Enemy_Set5B0b0_1_0013EC30;
typedef struct { char pad[0x2D]; unsigned char : 1; unsigned int f : 1; } Ent;
typedef struct { char pad[0x4B4]; Ent *ents[1]; } Obj_Enemy_Set5B0b1_1_0013EC10_;
extern u8 D_00222A53[];
void Enemy_UpdateLerp_0_0013DA90(O *o, f32 f);
s32 Enemy_GetPart_1_0013DC70(void *arg0, s32 arg1);
s32 Enemy_GetPartValue_1_0013DCA0(S_Enemy_UpdateBlend5CC_0_0013DA20 *s, u8 i);
u8 Enemy_GetPartFlag_0_0013DCC0(Obj_Enemy_GetPartFlag_0_0013DCC0 *o, u8 i);
int* Enemy_GetModelData_1_0013DCE0(Hold *h);
s32 Enemy_GetModelParam174_1_0013DD10(void *arg0);
f32 Enemy_GetParam298_1_0013DD40(void *arg0);
void Enemy_GetParamAngles_0_0013DD50(s8 *a0, f32 *a1, f32 *a2);
f32 Enemy_GetTurnRateRad_1_0013DE20(void *arg0);
s32 Enemy_GetParamPtr290_1_0013DE50(void *arg0);
s32 Enemy_GetParamPtr270_1_0013DE60(void *arg0);
void Enemy_ScaleStats_0_0013DE70(u8 *obj, u16 *in, u16 *out);
s32 Enemy_GetParamPtr210_1_0013E060(void *arg0);
s32 Enemy_GetParamPtr10_1_0013E070(void *arg0);
u8 Enemy_GetParamByte6_1_0013E080(void *arg0);
void Enemy_PlayModelAnim_0_0013E090(void *arg0, s32 arg1);
s32 Enemy_GetModelField8_0_0013E0B0(void *arg0);
s32 Enemy_GetPartAngle_1_0013E0C0(Obj_Enemy_GetPartAngle_1_0013E0C0 *o, u8 i);
u16 Enemy_GetCurrentParamIdx_0_0013E110(s8 *arg0);
u8 Ent_GetTypeByte_1_0013E220(u16 *p);
u8 Enemy_Get60B_1_0013E240(void *arg0);
void Enemy_Set60B_1_0013E250(void *arg0, s8 arg1);
s8 Enemy_Get609_1_0013E260(void *arg0);
s8 Enemy_Get60A_1_0013E270(void *arg0);
void Enemy_Set60A_1_0013E280(void *arg0, s8 arg1);
s8 Enemy_Get608_1_0013E290(void *arg0);
void Enemy_Set608_1_0013E2A0(void *arg0, s8 arg1);
s32 Enemy_CanAct_0_0013E2B0(void *arg0);
void Enemy_SyncPosition_0_0013E370(Obj_Enemy_Get60B_1_0013E240 *o);
f32 Enemy_GetHeightAboveFloor_0_0013E3C0(void *arg0);
void Enemy_SetPartValue_1_0013E3F0(S_Enemy_Get60B_1_0013E240 *s, u8 i, s16 v);
u16 Enemy_GetSelPartValue_1_0013E410(S_Enemy_GetSelPartValue_1_0013E410 *s);
void Enemy_Set5D8_1_0013E430(void *arg0, f32 fparg0);
f32 Enemy_Get5CC_1_0013E440(void *arg0);
void Enemy_Set5C8_1_0013E450(void *arg0, f32 fparg0);
f32 Enemy_Get5C4_1_0013E460(void *arg0);
void Enemy_Set5C0_1_0013E470(void *arg0, f32 fparg0);
void Enemy_Set5B8_1_0013E480(void *arg0, f32 fparg0);
void Enemy_Set5B4b6_1_0013E490(Obj_Enemy_Set5B4b6_1_0013E490 *o, int v);
void Enemy_Set5B4b5_1_0013E4B0(Obj_Enemy_Get60B_1_0013E240_ *o, int v);
u64 Enemy_Get5B4b5_1_0013E4D0(void *arg0);
u64 Enemy_Get5B5b4w2_1_0013E4E0(void *arg0);
void Enemy_AddStatusFlags_1_0013E4F0(S_Enemy_Get60B_1_0013E240_ *s, u8 a);
s32 Enemy_Get5B5mF_1_0013E5E0(void *arg0);
void Enemy_Set5B4b4_1_0013E5F0(Obj_Enemy_Set5B4b4_1_0013E5F0 *o, int v);
u64 Enemy_Get5B4b4_1_0013E610(void *arg0);
void Enemy_Set5B4b3_1_0013E620(Obj_Enemy_Set5B4b3_1_0013E620 *o, int v);
void Enemy_Set5B4b2_1_0013E640(Obj_Enemy_Set5B4b4_1_0013E5F0_ *o, int v);
u64 Enemy_Get5B4b2_1_0013E660(void *arg0);
void Enemy_Set5B4b1_1_0013E670(Obj_Enemy_Get60B_1_0013E240__ *o, int v);
s32 Enemy_Get5B4b1_1_0013E690(Obj_Enemy_Get5B4b1_1_0013E690 *o);
void Enemy_Set5B4b0_1_0013E6A0(Obj_Enemy_Set5B4b0_1_0013E6A0 *o, int v);
s32 Enemy_Get5B4m1_1_0013E6C0(void *arg0);
void Enemy_Set5B3b7_1_0013E6D0(Obj_Enemy_Set5B3b7_1_0013E6D0 *o, int v);
void Enemy_Set5B6b1_1_0013E6F0(Obj_Enemy_Get60B_1_0013E240___ *o, int v);
void Enemy_Set5B3b6_1_0013E710(Obj_Enemy_Set5B3b6_1_0013E710 *o, int v);
void Enemy_Set5B2b6w2_1_0013E730(Obj_Enemy_Set5B2b6w2_1_0013E730 *o, int v);
u64 Enemy_Get5B2b6w2_1_0013E750(void *arg0);
void Enemy_Set5B2b5_1_0013E760(Obj_Enemy_Set5B3b6_1_0013E710_ *o, int v);
u64 Enemy_Get5B2b5_1_0013E780(void *arg0);
void Enemy_Set5B2b4_1_0013E790(Obj_Enemy_Set5B2b4_1_0013E790 *o, int v);
u64 Enemy_Get5B2b4_1_0013E7B0(void *arg0);
void Enemy_Set5B3b3_1_0013E7C0(Obj_Enemy_Set5B3b3_1_0013E7C0 *o, int v);
void Enemy_SetStateResetTimer_1_0013E7E0(Obj_Enemy_Get60B_1_0013E240____ *o, u8 v);
u64 Enemy_Get5B3b2_1_0013E820(void *arg0);
u64 Enemy_Get5B2b3_1_0013E830(void *arg0);
void Enemy_Set5B2b2_1_0013E840(Obj_Enemy_Set5B2b2_1_0013E840 *o, int v);
void Enemy_Set5B2b1_1_0013E860(Obj_Enemy_Set5B2b1_1_0013E860 *o, int v);
u64 Enemy_Get5B2b1_1_0013E880(void *arg0);
void Enemy_Set5B2b0_1_0013E890(Obj_Enemy_Set5B2b2_1_0013E840_ *o, int v);
s32 Enemy_Get5B2m1_1_0013E8B0(void *arg0);
void Enemy_Set5B1b7_1_0013E8C0(Obj_Enemy_Set5B1b7_1_0013E8C0 *o, int v);
u64 Enemy_Get5B1b7_1_0013E8E0(void *arg0);
void Enemy_Set5B1b6_1_0013E8F0(Obj_Enemy_Set5B1b6_1_0013E8F0 *o, int v);
u64 Enemy_Get5B1b6_1_0013E910(void *arg0);
void Enemy_Set5B1b5_1_0013E920(Obj_Enemy_Get60B_1_0013E240_____ *o, int v);
u64 Enemy_Get5B1b5_1_0013E940(void *arg0);
void Enemy_Set5B5b7_1_0013E950(Obj_Enemy_Set5B5b7_1_0013E950 *o, int v);
u64 Enemy_Get5B5b7_1_0013E970(void *arg0);
void Enemy_Set5B1b4IfUnlocked_0_0013E980(Obj_Enemy_Set5B1b4IfUnlocked_0_0013E980 *o, int v);
u64 Enemy_Get5B1b4_1_0013E9C0(void *arg0);
void Enemy_Set5B1b3IfUnlocked_1_0013E9D0(Obj_Enemy_Set5B5b7_1_0013E950_ *o, int v);
u64 Enemy_Get5B1b3_1_0013EA10(void *arg0);
void Enemy_Set5B1b2_1_0013EA20(Obj_Enemy_Get60B_1_0013E240______ *o, int v);
s32 Enemy_Get5B1b2_1_0013EA40(Obj_Enemy_Get5B1b2_1_0013EA40 *o);
void Enemy_Set5B1b1_1_0013EA50(Obj_Enemy_Set5B1b1_1_0013EA50 *o, int v);
u64 Enemy_Get5B1b1_1_0013EA70(void *arg0);
void Enemy_Set5B6b4_1_0013EA80(Obj_Enemy_Set5B6b4_1_0013EA80 *o, int v);
u64 Enemy_Get5B6b4_1_0013EAA0(void *arg0);
void Enemy_Set5B6b3_1_0013EAB0(Obj_Enemy_Get60B_1_0013E240_______ *o, int v);
u64 Enemy_Get5B6b3_1_0013EAD0(void *arg0);
void Enemy_Set5B6b2_1_0013EAE0(Obj_Enemy_Set5B6b2_1_0013EAE0 *o, int v);
u64 Enemy_Get5B6b2_1_0013EB00(void *arg0);
void Enemy_Set5B1b0_1_0013EB10(Obj_Enemy_Set5B1b0_1_0013EB10 *o, int v);
s32 Enemy_Get5B1m1_1_0013EB30(void *arg0);
void Enemy_Set5B0b7_1_0013EB40(Obj_Enemy_Set5B6b2_1_0013EAE0_ *o, int v);
u64 Enemy_Get5B0b7_1_0013EB60(void *arg0);
void Enemy_Set5B0b6_1_0013EB70(Obj_Enemy_Set5B0b6_1_0013EB70 *o, int v);
u64 Enemy_Get5B0b6_1_0013EB90(void *arg0);
void Enemy_SetMode_0_0013EBA0(Obj_Enemy_SetMode_0_0013EBA0 *o, u8 v);
void Enemy_Set5B0b2_1_0013EBF0(Obj_Enemy_Get60B_1_0013E240________ *o, int v);
void Enemy_Set5B0b1_1_0013EC10(Obj_Enemy_Set5B0b1_1_0013EC10 *o, int v);
void Enemy_Set5B0b0_1_0013EC30(Obj_Enemy_Set5B0b0_1_0013EC30 *o, int v);
s32 Enemy_Get5B0m1_1_0013EC50(void *arg0);
u32 Enemy_GetPartFlagU_0_0013EC60(Obj_Enemy_Set5B0b1_1_0013EC10_ *o, u8 i);
void EnemyScr_Event2022_1_00140DE0(Actor *);
f32 cosf(f32);
void EnemyScr_Event200DGetStats_1_00142090(void *, void *, void *, f32 *, f32 *);

/* Enemy_UpdateBlend5CC_0_0013DA20 */
/* Enemy_UpdateBlend5CC_0_0013DA20 */
void Enemy_UpdateBlend5CC_0_0013DA20(Actor *a, f32 d) {
    f32 v = a->unk5CC;
    if (((B_Enemy_UpdateBlend5CC_0_0013DA20 *)a->unk518)->x190->x120.f.b1) {
        v += d;
        if (!(v < 1.0f)) v = 1.0f;
    } else if (!(v <= d)) {
        v -= d;
    } else {
        v = 0.0f;
    }
    a->unk5CC = v;
}

/* Enemy_UpdateLerp_0_0013DA90 */
void Enemy_UpdateLerp_0_0013DA90(O *o, f32 f) {
    f32 b;
    f32 a;
    a = o->a;
    b = o->b;
    if (a != b) {
        if (a > b) {
            b += f / 0.5f;
            if (!(b <= a)) b = a;
        } else {
            b -= f / 0.5f;
            if (b < a) b = a;
        }
        o->b = b;
    }
}

/* Enemy_UpdateTimer5C0_0_0013DB10 */
void Enemy_UpdateTimer5C0_0_0013DB10(Actor *a, f32 dt) {
    f32 t;
    if (a->flags5B4.f.b3) {
        dt /= a->unk5C8;
        t = a->unk5C0;
        t += dt;
        if (t >= 1.0f) {
            t = 1.0f;
            a->flags5B4.f.b3 = 0;
        }
        a->unk5C0 = t;
    }
}

/* Enemy_UpdateDeath_0_0013DB80 */
void Enemy_UpdateDeath_0_0013DB80(Actor *a, f32 dt) {
    f32 t;
    if (a->flags5B3.f.b3) {
        a->flags5B2.f.b3 = 1;
    }
    if (a->flags5B3.f.b2) {
        t = a->unk5C0;
        if (t > dt) t = t - dt; else t = 0.0f;
        a->unk5C0 = t;
        if (t == 0.0f && !a->flags5B3.f.b3) {
            EnemyScr_Event2022_1_00140DE0(a);
            a->flags5B3.f.b3 = 1;
        }
        a->flags5B4.f.b3 = 0;
    }
}

/* Enemy_GetPart_1_0013DC70 */
s32 Enemy_GetPart_1_0013DC70(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 0x51C) + ((arg1 & 0xFF) * 0x170);
}

/* Enemy_GetPartValue_1_0013DCA0 */
s32 Enemy_GetPartValue_1_0013DCA0(S_Enemy_UpdateBlend5CC_0_0013DA20 *s, u8 i)
{
    return s->v[i];
}

/* Enemy_GetPartFlag_0_0013DCC0 */
u8 Enemy_GetPartFlag_0_0013DCC0(Obj_Enemy_GetPartFlag_0_0013DCC0 *o, u8 i)
{
    return o->b[o->ents[i]->idx];
}

/* Enemy_GetModelData_1_0013DCE0 */
int *Enemy_GetModelData_1_0013DCE0(Hold *h)
{
    if (h->q)
        return (int *)((char *)*h->q + 0x10);
    return 0;
}

/* Enemy_GetModelParam174_1_0013DD10 */
s32 Enemy_GetModelParam174_1_0013DD10(void *arg0) {
    void **temp_2;

    temp_2 = M2C_FIELD(arg0, void ***, 0x4A8);
    if (temp_2 != NULL) {
        return M2C_FIELD(*temp_2, s32 *, 0x174);
    }
    return 0;
}

/* Enemy_GetParam298_1_0013DD40 */
f32 Enemy_GetParam298_1_0013DD40(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x4B0), f32 *, 0x298);
}

/* Enemy_GetParamAngles_0_0013DD50 */
static inline f32 u2f(u32 x) { return x; }

void Enemy_GetParamAngles_0_0013DD50(s8 *a0, f32 *a1, f32 *a2) {
    s8 *p = *(s8 **)(a0 + 0x4B0) + 0x270;
    if (a1) {
        *a1 = u2f(*(u16 *)(p + 0x10));
    }
    if (a2) {
        *a2 = cosf(3.1415927f * (u2f(*(u16 *)(p + 0x12)) / 180.0f));
    }
}

/* Enemy_GetTurnRateRad_1_0013DE20 */
f32 Enemy_GetTurnRateRad_1_0013DE20(void *arg0) {
    return 3.1415927f * (M2C_FIELD(M2C_FIELD(arg0, void **, 0x4B0), f32 *, 0x2A0) / 180.0f);
}

/* Enemy_GetParamPtr290_1_0013DE50 */
s32 Enemy_GetParamPtr290_1_0013DE50(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x4B0) + 0x290;
}

/* Enemy_GetParamPtr270_1_0013DE60 */
s32 Enemy_GetParamPtr270_1_0013DE60(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x4B0) + 0x270;
}

/* Enemy_ScaleStats_0_0013DE70 */
void Enemy_ScaleStats_0_0013DE70(u8 *obj, u16 *in, u16 *out) {
    f32 sx;
    f32 sy;
    u8 flag;
    u8 i;
    f32 one = 1.0f;
    u16 *p, *q;
    flag = ((BF *)(obj + 0x5B3))->flag;
    sx = 1.0f;
    sy = 1.0f;
    EnemyScr_Event200DGetStats_1_00142090(obj, NULL, NULL, &sx, &sy);
    for (i = 0; i < 4; i++) {
        u16 *p = &in[i];
        out[i] = (u32)(one * (sx * (f32)(u32)p[0]));
        if (flag) out[i] += p[8];
    }
    for (i = 4; i < 8; i++) {
        u16 *p = &in[i];
        out[i] = (u32)(one * (sy * (f32)(u32)p[0]));
        if (flag) out[i] += p[8];
    }
}

/* Enemy_GetParamPtr210_1_0013E060 */
s32 Enemy_GetParamPtr210_1_0013E060(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x4B0) + 0x210;
}

/* Enemy_GetParamPtr10_1_0013E070 */
s32 Enemy_GetParamPtr10_1_0013E070(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x4B0) + 0x10;
}

/* Enemy_GetParamByte6_1_0013E080 */
u8 Enemy_GetParamByte6_1_0013E080(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x4B0), u8 *, 6);
}

/* Enemy_PlayModelAnim_0_0013E090 */
void Enemy_PlayModelAnim_0_0013E090(void *arg0, s32 arg1) {
    Mdl_GetMotionLength_0_00173F70(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void ***, 0x18C), arg1 & 0xFFFF);
}

/* Enemy_GetModelField8_0_0013E0B0 */
s32 Enemy_GetModelField8_0_0013E0B0(void *arg0) {
    return M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void **, 0x1A8), s32 *, 8);
}

/* Enemy_GetPartAngle_1_0013E0C0 */
s32 Enemy_GetPartAngle_1_0013E0C0(Obj_Enemy_GetPartAngle_1_0013E0C0 *o, u8 i)
{
    s16 v;
    if (i == 0xFF)
        return 0x40;
    v = o->ents[i]->h;
    if (v == -1)
        return 0x40;
    return v;
}

/* Enemy_GetCurrentParamIdx_0_0013E110 */
u16 Enemy_GetCurrentParamIdx_0_0013E110(s8 *arg0) {
    u8 hi8;
    u8 flag;
    u8 lo;
    s32 hi;
    u16 idx;
    Hdr *pp;
    Ent_Enemy_GetCurrentParamIdx_0_0013E110 *q;
    flag = ((u64)((s64)*(u8 *)(arg0 + 0x5A1) << 0x3C) >> 0x3F);
    if (flag) hi = *(u16 *)(arg0 + 0x712);
    else { pp = *(Hdr **)(arg0 + 0x4A8); if (pp) hi = *(s32 *)pp->tbl; else hi = 0; }
    hi8 = hi;
    if (flag) lo = *(u16 *)(arg0 + 0x710) % 100;
    else {
        pp = *(Hdr **)(arg0 + 0x4A8); idx = *(u16 *)(arg0 + 0x4AC);
        q = pp ? &pp->tbl->ents[idx] : NULL;
        if (q) lo = q->val % 100; else lo = *(u16 *)(arg0 + 0x710) % 100;
    }
    return lo + hi8 * 100;
}

/* Ent_GetTypeByte_1_0013E220 */
u8 Ent_GetTypeByte_1_0013E220(u16 *p) { return p ? *p : 0xFF; }

/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
/* Enemy_Get60B_1_0013E240 */
u8 Enemy_Get60B_1_0013E240(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x60B);
}

/* Enemy_Set60B_1_0013E250 */
void Enemy_Set60B_1_0013E250(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x60B) = arg1;
}

/* Enemy_Get609_1_0013E260 */
s8 Enemy_Get609_1_0013E260(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0x609);
}

/* Enemy_Get60A_1_0013E270 */
s8 Enemy_Get60A_1_0013E270(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0x60A);
}

/* Enemy_Set60A_1_0013E280 */
void Enemy_Set60A_1_0013E280(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x60A) = arg1;
}

/* Enemy_Get608_1_0013E290 */
s8 Enemy_Get608_1_0013E290(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0x608);
}

/* Enemy_Set608_1_0013E2A0 */
void Enemy_Set608_1_0013E2A0(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x608) = arg1;
}

/* Enemy_CanAct_0_0013E2B0 */
s32 Enemy_CanAct_0_0013E2B0(void *arg0) {
    if (((u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B3) << 0x3C) >> 0x3F) != 0) {
        return 0;
    }
    if (((u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B2) << 0x3C) >> 0x3F) != 0) {
        return 0;
    }
    if (((u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B6) << 0x3A) >> 0x3F) != 0) {
        return 0;
    }
    if ((((u64) ((s64) (*D_00222A53) << 0x3C) >> 0x3F) != 0) && (M2C_FIELD(arg0, f32 *, 0x5D4) == 0.0f) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x4B0), f32 *, 0x290) == 0.0f)) {
        return 0;
    }
    return 1;
}

/* Enemy_SyncPosition_0_0013E370 */
void Enemy_SyncPosition_0_0013E370(Obj_Enemy_Get60B_1_0013E240 *o)
{
    if (o->mode < 2) {
        if (o->on)
            o->v = ((Q *)o)->b->c->v;
    } else {
        o->v = ((Q *)o)->b->c->v;
    }
}

/* Enemy_GetHeightAboveFloor_0_0013E3C0 */
f32 Enemy_GetHeightAboveFloor_0_0013E3C0(void *arg0) {
    f32 var_f0;

    var_f0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void **, 0x198), f32 *, 4) - M2C_FIELD(arg0, f32 *, 0x5DC);
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    return var_f0;
}

/* Enemy_SetPartValue_1_0013E3F0 */
void Enemy_SetPartValue_1_0013E3F0(S_Enemy_Get60B_1_0013E240 *s, u8 i, s16 v)
{
    s->v[i] = v;
}

/* Enemy_GetSelPartValue_1_0013E410 */
u16 Enemy_GetSelPartValue_1_0013E410(S_Enemy_GetSelPartValue_1_0013E410 *s)
{
    return s->v[s->sel];
}

/* Enemy_Set5D8_1_0013E430 */
void Enemy_Set5D8_1_0013E430(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x5D8) = fparg0;
}

/* Enemy_Get5CC_1_0013E440 */
f32 Enemy_Get5CC_1_0013E440(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x5CC);
}

/* Enemy_Set5C8_1_0013E450 */
void Enemy_Set5C8_1_0013E450(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x5C8) = fparg0;
}

/* Enemy_Get5C4_1_0013E460 */
f32 Enemy_Get5C4_1_0013E460(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x5C4);
}

/* Enemy_Set5C0_1_0013E470 */
void Enemy_Set5C0_1_0013E470(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x5C0) = fparg0;
}

/* Enemy_Set5B8_1_0013E480 */
void Enemy_Set5B8_1_0013E480(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x5B8) = fparg0;
}

/* Enemy_Set5B4b6_1_0013E490 */
/* Bitfield setter on an object's flag byte at 0x5B4. */


void Enemy_Set5B4b6_1_0013E490(Obj_Enemy_Set5B4b6_1_0013E490 *o, int v)
{
    o->f = v;
}

/* Enemy_Set5B4b5_1_0013E4B0 */
/* Bitfield setter on an object's flag byte at 0x5B4. */


void Enemy_Set5B4b5_1_0013E4B0(Obj_Enemy_Get60B_1_0013E240_ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B4b5_1_0013E4D0 */
u64 Enemy_Get5B4b5_1_0013E4D0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B4) << 0x3A) >> 0x3F;
}

/* Enemy_Get5B5b4w2_1_0013E4E0 */
u64 Enemy_Get5B5b4w2_1_0013E4E0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B5) << 0x3A) >> 0x3E;
}

/* Enemy_AddStatusFlags_1_0013E4F0 */
void Enemy_AddStatusFlags_1_0013E4F0(S_Enemy_Get60B_1_0013E240_ *s, u8 a) {
    s->lo |= a;
    if (a) s->a7 = 1;
    if ((u8)a & 1) s->mid = 0;
    if ((u8)a & 2) s->mid = 1;
    if ((u8)a & 4) s->mid = 2;
    if ((u8)a & 8) s->mid = 3;
}

/* Enemy_Get5B5mF_1_0013E5E0 */
s32 Enemy_Get5B5mF_1_0013E5E0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x5B5) & 0xF;
}

/* Enemy_Set5B4b4_1_0013E5F0 */
/* Enemy_Set5B4b4_1_0013E5F0 */
/* Enemy_Set5B4b4_1_0013E5F0 */
/* Enemy_Set5B4b4_1_0013E5F0 */
/* Enemy_Set5B4b4_1_0013E5F0 */
/* Bitfield setter on an object's flag byte at 0x5B4. */


void Enemy_Set5B4b4_1_0013E5F0(Obj_Enemy_Set5B4b4_1_0013E5F0 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B4b4_1_0013E610 */
u64 Enemy_Get5B4b4_1_0013E610(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B4) << 0x3B) >> 0x3F;
}

/* Enemy_Set5B4b3_1_0013E620 */
/* Bitfield getters and setter on an object's flag bytes at 0x5B1 and 0x5B4. */


void Enemy_Set5B4b3_1_0013E620(Obj_Enemy_Set5B4b3_1_0013E620 *o, int v)
{
    o->b3 = v;
}

/* Enemy_Set5B4b2_1_0013E640 */
/* Bitfield setter on an object's flag byte at 0x5B4. */


void Enemy_Set5B4b2_1_0013E640(Obj_Enemy_Set5B4b4_1_0013E5F0_ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B4b2_1_0013E660 */
u64 Enemy_Get5B4b2_1_0013E660(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B4) << 0x3D) >> 0x3F;
}

/* Enemy_Set5B4b1_1_0013E670 */
/* Bitfield setter on an object's flag byte at 0x5B4. */


void Enemy_Set5B4b1_1_0013E670(Obj_Enemy_Get60B_1_0013E240__ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B4b1_1_0013E690 */
/* Bitfield getters and setter on an object's flag bytes at 0x5B1 and 0x5B4. */


int Enemy_Get5B4b1_1_0013E690(Obj_Enemy_Get5B4b1_1_0013E690 *o)
{
    return o->b1;
}

/* Enemy_Set5B4b0_1_0013E6A0 */
/* Enemy_Set5B4b0_1_0013E6A0 */
/* Enemy_Set5B4b0_1_0013E6A0 */
/* Enemy_Set5B4b0_1_0013E6A0 */
/* Bitfield setter on an object's flag byte at 0x5B4. */


void Enemy_Set5B4b0_1_0013E6A0(Obj_Enemy_Set5B4b0_1_0013E6A0 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B4m1_1_0013E6C0 */
s32 Enemy_Get5B4m1_1_0013E6C0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x5B4) & 1;
}

/* Enemy_Set5B3b7_1_0013E6D0 */
/* Bitfield setter on an object's flag byte at 0x5B3. */


void Enemy_Set5B3b7_1_0013E6D0(Obj_Enemy_Set5B3b7_1_0013E6D0 *o, int v)
{
    o->f = v;
}

/* Enemy_Set5B6b1_1_0013E6F0 */
/* Bitfield setter on an object's flag byte at 0x5B6. */


void Enemy_Set5B6b1_1_0013E6F0(Obj_Enemy_Get60B_1_0013E240___ *o, int v)
{
    o->f = v;
}

/* Enemy_Set5B3b6_1_0013E710 */
/* Enemy_Set5B3b6_1_0013E710 */
/* Enemy_Set5B3b6_1_0013E710 */
/* Enemy_Set5B3b6_1_0013E710 */
/* Enemy_Set5B3b6_1_0013E710 */
/* Bitfield setter on an object's flag byte at 0x5B3. */


void Enemy_Set5B3b6_1_0013E710(Obj_Enemy_Set5B3b6_1_0013E710 *o, int v)
{
    o->f = v;
}

/* Enemy_Set5B2b6w2_1_0013E730 */
/* Bitfield setter on an object's flag byte at 0x5B2. */


void Enemy_Set5B2b6w2_1_0013E730(Obj_Enemy_Set5B2b6w2_1_0013E730 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B2b6w2_1_0013E750 */
u64 Enemy_Get5B2b6w2_1_0013E750(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B2) << 0x38) >> 0x3E;
}

/* Enemy_Set5B2b5_1_0013E760 */
/* Bitfield setter on an object's flag byte at 0x5B2. */


void Enemy_Set5B2b5_1_0013E760(Obj_Enemy_Set5B3b6_1_0013E710_ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B2b5_1_0013E780 */
u64 Enemy_Get5B2b5_1_0013E780(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B2) << 0x3A) >> 0x3F;
}

/* Enemy_Set5B2b4_1_0013E790 */
/* Enemy_Set5B2b4_1_0013E790 */
/* Enemy_Set5B2b4_1_0013E790 */
/* Enemy_Set5B2b4_1_0013E790 */
/* Enemy_Set5B2b4_1_0013E790 */
/* Enemy_Set5B2b4_1_0013E790 */
/* Bitfield setter on an object's flag byte at 0x5B2. */


void Enemy_Set5B2b4_1_0013E790(Obj_Enemy_Set5B2b4_1_0013E790 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B2b4_1_0013E7B0 */
u64 Enemy_Get5B2b4_1_0013E7B0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B2) << 0x3B) >> 0x3F;
}

/* Enemy_Set5B3b3_1_0013E7C0 */
/* Bitfield setter on an object's flag byte at 0x5B3. */


void Enemy_Set5B3b3_1_0013E7C0(Obj_Enemy_Set5B3b3_1_0013E7C0 *o, int v)
{
    o->f = v;
}

/* Enemy_SetStateResetTimer_1_0013E7E0 */
void Enemy_SetStateResetTimer_1_0013E7E0(Obj_Enemy_Get60B_1_0013E240____ *o, u8 v)
{
    if (o->f != v) {
        o->f = v;
        o->t = 1.0f;
    }
}

/* Enemy_Get5B3b2_1_0013E820 */
u64 Enemy_Get5B3b2_1_0013E820(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B3) << 0x3D) >> 0x3F;
}

/* Enemy_Get5B2b3_1_0013E830 */
u64 Enemy_Get5B2b3_1_0013E830(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B2) << 0x3C) >> 0x3F;
}

/* Enemy_Set5B2b2_1_0013E840 */
/* Enemy_Set5B2b2_1_0013E840 */
/* Enemy_Set5B2b2_1_0013E840 */
/* Enemy_Set5B2b2_1_0013E840 */
/* Enemy_Set5B2b2_1_0013E840 */
/* Bitfield setter on an object's flag byte at 0x5B2. */


void Enemy_Set5B2b2_1_0013E840(Obj_Enemy_Set5B2b2_1_0013E840 *o, int v)
{
    o->f = v;
}

/* Enemy_Set5B2b1_1_0013E860 */
/* Bitfield setter on an object's flag byte at 0x5B2. */


void Enemy_Set5B2b1_1_0013E860(Obj_Enemy_Set5B2b1_1_0013E860 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B2b1_1_0013E880 */
u64 Enemy_Get5B2b1_1_0013E880(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B2) << 0x3E) >> 0x3F;
}

/* Enemy_Set5B2b0_1_0013E890 */
/* Bitfield setter on an object's flag byte at 0x5B2. */


void Enemy_Set5B2b0_1_0013E890(Obj_Enemy_Set5B2b2_1_0013E840_ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B2m1_1_0013E8B0 */
s32 Enemy_Get5B2m1_1_0013E8B0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x5B2) & 1;
}

/* Enemy_Set5B1b7_1_0013E8C0 */
/* Enemy_Set5B1b7_1_0013E8C0 */
/* Enemy_Set5B1b7_1_0013E8C0 */
/* Enemy_Set5B1b7_1_0013E8C0 */
/* Enemy_Set5B1b7_1_0013E8C0 */
/* Enemy_Set5B1b7_1_0013E8C0 */
/* Bitfield setter on an object's flag byte at 0x5B1. */


void Enemy_Set5B1b7_1_0013E8C0(Obj_Enemy_Set5B1b7_1_0013E8C0 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B1b7_1_0013E8E0 */
u64 Enemy_Get5B1b7_1_0013E8E0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B1) << 0x38) >> 0x3F;
}

/* Enemy_Set5B1b6_1_0013E8F0 */
/* Bitfield setter on an object's flag byte at 0x5B1. */


void Enemy_Set5B1b6_1_0013E8F0(Obj_Enemy_Set5B1b6_1_0013E8F0 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B1b6_1_0013E910 */
u64 Enemy_Get5B1b6_1_0013E910(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B1) << 0x39) >> 0x3F;
}

/* Enemy_Set5B1b5_1_0013E920 */
/* Bitfield setter on an object's flag byte at 0x5B1. */


void Enemy_Set5B1b5_1_0013E920(Obj_Enemy_Get60B_1_0013E240_____ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B1b5_1_0013E940 */
u64 Enemy_Get5B1b5_1_0013E940(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B1) << 0x3A) >> 0x3F;
}

/* Enemy_Set5B5b7_1_0013E950 */
/* Enemy_Set5B5b7_1_0013E950 */
/* Enemy_Set5B5b7_1_0013E950 */
/* Enemy_Set5B5b7_1_0013E950 */
/* Enemy_Set5B5b7_1_0013E950 */
/* Enemy_Set5B5b7_1_0013E950 */
/* Bitfield setter on an object's flag byte at 0x5B5. */


void Enemy_Set5B5b7_1_0013E950(Obj_Enemy_Set5B5b7_1_0013E950 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B5b7_1_0013E970 */
u64 Enemy_Get5B5b7_1_0013E970(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B5) << 0x38) >> 0x3F;
}

/* Enemy_Set5B1b4IfUnlocked_0_0013E980 */
void Enemy_Set5B1b4IfUnlocked_0_0013E980(Obj_Enemy_Set5B1b4IfUnlocked_0_0013E980 *o, int v)
{
    if (!o->lock)
        o->f = v;
}

/* Enemy_Get5B1b4_1_0013E9C0 */
u64 Enemy_Get5B1b4_1_0013E9C0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B1) << 0x3B) >> 0x3F;
}

/* Enemy_Set5B1b3IfUnlocked_1_0013E9D0 */
void Enemy_Set5B1b3IfUnlocked_1_0013E9D0(Obj_Enemy_Set5B5b7_1_0013E950_ *o, int v)
{
    if (!o->lock)
        o->f = v;
}

/* Enemy_Get5B1b3_1_0013EA10 */
u64 Enemy_Get5B1b3_1_0013EA10(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B1) << 0x3C) >> 0x3F;
}

/* Enemy_Set5B1b2_1_0013EA20 */
/* Bitfield setter on an object's flag byte at 0x5B1. */


void Enemy_Set5B1b2_1_0013EA20(Obj_Enemy_Get60B_1_0013E240______ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B1b2_1_0013EA40 */
/* Bitfield getters and setter on an object's flag bytes at 0x5B1 and 0x5B4. */


int Enemy_Get5B1b2_1_0013EA40(Obj_Enemy_Get5B1b2_1_0013EA40 *o)
{
    return o->a2;
}

/* Enemy_Set5B1b1_1_0013EA50 */
/* Enemy_Set5B1b1_1_0013EA50 */
/* Enemy_Set5B1b1_1_0013EA50 */
/* Enemy_Set5B1b1_1_0013EA50 */
/* Enemy_Set5B1b1_1_0013EA50 */
/* Enemy_Set5B1b1_1_0013EA50 */
/* Bitfield setter on an object's flag byte at 0x5B1. */


void Enemy_Set5B1b1_1_0013EA50(Obj_Enemy_Set5B1b1_1_0013EA50 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B1b1_1_0013EA70 */
u64 Enemy_Get5B1b1_1_0013EA70(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B1) << 0x3E) >> 0x3F;
}

/* Enemy_Set5B6b4_1_0013EA80 */
/* Bitfield setter on an object's flag byte at 0x5B6. */


void Enemy_Set5B6b4_1_0013EA80(Obj_Enemy_Set5B6b4_1_0013EA80 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B6b4_1_0013EAA0 */
u64 Enemy_Get5B6b4_1_0013EAA0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B6) << 0x3B) >> 0x3F;
}

/* Enemy_Set5B6b3_1_0013EAB0 */
/* Bitfield setter on an object's flag byte at 0x5B6. */


void Enemy_Set5B6b3_1_0013EAB0(Obj_Enemy_Get60B_1_0013E240_______ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B6b3_1_0013EAD0 */
u64 Enemy_Get5B6b3_1_0013EAD0(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B6) << 0x3C) >> 0x3F;
}

/* Enemy_Set5B6b2_1_0013EAE0 */
/* Enemy_Set5B6b2_1_0013EAE0 */
/* Enemy_Set5B6b2_1_0013EAE0 */
/* Enemy_Set5B6b2_1_0013EAE0 */
/* Enemy_Set5B6b2_1_0013EAE0 */
/* Enemy_Set5B6b2_1_0013EAE0 */
/* Bitfield setter on an object's flag byte at 0x5B6. */


void Enemy_Set5B6b2_1_0013EAE0(Obj_Enemy_Set5B6b2_1_0013EAE0 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B6b2_1_0013EB00 */
u64 Enemy_Get5B6b2_1_0013EB00(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B6) << 0x3D) >> 0x3F;
}

/* Enemy_Set5B1b0_1_0013EB10 */
/* Bitfield setter on an object's flag byte at 0x5B1. */


void Enemy_Set5B1b0_1_0013EB10(Obj_Enemy_Set5B1b0_1_0013EB10 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B1m1_1_0013EB30 */
s32 Enemy_Get5B1m1_1_0013EB30(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x5B1) & 1;
}

/* Enemy_Set5B0b7_1_0013EB40 */
/* Bitfield setter on an object's flag byte at 0x5B0. */


void Enemy_Set5B0b7_1_0013EB40(Obj_Enemy_Set5B6b2_1_0013EAE0_ *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B0b7_1_0013EB60 */
u64 Enemy_Get5B0b7_1_0013EB60(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B0) << 0x38) >> 0x3F;
}

/* Enemy_Set5B0b6_1_0013EB70 */
/* Enemy_Set5B0b6_1_0013EB70 */
/* Enemy_Set5B0b6_1_0013EB70 */
/* Enemy_Set5B0b6_1_0013EB70 */
/* Bitfield setter on an object's flag byte at 0x5B0. */


void Enemy_Set5B0b6_1_0013EB70(Obj_Enemy_Set5B0b6_1_0013EB70 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B0b6_1_0013EB90 */
u64 Enemy_Get5B0b6_1_0013EB90(void *arg0) {
    return (u64) ((s64) M2C_FIELD(arg0, u8 *, 0x5B0) << 0x39) >> 0x3F;
}

/* Enemy_SetMode_0_0013EBA0 */
void Enemy_SetMode_0_0013EBA0(Obj_Enemy_SetMode_0_0013EBA0 *o, u8 v)
{
    o->a = v;
    if (v < 4)
        o->b = v;
}

/* Enemy_Set5B0b2_1_0013EBF0 */
/* Bitfield setter on an object's flag byte at 0x5B0. */


void Enemy_Set5B0b2_1_0013EBF0(Obj_Enemy_Get60B_1_0013E240________ *o, int v)
{
    o->f = v;
}

/* Enemy_Set5B0b1_1_0013EC10 */
/* Enemy_Set5B0b1_1_0013EC10 */
/* Enemy_Set5B0b1_1_0013EC10 */
/* Enemy_Set5B0b1_1_0013EC10 */
/* Bitfield setter on an object's flag byte at 0x5B0. */


void Enemy_Set5B0b1_1_0013EC10(Obj_Enemy_Set5B0b1_1_0013EC10 *o, int v)
{
    o->f = v;
}

/* Enemy_Set5B0b0_1_0013EC30 */
/* Bitfield setter on an object's flag byte at 0x5B0. */


void Enemy_Set5B0b0_1_0013EC30(Obj_Enemy_Set5B0b0_1_0013EC30 *o, int v)
{
    o->f = v;
}

/* Enemy_Get5B0m1_1_0013EC50 */
s32 Enemy_Get5B0m1_1_0013EC50(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x5B0) & 1;
}

/* Enemy_GetPartFlagU_0_0013EC60 */
u32 Enemy_GetPartFlagU_0_0013EC60(Obj_Enemy_Set5B0b1_1_0013EC10_ *o, u8 i)
{
    return o->ents[i]->f;
}
