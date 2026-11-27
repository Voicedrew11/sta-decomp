#include "common.h"
#include "m2c.h"
typedef struct { u16 v[8]; } H;
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 ev; s32 btn; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } In;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x30]; u8 x3C; u8 pad3D[0x53]; } E;
typedef struct { u8 pad[5]; u8 kind; } K;
typedef struct { u8 x0; } K2;
typedef struct { u64 a:6; u64 b:2; } BF;
extern f32 D_00201D8C;
extern Flags8 D_004A4340[];
extern s32 D_004A331C[];
extern s32 D_004A3320[];
extern s32 D_004A4330[];
extern s32 D_004A4334[];
extern s32 *D_00201D7C;
extern s32 D_00202224;
extern s32 D_00202238;
extern f32 D_00201D84;
extern f32 D_00201D88;
extern f32 D_00202228;
extern f32 D_0020222C;
extern f32 D_004A3328[];
extern Q2 D_001F3260;
extern s32 D_00202220;
extern s32 D_00202230;
extern s32 D_00202234;
extern s16 D_004A3310[];
extern s16 D_004A3312[];
extern Flags8 D_004A332C[];
extern s32 D_004A3330[];
extern f32 D_004A433C[];
extern f32 *D_00201D80;
void func_001A1460(u8 *a);
void func_001A1550(u8 *a0, f32 f);
void func_001A1B40(s32 a0);
void func_001A1C80(In *in);
void func_001A2C00(s32 a0, s32 a1);
void func_001A2DE0(void);
void func_001A2EA0(void);
void func_001A2F20(u32 a0);
void func_001A2FF0(s32 i, s8 *o, s8 *p);
f32 func_00187770(f32, f32, f32);
void func_0018A310(s32);
void func_0017F5C0(void);
void func_00181420(void);
void func_00187B20(s32);
void func_0019EF60(u8 *);
H* func_001C9BA0(void);
s8* func_001C9B60(void);
s32 func_001C9BF0(void);
void func_001DD7F0(s32, s32, f32);
void func_001DF360(s32, s32);
void func_001DEB00(s32, s32, f32);
void func_00184960(void *, f32);
void func_001DE0D0(s32, f32);
void func_0019A370(H *, H *, H *, H *, s32);
void func_0019A500(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);
void func_00186440(f32, H *, H *, H *, H *);
void func_00185B30(s32, s32);
void func_00185510(f32, H *);
void func_00185B40(f32, s8 *);
s32 func_001CCD90(s32);
void func_00185390(f32, s32, s32, s32);
void func_001DF470(f32, s32);
void func_00183DC0(s32);
void func_001A1000(s32);
void func_001A0DB0(s32);
void func_001A0B00(s32);
void func_001A0850(s32);
void func_001A06B0(s32);
void func_001A03C0(s32);
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_001803D0(s16, s16);
void func_001803C0(s32 *, s32);
void func_001803B0(s32, s32);
void func_0019FD00(void);
void func_001CCE30(void);
void func_001CEDC0(s32);
void func_001CEA50(s32);
void func_001DF460(void);
void func_0019A0D0(s32);
K* func_001A97D0(s16);
E* func_001AFC90(void);
K2* func_001CC3F0(s16);
s32 func_00195B80(s32, s32 *);
void func_00131600(s32, s32);
u8 func_00189EA0(void);
void func_0019D510(void);
void memset(void *, s32, s32);
s32 func_00195BE0(s32);
void func_001833E0(s16, s32);
void func_0017F840(s32, void **);

/* func_001A1460 */
void func_001A1460(u8 *a) {
    func_0018A310(-1);
    if (a[8] == 0x22) {
        D_00201D8C = func_00187770(D_00201D8C, -0.02f, 3.5f);
    } else {
        D_00201D8C = func_00187770(D_00201D8C, -2.99f, 3.5f);
    }
    if (!D_004A4340[0].f.b2) {
        func_0017F5C0();
    }
    if (!(D_00201D8C <= -2.99f)) {
        func_001A1550(a, D_00201D8C);
    }
    func_00181420();
    func_00187B20(0);
    if (D_004A331C[0]) {
        func_0019EF60(a);
    }
}

/* func_001A1550 */
static inline s32 cls_func_001A1550(s32 x) {
    s32 r;
    switch (x) {
    case 0: r = 0; break;
    case 1: r = 0; break;
    case 2: r = 2; break;
    case 3: r = 2; break;
    case 4: r = 1; break;
    case 5: r = 2; break;
    case 6: r = 2; break;
    default: r = -1; break;
    }
    return r;
}
static inline s32 mp(s32 x) { if (x == 1) return 1; if (x == 9) return 100; return x; }

void func_001A1550(u8 *a0, f32 f) {
    s32 rFC;
    s32 rF8;
    s32 rF4;
    s32 rF0;
    s32 rEC;
    H d0;
    H c0;
    H b0;
    H a0_;
    H m90;
    H m80;
    s32 mode;
    H *s2;
    H *s1;
    s8 *s5;
    s32 id;
    s32 i;
    s32 x;
    f32 hi;
    f32 lo;

    mode = D_004A3320[0];
    s2 = func_001C9BA0();
    s1 = func_001C9BA0();
    s5 = func_001C9B60();
    id = D_00201D7C[D_004A4330[0]];
    if (D_00202224 <= 0) id = -1;
    if (a0[8] == 0x22) {
        if (D_004A4340[0].f.b2) {
            hi = 3.5f;
            D_00201D84 = func_00187770(D_00201D84, -0.02f, hi);
            lo = -2.99f;
            D_00201D88 = func_00187770(D_00201D88, lo, 3.5f);
        } else {
            hi = 3.5f;
            lo = -2.99f;
            D_00201D84 = func_00187770(D_00201D84, lo, hi);
            D_00201D88 = func_00187770(D_00201D88, -0.02f, 3.5f);
        }
    } else {
        hi = 3.5f;
        lo = -2.99f;
        D_00201D84 = func_00187770(D_00201D84, lo, hi);
        D_00201D88 = func_00187770(D_00201D88, -2.99f, 3.5f);
    }
    func_001DD7F0(id, mode, D_00201D84);
    func_001DF360(D_004A4340[0].f.b2, id);
    func_001DEB00(D_00202238, mode, -D_00201D88 / 2.0f);
    func_00184960((s8 *)s2 + 0x80, -D_00201D88 / 2.0f);
    func_001DE0D0(id, D_00201D88);
    if (D_004A4340[0].f.b3) {
        func_0019A370(&m90, &m80, &b0, &a0_, id);
        func_00186440(f, &m90, &m80, &b0, &a0_);
        func_00185B30(0, 0);
    } else {
        if (func_001C9BF0()) {
            func_0019A500(&d0, &c0, &rFC, &rF8, &rF4, -1, -1, 0);
        }
        if (D_00202224 <= 0) {
            func_0019A500(&b0, &a0_, &rFC, &rF0, &rEC, -1, -1, 0);
        } else {
            func_0019A500(&b0, &a0_, &rFC, &rF0, &rEC, D_00202238, id, cls_func_001A1550(mode) != 2);
        }
        for (i = 0; i < 8; i++) {
            b0.v[7 - i] -= d0.v[7 - i];
            a0_.v[7 - i] -= c0.v[7 - i];
        }
        if (id == (s16)func_001CCD90(D_00202238)) {
            func_00185B30(0, 0);
            func_00186440(f, &d0, &c0, NULL, NULL);
        } else {
            func_00185B30(rF0 - rF8, rEC - rF4);
            func_00186440(f, &d0, &c0, &b0, &a0_);
        }
    }
    func_00185510(f, s1);
    func_00185B40(f, s5);
    if (D_004A4334[0] == 1) D_0020222C = 10.0f;
    if (D_0020222C > 0.0f) {
        D_0020222C -= 1.0f;
        D_00202228 = func_00187770(D_00202228, lo, hi);
    } else {
        D_00202228 = func_00187770(D_00202228, -0.02f, hi);
    }
    func_00185390(f + D_00202228, 1, D_00202224, D_004A4330[0]);
    func_001DF470(f + D_00202228, mp(D_00202238));
}

/* func_001A1B40 */
#define D_004A331C D_004A331C__as_func_001A1B40
extern u32 D_004A331C__as_func_001A1B40[];
#define func_001A2F20 func_001A2F20__as_func_001A1B40
void func_001A2F20__as_func_001A1B40(s32);
#define func_001A1C80 func_001A1C80__as_func_001A1B40
void func_001A1C80__as_func_001A1B40(s32);

void func_001A1B40(s32 a0) {
    s32 id;
    s32 x;

    x = D_004A3320[0];
    id = D_00201D7C[D_004A4330[0]];
    if (D_00202224 <= 0) id = -1;
    D_004A4334[0] = 0;
    func_001A2F20(x);
    func_00183DC0(id);
    if (D_004A3328[0] > 0.0f) {
        D_004A3328[0] -= 1.0f;
        return;
    }
    switch (D_004A331C[0]) {
    case 0: func_001A1C80(a0); break;
    case 1: func_001A1000(a0); break;
    case 2: func_001A0DB0(a0); break;
    case 3: func_001A0B00(a0); break;
    case 4: func_001A0850(a0); break;
    case 5: func_001A06B0(a0); break;
    case 6: func_001A03C0(a0); break;
    }
}
#undef func_001A2F20
#undef func_001A1C80
#undef D_004A331C

/* func_001A1C80 */
#define func_001A2FF0 func_001A2FF0__as_func_001A1C80
void func_001A2FF0__as_func_001A1C80(void);
#define D_004A4340 D_004A4340__as_func_001A1C80
extern Flags8_6x2 D_004A4340__as_func_001A1C80[];

static inline s32 cls_func_001A1C80(s32 x) {
    s32 r;
    switch (x) {
    case 0: r = 0; break;
    case 1: r = 0; break;
    case 2: r = 2; break;
    case 3: r = 2; break;
    case 4: r = 1; break;
    case 5: r = 2; break;
    case 6: r = 2; break;
    default: r = -1; break;
    }
    return r;
}
static inline s32 nx(s32 x) {
    s32 r;
    switch (x) {
    case 1: r = func_00195B80(1, &D_00202220); break;
    case 2: r = func_00195B80(2, &D_00202220); break;
    case 3: r = func_00195B80(3, &D_00202220); break;
    case 4: r = func_00195B80(4, &D_00202220); break;
    case 5: r = func_00195B80(5, &D_00202220); break;
    case 6: r = func_00195B80(6, &D_00202220); break;
    case 0:
    default: r = -1; break;
    }
    return r;
}
static inline void setupn(s32 n) {
    Q2 q;
    Arg a;
    q = D_001F3260;
    a.fn = func_0019D510;
    a.n = n;
    a.f = -3.0f;
    a.cb = func_001A2FF0;
    a.a = 0;
    a.b = 0;
    a.p = D_00201D7C;
    func_0017F890(D_00202238, &q, &a);
    func_0017F7C0(D_00202238, 1, 1);
    D_00202230 = 2;
    func_0017F470(D_004A4330[0], D_00202238, 1);
}
static inline void setup(void) {
    Q2 q;
    Arg a;
    q = D_001F3260;
    a.fn = func_0019D510;
    a.f = -3.0f;
    a.cb = func_001A2FF0;
    a.a = 0;
    a.b = 0;
    a.p = D_00201D7C;
    a.n = D_00202224;
    func_0017F890(D_00202238, &q, &a);
    func_0017F7C0(D_00202238, 1, 1);
    D_00202230 = 2;
    func_0017F470(D_004A4330[0], D_00202238, 1);
}

void func_001A1C80(In *in) {
    s32 mode;
    u8 k;
    s32 sel;
    s32 i;
    s32 btn;
    s32 *p;
    s32 id;
    E *e;
    s32 ok;
    u8 b;
    s32 t;

    mode = D_004A3320[0];
    t = D_00202238;
    if (mode == 1) {
        func_001803D0(-2, -2);
    } else {
        func_001803D0((s16)func_001CCD90(t), -2);
    }
    if (D_004A332C[0].f.b2) {
        func_0019FD00();
        func_001A2C00(D_00202238, cls_func_001A1C80(mode));
        D_004A4340[0].f.b5 = D_00202234 != D_00202224;
        if (D_004A4340[0].f.b5) {
            setupn(D_00202224);
            D_004A4340[0].f.b5 = 0;
        }
        func_001CCE30();
        func_001CEDC0(3);
        func_001CEA50(1);
        D_004A332C[0].f.b2 = 0;
    }
    if (D_004A332C[0].f.b3) {
        func_001A2C00(D_00202238, cls_func_001A1C80(mode));
        D_004A332C[0].f.b3 = 0;
        D_004A433C[0] = 10.0f;
    }
    if (!(D_004A4330[0] < D_00202224)) D_004A4330[0] = D_00202224 - 1;
    sel = D_004A4330[0];
    id = D_00201D7C[sel];
    if (D_00202224 <= 0) {
        sel = 0;
        D_004A4330[0] = 0;
        id = -1;
    }
    if (in->ev == 0x19) {
        D_004A4330[0] = 0;
        D_004A4340[0].f.b3 = 0;
        D_004A4340[0].f.b2 = 0;
        func_001DF460();
        func_0019A0D0(cls_func_001A1C80(mode) != 2);
        if (mode == 1) {
            p = D_004A3330;
            for (i = 0; i < 0x400; i++, p++) {
                *p = 0;
                if (func_001A97D0(i)->kind == 3) {
                    func_001AFC90();
                    *p = 1;
                }
            }
            D_004A4340[0].f.b6 = 1;
            func_001803C0(D_004A3330, 0);
        } else {
            func_001803C0(NULL, 0);
        }
        D_00202220 = 0;
        D_00202238 = 6;
        func_001A2C00(6, cls_func_001A1C80(mode));
        setup();
    }
    if (in->ev != 0x16) return;
    btn = in->btn;
    if (btn & 0x10) {
        sel--;
        if (sel < 0) {
            sel = D_00202224 - 1;
            if (sel < 0) sel = 0;
        }
        in->btn = 0;
    } else if (btn & 0x40) {
        sel++;
        if (!(sel < D_00202224)) sel = 0;
        in->btn = 0;
    } else if (btn & 0x480) {
        func_0017F7C0(D_00202238, 0, 1);
        func_001DF460();
        D_004A4330[0] = 0;
        D_004A4334[0] = 1;
        D_00202230 = 2;
        D_00202220--;
        D_00202238 = nx(D_004A3320[0]);
        func_001A2C00(D_00202238, cls_func_001A1C80(mode));
        setup();
        func_00131600(0x66, in->xE);
        in->btn = 0;
        return;
    } else if (btn & 0x820) {
        func_0017F7C0(D_00202238, 0, 1);
        func_001DF460();
        D_004A4330[0] = 0;
        D_004A4334[0] = 1;
        D_00202230 = 2;
        D_00202220++;
        D_00202238 = nx(D_004A3320[0]);
        func_001A2C00(D_00202238, cls_func_001A1C80(mode));
        setup();
        func_00131600(0x66, in->xE);
        in->btn = 0;
        return;
    } else if (btn & 0x1000) {
        func_0017F7C0(D_00202238, D_004A4340[0].f.b2, 1);
        if (D_004A4340[0].f.b2) setup();
        D_00202230 = 2;
        D_004A4340[0].f.b2 = !D_004A4340[0].f.b2;
        D_004A433C[0] = 15.0f;
        in->xC = D_004A4340[0].f.b2;
        func_00131600(0x67, in->xE);
        in->btn = 0;
    } else if (btn & 0x8000) {
        D_004A4340[0].f.b3 = !D_004A4340[0].f.b3;
        func_00131600(0x67, in->xE);
        in->btn = 0;
    } else if (btn & 0x2000) {
        if (D_00202224 > 0) {
            ok = 0;
            if (mode == 6) {
                e = &func_001AFC90()[id];
                if (e->xA == 1) {
                    k = e->x3C;
                    if (k == func_001CC3F0(id)->x0) ok = 1;
                } else if (e->xA == 2) {
                    k = e->x3C;
                    if (k == func_001CC3F0(id)->x0) ok = 1;
                }
            }
            if (ok) {
                func_00131600(0x68, in->xE);
            } else {
                D_004A3310[0] = id;
                D_004A332C[0].f.b4 = 1;
                D_004A331C[0] = mode;
                D_004A433C[0] = 10.0f;
                D_004A3312[0] = 1;
                D_00202234 = D_00202224;
                func_00131600(0x67, in->xE);
            }
            in->btn = 0;
        }
    } else if (btn & 0x4000) {
        b = D_004A4340[0].f.b2;
        if (b) {
            func_0017F7C0(D_00202238, b, 1);
            if (D_004A4340[0].f.b2) setup();
            D_00202230 = 2;
            D_004A4340[0].f.b2 = !D_004A4340[0].f.b2;
            D_004A433C[0] = 15.0f;
            in->xC = D_004A4340[0].f.b2;
            func_00131600(0x67, in->xE);
            in->btn = 0;
        } else {
            in->x8 = func_00189EA0();
            func_0017F7C0(D_00202238, 0, 1);
            if (D_00202238 > 4) {
                in->x9 = D_00202238 + 1;
            } else {
                in->x9 = D_00202238;
            }
            func_001803C0(NULL, 0);
            func_001803B0(0, 0);
            in->btn = 0;
            in->ev = 0x1A;
            func_00131600(0x69, in->xE);
            in->btn = 0;
        }
    }
    if (func_0017F470(D_004A4330[0], D_00202238, 0) != 0 || D_004A4340[0].f.b2) {
        if (D_004A4330[0] != sel) func_00131600(0x66, in->xE);
        D_004A4330[0] = sel;
        D_00202230 = 0;
        D_004A4340[0].f.b4 = 0;
    }
}
#undef func_001A2FF0
#undef D_004A4340

/* func_001A2C00 */
#define func_001AFC90 func_001AFC90__as_func_001A2C00
u8 *func_001AFC90__as_func_001A2C00(void);
#define func_001CC3F0 func_001CC3F0__as_func_001A2C00
u8 *func_001CC3F0__as_func_001A2C00(s16);
#define func_001A97D0 func_001A97D0__as_func_001A2C00
u8 *func_001A97D0__as_func_001A2C00(s16);

void func_001A2C00(s32 a0, s32 a1) {
    u8 *e;
    s32 i;
    u8 *base;
    u8 *c;

    base = func_001AFC90();
    D_00202224 = 0;
    memset(D_00201D7C, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        c = func_001CC3F0(func_00195BE0(i));
        switch (a1) {
        case 0:
            if (func_001A97D0(func_00195BE0(i))[5] == 0) {
                continue;
            }
            if ((s32)func_001A97D0(func_00195BE0(i))[2] <= 0) {
                continue;
            }
            break;
        case 1:
            if ((s32)func_001A97D0(func_00195BE0(i))[4] <= 0) {
                continue;
            }
            break;
        case 2:
            if ((s32)c[2] <= 0) {
                continue;
            }
            break;
        }
        e = base + func_00195BE0(i) * 0x90;
        if (a0 >= 2 || *(u16 *)(e + 0xA) == 2) {
            if (a0 < 2 || a0 >= 9 || (*(u16 *)(e + 0xA) == 1 && *(u16 *)(e + 0x20) == a0 - 2)) {
                if (a0 != 9 || *(u16 *)(e + 0xA) == 0) {
                    D_00201D7C[D_00202224] = func_00195BE0(i);
                    D_00202224++;
                }
            }
        }
    }
}
#undef func_001AFC90
#undef func_001CC3F0
#undef func_001A97D0

/* func_001A2DE0 */
#define D_004A4340 D_004A4340__as_func_001A2DE0
extern BF D_004A4340__as_func_001A2DE0[];
#define func_001A97D0 func_001A97D0__as_func_001A2DE0
u8 *func_001A97D0__as_func_001A2DE0(s16);

void func_001A2DE0(void) {
    s32 i;
    if (D_004A4340[0].b) {
        for (i = 0; i < 0x400; i++) {
            D_004A3330[i] = 0;
            if (func_001A97D0(i)[5] == 3) {
                func_001A97D0(i)[5] = 1;
            }
        }
    }
    D_004A4340[0].b = 0;
}
#undef func_001A97D0
#undef D_004A4340

/* func_001A2EA0 */
#define func_001A97D0 func_001A97D0__as_func_001A2EA0
u8 *func_001A97D0__as_func_001A2EA0(s16);
void func_001A2EA0(void) {
    s32 i;
    s32 *p = D_004A3330;
    for (i = 0; i < 0x400; i++, p++) {
        *p = 0;
        if (func_001A97D0(i)[5] == 3) {
            func_001A97D0(i)[5] = 1;
        }
    }
}
#undef func_001A97D0

/* func_001A2F20 */
void func_001A2F20(u32 a0) {
    s32 n = 10;
    s32 i;

    switch (a0) {
    case 1:
    case 3:
    case 4:
        n = 10;
        break;
    case 2:
    case 5:
        n = 9;
        break;
    case 6:
        n = 7;
        break;
    }
    for (i = 0; i < n; i++) {
        func_001833E0(func_001CCD90(i), i);
    }
    for (; n < 10; n++) {
        func_001833E0(-1, n);
    }
}

/* func_001A2FF0 */
void func_001A2FF0(s32 i, s8 *o, s8 *p) {
    void *info;
    func_0017F840(D_00202238, &info);
    switch (D_00202230) {
    case 0:
        *(f32 *)(o + 0x14) = *(f32 *)(p + 8) - (f32)i;
        break;
    case 2:
        if (i >= D_004A4330[0] - 3 && i <= D_004A4330[0] + 3) {
            *(f32 *)(o + 0x14) = D_00201D80[i] = *(f32 *)(p + 8) - (f32)i;
        } else {
            *(f32 *)(o + 0x14) = D_00201D80[i] = -5.0f;
        }
        break;
    }
}
