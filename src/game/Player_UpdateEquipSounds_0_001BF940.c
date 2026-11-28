#include "actor.h"
#include "obj3d.h"
#include "m2c.h"
typedef struct { u8 pad[0x94]; Flags8 f94; } R_Player_UpdateEquipSounds_0_001BF940;
typedef struct {
    u8 pad[0x390];
    R_Player_UpdateEquipSounds_0_001BF940 *x390;
    u8 pad394[2];
    u8 x396;
    u8 pad397[0x39C - 0x397];
    u8 x39C;
    u8 pad39D[0x3C0 - 0x39D];
    Obj3D *x3C0;
    Obj3D *x3C4;
    Obj3D *x3C8;
    u8 pad3CC[0x3D5 - 0x3CC];
    u8 x3D5;
} S_Player_UpdateEquipSounds_0_001BF940;
typedef struct { u8 pad[0x80]; s16 x80; s16 x82; u8 pad84[4]; s16 x88; u8 pad8A[0x94 - 0x8A]; Flags8 f94; } R_Player_UpdateHeldItem_0_001BFB70;
typedef struct {
    u8 pad[0x390];
    R_Player_UpdateHeldItem_0_001BFB70 *x390;
    u8 pad394[0x3B8 - 0x394];
    s16 x3B8;
    s16 x3BA;
    s16 x3BC;
    u8 pad3BE[2];
    Obj3D *x3C0;
    Obj3D *x3C4;
    Obj3D *x3C8;
    s8 x3CC;
    s8 x3CD;
    s8 x3CE;
    s8 x3CF;
    u8 pad3D0[4];
    s8 x3D4;
    s8 x3D5;
    Flags8 f3D6;
} S_Player_UpdateHeldItem_0_001BFB70;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    u8 pad[0x40];
    u16 x40;
    u16 x42;
    u8 x44;
    u8 x45;
    u8 x46;
    u8 x47;
    u8 x48;
    u8 x49;
    u8 pad4A[0xC];
    u8 x56;
    u8 x57;
    u8 pad58[0x38];
} E;
typedef struct {
    u16 h[6];
    u8 padC[4];
    s32 w[6];
    u8 pad28[9];
    Bits f31;
    u8 pad32[0xE];
} D;
typedef struct { u8 pad[6]; s16 x6; } Q;
typedef struct {
    u8 pad[0x18];
    f32 *p18;
    u8 pad1C[0x374 - 0x1C];
    f32 x374;
    s8 *x378;
    u8 pad37C[0x14];
    Q *x390;
    u8 pad394[3];
    s8 x397;
    u8 pad398[2];
    s16 x39A;
    u8 pad39C[6];
    Bits f3A2;
    u8 pad3A3[0x46A - 0x3A3];
    u16 x46A;
    u8 pad46C[4];
    u16 x470[6];
} P;
typedef struct {
    u8 pad[0x39C];
    u32 b39C:8;
    u32 b8:6;
    u32 m:4;
    u32 n:4;
    u32 o:6;
    u32 r:4;
    u8 pad3A0[0x414 - 0x3A0];
    void *x414;
} S;
typedef struct { u8 pad[0x9C]; s16 x9C; } R;
typedef struct { u8 pad[0x518]; u8 *x518; } A;
extern Mtx D_001F2170;
extern f32 D_00222850[];
extern f32 D_003139A0[];
extern f32 D_001F2170__as_Player_GetHandMatrix_1_001C0660[];
void Player_UpdateEquipSounds_0_001BF940(Actor *a0);
s32 Player_UpdateHeldItem_0_001BFB70(Actor *a0);
void Player_FireWeapon_0_001C0020(Actor *a);
s32 Player_TryPickup_0_001C0550(A *a0);
void Player_GetHandMatrix_1_001C0660(f32 *out, s32 a1, s32 flag, u32 n);
void Player_BlendHandMatrix_0_001C0860(f32 (*out)[4], s32 a1, u32 a2, s32 flag, f32 t);
s32 Snd_BindMapSe_0_0012DA90(void);
s32 Equip_GetSlotItem_1_001CCD90(s32);
u8 Item_GetType_0_001CCDE0(s32);
s32 ItemType_IsWeapon_0_001D1D50(u8);
u8* PlayerData_GetEquipEntry_0_001D1E10(void);
void Player_SetArmMotion_1_001C7020(u16, f32, s32, f32, f32);
void Snd_StopStream3_0_0012DA80(void);
void ItemObj_Free_1_001AF4A0(Obj3D *);
Obj3D* ItemObj_Spawn_0_001AE7C0(s32);
s32 ItemType_GetCategory_0_001D1CB0(s32);
s32 Item_GetType_0_001CCDE0__as_Player_UpdateHeldItem_0_001BFB70(s32);
E* Item_GetTable_1_001AFC90(void);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Equip_DamageWeapon_0_001CC450(u16);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0CopyVector(void *, void *);
void Sfx_SetTransform_1_001677C0(s8 *, Mtx *);
void Sfx_SetOwner_1_00167600(s8 *, Actor *);
void memset(void *, s32, s32);
void Sfx_GetState_0_001672B0(s8 *, D *);
R* ItemObj_FindPickTarget_0_001AC3E0(void);
s32 Inventory_CanCarry_0_001CBE40(s32);
void Msg_ShowById_1_0018B0E0(s32);
R* Chest_CheckOpen_0_001B9360(void);
void sceVu0InversMatrix(f32 (*)[4], f32 *);
void sceVu0ApplyMatrix(f32 *, f32 (*)[4], f32 *);
void sceVu0AddVector(f32 *, f32 *, f32 *);
void ItemObj_GetScale_0_001ADBA0(s32, f32 *);
void sceVu0MulMatrix(f32 *, f32 (*)[4], f32 (*)[4]);
void sceVu0CopyVector__as_Player_GetHandMatrix_1_001C0660(f32 *, f32 *);
void sceVu0CopyMatrix__as_Player_GetHandMatrix_1_001C0660(f32 (*)[4], f32 *);
void sceVu0RotMatrixY__as_Player_GetHandMatrix_1_001C0660(f32 (*)[4], f32 (*)[4], f32);
void ItemObj_GetMatrix_0_001ADC60(s32, f32 (*)[4]);
void Mtx_ToQuat_2_0015E290(f32 *, f32 (*)[4]);
void sceVu0InterVector(f32 *, f32 *, f32 *, f32);
void Quat_Slerp_2_0015DFA0(f32 *, f32 *, f32 *, f32);
void Quat_ToMatrix_2_0015E180(f32 (*)[4], f32 *);

/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
/* Player_UpdateEquipSounds_0_001BF940 */
void Player_UpdateEquipSounds_0_001BF940(Actor *a0) {
    S_Player_UpdateEquipSounds_0_001BF940 *s = (S_Player_UpdateEquipSounds_0_001BF940 *)(a0->unk518 + 0x180);
    Obj3D *o;
    Obj3D *p;

    if (s->x390->f94.f.b0) {
        p = s->x3C0;
    } else {
        p = s->x3C4;
    }
    if (p != NULL) {
        p->xA8.f.b7 = 0;
        p->xA8.f.b2 = 1;
        p->xA9.f.b3 = 0;
    }
    if (s->x390->f94.f.b0) {
        o = s->x3C4;
    } else {
        o = s->x3C0;
    }
    if (o != NULL && o->xA8.f.b0) {
        if (s->x3D5 == 0) {
            o->xA8.f.b7 = 0;
        } else {
            o->xA8.f.b7 = 1;
        }
        o->xA8.f.b2 = 1;
        if (!o->xA9.f.b3 && !Snd_BindMapSe_0_0012DA90()) {
            o->xA9.f.b3 = 1;
        }
    }
    p = s->x3C8;
    if (p != NULL) {
        p->xA8.f.b7 = 1;
        p->xA8.f.b2 = 1;
        p->xA9.f.b0 = 1;
        p->xA9.f.b3 = 0;
    }
    s->x39C = Item_GetType_0_001CCDE0(Equip_GetSlotItem_1_001CCD90(s->x390->f94.f.b0));
    if (ItemType_IsWeapon_0_001D1D50(s->x39C)) {
        s->x396 = PlayerData_GetEquipEntry_0_001D1E10()[3];
    }
}

/* Player_UpdateHeldItem_0_001BFB70 */
static inline S_Player_UpdateHeldItem_0_001BFB70 *get(void) {
    S_Player_UpdateHeldItem_0_001BFB70 *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_Player_UpdateHeldItem_0_001BFB70 *)(base + 0x180);
    }
    return r;
}
static inline void reset(void) {
    S_Player_UpdateHeldItem_0_001BFB70 *p;
    s8 *base;
    if (D_002022E4 == NULL) {
        p = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        p = NULL;
    } else {
        p = (S_Player_UpdateHeldItem_0_001BFB70 *)(base + 0x180);
    }
    if (p != NULL) {
        Player_SetArmMotion_1_001C7020(0, 0.0f, 0, 0.0f, 1.0f);
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        p->x3D5 = 0;
        p->x3D4 = 0;
        p->f3D6.f.b5 = 0;
    }
}

s32 Player_UpdateHeldItem_0_001BFB70(Actor *a0) {
    S_Player_UpdateHeldItem_0_001BFB70 *s = (S_Player_UpdateHeldItem_0_001BFB70 *)(a0->unk518 + 0x180);
    s32 n;
    s16 m;

    n = s->x390->x80;
    if (n != s->x3B8 || s->x3C0 == NULL) {
        if (s->x3C0 != NULL) {
            if (!s->x390->f94.f.b0) Snd_StopStream3_0_0012DA80();
            ItemObj_Free_1_001AF4A0(s->x3C0);
            s->x3C0 = NULL;
        }
        if (n != -1) {
            s->x3C0 = ItemObj_Spawn_0_001AE7C0(n);
        } else {
            s->x3C0 = ItemObj_Spawn_0_001AE7C0(0x3FF);
        }
        s->x3B8 = n;
        if (!s->x390->f94.f.b0) reset();
    }
    n = s->x390->x82;
    if (ItemType_GetCategory_0_001D1CB0(Item_GetType_0_001CCDE0__as_Player_UpdateHeldItem_0_001BFB70(s->x390->x80))) {
        if (s->x3C4 != NULL) {
            Snd_StopStream3_0_0012DA80();
            ItemObj_Free_1_001AF4A0(s->x3C4);
            s->x3C4 = NULL;
            if (s->x390->f94.f.b0) reset();
        }
        s->x3BA = n;
        s->x390->f94.f.b0 = 0;
    } else {
        m = n;
        if (m != s->x3BA || s->x3C4 == NULL) {
            if (s->x3C4 != NULL) {
                if (s->x390->f94.f.b0) Snd_StopStream3_0_0012DA80();
                ItemObj_Free_1_001AF4A0(s->x3C4);
                s->x3C4 = NULL;
            }
            if (m != -1) {
                s->x3C4 = ItemObj_Spawn_0_001AE7C0(n);
            } else {
                s->x3C4 = ItemObj_Spawn_0_001AE7C0(0x3FF);
            }
            s->x3BA = n;
            if (s->x390->f94.f.b0) reset();
        }
    }
    n = s->x390->x88;
    if (n != -1) {
        if (n != s->x3BC || s->x3C8 == NULL) {
            if (s->x3C8 != NULL) ItemObj_Free_1_001AF4A0(s->x3C8);
            s->x3C8 = ItemObj_Spawn_0_001AE7C0(n);
            reset();
        }
        s->x3BC = n;
    } else {
        if (s->x3C8 != NULL) {
            ItemObj_Free_1_001AF4A0(s->x3C8);
            s->x3C8 = NULL;
        }
        s->x3BC = -1;
    }
    return 0;
}

/* Player_FireWeapon_0_001C0020 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 u2f(u32 x) { return x; }

void Player_FireWeapon_0_001C0020(Actor *a) {
    D d;
    Mtx m;
    P *p;
    E *tbl;
    s32 i;
    s32 j;
    u16 *c;

    p = (P *)(a->unk518 + 0x180);
    tbl = Item_GetTable_1_001AFC90();
    j = i = (s16)Equip_GetSlotItem_1_001CCD90(6);
    if (i != -1 && p->x397 > 0) {
    c = &((u16 (*)[0x48])&tbl->x42)[j][0];
    if (*c <= p->x390->x6 && p->x374 <= 0.0f) {
    p->x378 = Sfx_Spawn_2_00169B50(tbl[j].x40, 0, 0, 0);
    if (p->x378 != NULL) {
    Equip_DamageWeapon_0_001CC450(p->x46A);
    p->x390->x6 -= *c;
    p->x397--;
    p->x39A = 0;
    p->x374 = u2f(tbl[i].x56);
    sceVu0CopyMatrix(&m, &D_001F2170);
    sceVu0RotMatrixX(&m, &m, WRAP(-WRAP(p->p18[8])));
    sceVu0RotMatrixY(&m, &m, WRAP(WRAP(p->p18[9])));
    sceVu0CopyVector(&m.m[3], p->p18);
    m.m[3].w = 1.0f;
    Sfx_SetTransform_1_001677C0(p->x378, &m);
    Sfx_SetOwner_1_00167600(p->x378, a);
    memset(&d, 0, 0x40);
    d.h[0] = p->x470[0] / tbl[i].x57;
    d.h[1] = p->x470[1] / tbl[i].x57;
    d.h[2] = p->x470[2] / tbl[i].x57;
    d.h[3] = p->x470[3] / tbl[i].x57;
    d.h[4] = p->x470[4] / tbl[i].x57;
    d.h[5] = p->x470[5] / tbl[i].x57;
    d.w[0] = tbl[i].x44;
    d.w[1] = tbl[i].x45;
    d.w[2] = tbl[i].x46;
    d.w[3] = tbl[i].x48;
    d.w[4] = tbl[i].x47;
    d.w[5] = tbl[i].x49;
    d.f31.b1 = 1;
    Sfx_GetState_0_001672B0(p->x378, &d);
    p->f3A2.b3 = 1;
    }
    }
    }
}

/* Player_TryPickup_0_001C0550 */
s32 Player_TryPickup_0_001C0550(A *a0) {
    S *s;
    R *r;
    s = (S *)(a0->x518 + 0x180);
    s->x414 = 0;
    r = ItemObj_FindPickTarget_0_001AC3E0();
    if (r) {
        if (Inventory_CanCarry_0_001CBE40(r->x9C)) {
            s->m = 1;
            s->n = 0;
            s->x414 = r;
        } else {
            Msg_ShowById_1_0018B0E0(0xCC);
        }
        return 1;
    }
    r = Chest_CheckOpen_0_001B9360();
    if (r) {
        s->m = 1;
        s->n = 0;
        s->x414 = r;
        return 1;
    }
    return 0;
}

/* Player_GetHandMatrix_1_001C0660 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void Player_GetHandMatrix_1_001C0660(f32 *out, s32 a1, s32 flag, u32 n) {
    f32 m2[4][4] __attribute__((aligned(16)));
    f32 m1[4][4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 ang;

    ang = -12.0f * (3.1415927f * n) / 180.0f;
    sceVu0InversMatrix(m1, D_00222850);
    sceVu0CopyVector__as_Player_GetHandMatrix_1_001C0660(w, D_003139A0);
    w[2] = 180.0f;
    w[1] = 30.0f;
    sceVu0ApplyMatrix(w, m1, w);
    sceVu0AddVector(m1[3], m1[3], w);
    sceVu0CopyMatrix__as_Player_GetHandMatrix_1_001C0660(m2, D_001F2170__as_Player_GetHandMatrix_1_001C0660);
    ItemObj_GetScale_0_001ADBA0(a1, v);
    m2[0][0] = v[0];
    m2[1][1] = v[1];
    m2[2][2] = v[2];
    sceVu0RotMatrixY__as_Player_GetHandMatrix_1_001C0660(m2, m2, WRAP(ang));
    m1[3][3] = 1.0f;
    if (flag != 0) {
        m2[3][2] -= 150.0f;
        m2[3][0] += 70.0f;
        m2[3][1] += 150.0f;
    }
    sceVu0MulMatrix(out, m1, m2);
}

/* Player_BlendHandMatrix_0_001C0860 */
#define D_001F2170 D_001F2170__as_Player_BlendHandMatrix_0_001C0860
extern f32 D_001F2170__as_Player_BlendHandMatrix_0_001C0860[];
#define sceVu0CopyVector sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860
void sceVu0CopyVector__as_Player_BlendHandMatrix_0_001C0860(f32 *, f32 *);
#define Player_GetHandMatrix_1_001C0660 Player_GetHandMatrix_1_001C0660__as_Player_BlendHandMatrix_0_001C0860
void Player_GetHandMatrix_1_001C0660__as_Player_BlendHandMatrix_0_001C0860(f32 (*)[4], s32, s32, u32);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_Player_BlendHandMatrix_0_001C0860
void sceVu0CopyMatrix__as_Player_BlendHandMatrix_0_001C0860(f32 (*)[4], void *);
#define sceVu0MulMatrix sceVu0MulMatrix__as_Player_BlendHandMatrix_0_001C0860
void sceVu0MulMatrix__as_Player_BlendHandMatrix_0_001C0860(f32 (*)[4], f32 (*)[4], f32 (*)[4]);

void Player_BlendHandMatrix_0_001C0860(f32 (*out)[4], s32 a1, u32 a2, s32 flag, f32 t) {
    f32 m[4][4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 q1[4] __attribute__((aligned(16)));
    f32 q2[4] __attribute__((aligned(16)));
    f32 s[4] __attribute__((aligned(16)));
    f32 q[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));

    if (flag == 0) {
        ItemObj_GetMatrix_0_001ADC60(a1, m);
        sceVu0CopyVector(c, m[3]);
        Mtx_ToQuat_2_0015E290(q1, m);
        Player_GetHandMatrix_1_001C0660(m, a1, 0, a2);
        sceVu0CopyVector(b, m[3]);
        Mtx_ToQuat_2_0015E290(q2, m);
        sceVu0InterVector(v, b, c, t);
        v[3] = 1.0f;
        ItemObj_GetScale_0_001ADBA0(a1, s);
        sceVu0CopyMatrix(m, D_001F2170);
        m[0][0] = s[0];
        m[1][1] = s[1];
        m[2][2] = s[2];
        Quat_Slerp_2_0015DFA0(q, q1, q2, t);
        Quat_ToMatrix_2_0015E180(out, q);
        sceVu0MulMatrix(out, m, out);
        sceVu0CopyVector(out[3], v);
    } else {
        Player_GetHandMatrix_1_001C0660(m, a1, 0, a2);
        sceVu0CopyVector(c, m[3]);
        Player_GetHandMatrix_1_001C0660(m, a1, 1, a2);
        sceVu0CopyVector(b, m[3]);
        sceVu0InterVector(v, b, c, t);
        v[3] = 1.0f;
        sceVu0CopyMatrix(out, m);
        sceVu0CopyVector(out[3], v);
    }
}
#undef sceVu0CopyVector
#undef Player_GetHandMatrix_1_001C0660
#undef sceVu0CopyMatrix
#undef sceVu0MulMatrix
#undef D_001F2170
