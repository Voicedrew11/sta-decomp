#include "actor.h"
typedef union { u128 q[2]; s32 w[8]; void *p[8]; f32 f[8]; } Q2;
typedef struct { void *p; s32 n; f32 f; void *fn; void *cb; s32 a; s32 b; } Arg;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
void func_0017F470(f32, s32, s32);
void func_001906D0(void);
void func_001905E0(void);
extern Q2 D_001F2D40;
extern s32 D_001F2D30[];
extern f32 D_001F2AC0[];
extern f32 D_001F2B20[];
extern s32 D_00201D08;

void func_00190490(void) {
    Q2 q;
    Arg a;

    q = D_001F2D40;
    a.p = D_001F2D30;
    a.n = 3;
    a.fn = func_001906D0;
    a.f = D_001F2AC0[0];
    a.cb = func_001905E0;
    a.a = 0;
    a.b = 0;
    func_0017F890(11, &q, &a);
    func_0017F470(0.0f, 11, 0);
    func_0017F7C0(11, 0, 0);
    q.w[2] = 8;
    q.f[5] = 1.0f;
    q.p[3] = D_001F2B20;
    q.w[4] = 4;
    a.p = &D_00201D08;
    a.n = 1;
    a.fn = 0;
    a.f = D_001F2B20[0];
    a.cb = 0;
    func_0017F890(12, &q, &a);
    func_0017F470(1.0f, 12, 0);
    func_0017F7C0(12, 0, 0);
}
