#include "common.h"
s32 printf(const char *, ...);
s32 sceSifCheckStatRpc(void *);
s32 func_001D8960(s32, s32, s32, s32, s32);
extern char D_001FE6C0[];
extern s32 D_004B7A40[];
extern s32 D_004B9EF0[];
s32 func_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *src) {
    u8 *dst = (u8 *)(((u32)D_004B7A40 & 0x0FFFFFFF) | 0x20000000);
    s32 n = 10000000;
    s32 r;
    s32 i;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    if (src != NULL) {
        for (i = 0; i < c; i++) dst[i] = ((u8 *)src)[i];
    }
    return func_001D8960(a, b, c, d, e);
}
