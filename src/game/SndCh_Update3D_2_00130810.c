#include "common.h"
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    Vec v;
    s32 x20; f32 x24; f32 x28; f32 x2C; s32 x30; s32 *x34; s32 x38; s16 x3C; s16 x3E;
    s32 x40; f32 x44; u8 p48[8]; Vec x50; f32 x60; f32 x64; f32 x68; u8 x6C; s8 x6D; s8 x6E; u8 p6F[0x11];
} Snd_SndCh_Update3D_2_00130810;
typedef struct { s8 b0; char rest[0x7F]; } E_SndCh_IsPlaying_1_00131060;
typedef struct { s8 on; s8 idx; s8 x2; s8 x3; s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF; u8 p10[0x40]; Vec v; u8 p60[0x20]; } Snd_SndCh_SetVolume_2_001310B0;
typedef struct { u8 p[0x3C]; s16 x3C; u8 q[0x42]; } Snd_SndCh_SetPitch_1_00131130;
typedef struct { char p[0x24]; f32 x24; f32 x28; char q[0x54]; } S_SndCh_GetPosition_1_00131180;
typedef struct { s8 on; s8 idx; s8 x2; s8 x3; s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF; u8 p10[0x40]; Vec v; u8 p60[0x20]; } Snd_SndCh_SetPosition_2_001311E0;
typedef struct { char p[0x44]; f32 x44; char q[0x38]; } S_SndCh_SetRange_0_00131250;
typedef struct { u8 p[0x40]; f32 x40; u8 r[0x3C]; } Snd_SndCh_SetFalloff_0_001312C0;
typedef struct { s8 b0; s8 b1; char p2[0xE]; Vec v; char p20[0x14]; s32 x34; s32 x38; char rest[0x44]; } E_SndCh_SetPositionStatic_1_00131330;
extern u8 D_0022EC14[];
extern Mtx D_002F16C0;
extern Vec D_001F2150;
extern E_SndCh_IsPlaying_1_00131060 D_0022CBC0[];
void SndCh_Update3D_2_00130810(Snd_SndCh_Update3D_2_00130810 *s);
s8 SndCh_IsPlaying_1_00131060(s32 i);
s32 SndCh_SetVolume_2_001310B0(s32 a, s16 v);
s32 SndCh_SetPitch_1_00131130(s32 i, s16 v);
s32 SndCh_GetPosition_1_00131180(s32 arg0, f32 *arg1);
s32 SndCh_SetPosition_2_001311E0(s32 a, Vec *b);
s32 SndCh_SetRange_0_00131250(s32 arg0, f32 f);
s32 SndCh_SetFalloff_0_001312C0(s32 i, f32 v);
s32 SndCh_SetPositionStatic_1_00131330(s32 arg0, Vec *v);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0ApplyMatrix(Vec *, Mtx *, Vec *);
f32 atan2f(f32, f32);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 expf(f32);
f32 fabsf(f32);
void sceVu0Normalize(Vec *, Vec *);
f32 powf(f32, f32);
f32 sqrtf(f32);

/* SndCh_Update3D_2_00130810 */
void SndCh_Update3D_2_00130810(Snd_SndCh_Update3D_2_00130810 *s) {
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

/* SndCh_IsPlaying_1_00131060 */
static inline E_SndCh_IsPlaying_1_00131060 *get_SndCh_IsPlaying_1_00131060(s32 i) { if (0 <= i && i < 63) return &D_0022CBC0[i]; return 0; }
s8 SndCh_IsPlaying_1_00131060(s32 i)
{
    E_SndCh_IsPlaying_1_00131060 *e = get_SndCh_IsPlaying_1_00131060(i);
    if (e) return e->b0;
    return 0;
}

/* SndCh_SetVolume_2_001310B0 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_SetVolume_2_001310B0
extern Snd_SndCh_SetVolume_2_001310B0 D_0022CBC0__as_SndCh_SetVolume_2_001310B0[];
static inline Snd_SndCh_SetVolume_2_001310B0 *get_SndCh_SetVolume_2_001310B0(s32 i) { if (!(0 > i) && i < 0x3F) return &D_0022CBC0[i]; return 0; }
s32 SndCh_SetVolume_2_001310B0(s32 a, s16 v) {
    Snd_SndCh_SetVolume_2_001310B0 *s = get_SndCh_SetVolume_2_001310B0(a);
    if (s == 0) return -1;
    if (v < 0) v = 0;
    if (v > 0x7F) v = 0x7F;
    s->x8 = v;
    return 0;
}
#undef D_0022CBC0

/* SndCh_SetPitch_1_00131130 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_SetPitch_1_00131130
extern Snd_SndCh_SetPitch_1_00131130 D_0022CBC0__as_SndCh_SetPitch_1_00131130[];
static inline Snd_SndCh_SetPitch_1_00131130 *get_SndCh_SetPitch_1_00131130(s32 i) {
    if (0 <= i && i < 0x3F) return &D_0022CBC0[i];
    return 0;
}
s32 SndCh_SetPitch_1_00131130(s32 i, s16 v) {
    Snd_SndCh_SetPitch_1_00131130 *s = get_SndCh_SetPitch_1_00131130(i);
    if (s == 0) return -1;
    s->x3C = v;
    return 0;
}
#undef D_0022CBC0

/* SndCh_GetPosition_1_00131180 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_GetPosition_1_00131180
extern S_SndCh_GetPosition_1_00131180 D_0022CBC0__as_SndCh_GetPosition_1_00131180[];

s32 SndCh_GetPosition_1_00131180(s32 arg0, f32 *arg1) {
    S_SndCh_GetPosition_1_00131180 *s;
    if (!(0 > arg0) && arg0 < 0x3F) {
        s = &D_0022CBC0[arg0];
    } else {
        s = 0;
    }
    if (s == 0) {
        return -1;
    }
    s->x24 = arg1[0];
    s->x28 = arg1[1];
    return 0;
}
#undef D_0022CBC0

/* SndCh_SetPosition_2_001311E0 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_SetPosition_2_001311E0
extern Snd_SndCh_SetPosition_2_001311E0 D_0022CBC0__as_SndCh_SetPosition_2_001311E0[];
static inline Snd_SndCh_SetPosition_2_001311E0 *get_SndCh_SetPosition_2_001311E0(s32 i) { if (!(0 > i) && i < 0x3F) return &D_0022CBC0[i]; return 0; }
s32 SndCh_SetPosition_2_001311E0(s32 a, Vec *b) {
    Snd_SndCh_SetPosition_2_001311E0 *s = get_SndCh_SetPosition_2_001311E0(a);
    if (s == 0) return -1;
    sceVu0CopyVector(&s->v, b);
    return 0;
}
#undef D_0022CBC0

/* SndCh_SetRange_0_00131250 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_SetRange_0_00131250
extern S_SndCh_SetRange_0_00131250 D_0022CBC0__as_SndCh_SetRange_0_00131250[];

s32 SndCh_SetRange_0_00131250(s32 arg0, f32 f) {
    S_SndCh_SetRange_0_00131250 *s;
    if (!(0 > arg0) && arg0 < 0x3F) {
        s = &D_0022CBC0[arg0];
    } else {
        s = 0;
    }
    if (s == 0) {
        return -1;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    s->x44 = f;
    return 0;
}
#undef D_0022CBC0

/* SndCh_SetFalloff_0_001312C0 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_SetFalloff_0_001312C0
extern Snd_SndCh_SetFalloff_0_001312C0 D_0022CBC0__as_SndCh_SetFalloff_0_001312C0[];
static inline Snd_SndCh_SetFalloff_0_001312C0 *get_SndCh_SetFalloff_0_001312C0(s32 i) {
    if (0 <= i && i < 0x3F) {
        return &D_0022CBC0[i];
    }
    return NULL;
}
s32 SndCh_SetFalloff_0_001312C0(s32 i, f32 v) {
    Snd_SndCh_SetFalloff_0_001312C0 *s = get_SndCh_SetFalloff_0_001312C0(i);
    if (s == NULL) return -1;
    if (v < 0.0f) v = 0.0f;
    s->x40 = v;
    return 0;
}
#undef D_0022CBC0

/* SndCh_SetPositionStatic_1_00131330 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_SetPositionStatic_1_00131330
extern E_SndCh_SetPositionStatic_1_00131330 D_0022CBC0__as_SndCh_SetPositionStatic_1_00131330[];
static inline E_SndCh_SetPositionStatic_1_00131330 *get_SndCh_SetPositionStatic_1_00131330(s32 i) {
    E_SndCh_SetPositionStatic_1_00131330 *p;
if (0 <= i && i < 0x3F) p = &D_0022CBC0[i]; else p = NULL;
    return p;
}
s32 SndCh_SetPositionStatic_1_00131330(s32 arg0, Vec *v) {
    E_SndCh_SetPositionStatic_1_00131330 *p = get_SndCh_SetPositionStatic_1_00131330(arg0);
    if (p == NULL) return -1;
    p->x34 = 0;
    p->x38 = 0;
    sceVu0CopyVector(&p->v, v);
    return 0;
}
#undef D_0022CBC0
