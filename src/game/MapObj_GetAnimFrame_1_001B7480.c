#include "m2c.h"
#include "common.h"
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 pad[0x18]; u16 x18; u16 x1A; u8 pad2[0x30 - 0x1C]; } E_MapObj_GetNodeFlags_0_001B76C0;
typedef struct { char p[0x1A]; u16 id; char rest[0x14]; } E_MapObj_GetNode_0_001B77A0;
typedef struct { char pad[0x6E]; u16 n; char p70[0xC8]; E_MapObj_GetNode_0_001B77A0 *e; } T_MapObj_GetNode_0_001B77A0;
typedef struct { char p[0x1A]; u16 id; char rest[0x14]; } E_MapObj_GetNodeIndex_0_001B7840;
typedef struct { char pad[0x6E]; u16 n; char p70[0xC8]; E_MapObj_GetNodeIndex_0_001B7840 *e; } T_MapObj_GetNodeIndex_0_001B7840;
typedef struct { u8 pad[0x14]; u16 n; } C;
typedef struct { u8 pad[0x1A]; u16 id; u8 pad2[0x14]; } E30;
typedef struct { u8 pad[0x40]; void ***m; u8 pad2[0x3C]; } E80_MapObj_SetNodeMatrix_0_001B78D0;
typedef struct { u8 pad[0x6E]; u16 count; u8 pad2[0x138-0x70]; E30 *arr; u8 pad3[0x180-0x13C]; E80_MapObj_SetNodeMatrix_0_001B78D0 *ent; } Obj_MapObj_SetNodeMatrix_0_001B78D0;
typedef struct { u8 pad[0x51]; u8 b0:1; u8 b1:2; u8 b3:5; u8 pad2[0x2E]; } E80_MapObj_SetNodeMatrixB_0_001B7A30;
typedef struct { u8 pad[0x6E]; u16 count; u8 pad2[0x138-0x70]; E30 *arr; u8 pad3[0x180-0x13C]; E80_MapObj_SetNodeMatrixB_0_001B7A30 *ent; } Obj_MapObj_SetNodeMatrixB_0_001B7A30;
typedef struct { s8 pad[0x1A]; u16 x1A; s8 pad2[0x14]; } Ent;
typedef struct {
    s8 pad[0x6E];
    u16 n;
    s8 pad70[0xC8];
    Ent *ents;
    s8 pad13C[0x44];
    s8 *x180;
} Chr;
typedef struct { u8 pad[0x1A]; u16 x1A; u8 p[0x14]; } It;
typedef struct { u8 pad[0x6E]; u16 n; u8 p[0xC8]; It *items; } Obj_MapObj_StopAnim_1_001B7C10;
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad2[0x14]; } E_MapObj_PlayAnim_1_001B7CD0;
typedef struct { u8 pad[0x6E]; u16 n; u8 pad2[0xC8]; E_MapObj_PlayAnim_1_001B7CD0 *e; } P;
typedef struct { u8 pad[0x50]; u32 a:11; u32 f:8; u32 b:13; u8 pad2[0x2C]; } E80_MapObj_GetAnimState_0_001B7D80;
typedef struct { u8 pad[0x6E]; u16 count; u8 pad2[0x138-0x70]; E30 *arr; u8 pad3[0x180-0x13C]; E80_MapObj_GetAnimState_0_001B7D80 *ent; } Obj_MapObj_GetAnimState_0_001B7D80;
typedef struct { u8 pad[0x50]; u32 a:11; u32 f:8; u32 b:13; u8 pad2[0x2C]; } E80_MapObj_SetAnimState_0_001B7E80;
typedef struct { u8 pad[0x6E]; u16 count; u8 pad2[0x138-0x70]; E30 *arr; u8 pad3[0x180-0x13C]; E80_MapObj_SetAnimState_0_001B7E80 *ent; } Obj_MapObj_SetAnimState_0_001B7E80;
typedef struct { u8 pad[0x13]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 pad14[0x2C]; } E_MapObj_CheckProximity_0_001B7F90;
typedef struct { u8 pad[0x170]; E_MapObj_CheckProximity_0_001B7F90 *e; } V;
typedef struct { u8 pad[0x18]; u16 x18; u16 x1A; } A;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 pad[3]; f32 x1C; s32 pad2[4]; } S;
typedef struct { u8 b0 : 2; } BF50;
typedef struct { u8 p : 1; u8 v : 2; } BF51;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } BF8;
typedef struct { u8 p : 2; u8 v : 2; } BF24;
f32 MapObj_GetAnimFrame_1_001B7480(s32 a0, s32 a1, u32 a2);
f32 MapObj_GetAnimFrameB_1_001B7610(s32 arg0, s32 arg1, M2C_UNK arg2);
s32 MapObj_GetNodeFlags_0_001B76C0(s32 a0, s32 a1);
E_MapObj_GetNode_0_001B77A0* MapObj_GetNode_0_001B77A0(s32 a, s32 k);
s32 MapObj_GetNodeIndex_0_001B7840(s32 a, s32 k);
void MapObj_SetNodeMatrix_0_001B78D0(s32 arg0, s32 arg1, u32 arg2, s32 arg3);
void MapObj_SetNodeMatrixB_0_001B7A30(s32 arg0, s32 arg1, void *arg2);
void MapObj_GetNodeMatrix_0_001B7B30(s32 id, s32 key, void *out);
void MapObj_StopAnim_1_001B7C10(s32 a, s32 k);
void MapObj_PlayAnimWrap_0_001B7CC0(s32 arg0, s32 arg1);
void MapObj_PlayAnim_1_001B7CD0(s32 a, s32 k);
u16 MapObj_GetAnimState_0_001B7D80(s32 arg0, s32 arg1);
void MapObj_SetAnimState_0_001B7E80(s32 arg0, s32 arg1, s32 arg2);
void MapObj_CheckProximity_0_001B7F90(A *a0, s32 *a1, s32 a2, s32 a3);
void MapObj_StopAnimImpl_0_001B80B0(s32 a0, u32 a1);
s8* MapObj_Find_1_001B19A0(s32);
f32 Mdl_GetMotionLength_0_00173F70(s8 *, u16);
s8* Mdl_GetFrameData_0_001715B0(void ***);
void sceVu0CopyMatrix(s32, s8 *);
void MapObj_PlayAnimImpl_1_001B8350(s32, s32, s32);
void Player_GetPos_1_001C9410(Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void memset(void *, s32, s32);
f32 sceVu0InnerProduct(Vec *, Vec *);
void Event_CheckTrigger_0_00179F80(S *);
f32 sqrtf(f32);
s32 MapState_GetField_0_001A9D50(s32, u16);
void MapState_SetField_0_001A9E10(s32, u16, u8);
void MapObj_SetAnimFrame_0_001B87C0(s8 *, u32, s32, s32, f32, f32);
void Mdl_AnimateWrap_0_00171B70(s8 *, u16, f32);
void sceVu0CopyVector(s8 *, s8 *);
void Mdl_UpdateBoneMatricesCur_0_00171540(s8 *, s8 *);
void Sfx_SetTransform_1_001677C0(s8 *, s8 *);

/* MapObj_GetAnimFrame_1_001B7480 */
f32 MapObj_GetAnimFrame_1_001B7480(s32 a0, s32 a1, u32 a2) {
    s8 ****pp;
    s8 **q;
    u16 k;
    s8 *e;
    u16 idx;
    s8 *p;
    s8 *tbl;
    s8 *t;
    s8 *o;
    s8 *s;
    s32 c;

    p = MapObj_Find_1_001B19A0(a0);
    if (p == NULL) {
        return 0.0f;
    }
    e = *(s8 **)(p + 0x180) + (a1 << 7);
    idx = *(u16 *)(*(s8 **)(p + 0x138) + a1 * 0x30 + 0x18);
    tbl = *(s8 **)(p + 0x170);
    t = tbl + (idx << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF3 *)(t + 0x12))->v) {
        k = *(u16 *)(tbl + (*(u16 *)(t + 6) << 6));
        pp = *(s8 *****)(e + 0x44);
    } else {
        pp = *(s8 *****)(e + 0x40);
        k = idx;
    }
    if (pp == NULL || *pp == NULL) {
        return 0.0f;
    }
    q = **pp;
    s = *(s8 **)(p + 0x194) + k * 0x10;
    if (q == NULL || (o = *q) == NULL) {
        return 0.0f;
    }
    if (*(u16 *)(o + 0x16) <= 0) {
        return 0.0f;
    }
    if (a2 >= *(u32 *)(s + 4)) {
        return 0.0f;
    }
    c = (*(u8 **)(s + 8))[a2];
    if (c == 0xFF) {
        return 0.0f;
    }
    if (q && q) {
    } /* permuter: scheduling barrier */
    return 30.0f * Mdl_GetMotionLength_0_00173F70(o, c);
}

/* MapObj_GetAnimFrameB_1_001B7610 */
#define MapObj_GetAnimFrame_1_001B7480 MapObj_GetAnimFrame_1_001B7480__as_MapObj_GetAnimFrameB_1_001B7610
f32 MapObj_GetAnimFrame_1_001B7480__as_MapObj_GetAnimFrameB_1_001B7610(s32, s32, M2C_UNK);

f32 MapObj_GetAnimFrameB_1_001B7610(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s8 *e;
    s8 *p;
    s32 n;
    s32 i;

    p = MapObj_Find_1_001B19A0(arg0);
    if (p == NULL) {
        return 0.0f;
    }
    n = M2C_FIELD(p, u16 *, 0x6E);
    i = 0;
    if (i < n) {
        e = M2C_FIELD(p, s8 **, 0x138);
        do {
            if (arg1 == M2C_FIELD(e, u16 *, 0x1A) % 100) {
                return MapObj_GetAnimFrame_1_001B7480(arg0, i, arg2);
            }
            i++;
            e += 0x30;
        } while (i < n);
    }
    return 0.0f;
}
#undef MapObj_GetAnimFrame_1_001B7480

/* MapObj_GetNodeFlags_0_001B76C0 */
static inline E_MapObj_GetNodeFlags_0_001B76C0 *find_MapObj_GetNodeFlags_0_001B76C0(s32 a0, s32 a1) {
    s32 i;
    u16 n;
    E_MapObj_GetNodeFlags_0_001B76C0 *q;
    s8 *p;
    E_MapObj_GetNodeFlags_0_001B76C0 *e;
    p = MapObj_Find_1_001B19A0(a0);
    if (p == NULL) {
        return NULL;
    }
    n = M2C_FIELD(p, u16 *, 0x6E);
    i = 0;
    if (i < n) {
        e = M2C_FIELD(p, E_MapObj_GetNodeFlags_0_001B76C0 **, 0x138);
        q = e;
        do {
            if (a1 == q->x1A % 100) {
                return &e[i];
            }
            i++;
            q++;
        } while (i < n);
    }
    return NULL;
}

s32 MapObj_GetNodeFlags_0_001B76C0(s32 a0, s32 a1) {
    s8 *s;
    E_MapObj_GetNodeFlags_0_001B76C0 *r;

    s = MapObj_Find_1_001B19A0(a0);
    r = find_MapObj_GetNodeFlags_0_001B76C0(a0, a1);
    if (s == NULL || r == NULL) {
        return 0;
    }
    return M2C_FIELD(s, s32 *, 0x170) + (r->x18 << 6);
}

/* MapObj_GetNode_0_001B77A0 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_GetNode_0_001B77A0
T_MapObj_GetNode_0_001B77A0 *MapObj_Find_1_001B19A0__as_MapObj_GetNode_0_001B77A0(s32 a);

E_MapObj_GetNode_0_001B77A0 *MapObj_GetNode_0_001B77A0(s32 a, s32 k)
{
    T_MapObj_GetNode_0_001B77A0 *t = MapObj_Find_1_001B19A0(a);
    s32 i;
    if (!t)
        return NULL;
    for (i = 0; i < t->n; i++) {
        if (k == t->e[i].id % 100)
            return &t->e[i];
    }
    return NULL;
}
#undef MapObj_Find_1_001B19A0

/* MapObj_GetNodeIndex_0_001B7840 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_GetNodeIndex_0_001B7840
T_MapObj_GetNodeIndex_0_001B7840 *MapObj_Find_1_001B19A0__as_MapObj_GetNodeIndex_0_001B7840(s32 a);

s32 MapObj_GetNodeIndex_0_001B7840(s32 a, s32 k)
{
    T_MapObj_GetNodeIndex_0_001B7840 *t = MapObj_Find_1_001B19A0(a);
    s32 i;
    if (!t)
        return -1;
    for (i = 0; i < t->n; i++) {
        if (k == t->e[i].id % 100)
            return i;
    }
    return -1;
}
#undef MapObj_Find_1_001B19A0

/* MapObj_SetNodeMatrix_0_001B78D0 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_SetNodeMatrix_0_001B78D0
Obj_MapObj_SetNodeMatrix_0_001B78D0 *MapObj_Find_1_001B19A0__as_MapObj_SetNodeMatrix_0_001B78D0(s32);
static inline s32 find_MapObj_SetNodeMatrix_0_001B78D0(s32 a0, s32 a1) {
    Obj_MapObj_SetNodeMatrix_0_001B78D0 *p = MapObj_Find_1_001B19A0(a0);
    s32 i;
    if (p == NULL) return -1;
    for (i = 0; i < p->count; i++) {
        if (a1 == p->arr[i].id % 100) return i;
    }
    return -1;
}

void MapObj_SetNodeMatrix_0_001B78D0(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    Obj_MapObj_SetNodeMatrix_0_001B78D0 *o = MapObj_Find_1_001B19A0(arg0);
    u32 i = find_MapObj_SetNodeMatrix_0_001B78D0(arg0, arg1);
    void ***m;
    C *c;
    s8 *v;
    if (o != NULL && i < o->count) {
        m = ((E80_MapObj_SetNodeMatrix_0_001B78D0 *)((s8 *)o->ent + (i << 7)))->m;
        if (m == NULL || *m == NULL) return;
        if (**m == NULL || (c = **(C ***)*m) == NULL) return;
        v = Mdl_GetFrameData_0_001715B0(m);
        if (arg2 < c->n) {
            sceVu0CopyMatrix(arg3, v + (arg2 + 1) * 0x140 + 0xC0);
        }
    }
}
#undef MapObj_Find_1_001B19A0

/* MapObj_SetNodeMatrixB_0_001B7A30 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_SetNodeMatrixB_0_001B7A30
Obj_MapObj_SetNodeMatrixB_0_001B7A30 *MapObj_Find_1_001B19A0__as_MapObj_SetNodeMatrixB_0_001B7A30(s32);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_MapObj_SetNodeMatrixB_0_001B7A30
void sceVu0CopyMatrix__as_MapObj_SetNodeMatrixB_0_001B7A30(void *, void *);
static inline s32 find_MapObj_SetNodeMatrixB_0_001B7A30(s32 a0, s32 a1) {
    Obj_MapObj_SetNodeMatrixB_0_001B7A30 *p = MapObj_Find_1_001B19A0(a0);
    s32 i;
    if (p == NULL) return -1;
    for (i = 0; i < p->count; i++) {
        if (a1 == p->arr[i].id % 100) return i;
    }
    return -1;
}

void MapObj_SetNodeMatrixB_0_001B7A30(s32 arg0, s32 arg1, void *arg2) {
    Obj_MapObj_SetNodeMatrixB_0_001B7A30 *o = MapObj_Find_1_001B19A0(arg0);
    u32 i = find_MapObj_SetNodeMatrixB_0_001B7A30(arg0, arg1);
    E80_MapObj_SetNodeMatrixB_0_001B7A30 *e;
    if (o != NULL && i < o->count) {
        e = (E80_MapObj_SetNodeMatrixB_0_001B7A30 *)((s8 *)o->ent + (i << 7));
        sceVu0CopyMatrix(e, arg2);
        e->b1 = 2;
    }
}
#undef MapObj_Find_1_001B19A0
#undef sceVu0CopyMatrix

/* MapObj_GetNodeMatrix_0_001B7B30 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_GetNodeMatrix_0_001B7B30
Chr *MapObj_Find_1_001B19A0__as_MapObj_GetNodeMatrix_0_001B7B30(s32);
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_MapObj_GetNodeMatrix_0_001B7B30
void sceVu0CopyMatrix__as_MapObj_GetNodeMatrix_0_001B7B30(void *, void *);
static inline s32 lookup(Chr *c, s32 key) {
    s32 i;
    if (c == 0) {
        return -1;
    }
    for (i = 0; i < c->n; i++) {
        if (key == c->ents[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapObj_GetNodeMatrix_0_001B7B30(s32 id, s32 key, void *out) {
    Chr *t = MapObj_Find_1_001B19A0(id);
    u32 idx = lookup(MapObj_Find_1_001B19A0(id), key);
    if (t != 0 && idx < t->n) {
        sceVu0CopyMatrix(out, t->x180 + idx * 0x80);
    }
}
#undef MapObj_Find_1_001B19A0
#undef sceVu0CopyMatrix

/* MapObj_StopAnim_1_001B7C10 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_StopAnim_1_001B7C10
Obj_MapObj_StopAnim_1_001B7C10 *MapObj_Find_1_001B19A0__as_MapObj_StopAnim_1_001B7C10(s32);
#define MapObj_StopAnimImpl_0_001B80B0 MapObj_StopAnimImpl_0_001B80B0__as_MapObj_StopAnim_1_001B7C10
void MapObj_StopAnimImpl_0_001B80B0__as_MapObj_StopAnim_1_001B7C10(s32, s32);
static inline s32 find_MapObj_StopAnim_1_001B7C10(s32 a, s32 k) {
    Obj_MapObj_StopAnim_1_001B7C10 *o = MapObj_Find_1_001B19A0(a);
    s32 i;
    if (o == 0) return -1;
    for (i = 0; i < o->n; i++) {
        if (k == o->items[i].x1A % 100) return i;
    }
    return -1;
}
void MapObj_StopAnim_1_001B7C10(s32 a, s32 k) {
    MapObj_StopAnimImpl_0_001B80B0(a, find_MapObj_StopAnim_1_001B7C10(a, k));
}
#undef MapObj_Find_1_001B19A0
#undef MapObj_StopAnimImpl_0_001B80B0

/* MapObj_PlayAnimWrap_0_001B7CC0 */
#define MapObj_PlayAnimImpl_1_001B8350 MapObj_PlayAnimImpl_1_001B8350__as_MapObj_PlayAnimWrap_0_001B7CC0
int MapObj_PlayAnimImpl_1_001B8350__as_MapObj_PlayAnimWrap_0_001B7CC0();
void MapObj_PlayAnimWrap_0_001B7CC0(s32 arg0, s32 arg1) {
    MapObj_PlayAnimImpl_1_001B8350(arg0, arg1, 0);
}
#undef MapObj_PlayAnimImpl_1_001B8350

/* MapObj_PlayAnim_1_001B7CD0 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_PlayAnim_1_001B7CD0
P *MapObj_Find_1_001B19A0__as_MapObj_PlayAnim_1_001B7CD0(s32);

static inline s32 find_MapObj_PlayAnim_1_001B7CD0(s32 a, s32 k) {
    P *p;
    E_MapObj_PlayAnim_1_001B7CD0 *e;
    s32 n;
    s32 i;
    p = MapObj_Find_1_001B19A0(a);
    if (p == NULL) return -1;
    n = p->n;
    i = 0;
    if (i < n) {
        e = p->e;
        do {
            if (k == e->x1A % 100) return i;
            i++;
            e++;
        } while (i < n);
    }
    return -1;
}
void MapObj_PlayAnim_1_001B7CD0(s32 a, s32 k) {
    MapObj_PlayAnimImpl_1_001B8350(a, find_MapObj_PlayAnim_1_001B7CD0(a, k), 0);
}
#undef MapObj_Find_1_001B19A0

/* MapObj_GetAnimState_0_001B7D80 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_GetAnimState_0_001B7D80
Obj_MapObj_GetAnimState_0_001B7D80 *MapObj_Find_1_001B19A0__as_MapObj_GetAnimState_0_001B7D80(s32);
static inline s32 find_MapObj_GetAnimState_0_001B7D80(s32 a0, s32 a1) {
    Obj_MapObj_GetAnimState_0_001B7D80 *p = MapObj_Find_1_001B19A0(a0);
    s32 i;
    if (p == NULL) return -1;
    for (i = 0; i < p->count; i++) {
        if (a1 == p->arr[i].id % 100) return i;
    }
    return -1;
}

u16 MapObj_GetAnimState_0_001B7D80(s32 arg0, s32 arg1) {
    Obj_MapObj_GetAnimState_0_001B7D80 *o = MapObj_Find_1_001B19A0(arg0);
    s32 i = find_MapObj_GetAnimState_0_001B7D80(arg0, arg1);
    if (o == NULL) return 0;
    if (i < 0 || i >= o->count) return 0;
    return o->ent[i].f;
}
#undef MapObj_Find_1_001B19A0

/* MapObj_SetAnimState_0_001B7E80 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_SetAnimState_0_001B7E80
Obj_MapObj_SetAnimState_0_001B7E80 *MapObj_Find_1_001B19A0__as_MapObj_SetAnimState_0_001B7E80(s32);
static inline s32 find_MapObj_SetAnimState_0_001B7E80(s32 a0, s32 a1) {
    Obj_MapObj_SetAnimState_0_001B7E80 *p = MapObj_Find_1_001B19A0(a0);
    s32 i;
    if (p == NULL) return -1;
    for (i = 0; i < p->count; i++) {
        if (a1 == p->arr[i].id % 100) return i;
    }
    return -1;
}

void MapObj_SetAnimState_0_001B7E80(s32 arg0, s32 arg1, s32 arg2) {
    Obj_MapObj_SetAnimState_0_001B7E80 *o = MapObj_Find_1_001B19A0(arg0);
    s32 i = find_MapObj_SetAnimState_0_001B7E80(arg0, arg1);
    if (o != NULL) {
        if (i < 0 || i >= o->count) return;
        o->ent[i].f = arg2;
    }
}
#undef MapObj_Find_1_001B19A0

/* MapObj_CheckProximity_0_001B7F90 */
#define MapObj_Find_1_001B19A0 MapObj_Find_1_001B19A0__as_MapObj_CheckProximity_0_001B7F90
V *MapObj_Find_1_001B19A0__as_MapObj_CheckProximity_0_001B7F90(s32);
#define Mdl_GetFrameData_0_001715B0 Mdl_GetFrameData_0_001715B0__as_MapObj_CheckProximity_0_001B7F90
s8 *Mdl_GetFrameData_0_001715B0__as_MapObj_CheckProximity_0_001B7F90(s32);

void MapObj_CheckProximity_0_001B7F90(A *a0, s32 *a1, s32 a2, s32 a3) {
    V *v;
    E_MapObj_CheckProximity_0_001B7F90 *e;
    s8 *r;
    S s;
    Vec d;
    v = MapObj_Find_1_001B19A0(a2);
    if (v == NULL) return;
    if (a0->x1A % 100 == 0) return;
    e = &v->e[a0->x18];
    r = Mdl_GetFrameData_0_001715B0(a1[0x10]);
    Player_GetPos_1_001C9410(&d);
    sceVu0SubVector(&d, &d, (Vec *)(r + 0x230));
    if (!e->b3) d.y = 0.0f;
    memset(&s, 0, 0x30);
    s.x0 = 0;
    s.x4 = a0->x1A % 100;
    s.x8 = a2;
    s.xC = a3;
    s.x1C = sqrtf(sceVu0InnerProduct(&d, &d));
    Event_CheckTrigger_0_00179F80(&s);
}
#undef MapObj_Find_1_001B19A0
#undef Mdl_GetFrameData_0_001715B0

/* MapObj_StopAnimImpl_0_001B80B0 */
#define Mdl_GetFrameData_0_001715B0 Mdl_GetFrameData_0_001715B0__as_MapObj_StopAnimImpl_0_001B80B0
s8 *Mdl_GetFrameData_0_001715B0__as_MapObj_StopAnimImpl_0_001B80B0(s8 **);

void MapObj_StopAnimImpl_0_001B80B0(s32 a0, u32 a1) {
    s8 *p;
    s8 *t;
    s8 *e;
    s8 *s;
    s8 **q;
    s8 **m;
    s8 *r;
    s32 mode;

    p = MapObj_Find_1_001B19A0(a0);
    if (p != NULL) {
    t = *(s8 **)(p + 0x138) + a1 * 0x30;
    e = *(s8 **)(p + 0x180) + (a1 << 7);
    s = *(s8 **)(p + 0x170) + (*(u16 *)(t + 0x18) << 6);
    if (*(u16 *)(s + 4) == 2 && (*(u8 *)(e + 0x50) & 3)) {
    MapState_SetField_0_001A9E10(*(s32 *)p, a1, MapState_GetField_0_001A9D50(*(s32 *)p, a1) & ~1);
    ((BF50 *)(e + 0x50))->b0 = 0;
    ((BF8 *)(e + 0x52))->b3 = 1;
    ((BF8 *)(e + 0x52))->b4 = 0;
    *(f32 *)(e + 0x58) = 1.0f;
    m = *(s8 ***)(e + 0x40);
    if (m == NULL || *m == NULL) {
        return;
    }
    q = *(s8 ***)*m;
    if (q == NULL || *q == NULL) {
        return;
    }
    if (((BF8 *)(s + 0x12))->b0 && *(u16 *)(*q + 0x16) != 0) {
        mode = ((BF24 *)(t + 0x24))->v;
        if (mode == 1) {
            MapObj_SetAnimFrame_0_001B87C0(p, a1, 0, 0x80, 0.0f, 1.0f);
        } else if (mode == 2) {
            MapObj_SetAnimFrame_0_001B87C0(p, a1, 0, 0, 0.0f, 1.0f);
            ((BF8 *)(e + 0x52))->b7 = 1;
        }
        Mdl_AnimateWrap_0_00171B70(*m, *(u16 *)(*m + 8), *(f32 *)(*m + 0xC));
    }
    sceVu0CopyVector(*m + 0x30, p + 0x10);
    Mdl_UpdateBoneMatricesCur_0_00171540(*m, e);
    ((BF51 *)(e + 0x51))->v = 2;
    if (*(s8 **)(e + 0x54) != NULL) {
        r = Mdl_GetFrameData_0_001715B0(m);
        if (*(u8 *)(s + 2) < *(u16 *)(*q + 0x14)) {
            Sfx_SetTransform_1_001677C0(*(s8 **)(e + 0x54), r + (*(u8 *)(s + 2) + 1) * 0x140 + 0xC0);
            return;
        }
        Sfx_SetTransform_1_001677C0(*(s8 **)(e + 0x54), r + 0x200);
    }
    }
    }
}
#undef Mdl_GetFrameData_0_001715B0
