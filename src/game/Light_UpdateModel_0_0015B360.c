#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { u8 b0:1; } B;
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; B fl; u8 pad[7]; } Ent;
typedef struct { Ent sp[4]; Ent ents[2][64]; u16 x2100[2]; u16 cnt[2]; } W;
extern W D_0030A2D0;
extern Vec D_0030A290, D_0030A320, D_0030A330, D_0030A350, D_0030A360, D_0030A370, D_0030A390;
extern s8 D_003139A0[];
extern s32 D_00201F2C;
void sceVu0CopyVector(Vec *, void *);
void sceVu0CopyMatrix(Vec *, void *);
f32 Light_CalcIntensity_0_0015B720(void *, void *);
void sceVu0InterVector(f32, Vec *, Vec *, Vec *);

void Light_UpdateModel_0_0015B360(void *a0, s32 mask) {
    Vec *h;
    Vec *h2;
    s32 i;
    s32 j;
    f32 sum;
    f32 inv;
    Vec d;
    Vec c;

    h = (Vec *)((u8 *)&D_0030A2D0 + D_00201F2C * 32);
    h2 = h + 1;
    sceVu0CopyVector(&D_0030A360, D_003139A0);
    sceVu0CopyVector(&D_0030A370, D_003139A0);
    sceVu0CopyMatrix(&D_0030A290, a0);
    sum = Light_CalcIntensity_0_0015B720(&D_0030A350, &D_0030A390);
    for (i = 0; i < 2; i++) {
        if ((mask & (1 << i)) && D_0030A2D0.cnt[i]) {
            for (j = 0; j < 64; j++) {
                if (D_0030A2D0.ents[i][j].fl.b0) {
                    sum += Light_CalcIntensity_0_0015B720(&D_0030A350, &D_0030A2D0.ents[i][j]);
                }
            }
        }
    }
    inv = 1.0f / sum;
    d.x = D_0030A360.x * inv;
    d.y = D_0030A360.y * inv;
    d.z = D_0030A360.z * inv;
    d.w = 0.0f;
    c.x = D_0030A370.x * inv;
    c.y = D_0030A370.y * inv;
    c.z = D_0030A370.z * inv;
    c.w = D_0030A370.w * inv;
    sceVu0InterVector(0.85f, &D_0030A320, &D_0030A320, &d);
    sceVu0InterVector(0.85f, &D_0030A330, &D_0030A330, &c);
    if (h && &D_0030A330) {
        h->x = D_0030A330.x;
        h->y = D_0030A330.y;
        h->z = 0.5f * (0.999999f - D_0030A330.z);
        h->w = 0.5f * (1.0f - D_0030A330.w);
    }
    sceVu0CopyVector(h2, &D_0030A320);
    if (!(h2->x <= 1.0f)) h2->x = 1.0f;
    if (h2->x < 0.0f) h2->x = 0.0f;
    if (!(h2->y <= 1.0f)) h2->y = 1.0f;
    if (h2->y < 0.0f) h2->y = 0.0f;
    if (!(h2->z <= 1.0f)) h2->z = 1.0f;
    if (h2->z < 0.0f) h2->z = 0.0f;
}
