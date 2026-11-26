#include "m2c.h"
typedef union { u128 q[2]; s32 w[8]; f32 f[8]; void *p[8]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 r:2; } F;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9; s8 xA; u8 pB; s8 xC; } O;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
void func_0017F470(f32, s32, s32);
void func_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
void func_0018B320(s32 *);
f32 sinf(f32);
void func_00130440(void);
void func_00190770(void);
void func_00191820(void);
void func_00191C40(void);
extern Q2 D_001F2CE0;
extern s32 D_001F2CD0[];
extern f32 D_001F2A90[];
extern s32 D_004A1080[];
extern s32 D_004A10C0[];
extern f32 D_004A10C4[];
extern f32 D_004A10C8[];
extern s32 D_004A10D0[];
extern s32 D_004A10D4[];
extern f32 D_004A10D8[];
extern F D_004A10DC[];
extern s32 D_00202128;
extern s32 D_00202130;

void func_0018FFE0(O *p) {
    Q2 q;
    Arg a;

    switch (p->x0) {
    case 0x19:
        D_004A10D8[0] = 0.0f;
        D_004A10D4[0] = 0;
        D_004A10D0[0] = 1;
        D_004A10C0[0] = 0;
        D_004A10C8[0] = 0.0f;
        D_004A10C4[0] = 0.0f;
        D_004A10DC[0].b2 = 0;
        D_004A10DC[0].b1 = 0;
        D_004A10DC[0].b4 = 0;
        D_004A10DC[0].b5 = 1;
        D_00202128 = 0;
        q = D_001F2CE0;
        q.f[5] = D_001F2A90[0];
        a.p = D_001F2CD0;
        a.n = 4 - D_00202130;
        a.fn = func_00190770;
        a.f = D_001F2A90[0];
        a.a = 0;
        a.b = 0;
        a.cb = func_00191820;
        func_0017F890(13, &q, &a);
        func_0017F470(0.0f, 13, 0);
        func_0017F7C0(13, 0, 1);
        if (D_00202130) {
            func_0018B150(1.0f, D_004A1080, 0x2C, 2, func_00191C40, 0);
            func_0018B320(D_004A1080);
            D_004A10DC[0].b3 = 1;
            p->xA = 1;
        }
        if (D_00202130) {
            p->xC = 4;
        } else {
            p->xC = 0;
        }
        break;
    case 0x1B:
        break;
    case 0:
        func_0017F7C0(13, 1, 1);
        break;
    case 0x16:
        break;
    case 0x1A:
        break;
    case 0x1C:
        break;
    case 0x1E:
        func_00130440();
        break;
    }
    D_004A10D8[0] += 1.0f;
    D_004A10C0[0] += 5;
    D_004A10C0[0] %= 180;
    D_004A10C4[0] = 10.0f * sinf(3.1415927f * D_004A10C0[0] / 180.0f);
    D_004A10C8[0] = -10.0f * sinf(3.1415927f * D_004A10C0[0] / 180.0f);
}
