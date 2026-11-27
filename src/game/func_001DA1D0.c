#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; u16 xC; u16 xE; } B_func_001DA1D0;
typedef struct { s8 x0; s8 x1; s8 x2; s8 x3; } C_func_001DA1D0;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } R;
typedef struct { s8 x0; s8 x1; s8 x2; s8 x3; } C_func_001DA530;
typedef struct { s32 v; char pad[12]; } E_func_001DA530;
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 p[3]; } B_func_001DA620;
typedef struct { s8 a; s8 b; s8 c; s8 d; } C_func_001DA620;
typedef struct { f32 v[8]; } M_func_001DA720;
typedef struct { s32 v; char pad[0x1C]; } E_func_001DA7D0;
typedef struct { s32 x0; s32 x4; s16 x8; s16 xA; s32 xC; s32 x10; s16 x14; s16 x16; u8 p[8]; } M_func_001DA840;
typedef struct { s32 v; char pad[12]; } E_func_001DA8F0;
typedef struct { s32 a; s32 b; s32 c[2]; } E_func_001DA920;
typedef struct { char pad[0x200]; E_func_001DA920 e[1]; } T_func_001DA920;
typedef struct { char p[0x14]; s16 x14; char r[0xA]; } A;
typedef struct { s32 x200; s32 x204; s32 x208; s32 x20C; } B_func_001DA9A0;
typedef struct { s32 addr; u32 size; s32 pad[2]; } E_func_001DAA90;
typedef struct { char pad[8]; s32 v; char rest[0x14]; } E_func_001DAC70;
typedef struct { s32 x0; s32 x4; u32 x8; s32 xC; s32 x10; s16 x14; char rest[0xA]; } E_func_001DACB0;
typedef struct { s32 a, b, c, d; } F;
typedef struct { E_func_001DACB0 e[16]; F f[8]; char pad[0x420 - 0x280]; s8 g[8][0x20]; } T_func_001DACB0;
typedef struct { s8 a, b, c, d; } G;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s16 x14; char rest[0xA]; } E_func_001DAEF0;
typedef struct {
    u8 pad0[8];
    u32 x8;
    u8 padC[4];
    s32 x10;
    u8 pad14[2];
    s16 x16;
    u8 pad18[8];
} Ent;
typedef struct { s32 data; s32 addr; u32 size; s32 mode; } Dma;
extern s32 D_004BA4F8[];
extern s32 D_00202320;
extern s32 D_00202324;
extern s8 D_004BA782[][4];
extern E_func_001DA530 D_004BA70C[];
extern s8 D_004BA920[][32];
extern u16 D_004BAA36[];
extern s32 D_0020232C;
extern u32 D_004BAA28[];
extern s32 D_004BA2F8[];
extern s32 D_004BA2E0[];
extern u32 D_004BA2E4[];
extern u32 D_004BA2E8[];
extern s32 D_004BA2EC[];
extern u32 D_004BA2F4[];
extern Dma D_004BAA60;
extern s32 D_004BA2F0[];
void func_001DA1D0(s32 n0, R *r0);
void func_001DA340(s32 *x, s32 *y, s32 k, s32 a, s32 lim);
s32 func_001DA4F0(s32 arg0);
s32 func_001DA530(s32 i);
s32 func_001DA620(s32 i, s32 j, u8 x, u8 y, u8 z);
s32 func_001DA720(s32 i);
s32 func_001DA7D0(s32 i);
s32 func_001DA840(s32 a0, s16 a1, s16 a2, s16 a3, s16 t0, s32 t1);
void func_001DA8F0(s32 i, s16 b);
s32 func_001DA920(s32 i);
s32 func_001DA9A0(s32 j, s32 i);
s32 func_001DAA50(void);
s32 func_001DAA90(s32 i, s32 b, u32 sz);
s32 func_001DAC30(void);
s32 func_001DAC70(s32 i, s32 v);
s32 func_001DACB0(s32 arg0);
s32 func_001DAEF0(s32 v, s32 i, s32 c);
s32 func_001DAF80(void);
s32 func_001DB020(s32 arg0, s32 arg1, s32 arg2);
s32 func_001DB410(void);
void memset(void *, s32, s32);
s32 func_001D8350(s32, s32, s32, s32, s32, void *);
s16 func_001DBEA0(s32);
s16 func_001DC0F0(s32);
void func_001DBDB0(s32, s32, s32, s32);
void FlushCache(s32 mode);
s32 func_001D8680(s32, s32, s32, ...);
s32 sceSifFreeSysMemory(s32);
s32 sceSifAllocIopHeap(u32);
s32 func_001DB830(void);
s32 func_001DB9B0(s32, s32, u32);
void func_001D84F0(s32, s32, s32, s32);
s32 sceSifDmaStat(u32 id);
u32 sceSifSetDma(void *, s32);

/* .bss from 0x004BA300, defined from the top down (CodeWarrior writes
   uninitialised objects in reverse order) */
M_func_001DA720 D_004BA900;
M_func_001DA720 D_004BA880[0x4];
G D_004BA780[0x40];
s32 D_004BA700[0x20];
u8 D_004BA500[0x200];
s16 D_004BA300[0x100];      /* also D_004BA4F8 */

/* func_001DA1D0 */
#define D_004BA500 D_004BA500__as_func_001DA1D0
extern struct { char pad[0x200]; B_func_001DA1D0 b[8]; C_func_001DA1D0 c[64]; } D_004BA500__as_func_001DA1D0;
/* .bss, from the top down (CodeWarrior writes it in reverse) */

void func_001DA1D0(s32 n0, R *r0)
{
    R *r;
    s32 n;
    s32 cnt;
    C_func_001DA1D0 *c;
    C_func_001DA1D0 *cb;
    s16 *p;
    r = r0;
    n = n0;
    if (n0 > 0) {
        cb = D_004BA500.c - 0xA0;
        do {
            cnt = 0;
            memset(D_004BA300, 0, 0x1FC);
            p = D_004BA300;
            while (cnt < 63 && n > 0) {
                c = cb + 0xA0;
                if (c->x2 == 1) {
                    func_001DA340(&D_00202320, &D_00202324, r->x0, -r->x4, 0x7FF);
                    cnt++;
                    p[0] = D_00202320;
                    p[63] = D_00202324;
                    p[126] = ((u16)c->x0 << 8) | D_004BA500.b[c->x1].xC;
                    p[189] = r->xC;
                    D_004BA4F8[0] = cnt;
                    p++;
                }
                r++;
                cb++;
                n--;
            }
            if (cnt > 0)
                func_001D8350(4, 0, 0x1FC, 0, 0x411C00, D_004BA300);
        } while (n > 0);
    }
}
#undef D_004BA500

/* func_001DA340 */
void func_001DA340(s32 *x, s32 *y, s32 k, s32 a, s32 lim)
{
    s16 (*fs)(s32);
    s16 (*fc)(s32);
    if (k > 127) k = 127;
    if (k < 0) k = 0;
    if (a > lim) a = lim;
    if (a < -lim) a = -lim;
    fc = func_001DC0F0;
    fs = func_001DBEA0;
    if (a >= 0) {
        *x = k * fs(a) / 127;
        *y = k * fc(a) / 127;
    } else {
        a = -a;
        *x = k * fs(a) / 127;
        *y = -k * fc(a) / 127;
    }
}

/* func_001DA4F0 */
s32 func_001DA4F0(s32 arg0) {
    if (!(0 > arg0) && arg0 < 0x40) {
        return ~D_004BA782[arg0][0] != 0;
    }
    return -1;
}

/* func_001DA530 */
#define D_004BA500 D_004BA500__as_func_001DA530
extern struct { char pad[0x280]; C_func_001DA530 c[64]; } D_004BA500__as_func_001DA530;
s32 func_001DA530(s32 i) {
    C_func_001DA530 *c;
    if (D_004BAA36[0] == 0) return -1;
    if (i < 0 || i >= 64) return -1;
    c = &D_004BA500.c[i];
    if (c->x2 != -1 && !(0 > c->x1) && c->x1 < 8 && c->x0 >= 0) {
        func_001DBDB0(2, 2, c->x0, D_004BA70C[c->x1].v);
        c->x2 = -1;
        D_004BA920[c->x1][c->x0] = -1;
    }
    return 0;
}
#undef D_004BA500

/* func_001DA620 */
#define D_004BA500 D_004BA500__as_func_001DA620
extern struct { char pad[0x200]; B_func_001DA620 b[8]; C_func_001DA620 c[64]; } D_004BA500__as_func_001DA620;
#define func_001DBDB0 func_001DBDB0__as_func_001DA620
void func_001DBDB0__as_func_001DA620(s32, s32, s32, s32, s32, s32, s32);
s32 func_001DA620(s32 i, s32 j, u8 x, u8 y, u8 z) {
    C_func_001DA620 *c;
    B_func_001DA620 *b;
    if (D_004BAA36[0] == 0) {
        return -1;
    }
    if (!(0 > i) && i < 0x40 && !(0 > j) && j < 8) {
        c = &D_004BA500.c[i];
        b = &D_004BA500.b[j];
        if (b->x0 == 0) {
            return -1;
        }
        func_001DBDB0(1, 5, i, j, x, y, (z << 4) | (b->xC & 0xF));
        c->a = -1;
        c->b = j;
        c->c = 0;
    } else {
        return -1;
    }
    return i;
}
#undef func_001DBDB0
#undef D_004BA500

/* func_001DA720 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
#define func_001D8350 func_001D8350__as_func_001DA720
s32 func_001D8350__as_func_001DA720(s32 a, s32 b, s32 c, s32 d, s32 e, M_func_001DA720 *m);

s32 func_001DA720(s32 i)
{
    if (i < 0 || i > 4)
        return 0;
    D_004BA900 = D_004BA880[i];
    return func_001D8350(4, 1, 0x20, 4, 0x400800, &D_004BA900);
}
#undef func_001D8350

/* func_001DA7D0 */
#define D_004BA500 D_004BA500__as_func_001DA7D0
extern struct { char pad[0x380]; E_func_001DA7D0 e[5]; } D_004BA500__as_func_001DA7D0;

s32 func_001DA7D0(s32 i)
{
    E_func_001DA7D0 *e;
    if (i < 0 || i > 4)
        return -1;
    e = &D_004BA500.e[i];
    if (e->v == -1)
        return -1;
    e->v = -1;
    FlushCache(0);
    return 0;
}
#undef D_004BA500

/* func_001DA840 */
#define D_004BA880 D_004BA880__as_func_001DA840
extern M_func_001DA840 D_004BA880__as_func_001DA840[];
s32 func_001DA840(s32 a0, s16 a1, s16 a2, s16 a3, s16 t0, s32 t1) {
    M_func_001DA840 *m = D_004BA880;
    s32 i;
    s32 r;
    for (i = 0; i < 4; i++, m++) {
        if (m->x0 == -1) { r = i; break; }
    }
    if (i >= 4) return -2;
    m->x0 = t1;
    m->x4 = a0 | 0x100;
    m->x8 = a1;
    m->xA = a2;
    m->xC = a3;
    m->x10 = t0;
    m->x14 = a1;
    m->x16 = a2;
    FlushCache(0);
    return r;
}
#undef D_004BA880

/* func_001DA8F0 */
#define D_004BA70C D_004BA70C__as_func_001DA8F0
extern E_func_001DA8F0 D_004BA70C__as_func_001DA8F0[];
#define func_001D8680 func_001D8680__as_func_001DA8F0
void func_001D8680__as_func_001DA8F0(s32 a, s32 b, s32 c, ...);

void func_001DA8F0(s32 i, s16 b)
{
    func_001D8680(4, 0, 0x20A00, D_004BA70C[i].v, b);
}
#undef func_001D8680
#undef D_004BA70C

/* func_001DA920 */
#define D_004BA500 D_004BA500__as_func_001DA920
extern T_func_001DA920 D_004BA500__as_func_001DA920;
s32 func_001DA920(s32 i) {
    E_func_001DA920 *e = &D_004BA500.e[i];
    if (e->a != 0) {
        if (sceSifFreeSysMemory(e->a) != 0) return -1;
        e->a = 0; e->b = 0;
    } else {
        return -1;
    }
    FlushCache(0);
    return 0;
}
#undef D_004BA500

/* func_001DA9A0 */
#define D_004BA500 D_004BA500__as_func_001DA9A0
extern struct { A a[16]; B_func_001DA9A0 b[8]; } D_004BA500__as_func_001DA9A0;
s32 func_001DA9A0(s32 j, s32 i) {
    A *a;
    B_func_001DA9A0 *b;
    if (i < 0 || i >= 16) return -1;
    if (j < 0 || j >= 8) return -1;
    a = &D_004BA500.a[i];
    if (a->x14 < 0 || a->x14 >= 8) return -1;
    b = &D_004BA500.b[j];
    b->x208 = i;
    b->x20C = a->x14;
    return -(func_001D8680(4, 1, 0x20000, b->x20C, b->x200) != 0);
}
#undef D_004BA500

/* func_001DAA50 */
#define func_001DB830 func_001DB830__as_func_001DAA50
int func_001DB830__as_func_001DAA50();

s32 func_001DAA50(void) {
    if (func_001DB830() != 0) {
        D_0020232C = 0;
        return 0;
    }
    return 1;
}
#undef func_001DB830

/* func_001DAA90 */
#define D_004BA500 D_004BA500__as_func_001DAA90
extern struct { char pad[0x200]; E_func_001DAA90 e[8]; } D_004BA500__as_func_001DAA90;
s32 func_001DAA90(s32 i, s32 b, u32 sz) {
    E_func_001DAA90 *e;
    s32 r;

    r = -1;
    if (i < 0 || i >= 8) return -1;
    e = &D_004BA500.e[i];
    switch (D_0020232C) {
    case 0:
        sz = (sz + 15) & ~15;
        if (e->addr == 0) {
            e->addr = sceSifAllocIopHeap(sz);
            if (e->addr == 0) break;
            if (e->addr + sz > 0x1FFFFF) break;
        } else if (e->size != sz) break;
        e->size = sz;
        D_0020232C = 1;
    case 1:
        if (func_001DB830() != 0) { D_0020232C = 2; } else { r = 0; break; }
    case 2:
        if (func_001DB9B0(e[0].addr, b, (&e->addr)[1]) < 0) { D_0020232C = 0; break; }
        D_0020232C = 3;
    case 3:
        if (func_001DB830() != 0) { D_0020232C = 0; r = 1; } else r = 0;
    }
    FlushCache(0);
    return r;
}
#undef D_004BA500

/* func_001DAC30 */
s32 func_001DAC30(void) {
    s32 *p = D_004BA700;
    s32 r = -1;
    s32 i;
    for (i = 0; i < 8; i++, p += 4) {
        if (*p == 0) { r = i; break; }
    }
    return r;
}

/* func_001DAC70 */
#define D_004BA500 D_004BA500__as_func_001DAC70
extern E_func_001DAC70 D_004BA500__as_func_001DAC70[16];

s32 func_001DAC70(s32 i, s32 v)
{
    E_func_001DAC70 *e;

    if (i < 0 || i >= 16)
        return -1;
    e = &D_004BA500[i];
    e->v = v;
    return 0;
}
#undef D_004BA500

/* func_001DACB0 */
#define D_004BA500 D_004BA500__as_func_001DACB0
extern T_func_001DACB0 D_004BA500__as_func_001DACB0;

s32 func_001DACB0(s32 arg0) {
    u32 t;
    s8 k;
    s32 n;
    G *g;
    E_func_001DACB0 *e;
    s32 i;
    if (arg0 < 0 || arg0 >= 16) return -1;
    g = D_004BA780;
    n = 0x40;
    while (n--) {
        if (g->c != -1) {
            k = g->b;
            if (0 > k) {
            } else if (k < 8 && D_004BA500.f[k].c == arg0) {
                D_004BA500.g[k][g->a] = -1;
                g->c = -1;
                g->b = -1;
                g->a = -1;
            }
        }
        g++;
    }
    n = 8;
    while (n--) {
        if (D_004BA500.f[n].c == arg0) D_004BA500.f[n].c = -1;
    }
    e = &D_004BA500.e[arg0];
    func_001D84F0(4, 1, 0x10300, e->x14);
    func_001D8680(4, 0, 0x10A00, e->x14, 0);
    if (*D_004BAA28 == e->x8 + e->x10) *D_004BAA28 = e->x8;
    e->x8 = 0;
    e->x10 = 0;
    if (e->x4 != 0) {
        if (sceSifFreeSysMemory(e->x4) != 0) return -1;
        e->x4 = 0;
    }
    if (e->x0 != 0) {
        if (sceSifFreeSysMemory(e->x0) != 0) return -1;
        e->x0 = 0;
    }
    *D_004BAA28 = 0x5010;
    e = D_004BA500.e;
    i = 0;
    do {
        t = e->x8;
        if (*D_004BAA28 <= t) *D_004BAA28 = t + e->x10;
        i++;
        e++;
    } while (i < 16);
    FlushCache(0);
    return 0;
}
#undef D_004BA500

/* func_001DAEF0 */
#define D_004BA500 D_004BA500__as_func_001DAEF0
extern E_func_001DAEF0 D_004BA500__as_func_001DAEF0[16];
s32 func_001DAEF0(s32 v, s32 i, s32 c) {
    E_func_001DAEF0 *e;
    if (v < 0 || v >= 16) return -1;
    if (i < 0 || i >= 16) return -1;
    e = &D_004BA500[i];
    e->x14 = v;
    return -(func_001D8680(4, 1, 0x10100, e->x14, e->x8, e->x0, c) != 0);
}
#undef D_004BA500

/* func_001DAF80 */
s32 func_001DAF80(void)
{
    if (sceSifDmaStat(D_004BA2F8[0]) >= 0)
        return 1;
    if (!func_001D8680(4, 1, 0x800, 0, 0))
        return 1;
    if (!func_001D8680(4, 1, 0x800, 1, 0))
        return 1;
    D_004BA2E0[0] = 0;
    return 0;
}

/* func_001DB020 */
/* MATCH: extern s32 D_004BAA28[] (read into u32 y) + `y <= x` compare: sltu $at, x in v0 */
#define D_004BA2E0 D_004BA2E0__as_func_001DB020
extern u32 D_004BA2E0__as_func_001DB020[];
#define D_004BA2F8 D_004BA2F8__as_func_001DB020
extern u32 D_004BA2F8__as_func_001DB020[];
#define D_004BA500 D_004BA500__as_func_001DB020
extern Ent D_004BA500__as_func_001DB020[];
#define D_004BAA28 D_004BAA28__as_func_001DB020
extern s32 D_004BAA28__as_func_001DB020[];

s32 func_001DB020(s32 arg0, s32 arg1, s32 arg2) {
    u32 n;
    Ent *p;
    s32 ret;
    u32 x;
    u32 y;
    s32 r;

    ret = -1;
    if (D_004BA2EC[0] == 0) return ret;
    if (arg0 < 0 || arg0 >= 0x10) return -1;
    p = &D_004BA500[arg0];
    switch (D_004BA2E0[0]) {
    case 0:
        arg2 = (arg2 + 0xF) & ~0xF;
        D_004BA2E4[0] = arg2;
        p->x10 += arg2;
        if (p->x8 == 0) p->x8 = D_004BAA28[0];
        x = p->x8;
        y = *D_004BAA28;
        if ((u32)y <= x) { *D_004BAA28 = x; *D_004BAA28 += arg2; } else if (y < x + arg2) *D_004BAA28 = x + arg2;
        D_004BA2E8[0] = p->x8;
        if (0x1F8800 - p->x8 >= (u32)arg2) {
            D_004BAA60.data = arg1;
            D_004BAA60.mode = 0;
            D_004BA2E0[0] = 1;
            ret = 0;
        }
        break;
    case 1:
        D_004BAA60.size = (D_004BA2E4[0] > D_004BA2F4[0]) ? D_004BA2F4[0] : D_004BA2E4[0];
        D_004BAA60.addr = D_004BA2EC[p->x16];
        D_004BA2E0[0] = 2;
    case 2:
        switch (func_001D8680(4, 1, 0x800, p->x16, 0)) {
        case 1:
            D_004BA2E0[0] = 3;
            break;
        case 0:
            return 0;
        }
    case 3:
        D_004BA2F8[0] = sceSifSetDma(&D_004BAA60, 1);
        if (D_004BA2F8[0] == 0) {
            D_004BA2E0[0] = 0;
            break;
        }
        D_004BA2E0[0] = 4;
    case 4:
        if (sceSifDmaStat(D_004BA2F8[0]) >= 0) {
            ret = 0;
            break;
        }
        D_004BA2E0[0] = 5;
    case 5:
        n = D_004BAA60.size;
        r = func_001D8680(4, 1, 0x900, p->x16, 0, D_004BA2EC[p->x16], D_004BA2E8[0], n);
        if (-(r != ((n + 0x3F) & ~0x3F)) < 0) {
            D_004BA2E0[0] = 0;
            break;
        }
        D_004BAA60.data = D_004BAA60.data + D_004BAA60.size;
        D_004BA2E8[0] += D_004BAA60.size;
        D_004BA2E4[0] -= D_004BAA60.size;
        if ((s32)D_004BA2E4[0] > 0) {
            ret = 0;
            D_004BA2E0[0] = 1;
            break;
        }
        D_004BA2E0[0] = 6;
    case 6:
        switch (func_001D8680(4, 1, 0x800, p->x16, 0)) {
        case 1:
            D_004BA2E0[0] = 7;
            break;
        case 0:
            return 0;
        }
    case 7:
    case 8:
        D_004BA2E0[0] = 0;
        ret = 1;
        break;
    }
    FlushCache(0);
    return ret;
}
#undef D_004BA2E0
#undef D_004BA2F8
#undef D_004BA500
#undef D_004BAA28

/* func_001DB410 */
#define D_004BA2E8 D_004BA2E8__as_func_001DB410
extern s32 D_004BA2E8__as_func_001DB410[];

s32 func_001DB410(void) {
    if ((*D_004BA2EC) != 0) {
        return -1;
    }
    (*D_004BA2F4) = 0x80000;
loop_3:
    (*D_004BA2F4) = (u32) (*D_004BA2F4) >> 1;
    (*D_004BA2EC) = sceSifAllocIopHeap((*D_004BA2F4));
    if (((*D_004BA2EC) == 0) && ((u32) (*D_004BA2F4) < 0x4000U)) {
        return -1;
    }
    if ((*D_004BA2EC) != 0) {
        (*D_004BA2F0) = 0;
        (*D_004BA2F8) = -1;
        (*D_004BA2E0) = 0;
        (*D_004BA2E8) = 0;
        return 0;
    }
    goto loop_3;
}
#undef D_004BA2E8
