#include "actor.h"
#include "m2c.h"
typedef union { u32 w; Flags8 f; } Col_Player_DrawWeapon_0_001BCFF0;
typedef struct { Vec p; Vec r; u8 pad[0x40]; Col_Player_DrawWeapon_0_001BCFF0 c; } P_Player_DrawWeapon_0_001BCFF0;
typedef struct { u8 pad[0x160]; Flags8 f; u8 pad2[3]; s32 h; u8 pad3[8]; } E;
typedef struct { u8 pad[0x240]; Col_Player_DrawWeapon_0_001BCFF0 c; } C;
typedef struct { s32 *pp; u8 pad[0x20]; Flags8 f; } H2;
typedef struct { H2 *h; } H;
typedef struct { u128 q[10]; } Big;
typedef struct {
    u8 pad0[0x78];
    s32 n;
    u8 pad7C[0x19A - 0x7C];
    u8 a[0x100];
    u8 b[0x100];
    u8 pad39A[0x4B0 - 0x39A];
    C *x4B0;
    P_Player_DrawWeapon_0_001BCFF0 *tbl[0x19];
    s8 *x518;
    E *x51C;
    u8 pad520[0x80];
    Flags8 f5A0;
    Flags8 f5A1;
} O;
typedef struct { Vec m[2]; } M_Player_DrawWeapon_0_001BCFF0;
typedef struct { f32 m[4][4]; } MtxF;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col_Player_UpdateArea_0_001BD4E0;
typedef struct { u8 pad0[0x36]; u8 x36[0xB6 - 0x36]; u8 xB6, xB7, xB8, xB9; u8 padBA[4]; u16 xBE; u16 xC0; u8 xC2; } T158;
typedef struct { s32 x0; u8 pad4[0x154]; T158 *x158; u8 pad15C[0x2C]; u8 *x188; } M_Player_UpdateArea_0_001BD4E0;
typedef struct { u8 pad0[0x1E]; s16 x1E; u8 pad20; s8 x21; s8 x22; u8 pad23[5]; u8 b0:3; u8 b3:1; } N;
typedef struct { u8 pad0[0x26]; s16 x26; } C8;
typedef struct { u8 pad0[0xC0]; M_Player_UpdateArea_0_001BD4E0 *xC0; u8 padC4[4]; C8 *xC8; } Q;
typedef struct { u8 pad0[0xC]; u8 lo:4; u8 hi:4; u8 m:3; } S1;
typedef struct { u8 pad0[0x10]; Q *x10; u8 pad14[0xD0 - 0x14]; u8 xD0[0x2C]; S1 *xFC; u8 pad100[0x3BF - 0x100]; u8 x3BF; } P_Player_UpdateArea_0_001BD4E0;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad1C[0x40 - 0x1C]; Vec pos; u8 p50[0x3A0 - 0x50];
    union { struct { u16 a:7; u16 lvl:6; u16 r:3; } h; struct { u8 a; u8 r:7; u8 b7:1; } c; } f3A0; } P_Player_CheckLadder_0_001BE050;
typedef struct { f32 a[4]; f32 b[4]; } Ray;
typedef struct { s32 w[16]; } Res;
typedef struct { u16 a : 7; u16 v : 6; } BF;
extern Flags8 D_00222A50[];
extern Big D_004B4C40;
extern u64 D_002F1420[];
extern M_Player_UpdateArea_0_001BD4E0 **D_00201E80;
extern M_Player_UpdateArea_0_001BD4E0 **D_002022BC;
extern s32 D_002022B8;
extern f32 D_002022DC;
extern u32 D_00201C5C;
extern u8 D_00201E24;
extern f32 D_001F2080[];
extern f32 D_001F2084[];
extern f32 D_001F208C[];
extern f32 D_001F2090[];
extern f32 D_001F2094[];
extern f32 D_001F209C[];
extern f32 D_001F20C0[];
extern f32 D_001F20C4[];
extern f32 D_001F20C8[];
extern f32 D_001F20D0[];
extern f32 D_001F20D4[];
extern f32 D_001F20D8[];
extern Vec D_001F2070[];
extern Vec D_001F2100[];
extern f32 D_001F210C[];
extern MtxF D_001F2170;
extern Vec D_004B4CE0[];
extern f32 D_004B4CEC[];
extern Vec D_004B4C50[];
extern Vec D_004B4C60[];
extern Vec D_004B4C70[];
extern Vec D_004B4C80[];
extern Vec D_004B4C90[];
extern Vec D_004B4CA0[];
extern Vec D_004B4CB0[];
extern Vec D_004B4CC0[];
extern Vec D_004B4CD0[];
extern f32 D_004B4CDC[];
extern u8 D_0030D0E0[];
void Player_DrawWeapon_0_001BCFF0(O *o);
inline s8* get(void);
s32 Player_GetEquipSlot_0_001BD350(s32 a);
void Player_UpdateArea_0_001BD4E0(Actor *a);
s32 Player_CheckLadder_0_001BE050(Actor *a);
s32 Player_CheckCeiling_0_001BE390(s8 *a0);
void Player_SpawnStepSfx_0_001BE510(Actor *a0);
s8* Mdl_GetFrameData_0_001715B0(H *);
void Mdl_SetLayerTex_0_0016B2D0(H *, Col_Player_DrawWeapon_0_001BCFF0, s32, s32);
void GsPkt_BeginAD_3_001545D0(void);
void GsPkt_SetReg_3_001543E0(s32, u64);
void GsPkt_Flush_1_001544C0(void);
void Mdl_DrawLitWrap_0_0016B960(s8 *, s32, s32, s8 *, s32, s32);
void Fog_ApplyDefault_0_0015B270(void);
void Mdl_DrawMeshesC_1_0016D380(s32, H2 *, s8 *, s32, Col_Player_DrawWeapon_0_001BCFF0, s32);
void Seg_Init_1_001502A0(M_Player_DrawWeapon_0_001BCFF0 *, P_Player_DrawWeapon_0_001BCFF0 *, Vec *, f32);
void Sfx_SetColor_0_00167670(s32, M_Player_DrawWeapon_0_001BCFF0 *);
void Sfx_SetTransform_1_001677C0(s32, s8 *);
void GsPkt_CloseChain_1_001549D0(void);
void Mdl_FlushLayer_0_0016B280(void);
s32 Equip_GetSlotItem_1_001CCD90(s32);
N* MapObj_FindCollider_0_001B1D00(M_Player_UpdateArea_0_001BD4E0 *, void *);
void Map_LoadArea_1_001B51F0(M_Player_UpdateArea_0_001BD4E0 *, u8 *, s32);
M_Player_UpdateArea_0_001BD4E0** Map_FindLoaded_0_001B0AE0(M_Player_UpdateArea_0_001BD4E0 *);
void MapObj_SendEvent_1_001B0A80(M_Player_UpdateArea_0_001BD4E0 *, s32);
void MapState_SetVisited_0_001AA4C0(s32);
f32 Lerpf_3_0015DF90(f32, f32, f32);
f32* Map_GetFogEntry_0_001B40F0(M_Player_UpdateArea_0_001BD4E0 *, s32);
void sceVu0InterVector(Vec *, void *, Vec *, f32);
void sceVu0RotMatrixX(MtxF *, MtxF *, f32);
void sceVu0RotMatrixY(void *, void *, f32);
void sceVu0ApplyMatrix(Vec *, MtxF *, Vec *);
void sceVu0CopyVector(void *, void *);
void memset(void *, s32, s32);
s32 MapColl_CapsuleCastAll_1_001B3240(s8 *, MtxF *, Vec *, s32, s32);
s32 MapColl_CapsuleCast_1_001B2800(s8*, void *, void *, u16, s32, s32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Player_PlayStepSe_1_001CA2D0(s32);
s32 Player_ApplyDamage_2_001C8320(s32, s32, s32, s32);

/* Player_DrawWeapon_0_001BCFF0 */
void Player_DrawWeapon_0_001BCFF0(O *o) {
    u32 sv;
    H *h;
    s32 x;
    s8 *s1;
    s32 i;
    E *e;
    P_Player_DrawWeapon_0_001BCFF0 *p;
    u8 k;
    u8 v;
    Col_Player_DrawWeapon_0_001BCFF0 c;
    Col_Player_DrawWeapon_0_001BCFF0 c2;
    M_Player_DrawWeapon_0_001BCFF0 m;

    sv = D_00222A50[0].f.b3;
    if (o == NULL) return;
    if (!o->f5A0.f.b0 || !o->f5A0.f.b2) return;
    h = *(H **)(o->x518 + 0xB0);
    x = *h->h->pp;
    s1 = Mdl_GetFrameData_0_001715B0(h);
    o->f5A1.f.b6 = 1;
    if (!h->h->f.f.b1) return;
    D_00222A50[0].f.b3 = 1;
    *(Big *)(s1 + 0x10) = D_004B4C40;
    c = o->x4B0->c;
    D_00222A50[0].f.b4 = 1;
    Mdl_SetLayerTex_0_0016B2D0(h, c, 5, 0);
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x40, D_002F1420[0]);
    GsPkt_SetReg_3_001543E0(0x41, D_002F1420[0]);
    GsPkt_Flush_1_001544C0();
    Mdl_DrawLitWrap_0_0016B960(s1, 0, x, s1 + 0x280, 0, 2);
    Fog_ApplyDefault_0_0015B270();
    for (i = 0; i < o->n; i++) {
        v = o->a[i];
        p = o->tbl[v];
        if ((u32)i <= 1 || i == 15 || i == 29) continue;
        if (v == 0xFF) {
            c2 = o->x4B0->c;
        } else {
            c2 = p->c;
        }
        if (!c2.f.f.b3) {
            Mdl_DrawMeshesC_1_0016D380(*h->h->pp, h->h, s1, i, c2, 0);
        }
        k = o->b[i];
        p = o->tbl[k];
        e = &o->x51C[k];
        if (k == 0xFF) continue;
        if (e->h == 0) continue;
        if (e->f.f.b2) continue;
        Seg_Init_1_001502A0(&m, p, &p->r, p->p.w);
        Sfx_SetColor_0_00167670(e->h, &m);
        Sfx_SetTransform_1_001677C0(e->h, (s1 + (i + 1) * 0x140) + 0xC0);
    }
    D_00222A50[0].f.b4 = 0;
    GsPkt_CloseChain_1_001549D0();
    D_00222A50[0].f.b3 = sv;
    Mdl_FlushLayer_0_0016B280();
}

/* Player_GetEquipSlot_0_001BD350 */
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

s32 Player_GetEquipSlot_0_001BD350(s32 a) {
    s8 *p;
    s8 *q;
    s32 v;

    p = get();
    if (p == NULL) {
        return 1;
    }
    q = *(s8 **)(p + 0x3C8);
    if (q == NULL) {
        return 1;
    }
    if (!((Flags8 *)(q + 0xA8))->f.b0 || !((Flags8 *)(q + 0xA8))->f.b7) {
        return 1;
    }
    v = (s16)Equip_GetSlotItem_1_001CCD90(4);
    if ((v >= 300 && v <= 311) || (v >= 340 && v < 344)) {
        if ((a >= 4 && a <= 14) || (a >= 18 && a < 29)) {
            return 0;
        }
    }
    if (v == 0x14B || v == 0x14C) {
        if (a == 3 || a == 17) {
            return 0;
        }
    }
    if (v == 0x152 || v == 0x153) {
        if (a != 4 && a != 18) {
            return 0;
        }
    }
    return 1;
}

/* Player_UpdateArea_0_001BD4E0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define E80 (&D_00201E80)
#define D_004B4C40 D_004B4C40__as_Player_UpdateArea_0_001BD4E0
extern Vec D_004B4C40__as_Player_UpdateArea_0_001BD4E0[];
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_Player_UpdateArea_0_001BD4E0
void sceVu0RotMatrixY__as_Player_UpdateArea_0_001BD4E0(MtxF *, MtxF *, f32);
static inline f32 wrap(f32 x) { f32 t = 3.1415927f + x; return ((t - 6.2831855f * (s32)(0.15915494f * t)) + (t < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f; }
static inline f32 u2f(u32 x) { return x; }
static inline f32 rad(u32 d) { f32 f = d; return 3.1415927f * f / 180.0f; }

void Player_UpdateArea_0_001BD4E0(Actor *a) {
    P_Player_UpdateArea_0_001BD4E0 *p;
    N *n;
    S1 *s1;
    M_Player_UpdateArea_0_001BD4E0 *m;
    M_Player_UpdateArea_0_001BD4E0 *mm;
    u8 *e;
    f32 *k;
    f32 f;
    Col_Player_UpdateArea_0_001BD4E0 col;
    MtxF mt;
    Vec v;

    p = (P_Player_UpdateArea_0_001BD4E0 *)(a->unk518 + 0x180);
    n = 0;
    if (*(s32 *)(a->unk518 + 0x274) == 0) return;
    s1 = p->xFC;
    D_002022BC = 0;
    if (E80[2] != 0) {
        n = MapObj_FindCollider_0_001B1D00(*E80[2], p->xD0);
        if (n != 0) D_002022BC = E80[2];
    }
    if (E80[3] != 0 && n == 0) {
        n = MapObj_FindCollider_0_001B1D00(*E80[3], p->xD0);
        if (n != 0) D_002022BC = E80[3];
    }
    if (n != 0) {
        M_Player_UpdateArea_0_001BD4E0 **h;
        e = 0;
        h = D_002022BC;
        if (n->x1E != -1) e = &(*h)->x158->x36[n->x1E * 8];
        if (e != 0) Map_LoadArea_1_001B51F0(*h, e, n->b3);
    } else if (p->x10->xC8 != 0) {
        mm = p->x10->xC0;
        e = 0;
        D_002022BC = Map_FindLoaded_0_001B0AE0(mm);
        if (p->x10->xC8->x26 != -1) e = &mm->x158->x36[p->x10->xC8->x26 * 8];
        if (e != 0) Map_LoadArea_1_001B51F0(mm, e, 0);
    }
    if (D_002022BC != 0 && (m = *D_002022BC) != 0) {
        if (D_002022B8 != m->x0) {
            if (E80[2] != 0 && *E80[2] != 0 && E80[2] != D_002022BC) MapObj_SendEvent_1_001B0A80(*E80[2], 0);
            if (E80[3] != 0 && *E80[3] != 0 && E80[3] != D_002022BC) MapObj_SendEvent_1_001B0A80(*E80[3], 0);
            MapObj_SendEvent_1_001B0A80(m, 1);
            MapState_SetVisited_0_001AA4C0(m->x0);
            D_002022DC = 0.0f;
        }
        D_002022B8 = m->x0;
        if (D_002022DC >= 60.0f) f = 1.0f; else f = 1.0f / (60.0f - D_002022DC);
        col.w = D_00201C5C;
        col.c.r = Lerpf_3_0015DF90(u2f(col.c.r), u2f(m->x158->xB6), f);
        col.c.g = Lerpf_3_0015DF90(u2f(col.c.g), u2f(m->x158->xB7), f);
        col.c.b = Lerpf_3_0015DF90(u2f(col.c.b), u2f(m->x158->xB8), f);
        col.c.a = Lerpf_3_0015DF90(u2f(col.c.a), u2f(m->x158->xB9), f);
        D_00201C5C = col.w;
        k = Map_GetFogEntry_0_001B40F0(m, 0);
        D_001F2080[0] = Lerpf_3_0015DF90(D_001F2080[0], k[0], f);
        D_001F2084[0] = Lerpf_3_0015DF90(D_001F2084[0], k[1], f);
        D_001F208C[0] = Lerpf_3_0015DF90(D_001F208C[0], k[3], f);
        D_001F2090[0] = Lerpf_3_0015DF90(D_001F2090[0], k[8], f);
        D_001F2094[0] = Lerpf_3_0015DF90(D_001F2094[0], k[9], f);
        D_001F209C[0] = Lerpf_3_0015DF90(D_001F209C[0], k[11], f);
        D_001F20C0[0] = Lerpf_3_0015DF90(D_001F20C0[0], k[4], f);
        D_001F20C4[0] = Lerpf_3_0015DF90(D_001F20C4[0], k[5], f);
        D_001F20C8[0] = Lerpf_3_0015DF90(D_001F20C8[0], k[6], f);
        D_001F20D0[0] = Lerpf_3_0015DF90(D_001F20D0[0], k[4], f);
        D_001F20D4[0] = Lerpf_3_0015DF90(D_001F20D4[0], k[5], f);
        D_001F20D8[0] = Lerpf_3_0015DF90(D_001F20D8[0], k[6], f);
        sceVu0InterVector(D_001F2070, k + 0x14, D_001F2070, f);
        sceVu0InterVector(D_001F2100, k + 0x10, D_001F2100, f);
        D_001F210C[0] = 127.9f;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 1.0f;
        v.w = 1.0f;
        sceVu0RotMatrixX(&mt, &D_001F2170, WRAP(-(3.1415927f * (f32)(u32)m->x158->xBE / 180.0f)));
        sceVu0RotMatrixY(&mt, &mt, WRAP(3.1415927f * (f32)(u32)m->x158->xC0 / 180.0f));
        sceVu0ApplyMatrix(&v, &mt, &v);
        sceVu0InterVector(D_004B4CE0, &v, D_004B4CE0, f);
        D_004B4CEC[0] = 1.0f;
        D_00201E24 = Lerpf_3_0015DF90(u2f(D_00201E24), u2f(m->x158->xC2), f);
        D_002022DC += 1.0f;
        if (n != 0) {
            if (n->x22 != -1) e = m->x188 + n->x22 * 0xA0;
            else if (n->x21 != -1) e = m->x188 + n->x21 * 0xA0;
            else e = D_0030D0E0;
            sceVu0InterVector(D_004B4C40, e, D_004B4C40, 0.2f);
            sceVu0InterVector(D_004B4C50, e + 0x10, D_004B4C50, 0.2f);
            sceVu0InterVector(D_004B4C60, e + 0x20, D_004B4C60, 0.2f);
            sceVu0InterVector(D_004B4C70, e + 0x30, D_004B4C70, 0.2f);
            sceVu0InterVector(D_004B4C80, e + 0x40, D_004B4C80, 0.2f);
            sceVu0InterVector(D_004B4C90, e + 0x50, D_004B4C90, 0.2f);
            sceVu0InterVector(D_004B4CA0, e + 0x60, D_004B4CA0, 0.2f);
            sceVu0InterVector(D_004B4CB0, e + 0x70, D_004B4CB0, 0.2f);
            sceVu0InterVector(D_004B4CC0, e + 0x80, D_004B4CC0, 0.2f);
            sceVu0InterVector(D_004B4CD0, e + 0x90, D_004B4CD0, 0.2f);
            D_004B4CDC[0] = 127.9f;
        }
    }
    if (s1->m == 2) p->x3BF = s1->lo;
}
#undef sceVu0RotMatrixY
#undef D_004B4C40
#undef E80

/* Player_CheckLadder_0_001BE050 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define D_00201E80 D_00201E80__as_Player_CheckLadder_0_001BE050
extern s32 D_00201E80__as_Player_CheckLadder_0_001BE050;
#define sceVu0CopyVector sceVu0CopyVector__as_Player_CheckLadder_0_001BE050
void sceVu0CopyVector__as_Player_CheckLadder_0_001BE050(Vec *, Vec *);
#define MapColl_CapsuleCast_1_001B2800 MapColl_CapsuleCast_1_001B2800__as_Player_CheckLadder_0_001BE050
s32 MapColl_CapsuleCast_1_001B2800__as_Player_CheckLadder_0_001BE050(s8 *, MtxF *, Vec *, u16, s32, s32);
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_Player_CheckLadder_0_001BE050
void sceVu0RotMatrixY__as_Player_CheckLadder_0_001BE050(MtxF *, MtxF *, f32);
#define Sfx_SetTransform_1_001677C0 Sfx_SetTransform_1_001677C0__as_Player_CheckLadder_0_001BE050
void Sfx_SetTransform_1_001677C0__as_Player_CheckLadder_0_001BE050(s8 *, MtxF *);
static inline void hit(P_Player_CheckLadder_0_001BE050 *p, MtxF *r, MtxF *mp) {
    s8 *o;
    if (!p->f3A0.c.b7 && p->f3A0.h.lvl > 10) {
        o = Sfx_Spawn_2_00169B50(0x1DD, 0, 0, 0);
        if (o != 0) {
            sceVu0RotMatrixY(mp, &D_001F2170, WRAP(*(f32 *)(p->o + 0x24)));
            sceVu0CopyVector((Vec *)mp->m[3], (Vec *)r);
            Sfx_SetTransform_1_001677C0(o, mp);
            Player_PlayStepSe_1_001CA2D0(0x10);
        }
    }
}

s32 Player_CheckLadder_0_001BE050(Actor *a) {
    P_Player_CheckLadder_0_001BE050 *p;
    s32 i;
    s32 j;
    s8 *n;
    s8 ***q;
    s8 ***q2;
    s32 i2;
    Vec f;
    Vec e;
    MtxF m;
    MtxF t;
    p = (P_Player_CheckLadder_0_001BE050 *)(a->unk518 + 0x180);
    sceVu0CopyVector(&e, &p->pos);
    e.w = 1.0f;
    sceVu0CopyVector(&f, &p->pos);
    f.w = 1.0f;
    e.y = -29000.0f;
    memset(&m, 0, 0x40);
    for (i = 0, q = (s8 ***)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && MapColl_CapsuleCastAll_1_001B3240(**q, &m, &e, 0x80, 1)) {
            hit(p, &m, &t);
            return 1;
        }
    }
    for (i2 = 0, q2 = (s8 ***)(&D_00201E80 + 2); i2 < 2; i2++, q2++) {
        if (*q2 != 0 && (n = **q2) != 0) {
            for (j = 0; j < *(u16 *)(n + 0x6E); j++) {
                if (!MapColl_CapsuleCast_1_001B2800(n, &m, &e, j, 0x80, 1) == 0) {
                    hit(p, &m, &t);
                    return 1;
                }
            }
        }
    }
    return 0;
}
#undef sceVu0CopyVector
#undef MapColl_CapsuleCast_1_001B2800
#undef sceVu0RotMatrixY
#undef Sfx_SetTransform_1_001677C0
#undef D_00201E80

/* Player_CheckCeiling_0_001BE390 */
#define sceVu0CopyVector sceVu0CopyVector__as_Player_CheckCeiling_0_001BE390
void sceVu0CopyVector__as_Player_CheckCeiling_0_001BE390(f32 *, s8 *);
#define MapColl_CapsuleCast_1_001B2800 MapColl_CapsuleCast_1_001B2800__as_Player_CheckCeiling_0_001BE390
s32 MapColl_CapsuleCast_1_001B2800__as_Player_CheckCeiling_0_001BE390(s8 *, Res *, Ray *, u16, s32, s32);
#define MapColl_CapsuleCastAll_1_001B3240 MapColl_CapsuleCastAll_1_001B3240__as_Player_CheckCeiling_0_001BE390
s32 MapColl_CapsuleCastAll_1_001B3240__as_Player_CheckCeiling_0_001BE390(s32, Res *, Ray *, s32, s32);
#define D_00201E80 D_00201E80__as_Player_CheckCeiling_0_001BE390
extern s32 D_00201E80__as_Player_CheckCeiling_0_001BE390;

s32 Player_CheckCeiling_0_001BE390(s8 *a0) {
    Ray ray;
    Res res;
    s32 j;
    s8 *o;
    s32 i;
    s8 ***pp;
    s32 **q;
    s8 *p;

    p = *(s8 **)(a0 + 0x518) + 0x180;
    sceVu0CopyVector(ray.a, p + 0x40);
    ray.a[3] = 1.0f;
    sceVu0CopyVector(ray.b, p + 0x40);
    ray.b[3] = 1.0f;
    ray.a[1] = *(f32 *)(*(s8 **)(p + 0x10) + 0x14);
    ray.b[1] += 220.0f;
    memset(&res, 0, 0x40);
    for (i = 0, q = (s32 **)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0 && MapColl_CapsuleCastAll_1_001B3240(**q, &res, &ray, 8, 1) != 0) {
            return 1;
        }
    }
    for (i = 0, pp = (s8 ***)(&D_00201E80 + 2); i < 2; i++, pp++) {
        if (*pp != 0) {
            o = **pp;
            if (o != 0) {
                for (j = 0; j < *(u16 *)(o + 0x6E); j++) {
                    if (!MapColl_CapsuleCast_1_001B2800(o, &res, &ray, j, 8, 1) == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
#undef sceVu0CopyVector
#undef MapColl_CapsuleCast_1_001B2800
#undef MapColl_CapsuleCastAll_1_001B3240
#undef D_00201E80

/* Player_SpawnStepSfx_0_001BE510 */
#define Sfx_Spawn_2_00169B50 Sfx_Spawn_2_00169B50__as_Player_SpawnStepSfx_0_001BE510
s32 Sfx_Spawn_2_00169B50__as_Player_SpawnStepSfx_0_001BE510(s32, s32, s32, s32);
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_Player_SpawnStepSfx_0_001BE510
void sceVu0RotMatrixY__as_Player_SpawnStepSfx_0_001BE510(f32 *, void *, f32);
#define sceVu0CopyVector sceVu0CopyVector__as_Player_SpawnStepSfx_0_001BE510
void sceVu0CopyVector__as_Player_SpawnStepSfx_0_001BE510(f32 *, s8 *);
#define Sfx_SetTransform_1_001677C0 Sfx_SetTransform_1_001677C0__as_Player_SpawnStepSfx_0_001BE510
void Sfx_SetTransform_1_001677C0__as_Player_SpawnStepSfx_0_001BE510(s32, f32 *);
#define Player_PlayStepSe_1_001CA2D0 Player_PlayStepSe_1_001CA2D0__as_Player_SpawnStepSfx_0_001BE510
void Player_PlayStepSe_1_001CA2D0__as_Player_SpawnStepSfx_0_001BE510(u8);
#define D_001F2170 D_001F2170__as_Player_SpawnStepSfx_0_001BE510
extern s8 D_001F2170__as_Player_SpawnStepSfx_0_001BE510[];
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline s8 *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return D_002022E4->unk518 + 0x180;
}

void Player_SpawnStepSfx_0_001BE510(Actor *a0) {
    s8 *s1;
    s32 s0;
    f32 m[16];
    s8 *c;
    f32 t, h, n;

    s1 = a0->unk518 + 0x180;
    if (((BF *)(a0->unk518 + 0x520))->v > 8) {
        s0 = 0;
        switch (*(u8 *)(s1 + 0x3BF)) {
        case 0: case 2: case 3: case 4: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 15: break;
        case 1: s0 = Sfx_Spawn_2_00169B50(0x1DB, 0, 0, 0); break;
        case 5: s0 = Sfx_Spawn_2_00169B50(0x1DE, 0, 0, 0); break;
        case 6: s0 = Sfx_Spawn_2_00169B50(0x1DD, 0, 0, 0); break;
        case 14: s0 = Sfx_Spawn_2_00169B50(0x1DD, 0, 0, 0); break;
        }
        if (s0 != 0) {
            sceVu0RotMatrixY(m, D_001F2170, WRAP(*(f32 *)(*(s8 **)(s1 + 0x18) + 0x24)));
            c = cur();
            if (c != 0) {
                sceVu0CopyVector(m + 12, c + 0x40);
            }
            m[13] += 220.0f;
            Sfx_SetTransform_1_001677C0(s0, m);
        }
        Player_PlayStepSe_1_001CA2D0(*(u8 *)(s1 + 0x3BF));
    }
    if (((BF *)(s1 + 0x3A0))->v >= 20) {
        t = 30.0f * *(f32 *)(s1 + 0x54);
        h = t / 1000.0f;
        n = h / 2.0f - 9.0f;
        if (n == 0.0f) n = 1.0f;
        s0 = (s32)((h * h) / (1800.0f / n));
        if (s0 > 0) {
            Player_ApplyDamage_2_001C8320(s0, 1, 1, 1);
            *(s32 *)(*(s8 **)(s1 + 0x390) + 0x48) = 60;
        }
    }
}
#undef Sfx_Spawn_2_00169B50
#undef sceVu0RotMatrixY
#undef sceVu0CopyVector
#undef Sfx_SetTransform_1_001677C0
#undef Player_PlayStepSe_1_001CA2D0
#undef D_001F2170
