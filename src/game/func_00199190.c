#include "common.h"
#include "actor.h"
#include "m2c.h"
typedef union { s32 w; Flags8 f; } FW;
typedef struct { u16 v[8]; } H;
typedef struct { u8 pad[8]; u8 x8; } O;
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[3]; u8 xC; u8 xD; u8 xE; } S;
typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; } P;
typedef struct { u8 pad[0xA]; u16 xA; u8 padC[0x14]; u16 x20; u8 pad22[0x6E]; } E_func_0019A1D0;
typedef struct { u8 pad[0x2C]; u16 a[8]; u8 pad2[0x4A-0x3C]; u16 b[6]; } E_func_0019A370;
typedef struct { s16 v[10]; } Ids;
typedef struct { u8 b[4]; } Col;
typedef struct { u8 pad[0x14]; f32 x14; } A;
typedef struct { u8 pad[8]; f32 x8; } B;
extern f32 D_00201D5C;
extern FW D_004A28D0[];
extern s32 D_00201D48;
extern s32 *D_00201D4C;
extern f32 D_00201D54;
extern f32 D_00201D58;
extern s32 D_002021B4;
extern f32 D_002021B8;
extern f32 D_002021BC;
extern s32 D_004A28C0[];
extern s32 D_004A28C4[];
extern Q2 D_001F3040;
extern s32 D_002021AC;
extern s32 D_004A28C8[];
extern f32 D_004A28CC[];
extern s32 D_002021B0;
extern f32 *D_00201D50;
void func_00199190(u8 *arg0);
void func_00199260(O *o, f32 f);
void func_001997A0(s32 *arg0);
void func_00199AD0(S *a0);
void func_0019A0D0(s32 arg0);
void func_0019A1D0(s32 arg0);
void func_0019A370(u16 *a0, u16 *a1, void *a2, void *a3, s32 t0);
void func_0019A500(s32 a0, s32 a1, u32 *a2, u32 *a3, u32 *t0, s32 t1, s32 t2, s32 t3);
void func_0019A6A0(s32 i, A *a, B *b);
void func_0018A310(s32);
f32 func_00187770(f32, f32, f32);
void func_0017F5C0(void);
s8* func_001C9BA0(void);
s8* func_001C9B60(void);
s32 func_001C9BF0(void);
void func_00186440(f32, H *, H *, H *, H *);
void func_00185B30(s32, s32);
void func_00185510(f32, s8 *);
void func_00185B40(f32, s8 *);
void func_00185390(f32, s32, s32, s32);
void func_001DD7F0(s32, s32, f32);
void func_001DF360(s32, s32);
void func_00184DF0(s32, f32);
void func_00184040(s32, f32);
void func_00184960(s8 *, f32);
s16 func_001CCD90(s32);
void func_001DF470(f32, s32);
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_00183DC0(s32 *);
void func_001833E0(s32, s32);
void func_001CEDC0(s32);
void func_001DF460(void);
void func_0019D510(void);
void func_00131600(s32, u8);
void func_001803D0(s32, s32);
void func_001803B0(s32, s32);
s32 func_00195B80(s32, s32 *);
s32 func_001AFBD0(s32);
void func_001CCF00(s32, s32);
void func_001CEA50(s32);
u8* func_001CC3F0(s16);
void func_001CCE30(void);
void* func_001AFC90(void);
s32 func_00187130(s32, s32);
void memset(void *, s32, s32);
s32 func_00195BE0(s32);
s32 func_0019DE30(s32);
void func_001CCF50(Ids *, s32, s16);
u8* func_001A97D0(s16);
void func_001CF480(s32, s32, s32, s32, Ids *, Col *, s32);
u32 func_001D1170(void);
u16 func_001D1110(s32);
u16 func_001D10B0(s32);
void func_0017F840(s32, s32 *);

/* func_00199190 */
#define func_00199260 func_00199260__as_func_00199190
void func_00199260__as_func_00199190(u8 *, f32);

void func_00199190(u8 *arg0) {
    func_0018A310(-1);
    if (arg0[8] == 0x16) {
        D_00201D5C = func_00187770(D_00201D5C, -0.02f, 3.5f);
    } else {
        D_00201D5C = func_00187770(D_00201D5C, -2.99f, 3.5f);
    }
    if (!D_004A28D0[0].f.f.b3) {
        func_0017F5C0();
    }
    if (!(D_00201D5C <= -2.99f)) {
        func_00199260(arg0, D_00201D5C);
    }
}
#undef func_00199260

/* func_00199260 */
#define func_0019A370 func_0019A370__as_func_00199260
void func_0019A370__as_func_00199260(H *, H *, H *, H *, s32);
#define func_0019A500 func_0019A500__as_func_00199260
void func_0019A500__as_func_00199260(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);

void func_00199260(O *o, f32 f) {
    s32 eC;
    s32 e8;
    s32 e4;
    s32 e0;
    s32 dC;
    H c0;
    H b0;
    H a0;
    H x90;
    H x80;
    H x70;
    s8 *s3;
    s8 *s2;
    s8 *s1;
    s32 id;
    s32 i;

    s3 = func_001C9BA0();
    s2 = func_001C9BA0();
    s1 = func_001C9B60();
    id = D_00201D4C[D_004A28C0[0]];
    if (D_002021B4 <= 0) id = -1;
    if (o->x8 == 0x16) {
        if (D_004A28D0[0].f.f.b3) {
            D_00201D54 = func_00187770(D_00201D54, -0.02f, 3.5f);
            D_00201D58 = func_00187770(D_00201D58, -2.99f, 3.5f);
        } else {
            D_00201D54 = func_00187770(D_00201D54, -2.99f, 3.5f);
            D_00201D58 = func_00187770(D_00201D58, -0.02f, 3.5f);
        }
    } else {
        D_00201D54 -= (D_00201D54 - -2.99f) / 3.5f;
        D_00201D58 -= (D_00201D58 - -2.99f) / 3.5f;
    }
    func_001DD7F0(id, -1, D_00201D54);
    func_001DF360(D_004A28D0[0].f.f.b3, id);
    func_00184DF0(D_00201D48, -D_00201D58 / 2.0f);
    func_00184040(id, D_00201D58);
    func_00184960(s3 + 0x80, -D_00201D58 / 2.0f);
    if (D_004A28D0[0].f.f.b2) {
        func_0019A370(&a0, &x90, &x80, &x70, id);
        func_00186440(f, &a0, &x90, &x80, &x70);
        func_00185B30(0, 0);
    } else {
        if (func_001C9BF0()) func_0019A500(&c0, &b0, &eC, &e8, &e4, -1, -1, 0);
        if (D_002021B4 <= 0) func_0019A500(&x80, &x70, &eC, &e0, &dC, -1, -1, 0);
        else func_0019A500(&x80, &x70, &eC, &e0, &dC, D_00201D48, id, 0);
        for (i = 0; i < 8; i++) {
            x80.v[7 - i] -= c0.v[7 - i];
            x70.v[7 - i] -= b0.v[7 - i];
        }
        if (id == func_001CCD90(D_00201D48)) {
            func_00185B30(0, 0);
            func_00186440(f, &c0, &b0, 0, 0);
        } else {
            func_00185B30(e0 - e8, dC - e4);
            func_00186440(f, &c0, &b0, &x80, &x70);
        }
    }
    func_00185510(f, s2);
    func_00185B40(f, s1);
    if (D_004A28C4[0] == 1) D_002021BC = 10.0f;
    if (!(D_002021BC <= 0.0f)) {
        D_002021BC -= 1.0f;
        D_002021B8 = func_00187770(D_002021B8, -2.99f, 3.5f);
    } else {
        D_002021B8 = func_00187770(D_002021B8, -0.02f, 3.5f);
    }
    func_00185390(f + D_002021B8, 1, D_002021B4, D_004A28C0[0]);
    func_001DF470(f + D_002021B8, D_00201D48);
}
#undef func_0019A370
#undef func_0019A500

/* func_001997A0 */
#define func_0017F470 func_0017F470__as_func_001997A0
void func_0017F470__as_func_001997A0(f32, s32, s32);
#define func_00199AD0 func_00199AD0__as_func_001997A0
void func_00199AD0__as_func_001997A0(s32 *);
#define func_0019A6A0 func_0019A6A0__as_func_001997A0
void func_0019A6A0__as_func_001997A0(void);
#define D_00201D4C D_00201D4C__as_func_001997A0
extern s32 **D_00201D4C__as_func_001997A0;
static inline void setup_func_001997A0(void) {
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

void func_001997A0(s32 *arg0) {
    s32 *p;
    s32 i;

    p = D_00201D4C[D_004A28C0[0]];
    if (D_004A28CC[0] > 0.0f) {
        D_004A28CC[0] -= 1.0f;
        D_004A28D0[0].f.f.b1 = 0;
    } else {
        switch (D_004A28C4[0]) {
        case 1:
            func_0017F7C0(D_00201D48, 0, 1);
            D_004A28C0[0] = 0;
            D_00201D48 = D_004A28C8[0];
            func_0019A1D0(D_00201D48);
            setup_func_001997A0();
        }
        D_004A28C4[0] = 0;
        D_004A28C8[0] = 0;
        D_004A28D0[0].f.f.b1 = 1;
    }
    func_00183DC0(p);
    for (i = 0; i < 10; i++) {
        func_001833E0(func_001CCD90(i), i);
    }
    switch (*arg0) {
    case 0x19:
        D_004A28C0[0] = 0;
        D_004A28D0[0].w = 0;
        func_0019A1D0(D_00201D48);
        func_001CEDC0(3);
        for (i = 0; i < 10; i++) {
            func_001833E0(func_001CCD90(i), i);
        }
        setup_func_001997A0();
        func_001DF460();
        D_004A28D0[0].f.f.b1 = 1;
        func_0019A0D0(0);
        break;
    case 0x16:
        if (D_004A28D0[0].f.f.b1) {
            func_00199AD0(arg0);
        }
        break;
    }
}
#undef func_0017F470
#undef func_00199AD0
#undef func_0019A6A0
#undef D_00201D4C

/* func_00199AD0 */
#define func_0019A6A0 func_0019A6A0__as_func_00199AD0
void func_0019A6A0__as_func_00199AD0(void);
#define D_00201D4C D_00201D4C__as_func_00199AD0
extern s32 **D_00201D4C__as_func_00199AD0;
static inline void setup_func_00199AD0(void) {
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
#undef func_0019A6A0
#undef D_00201D4C

/* func_0019A0D0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_004A18C0[0x63];
#define func_0019D510 func_0019D510__as_func_0019A0D0
s32 func_0019D510__as_func_0019A0D0(s32);
#define func_001803B0 func_001803B0__as_func_0019A0D0
void func_001803B0__as_func_0019A0D0(s32 *, s32);

void func_0019A0D0(s32 arg0) {
    s32 i;

    for (i = 99; i >= 0; i--) {
        D_004A18C0[i] = 0;
    }
    for (i = 100; i < 0x400; i++) {
        func_001AFC90();
        D_004A18C0[i] = 0;
        if (func_0019D510(i) && func_00187130(i, arg0)) {
            D_004A18C0[i] = 1;
        }
    }
    func_001803B0(D_004A18C0, 0);
}
#undef func_0019D510
#undef func_001803B0

/* func_0019A1D0 */
#define func_001CC3F0 func_001CC3F0__as_func_0019A1D0
P *func_001CC3F0__as_func_0019A1D0(s16);
#define func_001AFC90 func_001AFC90__as_func_0019A1D0
E_func_0019A1D0 *func_001AFC90__as_func_0019A1D0(void);

void func_0019A1D0(s32 arg0) {
    s32 i;
    E_func_0019A1D0 *base;
    P *p;
    E_func_0019A1D0 *e;
    s32 v;

    base = func_001AFC90();
    D_002021B4 = 0;
    memset(D_00201D4C, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        p = func_001CC3F0(func_00195BE0(i));
        if (!(p->x2 > 0)) {
            if (func_0019DE30(func_00195BE0(i)) == 0) {
                continue;
            }
            if (!(p->x3 > 0)) {
                continue;
            }
        }
        e = &base[func_00195BE0(i)];
        if (arg0 < 2 && e->xA != 2) {
            continue;
        }
        if (!(arg0 < 2) && arg0 < 9) {
            if (e->xA != 1) {
                continue;
            }
            if (e->x20 != arg0 - 2) {
                continue;
            }
        }
        if (arg0 == 9) {
            if (e->xA != 0) {
                continue;
            }
            if (func_00195BE0(i) == 0) {
                continue;
            }
        }
        v = func_00195BE0(i);
        D_00201D4C[D_002021B4] = v;
        if (v == func_001CCD90(arg0)) {
            D_004A28C0[0] = D_002021B4;
        }
        D_002021B4++;
    }
}
#undef func_001CC3F0
#undef func_001AFC90

/* func_0019A370 */
#define func_001AFC90 func_001AFC90__as_func_0019A370
extern u8 *func_001AFC90__as_func_0019A370(void);

void func_0019A370(u16 *a0, u16 *a1, void *a2, void *a3, s32 t0) {
    u8 *e = func_001AFC90() + t0 * 0x90;
    memset(a1, 0, 0x10);
    memset(a0, 0, 0x10);
    memset(a3, 0, 0x10);
    memset(a2, 0, 0x10);
    if (t0 >= 0) {
        switch (func_001AFBD0(t0)) {
        case 1:
            a0[0] = *(u16 *)(e + 0x2C); a0[1] = *(u16 *)(e + 0x2E);
            a0[2] = *(u16 *)(e + 0x30); a0[3] = *(u16 *)(e + 0x32);
            a0[4] = *(u16 *)(e + 0x34); a0[5] = *(u16 *)(e + 0x36);
            a0[6] = *(u16 *)(e + 0x38); a0[7] = *(u16 *)(e + 0x3A);
            a1[0] = *(u16 *)(e + 0x4A); a1[1] = *(u16 *)(e + 0x4C);
            a1[2] = *(u16 *)(e + 0x4E); a1[3] = *(u16 *)(e + 0x50);
            a1[4] = *(u16 *)(e + 0x52); a1[5] = *(u16 *)(e + 0x54);
            break;
        case 2:
            a1[0] = *(u16 *)(e + 0x30); a1[1] = *(u16 *)(e + 0x32);
            a1[2] = *(u16 *)(e + 0x34); a1[3] = *(u16 *)(e + 0x36);
            a1[4] = *(u16 *)(e + 0x38); a1[5] = *(u16 *)(e + 0x3A);
            break;
        }
    }
}
#undef func_001AFC90

/* func_0019A500 */
void func_0019A500(s32 a0, s32 a1, u32 *a2, u32 *a3, u32 *t0, s32 t1, s32 t2, s32 t3) {
    s8 *base;
    s32 i;
    Ids ids;
    Col col[10];

    base = func_001C9BA0();
    ids = *(Ids *)(base + 0x80);
    memset(col, 0, 0x28);
    if (t1 >= 0) {
        func_001CCF50(&ids, t1, t2);
    }
    for (i = 0; i < 10; i++) {
        if (ids.v[i] != -1) {
            col[i] = *(Col *)(base + 0xA0 + ids.v[i] * 4);
            if (i == t1 && t3 != 0) {
                col[i].b[0] = *func_001A97D0(ids.v[i]);
            }
        }
    }
    func_001CF480(a0, 0, a1, 0, &ids, col, 3);
    *a2 = func_001D1170();
    *a3 = func_001D1110(a0);
    *t0 = func_001D10B0(a0);
}

/* func_0019A6A0 */
void func_0019A6A0(s32 i, A *a, B *b) {
    s32 t;
    func_0017F840(D_00201D48, &t);
    switch (D_002021AC) {
    case 0:
        a->x14 = b->x8 - (f32)i;
        break;
    case 2:
        if (i >= D_004A28C0[0] - 3 && i <= D_004A28C0[0] + 3) {
            a->x14 = D_00201D50[i] = b->x8 - (f32)i;
        } else {
            a->x14 = D_00201D50[i] = -5.0f;
        }
        break;
    }
}
