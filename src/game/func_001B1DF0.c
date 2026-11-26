#include "m2c.h"
#include "actor.h"
typedef struct { u8 pad[0x1C]; u16 x1C; } X;
typedef struct { X *x; } Y;
typedef struct { Y *y; } Mdl;
typedef struct { u8 pad[0x18]; u16 x18; u8 pad1A[0x16]; } E30;
typedef struct { u8 pad[0x40]; Mdl **x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 x52; u8 pad53[0x2D]; } E80;
typedef struct { u8 pad[0x1E]; Flags8 x1E; u8 pad1F[0x21]; } E40;
typedef struct {
    u8 pad[0x6E]; u16 n; u8 pad70[0xC8]; E30 *e30; u8 pad13C[0x34]; E40 *e40; u8 pad174[4]; Mdl ***x178; u8 pad17C[4]; E80 *e80;
    u8 pad184[0x54]; Flags8 x1D8;
} Obj;
typedef struct { u8 pad[0x30]; Obj *o; E30 *c; E80 *e; u8 pad3C[4]; } Ent;
typedef struct { u8 pad[0x24]; s32 x24; u8 pad28[8]; Obj *o; E30 *c; E80 *e; u8 pad3C[0xC]; } Tgt;
extern Flags8 D_00222A52[];
void func_001520E0(Tgt *, Mdl *, s32, u8, s32, s32 *, s32, Ent *, Obj *, s32);

void func_001B1DF0(Obj *o, Tgt *t, s32 a2, u8 a3, s32 t0, s32 *out, s32 n, Ent *ents) {
    s32 j;
    s32 cnt;
    s32 got;
    Tgt buf;
    s32 i;
    E80 *e;
    E30 *c;
    E40 *d;
    Mdl **pp;
    X *x;

    cnt = 0;
    if (o->x1D8.f.b0) {
        func_001520E0(t, **o->x178, a2, a3, t0, &cnt, n, ents, o, 0);
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
                            func_001520E0(&buf, *pp, a2, a3, t0, &got, n - cnt, &ents[cnt], 0, d->x1E.f.b3);
                        } else {
                            func_001520E0(t, *pp, a2, a3, t0, &got, n - cnt, &ents[cnt], 0, d->x1E.f.b3);
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
