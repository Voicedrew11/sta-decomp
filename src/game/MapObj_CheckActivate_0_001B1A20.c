#include "m2c.h"
#include "actor.h"
#include "common.h"
typedef struct { f32 x, y, z, w; } V;
typedef struct { s32 type; s32 a; s32 b; s32 c; f32 x, y, z, w; f32 h; f32 p; f32 r; s32 f; } Msg;
typedef struct { u8 pad[0x1A]; u16 v; u8 pad2[0x14]; } E30_MapObj_CheckActivate_0_001B1A20;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad2[0x3C]; } E80_MapObj_CheckActivate_0_001B1A20;
typedef struct { s32 id; u8 pad[0x6A]; u16 n; u8 pad2[0xC8]; E30_MapObj_CheckActivate_0_001B1A20 *e30; u8 pad3[0x44]; E80_MapObj_CheckActivate_0_001B1A20 *e80; } Obj_MapObj_CheckActivate_0_001B1A20;
typedef struct { u8 pad[0x24]; f32 x24; } H;
typedef struct { s32 v; u8 pad[0x4C]; } T;
typedef struct { u8 pad[0x1A]; s16 f1A; u8 pad2[0x14]; } E;
typedef struct { s32 pad[3]; T *tbl; s32 pad2[4]; } L;
typedef struct { u8 pad[0x10]; s32 *f10; } O;
typedef struct { s32 pad; O **f4; u8 pad2[0x12C]; E *f134; } A0;
typedef struct { u8 pad[0x20]; O *f20; s32 f24; u8 pad2[0x14]; s32 f3C; } A1;
typedef struct { u8 pad[0x1C]; u16 x1C; } X;
typedef struct { X *x; } Y;
typedef struct { Y *y; } Mdl;
typedef struct { u8 pad[0x18]; u16 x18; u8 pad1A[0x16]; } E30_MapObj_QueryColliders_0_001B1DF0;
typedef struct { u8 pad[0x40]; Mdl **x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 x52; u8 pad53[0x2D]; } E80_MapObj_QueryColliders_0_001B1DF0;
typedef struct { u8 pad[0x1E]; Flags8 x1E; u8 pad1F[0x21]; } E40;
typedef struct {
    u8 pad[0x6E]; u16 n; u8 pad70[0xC8]; E30_MapObj_QueryColliders_0_001B1DF0 *e30; u8 pad13C[0x34]; E40 *e40; u8 pad174[4]; Mdl ***x178; u8 pad17C[4]; E80_MapObj_QueryColliders_0_001B1DF0 *e80;
    u8 pad184[0x54]; Flags8 x1D8;
} Obj_MapObj_QueryColliders_0_001B1DF0;
typedef struct { u8 pad[0x30]; Obj_MapObj_QueryColliders_0_001B1DF0 *o; E30_MapObj_QueryColliders_0_001B1DF0 *c; E80_MapObj_QueryColliders_0_001B1DF0 *e; u8 pad3C[4]; } Ent;
typedef struct { u8 pad[0x24]; s32 x24; u8 pad28[8]; Obj_MapObj_QueryColliders_0_001B1DF0 *o; E30_MapObj_QueryColliders_0_001B1DF0 *c; E80_MapObj_QueryColliders_0_001B1DF0 *e; u8 pad3C[0xC]; } Tgt;
extern u16 D_00317238[];
extern Flags8 D_00222A52[];
s32 MapObj_CheckActivate_0_001B1A20(Obj_MapObj_CheckActivate_0_001B1A20 *o, s32 idx, s32 a2);
s32 MapObj_GetSection_0_001B1CB0(s32 arg0, void *arg1, s32 *arg2);
E* MapObj_FindCollider_0_001B1D00(A0 *arg0, A1 *arg1);
void MapObj_QueryColliders_0_001B1DF0(Obj_MapObj_QueryColliders_0_001B1DF0 *o, Tgt *t, s32 a2, u8 a3, s32 t0, s32 *out, s32 n, Ent *ents);
void sceVu0CopyVector(V *, void *);
s8* Mdl_GetFrameData_0_001715B0(s32);
void sceVu0CopyMatrix(V *, void *);
void sceVu0SubVector(V *, V *, V *);
f32 sceVu0InnerProduct(V *, V *);
f32 atan2f(f32, f32);
s32 Event_CheckTrigger_0_00179F80(Msg *);
f32 sqrtf(f32);
void Mdl_GetSectionPtrs_1_00171050(O *, L *);
void Coll_QueryMapCells_0_001520E0(Tgt *, Mdl *, s32, u8, s32, s32 *, s32, Ent *, Obj_MapObj_QueryColliders_0_001B1DF0 *, s32);

/* MapObj_CheckActivate_0_001B1A20 */
/* MapObj_CheckActivate_0_001B1A20 */
/* MapObj_CheckActivate_0_001B1A20 */
static inline s32 send(Msg *msg, s32 a2, s32 k, s32 id, s32 idx, V *q, f32 yaw, f32 b, f32 a, s32 fl) {
    if (D_00222A52[0].f.b4) return 0;
    msg->type = a2; msg->a = k; msg->b = id; msg->c = idx;
    msg->x = q->x; msg->y = q->y; msg->z = q->z; msg->w = q->w;
    msg->f = fl; msg->p = b; msg->h = yaw; msg->r = a;
    return Event_CheckTrigger_0_00179F80(msg);
}

s32 MapObj_CheckActivate_0_001B1A20(Obj_MapObj_CheckActivate_0_001B1A20 *o, s32 idx, s32 a2) {
    V p;
    V m[4];
    V q;
    Msg msg;
    s32 k;
    E80_MapObj_CheckActivate_0_001B1A20 *e;
    s8 *s;
    f32 t, yaw, a, b;
    s32 fl;
    s32 r;
    s32 id;
    E30_MapObj_CheckActivate_0_001B1A20 *c = &o->e30[idx];
    e = &o->e80[idx];
    k = c->v % 100;
    if (k != 0) {
    s = D_002022E4->unk518 + 0x180;
    sceVu0CopyVector(&p, s + 0x40);
    t = 3.1415927f + (*(H **)(s + 0x18))->x24;
    yaw = 180.0f * ((t - 6.2831855f * (s32)(0.15915494f * t)) + (t < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f) / 3.1415927f;
    sceVu0CopyMatrix(m, Mdl_GetFrameData_0_001715B0(e->x40) + 0x200);
    sceVu0SubVector(&q, &m[3], &p);
    { f32 d = sqrtf(sceVu0InnerProduct(&q, &q)); q.w = d; } a = 180.0f * atan2f(-q.x, -q.z) / 3.1415927f;
    b = 180.0f * atan2f(m[2].x, m[2].z) / 3.1415927f;
    fl = (D_00317238[0] & 0x2000) != 0;
    r = send(&msg, a2, k, o->id, idx, &q, yaw, b, a, fl);
    } else {
        r = 0;
    }
    return r;
}

/* MapObj_GetSection_0_001B1CB0 */
s32 MapObj_GetSection_0_001B1CB0(s32 arg0, void *arg1, s32 *arg2) {
    s32 temp_2;

    temp_2 = M2C_FIELD(arg1, s32 *, 0x34);
    if (temp_2 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg1, s32 *, 0x30) != arg0) {
        return 0;
    }
    if (arg2 != NULL) {
        *arg2 = M2C_FIELD(arg1, s32 *, 0x38);
    }
    return temp_2;
}

/* MapObj_FindCollider_0_001B1D00 */
E *MapObj_FindCollider_0_001B1D00(A0 *arg0, A1 *arg1) {
    L l;
    E *r = NULL;
    O *o;
    s32 t;
    s32 base;
    s32 idx;
    E *e;

    if (arg1->f24 == 0) {
        return NULL;
    }
    o = *arg0->f4;
    if (arg1->f20 != o) {
        return NULL;
    }
    base = *o->f10;
    Mdl_GetSectionPtrs_1_00171050(o, &l);
    idx = arg1->f3C;
    if (idx != -1) {
        e = (E *)((u8 *)(idx * sizeof(E)) + (s32)arg0->f134);
        t = base + l.tbl[e->f1A].v;
        if (t == arg1->f24) {
            r = e;
        }
    }
    return r;
}

/* MapObj_QueryColliders_0_001B1DF0 */
void MapObj_QueryColliders_0_001B1DF0(Obj_MapObj_QueryColliders_0_001B1DF0 *o, Tgt *t, s32 a2, u8 a3, s32 t0, s32 *out, s32 n, Ent *ents) {
    s32 j;
    s32 cnt;
    s32 got;
    Tgt buf;
    s32 i;
    E80_MapObj_QueryColliders_0_001B1DF0 *e;
    E30_MapObj_QueryColliders_0_001B1DF0 *c;
    E40 *d;
    Mdl **pp;
    X *x;

    cnt = 0;
    if (o->x1D8.f.b0) {
        Coll_QueryMapCells_0_001520E0(t, **o->x178, a2, a3, t0, &cnt, n, ents, o, 0);
        for (j = 0; j < n; j++) {
            ents[j].o = o;
        }
        t->o = o;
        if (t0 >= 0 && cnt != 0) {
            if (out) {
                *out = cnt;
            }
            return;
        }
        if (!D_00222A52[0].f.b4) {
            for (i = 0; i < o->n; i++) {
                e = &o->e80[i];
                c = &o->e30[i];
                d = &o->e40[c->x18];
                if (!(e->x50 & 3) && !e->x52.f.b4 && e->x52.f.b3) {
                    pp = e->x40;
                    x = **(X ***)*pp;
                    got = 0;
                    if (x->x1C) {
                        if (t->x24) {
                            Coll_QueryMapCells_0_001520E0(&buf, *pp, a2, a3, t0, &got, n - cnt, &ents[cnt], 0, d->x1E.f.b3);
                        } else {
                            Coll_QueryMapCells_0_001520E0(t, *pp, a2, a3, t0, &got, n - cnt, &ents[cnt], 0, d->x1E.f.b3);
                            if (t->x24) {
                                t->o = o;
                                t->e = e;
                                t->c = c;
                            }
                        }
                        for (j = 0; j < got; j++) {
                            (&ents[cnt])[j].o = o;
                            (&ents[cnt])[j].c = c;
                            (&ents[cnt])[j].e = e;
                        }
                        cnt += got;
                    }
                }
            }
        }
        if (out) {
            *out = cnt;
        }
    }
}
