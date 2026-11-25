#include "common.h"
typedef struct { s32 **x0; u16 x4; u16 x6; } HH;
typedef struct { u8 pad0[0x40]; HH **x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 x52; u8 pad53[0xD]; f32 x60; u8 pad64[0xC]; Vec x70; } E;
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[0x16]; } S;
typedef struct { u8 pad0[0x12]; Flags8 x12; u8 pad13[0xB]; Flags8 x1E; u8 pad1F[0x21]; } T;
typedef struct { u8 pad0[0x10]; s32 *x10; u16 x14; u16 x16; u16 x18; u16 pad1A; u16 x1C; } C;
typedef struct { s32 x0; s32 x4; s32 x8; u8 pad[0x44]; } Ent;
typedef struct { u8 pad0[0x20]; C *x20; u8 pad24[0xC]; void *x30; S *x34; E *x38; s32 x3C; } Out;
typedef struct {
    u8 pad0[0x6E];
    u16 x6E;
    u8 pad70[0xC8];
    S *x138;
    u8 pad13C[0x34];
    T *x170;
    u8 pad174[0xC];
    E *x180;
    u8 pad184[0x54];
    Flags8 x1D8;
} O;
extern Flags8 D_00222A52[];
f32 func_0015DF20(Vec *, Vec *);
s8 *func_001715B0(s32);
s32 func_0014E680(Out *, Ent *, s32, Vec *, s8 *, u8, u8);

s32 func_001B2B90(O *o, Out *out, Vec *p, u16 idx, u8 f1, u8 f2) {
    s8 *v;
    E *e;
    C *c;
    T *t;
    s32 i;
    s32 found;
    S *s;
    HH *h;
    Ent *tbl;
    Ent *ent;
    s32 a2;
    u32 k;
    f32 r;

    found = 0;
    if (D_00222A52[0].f.b4) return 0;
    if (!f1 || o == NULL) return 0;
    if (o->x1D8.f.b1 || !o->x1D8.f.b0) return 0;
    if (!(idx < o->x6E)) return 0;
    s = &o->x138[idx];
    e = &o->x180[idx];
    t = &o->x170[s->x18];
    if (!t->x12.f.b6) return 0;
    if ((e->x50 & 3) || e->x52.f.b4 || !e->x52.f.b3) return 0;
    r = e->x70.w + p->w;
    if (!(func_0015DF20(p, &e->x70) <= r * r)) return 0;
    if (e->x40 == NULL || (h = *e->x40) == NULL) return 0;
    if (h->x0 == NULL || (c = (C *)*h->x0) == NULL) return 0;
    tbl = (Ent *)((u32)c + 0x40 + c->x14 * 16 + c->x16 * 8 + c->x18 * 4);
    a2 = *c->x10;
    v = func_001715B0((s32)e->x40);
    if (v == NULL || c->x1C == 0) return 0;
    for (i = t->x1E.f.b3 != 0; i < h->x6; i++) {
        k = *(u8 *)(v + i * 0x140 + 0x332);
        if (k != 0xFF && k < c->x1C) {
            ent = &tbl[k];
            if (ent->x0 != 0 && ent->x8 != 0 &&
                func_0014E680(out, ent, a2, p, v + (i + 1) * 0x140 + 0xC0, f1, !(e->x60 > 1.0f)) != 0) {
                out->x20 = c;
                out->x3C = i;
                out->x30 = o;
                out->x38 = e;
                out->x34 = s;
                found = 1;
                if (f2) return found;
            }
        }
    }
    return found;
}
