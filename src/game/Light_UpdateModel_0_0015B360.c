#include "m2c.h"
#include "common.h"
typedef struct { u8 b0:1; } B;
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; B fl; u8 pad[7]; } Ent;
typedef struct { Ent sp[4]; Ent ents[2][64]; u16 x2100[2]; u16 cnt[2]; } W;
extern W D_0030A2D0;
extern Vec D_0030A290;
extern Vec D_0030A320;
extern Vec D_0030A330;
extern Vec D_0030A350;
extern Vec D_0030A360;
extern Vec D_0030A370;
extern Vec D_0030A390;
extern s8 D_003139A0[];
extern s32 D_00201F2C;
extern Vec D_001F2150;
void Light_UpdateModel_0_0015B360(void *a0, s32 mask);
void Light_CopyColor_0_0015B6B0(void *arg0, void *arg1);
f32 Light_CalcIntensity_0_0015B720(void *a0, u8 *a1);
void sceVu0CopyVector(void *, void*);
void sceVu0CopyMatrix(Vec *, void *);
void sceVu0InterVector(f32, Vec *, Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, void *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 powf(f32, f32);
f32 sqrtf(float);

/* Light_UpdateModel_0_0015B360 */
#define sceVu0CopyVector sceVu0CopyVector__as_Light_UpdateModel_0_0015B360
void sceVu0CopyVector__as_Light_UpdateModel_0_0015B360(Vec *, void *);
#define Light_CalcIntensity_0_0015B720 Light_CalcIntensity_0_0015B720__as_Light_UpdateModel_0_0015B360
f32 Light_CalcIntensity_0_0015B720__as_Light_UpdateModel_0_0015B360(void *, void *);

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
#undef sceVu0CopyVector
#undef Light_CalcIntensity_0_0015B720

/* Light_CopyColor_0_0015B6B0 */
void Light_CopyColor_0_0015B6B0(void *arg0, void *arg1) {
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return;
    }
    M2C_FIELD(arg0, f32 *, 0) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 8) = (f32) (0.5f * (0.999999f - M2C_FIELD(arg1, f32 *, 8)));
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) (0.5f * (1.0f - M2C_FIELD(arg1, f32 *, 0xC)));
}

/* Light_CalcIntensity_0_0015B720 */
f32 Light_CalcIntensity_0_0015B720(void *a0, u8 *a1) {
    Vec v60;
    Vec v50;
    Vec v40;
    Vec v30;
    f32 r = 0.01f * *(f32 *)(a1 + 0x30);
    f32 k = *(f32 *)(a1 + 0x1C);
    f32 d;
    f32 s;
    sceVu0CopyVector(&v60, a1);
    v60.w = 1.0f;
    sceVu0ApplyMatrix(&v60, &D_0030A290, &v60);
    sceVu0Normalize(&v50, &v60);
    d = sceVu0InnerProduct(&v50, &D_001F2150);
    d += k;
    if (d < 0.0f) {
        return 0.0f;
    }
    r *= d / (1.0f + k);
    s = sqrtf(sceVu0InnerProduct(&v60, &v60));
    if (*(f32 *)(a1 + 0xC) < s) {
        return 0.0f;
    }
    r *= powf(1.0f - s / *(f32 *)(a1 + 0xC), *(f32 *)(a1 + 0x34));
    sceVu0ScaleVector(&v40, a1 + 0x10, r);
    sceVu0AddVector(&D_0030A360, &v40, &D_0030A360);
    sceVu0ScaleVector(&v30, a1 + 0x20, r);
    sceVu0AddVector(&D_0030A370, &v30, &D_0030A370);
    return r;
}
