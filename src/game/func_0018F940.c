#include "m2c.h"
typedef union { u128 q[2]; s32 w[8]; f32 f[8]; void *p[8]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; void *a; s32 b; void *cb; } Arg;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 r:2; } F;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9; s8 xA; u8 pB; s8 xC; u8 xD; u8 xE; } O;
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad14[0x14]; f32 x28; } Info;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_0017F840(s32, Info **);
void func_0018B320(s32 *);
void func_00131600(s32, u8);
void func_00190490(void);
void func_00190340(void);
void func_00190720(void);
void func_00190630(void);
void func_0012C6C0(s32);
void func_0012C720(s32);
void func_0012C6B0(void);
void func_001304B0(s32);
extern Q2 D_001F2D10;
extern s32 D_001F2D00[];
extern f32 D_001F2AC0[];
extern u8 D_004A1075[];
extern s32 D_004A1080[];
extern s32 D_004A1084[];
extern s32 D_004A1088[];
extern s32 D_004A108C[];
extern f32 D_004A1090[];
extern f32 D_004A10B0[];
extern s32 D_004A10D0[];
extern s32 D_004A10D4[];
extern f32 D_004A10D8[];
extern F D_004A10DC[];
extern s32 D_004A10E0[];
extern s32 D_004A10E4[];
extern s32 D_004A10E8[];
extern s32 D_00202128;
extern s32 D_00202130;
static inline void fill(void) {
    Info *p;
    s32 i;
    s32 n;
    func_0017F840(13, &p);
    n = p->x10;
    for (i = 0; i < n; i++) {
        D_004A10B0[i] = p->x28 - i;
    }
}

void func_0018F940(O *a0) {
    s32 cur;
    s32 nxt;
    s32 flags;
    s32 v;
    Q2 q;
    Arg a;

    D_004A1088[0] = 0;
    D_004A1080[0] = 0x2B;
    D_004A1084[0] = 3;
    D_004A1090[0] = 1.0f;
    D_004A108C[0] = 0;
    cur = D_004A10D0[0];
    nxt = cur;
    if (!D_004A10DC[0].b3) {
        flags = a0->x4;
        if (flags & 0x2000) {
            func_00131600(0x67, a0->xE);
            switch (D_004A10D0[0]) {
            case 0:
                D_004A10D4[0] = 1;
                D_004A10E0[0] = 0;
                q = D_001F2D10;
                a.p = D_001F2D00;
                a.n = 3;
                a.fn = func_00190720;
                a.a = func_00190630;
                a.b = 0;
                a.cb = 0;
                a.f = D_001F2AC0[0];
                func_0017F890(11, &q, &a);
                func_0017F470(0.0f, 11, 0);
                func_0017F7C0(11, 0, 0);
                D_004A10DC[0].b4 = 1;
                D_004A10DC[0].b5 = 1;
                v = D_004A1075[0] * 2;
                if (v > 0x7F) v = 0x7F;
                func_0012C6C0(0x7F);
                func_0012C720(v);
                break;
            case 1:
                D_004A10D4[0] = 2;
                D_004A10E4[0] = 0;
                func_00190490();
                break;
            case 2:
                D_004A10D4[0] = 3;
                D_004A10E8[0] = 0;
                func_00190340();
                break;
            case 3:
                D_004A10D4[0] = 4;
                func_0018B320(D_004A1080);
                a0->xA = 1;
                break;
            }
            D_004A10D8[0] = 0.0f;
            if (D_00202128 == 0) fill();
            D_00202128 = 1;
            return;
        } else if (flags & 0x4000) {
            func_00131600(0x69, a0->xE);
            D_004A10D8[0] = 0.0f;
            D_004A10D4[0] = 5;
            if (D_00202128 == 0) fill();
            D_00202128 = 3;
            func_0017F7C0(13, 0, 1);
            func_001304B0(-0x666);
            if (D_004A10DC[0].b4) {
                v = D_004A1075[0] * 2;
                if (v > 0x7F) v = 0x7F;
                func_0012C720(v);
                func_0012C6B0();
            } else {
                func_0012C720(0x7F);
            }
            return;
        } else if (flags & 0x10) {
            if (D_00202128 == 0) {
                nxt = cur - 1;
                a0->x4 = flags & ~0x10;
            }
        } else if (flags & 0x40) {
            if (D_00202128 == 0) {
                nxt = cur + 1;
                a0->x4 = flags & ~0x40;
            }
        }
    }
    if (!func_0017F470(*(volatile s32 *)D_004A10D0, 13, 0)) {
        D_004A10D0[0] = cur;
        return;
    }
    if (nxt != D_004A10D0[0]) func_00131600(0x66, a0->xE);
    v = 4 - D_00202130;
    D_004A10D0[0] = (nxt + v) % v;
}
