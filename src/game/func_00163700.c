#include "m2c.h"
typedef struct {
    u8 idx[4];
    u8 f4;
    u8 f5;
    u8 pad6[2];
    f32 w1;
    f32 w2;
    f32 base;
    f32 amp;
    f32 scale;
    f32 f1C;
} Noise;
typedef struct { f32 t; f32 v; } Key;
typedef struct { f32 x0; u16 x4; u8 x6; u8 x7; } Hdr;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { u8 x0; B8 f; u8 pad[2]; f32 x4; f32 x8; f32 xC; f32 x10; } Mod;
void func_0015ED80(Noise *p, u32 n, f32 *out, f32 x, f32 lo, f32 hi);
f32 fabsf(f32);
extern u32 D_00201E94;
static inline f32 u2f(u32 x) { return x; }
static inline void interp(f32 *out, Hdr *h, s32 *keys, f32 *pt, s32 loop, f32 len) {
    s32 n = h->x6;
    Key *lo = (Key *)&keys[h->x4];
    Key *hi = lo + n - 1;
    Key *prev;
    f32 t;
    if (loop) {
        while (len < *pt) {
            *pt -= len;
        }
    }
    t = *pt;
    if (n == 0) {
        *out = h->x0;
    } else {
        if (t < lo->t) {
            hi = lo;
        } else if (hi->t < t) {
            lo = hi;
        } else {
            do {
                prev = lo;
                lo++;
                if (t < lo->t) {
                    hi = lo;
                    lo = prev;
                    break;
                }
            } while (lo != hi);
        }
        if (lo->t == hi->t) {
            *out = lo->v;
        } else {
            f32 r = (t - lo->t) / (hi->t - lo->t);
            *out = lo->v + r * (hi->v - lo->v);
        }
    }
}

void func_00163700(f32 *out, Hdr *h, Mod *mods, s32 *keys, s32 loop, f32 t, f32 len) {
    f32 res;
    Noise p;
    Key *lo;
    Key *hi;
    Key *prev;
    s32 n;
    s32 idx;
    Mod *m;
    u8 b;

    interp(out, h, keys, &t, loop, len);
    idx = h->x7 & 0xF;
    if (idx != 0xF) {
        m = &mods[idx];
        b = m->x0;
        if (m->f.b1) {
            p.idx[0] = b;
            p.idx[1] = b + 1;
            p.idx[2] = b + 2;
            p.idx[3] = b + 3;
        } else {
            p.idx[0] = b;
            p.idx[1] = b;
            p.idx[2] = b;
            p.idx[3] = b;
        }
        p.f4 = m->f.b0;
        p.f5 = 0;
        p.w1 = 0.0f;
        p.w2 = 0.0f;
        p.scale = m->x4;
        p.amp = m->x8;
        p.f1C = m->xC;
        p.base = m->x10;
        if (m->f.b2) {
            func_0015ED80(&p, 1, &res, t + 0.033333335f * u2f(D_00201E94), 0.0f, 1000000.0f);
        } else {
            func_0015ED80(&p, 1, &res, t, 0.0f, 1000000.0f);
        }
        if (m->f.b4) {
            res = fabsf(res);
        }
        if (m->f.b5) {
            *out *= res;
        }
        if (m->f.b6) {
            *out += res;
        }
    }
}
