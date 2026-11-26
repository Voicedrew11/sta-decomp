





#include "common.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 ev; s32 btn; u8 x8; u8 x9; u8 xA; u8 xB; u8 xC; u8 xD; u8 xE; } In;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x30]; u8 x3C; u8 pad3D[0x53]; } E;
typedef struct { u8 pad[5]; u8 kind; } K;
typedef struct { u8 x0; } K2;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_001803D0(s16, s16);
void func_001803C0(s32 *, s32);
void func_001803B0(s32, s32);
s32 func_001CCD90(s32);
void func_0019FD00(void);
void func_001A2C00(s32, s32);
void func_001CCE30(void);
void func_001CEDC0(s32);
void func_001CEA50(s32);
void func_001DF460(void);
void func_0019A0D0(s32);
K *func_001A97D0(s16);
E *func_001AFC90(void);
K2 *func_001CC3F0(s16);
s32 func_00195B80(s32, s32 *);
void func_00131600(s32, s32);
u8 func_00189EA0(void);
void func_0019D510(void);
void func_001A2FF0(void);
extern Q2 D_001F3260;
extern s32 *D_00201D7C;
extern s32 D_00202220;
extern s32 D_00202224;
extern s32 D_00202230;
extern s32 D_00202234;
extern s32 D_00202238;
extern s16 D_004A3310[];
extern s16 D_004A3312[];
extern s32 D_004A331C[];
extern s32 D_004A3320[];
extern Flags8 D_004A332C[];
extern s32 D_004A3330[];
extern s32 D_004A4330[];
extern s32 D_004A4334[];
extern f32 D_004A433C[];
extern Flags8_6x2 D_004A4340[];

static inline s32 cls(s32 x) {
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
    case 0: r = func_00195B80(1, &D_00202220); break;
    case 1: r = func_00195B80(2, &D_00202220); break;
    case 2: r = func_00195B80(3, &D_00202220); break;
    case 3: r = func_00195B80(4, &D_00202220); break;
    case 4: r = func_00195B80(5, &D_00202220); break;
    case 5: r = func_00195B80(6, &D_00202220); break;
    case 6:
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
        func_001A2C00(D_00202238, cls(mode));
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
        func_001A2C00(D_00202238, cls(mode));
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
        func_0019A0D0(cls(mode) != 2);
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
        func_001A2C00(6, cls(mode));
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
        func_001A2C00(D_00202238, cls(mode));
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
        func_001A2C00(D_00202238, cls(mode));
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





