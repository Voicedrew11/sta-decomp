#include "actor.h"
#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0x120]; Flags8 x120; } C;
typedef struct { u8 pad[0x190]; C *x190; } B;
typedef struct { u8 pad[0x5B8]; f32 a; f32 b; } O;
typedef struct { char pad[0x4B4]; s32 v[1]; } S;
typedef struct { char pad[0x2A]; u8 idx; } Ent_Enemy_GetPartFlag_0_0013DCC0;
typedef struct { char pad[0x39A]; u8 b[0x11A]; Ent_Enemy_GetPartFlag_0_0013DCC0 *ents[1]; } Obj_Enemy_GetPartFlag_0_0013DCC0;
typedef struct { char pad[0x4A8]; int **q; } Hold;
typedef struct { u8 b:7; u8 flag:1; } BF;
typedef struct { char pad[0x24]; s16 h; } Ent_Enemy_GetPartAngle_1_0013E0C0;
typedef struct { char pad[0x4B4]; Ent_Enemy_GetPartAngle_1_0013E0C0 *ents[1]; } Obj_Enemy_GetPartAngle_1_0013E0C0;
typedef struct { u8 pad[0x1A]; u16 val; u8 pad2[0x54-0x1C]; } Ent_Enemy_GetCurrentParamIdx_0_0013E110;
typedef struct { u8 pad[0x13C]; Ent_Enemy_GetCurrentParamIdx_0_0013E110 *ents; } Tbl;
typedef struct { Tbl *tbl; } Hdr;
void Enemy_UpdateBlend5CC_0_0013DA20(Actor *a, f32 d);
void Enemy_UpdateLerp_0_0013DA90(O *o, f32 f);
void Enemy_UpdateTimer5C0_0_0013DB10(Actor *a, f32 dt);
void Enemy_UpdateDeath_0_0013DB80(Actor *a, f32 dt);
s32 Enemy_GetPart_1_0013DC70(void *arg0, s32 arg1);
s32 Enemy_GetPartValue_1_0013DCA0(S *s, u8 i);
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
void EnemyScr_Event2022_1_00140DE0(Actor *);
f32 cosf(f32);
void EnemyScr_Event200DGetStats_1_00142090(void *, void *, void *, f32 *, f32 *);

/* Enemy_UpdateBlend5CC_0_0013DA20 */
void Enemy_UpdateBlend5CC_0_0013DA20(Actor *a, f32 d) {
    f32 v = a->unk5CC;
    if (((B *)a->unk518)->x190->x120.f.b1) {
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
s32 Enemy_GetPartValue_1_0013DCA0(S *s, u8 i)
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
