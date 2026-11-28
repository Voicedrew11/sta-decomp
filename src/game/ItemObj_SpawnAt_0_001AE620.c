#include "m2c.h"
#include "common.h"
#include "obj3d.h"
typedef struct {
    s8 pad0[0x40];
    f32 v40[4];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    s8 pad70[0x10];
    s32 x80;
    s8 pad84[0x18];
    s16 h9C;
    s8 pad9E[8];
    s8 xA6;
    s8 xA7;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:5;
    s8 padA9[5];
    s16 xAE;
    s8 padB0[4];
    f32 xB4;
    s8 padB8[0x18];
} Obj_ItemObj_SpawnAt_0_001AE620;
typedef struct { s8 pad[0x10]; s32 x10; s8 pad14[0x6C]; s8 x80[0x10]; } Ent_ItemObj_SpawnAt_0_001AE620;
typedef struct {
    s8 pad0[0x40];
    f32 v40[4];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    s8 pad70[0x10];
    s32 x80;
    s8 pad84[0x18];
    s16 h9C;
    s8 pad9E[8];
    s8 xA6;
    s8 xA7;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:5;
    s8 padA9[5];
    s16 xAE;
    s8 padB0[4];
    f32 xB4;
    s8 padB8[0x18];
} Obj_ItemObj_Spawn_0_001AE7C0;
typedef struct { s8 pad[0x10]; s32 x10; s8 pad14[0x6C]; s8 x80[0x10]; } Ent_ItemObj_Spawn_0_001AE7C0;
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_ItemObj_Drop_0_001AE900;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x4C]; Vec_ItemObj_Drop_0_001AE900 a; Vec_ItemObj_Drop_0_001AE900 b; Vec_ItemObj_Drop_0_001AE900 c; } Ent_ItemObj_Drop_0_001AE900;
typedef struct {
    u8 b0:1;
    u8 b1:1;
    u8 b2:4;
    u8 b6:1;
    u8 b7:1;
} BF;
typedef struct {
    Mtx m;
    Vec_ItemObj_Drop_0_001AE900 v40, v50, v60, v70;
    s32 x80;
    u8 pad84[8];
    s32 *x8C;
    u8 pad90[0xC];
    s16 idx;
    u8 pad9E[8];
    s8 xA6;
    s8 xA7;
    BF xA8;
    u8 fA9;
    s16 xAA;
    s16 xAC;
    s16 xAE;
    f32 xB0;
    f32 xB4;
} Node;
typedef struct {
    Vec_ItemObj_Drop_0_001AE900 m[3];
    Vec_ItemObj_Drop_0_001AE900 pos;
    Vec_ItemObj_Drop_0_001AE900 a, b, c;
    Vec_ItemObj_Drop_0_001AE900 d;
    s32 f80;
    s32 pad84[2];
    s32 f8C;
    s32 pad90[3];
    s16 f9C;
    s16 pad9e[4];
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:4;
    u8 a6:1;
    u8 a7:1;
    u8 c0:1;
    u8 c1:1;
    u8 c2:6;
    u16 fAA;
    s16 fAC;
    s16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj_ItemObj_Drop_0_001AE900;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct { Vec_ItemObj_SpawnFromMap_0_001AEE80 m[4]; } __attribute__((aligned(16))) Mtx_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct {
    u8 pad[0x10];
    s32 f10;
    u8 pad2[0x60 - 0x14];
    Vec_ItemObj_SpawnFromMap_0_001AEE80 a, b, c;
} Ent_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct {
    Vec_ItemObj_SpawnFromMap_0_001AEE80 m[3];
    Vec_ItemObj_SpawnFromMap_0_001AEE80 pos;
    Vec_ItemObj_SpawnFromMap_0_001AEE80 a, b, c;
    Vec_ItemObj_SpawnFromMap_0_001AEE80 d;
    s32 f80;
    s32 pad84[2];
    s32 f8C;
    s32 pad90[3];
    s16 f9C;
    s16 pad9e[3];
    s8 fA4;
    s8 padA5;
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:4;
    u8 a6:1;
    u8 a7:1;
    u8 c0:1;
    u8 c1:1;
    u8 c2:1;
    u8 c3:5;
    u16 fAA;
    s16 fAC;
    s16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj_ItemObj_SpawnFromMap_0_001AEE80;
typedef struct { Vec m[4]; } __attribute__((aligned(16))) MtxA;
typedef struct {
    u8 pad[0x10];
    s32 f10;
    u8 pad2[0x60 - 0x14];
    Vec a, b, c;
} Ent_ItemObj_SpawnFromSource_0_001AF150;
typedef struct {
    u8 pad[0x18];
    s32 f18;
    u16 f1C;
    u16 pad1e;
    u8 b0:1;
    u8 b1:1;
    u8 b2:6;
    u8 pad21;
    u16 f22;
} Src;
typedef struct {
    Vec m[3];
    Vec pos;
    Vec a, b, c;
    Vec d;
    s32 f80;
    s32 pad84[2];
    s32 f8C;
    s32 pad90[3];
    s16 f9C;
    s16 pad9e[4];
    s8 fA6;
    s8 fA7;
    u8 a0:1;
    u8 a1:1;
    u8 a2:6;
    u8 c0:1;
    u8 c1:1;
    u8 c2:6;
    u16 fAA;
    s16 fAC;
    u16 fAE;
    s32 padB0;
    f32 fB4;
    u8 padB8[0xD0 - 0xB8];
} Obj_ItemObj_SpawnFromSource_0_001AF150;
typedef struct { s32 pad[2]; s32 f8; s32 fC; } G_ItemObj_SpawnFromSource_0_001AF150;
typedef struct O {
    u8 pad[0x84];
    s8 *m84;
    u8 pad88[0x14];
    s16 m9C;
    s16 m9E;
    u8 padA0[7];
    s8 mA7;
    union { u16 h; u8 b; } mA8;
    u8 padAA[4];
    s16 mAE;
    u8 padB0[4];
    f32 mB4;
    s32 mB8;
    s32 mBC;
    s32 mC0[2][2];
} O;
typedef struct { s16 a[2]; s16 n[2]; O *list[2][16]; } G_ItemObj_Free_1_001AF4A0;
extern Obj_ItemObj_SpawnAt_0_001AE620 *D_00202288;
extern Ent_ItemObj_SpawnAt_0_001AE620 *D_002022B0;
extern f32 D_001F2170[];
extern s32 D_00201E80;
extern Vec_ItemObj_Drop_0_001AE900 D_001F3820;
extern Vec_ItemObj_Drop_0_001AE900 D_001F3830;
extern s32 D_002022BC;
extern s16 D_004AC5A4[];
extern Node *D_004AC5A8[][16];
extern s16 D_004AC5A0[];
extern s32 D_0020228C;
extern s32 D_002022A0;
extern s32 D_00202290;
extern s16 D_004AC5A2[];
extern s16 D_004AC5A6[];
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B80[];
extern s32 D_004B4B88[];
Obj_ItemObj_SpawnAt_0_001AE620* ItemObj_SpawnAt_0_001AE620(s16 id, f32 *a, f32 *b);
Obj_ItemObj_Spawn_0_001AE7C0* ItemObj_Spawn_0_001AE7C0(s16 id);
Node* ItemObj_Drop_0_001AE900(s32 *owner, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, s32 ground, s32 rel);
Obj_ItemObj_Drop_0_001AE900* ItemObj_SpawnThrown_0_001AEC00(s32 arg0, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, Vec_ItemObj_Drop_0_001AE900 *d);
Obj_ItemObj_SpawnFromMap_0_001AEE80* ItemObj_SpawnFromMap_0_001AEE80(s32 *arg0, s16 id, Vec_ItemObj_SpawnFromMap_0_001AEE80 *a, Vec_ItemObj_SpawnFromMap_0_001AEE80 *b, s16 arg4);
Obj_ItemObj_SpawnFromSource_0_001AF150* ItemObj_SpawnFromSource_0_001AF150(s32 arg0, Src *arg1, u16 arg2, Vec *arg3);
void ItemObj_PickUp_0_001AF3F0(Obj3D *o);
void ItemObj_Free_1_001AF4A0(O *o);
void ItemObj_FreeOwned_0_001AF740(s32 *a0);
void ItemObj_FreeAll_0_001AF840(void);
void ItemObj_SetPools_0_001AF970(s32 arg0, s32 arg1);
void ItemObj_Init_0_001AF980(void);
void ItemObj_ClearTables_1_001AFA20(void);
void sceVu0CopyVector(void *, void *);
void Mtx_Compose_2_00173FD0(void *, void *, void *, void *);
void sceVu0CopyMatrix(void *, void *);
void sceVu0MulMatrix(void*, void*, void *);
void sceVu0AddVector(void *, void *, void *);
void sceVu0SubVector(void *, void *, void *);
void Map_CopyOrigin_0_001B51E0(s32, void *);
void* ItemObj_AllocSlot_1_001AE360(s16, u8);
s32 ItemObj_FindGround_0_001AE250(s32 *, Vec_ItemObj_Drop_0_001AE900 *, f32 *);
void ItemObj_SaveState_1_001AE510(void);
void Map_DecodeTransform_0_001B59E0(Src *, Vec *, Vec *, Vec *);
s32 MapState_GetField_0_001A9D50(u32, u16);
void MapState_SetField_0_001A9E10(s32, u16, u8);
void MapState_SetBit_0_001A9CA0(s32, s16);
void memset(void *, s32, s32);
void Sfx_Release_1_00167030(s32);
void Mdl_DestroyInstance_0_001745D0(s32, s8 *);
void Pool_Free_2_00128580(s32, s32);
void Task_RunWrap_0_0014DAB0(s32);
void ItemMdl_Update_0_001AB690();
void Task_Register_0_0014DB10(void (*)());

/* ItemObj_SpawnAt_0_001AE620 */
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_SpawnAt_0_001AE620
void sceVu0CopyVector__as_ItemObj_SpawnAt_0_001AE620(f32 *, f32 *);
#define Mtx_Compose_2_00173FD0 Mtx_Compose_2_00173FD0__as_ItemObj_SpawnAt_0_001AE620
void Mtx_Compose_2_00173FD0__as_ItemObj_SpawnAt_0_001AE620(Obj_ItemObj_SpawnAt_0_001AE620 *, f32 *, f32 *, s8 *);
#define D_004AC630 D_004AC630__as_ItemObj_SpawnAt_0_001AE620
extern Obj_ItemObj_SpawnAt_0_001AE620 D_004AC630__as_ItemObj_SpawnAt_0_001AE620[4];

Obj_ItemObj_SpawnAt_0_001AE620 *ItemObj_SpawnAt_0_001AE620(s16 id, f32 *a, f32 *b) {
    Obj_ItemObj_SpawnAt_0_001AE620 *s = 0;
    Ent_ItemObj_SpawnAt_0_001AE620 *t = D_002022B0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_004AC630[i].h9C == -1) {
            s = &D_004AC630[i];
            break;
        }
    }
    if (s == 0) {
        return 0;
    }
    s->h9C = id;
    s->xAE = -1;
    s->xA6 = 0x19;
    s->xA7 = -1;
    s->b0 = 0;
    s->b1 = 0;
    s->b2 = 1;
    s->x80 = t[id].x10;
    s->xB4 = 1.0f;
    sceVu0CopyVector(s->v40, a);
    sceVu0CopyVector(s->v50, b);
    s->x68 = 1.0f;
    s->x64 = 1.0f;
    s->x60 = 1.0f;
    s->x6C = 0.0f;
    Mtx_Compose_2_00173FD0(s, a, b, t[id].x80);
    if (D_00202288 == 0) {
        D_00202288 = s;
    }
    return s;
}
#undef sceVu0CopyVector
#undef Mtx_Compose_2_00173FD0
#undef D_004AC630

/* ItemObj_Spawn_0_001AE7C0 */
#define D_00202288 D_00202288__as_ItemObj_Spawn_0_001AE7C0
extern Obj_ItemObj_Spawn_0_001AE7C0 *D_00202288__as_ItemObj_Spawn_0_001AE7C0;
#define D_002022B0 D_002022B0__as_ItemObj_Spawn_0_001AE7C0
extern Ent_ItemObj_Spawn_0_001AE7C0 *D_002022B0__as_ItemObj_Spawn_0_001AE7C0;
#define D_004AC630 D_004AC630__as_ItemObj_Spawn_0_001AE7C0
extern Obj_ItemObj_Spawn_0_001AE7C0 D_004AC630__as_ItemObj_Spawn_0_001AE7C0[4];

Obj_ItemObj_Spawn_0_001AE7C0 *ItemObj_Spawn_0_001AE7C0(s16 id) {
    Obj_ItemObj_Spawn_0_001AE7C0 *s = 0;
    Ent_ItemObj_Spawn_0_001AE7C0 *t = D_002022B0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_004AC630[i].h9C == -1) {
            s = &D_004AC630[i];
            break;
        }
    }
    if (s == 0) {
        return 0;
    }
    s->h9C = id;
    s->xAE = -1;
    s->xA6 = -1;
    s->xA7 = -1;
    s->b0 = 0;
    s->b1 = 0;
    s->b2 = 1;
    s->x80 = t[id].x10;
    s->xB4 = 1.0f;
    sceVu0CopyMatrix(s, D_001F2170);
    if (D_00202288 == 0) {
        D_00202288 = s;
    }
    return s;
}
#undef D_00202288
#undef D_002022B0
#undef D_004AC630

/* ItemObj_Drop_0_001AE900 */
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_Drop_0_001AE900
void sceVu0CopyVector__as_ItemObj_Drop_0_001AE900(Vec_ItemObj_Drop_0_001AE900 *, Vec_ItemObj_Drop_0_001AE900 *);
#define Mtx_Compose_2_00173FD0 Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900
void Mtx_Compose_2_00173FD0__as_ItemObj_Drop_0_001AE900(void *, Vec_ItemObj_Drop_0_001AE900 *, Vec_ItemObj_Drop_0_001AE900 *, Vec_ItemObj_Drop_0_001AE900 *);
#define Map_CopyOrigin_0_001B51E0 Map_CopyOrigin_0_001B51E0__as_ItemObj_Drop_0_001AE900
void Map_CopyOrigin_0_001B51E0__as_ItemObj_Drop_0_001AE900(s32, Vec_ItemObj_Drop_0_001AE900 *);
#define D_002022B0 D_002022B0__as_ItemObj_Drop_0_001AE900
extern Ent_ItemObj_Drop_0_001AE900 *D_002022B0__as_ItemObj_Drop_0_001AE900;
#define D_00202288 D_00202288__as_ItemObj_Drop_0_001AE900
extern Node *D_00202288__as_ItemObj_Drop_0_001AE900;
static inline void upd(Node *n) {
    Ent_ItemObj_Drop_0_001AE900 *tbl = D_002022B0;
    if (n != NULL && n->idx != -1) {
        if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
            Mtx_Compose_2_00173FD0(n, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent_ItemObj_Drop_0_001AE900 *e = &tbl[n->idx];
            Mtx_Compose_2_00173FD0(&tmp, &e->a, &e->b, &e->c);
            Mtx_Compose_2_00173FD0(n, &n->v40, &n->v50, &n->v60);
            sceVu0MulMatrix(n, n, &tmp);
        }
        sceVu0AddVector(&n->m.m[3], &n->m.m[3], &n->v70);
    }
}

Node *ItemObj_Drop_0_001AE900(s32 *owner, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, s32 ground, s32 rel) {
    Vec_ItemObj_Drop_0_001AE900 c;
    Ent_ItemObj_Drop_0_001AE900 *t;
    Node *s;
    s32 side;

    t = D_002022B0;
    c = D_001F3830;
    side = -1;
    if (((s32 **)&D_00201E80)[2] == owner) {
        side = 0;
    }
    if (((s32 **)&D_00201E80)[3] == owner) {
        side = 1;
    }
    s = ItemObj_AllocSlot_1_001AE360(id, side);
    if (s == 0) {
        return 0;
    }
    s->idx = id;
    s->xAA = 0;
    s->xAE = -1;
    s->xA6 = 0x19;
    s->xA7 = -1;
    s->xAC = 0;
    s->xA8.b0 = 0;
    s->xA8.b1 = 0;
    s->xA8.b6 = ground;
    s->x80 = t[id].x10;
    s->x8C = owner;
    s->xB4 = 1.0f;
    sceVu0CopyVector(&s->v40, a);
    sceVu0CopyVector(&s->v50, b);
    s->v50.v[2] = 0.0f;
    s->v50.v[0] = 0.0f;
    sceVu0CopyVector(&s->v60, &c);
    if (owner != 0) {
        Map_CopyOrigin_0_001B51E0(*owner, &s->v70);
        if (rel != 0) {
            sceVu0SubVector(&s->v40, &s->v40, &s->v70);
        }
    }
    upd(s);
    if (ground != 0) {
        if (ItemObj_FindGround_0_001AE250(owner, &s->m.m[3], &s->xB0) == 0) {
            s->idx = -1;
            *(s16 *)&s->xA8 = 0;
            s->x80 = 0;
            s->x8C = 0;
            return 0;
        }
        s->xB0 -= s->v70.v[1];
    }
    D_004AC5A8[side][D_004AC5A4[side]++] = s;
    ItemObj_SaveState_1_001AE510();
    if (D_00202288 == 0) {
        D_00202288 = s;
    }
    return s;
}

static inline void update_ItemObj_Drop_0_001AE900(Obj_ItemObj_Drop_0_001AE900 *o) {
    Mtx m;
    Ent_ItemObj_Drop_0_001AE900 *e;
    Ent_ItemObj_Drop_0_001AE900 *ents = D_002022B0;
    if (o == NULL) return;
    if (o->f9C == -1) return;
    if (o->c1) {
        Mtx_Compose_2_00173FD0(o, &o->a, &o->b, &o->c);
    } else {
        e = &ents[o->f9C];
        Mtx_Compose_2_00173FD0(&m, &e->a, &e->b, &e->c);
        Mtx_Compose_2_00173FD0(o, &o->a, &o->b, &o->c);
        sceVu0MulMatrix(o, o, &m);
    }
    sceVu0AddVector(&o->pos, &o->pos, &o->d);
}

Obj_ItemObj_Drop_0_001AE900 *ItemObj_SpawnThrown_0_001AEC00(s32 arg0, s16 id, Vec_ItemObj_Drop_0_001AE900 *a, Vec_ItemObj_Drop_0_001AE900 *b, Vec_ItemObj_Drop_0_001AE900 *d) {
    Ent_ItemObj_Drop_0_001AE900 *ents;
    s32 side;
    Obj_ItemObj_Drop_0_001AE900 *o;
    s32 k;
    Vec_ItemObj_Drop_0_001AE900 c;
    ents = D_002022B0;
    c = D_001F3820;
    side = -1;
    if ((&D_00201E80)[2] == D_002022BC) side = 0;
    if ((&D_00201E80)[3] == D_002022BC) side = 1;
    k = !side;
    o = ItemObj_AllocSlot_1_001AE360(id, k);
    if (o == NULL) return NULL;
    o->f9C = id;
    o->fAA = 0;
    o->fAE = -1;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = 0;
    o->a0 = 0;
    o->a1 = 0;
    o->a6 = 0;
    o->f80 = ents[id].x10;
    o->f8C = arg0;
    o->fB4 = 1.0f;
    sceVu0CopyVector(&o->a, a);
    sceVu0CopyVector(&o->b, b);
    sceVu0CopyVector(&o->c, &c);
    sceVu0CopyVector(&o->d, d);
    update_ItemObj_Drop_0_001AE900(o);
    D_004AC5A8[k][D_004AC5A4[k]++] = o;
    if (D_00202288 == NULL) D_00202288 = o;
    return o;
}
#undef sceVu0CopyVector
#undef Mtx_Compose_2_00173FD0
#undef Map_CopyOrigin_0_001B51E0
#undef D_002022B0
#undef D_00202288

/* ItemObj_SpawnFromMap_0_001AEE80 */
#define D_00202288 D_00202288__as_ItemObj_SpawnFromMap_0_001AEE80
extern Obj_ItemObj_SpawnFromMap_0_001AEE80 *D_00202288__as_ItemObj_SpawnFromMap_0_001AEE80;
#define D_002022B0 D_002022B0__as_ItemObj_SpawnFromMap_0_001AEE80
extern Ent_ItemObj_SpawnFromMap_0_001AEE80 *D_002022B0__as_ItemObj_SpawnFromMap_0_001AEE80;
#define D_004AE370 D_004AE370__as_ItemObj_SpawnFromMap_0_001AEE80
extern Obj_ItemObj_SpawnFromMap_0_001AEE80 D_004AE370__as_ItemObj_SpawnFromMap_0_001AEE80[2][64];
#pragma explicit_zero_data on
Vec_ItemObj_SpawnFromMap_0_001AEE80 D_001F3810 = { 1.0f, 1.0f, 1.0f, 1.0f };
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromMap_0_001AEE80
void ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromMap_0_001AEE80(Obj_ItemObj_SpawnFromMap_0_001AEE80 *);
#define Map_CopyOrigin_0_001B51E0 Map_CopyOrigin_0_001B51E0__as_ItemObj_SpawnFromMap_0_001AEE80
void Map_CopyOrigin_0_001B51E0__as_ItemObj_SpawnFromMap_0_001AEE80(s32, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_SpawnFromMap_0_001AEE80
void sceVu0CopyVector__as_ItemObj_SpawnFromMap_0_001AEE80(Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
#define Mtx_Compose_2_00173FD0 Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromMap_0_001AEE80
void Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromMap_0_001AEE80(void *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
#define sceVu0MulMatrix sceVu0MulMatrix__as_ItemObj_SpawnFromMap_0_001AEE80
void sceVu0MulMatrix__as_ItemObj_SpawnFromMap_0_001AEE80(void *, void *, Mtx_ItemObj_SpawnFromMap_0_001AEE80 *);
#define sceVu0AddVector sceVu0AddVector__as_ItemObj_SpawnFromMap_0_001AEE80
void sceVu0AddVector__as_ItemObj_SpawnFromMap_0_001AEE80(Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *, Vec_ItemObj_SpawnFromMap_0_001AEE80 *);
static inline void update_ItemObj_SpawnFromMap_0_001AEE80(Obj_ItemObj_SpawnFromMap_0_001AEE80 *o) {
    Mtx_ItemObj_SpawnFromMap_0_001AEE80 m;
    Ent_ItemObj_SpawnFromMap_0_001AEE80 *e;
    Ent_ItemObj_SpawnFromMap_0_001AEE80 *ents = D_002022B0;
    if (o == NULL) return;
    if (o->f9C == -1) return;
    if (o->c1) {
        Mtx_Compose_2_00173FD0(o, &o->a, &o->b, &o->c);
    } else {
        e = &ents[o->f9C];
        Mtx_Compose_2_00173FD0(&m, &e->a, &e->b, &e->c);
        Mtx_Compose_2_00173FD0(o, &o->a, &o->b, &o->c);
        sceVu0MulMatrix(o, o, &m);
    }
    sceVu0AddVector(&o->pos, &o->pos, &o->d);
}

Obj_ItemObj_SpawnFromMap_0_001AEE80 *ItemObj_SpawnFromMap_0_001AEE80(s32 *arg0, s16 id, Vec_ItemObj_SpawnFromMap_0_001AEE80 *a, Vec_ItemObj_SpawnFromMap_0_001AEE80 *b, s16 arg4) {
    Ent_ItemObj_SpawnFromMap_0_001AEE80 *ents;
    s32 side;
    Obj_ItemObj_SpawnFromMap_0_001AEE80 *o;
    s16 *cnt;
    Vec_ItemObj_SpawnFromMap_0_001AEE80 c;
    ents = D_002022B0;
    c = D_001F3810;
    side = -1;
    if ((&D_00201E80)[2] == (s32)arg0) side = 0;
    if ((&D_00201E80)[3] == (s32)arg0) side = 1;
    cnt = &D_004AC5A0[side];
    if (!(*(volatile s16 *)cnt < 0x40)) return NULL;
    o = &D_004AE370[side][*(volatile s16 *)cnt];
    if (o->f9C != -1) ItemObj_Free_1_001AF4A0(o);
    o->f9C = id;
    o->fAA = 0;
    o->fAE = -1;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = arg4;
    o->a0 = 0;
    o->a1 = 0;
    o->c2 = 1;
    o->f80 = ents[id].f10;
    o->f8C = (s32)arg0;
    o->fB4 = 1.0f;
    o->fA4 = 0x2D;
    sceVu0CopyVector(&o->a, a);
    sceVu0CopyVector(&o->b, b);
    o->b.z = 0.0f;
    o->b.x = 0.0f;
    sceVu0CopyVector(&o->c, &c);
    if (arg0 != NULL) Map_CopyOrigin_0_001B51E0(*arg0, &o->d);
    update_ItemObj_SpawnFromMap_0_001AEE80(o);
    (*cnt)++;
    if (D_00202288 == NULL) D_00202288 = o;
    return o;
}
#undef ItemObj_Free_1_001AF4A0
#undef Map_CopyOrigin_0_001B51E0
#undef sceVu0CopyVector
#undef Mtx_Compose_2_00173FD0
#undef sceVu0MulMatrix
#undef sceVu0AddVector
#undef D_00202288
#undef D_002022B0
#undef D_004AE370

/* ItemObj_SpawnFromSource_0_001AF150 */
#define D_00202288 D_00202288__as_ItemObj_SpawnFromSource_0_001AF150
extern Obj_ItemObj_SpawnFromSource_0_001AF150 *D_00202288__as_ItemObj_SpawnFromSource_0_001AF150;
#define D_002022B0 D_002022B0__as_ItemObj_SpawnFromSource_0_001AF150
extern Ent_ItemObj_SpawnFromSource_0_001AF150 *D_002022B0__as_ItemObj_SpawnFromSource_0_001AF150;
#define D_004AE370 D_004AE370__as_ItemObj_SpawnFromSource_0_001AF150
extern Obj_ItemObj_SpawnFromSource_0_001AF150 D_004AE370__as_ItemObj_SpawnFromSource_0_001AF150[][64];
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromSource_0_001AF150
void ItemObj_Free_1_001AF4A0__as_ItemObj_SpawnFromSource_0_001AF150(Obj_ItemObj_SpawnFromSource_0_001AF150 *);
#define sceVu0CopyVector sceVu0CopyVector__as_ItemObj_SpawnFromSource_0_001AF150
void sceVu0CopyVector__as_ItemObj_SpawnFromSource_0_001AF150(Vec *, Vec *);
#define Mtx_Compose_2_00173FD0 Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromSource_0_001AF150
void Mtx_Compose_2_00173FD0__as_ItemObj_SpawnFromSource_0_001AF150(void *, Vec *, Vec *, Vec *);
#define sceVu0MulMatrix sceVu0MulMatrix__as_ItemObj_SpawnFromSource_0_001AF150
void sceVu0MulMatrix__as_ItemObj_SpawnFromSource_0_001AF150(void *, void *, MtxA *);
#define sceVu0AddVector sceVu0AddVector__as_ItemObj_SpawnFromSource_0_001AF150
void sceVu0AddVector__as_ItemObj_SpawnFromSource_0_001AF150(Vec *, Vec *, Vec *);
static inline void update_ItemObj_SpawnFromSource_0_001AF150(Obj_ItemObj_SpawnFromSource_0_001AF150 *o) {
    MtxA m;
    Ent_ItemObj_SpawnFromSource_0_001AF150 *e;
    Ent_ItemObj_SpawnFromSource_0_001AF150 *ents = D_002022B0;
    if (o == NULL) return;
    if (o->f9C == -1) return;
    if (o->c1) {
        Mtx_Compose_2_00173FD0(o, &o->a, &o->b, &o->c);
    } else {
        e = &ents[o->f9C];
        Mtx_Compose_2_00173FD0(&m, &e->a, &e->b, &e->c);
        Mtx_Compose_2_00173FD0(o, &o->a, &o->b, &o->c);
        sceVu0MulMatrix(o, o, &m);
    }
    sceVu0AddVector(&o->pos, &o->pos, &o->d);
}

Obj_ItemObj_SpawnFromSource_0_001AF150 *ItemObj_SpawnFromSource_0_001AF150(s32 arg0, Src *arg1, u16 arg2, Vec *arg3) {
    Ent_ItemObj_SpawnFromSource_0_001AF150 *ents;
    s32 side;
    s32 k;
    Obj_ItemObj_SpawnFromSource_0_001AF150 *o;
    ents = D_002022B0;
    side = -1;
    if ((&D_00201E80)[2] == D_002022BC) side = 0;
    if ((&D_00201E80)[3] == D_002022BC) side = 1;
    k = !side;
    if (arg2 >= 0x40) return NULL;
    if (arg2 >= D_004AC5A0[k]) D_004AC5A0[k] = arg2 + 1;
    o = &D_004AE370[k][arg2];
    if (o->f9C != -1) ItemObj_Free_1_001AF4A0(o);
    o->f9C = arg1->f18;
    o->fAA = arg1->f1C;
    o->fAE = arg1->f22;
    o->fA6 = 0x19;
    o->fA7 = -1;
    o->fAC = arg2;
    o->a0 = 0;
    o->a1 = 0;
    o->c1 = arg1->b1;
    o->f80 = ents[arg1->f18].f10;
    o->f8C = arg0;
    o->fB4 = 1.0f;
    Map_DecodeTransform_0_001B59E0(arg1, &o->a, &o->b, &o->c);
    sceVu0CopyVector(&o->d, arg3);
    update_ItemObj_SpawnFromSource_0_001AF150(o);
    if (D_00202288 == NULL) D_00202288 = o;
    return o;
}
#undef ItemObj_Free_1_001AF4A0
#undef sceVu0CopyVector
#undef Mtx_Compose_2_00173FD0
#undef sceVu0MulMatrix
#undef sceVu0AddVector
#undef D_00202288
#undef D_002022B0
#undef D_004AE370

/* ItemObj_PickUp_0_001AF3F0 */
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_ItemObj_PickUp_0_001AF3F0
void ItemObj_Free_1_001AF4A0__as_ItemObj_PickUp_0_001AF3F0(Obj3D *);
void ItemObj_PickUp_0_001AF3F0(Obj3D *o) {
    if (o->x9E == 0) {
        s32 *p = *o->x8C;
        if (o->xA9.f.b2) {
            MapState_SetField_0_001A9E10(*p, o->xAC, MapState_GetField_0_001A9D50(*p, o->xAC) | 2);
        } else {
            MapState_SetBit_0_001A9CA0(*p, o->xAC);
        }
    }
    ItemObj_Free_1_001AF4A0(o);
    if (o->x9E == 1) ItemObj_SaveState_1_001AE510();
}
#undef ItemObj_Free_1_001AF4A0

/* ItemObj_Free_1_001AF4A0 */
#define D_00202288 D_00202288__as_ItemObj_Free_1_001AF4A0
extern O *D_00202288__as_ItemObj_Free_1_001AF4A0;
#define D_004AC5A0 D_004AC5A0__as_ItemObj_Free_1_001AF4A0
extern volatile G_ItemObj_Free_1_001AF4A0 D_004AC5A0__as_ItemObj_Free_1_001AF4A0;

void ItemObj_Free_1_001AF4A0(O *o) {
    s32 t;
    s32 k;

    if (o == 0) return;
    if (o->m9C == -1) return;
    if (o == D_00202288) {
        D_0020228C = 1;
    }
    if (o->mA8.b & 1) {
        if (o->mB8 != 0) {
            Sfx_Release_1_00167030(o->mB8);
        }
        if (o->mBC != 0) {
            Sfx_Release_1_00167030(o->mBC);
        }
        for (k = 0; k < 4; k++) {
            if (o->mC0[k / 2][k % 2] != 0) {
                Sfx_Release_1_00167030(o->mC0[k / 2][k % 2]);
            }
        }
        Mdl_DestroyInstance_0_001745D0(D_002022A0, o->m84);
        o->m84 = 0;
    }
    o->m9C = -1;
    o->mA8.h = 0;
    switch (o->m9E) {
    case 0:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 0;
        break;
    case 1:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 1;
        for (t = 0; t < 2; t++) {
            for (k = 0; k < D_004AC5A0.n[t]; k++) {
                if (D_004AC5A0.list[t][k] == o) break;
            }
            if (k >= D_004AC5A0.n[t]) continue;
            goto cond;
        body:
            D_004AC5A0.list[t][k] = D_004AC5A0.list[t][k + 1];
            k++;
        cond:
            if (k < D_004AC5A0.n[t] - 1) goto body;
            D_004AC5A0.n[t]--;
            break;
        }
        break;
    case 2:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 2;
        break;
    }
    o->mB4 = 1.0f;
    o->mAE = -1;
    o->mA7 = -1;
}
#undef D_00202288
#undef D_004AC5A0

/* ItemObj_FreeOwned_0_001AF740 */
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_ItemObj_FreeOwned_0_001AF740
void ItemObj_Free_1_001AF4A0__as_ItemObj_FreeOwned_0_001AF740(Obj3D *);
#define D_00201E80 D_00201E80__as_ItemObj_FreeOwned_0_001AF740
extern s32 *D_00201E80__as_ItemObj_FreeOwned_0_001AF740[2];

void ItemObj_FreeOwned_0_001AF740(s32 *a0) {
    s32 k;
    s32 i;
    Obj3D *o;
    k = -1;
    if (D_00201E80[2] == a0) k = 0;
    if (D_00201E80[3] == a0) k = 1;
    for (i = 0, o = D_004AE370[k]; i < 64; i++, o++) ItemObj_Free_1_001AF4A0(o);
    for (i = 0, o = D_004AC970[k]; i < 16; i++, o++) ItemObj_Free_1_001AF4A0(o);
    D_004AC5A0[k] = 0;
    D_004AC5A4[k] = 0;
}
#undef ItemObj_Free_1_001AF4A0
#undef D_00201E80

/* ItemObj_FreeAll_0_001AF840 */
#define ItemObj_Free_1_001AF4A0 ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840
int ItemObj_Free_1_001AF4A0__as_ItemObj_FreeAll_0_001AF840();
#define D_00202288 D_00202288__as_ItemObj_FreeAll_0_001AF840
extern s32 D_00202288__as_ItemObj_FreeAll_0_001AF840;
#define D_004AC630 D_004AC630__as_ItemObj_FreeAll_0_001AF840
extern u8 D_004AC630__as_ItemObj_FreeAll_0_001AF840[];
#define D_004AC970 D_004AC970__as_ItemObj_FreeAll_0_001AF840
extern u8 D_004AC970__as_ItemObj_FreeAll_0_001AF840[];
#define D_004AE370 D_004AE370__as_ItemObj_FreeAll_0_001AF840
extern u8 D_004AE370__as_ItemObj_FreeAll_0_001AF840[];

void ItemObj_FreeAll_0_001AF840(void) {
    u8 *var_17_3;
    u8 *var_17_2;
    s32 var_17;
    u8 *var_16;
    s32 var_16_3;
    s32 var_16_2;

    if ((*D_004B4B80) != 0) {
        Pool_Free_2_00128580(D_00202290, (*D_004B4B80));
    }
    if ((*D_004B4B74) != 0) {
        Task_RunWrap_0_0014DAB0((*D_004B4B74));
        (*D_004B4B74) = 0;
    }
    (*D_004B4B80) = 0;
    var_17 = 0;
    (*D_004B4B74) = 0;
    var_16 = (u8 *) (D_004AE370);
    D_00202288 = 0;
    (*D_004B4B70) = 0;
    D_0020228C = 0;
    (*D_004B4B88) = 0;
    do {
        ItemObj_Free_1_001AF4A0(var_16);
        ItemObj_Free_1_001AF4A0(var_16 + 0x3400);
        var_17 += 1;
        var_16 += 0xD0;
    } while (var_17 < 0x40);
    var_16_2 = 0;
    var_17_2 = (u8 *) (D_004AC970);
    do {
        ItemObj_Free_1_001AF4A0(var_17_2);
        ItemObj_Free_1_001AF4A0(var_17_2 + 0xD00);
        var_16_2 += 1;
        var_17_2 += 0xD0;
    } while (var_16_2 < 0x10);
    var_16_3 = 0;
    var_17_3 = (u8 *) (D_004AC630);
    do {
        ItemObj_Free_1_001AF4A0(var_17_3);
        var_16_3 += 1;
        var_17_3 += 0xD0;
    } while (var_16_3 < 4);
    (*D_004AC5A0) = 0;
    (*D_004AC5A2) = 0;
    (*D_004AC5A4) = 0;
    (*D_004AC5A6) = 0;
}
#undef D_00202288
#undef D_004AC630
#undef D_004AC970
#undef D_004AE370
#undef ItemObj_Free_1_001AF4A0

/* ItemObj_SetPools_0_001AF970 */
#define ItemObj_ClearTables_1_001AFA20 ItemObj_ClearTables_1_001AFA20__as_ItemObj_SetPools_0_001AF970
int ItemObj_ClearTables_1_001AFA20__as_ItemObj_SetPools_0_001AF970();

void ItemObj_SetPools_0_001AF970(s32 arg0, s32 arg1) {
    D_00202290 = arg0;
    D_002022A0 = arg1;
    ItemObj_ClearTables_1_001AFA20();
}
#undef ItemObj_ClearTables_1_001AFA20

/* ItemObj_Init_0_001AF980 */
#define ItemObj_ClearTables_1_001AFA20 ItemObj_ClearTables_1_001AFA20__as_ItemObj_Init_0_001AF980
int ItemObj_ClearTables_1_001AFA20__as_ItemObj_Init_0_001AF980();
#define memset memset__as_ItemObj_Init_0_001AF980
void memset__as_ItemObj_Init_0_001AF980(s32 *, s32, s32);
#define D_00202288 D_00202288__as_ItemObj_Init_0_001AF980
extern s32 D_00202288__as_ItemObj_Init_0_001AF980;

void ItemObj_Init_0_001AF980(void) {
    ItemObj_ClearTables_1_001AFA20();
    memset(D_004B4B70, 0, 0x1C);
    Task_Register_0_0014DB10(ItemMdl_Update_0_001AB690);
    if ((*D_004B4B80) != 0) {
        Pool_Free_2_00128580(D_00202290, (*D_004B4B80));
    }
    if ((*D_004B4B74) != 0) {
        Task_RunWrap_0_0014DAB0((*D_004B4B74));
        (*D_004B4B74) = 0;
    }
    (*D_004B4B80) = 0;
    D_00202288 = 0;
    (*D_004B4B74) = 0;
    D_0020228C = 0;
    (*D_004B4B70) = 0;
    (*D_004B4B88) = 0;
}
#undef memset
#undef D_00202288
#undef ItemObj_ClearTables_1_001AFA20

/* ItemObj_ClearTables_1_001AFA20 */
#define D_004AC5A0 D_004AC5A0__as_ItemObj_ClearTables_1_001AFA20
extern u8 D_004AC5A0__as_ItemObj_ClearTables_1_001AFA20[];
static inline void init(Obj3D *e, s16 t) { e->x9C = -1; e->x9E = t; e->xB4 = 1.0f; e->xAE = -1; e->xA7 = -1; }

void ItemObj_ClearTables_1_001AFA20(void) {
    u32 i;
    memset(D_004AC5A0, 0, 0x88);
    memset(D_004AE370, 0, 0x6800);
    memset(D_004AC970, 0, 0x1A00);
    memset(D_004AC630, 0, 0x340);
    for (i = 0; i < 64; i++) { init(&D_004AE370[0][i], 0); init(&D_004AE370[1][i], 0); }
    for (i = 0; i < 16; i++) { init(&D_004AC970[0][i], 1); init(&D_004AC970[1][i], 1); }
    init(&D_004AC630[0], 2); init(&D_004AC630[1], 2); init(&D_004AC630[2], 2); init(&D_004AC630[3], 2);
}
#undef D_004AC5A0
