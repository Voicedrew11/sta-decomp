#include "common.h"
s32 toupper(s32);
u64 func_00177F80(u8 *s) {
    u64 h = 0;
    u8 *p = s;
    while (*p) p++;
    p--;
    while (*p) {
        h = ((h << 8) | (h >> 56)) ^ toupper(*p);
        if (p == s) break;
        p--;
    }
    return h;
}
