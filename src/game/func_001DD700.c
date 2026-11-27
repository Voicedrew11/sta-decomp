#include "common.h"
#include "m2c.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C;
typedef struct { u8 a:3; u8 c:1; u8 d:1; u8 e:3; } BF;
typedef struct {
    f32 x0;
    f32 x4;
    BF x8;
    u8 pad9[3];
    s16 xC;
    u8 padE[6];
    f32 x14;
    u8 pad18[8];
    f32 x20;
    f32 x24;
    s8 *x28;
    u8 pad2C[0x10];
} T;
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent_func_001DD7F0;
typedef struct { u32 n; Ent_func_001DD7F0 *p; } L_func_001DD7F0;
typedef struct { u8 pad[0x28]; L_func_001DD7F0 *l; } O_func_001DD7F0;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; u8 b[4]; } Col_func_001DDA20;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; u8 a[0x10]; u8 b[0x10]; } Q;
typedef struct { u8 pad[0x54]; Q *q54; u8 pad58[4]; Q *q5C; } R_func_001DDA20;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[4]; u16 xA; u8 padC[0x14]; u16 x20; u8 pad22[0x1A]; u8 x3C; u8 rest[0x53]; } E_func_001DDA20;
typedef struct { u8 pad[0x10]; u8 p10[0x18]; s32 x28; u8 c[4]; f32 x30, x34, x38, x3C; } O_func_001DDA20;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent_func_001DE0D0;
typedef struct { u32 n; Ent_func_001DE0D0 *p; } L_func_001DE0D0;
typedef struct { u8 pad[0x4]; L_func_001DE0D0 *l; } O_func_001DE0D0;
typedef union { u32 w; s8 b[4]; } Col_func_001DE2D0;
typedef struct { u8 pad0[0x10]; u8 x10[0x18]; s32 x28; u8 x2C[4]; f32 x30; f32 x34; f32 x38; f32 x3C; } O_func_001DE2D0;
typedef struct { u8 p0[4]; u16 x4; u8 x6; u8 p7[3]; u16 xA; u8 pC[0x14]; u16 x20; u8 p22[0x1A]; u8 x3C; u8 p3D[0x53]; } E_func_001DE2D0;
typedef struct { s32 x0; s32 x4; u8 p8[8]; u8 x10[0x10]; u8 x20[0x10]; } R_func_001DE2D0;
typedef struct { u8 p0[0x300]; R_func_001DE2D0 r[2]; } Rs;
typedef struct { u8 p0[0x54]; Rs *x54; u8 p58[4]; Rs *x5C; } G_func_001DE2D0;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xB]; s8 b3F; } Ent_func_001DEB00;
typedef struct { u32 n; Ent_func_001DEB00 *p; } L_func_001DEB00;
typedef struct { L_func_001DEB00 *l; } O_func_001DEB00;
typedef union { u32 w; u8 b[4]; } Col_func_001DED50;
typedef struct { s32 x0; s32 x4; u8 pad[8]; s8 x10[0x10]; s8 x20[0x10]; } E_func_001DED50;
typedef struct { u8 p0[0x34]; E_func_001DED50 *x34; } G_func_001DED50;
typedef struct { u8 p0[0x10]; s8 x10[0x18]; s32 x28; Col_func_001DED50 c; f32 x30, x34, x38, x3C; } O_func_001DED50;
extern s32 D_00201E50;
extern f32 D_002020D4;
extern f32 D_00202360;
extern s32 D_00202378;
extern S D_001F3A90[] __attribute__((aligned(16)));
extern S D_001F3AB0[] __attribute__((aligned(16)));
extern s8 D_001FE748[];
extern s8 D_001FE750[];
extern s8 D_001FE758[];
extern s8 D_001FE760[];
extern s8 D_001FE768[];
extern s32 D_004BABB0[];
extern s32 D_004BABC8[];
extern s8 D_004BABE0[];
extern f32 D_004BABF4[];
extern f32 D_004BABF8[];
extern f32 D_004BAC0C[];
extern f32 D_004BAC10[];
extern u32 D_004BAC1C[];
extern S D_001F3A70 __attribute__((aligned(16)));
extern char D_004BAA70[];
extern u8 D_004BAB70[];
extern f32 D_004BAB84[];
extern f32 D_004BAB88[];
extern f32 D_004BAB9C[];
extern f32 D_004BABA0[];
extern u32 D_004BABAC[];
extern s32 D_0020237C;
extern S D_001F3A50[] __attribute__((aligned(16)));
extern f32 D_0020235C;
extern f32 D_00202364;
extern f32 D_00202368;
extern f32 D_0020236C;
extern f32 D_00202370;
void func_001DD700(s32 a0, s32 a1);
void func_001DD7F0(s32 arg, s32 arg1, f32 ang);
void func_001DDA20(O_func_001DDA20 *o, s32 kind, u32 id, s32 a3);
void func_001DE0D0(s32 arg, f32 ang);
void func_001DE2D0(O_func_001DE2D0 *o, s32 a1, u32 mode, s32 id);
void func_001DEB00(s32 arg, s32 arg1, f32 ang);
void func_001DED50(O_func_001DED50 *o, s32 sel, u32 id, u32 n);
u32 strlen(void *);
void func_00187A90(void *, void *, u64);
s32 func_00188010(void *, C);
void func_00187B20(s32);
s8* func_00195B10(s32);
O_func_001DD7F0* func_00189050(s32);
s8* func_00189020(s32);
f32 func_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void func_001829B0(void *, s8*, void (*)(void), s32);
void func_00181680(s32, void *, void *, void*, S*, s32);
void func_00183650(void *);
void func_001848A0(s32);
s32 func_00187130(s32, s32);
void func_001875C0(s8 *, s32, Col_func_001DDA20, f32, f32, f32);
u8* func_001A97D0(s32);
s32 func_001AFBD0(s32);
E_func_001DDA20* func_001AFC90(void);
u8* func_001CC3F0(s32);
s32 sprintf(void *, void *, ...);
s8* strcpy(s8 *, s8 *);
f64 fptodp(f32);
void func_00187960(f32, void *);
s16 func_001CBA30(void);

/* func_001DD700 */
void func_001DD700(s32 a0, s32 a1) {
    C col;
    T t;
    s8 *s;
    col.w = 0x80808080;
    a0 += a1;
    if (D_00201E50 != a0) {
        D_00201E50 = a0;
        D_00202360 = D_002020D4;
    }
    s = func_00195B10(a0 + 0x12C);
    if (s == 0) {
        return;
    }
    func_00187A90(&t, s, strlen(s));
    t.x0 = 622.0f;
    t.x4 = 415.0f;
    t.x8.a = 2;
    t.x24 = 1.0f;
    t.x20 = 0.7f;
    t.x14 = 3.0f * (D_002020D4 - D_00202360);
    func_00188010(&t, col);
    func_00187B20(1);
}

/* func_001DD7F0 */
#define func_001DDA20 func_001DDA20__as_func_001DD7F0
void func_001DDA20__as_func_001DD7F0(void);
#define func_001829B0 func_001829B0__as_func_001DD7F0
void func_001829B0__as_func_001DD7F0(Ent_func_001DD7F0 *, s8 *, void (*)(void), s32);

void func_001DD7F0(s32 arg, s32 arg1, f32 ang) {
    u32 i;
    L_func_001DD7F0 *l;
    s8 *base;
    Ent_func_001DD7F0 e;
    V2 q;
f32 d, a, t, dx, dy;
    l = func_00189050(2)->l;
    base = func_00189020(2);
    func_00187B20(0);
    if (arg1 == -1) {
        D_00202378 = -1;
    } else {
        D_00202378 = arg1;
    }
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang / 2.0f;
        e.x = 735.0f + d * sinf(a);
        e.y = 129.0f + d * cosf(a);
        }
        func_001829B0(&e, base + l->p[i].idx * 8, func_001DDA20, arg);
    }
}
#undef func_001DDA20
#undef func_001829B0

/* func_001DDA20 */
// mwcc=mwcps2-3.0b38-030307
/* MATCH with mwccps2 3.0b38 (addi range check); case 0x12E: ((volatile O_func_001DDA20 *)o)->x38 fixes lwc1/lw order */
#define func_00189020 func_00189020__as_func_001DDA20
R_func_001DDA20 *func_00189020__as_func_001DDA20(s32);
#define sprintf sprintf__as_func_001DDA20
s32 sprintf__as_func_001DDA20(s8 *, s8 *, ...);

static inline f32 u2f_func_001DDA20(u32 x) { return x; }

void func_001DDA20(O_func_001DDA20 *o, s32 kind, u32 id, s32 a3) {
    s8 buf[256];
    S t __attribute__((aligned(16)));
    Col_func_001DDA20 col;
    s32 n = (s16)a3;
    Q *q;
    s32 flag;
    E_func_001DDA20 *e;
    s32 v;

    t = D_001F3A90[0];
    if (id < 300) {
        t.x = o->x30;
        t.y = o->x34;
        if (id == 0) {
            o->c[0] = 0x40;
            o->c[1] = 0x40;
            o->c[2] = 0x40;
        }
        func_00181680(o->x28, o, (u8 *)o + 0x10, o->c, &t, id);
        return;
    }
    switch (id) {
    case 300: {
        S t2 __attribute__((aligned(16)));
        t2 = D_001F3AB0[0];
        q = &func_00189020(0)->q54[kind + 15];
        col.w = 0x30808080;
        t2.x = o->x38;
        t2.y = o->x3C;
        func_00181680(q->x4, q->a, q->b, &col, &t2, id);
        break;
    }
    case 301:
        q = &func_00189020(0)->q5C[kind + 15];
        col.w = 0x30808080U;
        t.m[0] = 1.1f;
        t.m[3] = 1.0f;
        t.x = o->x38 - 5.0f;
        t.y = o->x3C - 4.0f;
        func_00181680(q->x4, q->a, q->b, &col, &t, id);
        break;
    }
    switch (kind) {
    case 0:
        switch (id) {
        case 10001:
            D_004BAC0C[0] = o->x38;
            D_004BAC10[0] = o->x3C;
            D_004BABF8[0] = D_004BABF4[0] = 1.25f;
            D_004BAC1C[0] = 0x80FFFFFF;
            func_00183650(D_004BABE0);
            break;
        }
        break;
    case 1:
        switch (id) {
        case 0x12F:
            if (n > 0) {
                v = 0;
                flag = 0;
                if (n != D_004BABB0[kind]) {
                    D_004BABC8[kind] = 0;
                    D_004BABB0[kind] = n;
                }
                if (D_004BABC8[kind] < 0x80)
                    D_004BABC8[kind] += 0x10;
                col.w = 0x80808080;
                switch (D_00202378) {
                case 0:
                    break;
                case 1:
                case 4:
                    v = *func_001A97D0(n);
                    flag = 1;
                    break;
                case -1:
                case 2:
                case 3:
                case 5:
                case 6:
                    v = *func_001CC3F0(n);
                    flag = 0;
                    break;
                }
                sprintf(buf, D_001FE748, v);
                if (func_001AFBD0(n) == 0) {
                    strcpy(buf, D_001FE750);
                } else if (func_001AFBD0(n) == 1) {
                    e = &func_001AFC90()[(s16)n];
                    switch (e->x20) {
                    case 5:
                    case 6:
                        strcpy(buf, D_001FE750);
                        break;
                    default:
                        func_001848A0(n);
                        break;
                    }
                } else {
                    func_001848A0(n);
                }
                if (func_00187130(n, flag))
                    col.w = 0x80404080;
                else
                    col.w = 0x80808080;
                func_001875C0(buf, 2, col, o->x38, o->x3C, 0.9f);
            }
            break;
        case 0x130:
            v = 0;
            if ((s16)n > 0) {
                e = &func_001AFC90()[a3];
                if (e->xA == 1) {
                    v = e->x3C;
                    switch (e->x20) {
                    case 5:
                    case 6:
                        v = 0;
                        break;
                    }
                } else if (e->xA == 2) {
                    v = e->x3C;
                }
                col.w = 0x80808080;
                if (v == 0)
                    strcpy(buf, D_001FE758);
                else
                    sprintf(buf, D_001FE760, v);
                func_001875C0(buf, 0, col, o->x38, o->x3C, 0.8f);
            }
            break;
        }
        break;
    case 2:
        switch (id) {
        case 0x12E:
            if ((s16)n > 0) {
                E_func_001DDA20 *e2 = &func_001AFC90()[a3];
                if (n != D_004BABB0[kind]) {
                    D_004BABC8[kind] = 0;
                    D_004BABB0[kind] = n;
                }
                if (D_004BABC8[kind] < 0x80)
                    D_004BABC8[kind] += 0x10;
                col.w = 0x80808080;
                sprintf(buf, D_001FE768, (double)(u2f_func_001DDA20(e2->x4) / 10.0f));
                func_001875C0(buf, 2, col, ((volatile O_func_001DDA20 *)o)->x38, o->x3C, 0.9f);
            }
            break;
        }
        break;
    }
}
#undef func_00189020
#undef sprintf

/* func_001DE0D0 */
#define func_00189050 func_00189050__as_func_001DE0D0
O_func_001DE0D0 *func_00189050__as_func_001DE0D0(s32);
#define func_001DE2D0 func_001DE2D0__as_func_001DE0D0
void func_001DE2D0__as_func_001DE0D0(void);
#define func_001829B0 func_001829B0__as_func_001DE0D0
void func_001829B0__as_func_001DE0D0(Ent_func_001DE0D0 *, s8 *, void (*)(void), s32);

void func_001DE0D0(s32 arg, f32 ang) {
    u32 i;
    L_func_001DE0D0 *l;
    s8 *base;
    Ent_func_001DE0D0 e;
    V2 q;
f32 d, a, t, dx, dy;
    l = func_00189050(6)->l;
    base = func_00189020(6);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang;
        e.x = 735.0f + d * sinf(a);
        e.y = 129.0f + d * cosf(a);
        }
        func_001829B0(&e, base + l->p[i].idx * 8, func_001DE2D0, arg);
    }
}
#undef func_00189050
#undef func_001DE2D0
#undef func_001829B0

/* rodata_001FE790 */
/* rodata_001FE790: the game's data at 0x001FE790..., one object per label. */
/* used by: func_001DE2D0, func_001DED50, text_001DE2D0.s */
#pragma explicit_zero_data on

const char D_001FE790[0x5] __attribute__((aligned(16))) = "/%3d\000";
const s32 D_001FE798[0x2] = { 0x43, 0 };
const s32 D_001FE7A0[0x4] = { 0x6425, 0, 0, 0 };
#pragma explicit_zero_data reset

/* func_001DE2D0 */
/* round 3 near-miss: 6 words: lw a2 (Col_func_001DE2D0 stack arg) vs lwc1 f12 order before func_001875C0, 3 sites */
#define D_00202378 D_00202378__as_func_001DE2D0
extern u32 D_00202378__as_func_001DE2D0;
#define D_001FE748 D_001FE748__as_func_001DE2D0
extern char D_001FE748__as_func_001DE2D0[];
#define D_001FE750 D_001FE750__as_func_001DE2D0
extern char D_001FE750__as_func_001DE2D0[];
#define D_001FE758 D_001FE758__as_func_001DE2D0
extern char D_001FE758__as_func_001DE2D0[];
#define D_001FE768 D_001FE768__as_func_001DE2D0
extern char D_001FE768__as_func_001DE2D0[];
#define D_001FE790 D_001FE790__as_func_001DE2D0
extern char D_001FE790__as_func_001DE2D0[];
#define D_001FE798 D_001FE798__as_func_001DE2D0
extern char D_001FE798__as_func_001DE2D0[];
#define D_001FE7A0 D_001FE7A0__as_func_001DE2D0
extern char D_001FE7A0__as_func_001DE2D0[];
#define func_00181680 func_00181680__as_func_001DE2D0
void func_00181680__as_func_001DE2D0(s32, void *, void *, void *, S *, u32);
#define func_001875C0 func_001875C0__as_func_001DE2D0
void func_001875C0__as_func_001DE2D0(char *, s32, Col_func_001DE2D0, f32, f32, f32);
#define func_00189020 func_00189020__as_func_001DE2D0
G_func_001DE2D0 *func_00189020__as_func_001DE2D0(s32);
#define func_001A97D0 func_001A97D0__as_func_001DE2D0
u8 *func_001A97D0__as_func_001DE2D0(s16);
#define func_001CC3F0 func_001CC3F0__as_func_001DE2D0
u8 *func_001CC3F0__as_func_001DE2D0(s16);
#define func_001AFC90 func_001AFC90__as_func_001DE2D0
E_func_001DE2D0 *func_001AFC90__as_func_001DE2D0(void);
#define sprintf sprintf__as_func_001DE2D0
s32 sprintf__as_func_001DE2D0(char *, const char *, ...);
#define strcpy strcpy__as_func_001DE2D0
char *strcpy__as_func_001DE2D0(char *, const char *);
static inline f32 u2f_func_001DE2D0(u32 x) { return x; }

void func_001DE2D0(O_func_001DE2D0 *o, s32 a1, u32 mode, s32 id) {
    S buf __attribute__((aligned(16)));
    Col_func_001DE2D0 c0;
    Col_func_001DE2D0 cA;
    Col_func_001DE2D0 c9;
    Col_func_001DE2D0 c1;
    Col_func_001DE2D0 cE;
    Col_func_001DE2D0 cD;
    u32 s;
    buf = D_001F3A70;
    c0.w = 0x80808080;
    if ((u32)(mode - 1000) <= 1 || mode == 1002) {
        switch (D_00202378) {
        case 2: case 3: case 4: case 5: case 6:
            return;
        }
    }
    if (mode < 600) {
        buf.x = o->x30;
        buf.y = o->x34;
        if (mode == 0) {
            o->x2C[0] = 0x40;
            o->x2C[1] = 0x40;
            o->x2C[2] = 0x40;
        }
        func_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 0x259:
        break;
    case 0x25A:
        break;
    case 0x25B: {
        R_func_001DE2D0 *r;
        Rs *q = func_00189020(0)->x54;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[0];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x25C: {
        R_func_001DE2D0 *r;
        Rs *q = func_00189020(0)->x5C;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[0];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x25D:
        if (id > 0) {
            f32 f;
            s32 m;
            func_001848A0(id);
            m = 0;
            switch (D_00202378) {
            case 1:
            case 4:
                f = u2f_func_001DE2D0(*func_001A97D0(id));
                m = 1;
                break;
            case 2:
            case 3:
            case 5:
            case 6:
                f = u2f_func_001DE2D0(*func_001CC3F0(id));
                m = 0;
                break;
            case 0:
                break;
            }
            if (func_00187130(id, m) != 0) {
                cD.w = 0x80404080;
            } else {
                cD.w = 0x80808080;
            }
            sprintf(D_004BAA70, D_001FE748, (s32)f);
            if (func_001AFBD0(id) == 0) {
                strcpy(D_004BAA70, D_001FE750);
            } else if (func_001AFBD0(id) == 1) {
                E_func_001DE2D0 *e = &func_001AFC90()[id];
                switch (e->x20) {
                case 5:
                case 6:
                    strcpy(D_004BAA70, D_001FE750);
                    break;
                }
            }
            func_001875C0(D_004BAA70, 0, cD, ((volatile O_func_001DE2D0 *)o)->x38, o->x3C, 0.9f);
        }
        break;
    case 0x25E:
        if (id > 0) {
            s32 v = 0;
            E_func_001DE2D0 *e = &func_001AFC90()[id];
            if (e != NULL && id != -1) {
                if (e->xA == 1) {
                    e = &func_001AFC90()[id];
                    switch (e->x20) {
                    case 5:
                    case 6:
                        v = 0;
                        break;
                    default:
                        v = e->x3C;
                        break;
                    }
                } else if (e->xA == 2) {
                    v = e->x3C;
                }
                cE.w = 0x80808080;
                if (v == 0) {
                    strcpy(D_004BAA70, D_001FE758);
                } else {
                    sprintf(D_004BAA70, D_001FE790, v);
                }
                func_001875C0(D_004BAA70, 0, cE, ((volatile O_func_001DE2D0 *)o)->x38, o->x3C, 0.9f);
                return;
            }
        }
        break;
    case 0x25F: {
        R_func_001DE2D0 *r;
        Rs *q = func_00189020(0)->x54;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[1];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x260: {
        R_func_001DE2D0 *r;
        Rs *q = func_00189020(0)->x5C;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[1];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x261:
        if (id > 0) {
            E_func_001DE2D0 *e = &func_001AFC90()[id];
            c1.w = 0x80808080;
            sprintf(D_004BAA70, D_001FE768, fptodp(u2f_func_001DE2D0(e->x4) / 10.0f));
            func_001875C0(D_004BAA70, 0, c1, ((volatile O_func_001DE2D0 *)o)->x38, o->x3C, 0.9f);
            return;
        }
        break;
    case 0x2711:
        D_004BAB9C[0] = o->x38;
        D_004BABA0[0] = o->x3C;
        D_004BAB84[0] = 1.0f;
        D_004BABAC[0] = 0x80FFFFFF;
        D_004BAB88[0] = 1.0f;
        func_00183650(D_004BAB70);
        return;
    case 0x3E8:
        buf.x = o->x30;
        buf.y = o->x34;
        func_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    case 0x3E9: {
        c9.w = 0x80808080;
        func_001875C0(D_001FE798, 2, c9, ((volatile O_func_001DE2D0 *)o)->x38, o->x3C, 0.9f);
        return;
    }
    case 0x3EA:
        if (id > 0) {
            E_func_001DE2D0 *e = &func_001AFC90()[id];
            u8 *r = func_001A97D0(id);
            cA.w = 0x80808080;
            if (r[5] == 2) {
                sprintf(D_004BAA70, D_001FE7A0, 5);
            } else {
                sprintf(D_004BAA70, D_001FE7A0, e->x6);
            }
            func_001875C0(D_004BAA70, 2, cA, ((volatile O_func_001DE2D0 *)o)->x38, o->x3C, 0.9f);
            return;
        }
        sprintf(D_004BAA70, D_001FE750);
        func_001875C0(D_004BAA70, 2, c0, ((volatile O_func_001DE2D0 *)o)->x38, o->x3C, 0.9f);
        break;
    }
}
#undef func_00181680
#undef func_001875C0
#undef func_00189020
#undef func_001A97D0
#undef func_001CC3F0
#undef func_001AFC90
#undef sprintf
#undef strcpy
#undef D_00202378
#undef D_001FE748
#undef D_001FE750
#undef D_001FE758
#undef D_001FE768
#undef D_001FE790
#undef D_001FE798
#undef D_001FE7A0

/* func_001DEB00 */
#define func_00189050 func_00189050__as_func_001DEB00
O_func_001DEB00 *func_00189050__as_func_001DEB00(s32);
#define func_001DED50 func_001DED50__as_func_001DEB00
void func_001DED50__as_func_001DEB00(void);
#define func_001829B0 func_001829B0__as_func_001DEB00
void func_001829B0__as_func_001DEB00(Ent_func_001DEB00 *, s8 *, void (*)(void), s32);

void func_001DEB00(s32 arg, s32 arg1, f32 ang) {
    u32 i;
    L_func_001DEB00 *l;
    s8 *base;
    Ent_func_001DEB00 e;
    V2 q;
f32 d, a, t, dx, dy;
    s32 c;
    l = func_00189050(6)->l;
    base = func_00189020(6);
    func_00187B20(0);
    D_00202378 = arg1;
    D_0020237C = arg;
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
            p.x = 108.0f;
            p.y = 72.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 108.0f;
        dy = e.y - 72.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = func_00187460(&q, &p);
        a = t + ang;
        c = (s32)(256.0f * (ang / -2.99f)) + 0x80;
        if (c < 0) c = 0;
        if (c > 0x80) c = 0x80;
        e.b3F = c;
        e.x = 108.0f + d * sinf(a);
        e.y = 72.0f + d * cosf(a);
        }
        func_001829B0(&e, base + l->p[i].idx * 8, func_001DED50, arg);
    }
}
#undef func_00189050
#undef func_001DED50
#undef func_001829B0

/* rodata_001FE7CC */
/* rodata_001FE7CC: the game's data at 0x001FE7CC..., one object per label. */
/* used by: func_001DED50 */
#pragma explicit_zero_data on

const s32 D_001FE7CC[0x1] = { 0 };
const s8 D_001FE7D0[0x8] __attribute__((aligned(4))) = "BUY\000\000\000\000\000";
const s8 D_001FE7D8[0x5] __attribute__((aligned(4))) = "SELL\000";
const s8 D_001FE7E0[0x8] __attribute__((aligned(4))) = "PUT\000\000\000\000\000";
const s8 D_001FE7E8[0x5] __attribute__((aligned(4))) = "DRAW\000";
const s8 D_001FE7F0[0x8] __attribute__((aligned(4))) = "HEALING\000";
const s8 D_001FE7F8[0x7] __attribute__((aligned(4))) = "REPAIR\000";
static const u8 pad_001FE7FF[0x1] __attribute__((aligned(1))) = { 0 };
#pragma explicit_zero_data reset

/* func_001DED50 */
#define D_001FE798 D_001FE798__as_func_001DED50
extern s8 D_001FE798__as_func_001DED50[];
#define D_001FE7A0 D_001FE7A0__as_func_001DED50
extern s8 D_001FE7A0__as_func_001DED50[];
#define D_001FE7D0 D_001FE7D0__as_func_001DED50
extern s8 D_001FE7D0__as_func_001DED50[];
#define D_001FE7D8 D_001FE7D8__as_func_001DED50
extern s8 D_001FE7D8__as_func_001DED50[];
#define D_001FE7E0 D_001FE7E0__as_func_001DED50
extern s8 D_001FE7E0__as_func_001DED50[];
#define D_001FE7E8 D_001FE7E8__as_func_001DED50
extern s8 D_001FE7E8__as_func_001DED50[];
#define D_001FE7F0 D_001FE7F0__as_func_001DED50
extern s8 D_001FE7F0__as_func_001DED50[];
#define D_001FE7F8 D_001FE7F8__as_func_001DED50
extern s8 D_001FE7F8__as_func_001DED50[];
#define D_00202378 D_00202378__as_func_001DED50
extern u32 D_00202378__as_func_001DED50;
#define D_004BAA70 D_004BAA70__as_func_001DED50
extern s8 D_004BAA70__as_func_001DED50[];
#define func_00181680 func_00181680__as_func_001DED50
void func_00181680__as_func_001DED50(s32, s8 *, s8 *, void *, S *, s32);
#define func_00189020 func_00189020__as_func_001DED50
G_func_001DED50 *func_00189020__as_func_001DED50(s32);
#define func_001875C0 func_001875C0__as_func_001DED50
void func_001875C0__as_func_001DED50(f32, f32, f32, s8 *, s32, Col_func_001DED50);
#define sprintf sprintf__as_func_001DED50
void sprintf__as_func_001DED50(s8 *, s8 *, ...);
#define strcpy strcpy__as_func_001DED50
void strcpy__as_func_001DED50(s8 *, s8 *);

void func_001DED50(O_func_001DED50 *o, s32 sel, u32 id, u32 n) {
    Col_func_001DED50 c1;
    Col_func_001DED50 c2;
    S t __attribute__((aligned(16)));
    E_func_001DED50 *e;
    s32 k;

    t = D_001F3A50[0];
    D_0020235C += 0.1f;
    if (id < 2000) {
        t.x = o->x30;
        t.y = o->x34;
        if (id == 0) {
            o->c.b[0xC - 0xC] = 0x40;
            o->c.b[0xD - 0xC] = 0x40;
            o->c.b[0xE - 0xC] = 0x40;
        }
        switch (D_00202378) {
        case 0:
        case 1:
            break;
        case 2:
            if (id == 0x1FD) return;
            break;
        case 3:
            if (sel == 100) return;
            break;
        case 4:
            if (sel == 100) return;
            break;
        case 5:
            if (id == 0x1FD) return;
            if (sel == 100) return;
            break;
        case 6:
            if (id == 0x1FB) return;
            if (id == 0x1FC) return;
            if (id == 0x1FD) return;
            if (sel == 100) return;
            break;
        }
        func_00181680(o->x28, (s8 *)o, o->x10, &o->c, &t, id);
    }
    if (n == id - 1500) {
        D_00202368 = 32.0f + o->x38 + 75.0f * sinf(0.1f * D_0020235C);
        D_00202364 = 32.0f + o->x3C + 75.0f * cosf(0.1f * D_0020235C);
        e = func_00189020(6)->x34;
        t.x = o->x38;
        t.y = o->x3C;
        t.m[3] = 1.0f;
        t.m[0] = 1.0f;
        func_00187960(D_002020D4, &o->c);
        func_00181680(e->x4, e->x10, e->x20, &o->c, &t, id);
    }
    if (n == id - 500) {
        D_00202370 = 32.0f + o->x38 + 75.0f * sinf(3.14f + 0.1f * D_0020235C);
        D_0020236C = 32.0f + o->x3C + 75.0f * cosf(3.14f + 0.1f * D_0020235C);
        if (n != 4) {
            D_00202368 = 32.0f + o->x38 + 75.0f * sinf(0.1f * D_0020235C);
            D_00202364 = 32.0f + o->x3C + 75.0f * cosf(0.1f * D_0020235C);
        }
        k = 0;
        switch (n) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            k = 0;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            k = 1;
            break;
        }
        e = &func_00189020(6)->x34[k];
        t.x = o->x38;
        t.y = o->x3C;
        t.m[3] = 1.0f;
        t.m[0] = 1.0f;
        func_00187960(D_002020D4, &o->c);
        func_00181680(e->x4, e->x10, e->x20, &o->c, &t, id);
    }
    if (id == 5000) {
        c1.w = 0x80808080;
        c1.b[3] = o->c.b[3] * 2;
        switch (D_00202378) {
        case 0:
            break;
        case 1:
            strcpy(D_004BAA70, D_001FE7D0);
            break;
        case 2:
            strcpy(D_004BAA70, D_001FE7D8);
            break;
        case 3:
            strcpy(D_004BAA70, D_001FE7E0);
            break;
        case 4:
            strcpy(D_004BAA70, D_001FE7E8);
            break;
        case 5:
            strcpy(D_004BAA70, D_001FE7F0);
            break;
        case 6:
            strcpy(D_004BAA70, D_001FE7F8);
            break;
        }
        func_001875C0(o->x38, o->x3C, 0.9f, D_004BAA70, 0, c1);
    }
    if (sel == 100) {
        c2.w = 0x80808080;
        c2.b[3] = o->c.b[3] * 2;
        if (id == 100) {
            func_001875C0(o->x38, o->x3C, 0.9f, D_001FE798, 0, c2);
        }
        if (id == 0x65) {
            sprintf(D_004BAA70, D_001FE7A0, func_001CBA30());
            func_001875C0(o->x38, o->x3C, 0.9f, D_004BAA70, 2, c2);
        }
    }
}
#undef func_00181680
#undef func_00189020
#undef func_001875C0
#undef sprintf
#undef strcpy
#undef D_001FE798
#undef D_001FE7A0
#undef D_001FE7D0
#undef D_001FE7D8
#undef D_001FE7E0
#undef D_001FE7E8
#undef D_001FE7F0
#undef D_001FE7F8
#undef D_00202378
#undef D_004BAA70
