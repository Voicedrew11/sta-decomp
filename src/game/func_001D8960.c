#include "common.h"
s32 printf(const char *, ...);
s32 sceSifCheckStatRpc(void *);
void sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
extern char D_001FE6C0[];
extern s32 D_004B7A40[];
extern s32 D_004B9EF0[];
s32 func_001D8960(s32 a, s32 b, s32 c, s32 d, u32 e) {
    s32 m;
    s32 *buf;
    s32 n;
    s32 r;
    m = !(b != 0);
    buf = D_004B7A40;
    c = (c + 0xF) & ~0xF;
    if (c > 0x200) c = 0x200;
    d = (d + 0xF) & ~0xF;
    if (d > 0x200) d = 0x200;
    n = 10000000;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    sceSifCallRpc(D_004B9EF0, ((a << 28) & 0xF0000000) | (e & 0x0FFFFFFF), m, buf, c, buf, d, 0, 0);
    return buf[0];
}

