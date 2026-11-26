#include "common.h"
typedef struct { s32 x0; u8 pad[0x28]; s32 x2C; s32 x30; s32 x34; s32 x38; s32 x3C; s32 x40; } S;
extern volatile S D_004BDEE0;
extern volatile s32 D_004BDF0C[]; extern s32 D_004BDF14[], D_004BDF18[], D_004BDF1C[], D_004BDF20[];
typedef struct { s32 x0; s32 x4; u8 *x8; s32 xC; } H;
void func_00123A88(void *, void *, s32);
void func_001EBAB0(volatile S *s, u8 **a1, s32 *a2, u8 **a3, s32 *a4);
s32 func_001EBE10(s32 a0, H *h, u8 *buf0) {
    u8 *D2;
    s32 t;
    u8 *buf;
    u8 *src;
    s32 rest;
    s32 total;
    u8 *D1;
    s32 n;
    s32 N1;
    s32 m;
    s32 size;
    u8 *end;
    u8 *d1;
    u8 *d2;
    s32 n1;
    s32 n2;
    u32 k;
    s32 left;
    buf = buf0;
    src = h->x8 + 4;
    size = *(s32 *)(buf + 0x50008);
    end = buf + size;
    if (src >= end) src -= size;
    n = end - src;
    m = h->xC - 4;
    n = (m < n) ? m : n;
    rest = m - n;
    func_001EBAB0(&D_004BDEE0, &d1, &n1, &d2, &n2);
    total = n + rest;
    D2 = d2;
    N1 = n1;
    D1 = d1;
    if (N1 + n2 < total) {
        total = 0;
    } else if (n >= N1) {
        func_00123A88(D1, src, N1);
        func_00123A88(D2, src + N1, n - N1);
        func_00123A88(D2 + n - N1, buf, rest);
    } else {
        t = N1 - n;
        if (rest >= t) {
            func_00123A88(D1, src, n);
            func_00123A88(D1 + n, buf, t);
            func_00123A88(D2, buf + N1 - n, rest - t);
        } else {
            func_00123A88(D1, src, n);
            func_00123A88(D1 + n, buf, rest);
        }
    }
    left = total;
    if (D_004BDEE0.x0 == 0) {
        k = 0x28 - D_004BDF0C[0];
        k = (k < (u32)total) ? k : total;
        D_004BDF0C[0] += k;
        if ((u32)D_004BDF0C[0] >= 0x28U) D_004BDEE0.x0 = 1;
        left -= k;
    }
    D_004BDF14[0] = (D_004BDF14[0] + left) % D_004BDF1C[0];
    D_004BDF18[0] += left;
    D_004BDF20[0] += left;
    return total > 0;
}
