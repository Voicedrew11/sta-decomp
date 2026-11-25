#include "m2c.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { u8 b0 : 1; } F;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
void func_0017F470(f32, s32, s32);
void func_00183DC0(s32);
void func_0019D580(s32 *);
void func_0019DA70(s32 *);
void func_0019DCF0(void);
void func_0019D510(void);
void func_0019DE90(void);
extern Q2 D_001F30C0;
extern s32 *D_00201D68;
extern s32 D_002021E8;
extern s32 D_002021F4;
extern s32 D_002021F8;
extern s32 D_004A3290[];
extern s32 D_004A3294[];
extern f32 D_004A3298[];
extern F D_004A329C[];

void func_0019D290(s32 *arg0) {
    Q2 q;
    Arg a;

    if (*arg0 == 0x19) {
        D_004A3290[0] = 0;
        func_0019DCF0();
        q = D_001F30C0;
        a.fn = func_0019D510;
        a.f = -3.0f;
        a.cb = func_0019DE90;
        a.a = 0;
        a.b = 0;
        a.p = (s32)D_00201D68;
        a.n = D_002021F8;
        func_0017F890(1, &q, &a);
        func_0017F7C0(1, 1, 1);
        D_002021F4 = 2;
        func_0017F470(D_004A3290[0], 1, 1);
    }
    func_00183DC0(D_00201D68[D_004A3290[0]]);
    if (D_004A329C[0].b0) {
        switch (D_002021E8) {
        case 0:
            func_0019DA70(arg0);
            break;
        case 1:
            func_0019D580(arg0);
            break;
        }
    }
    if (!D_004A329C[0].b0) {
        D_004A3298[0] -= 1.0f;
        if (D_004A3298[0] < 0.0f) {
            D_004A329C[0].b0 = 1;
            switch (D_004A3294[0]) {
            case 1:
                D_002021E8 = 0;
                D_004A3298[0] = 15.0f;
                D_004A329C[0].b0 = 0;
                break;
            case 2:
                D_002021E8 = 1;
                break;
            }
            D_004A3294[0] = -1;
            return;
        }
        D_004A329C[0].b0 = 0;
        return;
    }
}
