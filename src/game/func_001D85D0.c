#include "common.h"
s32 func_001D8960(s32, s32, s32, s32, s32);
s32 printf(const char *, ...);
s32 sceSifCheckStatRpc(void *);
extern char D_001FE6C0[];
extern s32 D_004B9EF0[];
s32 func_001D85D0(s32 a0, s32 a1, s32 a2) {
    s32 r, t;
    s32 n;
    n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop; out: if (r < 0) return -1; return func_001D8960(a0, a1, 0, 4, a2);
}
