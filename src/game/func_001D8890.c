#include "common.h"
typedef struct { u8 pad[0x24]; void *serve; u8 pad28[0x8]; } CD;
extern CD D_004B9EF0;
extern char D_001FE6C0[];
extern s32 D_002022FC;
extern s32 D_00202300;
s32 sceSifBindRpc(CD *, u32, s32);
s32 sceSifCheckStatRpc(CD *);
s32 printf(const char *, ...);
void func_001D8960(s32, s32, s32, s32, s32);
s32 func_001D8890(void) {
    s32 i;
    s32 r;
    if (D_002022FC == 1) return 0;
    D_00202300 = 0;
    do {
        sceSifBindRpc(&D_004B9EF0, 0x101A, 0);
    } while (D_004B9EF0.serve == 0);
    i = 10000000;
    goto cond;
body:
    if (i < 0) { printf(D_001FE6C0); r = -1; goto done; }
    i--;
cond:
    if (sceSifCheckStatRpc(&D_004B9EF0) == 1) goto body;
    r = 1;
done:
    if (r >= 0) func_001D8960(0, 1, 0, 4, 0x10000);
    D_002022FC = 1;
    return 1;
}
