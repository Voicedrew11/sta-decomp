#include "common.h"

typedef struct { u8 pad[0xC]; u32 n; s32 off[1]; } Tbl;
typedef struct { u32 n; s32 off[1]; } Ent;
typedef struct { u8 pad[5]; u8 lo; u8 hi; } Rec;
typedef struct { u8 pad[8]; u16 k; u8 pad2[0x32 - 10]; } Elm;
typedef struct { s32 x0; u16 x4; } Snd;
typedef struct { u8 pad[0x20]; s32 off2; } Sub;
typedef struct { u8 pad[0x10]; Sub h; s32 off1; } Hdr;

static inline s32 isz(s32 x) { return !(x != 0); }

s32 Bgm_FindTrack_0_001D9470(Hdr *a, s32 base, s32 end, u32 i, u32 j, u32 k, s32 *out)
{
    Sub *h;
    Tbl *t;
    Ent *e;
    Rec *r;
    u16 *kp;
    Tbl *t2;
    Snd *s;


    if (isz((s32)a & base))
        return 0;
    t = (Tbl *)((u8 *)a + a->off1);
    h = &a->h;
    if (t->n < i)
        return 0;
    e = (Ent *)((u8 *)t + t->off[i]);
    if (e->n < j)
        return 0;
    r = (Rec *)((u8 *)t + e->off[j]);
    if (r->lo > k || k > r->hi)
        return 0;
    kp = &((Elm *)r + (k - r->lo))->k;
    t2 = (Tbl *)((u8 *)a + h->off2);
    if (t2->n < *kp)
        return 0;
    s = (Snd *)((u8 *)t2 + t2->off[*kp]);
    out[0] = base + s->x0;
    out[1] = s->x4;
    if (t2->n >= *kp + 1)
        out[2] = *(s32 *)((u8 *)t2 + t2->off[*kp + 1]) - s->x0;
    else
        out[2] = end - s->x0;
    return 1;
}
