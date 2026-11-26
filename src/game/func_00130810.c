#include "common.h"
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    Vec v;
    s32 x20; f32 x24; f32 x28; f32 x2C; s32 x30; s32 *x34; s32 x38; s16 x3C; s16 x3E;
    s32 x40; f32 x44; u8 p48[8]; Vec x50; f32 x60; f32 x64; f32 x68; u8 x6C; s8 x6D; s8 x6E; u8 p6F[0x11];
} Snd;
extern u8 D_0022EC14[];
extern Mtx D_002F16C0;
extern Vec D_001F2150;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
f32 atan2f(f32, f32);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 expf(f32);
f32 fabsf(f32);
void sceVu0Normalize(Vec *, Vec *);
f32 powf(f32, f32);
f32 sqrtf(f32);

void func_00130810(Snd *s) {
    Vec v;
    Vec a;
    Vec pos;
    Vec d;
    f32 dist;
    f32 pan;
    f32 vol;
    f32 ang;
    f32 diff;
    f32 f;
    f32 r;
    s32 cur;
    s32 n;

    if (s->x34 == 0 && s->x20 == 0) {
        sceVu0CopyVector(&pos, &s->v);
    } else if (s->x34 != 0) {
        sceVu0CopyVector(&pos, (Vec *)(*s->x34 + s->x38));
    } else if (s->x20 != 0) {
        sceVu0CopyVector(&pos, (Vec *)s->x20);
    }
    sceVu0ApplyMatrix(&v, &D_002F16C0, &pos);
    ang = atan2f(v.z, v.x);
    switch (D_0022EC14[0]) {
    case 0:
        pan = -256.0f;
        break;
    case 1:
        pan = 162.65636f * (ang - 3.1415927f);
        if (pan < -511.0f) pan += 1022.0f;
        if (!(pan <= 511.0f)) pan -= 1022.0f;
        pan = pan < 0.0f ? pan : -pan;
        cur = s->xC;
        diff = pan - cur;
        n = diff;
        n = n < 0 ? -n : n;
        if (n > 32) {
            pan = cur + 32.0f * diff / n;
        }
        break;
    case 2:
        pan = 162.65636f * (ang - 3.1415927f);
        cur = s->xC;
        if (cur > -1024 && cur < -767 && !(pan <= -256.0f)) {
            pan -= 1024.0f;
        } else if (cur > -1536 && cur < -1023) {
            if (!(pan <= -768.0f)) pan -= 1024.0f;
        } else if (cur < -1535) {
            if (pan <= -256.0f) pan -= 1024.0f;
        } else if (cur > -256) {
            if (pan < -768.0f) pan -= 1024.0f;
        }
        diff = pan - cur;
        n = diff;
        n = n < 0 ? -n : n;
        if (n > 32) {
            if (n > 1024) {
                pan = cur - 32.0f * diff / n;
                if (pan <= -2048.0f) pan += 2048.0f;
                if (!(pan <= 0.0f)) pan -= 2048.0f;
            } else {
                pan = cur + 32.0f * diff / n;
            }
        }
        break;
    default:
        pan = -256.0f;
        break;
    }
    cur = s->xC;
    diff = pan - cur;
    n = diff;
    n = n < 0 ? -n : n;
    if (n > 32) {
        if (n > 1024) {
            pan = cur - 32.0f * diff / n;
            if (pan <= -2048.0f) pan += 2048.0f;
            if (!(pan <= 0.0f)) pan -= 2048.0f;
        } else {
            pan = cur + 32.0f * diff / n;
        }
    }
    if (s->x6C == 0) {
        dist = sqrtf(sceVu0InnerProduct(&v, &v));
        if (dist > s->x24) {
            r = dist - s->x24;
            f = (s->x28 > 0.0f) ? expf(-4.8441868f / s->x28 * r) : 0.0f;
            s->x8 = s->xA * f;
        } else {
            s->x8 = s->xA;
        }
    } else {
        a.x = fabsf(v.x);
        a.y = fabsf(v.y);
        a.z = fabsf(v.z);
        if (a.x > s->x60 || a.y > s->x64 || a.z > s->x68) {
            d.x = (a.x > s->x60) ? a.x - s->x60 : 0.0f;
            d.y = (a.y > s->x64) ? a.y - s->x64 : 0.0f;
            d.z = (a.z > s->x68) ? a.z - s->x68 : 0.0f;
            d.w = 1.0f;
            f = sceVu0InnerProduct(&d, &d);
            r = s->x28 * s->x28;
            if (r > f) {
                f = (r - f) / r;
                f = f < 0.0f ? 0.0f : f;
                s->x8 = s->xA * f;
            } else {
                s->x8 = 0;
            }
        } else {
            s->x8 = s->xA;
        }
    }
    vol = 24.0f * (s->x2C - dist) / (34000.0f - 30.0f * (s->x2C - dist));
    if (fabsf(vol) < 0.00390625f) vol = 0.0f;
    vol += 1.0f;
    if (vol < 0.0f) vol = 0.0625f;
    if (!(vol <= 1.125f)) vol = 1.125f;
    f = vol * s->x3E;
    if (vol < 1.0f) f += 0.999f;
    s->x3C = f;
    s->x2C = dist;
    if (!(s->x44 <= 0.0f)) {
        sceVu0Normalize(&a, &s->x50);
        sceVu0ApplyMatrix(&a, &D_002F16C0, &a);
        f = sceVu0InnerProduct(&a, &D_001F2150);
        f = 1.0f - f;
        s->x8 = s->x8 * powf(0.5f * f, s->x44);
    }
    s->xC = pan;
}
