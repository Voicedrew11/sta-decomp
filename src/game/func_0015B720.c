#include "common.h"
extern Vec D_0030A290, D_001F2150, D_0030A360, D_0030A370;
void sceVu0CopyVector(void *, void *);
void sceVu0ApplyMatrix(Vec *, Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, void *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 func_0011DBF0(f32, f32);
float sqrtf(float);

f32 func_0015B720(void *a0, u8 *a1) {
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
    r *= func_0011DBF0(1.0f - s / *(f32 *)(a1 + 0xC), *(f32 *)(a1 + 0x34));
    sceVu0ScaleVector(&v40, a1 + 0x10, r);
    sceVu0AddVector(&D_0030A360, &v40, &D_0030A360);
    sceVu0ScaleVector(&v30, a1 + 0x20, r);
    sceVu0AddVector(&D_0030A370, &v30, &D_0030A370);
    return r;
}
