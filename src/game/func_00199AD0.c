#include "actor.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef union { s32 w; Flags8 f; } FW;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[3]; u8 xC; u8 xD; u8 xE; } S;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
s16 func_001CCD90(s32);
void func_001CEDC0(s32);
void func_001DF460(void);
void func_0019D510(void);
void func_0019A6A0(void);
void func_00131600(s32, u8);
void func_001803D0(s32, s32);
void func_001803B0(s32, s32);
s32 func_00195B80(s32, s32 *);
s32 func_001AFBD0(s32);
void func_001CCF00(s32, s32);
void func_001CEA50(s32);
u8 *func_001CC3F0(s16);
void func_001CCE30(void);
extern Q2 D_001F3040;
extern s32 D_00201D48;
extern s32 **D_00201D4C;
extern s32 D_002021B4;
extern s32 D_002021B0;
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
static inline void toggle(S *a0, s32 v) {
    func_0017F7C0(D_00201D48, v, 1);
    if (D_004A28D0[0].f.f.b3) {
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
    D_004A28D0[0].f.f.b3 = !D_004A28D0[0].f.f.b3;
    a0->xC = D_004A28D0[0].f.f.b3;
    D_002021AC = 2;
    D_004A28CC[0] = 15.0f;
    func_00131600(0x67, a0->xE);
}

void func_00199AD0(S *a0) {
    s32 cur;
    s32 id;
    s32 flags;
    u8 t;

    cur = D_004A28C0[0];
    id = (s32)D_00201D4C[cur];
    func_001803D0(func_001CCD90(D_00201D48), -2);
    flags = a0->x4;
    if (flags & 0x10) {
        cur--;
        if (cur < 0) {
            cur = D_002021B4 - 1;
            if (cur < 0) cur = 0;
        }
        a0->x4 = 0;
    } else if (flags & 0x40) {
        cur++;
        if (!(cur < D_002021B4)) cur = 0;
        a0->x4 = 0;
    } else if (flags & 0x480) {
        func_0017F7C0(D_00201D48, 0, 1);
        D_002021B0--;
        D_004A28C4[0] = 1;
        D_004A28C8[0] = func_00195B80(0, &D_002021B0);
        D_002021AC = 2;
        func_00131600(0x66, a0->xE);
        func_001DF460();
        a0->x4 = 0;
        return;
    } else if (flags & 0x820) {
        func_0017F7C0(D_00201D48, 0, 1);
        D_002021B0++;
        D_004A28C4[0] = 1;
        D_004A28C8[0] = func_00195B80(0, &D_002021B0);
        D_002021AC = 2;
        func_00131600(0x66, a0->xE);
        func_001DF460();
        a0->x4 = 0;
        return;
    } else if (flags & 0x2000) {
        if (id > 0 && D_002021B4 > 0) {
            if (!func_001AFBD0(id)) {
                func_001CCF00(D_00201D48, (s16)id);
                func_001CEA50(1);
                func_00131600(0x67, a0->xE);
            } else if (*func_001CC3F0(id) > 0) {
                func_001CCF00(D_00201D48, (s16)id);
                func_001CEA50(1);
                func_00131600(0x67, a0->xE);
            } else {
                func_00131600(0x6B, a0->xE);
            }
            func_001CCE30();
            func_001CEDC0(3);
        }
        a0->x4 = 0;
    } else if (flags & 0x1000) {
        toggle(a0, D_004A28D0[0].f.f.b3);
        a0->x4 = 0;
    } else if (flags & 0x8000) {
        D_004A28D0[0].f.f.b2 = !D_004A28D0[0].f.f.b2;
        func_00131600(0x67, a0->xE);
        a0->x4 = 0;
    } else if (flags & 0x4000) {
        t = D_004A28D0[0].f.f.b3;
        if (t) {
            toggle(a0, t);
            a0->x4 = 0;
        } else {
            a0->x8 = 0x14;
            a0->x4 = 0;
            a0->x0 = 0x1A;
            func_0017F7C0(D_00201D48, 0, 1);
            func_001803D0(-2, -2);
            func_001803B0(0, 0);
            func_00131600(0x69, a0->xE);
            a0->x4 = 0;
        }
    }
    if (func_0017F470(D_004A28C0[0], D_00201D48, 0) || D_004A28D0[0].f.f.b3) {
        if (D_004A28C0[0] != cur) func_00131600(0x66, a0->xE);
        D_004A28C0[0] = cur;
        D_002021AC = 0;
    }
}
