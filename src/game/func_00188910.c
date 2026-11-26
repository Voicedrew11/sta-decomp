#include "common.h"
typedef struct { u16 lo, hi, base; } R;
typedef struct { u8 b[0x18]; } T;
typedef struct { u8 pad[0x10]; u16 n; u8 pad12[2]; R *r; T *t; } S;

T *func_00188910(S *s, u16 key) {
    R *e;
    s32 lo;
    s32 hi;
    s32 mid;
    if (s == 0) return 0;
    lo = 0;
    hi = s->n - 1;
    for (;;) {
        mid = (lo + hi) / 2;
        e = &s->r[mid];
        if (key < e->lo) {
            if (lo >= hi) goto fail;
            hi = mid - 1;
        } else if (e->hi < key) {
            if (lo >= hi) goto fail;
            lo = mid + 1;
        } else {
            return &s->t[e->base + key - e->lo];
        }
    }
fail:
    return 0;
}
