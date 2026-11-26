#include "actor.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef union { s32 w; Flags8 f; } FW;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
void func_0017F470(f32, s32, s32);
void func_0019A1D0(s32);
void func_00183DC0(s32 *);
s16 func_001CCD90(s32);
void func_001833E0(s32, s32);
void func_001CEDC0(s32);
void func_001DF460(void);
void func_0019A0D0(s32);
void func_00199AD0(s32 *);
void func_0019D510(void);
void func_0019A6A0(void);
extern Q2 D_001F3040;
extern s32 D_00201D48;
extern s32 **D_00201D4C;
extern s32 D_002021B4;
extern s32 D_002021AC;
extern s32 D_004A28C0[];
extern s32 D_004A28C4[];
extern s32 D_004A28C8[];
extern f32 D_004A28CC[];
extern FW D_004A28D0[];
static inline void setup(void) {
    Q2 q;
    Arg a;
    q = D_001F3040;
    a.fn = func_0019D510;
    a.f = -3.0f;
    a.cb = func_0019A6A0;
    a.a = 0;
    a.b = 0;
    a.p = (s32 *)D_00201D4C;
    a.n = D_002021B4;
    func_0017F890(D_00201D48, &q, &a);
    func_0017F7C0(D_00201D48, 1, 1);
    D_002021AC = 2;
    func_0017F470(D_004A28C0[0], D_00201D48, 1);
}

void func_001997A0(s32 *arg0) {
    s32 *p;
    s32 i;

    p = D_00201D4C[D_004A28C0[0]];
    if (D_004A28CC[0] > 0.0f) {
        D_004A28CC[0] -= 1.0f;
        D_004A28D0[0].f.f.b1 = 0;
    } else {
        switch (D_004A28C4[0]) {
        case 1:
            func_0017F7C0(D_00201D48, 0, 1);
            D_004A28C0[0] = 0;
            D_00201D48 = D_004A28C8[0];
            func_0019A1D0(D_00201D48);
            setup();
        }
        D_004A28C4[0] = 0;
        D_004A28C8[0] = 0;
        D_004A28D0[0].f.f.b1 = 1;
    }
    func_00183DC0(p);
    for (i = 0; i < 10; i++) {
        func_001833E0(func_001CCD90(i), i);
    }
    switch (*arg0) {
    case 0x19:
        D_004A28C0[0] = 0;
        D_004A28D0[0].w = 0;
        func_0019A1D0(D_00201D48);
        func_001CEDC0(3);
        for (i = 0; i < 10; i++) {
            func_001833E0(func_001CCD90(i), i);
        }
        setup();
        func_001DF460();
        D_004A28D0[0].f.f.b1 = 1;
        func_0019A0D0(0);
        break;
    case 0x16:
        if (D_004A28D0[0].f.f.b1) {
            func_00199AD0(arg0);
        }
        break;
    }
}
