#include "m2c.h"
#include "common.h"
#include "include_asm.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
typedef struct { s16 x, y; } V_func_00157D50;
typedef struct { u8 pad[0x140]; V_func_00157D50 pos[2][8][11]; V_func_00157D50 vel[2][8][11]; } W;
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 col;
    s32 x48;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } f4C;
    u8 pad4D[3];
} Buf;
typedef struct {
    u32 x0;
    u16 w, h;
    u8 r, g, b, a;
    s16 xC, xE, x10, x12;
    u16 x14, x16, x18;
    u8 x1A, x1B;
    s8 x1C, x1D, x1E, x1F;
} P;
typedef struct {
    s32 x0, x4;
    s16 x8;
    u8 xA, xB;
} Arg;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } B8;
typedef struct {
    s32 x0, x4, x8, xC;
    s32 x10, x14, x18, x1C;
    u8 pad20[0x24];
    u32 col;
    u8 pad48[4];
    B8 f;
    u8 pad4D[3];
} S;
typedef union { u128 q; f32 f[4]; } V_func_00159160;
extern s32 D_00201F2C;
extern f32 D_00201E90;
extern Q D_001F2050;
extern s32 D_002F1AE0[];
extern W D_002F19B0;
extern f32 D_002F2070[];
extern u64 D_00201F78;
extern V_func_00159160 D_001F2040[];
extern f32 D_002F16C0[];
extern f32 D_002F1840[];
extern f32 D_002F19E0[];
extern f32 D_002F2080[];
extern f32 D_002F20BC[];
extern struct { unsigned char : 7; unsigned char f : 1; char pad[15]; } D_002F2078;
extern s16 D_002F1A64[];
extern s16 D_002F1A66[];
extern u8 D_002F1A68[];
extern u8 D_002F1A69[];
extern u8 D_002F1A6A[];
extern u8 D_002F1A6B[];
extern s16 D_002F1A6C[];
extern s16 D_002F1A6E[];
extern s16 D_002F1A70[];
extern s16 D_002F1A72[];
extern s16 D_002F1A74[];
extern s16 D_002F1A76[];
extern u16 D_002F1A78[];
extern u8 D_002F1A7A[];
extern u8 D_002F1A7B[];
extern u8 D_002F1A7D[];
extern u8 D_002F1A7E[];
extern u8 D_002F1A7F[];
extern s32 D_002F1AA0[];
extern s32 D_002F1AB0[];
extern s32 D_002F1AC0[];
extern s32 D_002F1AD0[];
extern f32 D_002F1AD4[];
extern s16 D_002F1A48[];
extern s32 D_002F1A80[];
extern s32 D_002F1A60[];
extern s32 D_002F19CC[];
extern s32 D_002F19C0[];
extern s32 D_002F19D8[];
extern s32 D_002F19DC[];
extern W D_002F19B0__as_func_00157FE0;
extern struct { unsigned char : 6; unsigned char f : 1; char pad[15]; } D_002F2078__as_func_00159500;
extern s32 D_002F2070__as_func_00159500[];
extern struct { unsigned char : 5; unsigned char f : 1; char pad[15]; } D_002F2078__as_func_00159590;
extern struct { unsigned char : 4; unsigned char f : 1; char pad[15]; } D_002F2078__as_func_001595C0;
extern struct { unsigned char : 2; unsigned char f : 1; char pad[15]; } D_002F2078__as_func_001595F0;
extern struct { unsigned char : 1; unsigned char f : 1; char pad[15]; } D_002F2078__as_func_00159620;
extern struct { unsigned char f : 1; char pad[15]; } D_002F2078__as_func_00159650;
extern s32 D_002F19B0__as_func_00159680[];
extern s8 D_002F19C0__as_func_00159680[];
extern s8 D_002F19CC__as_func_00159680[];
extern M2C_UNK D_002F1A60__as_func_00159680[];
extern M2C_UNK D_002F1A80__as_func_00159680[];
extern s8 D_002F1AA0__as_func_00159680[];
extern M2C_UNK D_002F1AB0__as_func_00159680[];
extern M2C_UNK D_002F1AC0__as_func_00159680[];
extern f32 D_002F1AD0__as_func_00159680[];
extern u8 D_002F2078__as_func_00159680[];
void func_00157320(s32 a0);
s32* func_00157620(void);
void func_00157D50(f32 dt);
void func_00157FE0(u8 a0);
void func_001580E0(P *p);
void func_00158900(Arg *a0);
void func_00158BF0(s32 dx, s32 dy);
void func_00158EE0(f32 *c);
void func_00159160(s32 *arg0, s32 *arg1);
void func_00159310(int v);
void func_00159340(u8 a0, u8 a1, u8 a2, u8 a3, s16 a4, u8 a5);
void func_00159400(s32 *arg0, f32 fparg0);
void func_00159460(s32 arg0);
void func_00159480(void *arg0);
s32* func_00159500(s32 on);
s32* func_00159590(int v);
s32* func_001595C0(int v);
void func_001595F0(int v);
s32* func_00159620(int v);
s32* func_00159650(int v);
void func_00159680(void);
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_00154420(void);
Q* func_00154A80(s32);
void func_00154A70(void);
void func_00176AE0(void);
u64 __fixunssfdi(f32);
void memcpy(V_func_00157D50 (*)[11], V_func_00157D50 (*)[11], s32);
u32 func_0015ED20(void);
void memset(void *, s32, s32);
void func_001544C0(void);
void func_00155BD0(void *);
void func_00153740(void);
f32 cosf(f32);
f32 sinf(f32);
void sceVu0ApplyMatrix(f32 *, f32 *, f32 *);
void sceVu0InversMatrix(f32 *, f32 *);
void sceVu0CopyMatrix(f32 *, f32 *);
void sceVu0CopyVector(s32 *, s32 *);
M2C_UNK sceVu0InterVector(f32, s8 *, M2C_UNK *, M2C_UNK *);
M2C_UNK func_00157630();
void func_00157FE0__as_func_00157D50(s32);
void func_001543E0__as_func_00158900(s32, u64);
void func_001543E0__as_func_00158BF0(s32, u64);
void func_001543E0__as_func_00158EE0(s32, u64);
void func_00155BD0__as_func_00158EE0(S *);
void sceVu0CopyVector__as_func_00159460(s32 *, s32);
void func_00157FE0__as_func_00159500(s32 a);
s32 func_00158900__as_func_00159680();
s32 func_00158BF0__as_func_00159680();
s32 func_00158EE0__as_func_00159680();
s32 func_00159160__as_func_00159680();
M2C_UNK sceVu0CopyVector__as_func_00159680(s8 *, M2C_UNK *);
M2C_UNK func_001580E0__as_func_00159680(M2C_UNK *);

/* func_00157320 */
/* func_00157320 */
static inline s32 wd(void) { return D_00201F2C ? 0 : 0x1180; }

void func_00157320(s32 a0) {
    Q q;
    Q c;
    Q *p;
    u64 v;
    f32 f;
    u16 i;
    func_001545D0();
    func_001543E0(0x3F, 0xFFFFFFFF);
    func_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
    func_001543E0(0x4E, 0x3A000118);
    f = D_00201E90;
    v = (__fixunssfdi(f) << 32) | 0x27F0000;
    func_001543E0(0x40, v | (__fixunssfdi(448.0f - f - 1.0f) << 48));
    func_001543E0(0x47, 0x32001);
    func_00154420();
    p = func_00154A80(0x20);
    q.q = 0;
    q.w[0] = 0x1000001F;
    q.w[3] = 0x5000001F;
    p[0].q = q.q;
    q.d[0] = ((u64)0x30834000 << 32) | 0x800A;
    q.d[1] = 0x551;
    p[1].q = q.q;
    p += 2;
    i = 0;
    do {
        c = D_001F2050;
        q.w[0] = 128.0f * c.f[0];
        q.w[1] = 128.0f * c.f[1];
        q.w[2] = 128.0f * c.f[2];
        q.w[3] = 128.0f * c.f[3];
        p[0].q = q.q;
        q.w[0] = (i + 0x6C0) << 4;
        q.w[1] = 0x7200;
        q.w[2] = a0;
        q.w[3] = 0;
        p[1].q = q.q;
        q.w[0] = (i + 0x700) << 4;
        q.w[1] = 0x8E00;
        q.w[2] = a0;
        q.w[3] = 0;
        p[2].q = q.q;
        p += 3;
        i += 0x40;
    } while (i < 0x280);
    func_00154A70();
    func_00176AE0();
}

/* func_00157620 */

s32 *func_00157620(void) {
    return D_002F1AE0;
}

/* text_00157630 */
INCLUDE_ASM(func_00157630);

/* func_00157D50 */
void func_001543E0__as_func_00157D50(s32, s64);

/* func_00157D50 */

void func_00157D50(f32 dt) {
    u8 l;
    u8 j;
    u8 i;
    s16 ax;
    s16 ay;

    for (l = 0; l < 2; l++) {
        for (i = 1; i < 7; i++) {
            for (j = 1; j < 10; j++) {
                ax = 0;
                ay = 0;
                ax += D_002F19B0.pos[l][i - 1][j].x;
                ay += D_002F19B0.pos[l][i - 1][j].y;
                ax += D_002F19B0.pos[l][i + 1][j].x;
                ay += D_002F19B0.pos[l][i + 1][j].y;
                ax += D_002F19B0.pos[l][i][j - 1].x;
                ay += D_002F19B0.pos[l][i][j - 1].y;
                ax += D_002F19B0.pos[l][i][j + 1].x;
                ay += D_002F19B0.pos[l][i][j + 1].y;
                ax -= (s16)(D_002F19B0.pos[l][i][j].x * 4);
                ay -= (s16)(D_002F19B0.pos[l][i][j].y * 4);
                D_002F19B0.vel[l][i][j].x += ax;
                D_002F19B0.vel[l][i][j].y += ay;
            }
        }
        for (i = 1; i < 7; i++) {
            for (j = 1; j < 10; j++) {
                D_002F19B0.pos[l][i][j].x += (s16)(0.005f * D_002F19B0.vel[l][i][j].x);
                D_002F19B0.pos[l][i][j].y += (s16)(0.005f * D_002F19B0.vel[l][i][j].y);
            }
        }
    }
    D_002F2070[0] += dt / 100.0f;
    if (D_002F2070[0] > 1.0f) {
        D_002F2070[0] -= 1.0f;
        memcpy(D_002F19B0.pos[0], D_002F19B0.pos[1], 0x160);
        memcpy(D_002F19B0.vel[0], D_002F19B0.vel[1], 0x160);
        func_00157FE0(1);
    }
}

/* func_00157FE0 */

void func_00157FE0(u8 a0) {
    u8 j;
    u8 i;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 11; j++) {
            D_002F19B0.vel[a0][i][j].x = 0;
            D_002F19B0.vel[a0][i][j].y = 0;
            if (i == 0 || i == 7 || j == 0 || j == 10) {
                D_002F19B0.pos[a0][i][j].x = 0;
                D_002F19B0.pos[a0][i][j].y = 0;
            } else {
                D_002F19B0.pos[a0][i][j].x = (func_0015ED20() & 0x3FF) - 0x200;
                D_002F19B0.pos[a0][i][j].y = (func_0015ED20() & 0x3FF) - 0x200;
            }
        }
    }
}

/* func_001580E0 */
void func_001580E0(P *p) {
    Buf b;
    u64 tex, frame, sc;
    s32 k;
    u32 v;
    s32 dx, dy;
    u32 i;
    s32 ang;
    u8 a;
    s16 c, s;
    f32 f;
    if (p->x1A) {
        memset(&b, 0, 0x50);
        b.f4C.b0 = 1;
        b.f4C.b1 = 1;
        b.f4C.b2 = 1;
        k = p->x1C ? D_00201F2C : !(D_00201F2C != 0);
        if (k == 0) v = 0; else if (k == 1) v = 0x118000; else v = 0;
        tex = (u64)(v >> 8) | 0x68028000 | ((u64)2 << 32);
        sc = ((s64)(p->w - 1) << 16) | ((s64)(p->h - 1) << 48);
        frame = (u64)p->x0 | ((s64)(s32)((u32)p->w >> 6) << 16) | 0xA000000;
        func_001545D0();
        func_001543E0(0x4C, frame);
        func_001543E0(0x40, sc);
        func_001543E0(0x18, 0x8000 | ((u64)0x8000 << 32));
        func_001543E0(0x47, 0x31001);
        if (p->x1F) {
            func_001543E0(0x45, 1);
            func_001543E0(0x44, D_00201F78);
        }
        func_001543E0(6, tex);
        func_001543E0(0x14, 0x60);
        func_001544C0();
        b.f4C.b1 = 1;
        b.f4C.b2 = 0;
        b.col = 0x80808080;
        b.x0 = 0x8000;
        b.x4 = 0x8000;
        b.x8 = -1;
        b.x10 = (p->w + 0x800) << 4;
        b.x14 = (p->h + 0x800) << 4;
        b.x18 = -1;
        b.x20 = 0;
        b.x24 = 0;
        b.x30 = 0x2800;
        b.x34 = 0x1C00;
        func_00155BD0(&b);
        if (p->x1D) {
            dx = 0x1400 / p->w;
            dy = 0xE00 / p->h;
            func_001545D0();
            func_001543E0(0x42, 0x64 | ((u64)0x40 << 32));
            func_001544C0();
            b.f4C.b1 = 1;
            b.f4C.b2 = 1;
            b.col = 0x80808080;
            b.x0 = 0x8000;
            b.x4 = 0x8000;
            b.x8 = -1;
            b.x10 = (p->w + 0x800) << 4;
            b.x14 = (p->h + 0x800) << 4;
            b.x18 = -1;
            b.x20 = dx;
            b.x24 = dx;
            b.x30 = dy + 0x2800;
            b.x34 = dy + 0x1C00;
            func_00155BD0(&b);
        }
        if (p->r | p->g | p->b) {
            func_001545D0();
            func_001543E0(0x42, 0x62 | ((u64)0x80 << 32));
            func_001544C0();
            b.f4C.b1 = 0;
            b.f4C.b2 = 1;
            b.col = p->r | 0x80000000 | (p->g << 8) | (p->b << 16);
            func_00155BD0(&b);
        }
        func_00153740();
        if (p->x1A && p->x18) {
            tex = (u64)(p->x0 << 5) | ((s64)(s32)((u32)p->w >> 6) << 14) | (0x68A00000 | ((u64)2 << 32));
            b.f4C.b1 = 1;
            b.f4C.b2 = 1;
            func_001545D0();
            func_001543E0(0x42, 0x48);
            func_001543E0(6, tex);
            if (p->x1F) {
                func_001543E0(0x45, 0);
            }
            func_001544C0();
            b.x0 = 0x6C00;
            b.x4 = 0x7200;
            b.x10 = 0x9400;
            b.x14 = 0x8E00;
            b.x20 = p->xC;
            b.x24 = p->xE + 8;
            b.x30 = (p->w << 4) + p->x10;
            b.x34 = (p->h << 4) + p->x12;
            b.col = (p->a << 24) | 0x808080;
            func_00155BD0(&b);
            p->x16 += p->x1E;
            while (p->x16 >= p->x18) {
                p->x16 -= p->x18;
            }
            a = p->a;
            for (i = 1; i < p->x1A; i++) {
                a = (a * p->x1B) >> 7;
                b.col &= 0xFFFFFF;
                b.col |= a << 24;
                for (ang = p->x16; ang < 360; ang += p->x18) {
                    f = 3.1415f * ang / 180.0f;
                    c = (s32)(i * (p->x14 * cosf(f)));
                    s = (s32)(i * (p->x14 * sinf(f)));
                    b.x0 = c + 0x6C00;
                    b.x4 = s + 0x7200;
                    b.x10 = c + 0x9400;
                    b.x14 = s + 0x8E00;
                    func_00155BD0(&b);
                }
            }
        }
        func_00176AE0();
    }
}

/* func_00158900 */

void func_00158900(Arg *a0) {
    Buf b;
    u32 fbp;
    s32 i;
    s32 sel;
    sel = a0->x8 ? D_00201F2C : !D_00201F2C;
    if (sel == 0) fbp = 0;
    else if (sel == 1) fbp = 0x118000;
    else fbp = 0;
    func_001545D0();
    func_001543E0(0x3F, 0xFFFFFFFF);
    func_001543E0(0x42, 0x44);
    func_001543E0(0x47, 0x31001);
    func_001543E0(6, (u64)(fbp >> 8) | 0x68028000 | ((u64)2 << 32));
    func_001543E0(0x14, 0);
    func_001544C0();
    memset(&b, 0, 0x50);
    b.f4C.b0 = 1;
    b.f4C.b1 = 1;
    b.f4C.b2 = 1;
    b.x0 = 0x7000;
    b.x4 = 0x8E10;
    b.x8 = -1;
    b.x10 = 0x6C00;
    b.x14 = 0x7210;
    b.x18 = -1;
    b.x20 = 0x400;
    b.x24 = 0x1C00;
    b.x30 = 0;
    b.x34 = 0;
    if (a0->xA) {
        b.x0 += a0->x0;
        b.x4 += a0->x4;
        b.col = (a0->xA << 24) | 0x808080;
        for (i = 0; i < 0x280; i += 0x40) {
            func_00155BD0(&b);
            b.x0 += 0x400;
            b.x10 += 0x400;
            b.x20 += 0x400;
            b.x30 += 0x400;
        }
    }
    if (a0->xB) {
        b.x0 -= a0->x0;
        b.x4 -= a0->x4;
        b.col = (a0->xB << 24) | 0x808080;
        for (i = 0; i < 0x280; i += 0x40) {
            func_00155BD0(&b);
            b.x0 += 0x400;
            b.x10 += 0x400;
            b.x20 += 0x400;
            b.x30 += 0x400;
        }
    }
    func_00176AE0();
}

/* func_00158BF0 */

void func_00158BF0(s32 dx, s32 dy) {
    Buf b;
    u32 w;
    s32 step;
    s32 i;
    u8 z;

    { s32 v = !(D_00201F2C != 0); if (v == 0) w = 0; else if (v == 1) w = 0x118000; else w = 0; }
    func_001545D0();
    func_001543E0(6, (u64)(w >> 8) | 0x68028000 | ((u64)2 << 32));
    func_001543E0(0x14, 0);
    func_001543E0(0x47, 0x31001);
    func_001543E0(0x22, 3);
    func_001544C0();
    memset(&b, 0, 0x50);
    b.col = 0xFF808080;
    if (dx <= 0) {
        b.x0 = 0x6C00;
        b.x0 -= 8;
        b.x10 = 0x6E00;
        b.x20 = 0;
        b.x30 = 0x200;
    } else {
        b.x0 = 0x9400;
        b.x10 = 0x9200;
        b.x10 -= 8;
        b.x20 = 0x2800;
        b.x30 = 0x2600;
    }
    if (dy <= 0) {
        b.x4 = 0x7200;
        b.x4 -= 8;
        b.x14 = 0x8E00;
        b.x34 = 0x1C00;
        b.x24 = 0;
    } else {
        b.x4 = 0x8E00;
        b.x14 = 0x7200;
        b.x14 -= 8;
        b.x24 = 0x1C00;
        b.x34 = 0;
    }
    b.x0 += dx;
    b.x10 += dx;
    b.x4 += dy;
    b.x14 += dy;
    if (dx <= 0) step = 0x200; else step = -0x200;
    for (i = 0; i < 20; i++) {
        z = 0;
        b.f4C.b0 = z;
        b.f4C.b1 = 1;
        b.f4C.b2 = z;
        func_00155BD0(&b);
        b.x0 += step;
        b.x10 += step;
        b.x20 += step;
        b.x30 += step;
    }
    func_001545D0();
    func_001543E0(0x22, 0);
    func_001544C0();
    func_00176AE0();
}

/* func_00158EE0 */

void func_00158EE0(f32 *c) {
    S s;

    func_001545D0();
    func_001543E0(0x47, 0x31001);
    func_001543E0(0x42, 0x44);
    func_001543E0(0x40, 0x2800000 | ((u64)0x1C00000 << 32));
    func_001544C0();
    memset(&s, 0, 0x50);
    s.f.b0 = 1;
    s.f.b1 = 0;
    s.f.b2 = 1;
    s.x0 = 0x6C00;
    s.x4 = 0x7200;
    s.x8 = -1;
    s.x10 = 0x9400;
    s.x14 = 0x8E00;
    s.x18 = -1;
    s.col = ((u32)(255.0f * c[3] / 255.0f) << 24) | ((u32)(255.0f * c[2] / 255.0f) << 16) | ((u32)(255.0f * c[1] / 255.0f) << 8) | (u32)(255.0f * c[0] / 255.0f);
    func_00155BD0(&s);
}

/* func_00159160 */
void func_00159160(s32 *arg0, s32 *arg1) {
    V_func_00159160 c;
    f32 m[16];
    f32 b[4];
    f32 a[4];
    f32 w;

    if (D_002F20BC[0] == 0.0f) {
        *arg0 = 0;
        *arg1 = 0;
        sceVu0CopyMatrix(D_002F2080, D_002F16C0);
        return;
    }
    c = D_001F2040[0];
    c.f[2] = D_002F19E0[0];
    sceVu0InversMatrix(m, D_002F2080);
    sceVu0ApplyMatrix(b, m, c.f);
    sceVu0ApplyMatrix(a, D_002F1840, b);
    w = 1.0f / a[3];
    a[0] = a[0] * w - 2048.0f;
    a[1] = a[1] * w - 2048.0f;
    *arg0 = 8.0f * a[0];
    *arg1 = 8.0f * a[1];
    if (*arg0 < -0x80) {
        *arg0 = -0x80;
    }
    if (*arg0 > 0x80) {
        *arg0 = 0x80;
    }
    if (*arg1 < -0x80) {
        *arg1 = -0x80;
    }
    if (*arg1 > 0x80) {
        *arg1 = 0x80;
    }
    sceVu0CopyMatrix(D_002F2080, D_002F16C0);
}

/* func_00159310 */
void func_00159310(int v)
{
    D_002F2078.f = v;
}

/* func_00159340 */
void func_00159340(u8 a0, u8 a1, u8 a2, u8 a3, s16 a4, u8 a5) {
    D_002F1A64[0] = 0x100;
    D_002F1A66[0] = 0x100;
    D_002F1A68[0] = a1;
    D_002F1A69[0] = a2;
    D_002F1A6A[0] = a3;
    D_002F1A6B[0] = a0;
    D_002F1A6C[0] = 0x10;
    D_002F1A6E[0] = 0x10;
    D_002F1A70[0] = -8;
    D_002F1A72[0] = -8;
    D_002F1A74[0] = a4;
    D_002F1A76[0] = 0x3C;
    D_002F1A78[0] = a5;
    D_002F1A7A[0] = 2;
    D_002F1A7B[0] = 0x50;
    D_002F1A7D[0] = 1;
    D_002F1A7E[0] = 0;
    D_002F1A7F[0] = 1;
}

/* func_00159400 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void func_00159400(s32 *arg0, f32 fparg0) {
    sceVu0CopyVector(D_002F1AC0, D_002F1AA0);
    sceVu0CopyVector(D_002F1AB0, arg0);
    (*D_002F1AD4) = fparg0;
    (*D_002F1AD0) = 0;
}

/* func_00159460 */
#define sceVu0CopyVector sceVu0CopyVector__as_func_00159460
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_002F1A50[0x4];

void func_00159460(s32 arg0) {
    (*D_002F1A48) = 2;
    sceVu0CopyVector(D_002F1A50, arg0);
}
#undef sceVu0CopyVector

/* func_00159480 */
void func_00159480(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x182;
    M2C_FIELD(arg0, s8 *, 0x1A) = 2;
    M2C_FIELD(arg0, s8 *, 0x1B) = 0x40;
    M2C_FIELD(arg0, s8 *, 0xB) = 0x10;
    M2C_FIELD(arg0, s8 *, 8) = 8;
    M2C_FIELD(arg0, s8 *, 9) = 0x10;
    M2C_FIELD(arg0, s8 *, 0xA) = 0x10;
    M2C_FIELD(arg0, s16 *, 0x14) = 0x20;
    M2C_FIELD(arg0, s16 *, 0x16) = 0x1E;
    M2C_FIELD(arg0, s16 *, 0x18) = 0x3C;
    M2C_FIELD(arg0, s16 *, 4) = 0x100;
    M2C_FIELD(arg0, s16 *, 6) = 0x80;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D) = 1;
    M2C_FIELD(arg0, s8 *, 0x1E) = 0;
}

/* func_00159500 */
#define D_002F2078 D_002F2078__as_func_00159500

s32 *func_00159500(s32 on)
{
    s32 v = on != 0;
    if (v && !D_002F2078.f) {
        func_00157FE0(0);
        func_00157FE0(1);
        D_002F2070[0] = 0;
    }
    D_002F2078.f = v;
    return D_002F1AE0;
}
#undef D_002F2078

/* func_00159590 */
#define D_002F2078 D_002F2078__as_func_00159590

s32 *func_00159590(int v)
{
    D_002F2078.f = v != 0;
    return D_002F1A80;
}
#undef D_002F2078

/* func_001595C0 */
#define D_002F2078 D_002F2078__as_func_001595C0

s32 *func_001595C0(int v)
{
    D_002F2078.f = v != 0;
    return D_002F1A60;
}
#undef D_002F2078

/* func_001595F0 */
#define D_002F2078 D_002F2078__as_func_001595F0

void func_001595F0(int v)
{
    D_002F2078.f = v != 0;
}
#undef D_002F2078

/* func_00159620 */
#define D_002F2078 D_002F2078__as_func_00159620

s32 *func_00159620(int v)
{
    D_002F2078.f = v != 0;
    return D_002F19CC;
}
#undef D_002F2078

/* func_00159650 */
#define D_002F2078 D_002F2078__as_func_00159650

s32 *func_00159650(int v)
{
    D_002F2078.f = v != 0;
    return D_002F19C0;
}
#undef D_002F2078

/* func_00159680 */
#define D_002F19B0 D_002F19B0__as_func_00159680
#define D_002F1AD0 D_002F1AD0__as_func_00159680
#define D_002F2078 D_002F2078__as_func_00159680

void func_00159680(void) {
    s32 sp1C;
    s32 sp18;
    f32 temp_f1;

    if (((u64) ((s64) D_002F2078[0] << 0x38) >> 0x3F) != 0) {
        func_00154700(D_002F19B0[0], -1);
        if (D_002F2078[0] & 1) {
            func_00158900(D_002F19C0);
        }
        func_00156AF0();
        func_00157320(0);
        func_00155900();
        if ((D_002F1AD0[0] += 0.033333335f) > D_002F1AD4[0]) {
            D_002F1AD4[0] = 0.0f;
        }
        if (D_002F1AD4[0] == 0.0f) {
            sceVu0CopyVector(D_002F1AA0, D_002F1AB0);
        } else {
            sceVu0InterVector(1.0f - (D_002F1AD0[0] / D_002F1AD4[0]), D_002F1AA0, D_002F1AC0, D_002F1AB0);
        }
        func_00154700(D_002F19B0[0], 0);
        D_002F19DC[0] = 0;
        D_002F1A48[0] = 2;
        D_002F19D8[0] = 0;
        if (((u64) ((s64) D_002F2078[0] << 0x3C) >> 0x3F) != 0) {
            func_00158EE0(D_002F1AA0);
        }
        func_00156F60();
        func_00155900();
        return;
    }
    func_00154700(D_002F19B0[0], -1);
    if (D_002F2078[0] & 1) {
        func_00158900(D_002F19C0);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x3E) >> 0x3F) != 0) {
        func_00158900(D_002F19CC);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x3D) >> 0x3F) != 0) {
        func_00159160(&sp1C, &sp18);
        if (D_002F1A48[0] != 1) {
            func_00158BF0(sp1C, sp18);
        }
    }
    func_00157320(0);
    func_00155900();
    func_00154700(D_002F19B0[0], 0);
    if (((u64) ((s64) D_002F2078[0] << 0x3B) >> 0x3F) != 0) {
        func_001580E0(D_002F1A60);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x3A) >> 0x3F) != 0) {
        func_001580E0(D_002F1A80);
    }
    if (D_002F1A48[0] != 0) {
        D_002F1A48[0] -= 1;
    }
    if (((u64) ((s64) D_002F2078[0] << 0x39) >> 0x3F) != 0) {
        func_00157630();
    }
    func_00156CE0();
    if (((u64) ((s64) D_002F2078[0] << 0x3C) >> 0x3F) != 0) {
        func_00158EE0(D_002F1AA0);
    }
    func_00156F60();
    func_00155900();
}
#undef D_002F19B0
#undef D_002F1AD0
#undef D_002F2078
#undef func_001543E0
#undef D_002F19B0
#undef func_00155BD0
#undef sceVu0CopyVector
#undef D_002F2078
#undef D_002F2070
#undef func_00157FE0
#undef func_00158900
#undef func_00158BF0
#undef func_00158EE0
#undef func_00159160
#undef func_001580E0
#undef D_002F19C0
#undef D_002F19CC
#undef D_002F1A60
#undef D_002F1A80
#undef D_002F1AA0
#undef D_002F1AB0
#undef D_002F1AC0
#undef D_002F1AD0
