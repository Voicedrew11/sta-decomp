#include "common.h"
#include "m2c.h"
typedef f32 Mtx_Enemy_GetAttachMatrix_0_001A5AA0[4][4];
typedef struct { u8 pad[0x30]; } Elem;
typedef struct { u8 pad[0x138]; Elem *base; } Tbl;
typedef struct { u8 pad[0x40]; s32 id; } Inf;
typedef struct {
    u8 pad0[0xC0];
    Tbl *tbl;
    s32 padC4;
    Elem *cur;
    Inf *inf;
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m;
    s32 x110;
    s32 x114;
} Obj;
typedef struct { u8 pad[0x10]; Obj *obj; } Arg;
extern Mtx_Enemy_GetAttachMatrix_0_001A5AA0 D_001F2170;
void Enemy_DropItems_0_001A5990(s8 *a0);
u8 Enemy_GetAttachMatrix_0_001A5AA0(u16 *flag, Arg *a, Mtx_Enemy_GetAttachMatrix_0_001A5AA0 out);
s32 Inventory_CountItem_0_001CC0C0(s32, s32);
u32 Rand_Next_3_0015ED20(void);
void sceVu0CopyVector(Vec *, void *);
void* ItemObj_Drop_0_001AE900(s32, s16, Vec *, Vec *, s32, s32);
void sceVu0CopyMatrix(Mtx_Enemy_GetAttachMatrix_0_001A5AA0, Mtx_Enemy_GetAttachMatrix_0_001A5AA0);
void sceVu0MulMatrix(Mtx_Enemy_GetAttachMatrix_0_001A5AA0, Mtx_Enemy_GetAttachMatrix_0_001A5AA0, Mtx_Enemy_GetAttachMatrix_0_001A5AA0);
s8* Mdl_GetFrameData_0_001715B0(s32);
void MapObj_CheckActivate_0_001B1A20(Tbl *, s32, s32);

/* Enemy_DropItems_0_001A5990 */
void Enemy_DropItems_0_001A5990(s8 *a0) {
    u16 *p;
    s32 i;
    s32 id;
    u16 v;
    Vec a;
    Vec b;
    p = (u16 *)(*(s8 **)(a0 + 0x4B0) + 0x250);
    for (i = 0; i < 4; i++) {
        id = p[8];
        v = p[0xC];
        if (id < 0x400 && v != 0 && Inventory_CountItem_0_001CC0C0(id, 1) && Rand_Next_3_0015ED20() % 100 < v) {
            sceVu0CopyVector(&a, *(void **)(a0 + 0x518));
            sceVu0CopyVector(&b, *(s8 **)(a0 + 0x518) + 0x20);
            a.y -= 100.0f;
            ItemObj_Drop_0_001AE900(*(s32 *)(a0 + 0x4A8), id, &a, &b, 1, 1);
            return;
        }
        p++;
    }
}

/* Enemy_GetAttachMatrix_0_001A5AA0 */
u8 Enemy_GetAttachMatrix_0_001A5AA0(u16 *flag, Arg *a, Mtx_Enemy_GetAttachMatrix_0_001A5AA0 out) {
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m1;
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m2;
    Mtx_Enemy_GetAttachMatrix_0_001A5AA0 m3;
    s8 *p;
    u8 i;
    u8 j;
    u8 changed = 0;

    sceVu0CopyMatrix(out, D_001F2170);
    if (a->obj->cur != NULL) {
        p = Mdl_GetFrameData_0_001715B0(a->obj->inf->id);
        sceVu0CopyMatrix(m1, a->obj->m);
        sceVu0CopyMatrix(m2, (f32 (*)[4])(p + 0x200));
        sceVu0CopyMatrix(a->obj->m, m2);
        if (a->obj->x114 == a->obj->x110) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    if (m1[i][j] != m2[i][j]) {
                        changed = 1;
                    }
                }
            }
            if (changed) {
                sceVu0CopyMatrix(m3, D_001F2170);
                m3[0][0] = m1[0][0];
                m3[0][1] = m1[1][0];
                m3[0][2] = m1[2][0];
                m3[0][3] = 0.0f;
                m3[1][0] = m1[0][1];
                m3[1][1] = m1[1][1];
                m3[1][2] = m1[2][1];
                m3[1][3] = 0.0f;
                m3[2][0] = m1[0][2];
                m3[2][1] = m1[1][2];
                m3[2][2] = m1[2][2];
                m3[2][3] = 0.0f;
                m3[3][3] = 0.0f;
                sceVu0MulMatrix(out, m2, m3);
                out[3][0] = m2[3][0] - m1[3][0];
                out[3][1] = m2[3][1] - m1[3][1];
                out[3][2] = m2[3][2] - m1[3][2];
                out[3][3] = 1.0f;
            }
        }
        if (*flag == 0) {
            MapObj_CheckActivate_0_001B1A20(a->obj->tbl, a->obj->cur - a->obj->tbl->base, 1);
        }
    }
    return changed;
}
