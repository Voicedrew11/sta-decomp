#include "common.h"
typedef char *va_list;
extern s32 D_00201E3C;
extern s8 *D_00202328;
extern u8 D_004BA0E0[];
extern s8 D_004BA2E0[];
void func_001DBDB0(u8 c, s32 n, ...) {
    s32 i;
    va_list ap;
    ap = (char *)__builtin_next_arg(n) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    *D_00202328++ = c;
    if (c == 1) D_00201E3C += 3;
    { i = n; while (i--) { if (D_00202328 >= D_004BA2E0) break; ap += 8; *D_00202328++ = *(s32 *)(ap - 8); } }
    D_004BA0E0[0]++;
}
