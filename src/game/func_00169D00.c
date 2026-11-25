#include "common.h"

extern char D_0042D7E0[];
void func_00170250(void *a, s32 b);

void func_00169D00(s32 *p, u32 n)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (p[i]) {
            func_00170250(D_0042D7E0, p[i]);
            p[i] = 0;
        }
    }
}
