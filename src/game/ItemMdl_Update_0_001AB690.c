#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0x14]; s32 x14; Flags8 f18; } A;
typedef struct { u8 pad[0x90]; s32 x90; u8 pad2[0x8]; s16 h9C; s16 h9E; u8 pad3[8]; Flags8 fA8; } B;
typedef struct { u8 a:3; u8 f:3; u8 c:2; } F3b;
typedef struct { u8 pad[0x24]; Flags8 x24; } Anim;
typedef struct { u8 pad[0xA]; u16 xA; u16 xC; u8 padE[0x42]; u16 x50; u8 pad52[6]; s16 x58[2]; s8 x5C[2][2]; u8 pad60[0x30]; } Ent;
typedef struct { Anim *a; } M84;
typedef struct {
    u8 pad0[0x84];
    M84 *x84;
    u8 pad88[0x14];
    s16 idx;
    u8 pad9E[0xA];
    Flags8 xA8;
    Flags8 xA9;
    u8 padAA[0xE];
    s8 *xB8;
    s8 *xBC;
    s8 *xC0[2][2];
} Node;
typedef struct { u8 pad[0x60]; f32 a[4]; f32 b[4]; f32 c[4]; } Bone;
typedef struct {
    f32 m[8][4];
    u8 pad80[0xC];
    s32 **pp;
    u8 pad8c[0x9C - 0x90];
    s16 bone;
    s16 busy;
    u8 padA0[0xA9 - 0xA0];
    u8 f0:1; u8 local:1; u8 hide:1; u8 rest:5;
    u16 id;
    u8 padAC[0xD0 - 0xAC];
} Obj;
extern A *D_00202290;
extern s32 D_0020228C;
extern B *D_00202288;
extern s32 D_002022A0;
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B78[];
extern s32 D_004B4B7C[];
extern s32 *D_004B4B80[];
extern s32 *D_004B4B84[];
extern s32 D_004B4B88[];
extern F3b D_00222A54[];
extern s8 D_001FD9D0[];
extern s8 D_001FD9F0[];
extern s8 D_00270F40[];
extern s32 D_004AC630[];
extern s32 D_004AC970[];
extern s32 D_004AD670[];
extern s32 D_004AE370[];
extern s32 D_004B1770[];
extern Ent *D_002022B0;
extern s32 D_00201F2C;
void ItemMdl_Update_0_001AB690(void);
void* ItemMdl_NextRequest_0_001ABB20(void);
void ItemMdl_Spawn_0_001ABCC0(Node *o, s32 a1);
s32 ItemMdl_SetTransform_0_001ABF70(s32 key, s32 arg1, s32 arg2);
void Pool_Free_2_00128580(A *, s32 *);
void Task_RunWrap_0_0014DAB0(s32);
void sprintf(s8 *, s8 *, s32);
void strcpy(s8 *, s8 *);
s32 File_HashName_3_00159D10(s8 *);
s32 Arc_FindByHash_2_0015ABD0(s32);
s32 File_GetSectorOrSize_0_0015A300(s32);
void File_Close_2_0015AB80(s32);
s32* Pool_Alloc_3_001288C0(A *, s32);
s32 Task_SetPriorityWrap_0_0014DB00(s8 *, s32, s8 *);
s32 Obj_FreeTimer_0_0014DA70(s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
u8 Task_KillWrap_0_0014DAF0(s32);
void FlushCache(s32);
void Dma_SprCopy_1_001789E0(s32, s8 *, s32);
void memcpy(s32, s8 *, s32);
void Task_RemoveWrap_0_0014DAE0(s32);
s32 Obj_SetTimerEx_0_0014DA90(s32, s32, s32, s32);
s32 Obj_SetTimer_0_0014DA80(s32, s32);
s32* Tex_LoadArchive_0_0016F950(s32, s32 *);
s32 Tex_FindAnim_0_0016FF80(s32);
M84* Mdl_CreateInstance_0_00174230(s32, s32, s32, s32);
void Mdl_UpdateBoneMatricesCur_0_00171540(Anim *, Node *);
s32 Sfx_IsLoaded_2_00169BB0(s32);
s8* Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void Sfx_SetTransform_1_001677C0(s8 *, void *);
void sceVu0MulMatrix(void *, void *, void *);
void sceVu0AddVector(void *, void *, void *);
void sceVu0SubVector(void *, s32, void *, u32);
void Mtx_Compose_2_00173FD0(void *, void *, void *, void *);

/* ItemMdl_Update_0_001AB690 */
/* ItemMdl_Update_0_001AB690 */
#define ItemMdl_Spawn_0_001ABCC0 ItemMdl_Spawn_0_001ABCC0__as_ItemMdl_Update_0_001AB690
void ItemMdl_Spawn_0_001ABCC0__as_ItemMdl_Update_0_001AB690(B *, s32 *);
static inline void cleanup(void) {
    if (D_004B4B80[0]) Pool_Free_2_00128580(D_00202290, D_004B4B80[0]);
    if (D_004B4B74[0]) {
        Task_RunWrap_0_0014DAB0(D_004B4B74[0]);
        D_004B4B74[0] = 0;
    }
    D_004B4B80[0] = 0;
    D_00202288 = 0;
    D_004B4B74[0] = 0;
    D_0020228C = 0;
    D_004B4B70[0] = 0;
    D_004B4B88[0] = 0;
}

void ItemMdl_Update_0_001AB690(void) {
    s8 buf2[0x100];
    s8 buf1[0x100];
    s32 s;
    u32 n;
    s32 r;
    s32 q;
    s32 p;
    B *b;
    s32 c;
    s32 k;

    if (D_00202290 == NULL) return;
    if (D_00202290->f18.f.b1 && D_00202290->x14 != 0) return;
    if (D_0020228C != 0) {
        cleanup();
        return;
    }
    if (D_00202288 == 0) D_00202288 = ItemMdl_NextRequest_0_001ABB20();
    if (D_00202288 == 0) return;
    if (!D_00202288->fA8.f.b1) {
        c = D_00202288->h9E == 2 && D_00202288->h9C >= 800;
        k = D_00202288->h9C;
        if (c) sprintf(buf1, D_001FD9D0, k);
        else sprintf(buf1, D_001FD9F0, k);
        strcpy(buf2, buf1);
        if (D_004B4B78) {
            s = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf1));
            D_004B4B78[0] = File_GetSectorOrSize_0_0015A300(s);
            File_Close_2_0015AB80(s);
        }
        D_004B4B80[0] = Pool_Alloc_3_001288C0(D_00202290, D_004B4B78[0]);
        D_004B4B84[0] = 0;
        D_004B4B7C[0] = 0;
        D_004B4B74[0] = Task_SetPriorityWrap_0_0014DB00(buf2, 0x102, D_00270F40);
        D_004B4B7C[0] = Obj_FreeTimer_0_0014DA70(D_004B4B74[0]);
        Task_FlushWrap_0_0014DAC0(D_004B4B74[0], 0);
        D_00202288->fA8.f.b1 = 1;
    }
    switch (Task_KillWrap_0_0014DAF0(D_004B4B74[0])) {
    case 0:
        break;
    case 5:
        n = D_004B4B78[0] - D_004B4B7C[0];
        n = (n > 0x80000) ? 0x80000 : n;
        q = (s32)n >> 4;
        r = n - q * 16;
        FlushCache(0);
        Dma_SprCopy_1_001789E0(*D_004B4B80[0] + D_004B4B7C[0], D_00270F40, q);
        if (r > 0) memcpy(*D_004B4B80[0] + D_004B4B7C[0] + q * 16, D_00270F40 + q * 16, r);
        D_004B4B7C[0] += n;
        Task_RemoveWrap_0_0014DAE0(D_004B4B74[0]);
        break;
    case 3:
    case 6:
        if (D_004B4B70[0] != 0) break;
        p = *D_004B4B80[0];
        if (D_004B4B88[0] == 0) {
            if (Obj_SetTimerEx_0_0014DA90(D_004B4B74[0], p, p, D_004B4B78[0])) D_004B4B88[0] = 1;
        }
        if (D_004B4B88[0] != 0 && Obj_SetTimer_0_0014DA80(D_004B4B74[0], 8) != 0) break;
        D_004B4B88[0] = 0;
        D_004B4B84[0] = Tex_LoadArchive_0_0016F950(D_002022A0, D_004B4B80[0]);
        b = D_00202288;
        b->x90 = Tex_FindAnim_0_0016FF80(*D_004B4B84[0]);
        ItemMdl_Spawn_0_001ABCC0(D_00202288, D_004B4B84[0]);
        D_004B4B80[0] = 0;
        D_004B4B70[0] = 1;
        cleanup();
        break;
    case 1:
    case 2:
    case 4:
        D_00222A54[0].f = 3;
        break;
    }
}

/* ItemMdl_NextRequest_0_001ABB20 */

void *ItemMdl_NextRequest_0_001ABB20(void) {
    u8 temp_4_5;
    u8 temp_4_4;
    u8 temp_4_3;
    u8 temp_4_2;
    u8 temp_4;
    s32 var_6_5;
    s32 var_6_4;
    s32 var_6_3;
    s32 var_6_2;
    s32 var_6;
    s32 *var_2_5;
    s32 *var_2_4;
    s32 *var_2_3;
    s32 *var_2_2;
    s32 *var_2;

    var_6 = 0;
    var_2_5 = (s32 *) (D_004AC630);
loop_1:
    if (M2C_FIELD(var_2_5, s16 *, 0x9C) != -1) {
        temp_4 = M2C_FIELD(var_2_5, u8 *, 0xA8);
        if (!(temp_4 & 1) && (((u64) ((s64) temp_4 << 0x3E) >> 0x3F) == 0)) {
            return (s32 *) (var_2_5);
        }
    }
    var_6 += 1;
    var_2_5 = (s32*)((u8 *)var_2_5 + 0xD0);
    if (var_6 >= 4) {
        var_6_2 = 0;
        var_2_4 = (s32 *) (D_004AC970);
loop_7:
        if (M2C_FIELD(var_2_4, s16 *, 0x9C) != -1) {
            temp_4_2 = M2C_FIELD(var_2_4, u8 *, 0xA8);
            if (!(temp_4_2 & 1) && (((u64) ((s64) temp_4_2 << 0x3E) >> 0x3F) == 0)) {
                return (s32 *) (var_2_4);
            }
        }
        var_6_2 += 1;
        var_2_4 = (s32*)((u8 *)var_2_4 + 0xD0);
        if (var_6_2 >= 0x10) {
            var_6_3 = 0;
            var_2_3 = (s32 *) (D_004AD670);
loop_13:
            if (M2C_FIELD(var_2_3, s16 *, 0x9C) != -1) {
                temp_4_3 = M2C_FIELD(var_2_3, u8 *, 0xA8);
                if (!(temp_4_3 & 1) && (((u64) ((s64) temp_4_3 << 0x3E) >> 0x3F) == 0)) {
                    return (s32 *) (var_2_3);
                }
            }
            var_6_3 += 1;
            var_2_3 = (s32*)((u8 *)var_2_3 + 0xD0);
            if (var_6_3 >= 0x10) {
                var_6_4 = 0;
                var_2_2 = (s32 *) (D_004AE370);
loop_19:
                if (M2C_FIELD(var_2_2, s16 *, 0x9C) != -1) {
                    temp_4_4 = M2C_FIELD(var_2_2, u8 *, 0xA8);
                    if (!(temp_4_4 & 1) && (((u64) ((s64) temp_4_4 << 0x3E) >> 0x3F) == 0)) {
                        return (s32 *) (var_2_2);
                    }
                }
                var_6_4 += 1;
                var_2_2 = (s32*)((u8 *)var_2_2 + 0xD0);
                if (var_6_4 >= 0x40) {
                    var_6_5 = 0;
                    var_2 = (s32 *) (D_004B1770);
loop_25:
                    if (M2C_FIELD(var_2, s16 *, 0x9C) != -1) {
                        temp_4_5 = M2C_FIELD(var_2, u8 *, 0xA8);
                        if (!(temp_4_5 & 1) && (((u64) ((s64) temp_4_5 << 0x3E) >> 0x3F) == 0)) {
                            return (s32 *) (var_2);
                        }
                    }
                    var_6_5 += 1;
                    var_2 = (s32*)((u8 *)var_2 + 0xD0);
                    if (var_6_5 >= 0x40) {
                        return NULL;
                    }
                    goto loop_25;
                }
                goto loop_19;
            }
            goto loop_13;
        }
        goto loop_7;
    }
    goto loop_1;
}
#undef ItemMdl_Spawn_0_001ABCC0

/* ItemMdl_Spawn_0_001ABCC0 */
static inline Ent *ent(s16 i) {
    if (D_002022B0 != NULL && i > 0 && i < 0x400) return &D_002022B0[i];
    return NULL;
}

void ItemMdl_Spawn_0_001ABCC0(Node *o, s32 a1) {
    s8 *s;
    s32 k;
    s32 j;
    Ent *e;
    s32 save;
    s32 i;

    e = ent(o->idx);
    o->x84 = Mdl_CreateInstance_0_00174230(D_002022A0, a1, -1, -1);
    o->x84->a->x24.f.b2 = 0;
    save = D_00201F2C;
    for (i = 0; i < 2; i++) {
        D_00201F2C = i;
        Mdl_UpdateBoneMatricesCur_0_00171540(o->x84->a, o);
    }
    D_00201F2C = save;
    o->xA8.f.b1 = 0;
    o->xA8.f.b0 = 1;
    o->xA8.f.b7 = 1;
    o->xA9.f.b0 = 0;
    if (e->xC && Sfx_IsLoaded_2_00169BB0(e->xC)) {
        s = Sfx_Spawn_2_00169B50(e->xC, 0, 0, 0);
        if (s) Sfx_SetTransform_1_001677C0(s, o);
        o->xB8 = s;
    }
    if (e->xA == 2 && e->x50 && Sfx_IsLoaded_2_00169BB0(e->x50)) {
        s = Sfx_Spawn_2_00169B50(e->x50, 1, 0, 0);
        if (s) Sfx_SetTransform_1_001677C0(s, o);
        o->xBC = s;
    }
    if (e->xA == 1) {
        for (k = 0; k < 2; k++) {
            if (e->x58[k]) {
                for (j = 0; j < 2; j++) {
                    if (!(e->x5C[k][j] <= -1) && Sfx_IsLoaded_2_00169BB0(e->x58[k])) {
                        s = Sfx_Spawn_2_00169B50(e->x58[k], 1, 0, 0);
                        if (s) Sfx_SetTransform_1_001677C0(s, o);
                        o->xC0[k][j] = s;
                    }
                }
            }
        }
    }
}

/* ItemMdl_SetTransform_0_001ABF70 */
#define D_002022B0 D_002022B0__as_ItemMdl_SetTransform_0_001ABF70
extern Bone *D_002022B0__as_ItemMdl_SetTransform_0_001ABF70;
#define D_004AE370 D_004AE370__as_ItemMdl_SetTransform_0_001ABF70
extern Obj D_004AE370__as_ItemMdl_SetTransform_0_001ABF70[2][64];
static inline void update(Obj *o) {
    f32 tmp[16] __attribute__((aligned(16)));
    Bone *bones = D_002022B0;
    if (o != NULL && o->bone != -1) {
        if (o->local) {
            Mtx_Compose_2_00173FD0(o, o->m[4], o->m[5], o->m[6]);
        } else {
            Bone *b = &bones[o->bone];
            Mtx_Compose_2_00173FD0(tmp, b->a, b->b, b->c);
            Mtx_Compose_2_00173FD0(o, o->m[4], o->m[5], o->m[6]);
            sceVu0MulMatrix(o, o, tmp);
        }
        sceVu0AddVector(o->m[3], o->m[3], o->m[7]);
    }
}

s32 ItemMdl_SetTransform_0_001ABF70(s32 key, s32 arg1, s32 arg2) {
    u32 id = arg1 & 0xFFFF;
    s32 j, i;
    Obj *o;
    Obj *row;
    if (id == 0) return 0;
    for (i = 0, row = D_004AE370[0]; i < 2; i++, row += 64) {
        for (o = row, j = 0; j < 64; j++, o++) {
            if (o->busy == 0 && o->hide == 0 && o->pp != NULL && *o->pp != NULL && o->bone != -1 && **o->pp == key && o->id == id) {
                sceVu0SubVector(o->m[4], arg2, o->m[7], id);
                update(o);
                return 1;
            }
        }
    }
    return 0;
}
#undef D_002022B0
#undef D_004AE370
