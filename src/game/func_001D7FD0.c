#include "common.h"
s32 func_001D8960(s32, s32, s32, s32, s32);
s32 printf(const char *, ...);
s32 sceSifCheckStatRpc(void *);
extern char D_001FE6C0[];
extern s32 D_004B9EF0[];
extern u8 D_004B7A40[];
extern u8 D_004B7CB0[];
void func_001D7FD0(void) {
    s32 r, t;
    s32 n;
    s32 i;
    n = 10000000; goto check;
loop:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
check:
    t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop;
out:
    if (r >= 0) func_001D8960(0, 1, 0, 0x200, 0x70000);
    for (i = 0x1FF; i >= 0; i--) D_004B7CB0[i] = D_004B7A40[i];
}
