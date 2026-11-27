#include "m2c.h"
typedef struct { f32 a; f32 b; } P2;
typedef struct { u8 p0 : 1; u8 b1 : 1; u8 st : 4; } BF;
typedef struct { u8 pad[0x48]; BF fl; u8 pad2[3]; } E;
extern s32 D_00486990[];
extern P2 *D_0048699C[];
extern s32 D_004869A0[];
extern s32 D_004869B4[];
extern f32 D_004869B8[];
extern f32 D_004869D0[];
extern f32 D_004869D4[];
f32 fabsf(f32);

void UiAnim_Step_0_00180810(s32 i) {
    f32 *cur;
    f32 *dst;
    f32 d;
    f32 st;
    BF *fl;
    s32 k = i * 19;

    cur = &D_004869B8[k];
    dst = &D_004869D0[k];
    d = fabsf(*dst - *cur);
    D_004869D4[k] = 0.25f * (*dst - *cur);
    fl = (BF *)((u8 *)&D_00486990[k] + 0x48);
    switch (fl->st) {
    case 0:
        if (!(d <= D_004869A0[k] / 2.0f) && !fl->b1) {
            if (D_004869D4[k] < 0.0f) {
                *dst = (f32)D_004869B4[k] + D_0048699C[k][D_004869A0[k] - 1].a - 1.0f;
            } else {
                D_004869D0[k] = D_004869D0[k] = D_0048699C[k][0].a;
            }
            fl->st = 1;
        } else if (!(d <= 0.01f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else if (!(d <= 0.0f)) {
                *cur += st;
            }
        } else {
            fl->b1 = 0;
        }
        break;
    case 1:
        if (!(d <= 0.01f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else if (!(d <= 0.0f)) {
                *cur += st;
            }
        } else {
            if (!(*cur <= 0.0f)) {
                *cur = D_0048699C[k][0].a;
                *dst = 0.0f;
            } else { s32 *z = &D_004869B4[k];
                *cur = (f32)*z + D_0048699C[k][D_004869A0[k] - 1].a - 1.0f;
                *dst = (f32)*z - 1.0f;
            }
            fl->st = 2;
        }
        break;
    case 2:
        if (!(d <= 1.0f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else {
                *cur += st;
            }
        } else {
            fl->st = 0;
            fl->b1 = 0;
        }
        break;
    case 3:
        if (!(d <= 1.0f)) {
            st = D_004869D4[k];
            if (d <= st) {
                *cur = *dst;
            } else if (!(d <= 0.0f)) {
                *cur += st;
            }
        } else {
            fl->st = 0;
            fl->b1 = 0;
        }
        break;
    }
}
