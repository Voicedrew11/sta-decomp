#include "m2c.h"
typedef struct { u8 pad[8]; u16 x8; u8 pada[6]; u8 x10[0x20]; u8 lo:4; u8 hi:4; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } X;
typedef struct { u8 pad[0x390]; s16 *r; u8 pad394[0x462 - 0x394]; u16 st[7]; } S;
typedef struct { s16 p0; s16 a[3]; s16 p8; s16 b[3]; } Buf;
extern s8 *D_002022E4;
void func_001C8320(s32, s32, s32, s32);
s32 func_001CD450(s32, void *, s32, s32);
s32 func_001AB500(X *, Buf *);
void func_001CC830(s32, u32, s32, s32);
void func_001C8570(void *);
static inline S *get(void) {
    S *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    return r;
}
static inline s32 calc(X *a0, s32 k) {
    S *s;
    s32 v;
    s16 *r;
    Buf buf;
    s8 *base;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S *)(base + 0x180);
    }
    v = 0;
    if (s == NULL) return v;
    if (k) {
        r = s->r;
        v = r[0] / 100;
        if (v < r[2]) v = r[2] - v;
        return v;
    }
    buf.a[0] = s->st[0] / 5;
    buf.a[1] = s->st[1] / 5;
    buf.a[2] = s->st[2] / 5;
    buf.b[0] = s->st[4] / 5;
    buf.b[1] = s->st[5] / 5;
    buf.b[2] = s->st[6] / 5;
    return func_001AB500(a0, &buf);
}

s32 func_001C7DC0(X *a0) {
    S *s;
    s32 v;
    s16 *r;
    Buf buf;
    u8 b;
    s32 k;

    if (get() == NULL) return 0;
    if (!a0->b3) {
        k = a0->b2;
        v = calc(a0, k);
        if (!a0->b2 && func_001CD450(0x12, &b, 0, 1)) {
            v -= v * b / 100;
            if (v < 0) v = 0;
        }
    } else {
        v = 9999;
    }
    func_001CC830(v, a0->x8, 0, a0->lo);
    func_001C8570(a0->x10);
    func_001C8320(v, 1, 1, 1);
    return v;
}
