#include "m2c.h"
extern s32 D_00316A20[];
extern f32 D_003139E0[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_003139B0[0xc];
extern s32 D_00201C94;
extern f32 D_00201C8C;
extern f32 D_00201C90;
extern f32 powf(f32, f32);

f32 Noise_Fbm_1_0015F040(f32 x, f32 p, f32 lac, f32 oct) {
    f32 freq;
    s32 i;
    f32 *w;
    f32 sum;
    s32 j;
    f32 *q;

    if (D_00201C94 != 0 || p != D_00201C8C) {
        D_00201C90 = 0.0f;
        freq = 1.0f;
        D_00201C8C = p;
        for (i = 0; i <= oct; i++) {
            D_003139B0[i] = powf(freq, -p);
            D_00201C90 += D_003139B0[i];
            freq *= lac;
        }
        D_00201C94 = 0;
        D_00201C90 = 1.0f / powf(D_00201C90, 0.83f);
    }
    sum = 0.0f;
    for (i = 0; i < oct; i++) {
        f32 wt = D_003139B0[i];
        f32 v = 4096.0f + x;
        s32 k = (s32)v;
        u8 a = k;
        f32 f = v - (f32)k;
        f32 g0 = f * D_003139E0[D_00316A20[a]];
        f32 d = (f - 1.0f) * D_003139E0[D_00316A20[(u8)(a + 1)]] - g0;
        f32 s = (3.0f - 2.0f * f) * (f * f);
        f32 r = g0 + s * d;
        sum += wt * r;
        x *= lac;
    }
    sum *= D_00201C90;
    return sum;
}
