#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; u8 padC[0x10]; f32 x1C; u8 pad20[0xC]; s32 x2C; } Q;
typedef struct { u8 pad[0xE]; u16 xE; } E1;
typedef struct { u8 pad[0x1A]; u16 x1A; } E2;
typedef struct { u8 pad[0xC]; s32 *xC; } E3;
E1 *func_001B76C0(s32, s32);
E2 *func_001B77A0(s32, s32);
E3 *func_001B19A0(s32);
s32 func_00166F80(s32, s32, s32);
s8 *func_001A5460(s32 *);
void func_001A5440(s8 *);
s32 func_0017A480(s8 *, f32 *, f32 *);
u32 func_0013EA70(s8 *);
u8 func_00141610(s8 *);
extern u8 D_00202030;
static inline f32 u2f(u32 x) { return x; }
static inline s32 lt(f32 a, u32 b) { s32 r = 0; if (a < u2f(b)) r = 1; return r; }
static inline s32 chk(s32 b, s32 a, s32 bit, s32 off) {
    s32 r = -1;
    if ((func_001B77A0(b, a)->x1A / 100) & bit) {
        r = func_00166F80(*func_001B19A0(b)->xC, a + off, 0);
    }
    return r;
}
static inline s32 h5(Q *q, s32 d) {
    s32 a = q->x4;
    E3 *p = func_001B19A0(q->x8);
    if (a == 0) { return d; }
    d = func_00166F80(*p->xC, a, 0);
    return d;
}

s32 func_00179F80(Q *q) {
    s32 r = -1;
    f32 f;

    switch (q->x0) {
    case 0:
        f = q->x1C;
        if (lt(f, func_001B76C0(q->x8, q->x4)->xE)) {
            r = chk(q->x8, q->x4, 2, 0xC8);
        }
        break;
    case 7:
        if (chk(q->x8, q->x4, 4, 0x190) != -1) r = 1;
        break;
    case 8:
        if (chk(q->x8, q->x4, 8, 0x320) != -1) r = 1;
        break;
    case 1:
        if (chk(q->x8, q->x4, 1, 0x64) != -1) r = 1;
        break;
    case 2:
        if (chk(q->x8, q->x4, 0x10, 0x640) != -1) r = 1;
        break;
    case 3: {
        s32 c = D_00202030;
        if ((c >= 31 && c <= 49) || (q->x4 == 99 && c == 1)) {
            if (chk(q->x8, q->x4, 0x20, 0xC80) != -1) r = 1;
        }
        break;
    }
    case 4: {
        f32 d;
        f32 e;
        s32 it = 0;
        s8 *a;
        for (a = func_001A5460(&it); a; a = func_001A5460(&it)) {
            func_001A5440(a);
            if (func_0017A480(a, &d, &e) && func_0013EA70(a) && q->x2C && func_00141610(a) == 1) r = 1;
        }
        break;
    }
    case 5: {
        if (h5(q, r) != -1) r = 1;
        break;
    }
    case 6:
        break;
    }
    return r != -1;
}
