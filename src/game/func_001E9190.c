#include "common.h"

typedef struct { s32 w[4]; } Q;
typedef struct { u32 x, y, w, h; } R;

static inline Q *put(Q *p, u64 v, s32 r)
{
    p->w[0] = v & 0xFFFFFFFF; p->w[1] = v >> 32; p->w[2] = r; p->w[3] = 0;
    return p + 1;
}

Q *func_001E9190(Q *p, R *r, u32 c)
{
    p = put(p, 0x106, 0);
    p = put(p, (u64)r->x | ((u64)r->y << 16), 5);
    p = put(p, (u64)(c & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)((c >> 16) & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24), 1);
    p = put(p, (u64)(r->x + r->w) | ((u64)(r->y + r->h) << 16), 5);
    return p;
}
