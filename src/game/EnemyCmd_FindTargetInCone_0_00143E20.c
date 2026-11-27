#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec s; Vec e; } Seg;
typedef struct { Vec p; u8 pad[0x14]; s32 hit; u8 pad2[0x18]; } Hit;
typedef struct { u8 pad[0xC]; f32 xC; } Q;
typedef struct { Q *p; s32 pad[2]; } QP __attribute__((aligned(16)));
s32 Enemy_GetTargetHandle_0_0013EDE0(s8 *);
s8 *ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(s8 *);
s32 Enemy_GetMotionId_0_0013ED20(s8 *);
void Enemy_CopyPosition_2_00140470(s8 *, Vec *);
void Enemy_GetForwardVector_2_001403D0(s8 *, Vec *);
Vec *Enemy_GetPositionPtr_2_00140460(s8 *);
Vec *Enemy_GetRotationPtr_1_00140430(s8 *);
void sceVu0CopyVector(Vec *, Vec *);
void memset(void *, s32, s32);
void Enemy_RaycastMapC_0_0013D430(s32, Hit *, Seg *, s32, s32);
void sceVu0SubVector(Vec *, void *, void *);
void sceVu0ScaleVector(f32, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, void *);
s32 Enemy_Get81_1_0013FC00(s8 *);
void Enemy_GetCollider_0_0013FB90(s8 *, u8, QP *, QP *);
extern s32 D_00201E80;
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void EnemyCmd_FindTargetInCone_0_00143E20(s8 *a0, s32 a1, u8 a2, s32 a3, s32 t0, s32 t1, f32 ang) {
    u8 k;
    s8 *cur;
    s32 it;
    Vec m;
    Vec p;
    Hit r;
    Seg b;
    QP q1;
    QP q2;
    f32 t;
    u8 n;
    u8 i;
    f32 fz;
    f32 fx;

    k = Enemy_GetTargetHandle_0_0013EDE0(a0);
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    if (cur != NULL) {
        do {
            if (Ent_IsNull0_1_0013EE30(cur) == 0 && Enemy_GetTargetHandle_0_0013EDE0(cur) == k && (u8)Enemy_GetMotionId_0_0013ED20(cur) == a2) {
                Enemy_CopyPosition_2_00140470(a0, &p);
                Enemy_GetForwardVector_2_001403D0(a0, &m);
                p.x += m.x * t1;
                p.z += m.z * t1;
                p.x -= m.z * a3;
                p.z += m.x * a3;
                p.y -= t0;
                sceVu0CopyVector(&b.s, Enemy_GetPositionPtr_2_00140460(a0));
                b.s.y -= 100.0f;
                b.s.w = 1.0f;
                sceVu0CopyVector(&b.e, &p);
                b.e.w = 1.0f;
                memset(&r, 0, 0x40);
                if (((s32 **)&D_00201E80)[2] != NULL) {
                    Enemy_RaycastMapC_0_0013D430(*((s32 **)&D_00201E80)[2], &r, &b, 6, 3);
                }
                if (r.hit == 0 && ((s32 **)&D_00201E80)[3] != NULL) {
                    Enemy_RaycastMapC_0_0013D430(*((s32 **)&D_00201E80)[3], &r, &b, 6, 3);
                }
                if (r.hit != 0) {
                    sceVu0SubVector(&p, &r, &b);
                    sceVu0ScaleVector(0.9f, &p, &p);
                    sceVu0AddVector(&p, &p, &b);
                }
                n = Enemy_Get81_1_0013FC00(cur);
                for (i = 0; i < n; i++) {
                    q1.p = NULL;
                    q2.p = NULL;
                    Enemy_GetCollider_0_0013FB90(cur, i, &q1, &q2);
                    if (q1.p != NULL) q1.p->xC = -100.0f;
                    if (q2.p != NULL) q2.p->xC = -100.0f;
                }
                sceVu0CopyVector(Enemy_GetPositionPtr_2_00140460(cur), &p);
                sceVu0CopyVector((Vec *)(*(s8 **)(cur + 0x518) + 0x1C0), &p);
                t = ang + Enemy_GetRotationPtr_1_00140430(a0)->y;
                Enemy_GetRotationPtr_1_00140430(cur)->y = WRAP(t);
                return;
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
}
