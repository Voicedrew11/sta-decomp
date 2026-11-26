#include "common.h"
typedef char *va_list;
#define va_start(ap, parm) ((ap) = (char *)__builtin_next_arg(parm) - ((__builtin_args_info(2) >= 8) ? 0 : (8 - __builtin_args_info(2)) * 8))
#define va_arg(ap, T) (*(T *)(((ap) += 8) - 8))
s32 sceSifCheckStatRpc(void *);
void printf(const char *, ...);
s32 func_001D8960(s32, s32, s32, s32, s32);
extern u8 D_004B7A40[];
extern u8 D_004B9EF0[];
extern char D_001FE6C0[];

s32 func_001D8680(s32 a, s32 b, s32 c, ...) {
    s32 cnt;
    s32 *p;
    s32 r;
    va_list ap;
    p = (s32 *)(((u32)D_004B7A40 & 0x0FFFFFFF) | 0x20000000);
    cnt = 10000000;
    goto chk;
top:
    if (cnt < 0) {
        printf(D_001FE6C0);
        r = -1;
        goto out;
    }
    cnt--;
chk:
    if (sceSifCheckStatRpc(D_004B9EF0) == 1) goto top;
    r = 1;
out:
    if (r < 0) return -1;
    va_start(ap, c);
    p[0] = va_arg(ap, s32);
    p[1] = va_arg(ap, s32);
    p[2] = va_arg(ap, s32);
    p[3] = va_arg(ap, s32);
    p[4] = va_arg(ap, s32);
    p[5] = va_arg(ap, s32);
    p[6] = va_arg(ap, s32);
    p[7] = va_arg(ap, s32);
    return func_001D8960(a, b, 0x20, 4, c);
}
