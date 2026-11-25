#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec a; f32 x10; f32 x14; f32 x18; u8 b1C; u8 b1D; u8 b1E; u8 b1F; u16 h20; u8 b22; u8 used; u8 pad[0xC]; } Ent;
typedef struct { u8 pad[0xB0]; Ent ents[2][32]; } W;
extern W D_0030C420;
extern u16 D_0030D0D4[];
void func_00102A60(Vec *, Vec *);

s32 func_0015C730(s32 idx, Vec *v, u8 c0, u8 c1, u8 c2, u8 c3, u16 h, u8 c4, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 i;
    s32 id;
    Ent *e;

    for (i = 0; i < 32; i++) {
        if (D_0030C420.ents[idx & 1][i].used == 0) {
            id = i + (idx & 1) * 32;
            goto found;
        }
    }
    id = -1;
found:
    if (id == -1) {
        return id;
    }
    e = &D_0030C420.ents[(u32)id >> 5][id & 31];
    func_00102A60(&e->a, v);
    e->a.w = f0;
    e->x10 = f2;
    e->x14 = f3;
    e->x18 = f1;
    e->used = 1;
    e->b1C = c0;
    e->b1D = c1;
    e->b1E = c2;
    e->b1F = c3;
    e->h20 = h;
    e->b22 = c4;
    D_0030D0D4[idx]++;
    return id;
}
