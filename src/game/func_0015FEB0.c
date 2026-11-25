#include "actor.h"
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
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u8 f18;
    u8 f19;
    u8 pad[6];
} Ent;
void func_0015ED80(Noise *p, u32 n, f32 *out, f32 x, f32 lo, f32 hi);
f32 func_0011DBF0(f32, f32);
void func_001D7D08(s32, s32, u32);
void func_001D7D58(s32, s32, u16);
extern Ent D_003172E0[];
extern Flags8 D_003174E0[];
static inline s32 en(void) {
    return !D_003174E0[0].f.b1 && D_003174E0[0].f.b0;
}

void func_0015FEB0(s32 on, f32 dt) {
    f32 r;
    f32 acc[2] = {0};
    Noise nz;
    s32 i;
    f32 v;

    D_003174E0[0].f.b0 = on != 0;
    nz.f4 = 1;
    nz.f5 = 1;
    nz.idx[0] = 0;
    nz.base = 0;
    for (i = 0; i < 16; i++) {
        if (D_003172E0[i].f19 != 0) {
            nz.w1 = 0.25f * D_003172E0[i].fC;
            nz.w2 = 0.25f * D_003172E0[i].fC;
            nz.amp = D_003172E0[i].f4;
            nz.base = D_003172E0[i].f8;
            nz.scale = D_003172E0[i].f0;
            nz.f1C = D_003172E0[i].f10;
            func_0015ED80(&nz, 1, &r, D_003172E0[i].f14, 0.0f, D_003172E0[i].fC);
            acc[D_003172E0[i].f18] += r;
            D_003172E0[i].f14 += dt;
            if (!(D_003172E0[i].f14 <= D_003172E0[i].fC)) {
                D_003172E0[i].f19 = 0;
            }
        }
    }
    if (acc[0] < 0.0f) {
        acc[0] = 0.0f;
    }
    if (acc[1] < 0.0f) {
        acc[1] = 0.0f;
    }
    if (!D_003174E0[0].f.b1 && D_003174E0[0].f.b0) {
        if (en()) {
            func_001D7D58(0, 0, (s32)acc[0]);
        } else {
            func_001D7D58(0, 0, 0);
        }
        v = (f32)(s32)acc[1] / 255.0f;
        if (D_003174E0[0].f.b1 || !D_003174E0[0].f.b0) {
            func_001D7D08(0, 0, 0);
        }
        func_001D7D08(0, 0, 255.0f * func_0011DBF0(v, 0.5f));
    }
}
