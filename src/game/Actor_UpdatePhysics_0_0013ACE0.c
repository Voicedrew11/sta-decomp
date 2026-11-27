#include "actor.h"
#define FF(p, o) (*(f32 *)((s8 *)(p) + (o)))
typedef struct { u8 pad[0x2A]; u8 x2A; } Pt;
typedef struct { u8 pad[0x2C]; s8 *x2C; u8 pad30[0x10]; Vec x40; Vec x50; } Sub;
typedef struct { u8 pad[0xA0]; Vec xA0; u8 padB0[0x10]; Vec xC0; Vec xD0; Mtx xE0; Vec x120; Vec x130; } E;
extern Mtx D_001F2170;
u32 Enemy_Get5B2b6w2_1_0013E750(Actor *);
void sceVu0ScaleVector(Vec *, void *, f32);
void sceVu0AddVector(void *, void *, void *);
void EnemyScr_Event2023_1_00140CB0(Actor *, u8 *, f32 *, f32 *);
s8 *Enemy_GetParamPtr290_1_0013DE50(Actor *);
f32 *Enemy_GetModelData_1_0013DCE0(Actor *);
void Enemy_SyncPosition_0_0013E370(Actor *);
f32 Enemy_GetHeightAboveFloor_0_0013E3C0(Actor *);
s32 Ent_IsNull0_1_0013EE30(Actor *);
s32 Enemy_IsDead_1_0013EEE0(Actor *);
u16 Enemy_GetMaxHp_2_0013F700(Actor *);
void Enemy_AddHp_2_0013F710(Actor *, s32);
void Enemy_Kill_1_0013EF80(Actor *, s32);
s32 Enemy_GetHpPercent_2_0013F620(Actor *);
void EnemyScr_Event200COnHit_1_00142320(Actor *, s32, u8);
void Enemy_Get5B3b2_1_0013E820(Actor *);
void Enemy_SetStateResetTimer_1_0013E7E0(Actor *, u8);
Pt *Enemy_GetPartValue_1_0013DCA0(Actor *, u8);
E *Enemy_GetPart_1_0013DC70(Actor *, u8);
void sceVu0CopyMatrix(void *, void *);
void Quat_ToMatrixB_2_0015E580(Mtx *, void *);
void sceVu0MulMatrix(void *, void *, void *);
void sceVu0ApplyMatrix(Vec *, void *, void *);
f32 *Enemy_GetPositionPtr_2_00140460(Actor *);
void Enemy_HidePart_1_001A8B10(Actor *, u8);

void Actor_UpdatePhysics_0_0013ACE0(Actor *a, f32 g) {
    s32 i;
    Sub *S;
    u8 r;
    f32 k;
    S = (Sub *)(a->unk518 + 0x180);
    r = Enemy_Get5B2b6w2_1_0013E750(a);
    k = 3920.0f * g;
    S->x50.y += k;
    if (r == 0) {
        Vec v;
        sceVu0ScaleVector(&v, &S->x50, g);
        sceVu0AddVector(&S->x40, &v, &S->x40);
    } else if (r == 1) {
        Vec v;
        sceVu0ScaleVector(&v, &S->x50, g);
        sceVu0AddVector(&S->x40, &v, &S->x40);
    } else if (r == 2) {
        Vec v;
        S->x50.y = 0.0f;
        sceVu0ScaleVector(&v, &S->x50, g);
        sceVu0AddVector(&S->x40, &v, &S->x40);
    } else {
        u8 t = 0;
        f32 m = 2.0f;
        f32 b = 0.0f;
        f32 *p;
        EnemyScr_Event2023_1_00140CB0(a, &t, &m, &b);
        switch (t) {
        case 0:
            b += FF(a, 0x644);
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 1:
            b += FF(a, 0x684);
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 2:
            b += FF(a, 0x664);
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 3:
            p = Enemy_GetModelData_1_0013DCE0(a);
            if (p) b += p[1];
            b += FF(Enemy_GetParamPtr290_1_0013DE50(a), 0x18);
            break;
        case 4:
            p = Enemy_GetModelData_1_0013DCE0(a);
            if (p) b += p[1];
            break;
        }
        b -= S->x40.y;
        m *= g;
        if (!(b <= m)) b = m;
        if (b < -m) b = -m;
        S->x40.y += b;
        S->x50.y = 0.0f;
    }
    if (!(S->x40.y <= 20000.0f)) {
        S->x40.y = 20000.0f;
        S->x50.y = 0.0f;
    }
    Enemy_SyncPosition_0_0013E370(a);
    if (!(Enemy_GetHeightAboveFloor_0_0013E3C0(a) <= 2000.0f) && !Ent_IsNull0_1_0013EE30(a)) {
        if (!Enemy_IsDead_1_0013EEE0(a)) {
            Enemy_AddHp_2_0013F710(a, -Enemy_GetMaxHp_2_0013F700(a) - 1);
            Enemy_Kill_1_0013EF80(a, 0);
            EnemyScr_Event200COnHit_1_00142320(a, 0, Enemy_GetHpPercent_2_0013F620(a));
        }
        Enemy_Get5B3b2_1_0013E820(a);
        Enemy_SetStateResetTimer_1_0013E7E0(a, 1);
    }
    for (i = 0; i < a->pad000[0x80]; i++) {
        u8 id;
        E *e;
        u8 n;
        Pt *p;
        Vec v;
        Mtx M;
        Mtx M2;
        Vec V;
        id = a->pad520[i];
        p = Enemy_GetPartValue_1_0013DCA0(a, id);
        e = Enemy_GetPart_1_0013DC70(a, id);
        n = p->x2A;
        e->xD0.y += k * 0.25f;
        sceVu0ScaleVector(&v, &e->xD0, g);
        sceVu0AddVector(&e->xA0, &v, &e->xA0);
        sceVu0CopyMatrix(&M, &D_001F2170);
        M.m[0].x = e->xC0.x;
        M.m[1].y = e->xC0.y;
        M.m[2].z = e->xC0.z;
        Quat_ToMatrixB_2_0015E580(&M2, &e->x130);
        sceVu0MulMatrix(&e->xE0, &e->xE0, &M2);
        sceVu0ApplyMatrix(&V, &e->xE0, &e->x120);
        sceVu0MulMatrix(&M, &M, &e->xE0);
        sceVu0AddVector(&M.m[3], &e->xA0, &V);
        sceVu0CopyMatrix(S->x2C + (n + 1) * 0x140 + 0x100, &M);
        if (!(e->xA0.y - Enemy_GetPositionPtr_2_00140460(a)[1] <= 5000.0f)) {
            Enemy_HidePart_1_001A8B10(a, id);
            e->xA0.y = 5000.0f + Enemy_GetPositionPtr_2_00140460(a)[1];
        }
    }
}
