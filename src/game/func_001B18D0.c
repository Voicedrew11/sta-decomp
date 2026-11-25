#include "m2c.h"
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad1C[0x14]; } E;
typedef struct { s32 x0; u8 pad4[0xAC]; E *xB0; u8 padB4[0x84]; E *x138; } X;
extern X **D_002022BC;
static inline s32 cur(X **pp, X *x, s32 *out) {
    if (pp == 0) {
        if (out) *out = -1;
        return -1;
    }
    if (out) *out = x->x0;
    if (x->xB0) return x->xB0 - x->x138;
    return -1;
}

s32 func_001B18D0(s32 *out) {
    X *x;
    s32 i;
    if (D_002022BC) {
        x = *D_002022BC;
    } else {
        return -1;
    }
    i = cur(D_002022BC, x, out);
    if (i == -1) return -1;
    return x->x138[i].x1A;
}
