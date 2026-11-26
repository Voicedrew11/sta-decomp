#include "common.h"
typedef struct { u8 pad[0x20]; u16 x20; } Part;
typedef struct { u8 pad[0x15C]; u16 x15C; u8 pad15E[2]; Flags8 x160; u8 pad161[0xF]; } Ent;
typedef struct { u8 pad[0x4B4]; Part *tbl[0x19]; void *x518; Ent *x51C; } A;

static inline s32 clamp(s32 v, s32 hi) {
    if (v < 0) v = 0;
    if (hi < v) v = hi;
    return v;
}
static inline void upd5(Ent *e, s32 l1, s32 l2) { e->x15C = clamp(e->x15C - l1, l2); }

void func_0013F0C0(A *a, u8 k) {
    Ent *e;
    s32 m;
    s32 v;
    s32 mx;
    s32 j;
    j = k;
    e = &a->x51C[k];
    e->x160.f.b0 = 0;
    e->x160.f.b2 = 0;
    m = a->tbl[k]->x20;
    upd5(&a->x51C[k], m, m);
    e = (Ent *)((u8 *)a->x51C + j * 0x170);
    mx = a->tbl[k]->x20;
    v = e->x15C + ((u32)(u16)m >> 1);
    if (v < 0) v = 0;
    if (mx < v) v = mx;
    e->x15C = v;
}

