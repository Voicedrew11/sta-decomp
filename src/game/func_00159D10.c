#include "m2c.h"
void func_00125CE8(s8 *, s8 *);
s32 func_00125E00(s8 *);
u32 func_00126518(u8);

u32 func_00159D10(s8 *s) {
    s8 buf[0x100];
    u32 h = 0;
    s32 n;
    s8 *p;

    func_00125CE8(buf, s);
    n = func_00125E00(buf);
    if (n != 0) {
        p = buf + n;
        do {
            p--;
            n--;
            if (*p == 0x5C || *p == 0x2F) {
                s = buf + n + 1;
                break;
            }
        } while (n != 0);
    }
    while (*s) {
        h = (h >> 26) | (h << 6);
        h ^= func_00126518(*(u8 *)s);
        s++;
    }
    return h;
}
