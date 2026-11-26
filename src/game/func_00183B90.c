#include "common.h"
typedef struct {
    s32 x0;
    s32 x4;
    Flags8 f8;
} Res;
extern Res *D_002020AC;
extern s32 D_002020A8;
extern s32 D_0048D0E4[];
extern f32 D_0048D0F0[];
extern f32 D_0048D0F4[];
extern f32 D_0048D0F8[];
extern f32 D_0048D0FC[];
extern f32 D_0048D100[];
extern f32 D_0048D104[];
extern f32 D_0048D108[];
extern f32 D_0048D10C[];
extern s32 D_00201CE0;
extern s32 D_00201CE4;
extern s32 D_00201CDC;
extern s32 D_00201CE8;
extern s8 D_001FCA30[];
extern s8 D_001FCA48[];
void func_00177570(s32);
void func_001256E0(void *, void *, s32);
Res *func_001E1570(void *, s32);
s32 func_00177F80(void *);
s32 func_00177AF0(s32, s32);

void func_00183B90(s32 id) {


    s32 r;
    if (id == -1 || id == 0) {
        if (D_002020AC && D_002020AC->f8.f.b2 && D_0048D0E4[0]) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = 0;
            D_00201CE0 = -1;
        }
        return;
    }
    if (D_00201CE0 != id) {
        if (D_002020AC && D_002020AC->f8.f.b1) return;
        if (D_002020AC && D_002020AC->f8.f.b2 && D_0048D0E4[0]) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = 0;
        }
        D_00201CE0 = id;
        D_00201CE4 = -1;
        D_00201CDC = -1;
        D_00201CE8 = -1;
        {
        s8 buf[0x100] = {0};
        func_001256E0(buf, D_001FCA30, D_00201CE0);
        D_002020AC = func_001E1570(buf, 10);
        D_0048D0F0[0] = 0.0f;
        D_0048D0F4[0] = 0.0f;
        D_002020A8 = 0;
        D_0048D0F8[0] = 128.0f;
        D_0048D0FC[0] = 128.0f;
        D_0048D100[0] = 0.0f;
        D_0048D104[0] = 0.0f;
        D_0048D108[0] = 128.0f;
        D_0048D10C[0] = 128.0f;
        }
    }
    if (D_002020AC && !D_002020AC->f8.f.b1 && !D_002020AC->f8.f.b2 && D_002020AC->f8.f.b0) {
        s8 name[16];
        func_001256E0(name, D_001FCA48, D_00201CE0);
        r = D_002020AC->x0;
        if (r) {
            D_0048D0E4[0] = func_00177AF0(func_00177F80(name), r);
            D_002020AC->f8.f.b2 = 1;
        }
    }
}
