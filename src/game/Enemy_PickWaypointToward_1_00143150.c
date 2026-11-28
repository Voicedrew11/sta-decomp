#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0x10]; u8 tbl[1][0x100]; } T;
typedef struct { u8 pad[0x10010]; Vec tbl[1]; } Obj;
typedef struct { u8 pad[0x10010]; Vec s[1]; } Big;
void Enemy_PickWaypointToward_1_00143150(void *a, f32 *b, f32 *c);
u8 Enemy_PickRandomWaypoint_1_001431A0(T *arg0);
void Enemy_PickWaypointDir_1_00143290(void *a, f32 *b, f32 *c, s32 d, s32 e);
u8 Enemy_FindWaypointDir_0_001432F0(Obj *o, Vec *pos, u8 a, u8 b);
u8 Enemy_IsWaypointReachable_0_001434F0(Big *b, Vec *p1, Vec *p2, u8 idx);
void Enemy_PickNearestWaypointToward_1_001435D0(void *a, f32 *b, f32 *c);
u8 Enemy_FindNearestWaypoint_1_00143610(Obj *o, Vec *pos);
void sceVu0SubVector(void *, void *, void *);
u32 Rand_Next_3_0015ED20(void);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sqrtf(float);

/* Enemy_PickWaypointToward_1_00143150 */
#define sceVu0SubVector sceVu0SubVector__as_Enemy_PickWaypointToward_1_00143150
void sceVu0SubVector__as_Enemy_PickWaypointToward_1_00143150(f32 *v0, f32 *v1, f32 *v2);
#define Enemy_PickRandomWaypoint_1_001431A0 Enemy_PickRandomWaypoint_1_001431A0__as_Enemy_PickWaypointToward_1_00143150
void Enemy_PickRandomWaypoint_1_001431A0__as_Enemy_PickWaypointToward_1_00143150(void *a, f32 *v);

void Enemy_PickWaypointToward_1_00143150(void *a, f32 *b, f32 *c)
{
    f32 v[4];
    sceVu0SubVector(v, c, b);
    Enemy_PickRandomWaypoint_1_001431A0(a, c);
}
#undef sceVu0SubVector
#undef Enemy_PickRandomWaypoint_1_001431A0

/* Enemy_PickRandomWaypoint_1_001431A0 */
#define Enemy_FindNearestWaypoint_1_00143610 Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickRandomWaypoint_1_001431A0
u8 Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickRandomWaypoint_1_001431A0(void);

u8 Enemy_PickRandomWaypoint_1_001431A0(T *arg0) {
    u8 buf[16];
    u8 r;
    u8 n;
    u8 i;
    u8 j;
    u8 c;


    r = Enemy_FindNearestWaypoint_1_00143610();
    if (r != 0xFF) {
        buf[0] = r;
        i = 0;

        n = 1;
        for (; i < 0xFF; i++) {
            c = arg0->tbl[r][i];
            if (c != 0xFF) {
                for (j = 0; j < n; j++) {
                    if (buf[j] == c) {
                        break;
                    }
                }
                if (j == n) {
                buf[n++] = c;
            }
            }
        }
        r = buf[(u8)(Rand_Next_3_0015ED20() % n)];
    }
    return r;
}
#undef Enemy_FindNearestWaypoint_1_00143610

/* Enemy_PickWaypointDir_1_00143290 */
#define sceVu0SubVector sceVu0SubVector__as_Enemy_PickWaypointDir_1_00143290
void sceVu0SubVector__as_Enemy_PickWaypointDir_1_00143290(f32 *v0, f32 *v1, f32 *v2);
#define Enemy_FindWaypointDir_0_001432F0 Enemy_FindWaypointDir_0_001432F0__as_Enemy_PickWaypointDir_1_00143290
void Enemy_FindWaypointDir_0_001432F0__as_Enemy_PickWaypointDir_1_00143290(void *a, f32 *v, s32 c, s32 d);

void Enemy_PickWaypointDir_1_00143290(void *a, f32 *b, f32 *c, s32 d, s32 e)
{
    f32 v[4];
    sceVu0SubVector(v, c, b);
    Enemy_FindWaypointDir_0_001432F0(a, v, d, e);
}
#undef sceVu0SubVector
#undef Enemy_FindWaypointDir_0_001432F0

/* Enemy_FindWaypointDir_0_001432F0 */
#define sceVu0SubVector sceVu0SubVector__as_Enemy_FindWaypointDir_0_001432F0
void sceVu0SubVector__as_Enemy_FindWaypointDir_0_001432F0(Vec *, Vec *, Vec *);
static inline Vec *get_Enemy_FindWaypointDir_0_001432F0(Obj *o, u8 i)
{ Vec *p = &o->tbl[i]; if (o->tbl[i].w <= 0.0f) p = 0; return p; }
static inline u8 inner(Obj *o, Vec *pos, u8 a, u8 b) {
    Vec d;
    Vec e;
    Vec f;
    f32 len;
    f32 w;
    u8 r;
    Vec *p;
    if (a == b) return 1;
    if (a != 0xFF && b != 0xFF) {
    sceVu0SubVector(&d, get_Enemy_FindWaypointDir_0_001432F0(o, b), get_Enemy_FindWaypointDir_0_001432F0(o, a));
    sceVu0SubVector(&e, pos, get_Enemy_FindWaypointDir_0_001432F0(o, a));
    len = sqrtf(sceVu0InnerProduct(&d, &d));
    sceVu0Normalize(&d, &d);
    {
        f32 t = sceVu0InnerProduct(&d, &e);
        if (!(t < 0.0f) && t <= len) return 1;
    }
    r = 0;
    if (a != 0xFF) {
        p = get_Enemy_FindWaypointDir_0_001432F0(o, a);
        w = p->w;
        sceVu0SubVector(&f, p, pos);
        if (sqrtf(sceVu0InnerProduct(&f, &f)) - w < 0.0f) r = 1;
    }
    return r;
    }
    return 1;
}

u8 Enemy_FindWaypointDir_0_001432F0(Obj *o, Vec *pos, u8 a, u8 b)
{ return inner(o, pos, a, b); }
#undef sceVu0SubVector

/* Enemy_IsWaypointReachable_0_001434F0 */
#define sceVu0SubVector sceVu0SubVector__as_Enemy_IsWaypointReachable_0_001434F0
void sceVu0SubVector__as_Enemy_IsWaypointReachable_0_001434F0(Vec *, Vec *, Vec *);

u8 Enemy_IsWaypointReachable_0_001434F0(Big *b, Vec *p1, Vec *p2, u8 idx) {
    Vec a;
    Vec d;
    Vec *s;
    f32 r;
    u8 hit;

    sceVu0SubVector(&a, p2, p1);
    hit = 0;
    if (idx != 0xFF) {
        s = &b->s[idx];
        if (b->s[idx].w <= 0.0f) {
            s = NULL;
        }
        r = s->w;
        sceVu0SubVector(&d, s, &a);
        if (sqrtf(sceVu0InnerProduct(&d, &d)) - r < 0.0f) {
            hit = 1;
        }
    }
    return hit;
}
#undef sceVu0SubVector

/* Enemy_PickNearestWaypointToward_1_001435D0 */
#define sceVu0SubVector sceVu0SubVector__as_Enemy_PickNearestWaypointToward_1_001435D0
void sceVu0SubVector__as_Enemy_PickNearestWaypointToward_1_001435D0(f32 *v0, f32 *v1, f32 *v2);
#define Enemy_FindNearestWaypoint_1_00143610 Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickNearestWaypointToward_1_001435D0
void Enemy_FindNearestWaypoint_1_00143610__as_Enemy_PickNearestWaypointToward_1_001435D0(void *a, f32 *v);

void Enemy_PickNearestWaypointToward_1_001435D0(void *a, f32 *b, f32 *c)
{
    f32 v[4];
    sceVu0SubVector(v, c, b);
    Enemy_FindNearestWaypoint_1_00143610(a, v);
}
#undef sceVu0SubVector
#undef Enemy_FindNearestWaypoint_1_00143610

/* Enemy_FindNearestWaypoint_1_00143610 */
#define sceVu0SubVector sceVu0SubVector__as_Enemy_FindNearestWaypoint_1_00143610
void sceVu0SubVector__as_Enemy_FindNearestWaypoint_1_00143610(Vec *, Vec *, Vec *);
static inline Vec *get_Enemy_FindNearestWaypoint_1_00143610(Obj *o, u8 i)
{ Vec *p = &o->tbl[i]; if (o->tbl[i].w <= 0.0f) p = 0; return p; }
static inline s32 ok(Obj *o, u8 i) { return o->tbl[i].w > 0.001f; }
static inline u8 next(Obj *o, u8 *it) {
    u8 r = 0xFF;
    u8 i = *it;
    while (i < 0xFF) {
        if (ok(o, i)) {
            r = i++;
            break;
        }
        i++;
    }
    *it = i;
    return r;
}

u8 Enemy_FindNearestWaypoint_1_00143610(Obj *o, Vec *pos) {
    Vec d;
    u8 best;
    u8 it;
    u8 i;
    f32 bd;
    f32 w;
    f32 dist;
    Vec *p;
    best = 0xFF;
    bd = -100000.0f;
    it = 0;
    i = next(o, &it);
    while (i != 0xFF) {
        p = get_Enemy_FindNearestWaypoint_1_00143610(o, i);
        w = p->w;
        sceVu0SubVector(&d, p, pos);
        dist = sqrtf(sceVu0InnerProduct(&d, &d)) - w;
        if (best == 0xFF || dist < bd) {
            best = i;
            bd = dist;
        }
        i = next(o, &it);
    }
    return best;
}
#undef sceVu0SubVector
