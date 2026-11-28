#include "actor.h"
#include "common.h"
typedef struct { u8 pad[8]; u16 id; u8 pad2[2]; f32 f; } Mdl;
typedef struct {
    u8 pad[0x18];
    s8 *p18;
    u8 pad1C[0xC];
    Mdl *p28;
    s8 *p2C;
    u8 pad30[0x10];
    Vec m40;
    u8 pad50[0x10];
    Vec m60;
    u8 pad70[0x30];
    Vec mA0;
} Sub_Actor_UpdateAttachments_0_0013AB00;
typedef struct { u8 pad[0x140]; s16 id; u8 p142[2]; f32 f144; u8 p148[8]; f32 f150; } Ent_Actor_UpdateAttachments_0_0013AB00;
typedef struct { u8 pad[0x2A]; u8 a; u8 b; } Pt_Actor_UpdateAttachments_0_0013AB00;
typedef struct { u8 pad[0x7C]; u32 n; } A7C;
typedef struct { u8 pad[0x2A]; u8 x2A; } Pt_Actor_UpdatePhysics_0_0013ACE0;
typedef struct { u8 pad[0x2C]; s8 *x2C; u8 pad30[0x10]; Vec x40; Vec x50; } Sub_Actor_UpdatePhysics_0_0013ACE0;
typedef struct { u8 pad[0xA0]; Vec xA0; u8 padB0[0x10]; Vec xC0; Vec xD0; Mtx xE0; Vec x120; Vec x130; } E;
typedef struct { u8 pad[8]; u16 id; u8 pada[2]; f32 x; f32 y; } Anim;
typedef struct { u8 pad[0x10]; Vec v; u8 pad20[0xA0]; s32 xC0; } Sub10;
typedef struct { u8 pad[0x40]; Vec v; } Sub18;
typedef struct {
    u8 pad[0x10];
    Sub10 *p10;
    u8 pad14[4];
    Sub18 *p18;
    u8 pad1C[0xC];
    Anim *p28;
    u8 pad2C[0x14];
    Vec v40;
    Vec v50;
    u8 pad60[0x40];
    Vec vA0;
    u8 padB0[0x44];
    s32 xF4;
} Body;
typedef struct Obj Obj;
typedef void (*Cb)(Obj *, f32);
typedef struct { Vec a, b; Mtx m; u32 col; } Buf;
typedef struct { Vec v0; Vec v10; u8 pad[0xA]; u8 x2A; u8 x2B; u8 x2C; Flags8 f2D; u8 pad2[0x72]; Vec vA0; } Pt_Actor_UpdateTransform_0_0013B4F0;
typedef struct { u8 pad[0x160]; u8 x160; } Ent_Actor_UpdateTransform_0_0013B4F0;
typedef struct { Vec a, b, c, d; u8 pad[0x130]; } Bone;
typedef struct { u8 pad[0xB6]; u8 xB6; u8 xB7; } S18;
typedef struct { u8 pad[0x16]; u16 x16; } S0C;
typedef struct { u8 pad[4]; f32 f4; u8 pad8[4]; S0C **pC; u8 pad10[4]; Bone *p14; S18 *p18; u8 pad1C[0x10]; s8 *p2C; } Sub_Actor_UpdateTransform_0_0013B4F0;
typedef struct { Vec *p; } __attribute__((aligned(16))) PV;
typedef struct { u8 r:7; u8 b7:1; } F7;
extern Mtx D_001F2170;
extern s32 D_00201E80;
extern F7 D_00222A51[];
void Actor_UpdateAttachments_0_0013AB00(Actor *a0, f32 f);
void Actor_UpdatePhysics_0_0013ACE0(Actor *a, f32 g);
void Actor_UpdateCollision_0_0013B220(Obj *a, s32 skip, f32 dt);
void Actor_UpdateTransform_0_0013B4F0(Actor *a, s32 flag, f32 f);
void EnemyScr_Event2012_1_001419C0(Actor *, f32);
void Enemy_UpdateMotion_1_0013CBC0(Actor *, f32);
void Mdl_AnimateWrap_0_00171B70(Mdl *, u16, f32);
Pt_Actor_UpdateAttachments_0_0013AB00* Enemy_GetPartValue_1_0013DCA0(Actor *, u8);
Ent_Actor_UpdateAttachments_0_0013AB00* Enemy_GetPart_1_0013DC70(Actor *, u8);
void Mdl_AnimateCur_0_00171AF0(Mdl *, u16, u8, u8, f32);
void Mdl_BlendMotion_0_00171980(Mdl *, u16, u8, u8, f32, f32);
void sceVu0SubVector(Vec*, void *, void *);
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(void *, void *);
void Actor_UpdateBones_0_001370A0(Actor *);
void sceVu0ApplyMatrix(Vec*, void *, void *);
void sceVu0AddVector(void *, void *, void *);
u32 Enemy_Get5B2b6w2_1_0013E750(Actor *);
void sceVu0ScaleVector(Vec *, void *, f32);
void EnemyScr_Event2023_1_00140CB0(Actor *, u8 *, f32 *, f32 *);
s8* Enemy_GetParamPtr290_1_0013DE50(Actor *);
f32* Enemy_GetModelData_1_0013DCE0(Actor *);
void Enemy_SyncPosition_0_0013E370(Actor *);
f32 Enemy_GetHeightAboveFloor_0_0013E3C0(Actor *);
s32 Ent_IsNull0_1_0013EE30(void *);
s32 Enemy_IsDead_1_0013EEE0(Actor *);
u16 Enemy_GetMaxHp_2_0013F700(Actor *);
void Enemy_AddHp_2_0013F710(Actor *, s32);
void Enemy_Kill_1_0013EF80(Actor *, s32);
s32 Enemy_GetHpPercent_2_0013F620(Actor *);
void EnemyScr_Event200COnHit_1_00142320(Actor *, s32, u8);
void Enemy_Get5B3b2_1_0013E820(Actor *);
void Enemy_SetStateResetTimer_1_0013E7E0(Actor *, u8);
void Quat_ToMatrixB_2_0015E580(Mtx *, void *);
void sceVu0MulMatrix(void *, void *, void *);
f32* Enemy_GetPositionPtr_2_00140460(Actor *);
void Enemy_HidePart_1_001A8B10(Actor *, u8);
void Enemy_Set5B6b2_1_0013EAE0(Obj *, s32);
void Enemy_Set5B6b3_1_0013EAB0(Obj *, s32);
void Mdl_RunMotionEvents_0_001717A0(Anim *, u16, f32, f32, void *);
void Combat_DispatchAttack_0_00139D30();
void Actor_OffsetColliders_1_00137730(Obj *, Vec *);
void Actor_ResolveActorCollision_0_0013A2C0(Obj *, f32);
void Actor_ResolveWallCollision_0_0013A450(Obj *, f32);
void Actor_ResolveGround_0_0013A720(Obj *, f32);
void Enemy_UpdateAI_1_00136400(Obj *, f32);
void Actor_ResolveActorCollisionB_1_0013A190(Obj *, f32);
void Actor_ProcessHitEvents_0_00139F30(Obj *);
void Actor_UpdateAttachedColliders_0_00139E20(Obj *);
void Player_UpdateArmBones_0_001C5DE0(Obj *);
void Enemy_UpdateSfxTransform_0_001A83E0(Obj *);
u8 Enemy_Get81_1_0013FC00(Actor *);
s32 Enemy_GetCollider_0_0013FB90(Actor *, u8, Vec **, Vec **);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void Draw_ShadowDisc_0_00156920(Buf *);
f32 sqrtf(f32);

/* Actor_UpdateAttachments_0_0013AB00 */
#define sceVu0SubVector sceVu0SubVector__as_Actor_UpdateAttachments_0_0013AB00
void sceVu0SubVector__as_Actor_UpdateAttachments_0_0013AB00(Vec *, s8 *, s8 *);
#define sceVu0CopyVector sceVu0CopyVector__as_Actor_UpdateAttachments_0_0013AB00
void sceVu0CopyVector__as_Actor_UpdateAttachments_0_0013AB00(s8 *, s8 *);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Actor_UpdateAttachments_0_0013AB00
void sceVu0CopyMatrix__as_Actor_UpdateAttachments_0_0013AB00(s8 *, s8 *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Actor_UpdateAttachments_0_0013AB00
void sceVu0ApplyMatrix__as_Actor_UpdateAttachments_0_0013AB00(Vec *, Vec *, Vec *);
#define sceVu0AddVector sceVu0AddVector__as_Actor_UpdateAttachments_0_0013AB00
void sceVu0AddVector__as_Actor_UpdateAttachments_0_0013AB00(Vec *, Vec *, Vec *);

void Actor_UpdateAttachments_0_0013AB00(Actor *a0, f32 f) {
    Sub_Actor_UpdateAttachments_0_0013AB00 *s;
    u32 i;
    Pt_Actor_UpdateAttachments_0_0013AB00 *pt;
    Ent_Actor_UpdateAttachments_0_0013AB00 *e;
    s8 *b;
    Vec v;
    void (*cb)(Actor *, f32);

    b = a0->unk518;
    s = (Sub_Actor_UpdateAttachments_0_0013AB00 *)(b + 0x180);
    if (*(u16 *)(**(s8 ***)(b + 0x18C) + 0x16) == 0) {
        return;
    }
    if (a0->flags5B7.f.b6) {
        f = 0.0f;
    }
    cb = *(void (**)(Actor *, f32))((s8 *)a0 + 0x538);
    if (cb != 0) {
        cb(a0, f);
        return;
    }
    EnemyScr_Event2012_1_001419C0(a0, f);
    Enemy_UpdateMotion_1_0013CBC0(a0, f);
    Mdl_AnimateWrap_0_00171B70(s->p28, s->p28->id, s->p28->f);
    for (i = 0; i < *(u32 *)(a0->pad000 + 0x7C); i++) {
        pt = Enemy_GetPartValue_1_0013DCA0(a0, i);
        e = Enemy_GetPart_1_0013DC70(a0, i);
        { f32 w = e->f150; s16 id; f32 g; s32 a; s32 b2; if (w != 0.0f) { id = e->id; g = e->f144; a = pt->a; b2 = pt->b;
            if (w == 1.0f) {
                Mdl_AnimateCur_0_00171AF0(s->p28, id, a, b2, g);
            } else {
                Mdl_BlendMotion_0_00171980(s->p28, id, a, b2, g, 1.0f - w);
            }
        } }
    }
    sceVu0SubVector(&v, s->p2C + 0x2B0, s->p18 + 0xA0);
    sceVu0CopyVector(s->p18 + 0xA0, s->p2C + 0x2B0);
    sceVu0CopyMatrix(s->p2C + 0x280, s->p18 + 0x60);
    Actor_UpdateBones_0_001370A0(a0);
    sceVu0ApplyMatrix(&s->mA0, &s->m60, &v);
    sceVu0AddVector(&s->m40, &s->m40, &s->mA0);
}
#undef sceVu0SubVector
#undef sceVu0CopyVector
#undef sceVu0CopyMatrix
#undef sceVu0ApplyMatrix
#undef sceVu0AddVector

/* Actor_UpdatePhysics_0_0013ACE0 */
#define FF(p, o) (*(f32 *)((s8 *)(p) + (o)))
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_Actor_UpdatePhysics_0_0013ACE0
s32 Ent_IsNull0_1_0013EE30__as_Actor_UpdatePhysics_0_0013ACE0(Actor *);
#define Enemy_GetPartValue_1_0013DCA0 Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdatePhysics_0_0013ACE0
Pt_Actor_UpdatePhysics_0_0013ACE0 *Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdatePhysics_0_0013ACE0(Actor *, u8);
#define Enemy_GetPart_1_0013DC70 Enemy_GetPart_1_0013DC70__as_Actor_UpdatePhysics_0_0013ACE0
E *Enemy_GetPart_1_0013DC70__as_Actor_UpdatePhysics_0_0013ACE0(Actor *, u8);

void Actor_UpdatePhysics_0_0013ACE0(Actor *a, f32 g) {
    s32 i;
    Sub_Actor_UpdatePhysics_0_0013ACE0 *S;
    u8 r;
    f32 k;
    S = (Sub_Actor_UpdatePhysics_0_0013ACE0 *)(a->unk518 + 0x180);
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
        Pt_Actor_UpdatePhysics_0_0013ACE0 *p;
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
#undef Ent_IsNull0_1_0013EE30
#undef Enemy_GetPartValue_1_0013DCA0
#undef Enemy_GetPart_1_0013DC70

/* Actor_UpdateCollision_0_0013B220 */
struct Obj {
    u8 pad[0x518];
    s8 *unk518;
    u8 pad51C[0x1C];
    s32 x538;
    Cb f53C;
    Cb f540;
    Cb f544;
    void *f548;
};
#define sceVu0SubVector sceVu0SubVector__as_Actor_UpdateCollision_0_0013B220
void sceVu0SubVector__as_Actor_UpdateCollision_0_0013B220(Vec *, Vec *, Vec *);
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220
s32 Ent_IsNull0_1_0013EE30__as_Actor_UpdateCollision_0_0013B220(Obj *);

void Actor_UpdateCollision_0_0013B220(Obj *a, s32 skip, f32 dt) {
    Body *b;
    Vec v;

    b = (Body *)(a->unk518 + 0x180);
    if (!Ent_IsNull0_1_0013EE30(a) && skip) {
        return;
    }
    Enemy_Set5B6b2_1_0013EAE0(a, 0);
    Enemy_Set5B6b3_1_0013EAB0(a, 0);
    if (a->f548) {
        Mdl_RunMotionEvents_0_001717A0(b->p28, b->p28->id, b->p28->x, b->p28->y, a->f548);
    } else {
        Mdl_RunMotionEvents_0_001717A0(b->p28, b->p28->id, b->p28->x, b->p28->y, Combat_DispatchAttack_0_00139D30);
    }
    if (!Ent_IsNull0_1_0013EE30(a)) {
        Actor_OffsetColliders_1_00137730(a, &b->vA0);
        Actor_ResolveActorCollision_0_0013A2C0(a, dt);
    }
    if (!Ent_IsNull0_1_0013EE30(a) && ((&D_00201E80)[2] || (&D_00201E80)[3])) {
        if (a->f53C) {
            a->f53C(a, dt);
        } else {
            Actor_ResolveWallCollision_0_0013A450(a, dt);
            Actor_ResolveGround_0_0013A720(a, dt);
        }
    }
    if (!skip) {
        if (a->f540) {
            a->f540(a, dt);
        } else {
            Enemy_UpdateAI_1_00136400(a, dt);
        }
    }
    if (Ent_IsNull0_1_0013EE30(a)) {
        sceVu0SubVector(&v, &b->v40, &b->p10->v);
        Actor_OffsetColliders_1_00137730(a, &v);
        Actor_ResolveActorCollisionB_1_0013A190(a, dt);
        sceVu0CopyVector(&v, &b->v40);
        if (a->f53C) {
            a->f53C(a, dt);
        }
        b->p10->xC0 = 0;
        if (b->xF4) {
            Actor_ProcessHitEvents_0_00139F30(a);
        }
        if (a->f544) {
            a->f544(a, dt);
        }
        sceVu0SubVector(&v, &b->v40, &v);
        Actor_OffsetColliders_1_00137730(a, &v);
    } else {
        b->p10->xC0 = 0;
        Actor_ProcessHitEvents_0_00139F30(a);
        if (a->f544) {
            a->f544(a, dt);
        } else {
            Actor_UpdateAttachedColliders_0_00139E20(a);
        }
    }
    if (a->x538) {
        if (Ent_IsNull0_1_0013EE30(a)) {
            Player_UpdateArmBones_0_001C5DE0(a);
        }
    } else {
        Enemy_UpdateSfxTransform_0_001A83E0(a);
    }
    sceVu0CopyVector(b->p18, &b->v40);
    sceVu0CopyVector(&b->p18->v, &b->v50);
}
#undef sceVu0SubVector
#undef Ent_IsNull0_1_0013EE30

/* Actor_UpdateTransform_0_0013B4F0 */
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_Actor_UpdateTransform_0_0013B4F0
s32 Ent_IsNull0_1_0013EE30__as_Actor_UpdateTransform_0_0013B4F0(Actor *);
#define Enemy_GetPartValue_1_0013DCA0 Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdateTransform_0_0013B4F0
Pt_Actor_UpdateTransform_0_0013B4F0 *Enemy_GetPartValue_1_0013DCA0__as_Actor_UpdateTransform_0_0013B4F0(Actor *, u8);
#define Enemy_GetPart_1_0013DC70 Enemy_GetPart_1_0013DC70__as_Actor_UpdateTransform_0_0013B4F0
Ent_Actor_UpdateTransform_0_0013B4F0 *Enemy_GetPart_1_0013DC70__as_Actor_UpdateTransform_0_0013B4F0(Actor *, u8);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Actor_UpdateTransform_0_0013B4F0
void sceVu0CopyMatrix__as_Actor_UpdateTransform_0_0013B4F0(Mtx *, void *);
#define sceVu0CopyVector sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0
void sceVu0CopyVector__as_Actor_UpdateTransform_0_0013B4F0(Vec *, Vec *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Actor_UpdateTransform_0_0013B4F0
void sceVu0ApplyMatrix__as_Actor_UpdateTransform_0_0013B4F0(Vec *, Mtx *, Vec *);
#define sceVu0SubVector sceVu0SubVector__as_Actor_UpdateTransform_0_0013B4F0
void sceVu0SubVector__as_Actor_UpdateTransform_0_0013B4F0(Vec *, Vec *, Vec *);

void Actor_UpdateTransform_0_0013B4F0(Actor *a, s32 flag, f32 f) {
    Mtx M;
    PV P;
    PV Q;
    Vec V;
    Buf L1;
    Mtx M3;
    Buf L2;
    Sub_Actor_UpdateTransform_0_0013B4F0 *s;
    u8 i;
    u8 n;
    Pt_Actor_UpdateTransform_0_0013B4F0 *e;
    u32 j;
    Bone *g;
    Vec *b;

    s = (Sub_Actor_UpdateTransform_0_0013B4F0 *)(a->unk518 + 0x180);
    if (!Ent_IsNull0_1_0013EE30(a) && flag) return;
    Actor_UpdatePhysics_0_0013ACE0(a, f);
    if ((*s->pC)->x16 == 0) return;
    Actor_UpdateAttachments_0_0013AB00(a, f);
    n = Enemy_Get81_1_0013FC00(a);
    for (i = 0; i < n; i++) {
        P.p = 0;
        Q.p = 0;
        if ((u8)Enemy_GetCollider_0_0013FB90(a, i, &P.p, &Q.p)) {
            e = Enemy_GetPartValue_1_0013DCA0(a, a->unk82[i]);
            sceVu0CopyMatrix(&M, s->p2C + (e->x2A + 1) * 0x140 + 0xC0);
            sceVu0CopyVector(Q.p, P.p);
            sceVu0CopyVector(&V, &e->vA0);
            V.w = 1.0f;
            sceVu0ApplyMatrix(P.p, &M, &V);
            P.p->w = e->vA0.w * s->f4;
            Q.p->w < 0.0f ? sceVu0CopyVector(Q.p, P.p) : (void)0;
            if (D_00222A51[0].b7 && !Ent_IsNull0_1_0013EE30(a)) {
                sceVu0CopyMatrix(&L1.m, &D_001F2170);
                L1.col = 0x4000FF00;
                sceVu0CopyVector(&L1.a, Q.p);
                sceVu0SubVector(&L1.b, P.p, Q.p);
                L1.b.w = sqrtf(sceVu0InnerProduct(&L1.b, &L1.b));
                sceVu0Normalize(&L1.b, &L1.b);
                Draw_ShadowDisc_0_00156920(&L1);
            }
        } else {
            if (P.p) P.p->w = -100.0f;
            if (Q.p) Q.p->w = -100.0f;
        }
    }
        for (j = 0; j < *(u32 *)(a->pad000 + 0x7C); j++) {
            e = Enemy_GetPartValue_1_0013DCA0(a, j);
            if (e->f2D.f.b5) {
                sceVu0CopyVector(&s->p14[j].c, &s->p14[j].a);
                sceVu0CopyVector(&s->p14[j].d, &s->p14[j].b);
                g = &s->p14[j];
                b = &g->b;
                sceVu0CopyMatrix(&M3, s->p2C + (e->x2A + 1) * 0x140 + 0xC0);
                sceVu0CopyVector(&g->a, &e->v0);
                g->a.w = 1.0f;
                sceVu0CopyVector(b, &e->v10);
                b->w = 1.0f;
                sceVu0ApplyMatrix(&g->a, &M3, &g->a);
                sceVu0ApplyMatrix(b, &M3, b);
                sceVu0SubVector(b, b, &g->a);
                b->w = 0.0f;
                f = sqrtf(sceVu0InnerProduct(b, b));
                sceVu0Normalize(b, b);
                g->a.w = e->v0.w * s->f4;
                b->w = f;
                if (D_00222A51[0].b7 && !Ent_IsNull0_1_0013EE30(a) && !(Enemy_GetPart_1_0013DC70(a, j)->x160 & 1) &&
                    j != s->p18->xB7 && j != s->p18->xB6) {
                    sceVu0CopyMatrix(&L2.m, &D_001F2170);
                    L2.col = 0x40FFFFFF;
                    sceVu0CopyVector(&L2.a, &g->a);
                    sceVu0CopyVector(&L2.b, b);
                    Draw_ShadowDisc_0_00156920(&L2);
                }
            }
        }
}
#undef Ent_IsNull0_1_0013EE30
#undef Enemy_GetPartValue_1_0013DCA0
#undef Enemy_GetPart_1_0013DC70
#undef sceVu0CopyMatrix
#undef sceVu0CopyVector
#undef sceVu0ApplyMatrix
#undef sceVu0SubVector
