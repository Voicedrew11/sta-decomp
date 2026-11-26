#include "common.h"
s32 func_001D8960(s32, s32, s32, s32, s32);
s32 printf(const char *, ...);
s32 sceSifCheckStatRpc(void *);
s32 sceSifAllocIopHeap(s32);
extern char D_001FE6C0[];
extern s32 D_004B9EF0[];
s32 func_001D80E0(s32 size) {
    s32 r, t;
    s32 n;
    s32 v;
    s32 p = 0;
    n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop; out:
    if (r < 0) v = -1; else v = func_001D8960(0, 1, 0, 4, 0x30000);
    if (v >= size) {
        p = sceSifAllocIopHeap(size);
    } else {
        n = 10000000; goto check2; loop2: if (n < 0) { printf(D_001FE6C0); r = -1; goto out2; } n--; check2: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop2; out2:
        if (r >= 0) func_001D8960(0, 1, 0, 4, 0x30000);
    }
    return p;
}

