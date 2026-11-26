#include "m2c.h"
typedef struct { f32 a, b; } P2;
typedef struct { u8 pad0[0xC]; P2 *xC; s32 x10; f32 x14; } A;
typedef struct { s32 x0; s32 x4; f32 x8; } B;
typedef struct { u8 pad0[0x40]; f32 x40; f32 x44; } Info;
f32 func_0011D850(f32);
void func_0017F840(s32, Info **);
extern s32 D_00202128;
extern s32 D_00202134;
extern s32 D_00202138;
extern s32 D_004A10D0[];
extern f32 D_004A10B0[];

void func_00191820(s32 i, A *a, B *b) {
    Info *info;
    f32 d;
    f32 h;
    f32 v;

    func_0017F840(0xD, &info);
    if (D_00202128 == 1) {
        if (i < D_004A10D0[0]) {
            d = a->xC[a->x10 - 1].a - D_004A10B0[i];
            h = 0.5f * d;
            if (!(func_0011D850(d) <= 0.01f)) {
                D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
            } else {
                a->x14 = D_004A10B0[i];
            }
        } else if (i > D_004A10D0[0]) {
            d = a->xC[0].a - D_004A10B0[i];
            h = 0.5f * d;
            if (!(func_0011D850(d) <= 0.01f)) {
                D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
            } else {
                a->x14 = D_004A10B0[i];
            }
        } else {
            info->x44 = 0.5f * (info->x40 - b->x8);
            if (!(func_0011D850(info->x40 - b->x8) <= 0.01f)) {
                b->x8 = b->x8 + info->x44;
            }
            D_004A10B0[i] = a->x14 = b->x8 - (f32)i;
        }
    } else if (D_00202128 == 2) {
        if (i == 0) {
            D_00202134 = 1;
        }
        if (i != D_004A10D0[0]) {
            if (D_004A10D0[0] - i + 2 >= 0) {
                d = (b->x8 - (f32)i) - D_004A10B0[i];
                h = 0.5f * d;
                if (!(func_0011D850(d) <= 0.01f)) {
                    D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
                    D_00202134 = 0;
                } else {
                    a->x14 = D_004A10B0[i];
                }
            }
        } else {
            a->x14 = D_004A10B0[i];
        }
        if (i == b->x4 - 1 && D_00202134) {
            D_00202128 = 0;
        }
    } else if (D_00202128 == 3) {
        v = a->xC[0].a;
        if (i == 0) {
            D_00202138 = 1;
        }
        if (D_004A10B0[i] < 1.99f && !(D_004A10B0[i] <= v + 0.01f)) {
            d = v - D_004A10B0[i];
            h = 0.5f * d;
            if (!(func_0011D850(d) <= 0.01f)) {
                D_004A10B0[i] = a->x14 = h + D_004A10B0[i];
                D_00202138 = 0;
            } else {
                a->x14 = D_004A10B0[i];
            }
        } else {
            a->x14 = D_004A10B0[i];
        }
        if (i == b->x4 - 1 && D_00202138) {
            D_00202128 = 0;
            b->x8 = v;
            info->x40 = v;
        }
    } else {
        a->x14 = b->x8 - (f32)i;
    }
}
