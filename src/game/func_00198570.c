#include "common.h"
#include "m2c.h"
void func_00198570();
void func_00198BD0(s32 arg0);
void func_00198BE0();
void func_00198D80(void);

/* func_00198570 */
#define P P_func_00198570
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    u64 a, b;
    f32 x, y;
} S;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; Vec x10; Vec x20; } B;
typedef struct { u8 pad[0x54]; u8 *x54; } P;
typedef struct { u8 pad[0xE]; u8 xE; } G;
void func_00181680(s32, Vec *, Vec *, Col *, S *, u32);
void func_001875C0(f32, s8 *, f32, f32, s32, u32);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
G *func_001C9BA0(void);
P *func_00189020(s32);
s32 func_001AA440(u32);
u16 func_001AA090(s32);
u16 func_001A9FF0(s32);
s32 func_001959E0(s32);
void func_00183650(s8 *);
extern S D_001F2FE0 __attribute__((aligned(16)));
extern s32 D_004A1450[];
extern s32 D_004A18B0[];
extern u32 D_002021A4;
extern s8 D_001FD398[];
extern s8 D_001FD3A0[];
extern s8 D_001FD3B0[];
extern s8 D_001FD3C0[];
extern s8 D_001FD3C8[];
extern s8 D_001FD3D0[];
extern s8 D_001FD3E0[];
extern s8 D_001FD3E8[];
extern s8 D_004A1770[];
extern s8 D_004A1870[];
extern f32 D_004A1884[];
extern f32 D_004A1888[];
extern f32 D_004A189C[];
extern f32 D_004A18A0[];
extern u32 D_004A18AC[];
static inline f32 u2f(u32 x) { return x; }
static inline s32 any(u32 k) {
    u32 i;
    for (i = 0; (s32)i < 10; i++) {
        if (!(func_001AA440(k * 10 + i) != 0) == 0) return 1;
    }
    return 0;
}

void func_00198570(A *o, s32 mode, u32 kind) {
    S s __attribute__((aligned(16)));
    Col col;
    s32 n;
    s32 k;
    f32 f;
    u32 c;
    B *b;

    s = D_001F2FE0;
    n = D_004A1450[D_004A18B0[0]] * 10;
    {
        s8 buf[0x100] = {0};

        if (kind < 300) {
            if (func_001C9BA0()->xE == 0 && mode == 200) return;
            s.x = o->x30;
            s.y = o->x34;
            if (kind == 0) {
                o->x2C.c.r = 0x40;
                o->x2C.c.g = 0x40;
                o->x2C.c.b = 0x40;
            }
            func_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, kind);
            return;
        }
        if (kind == 500) {
            b = (B *)(func_00189020(0)->x54 + 0x390);
            col.w = 0x30808080;
            s.x = o->x38;
            s.y = o->x3C;
            func_00181680(b->x4, &b->x10, &b->x20, &col, &s, kind);
        }
        if (kind == 501) {
            col.w = 0x80808080;
            sprintf(buf, D_001FD398, D_002021A4);
            func_001875C0(o->x38, buf, o->x3C, 0.9f, 2, col.w);
        }
        if (mode == 100) {
            if (kind == 400) {
                col.w = 0x80808080;
                strcpy(buf, D_001FD3A0);
                func_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
            if (kind == 401) {
                col.w = 0x80808080;
                if (n < 0) {
                    strcpy(D_004A1770, D_001FD3B0);
                    strcpy(buf, D_001FD3B0);
                } else {
                    k = n / 10;
                    if (any(n / 10)) {
                        c = func_001AA090(k * 10);
                        f = 100.0f * (u2f(c) / (f32)func_001959E0(k));
                        if (func_001959E0(k) == 0) {
                            sprintf(buf, D_001FD3C0, (s32)f);
                        } else {
                            sprintf(buf, D_001FD3C8, (s32)f);
                        }
                    } else {
                        strcpy(buf, D_001FD3B0);
                    }
                }
                func_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
        }
        if (func_001C9BA0()->xE != 0 && mode == 200) {
            if (kind == 400) {
                col.w = 0x80808080;
                strcpy(buf, D_001FD3D0);
                func_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
            if (kind == 401) {
                col.w = 0x80808080;
                if (n < 0) {
                    strcpy(D_004A1770, D_001FD3B0);
                    strcpy(buf, D_001FD3B0);
                } else {
                    k = n / 10;
                    if (any(n / 10)) {
                        c = func_001A9FF0(k * 10);
                        f = 100.0f * (u2f(c) / (f32)func_001959E0(k));
                        if (func_001959E0(k) == 0) {
                            sprintf(buf, D_001FD3E0, (s32)f);
                        } else {
                            sprintf(buf, D_001FD3E8, (s32)f);
                        }
                    } else {
                        strcpy(buf, D_001FD3B0);
                    }
                }
                func_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
        }
        if (kind == 10001) {
            D_004A189C[0] = o->x38;
            D_004A18A0[0] = o->x3C;
            D_004A1884[0] = 1.25f;
            D_004A18AC[0] = 0x80FFFFFF;
            D_004A1888[0] = 1.25f;
            func_00183650(D_004A1870);
        }
    }
}
#undef P

/* func_00198BD0 */
void func_00198BD0(s32 arg0) {
    func_00198BE0((void *) arg0);
}

/* func_00198BE0 */
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } M;
extern s32 D_002021A8;
extern s32 D_004A1450[];
extern s32 D_004A18B0[];
extern f32 D_004A18B8[];
void func_00199000(void);
void func_00198D80(void);
void func_001803D0(s32, s32);
void func_00131600(s32, s32);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_00183970(s32);

void func_00198BE0(M *m) {
    s32 sel;
    s32 old;
    switch (m->x0) {
    case 0x19:
        D_004A18B0[0] = 0;
        func_00199000();
        func_00198D80();
        break;
    case 0x16:
        old = D_004A18B0[0];
        sel = old;
        if (m->x4 & 0x4000) {
            func_001803D0(-2, -2);
            func_00131600(0x69, m->xE);
            m->x8 = 0x18;
            m->x4 = 0;
            m->x0 = 0x1A;
            func_0017F7C0(0, 0, 1);
            return;
        }
        if (m->x4 & 0x10) {
            sel = old - 1;
        } else if (m->x4 & 0x40) {
            sel = old + 1;
        }
        if (D_002021A8 != 0) {
            sel = (sel + D_002021A8) % D_002021A8;
        }
        if (func_0017F470(old, 0, 0)) {
            if (D_004A18B0[0] != sel) {
                func_00131600(0x66, m->xE);
            }
            D_004A18B0[0] = sel;
        } else {
            D_004A18B8[0] = 10.0f;
        }
        break;
    }
    func_00183970(D_004A1450[D_004A18B0[0]] * 10);
}

/* func_00198D80 */
#define P P_func_00198D80
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; u32 n; } P;
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_001803D0(s32, s32);
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
#undef P
