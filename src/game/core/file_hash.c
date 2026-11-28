#include "m2c.h"
void strcpy(s8 *, s8 *);
s32 strlen(s8 *);
u32 toupper(u8);

u32 File_HashName_3_00159D10(s8 *s) {
    s8 buf[0x100];
    u32 h = 0;
    s32 n;
    s8 *p;

    strcpy(buf, s);
    n = strlen(buf);
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
        h ^= toupper(*(u8 *)s);
        s++;
    }
    return h;
}
