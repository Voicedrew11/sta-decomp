#include "common.h"
typedef struct { u8 b0:1; } B;
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; B fl; u8 pad[7]; } Ent;
typedef struct { Ent sp[4]; Ent ents[2][64]; } W;
typedef struct { u128 q[4]; } M;
extern W D_0030A2D0;
extern u16 D_0030C3D0[];
extern u16 D_0030C3D4[];
extern Vec D_0030A390[];
extern f32 D_0030A39C[];
extern Vec D_0030A3A0[];
extern f32 D_0030A3AC[];
extern Vec D_0030A3B0[];
extern f32 D_0030A3B4[];
extern f32 D_0030A3B8[];
extern f32 D_0030A3BC[];
extern f32 D_0030A3C0[];
extern f32 D_0030A3C4[];
extern B D_0030A3C8[];
extern Vec D_003139A0[];
extern M D_0030A310;
extern M D_0030A350;
s32 Light_Add_0_0015B980(s32 idx, Vec *a, Vec *b, Vec *c, f32 f0, f32 f1, f32 f2, f32 f3);
void Light_SetAmbient_0_0015BB40(Vec *a, Vec *b, f32 f);
void Light_Init_1_0015BCA0(void);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void memset(void *, s32, s32);

/* Light_Add_0_0015B980 */
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

/* Light_SetAmbient_0_0015BB40 */
void Light_SetAmbient_0_0015BB40(Vec *a, Vec *b, f32 f) {
    sceVu0CopyVector(D_0030A390, D_003139A0);
    D_0030A39C[0] = 30000.0f;
    if (b != NULL) {
        sceVu0ScaleVector(D_0030A3A0, b, 1.0f / 255.0f);
    } else {
        sceVu0CopyVector(D_0030A3A0, D_003139A0);
        D_0030A3A0[0].x = 0.0f;
    }
    D_0030A3AC[0] = 100.0f;
    if (a != NULL) {
        sceVu0CopyVector(D_0030A3B0, a);
    } else {
        D_0030A3B8[0] = 0.0f;
        D_0030A3B0[0].x = 1000.0f;
        D_0030A3B4[0] = 15000.0f;
        D_0030A3BC[0] = 1.0f;
    }
    if (f < 0.0f) {
        D_0030A3C0[0] = 1.0f;
    } else {
        D_0030A3C0[0] = f;
    }
    D_0030A3C4[0] = 0.1f;
    D_0030A3C8[0].b0 = 1;
}

/* Light_Init_1_0015BCA0 */
#define D_0030A2D0 D_0030A2D0__as_Light_Init_1_0015BCA0
extern s8 D_0030A2D0__as_Light_Init_1_0015BCA0[];

void Light_Init_1_0015BCA0(void) {
    memset(D_0030A2D0, 0, 0x2110);
    sceVu0CopyVector(D_0030A390, D_003139A0);
    D_0030A39C[0] = 30000.0f;
    sceVu0CopyVector(D_0030A3A0, D_003139A0);
    D_0030A3A0[0].x = 0.0f;
    D_0030A3AC[0] = 100.0f;
    D_0030A3B0[0].x = 1000.0f;
    D_0030A3B8[0] = 0.0f;
    D_0030A3B4[0] = 15000.0f;
    D_0030A3BC[0] = 1.0f;
    D_0030A3C0[0] = 1.0f;
    D_0030A3C4[0] = 0.1f;
    D_0030A3C8[0].b0 = 1;
    D_0030A350 = *(M *)D_0030A390;
    D_0030A310 = *(M *)D_0030A390;
}
#undef D_0030A2D0
