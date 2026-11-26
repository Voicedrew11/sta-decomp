#include "common.h"
typedef struct { s32 lo, hi, reg, pad; } Q;
typedef struct { u32 x, y, w, h; } R;
static inline Q *set(Q *p, u64 v, s32 r) { p->lo = v & 0xFFFFFFFF; p->hi = v >> 32; p->reg = r; p->pad = 0; return p + 1; }
static inline Q *hdr(Q *p) { p->lo = 0x116; p->hi = 0; p->reg = 0; p->pad = 0; return p + 1; }
Q *func_001E92C0(Q *p, R *b, R *a) {
    p = hdr(p);
    p = set(p, (u64)a->x | ((u64)a->y << 16), 3);
    p = set(p, (u64)b->x | ((u64)b->y << 16), 5);
    p = set(p, (u64)(a->x + a->w) | ((u64)(a->y + a->h) << 16), 3);
    p = set(p, (u64)(b->x + b->w) | ((u64)(b->y + b->h) << 16), 5);
    return p;
}
