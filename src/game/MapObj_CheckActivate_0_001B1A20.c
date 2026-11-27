#include "m2c.h"
#include "actor.h"
typedef struct { f32 x, y, z, w; } V;
typedef struct { s32 type; s32 a; s32 b; s32 c; f32 x, y, z, w; f32 h; f32 p; f32 r; s32 f; } Msg;
typedef struct { u8 pad[0x1A]; u16 v; u8 pad2[0x14]; } E30;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad2[0x3C]; } E80;
typedef struct { s32 id; u8 pad[0x6A]; u16 n; u8 pad2[0xC8]; E30 *e30; u8 pad3[0x44]; E80 *e80; } Obj;
typedef struct { u8 pad[0x24]; f32 x24; } H;
extern Actor *D_002022E4;
extern u16 D_00317238[];
extern Flags8 D_00222A52[];
void sceVu0CopyVector(V *, void *);
s8 *Mdl_GetFrameData_0_001715B0(s32);
void sceVu0CopyMatrix(V *, void *);
void sceVu0SubVector(V *, V *, V *);
f32 sceVu0InnerProduct(V *, V *);
f32 atan2f(f32, f32);
s32 Event_CheckTrigger_0_00179F80(Msg *);
f32 sqrtf(f32);
static inline s32 send(Msg *msg, s32 a2, s32 k, s32 id, s32 idx, V *q, f32 yaw, f32 b, f32 a, s32 fl) {
    if (D_00222A52[0].f.b4) return 0;
    msg->type = a2; msg->a = k; msg->b = id; msg->c = idx;
    msg->x = q->x; msg->y = q->y; msg->z = q->z; msg->w = q->w;
    msg->f = fl; msg->p = b; msg->h = yaw; msg->r = a;
    return Event_CheckTrigger_0_00179F80(msg);
}

s32 MapObj_CheckActivate_0_001B1A20(Obj *o, s32 idx, s32 a2) {
    V p;
    V m[4];
    V q;
    Msg msg;
    s32 k;
    E80 *e;
    s8 *s;
    f32 t, yaw, a, b;
    s32 fl;
    s32 r;
    s32 id;
    E30 *c = &o->e30[idx];
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
