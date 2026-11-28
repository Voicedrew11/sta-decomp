#include "obj3d.h"
#include "m2c.h"
#include "common.h"
#include "actor.h"
typedef struct {
    f32 m[12];
    f32 pos[4];
    u8 pad40[0x48];
    s8 *x88;
    u8 pad8C[0x10];
    s16 x9C;
    u8 pad9E[6];
    u8 xA4;
    u8 padA5[3];
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } xA8;
} Obj_ItemObj_TestPickRay_0_001AC200;
typedef struct { f32 v[4]; } Vec_ItemObj_UpdateTransforms_0_001AC4A0;
typedef struct { u8 pad[0x60]; Vec_ItemObj_UpdateTransforms_0_001AC4A0 a; Vec_ItemObj_UpdateTransforms_0_001AC4A0 b; Vec_ItemObj_UpdateTransforms_0_001AC4A0 c; } Ent_ItemObj_UpdateTransforms_0_001AC4A0;
typedef struct {
    Mtx m;
    Vec_ItemObj_UpdateTransforms_0_001AC4A0 v40, v50, v60, v70;
    u8 pad80[0x1C];
    s16 idx;
    u8 pad9E[0xB];
    u8 fA9;
    u8 padAA[0x26];
} Node_ItemObj_UpdateTransforms_0_001AC4A0;
typedef union { f32 f; struct { Flags8 b0; Flags8 b1; Flags8 b2; u8 b3; } s; } P;
typedef struct {
    Mtx m;
    Vec x40;
    Vec x50;
    Vec x60;
    Vec x70;
    P x80;
    s8 **x84;
    s32 x88;
    s8 **x8C;
    u8 pad90[0xC];
    s16 x9C;
    s16 x9E;
    u8 padA0[6];
    s8 xA6;
    s8 xA7;
    Flags8 xA8;
    Flags8 xA9;
    u16 xAA;
    s16 xAC;
    s16 xAE;
    s32 xB0;
    f32 xB4;
    s8 *xB8;
    s8 *xBC;
    s8 *xC0[2][2];
} O_ItemObj_DrawAll_0_001AC820;
typedef struct { u8 pad[0x8C]; s16 x8C; s16 x8E; u8 p90[0xC4]; s32 *x154; u8 p158[0x80]; u8 b0:1; } O_ItemObj_TestVisible_0_001ACD90;
typedef struct { u8 a:4; u8 b:1; u8 c:3; } BF;
typedef struct { unsigned char : 3; unsigned char f : 1; char pad[3]; } H_ItemObj_FilterOpaque_0_001ACFE0;
typedef struct { unsigned char : 2; unsigned char f : 1; char pad[3]; } H_ItemObj_FilterTranslucent_0_001AD030;
typedef struct { u8 p[0x10]; u8 **tbl; u8 p14[2]; u16 n; } M;
typedef struct { u8 p[0x84]; M ****m; u8 p88[8]; s32 x90; u8 p94[0x14]; Flags8 f; } O_ItemObj_SetRotation_0_001AD0C0;
typedef struct { u8 pad[0x10]; u8 (**tbl)[16]; u16 n14; u16 n16; } Q_ItemObj_SetAnim_0_001AD1C0;
typedef struct { Q_ItemObj_SetAnim_0_001AD1C0 *q; } R_ItemObj_SetAnim_0_001AD1C0;
typedef struct { R_ItemObj_SetAnim_0_001AD1C0 *r; } Anim_ItemObj_SetAnim_0_001AD1C0;
typedef struct { Anim_ItemObj_SetAnim_0_001AD1C0 *a; } M84_ItemObj_SetAnim_0_001AD1C0;
typedef struct {
    u8 pad[0x84];
    M84_ItemObj_SetAnim_0_001AD1C0 *x84;
    u8 pad88[8];
    s32 x90;
    u8 pad94[0x14];
    Flags8 xA8;
} Node_ItemObj_SetAnim_0_001AD1C0;
typedef struct { u8 pad[8]; u16 x8; u16 xA; } E;
typedef struct { u8 b[0x40]; } Dst;
typedef struct { u8 pad[0x14]; u16 n14; u16 n16; } Q_ItemObj_Animate_0_001AD4E0;
typedef struct { Q_ItemObj_Animate_0_001AD4E0 *q; } R_ItemObj_Animate_0_001AD4E0;
typedef struct { R_ItemObj_Animate_0_001AD4E0 *r; u8 pad4[4]; u16 id; u8 padA[2]; f32 x; f32 y; f32 spd; } Anim_ItemObj_Animate_0_001AD4E0;
typedef struct { u8 pad[0x52]; s8 x52; u8 pad53[9]; s8 x5C[2][2]; u8 pad60[0x30]; } Ent_ItemObj_Animate_0_001AD4E0;
typedef struct { Anim_ItemObj_Animate_0_001AD4E0 *a; } M84_ItemObj_Animate_0_001AD4E0;
typedef struct {
    Mtx m;
    Vec v40, v50, v60, v70;
    s32 x80;
    M84_ItemObj_Animate_0_001AD4E0 *x84;
    s8 *x88;
    u8 pad8C[0x10];
    s16 idx;
    u8 pad9E[2];
    f32 xA0;
    u8 xA4;
    u8 padA5[3];
    Flags8 xA8;
    Flags8 xA9;
    u8 padAA[6];
    f32 xB0;
    u8 padB4[4];
    s32 xB8;
    s32 xBC;
    s32 xC0[2][2];
} Node_ItemObj_Animate_0_001AD4E0;
typedef struct { u8 pad[0x80]; Vec s; } Ent_ItemObj_GetScale_0_001ADBA0;
typedef struct { f32 v[4]; } Vec_ItemObj_GetMatrix_0_001ADC60;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x4C]; Vec_ItemObj_GetMatrix_0_001ADC60 a; Vec_ItemObj_GetMatrix_0_001ADC60 b; Vec_ItemObj_GetMatrix_0_001ADC60 c; } Ent_ItemObj_GetMatrix_0_001ADC60;
typedef struct {
    Mtx m;
    Vec_ItemObj_GetMatrix_0_001ADC60 v40, v50, v60, v70;
    u8 pad80[0x1C];
    s16 idx;
    u8 pad9E[0xB];
    u8 fA9;
    u8 padAA[0x26];
} Node_ItemObj_GetMatrix_0_001ADC60;
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H_ItemObj_BindCaps_1_001ADD30;
typedef struct { u8 pad[0x10]; H_ItemObj_BindCaps_1_001ADD30 h; } Ch;
typedef struct { f32 p0[4]; f32 p1[4]; } Ray;
typedef struct { f32 x0; f32 x4; s32 pad8[7]; s32 hit; s32 pad28[6]; } Res;
typedef struct { u8 p:6; u8 v:1; } BF6;
typedef struct {
    u8 pad0[0x30];
    f32 pos[4];
    u8 pad40[0x34];
    f32 x74;
    u8 pad78[0x24];
    s16 x9C;
    u8 pad9E[0xA];
    BF6 xA8;
    u8 padA9[7];
    f32 xB0;
} Obj_ItemObj_DropToGround_0_001AE0E0;
typedef struct { u8 pad[8]; u16 x8; u8 padA[0x90 - 0xA]; } Ent_ItemObj_AllocSlot_1_001AE360;
typedef struct { u8 pad[8]; Obj3D *t[2][16]; } Tbl;
extern s8 D_003139A0[];
extern f32 D_00222850[];
extern Ent_ItemObj_UpdateTransforms_0_001AC4A0 *D_002022B0;
extern s8 D_0030D0E0[];
extern O_ItemObj_TestVisible_0_001ACD90 **D_002022BC;
extern BF D_00222A50[];
extern Node_ItemObj_Animate_0_001AD4E0 *D_002022A4;
extern s8 D_001FDA30[];
extern s32 D_00201E80;
extern Tbl D_004AC5A0;
s32 ItemObj_OffsetAll_0_001AC0F0(s32 arg0, u16 arg1, s32 arg2);
void ItemObj_TestPickRay_0_001AC200(Obj_ItemObj_TestPickRay_0_001AC200 *o, Obj_ItemObj_TestPickRay_0_001AC200 **best, f32 *dist);
Obj3D* ItemObj_FindPickTarget_0_001AC3E0(void);
void ItemObj_UpdateTransforms_0_001AC4A0(void *arg0);
void ItemObj_DrawAll_0_001AC820(O_ItemObj_DrawAll_0_001AC820 *o, s32 (*cb)(s8 **, P), s32 chk);
s32 ItemObj_TestVisible_0_001ACD90(O_ItemObj_TestVisible_0_001ACD90 **a0, s16 bit);
void ItemObj_DrawPass_1_001ACEB0(s32 arg0);
s32 ItemObj_FilterOpaque_0_001ACFE0(void *a, H_ItemObj_FilterOpaque_0_001ACFE0 h);
s32 ItemObj_FilterTranslucent_0_001AD030(void *a, H_ItemObj_FilterTranslucent_0_001AD030 h);
void ItemObj_Draw_0_001AD080(void);
void ItemObj_SetRotation_0_001AD0C0(O_ItemObj_SetRotation_0_001AD0C0 *o, s32 id);
void ItemObj_SetAnim_0_001AD1C0(Node_ItemObj_SetAnim_0_001AD1C0 *o, s32 a1);
void ItemObj_SpawnProjectile_0_001AD2C0(s32 a0, s32 a1, s32 a2, E *e, s32 t0, s32 t1);
void ItemObj_ResetAll_0_001AD390(void);
void ItemObj_Animate_0_001AD4E0(Node_ItemObj_Animate_0_001AD4E0 *o0, f32 dt);
void ItemObj_UpdateAll_1_001ADA30(f32 arg0);
void ItemObj_GetScale_0_001ADBA0(Obj3D *n, Vec *out);
void ItemObj_GetMatrix_0_001ADC60(Node_ItemObj_GetMatrix_0_001ADC60 *n, Mtx *out);
void ItemObj_BindCaps_1_001ADD30(void);
void ItemObj_DropToGround_0_001AE0E0(s32 arg0, Obj_ItemObj_DropToGround_0_001AE0E0 *obj);
s32 ItemObj_FindGround_0_001AE250(s32 arg0, f32 *pos, f32 *out);
Obj3D* ItemObj_AllocSlot_1_001AE360(s16 id, u8 side);
void sceVu0AddVector(s32, s8 *, s8 *, s32);
void sceVu0CopyVector(s32, s8 *);
void memcpy(void *, void *, s32);
void sceVu0InterVector(f32, f32 *, f32 *, f32 *);
void sceVu0ApplyMatrix(f32 *, void *, f32 *);
f32 fabsf(f32);
void sceVu0MulMatrix(void *, void *, void *);
void Mtx_Compose_2_00173FD0(void*, void *, void *, void *);
void Sfx_SetFlag_0_00167640(s8 *, s32);
void Sfx_SetOwnerFlag_0_0016B200(s8 *, s32);
s32 Player_IsCrouching_0_001C9A20(void);
void GsPkt_SetLayer_1_00154700(s32, s32);
s8* Map_FindSfxEntry_0_001B7300(s8 *, s32);
void Light_CopyColor_0_0015B6B0(Vec *, s8 *);
void Fog_SetReg_0_0015B1C0(Vec *, s8 *);
void Fog_ApplyDefault_0_0015B270(void);
s8* Mdl_GetFrameData_0_001715B0(void *);
s8* Player_GetCameraData_0_001C9B40(void);
void Mtx_ScaleRotation_0_0015CC40(void *, f32);
void Mdl_DrawLit_0_0016B970(s8 *, void *, s32, s8 *, s32, s32, s32);
void Mdl_DrawLitWrap_0_0016B960(s8 *, void *, s32, s8 *, s32, s32);
void Mdl_DrawMeshes_1_0016C7E0(s32, s8 *, s8 *, P);
void Mdl_DrawMeshesB_1_0016CD80(s32, s8 *, s8 *, P);
void GsPkt_EndLayer_1_00155900(void);
void Map_UpdateTexAnim_0_001B40B0(s8 *);
void GsPkt_CloseChain_1_001549D0(void);
void Mdl_SetLayerForMesh_0_0016B360(void *a, H_ItemObj_FilterOpaque_0_001ACFE0 h, s32 c);
void Mdl_FlushLayer_0_0016B280(void);
void Mdl_SetBoneRotation_0_001710D0(void *, s16, f32, f32, f32);
void Attack_PlaySe_0_001D1E80(s32, s32, E *, s32, s32);
s8* Attack_SpawnSfx_0_001D1F20(s32, s32, s32, s32, E *, s32, s32);
void Sfx_SetOwner_1_00167600(s8 *, Actor *);
void Player_InitAttack_0_001C79B0(Dst *);
void Sfx_GetState_0_001672B0(s8 *, Dst *);
f32 Mdl_GetMotionLength_0_00173F70(Q_ItemObj_Animate_0_001AD4E0 *, u16);
void Mdl_AnimateWrap_0_00171B70(Anim_ItemObj_Animate_0_001AD4E0 *, u16, f32);
void Mdl_UpdateBoneMatricesCur_0_00171540(Anim_ItemObj_Animate_0_001AD4E0 *, Node_ItemObj_Animate_0_001AD4E0 *);
void Mdl_RunMotionEvents_0_001717A0(Anim_ItemObj_Animate_0_001AD4E0 *, u16, f32, f32, void *);
void Seg_Init_1_001502A0(Vec *, Vec *, Vec *, f32);
void Sfx_SetColor_0_00167670(s32, Vec *);
void Sfx_SetTransform_1_001677C0(s32, void *);
void ItemObj_Free_1_001AF4A0(Obj3D *);
void ItemObj_SaveState_1_001AE510(void);
void sceVu0MulVector(Vec *, Vec *, Vec *);
Ch* Node_FindById_2_0014DCD0(s32, s32);
void memset(void *, s32, s32);
void MapColl_RayVsObjects_0_001B2180(s32, Res *, Ray *, s32, s32);

/* ItemObj_OffsetAll_0_001AC0F0 */
s32 ItemObj_OffsetAll_0_001AC0F0(s32 arg0, u16 arg1, s32 arg2) {
    s32 i;
    Obj3D *p;
    s32 j;
    Obj3D *row;

    sceVu0CopyVector(arg2, D_003139A0);
    if (arg1 == 0) {
        return 0;
    }
    for (i = 0, row = D_004AE370[0]; i < 2; i++, row += 64) {
        for (p = row, j = 0; j < 0x40; j++, p++) {
            if (p->x9E == 0 && p->xA9.f.b2 == 0 && p->x8C != NULL && *p->x8C != NULL
                && p->x9C != -1 && **p->x8C == arg0 && p->xAA == arg1) {
                sceVu0AddVector(arg2, (s8 *)p + 0x40, (s8 *)p + 0x70, i);
                return 1;
            }
        }
    }
    return 0;
}

/* ItemObj_TestPickRay_0_001AC200 */
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_TestPickRay_0_001AC200
void sceVu0CopyVector__as_ItemObj_TestPickRay_0_001AC200(f32 *, f32 *);

void ItemObj_TestPickRay_0_001AC200(Obj_ItemObj_TestPickRay_0_001AC200 *o, Obj_ItemObj_TestPickRay_0_001AC200 **best, f32 *dist) {
    f32 v[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 x, y, z, d;
    if (o->x9C != -1 && o->xA8.b0 && !o->xA8.b2 && o->xA4 == 0) {
        if (o->x88 != 0) {
            memcpy(a, o->x88, 0x10);
            memcpy(b, o->x88 + 0x40, 0x10);
            sceVu0InterVector(0.5f, v, a, b);
            v[3] = 1.0f;
            sceVu0ApplyMatrix(v, o, v);
        } else {
            sceVu0CopyVector(v, o->pos);
        }
        sceVu0ApplyMatrix(v, D_00222850, v);
        z = v[2];
        x = v[0];
        y = v[1];
        if (!(z < 0.0f) && z <= 330.0f) {
            if (!(fabsf(x) <= 150.0f) || !(fabsf(y) <= 100.0f)) return;
            z = 2.0f * z + 10.0f * fabsf(x);
            d = z + 10.0f * fabsf(y);
            if (d < *dist) {
                *dist = d;
                *best = o;
            }
        }
    }
}
#undef sceVu0CopyVector

/* ItemObj_FindPickTarget_0_001AC3E0 */
#define ItemObj_TestPickRay_0_001AC200 ItemObj_TestPickRay_0_001AC200__as_ItemObj_FindPickTarget_0_001AC3E0
void ItemObj_TestPickRay_0_001AC200__as_ItemObj_FindPickTarget_0_001AC3E0(Obj3D *, Obj3D **, f32 *);
Obj3D *ItemObj_FindPickTarget_0_001AC3E0(void) {
    Obj3D *best;
    f32 dist;
    s32 i;
    best = NULL;
    dist = 1e8f;
    for (i = 0; i < 64; i++) {
        ItemObj_TestPickRay_0_001AC200(&D_004AE370[0][i], &best, &dist);
        ItemObj_TestPickRay_0_001AC200(&D_004AE370[1][i], &best, &dist);
    }
    for (i = 0; i < 16; i++) {
        ItemObj_TestPickRay_0_001AC200(&D_004AC970[0][i], &best, &dist);
        ItemObj_TestPickRay_0_001AC200(&D_004AC970[1][i], &best, &dist);
    }
    return best;
}
#undef ItemObj_TestPickRay_0_001AC200

/* ItemObj_UpdateTransforms_0_001AC4A0 */
#define sceVu0AddVector sceVu0AddVector__as_ItemObj_UpdateTransforms_0_001AC4A0
void sceVu0AddVector__as_ItemObj_UpdateTransforms_0_001AC4A0(void *, void *, void *);
#define Mtx_Compose_2_00173FD0 Mtx_Compose_2_00173FD0__as_ItemObj_UpdateTransforms_0_001AC4A0
void Mtx_Compose_2_00173FD0__as_ItemObj_UpdateTransforms_0_001AC4A0(void *, Vec_ItemObj_UpdateTransforms_0_001AC4A0 *, Vec_ItemObj_UpdateTransforms_0_001AC4A0 *, Vec_ItemObj_UpdateTransforms_0_001AC4A0 *);
#define D_004AC970 D_004AC970__as_ItemObj_UpdateTransforms_0_001AC4A0
extern Node_ItemObj_UpdateTransforms_0_001AC4A0 D_004AC970__as_ItemObj_UpdateTransforms_0_001AC4A0[];
#define D_004AE370 D_004AE370__as_ItemObj_UpdateTransforms_0_001AC4A0
extern Node_ItemObj_UpdateTransforms_0_001AC4A0 D_004AE370__as_ItemObj_UpdateTransforms_0_001AC4A0[];
static inline void upd_ItemObj_UpdateTransforms_0_001AC4A0(Node_ItemObj_UpdateTransforms_0_001AC4A0 *n, void *m) {
    if (n->idx != -1) {
        sceVu0AddVector(&n->v70, &n->v70, m);
        {
        Ent_ItemObj_UpdateTransforms_0_001AC4A0 *tbl = D_002022B0;
        if (n != NULL && n->idx != -1) {
            if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
                Mtx_Compose_2_00173FD0(n, &n->v40, &n->v50, &n->v60);
            } else {
                Mtx tmp;
                Ent_ItemObj_UpdateTransforms_0_001AC4A0 *e = &tbl[n->idx];
                Mtx_Compose_2_00173FD0(&tmp, &e->a, &e->b, &e->c);
                Mtx_Compose_2_00173FD0(n, &n->v40, &n->v50, &n->v60);
                sceVu0MulMatrix(n, n, &tmp);
            }
            sceVu0AddVector(&n->m.m[3], &n->m.m[3], &n->v70);
        }
        }
    }
}

void ItemObj_UpdateTransforms_0_001AC4A0(void *arg0) {
    s32 i;
    Node_ItemObj_UpdateTransforms_0_001AC4A0 *n;

    n = D_004AE370;
    for (i = 0; i < 0x40; i++) {
        upd_ItemObj_UpdateTransforms_0_001AC4A0(n, arg0);
        upd_ItemObj_UpdateTransforms_0_001AC4A0(n + 0x40, arg0);
        n++;
    }
    {
    Node_ItemObj_UpdateTransforms_0_001AC4A0 *m = D_004AC970;
    for (i = 0; i < 0x10; i++) {
        upd_ItemObj_UpdateTransforms_0_001AC4A0(m, arg0);
        upd_ItemObj_UpdateTransforms_0_001AC4A0(m + 0x10, arg0);
        m++;
    }
    }
}
#undef sceVu0AddVector
#undef Mtx_Compose_2_00173FD0
#undef D_004AC970
#undef D_004AE370

/* ItemObj_DrawAll_0_001AC820 */
#define Mdl_GetFrameData_0_001715B0 Mdl_GetFrameData_0_001715B0__as_ItemObj_DrawAll_0_001AC820
s8 *Mdl_GetFrameData_0_001715B0__as_ItemObj_DrawAll_0_001AC820(s8 **);
#define ItemObj_TestVisible_0_001ACD90 ItemObj_TestVisible_0_001ACD90__as_ItemObj_DrawAll_0_001AC820
s32 ItemObj_TestVisible_0_001ACD90__as_ItemObj_DrawAll_0_001AC820(s8 **, s16);

void ItemObj_DrawAll_0_001AC820(O_ItemObj_DrawAll_0_001AC820 *o, s32 (*cb)(s8 **, P), s32 chk) {
    s32 i;
    Flags8 *f;
    s8 **pp;
    s8 *q;
    s8 **h;
    s32 id;
    s8 *r;
    s8 *v;
    Vec buf;
    u8 buf2[0xA0];
    P p;

    if (o->x9C != -1 && o->xA8.f.b0) {
    if (o->xB8 != NULL) Sfx_SetFlag_0_00167640(o->xB8, 0);
    if (o->xBC != NULL) Sfx_SetFlag_0_00167640(o->xBC, 0);
    for (i = 0; i < 4; i++) {
        if (o->xC0[i / 2][i % 2] != NULL) Sfx_SetFlag_0_00167640(o->xC0[i / 2][i % 2], 0);
    }
    if (o->xA8.f.b7 && !cb(o->x84, o->x80) && (chk == 0 || ItemObj_TestVisible_0_001ACD90(o->x8C, o->xAE))) {
    if (o->x8C != NULL && *o->x8C != NULL) Map_UpdateTexAnim_0_001B40B0(*o->x8C);
    p = o->x80;
    f = &p.s.b2;
    f->f.b4 = 0;
    if (o->xB4 < 1.0f) {
        p.s.b0.f.b4 = 1;
        f->f.b4 = 1;
    }
    if (o->xB8 != NULL) {
        Sfx_SetFlag_0_00167640(o->xB8, 1);
        if (o->xA8.f.b2) Sfx_SetOwnerFlag_0_0016B200(o->xB8, 1);
    }
    if (o->xBC != NULL && Player_IsCrouching_0_001C9A20()) {
        Sfx_SetFlag_0_00167640(o->xBC, 1);
        Sfx_SetOwnerFlag_0_0016B200(o->xBC, 1);
    }
    for (i = 0; i < 4; i++) {
        pp = &o->xC0[i / 2][i % 2];
        if (*pp != NULL) {
            Sfx_SetFlag_0_00167640(*pp, 1);
            if (o->xA8.f.b2) Sfx_SetOwnerFlag_0_0016B200(*pp, 1);
        }
    }
    if (o->xA8.f.b2) {
        GsPkt_SetLayer_1_00154700(5, 0);
        if (o->x9C / 100 == 3) f->f.b5 = 1;
    }
    q = NULL;
    if (o->xA7 != -1 && o->x8C != NULL) q = Map_FindSfxEntry_0_001B7300(*o->x8C, o->xA7);
    if (q != NULL) {
        Light_CopyColor_0_0015B6B0(&buf, q + 0x20);
        Fog_SetReg_0_0015B1C0(&buf, q + 0x10);
    } else {
        Fog_ApplyDefault_0_0015B270();
    }
    h = o->x84;
    id = ***(s32 ***)h;
    r = Mdl_GetFrameData_0_001715B0(h);
    if (o->xA8.f.b2 && o->x9C == 0x14A) {
        ((Flags8 *)(r + 0x5B8))->f.b3 = 1;
        ((Flags8 *)(r + 0x1738))->f.b3 = 1;
    }
    if (o->xA8.f.b2) {
        if (o->x8C != NULL && *o->x8C != NULL && o->xA6 != -1) {
            v = *(s8 **)(*o->x8C + 0x188) + o->xA6 * 0xA0;
        } else {
            v = Player_GetCameraData_0_001C9B40();
        }
    } else if (o->xA6 == -1 || o->x8C == NULL) {
        v = D_0030D0E0;
    } else {
        v = *(s8 **)(*o->x8C + 0x188) + o->xA6 * 0xA0;
    }
    if (o->xB4 < 1.0f) {
        memcpy(buf2, v, 0xA0);
        Mtx_ScaleRotation_0_0015CC40(buf2, o->xB4);
        Mdl_DrawLit_0_0016B970(r, buf2, id, r + 0x200, 0, 2, 1);
    } else {
        Mdl_DrawLitWrap_0_0016B960(r, v, id, r + 0x200, 0, 2);
    }
    if (o->x80.s.b1.f.b7) {
        Mdl_DrawMeshes_1_0016C7E0(id, *h, r, p);
    } else {
        Mdl_DrawMeshesB_1_0016CD80(id, *h, r, p);
    }
    if (o->xA8.f.b2) GsPkt_EndLayer_1_00155900();
    }
    }
}
#undef Mdl_GetFrameData_0_001715B0
#undef ItemObj_TestVisible_0_001ACD90

/* ItemObj_TestVisible_0_001ACD90 */
s32 ItemObj_TestVisible_0_001ACD90(O_ItemObj_TestVisible_0_001ACD90 **a0, s16 bit) {
    s32 m;
    s16 a;
    s32 *tbl;
    O_ItemObj_TestVisible_0_001ACD90 *p;
    s32 n;
    s16 idx;
    O_ItemObj_TestVisible_0_001ACD90 *o;
    m = 0;
    n = 0;
    if (a0 == 0 || (o = *a0) == 0 || !o->b0) return 0;
    if (bit == -1) return 1;
    tbl = o->x154;
    a = o->x8E;
    idx = o->x8C;
    if (a != -2) idx = a;
    if (idx != -1) m = tbl[idx];
    if (D_002022BC && (p = *D_002022BC) && p != o && p->x8C != -1) n = p->x154[p->x8C + 0x20];
    if (idx == -1) {
        if (!(n & (1 << bit))) return 0;
    } else {
        if (!(m & (1 << bit))) return 0;
    }
    return 1;
}

/* ItemObj_DrawPass_1_001ACEB0 */
#define ItemObj_DrawAll_0_001AC820 ItemObj_DrawAll_0_001AC820__as_ItemObj_DrawPass_1_001ACEB0
void ItemObj_DrawAll_0_001AC820__as_ItemObj_DrawPass_1_001ACEB0(void *, s32, s32);
#define D_004AC630 D_004AC630__as_ItemObj_DrawPass_1_001ACEB0
extern u8 D_004AC630__as_ItemObj_DrawPass_1_001ACEB0[];
#define D_004AC970 D_004AC970__as_ItemObj_DrawPass_1_001ACEB0
extern u8 D_004AC970__as_ItemObj_DrawPass_1_001ACEB0[];
#define D_004AE370 D_004AE370__as_ItemObj_DrawPass_1_001ACEB0
extern u8 D_004AE370__as_ItemObj_DrawPass_1_001ACEB0[];

void ItemObj_DrawPass_1_001ACEB0(s32 arg0) {
    s32 i;
    u8 *p;
    u8 *q;
    s32 j;
    u8 *r;
    s32 k;
    for (i = 0, p = D_004AE370; i < 0x40; i++, p += 0xD0) {
        ItemObj_DrawAll_0_001AC820(p, arg0, 1);
        ItemObj_DrawAll_0_001AC820(p + 0x3400, arg0, 1);
    }
    for (j = 0, q = D_004AC970; j < 0x10; j++, q += 0xD0) {
        ItemObj_DrawAll_0_001AC820(q, arg0, 0);
        ItemObj_DrawAll_0_001AC820(q + 0xD00, arg0, 0);
    }
    D_00222A50[0].b = 1;
    for (k = 0, r = D_004AC630; k < 4; k++, r += 0xD0) {
        ItemObj_DrawAll_0_001AC820(r, arg0, 0);
    }
    D_00222A50[0].b = 0;
    GsPkt_CloseChain_1_001549D0();
}
#undef ItemObj_DrawAll_0_001AC820
#undef D_004AC630
#undef D_004AC970
#undef D_004AE370

/* ItemObj_FilterOpaque_0_001ACFE0 */
s32 ItemObj_FilterOpaque_0_001ACFE0(void *a, H_ItemObj_FilterOpaque_0_001ACFE0 h)
{
    if (h.f)
        return 1;
    Mdl_SetLayerForMesh_0_0016B360(a, h, 3);
    return 0;
}

/* ItemObj_FilterTranslucent_0_001AD030 */
#define Mdl_SetLayerForMesh_0_0016B360 Mdl_SetLayerForMesh_0_0016B360__as_ItemObj_FilterTranslucent_0_001AD030
void Mdl_SetLayerForMesh_0_0016B360__as_ItemObj_FilterTranslucent_0_001AD030(void *a, H_ItemObj_FilterTranslucent_0_001AD030 h, s32 c);

s32 ItemObj_FilterTranslucent_0_001AD030(void *a, H_ItemObj_FilterTranslucent_0_001AD030 h)
{
    if (!h.f)
        return 1;
    Mdl_SetLayerForMesh_0_0016B360(a, h, 0);
    return 0;
}
#undef Mdl_SetLayerForMesh_0_0016B360

/* ItemObj_Draw_0_001AD080 */
#define ItemObj_DrawPass_1_001ACEB0 ItemObj_DrawPass_1_001ACEB0__as_ItemObj_Draw_0_001AD080
void ItemObj_DrawPass_1_001ACEB0__as_ItemObj_Draw_0_001AD080(void (*f)(void));
#define ItemObj_FilterTranslucent_0_001AD030 ItemObj_FilterTranslucent_0_001AD030__as_ItemObj_Draw_0_001AD080
void ItemObj_FilterTranslucent_0_001AD030__as_ItemObj_Draw_0_001AD080(void);
#define ItemObj_FilterOpaque_0_001ACFE0 ItemObj_FilterOpaque_0_001ACFE0__as_ItemObj_Draw_0_001AD080
void ItemObj_FilterOpaque_0_001ACFE0__as_ItemObj_Draw_0_001AD080(void);

void ItemObj_Draw_0_001AD080(void)
{
    ItemObj_DrawPass_1_001ACEB0(ItemObj_FilterTranslucent_0_001AD030);
    ItemObj_DrawPass_1_001ACEB0(ItemObj_FilterOpaque_0_001ACFE0);
    Mdl_FlushLayer_0_0016B280();
}
#undef ItemObj_DrawPass_1_001ACEB0
#undef ItemObj_FilterTranslucent_0_001AD030
#undef ItemObj_FilterOpaque_0_001ACFE0

/* ItemObj_SetRotation_0_001AD0C0 */
#define Mdl_SetBoneRotation_0_001710D0 Mdl_SetBoneRotation_0_001710D0__as_ItemObj_SetRotation_0_001AD0C0
void Mdl_SetBoneRotation_0_001710D0__as_ItemObj_SetRotation_0_001AD0C0(M ***, s16, f32, f32, f32);

void ItemObj_SetRotation_0_001AD0C0(O_ItemObj_SetRotation_0_001AD0C0 *o, s32 id) {
    u8 v;
    s32 w;
    if (o != NULL && (o->f.b & 1)) {
        if (o->x90 != 0) {
            v = (u8)id;
        } else {
            v = (*(***o->m)->tbl + o->x90 * 16)[id];
        }
        w = v;
        if ((***o->m)->n != 0) {
            Mdl_SetBoneRotation_0_001710D0(*o->m, w, 1.0f, 0.0f, 0.0f);
            o->f.f.b3 = 1;
            o->f.f.b4 = 0;
            o->f.f.b5 = 0;
        }
    }
}
#undef Mdl_SetBoneRotation_0_001710D0

/* ItemObj_SetAnim_0_001AD1C0 */
#define Mdl_SetBoneRotation_0_001710D0 Mdl_SetBoneRotation_0_001710D0__as_ItemObj_SetAnim_0_001AD1C0
void Mdl_SetBoneRotation_0_001710D0__as_ItemObj_SetAnim_0_001AD1C0(Anim_ItemObj_SetAnim_0_001AD1C0 *, s16, f32, f32, f32);
static inline u8 get(Node_ItemObj_SetAnim_0_001AD1C0 *o, s32 a1) {
    if (o->x90 != 0) {
        return a1;
    }
    return (*o->x84->a->r->q->tbl)[o->x90][a1];
}

void ItemObj_SetAnim_0_001AD1C0(Node_ItemObj_SetAnim_0_001AD1C0 *o, s32 a1) {
    s32 v;
    Anim_ItemObj_SetAnim_0_001AD1C0 *a;

    if (o != NULL && o->xA8.f.b0) {
        v = get(o, a1);
        a = o->x84->a;
        if (a->r->q->n16 != 0) {
            Mdl_SetBoneRotation_0_001710D0(a, v, 1.0f, 0.0f, 0.0f);
            o->xA8.f.b3 = 0;
            o->xA8.f.b4 = 1;
            o->xA8.f.b5 = 0;
        }
    }
}
#undef Mdl_SetBoneRotation_0_001710D0

/* ItemObj_SpawnProjectile_0_001AD2C0 */
void ItemObj_SpawnProjectile_0_001AD2C0(s32 a0, s32 a1, s32 a2, E *e, s32 t0, s32 t1) {
    Dst d;
    s8 *o;
    if (t1) {
        switch (e->x8) {
        case 0:
            Attack_PlaySe_0_001D1E80(a0, a2, e, t0, t1);
            break;
        case 1:
            o = Attack_SpawnSfx_0_001D1F20(a0, 0, a1, a2, e, t0, t1);
            if (o) {
                Sfx_SetOwner_1_00167600(o, D_002022E4);
                if (e->xA == 0xFFFF) {
                    Player_InitAttack_0_001C79B0(&d);
                    Sfx_GetState_0_001672B0(o, &d);
                }
            }
            break;
        }
    }
}

/* ItemObj_ResetAll_0_001AD390 */
void ItemObj_ResetAll_0_001AD390(void) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        if (D_004AE370[0][i].x9C != -1 && (D_004AE370[0][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AE370[0][i].x84);
        }
        if (D_004AE370[1][i].x9C != -1 && (D_004AE370[1][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AE370[1][i].x84);
        }
    }
    for (i = 0; i < 0x10; i++) {
        if (D_004AC970[0][i].x9C != -1 && (D_004AC970[0][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AC970[0][i].x84);
        }
        if (D_004AC970[1][i].x9C != -1 && (D_004AC970[1][i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AC970[1][i].x84);
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_004AC630[i].x9C != -1 && (D_004AC630[i].xA8.b & 1)) {
            Mdl_ResetBones_0_00171610(D_004AC630[i].x84);
        }
    }
}

/* ItemObj_Animate_0_001AD4E0 */
#define sceVu0AddVector sceVu0AddVector__as_ItemObj_Animate_0_001AD4E0
void sceVu0AddVector__as_ItemObj_Animate_0_001AD4E0(void *, void *, void *);
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_Animate_0_001AD4E0
void sceVu0CopyVector__as_ItemObj_Animate_0_001AD4E0(Vec *, void *);
#define Mtx_Compose_2_00173FD0 Mtx_Compose_2_00173FD0__as_ItemObj_Animate_0_001AD4E0
void Mtx_Compose_2_00173FD0__as_ItemObj_Animate_0_001AD4E0(void *, Vec *, Vec *, Vec *);
#define ItemObj_SpawnProjectile_0_001AD2C0 ItemObj_SpawnProjectile_0_001AD2C0__as_ItemObj_Animate_0_001AD4E0
void ItemObj_SpawnProjectile_0_001AD2C0__as_ItemObj_Animate_0_001AD4E0();
#define Mdl_GetFrameData_0_001715B0 Mdl_GetFrameData_0_001715B0__as_ItemObj_Animate_0_001AD4E0
s8 *Mdl_GetFrameData_0_001715B0__as_ItemObj_Animate_0_001AD4E0(M84_ItemObj_Animate_0_001AD4E0 *);
#define D_002022B0 D_002022B0__as_ItemObj_Animate_0_001AD4E0
extern Ent_ItemObj_Animate_0_001AD4E0 *D_002022B0__as_ItemObj_Animate_0_001AD4E0;
static inline void upd_ItemObj_Animate_0_001AD4E0(Node_ItemObj_Animate_0_001AD4E0 *n) {
    Ent_ItemObj_Animate_0_001AD4E0 *tbl = D_002022B0;
    if (n != NULL && n->idx != -1) {
        if (n->xA9.f.b1) {
            Mtx_Compose_2_00173FD0(n, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent_ItemObj_Animate_0_001AD4E0 *e = &tbl[n->idx];
            Mtx_Compose_2_00173FD0(&tmp, (Vec *)((s8 *)e + 0x60), (Vec *)((s8 *)e + 0x70), (Vec *)((s8 *)e + 0x80));
            Mtx_Compose_2_00173FD0(n, &n->v40, &n->v50, &n->v60);
            sceVu0MulMatrix(n, n, &tmp);
        }
        sceVu0AddVector(&n->m.m[3], &n->m.m[3], &n->v70);
    }
}
static inline Ent_ItemObj_Animate_0_001AD4E0 *ent(s16 i) {
    if (D_002022B0 != NULL && i > 0 && i < 0x400) return &D_002022B0[i];
    return NULL;
}

void ItemObj_Animate_0_001AD4E0(Node_ItemObj_Animate_0_001AD4E0 *o0, f32 dt) {
    s32 i;
    Anim_ItemObj_Animate_0_001AD4E0 *a;
    Node_ItemObj_Animate_0_001AD4E0 *o;
    Ent_ItemObj_Animate_0_001AD4E0 *en;
    R_ItemObj_Animate_0_001AD4E0 *r;
    s32 played;
    Vec e[2];
    Vec d;
    Vec c;
    f32 len;
    s8 *s;

    o = o0;
    played = 0;
    if (o->idx == -1) return;
    if (!o->xA8.f.b0) return;
    a = o->x84->a;
    r = a->r;
    if (r == NULL || r->q == NULL) return;
    if (o->xA4) o->xA4--;
    en = ent(o->idx);
    if (r->q->n16 != 0 && (o->xA8.f.b3 || o->xA8.f.b4)) {
        len = Mdl_GetMotionLength_0_00173F70(r->q, a->id);
        a->y = a->x;
        if (!o->xA8.f.b5) a->x = a->x + dt * a->spd;
        played = 1;
        if (o->xA8.f.b3) {
            if (a->x > len) a->x = a->x - len;
        } else {
            if (o->xA8.f.b5) o->xA8.f.b4 = 0;
            if (a->x > len) {
                a->x = len;
                o->xA8.f.b5 = 1;
            }
        }
        Mdl_AnimateWrap_0_00171B70(a, a->id, a->x);
    }
    if (o->xA8.f.b6) {
        o->xA0 += 50.0f * dt;
        o->v40.y = o->v40.y + o->xA0;
        if (o->v40.y > o->xB0) {
            o->v40.y = o->xB0 - 1.0f;
            o->xA8.f.b6 = 0;
        }
        if (o->v40.y > 29000.0f) {
            o->v40.y = 29000.0f;
            o->xA8.f.b6 = 0;
        }
        upd_ItemObj_Animate_0_001AD4E0(o);
    }
    if (!o->xA9.f.b0) Mdl_UpdateBoneMatricesCur_0_00171540(o->x84->a, o);
    if (played && o->xA8.f.b7) {
        D_002022A4 = o;
        Mdl_RunMotionEvents_0_001717A0(a, a->id, a->x, a->y, ItemObj_SpawnProjectile_0_001AD2C0);
    }
    if (o->xB8) {
        if (o->x88) {
            sceVu0CopyVector(&d, o->x88 + 0x60);
            sceVu0CopyVector(&c, o->x88 + 0x70);
            Seg_Init_1_001502A0(e, &d, &c, d.w);
            Sfx_SetColor_0_00167670(o->xB8, e);
        }
        Sfx_SetTransform_1_001677C0(o->xB8, o);
    }
    if (o->xBC) {
        if (en->x52 > -1 && en->x52 < r->q->n14) {
            s = Mdl_GetFrameData_0_001715B0(o->x84);
            Sfx_SetTransform_1_001677C0(o->xBC, s + (en->x52 + 1) * 0x140 + 0xC0);
        } else {
            Sfx_SetTransform_1_001677C0(o->xBC, o);
        }
    }
    for (i = 0; i < 4; i++) {
        s8 *k;
        s32 h = i / 2;
        s32 l = i % 2;
        s32 *p = &o->xC0[h][l];
        if (*p) {
            k = &en->x5C[h][l];
            if (*k > -1 && *k < r->q->n14) {
                s = Mdl_GetFrameData_0_001715B0(o->x84);
                Sfx_SetTransform_1_001677C0(*p, s + (*k + 1) * 0x140 + 0xC0);
            } else {
                Sfx_SetTransform_1_001677C0(*p, o);
            }
        }
    }
}
#undef sceVu0AddVector
#undef sceVu0CopyVector
#undef Mtx_Compose_2_00173FD0
#undef ItemObj_SpawnProjectile_0_001AD2C0
#undef Mdl_GetFrameData_0_001715B0
#undef D_002022B0

/* ItemObj_UpdateAll_1_001ADA30 */
#define ItemObj_Animate_0_001AD4E0 ItemObj_Animate_0_001AD4E0__as_ItemObj_UpdateAll_1_001ADA30
void ItemObj_Animate_0_001AD4E0__as_ItemObj_UpdateAll_1_001ADA30(Obj3D *, f32);

void ItemObj_UpdateAll_1_001ADA30(f32 arg0) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        ItemObj_Animate_0_001AD4E0(&D_004AE370[0][i], arg0);
        ItemObj_Animate_0_001AD4E0(&D_004AE370[1][i], arg0);
    }
    for (i = 0; i < 0x10; i++) {
        ItemObj_Animate_0_001AD4E0(&D_004AC970[0][i], arg0);
        ItemObj_Animate_0_001AD4E0(&D_004AC970[1][i], arg0);
    }
    for (i = 0; i < 4; i++) {
        ItemObj_Animate_0_001AD4E0(&D_004AC630[i], arg0);
    }
    for (i = 0; i < 0x10; i++) {
        if (D_004AC970[0][i].x9C != -1 && !(D_004AC970[0][i].x40.y < 29000.0f)) {
            ItemObj_Free_1_001AF4A0(&D_004AC970[0][i]);
            ItemObj_SaveState_1_001AE510();
        }
        if (D_004AC970[1][i].x9C != -1 && !(D_004AC970[1][i].x40.y < 29000.0f)) {
            ItemObj_Free_1_001AF4A0(&D_004AC970[1][i]);
            ItemObj_SaveState_1_001AE510();
        }
    }
    ItemObj_SaveState_1_001AE510();
}
#undef ItemObj_Animate_0_001AD4E0

/* ItemObj_GetScale_0_001ADBA0 */
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_GetScale_0_001ADBA0
void sceVu0CopyVector__as_ItemObj_GetScale_0_001ADBA0(Vec *, Vec *);
#define D_002022B0 D_002022B0__as_ItemObj_GetScale_0_001ADBA0
extern Ent_ItemObj_GetScale_0_001ADBA0 *D_002022B0__as_ItemObj_GetScale_0_001ADBA0;
void ItemObj_GetScale_0_001ADBA0(Obj3D *n, Vec *out) {
    Ent_ItemObj_GetScale_0_001ADBA0 *tbl = D_002022B0;
    out->x = out->y = out->z = 1.0f;
    out->w = 0.0f;
    if (n != NULL && n->x9C != -1) {
        if (n->xA9.f.b1) {
            sceVu0CopyVector(out, &n->x60);
            return;
        }
        sceVu0CopyVector(out, &tbl[n->x9C].s);
        sceVu0MulVector(out, out, &n->x60);
    }
}
#undef sceVu0CopyVector
#undef D_002022B0

/* ItemObj_GetMatrix_0_001ADC60 */
#define sceVu0AddVector sceVu0AddVector__as_ItemObj_GetMatrix_0_001ADC60
void sceVu0AddVector__as_ItemObj_GetMatrix_0_001ADC60(void *, void *, void *);
#define Mtx_Compose_2_00173FD0 Mtx_Compose_2_00173FD0__as_ItemObj_GetMatrix_0_001ADC60
void Mtx_Compose_2_00173FD0__as_ItemObj_GetMatrix_0_001ADC60(void *, Vec_ItemObj_GetMatrix_0_001ADC60 *, Vec_ItemObj_GetMatrix_0_001ADC60 *, Vec_ItemObj_GetMatrix_0_001ADC60 *);
#define D_002022B0 D_002022B0__as_ItemObj_GetMatrix_0_001ADC60
extern Ent_ItemObj_GetMatrix_0_001ADC60 *D_002022B0__as_ItemObj_GetMatrix_0_001ADC60;

void ItemObj_GetMatrix_0_001ADC60(Node_ItemObj_GetMatrix_0_001ADC60 *n, Mtx *out) {
    Ent_ItemObj_GetMatrix_0_001ADC60 *tbl = D_002022B0;
    if (n != NULL && n->idx != -1) {
        if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
            Mtx_Compose_2_00173FD0(out, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent_ItemObj_GetMatrix_0_001ADC60 *e = &tbl[n->idx];
            Mtx_Compose_2_00173FD0(&tmp, &e->a, &e->b, &e->c);
            Mtx_Compose_2_00173FD0(out, &n->v40, &n->v50, &n->v60);
            sceVu0MulMatrix(out, out, &tmp);
        }
        sceVu0AddVector(&out->m[3], &out->m[3], &n->v70);
    }
}
#undef sceVu0AddVector
#undef Mtx_Compose_2_00173FD0
#undef D_002022B0

/* ItemObj_BindCaps_1_001ADD30 */
/* the FOURCC literal lives in .rodata */
#pragma readonly_strings on
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

static inline void fix(Obj3D *o) {
    Ch *c;
    if (o->x9C != -1 && o->xA8.f.b0) {
        o->x88 = 0;
        c = Node_FindById_2_0014DCD0(*((s32 **)***(s32 ****)o->x84)[4], "CAPS"[0] | ("CAPS"[1] << 8) | ("CAPS"[2] << 16) | ("CAPS"[3] << 24));
        if (c != NULL) {
            o->x88 = (s32)DATA((H_ItemObj_BindCaps_1_001ADD30 *)((s32)c + 0x10));
        }
    }
}

void ItemObj_BindCaps_1_001ADD30(void) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        fix(&D_004AE370[0][i]);
        fix(&D_004AE370[1][i]);
    }
    for (i = 0; i < 0x10; i++) {
        fix(&D_004AC970[0][i]);
        fix(&D_004AC970[1][i]);
    }
    for (i = 0; i < 4; i++) {
        fix(&D_004AC630[i]);
    }
}

/* ItemObj_DropToGround_0_001AE0E0 */
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_DropToGround_0_001AE0E0
void sceVu0CopyVector__as_ItemObj_DropToGround_0_001AE0E0(f32 *, f32 *);

void ItemObj_DropToGround_0_001AE0E0(s32 arg0, Obj_ItemObj_DropToGround_0_001AE0E0 *obj) {
    Res res;
    Ray ray;
    s32 i;
    s32 side;

    side = 0;
    if (obj == 0) {
        return;
    }
    if (obj->x9C == -1) {
        return;
    }
    sceVu0CopyVector(ray.p0, obj->pos);
    ray.p0[3] = 1.0f;
    sceVu0CopyVector(ray.p1, obj->pos);
    ray.p1[3] = 1.0f;
    ray.p1[1] += 60000.0f;
    memset(&res, 0, 0x40);
    if (arg0 == (&D_00201E80)[2]) {
        side = 0;
    }
    if (arg0 == (&D_00201E80)[3]) {
        side = 1;
    }
    for (i = 0; i < 2; i++) {
        s32 *p = ((s32 **)(&D_00201E80 + 2))[side];
        if (p != 0) {
            MapColl_RayVsObjects_0_001B2180(*p, &res, &ray, 6, 3);
            if (res.hit != 0) {
                break;
            }
        }
        side = !side;
    }
    if (res.hit != 0) {
        obj->xB0 = res.x4 - obj->x74;
    } else {
        obj->xB0 = 50000.0f;
    }
    obj->xA8.v = 1;
}
#undef sceVu0CopyVector

/* ItemObj_FindGround_0_001AE250 */
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_FindGround_0_001AE250
void sceVu0CopyVector__as_ItemObj_FindGround_0_001AE250(f32 *, f32 *);

s32 ItemObj_FindGround_0_001AE250(s32 arg0, f32 *pos, f32 *out) {
    Res res;
    Ray ray;
    s32 i;
    s32 side;

    side = 0;
    sceVu0CopyVector(ray.p0, pos);
    ray.p0[3] = 1.0f;
    sceVu0CopyVector(ray.p1, ray.p0);
    ray.p1[1] += 60000.0f;
    memset(&res, 0, 0x40);
    if (arg0 == (&D_00201E80)[2]) {
        side = 0;
    }
    if (arg0 == (&D_00201E80)[3]) {
        side = 1;
    }
    for (i = 0; i < 2; i++) {
        s32 *p = ((s32 **)(&D_00201E80 + 2))[side];
        if (p != 0) {
            MapColl_RayVsObjects_0_001B2180(*p, &res, &ray, 6, 3);
            if (res.hit != 0) {
                *out = res.x4;
                return 1;
            }
        }
        side = !side;
    }
    return 0;
}
#undef sceVu0CopyVector

/* ItemObj_AllocSlot_1_001AE360 */
#define D_002022B0 D_002022B0__as_ItemObj_AllocSlot_1_001AE360
extern Ent_ItemObj_AllocSlot_1_001AE360 *D_002022B0__as_ItemObj_AllocSlot_1_001AE360;

Obj3D *ItemObj_AllocSlot_1_001AE360(s16 id, u8 side) {
    s32 k;
    Ent_ItemObj_AllocSlot_1_001AE360 *ents;
    s32 i;
    s32 m;

    ents = D_002022B0;
    for (i = 0; i < 16; i++) {
        if (D_004AC970[side][i].x9C == -1) return &D_004AC970[side][i];
    }
    for (k = 0; k < ents[id].x8; k++) {
        for (i = 0; i < 16; i++) {
            if (ents[D_004AC5A0.t[side][i]->x9C].x8 <= k) {
                ItemObj_Free_1_001AF4A0(*(Obj3D *volatile *)&D_004AC5A0.t[side][i]);
                for (m = 0; m < 16; m++) {
                    if (D_004AC970[side][m].x9C == -1) return &D_004AC970[side][m];
                }
            }
        }
    }
    return 0;
}
#undef D_002022B0
