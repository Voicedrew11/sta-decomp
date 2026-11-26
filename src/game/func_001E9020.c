#include "common.h"
typedef struct { s32 w[4]; } Q;
typedef struct { u32 x, y, w, h; } R;
extern u8 D_004BD310[];
extern u8 D_004BD311[];
extern u8 D_004BD312[];
extern u8 D_004BD313[];
extern Q *D_004BD31C[][2];

Q *func_001E9020(Q *p, R *r, s32 i, s32 j) {
    u64 v;
    Q *a;
    Q *b;
    Q *c;
    Q *d;
    Q *e;
    p->w[0] = 0x146;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    a = p + 1;
    a->w[0] = 0x44;
    a->w[1] = 0;
    a->w[2] = 0x42;
    a->w[3] = 0;
    b = a + 1;
    v = (u64)r->x | ((u64)r->y << 16);
    b->w[0] = v & 0xFFFFFFFF;
    b->w[1] = v >> 32;
    b->w[2] = 5;
    b->w[3] = 0;
    c = b + 1;
    D_004BD31C[j][i] = c;
    v = (u64)D_004BD310[0] | ((u64)D_004BD311[0] << 8) | ((u64)D_004BD312[0] << 16) | ((u64)D_004BD313[0] << 24);
    c->w[0] = v & 0xFFFFFFFF;
    c->w[1] = v >> 32;
    c->w[2] = 1;
    c->w[3] = 0;
    d = c + 1;
    v = (u64)(u32)(r->x + r->w) | ((u64)(u32)(r->y + r->h) << 16);
    d->w[0] = v & 0xFFFFFFFF;
    d->w[1] = v >> 32;
    d->w[2] = 5;
    d->w[3] = 0;
    e = d + 1;
    return e;
}
