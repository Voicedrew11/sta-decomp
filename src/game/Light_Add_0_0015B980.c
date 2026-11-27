#include "common.h"
typedef struct { u8 b0:1; } B;
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; B fl; u8 pad[7]; } Ent;
typedef struct { Ent sp[4]; Ent ents[2][64]; } W;
extern W D_0030A2D0;
extern u16 D_0030C3D0[];
extern u16 D_0030C3D4[];
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
static inline Ent *getEnt(s32 id) {
    if (id < 0) {
        if (id == -1) {
            return &D_0030A2D0.sp[1];
        }
        return &D_0030A2D0.sp[3];
    }
    return &D_0030A2D0.ents[id / 64][id % 64];
}

s32 Light_Add_0_0015B980(s32 idx, Vec *a, Vec *b, Vec *c, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 i;
    s32 id;
    Ent *e;

    i = D_0030C3D0[idx];

    for (;;) {
        if (!D_0030A2D0.ents[idx][i].fl.b0) {
            D_0030C3D0[idx] = i + 1;
            id = i + idx * 64;
            break;
        }
        i++;
        if (i == 64) {
            i = 0;
        }
    }
    e = getEnt(id);
    sceVu0CopyVector(&e->a, a);
    sceVu0ScaleVector(&e->b, b, 1.0f / 255.0f);
    e->a.w = f0;
    e->b.w = f1;
    sceVu0CopyVector(&e->c, c);
    e->x30 = f2;
    e->x34 = f3;
    e->fl.b0 = 1;
    D_0030C3D4[idx]++;
    return id;
}
