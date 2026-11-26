#include "common.h"
typedef struct { s32 a, b, c, d, x10, x14; } E;
typedef struct { s32 x0, x4, x8; u8 p[0x44]; E *x50; s32 x54; s32 x58; s32 x5C; } S;
s32 func_001EA690(S *a0, s32 a1) {
    s32 n;
    s32 r;
    s32 sz;
    s32 found;
    s32 last;
    s32 i;
    E *e;
    found = 0;
    n = a0->x58;
    r = 0;
    last = a0->x5C;
    sz = a0->x8 << 11;
    if (n > 0) {
        for (i = 0; i < n && found == 0; i++) {
            e = &a0->x50[(i + (a0->x54 + (last - n))) % a0->x54];
            if ((a1 + sz - e->x10) % sz < e->x14) {
                found = 1;
                r = 1;
            }
        }
    }
    return r;
}
