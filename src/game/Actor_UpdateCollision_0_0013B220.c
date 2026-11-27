#include "common.h"
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
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(void *, void *);
s32 Ent_IsNull0_1_0013EE30(Obj *);
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
extern s32 D_00201E80;

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
