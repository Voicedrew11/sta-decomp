#include "m2c.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; u32 n; } P;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
void func_0017F470(f32, s32, s32);
void func_001803D0(u32, s32);
P *func_001958E0(void);
s32 func_001AA440(u32);
void func_00198F30(void);
void func_00199110(void);
extern Q2 D_001F2FC0;
extern u32 D_002021A4;
extern s32 D_002021A8;
extern u32 D_002022B8;
extern s32 D_004A1450[];
extern s32 D_004A18B0[];

void func_00198D80(void) {
    Q2 q;
    Arg a;
    P *p;
    u32 i;
    u32 j;
    s32 cnt;
    s32 found;

    func_001803D0(D_002022B8 / 10, -2);
    p = func_001958E0();
    if (p != 0) {
        cnt = 0;
        for (i = 1; i < p->n + 1; i++) {
            found = 0;
            for (j = 0; j < 10; j++) {
                if (func_001AA440(j + i * 10)) {
                    found = 1;
                }
            }
            if (found) {
                cnt++;
            }
        }
        D_002021A4 = (u32)(cnt * 100) / p->n;
        q = D_001F2FC0;
        a.p = (s32)D_004A1450;
        a.fn = func_00198F30;
        a.f = -3.0f;
        a.cb = func_00199110;
        a.a = 0;
        a.b = 0;
        a.n = D_002021A8;
        func_0017F890(0, &q, &a);
        func_0017F7C0(0, 1, 1);
        func_0017F470(D_004A18B0[0], 0, 1);
    }
}
