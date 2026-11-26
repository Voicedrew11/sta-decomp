#include "actor.h"
typedef union { u128 q[2]; s32 w[8]; void *p[8]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
void func_0017F470(f32, s32, s32);
void func_00190680(void);
void func_001907D0(void);
extern Q2 D_001F2D60;
extern f32 D_001F2AC0[];
extern f32 D_001F2B00[];
extern s32 D_00201D10;
extern s32 D_00201D18;

void func_00190340(void) {
    Q2 q;
    Arg a;

    q = D_001F2D60;
    a.p = &D_00201D10;
    a.n = 2;
    a.fn = func_00190680;
    a.f = D_001F2AC0[0];
    a.a = 0;
    a.b = 0;
    a.cb = 0;
    func_0017F890(11, &q, &a);
    func_0017F470(0.0f, 11, 0);
    func_0017F7C0(11, 0, 0);
    q.w[5] = 0;
    q.p[7] = func_001907D0;
    q.w[2] = 8;
    q.p[3] = D_001F2B00;
    q.w[4] = 4;
    a.p = &D_00201D18;
    a.n = 1;
    a.fn = 0;
    a.f = D_001F2B00[0];
    a.a = 0;
    func_0017F890(12, &q, &a);
    func_0017F470(1.0f, 12, 0);
    func_0017F7C0(12, 0, 0);
}
