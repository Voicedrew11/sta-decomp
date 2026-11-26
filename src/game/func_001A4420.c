#include "m2c.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 p:5; u8 v:1; } BF5;
void func_0017F7C0(s32, s32, s32);
void func_0017F890(s32, Q2 *, Arg *);
void func_00130590(s32, s32, s32);
void func_001A4050(void);
extern Q2 D_001F3360;
extern s8 D_001FD890[];
extern s32 D_00201DA0;
extern s32 D_004A4394[];
extern s32 D_004A4398[];
extern s16 D_004A43A0[];
extern BF3 D_004A43AC[];

void func_001A4420(s32 *arg0) {
    Q2 q;
    Arg a;

    switch (*arg0) {
    case 25:
        D_004A4398[0] = 0;
        D_004A4394[0] = 0;
        if (((BF5 *)((s8 *)arg0 + 0x14))->v) {
            D_004A43A0[0] = 0;
        } else {
            D_004A43A0[0] = 0x7F;
        }
        D_004A43AC[0].v = 0;
        q = D_001F3360;
        a.p = (s32)&D_00201DA0; a.n = 2; a.fn = func_001A4050; a.f = -3.0f; a.a = 0; a.b = 0; a.cb = 0;
        func_0017F890(0, &q, &a);
        func_0017F7C0(0, 1, 1);
        func_00130590((s32)D_001FD890, 0, 1);
        break;
    case 27:
    case 0:
    case 22:
    case 26:
    case 28:
    case 30:
        break;
    }
}

