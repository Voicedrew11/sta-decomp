#include "common.h"
u8 *func_001E5B18(u16 *c, u8 *s);
static inline s32 lead(u8 c) { return (u8)(c + 0x7F) < 0x1F || (u8)(c + 0x20) < 0xB; }
s32 func_001E5D78(u8 *s, s32 n) {
    u8 *lim = (u8 *)-1;
    u8 *end;
    s32 cnt = 0;
    u16 c;
    if (n != -1) lim = s + n;
    end = lim - 1;
    for (;;) {
        if (!(s < end || (end == s && !lead(*s)))) return cnt;
        s = func_001E5B18(&c, s);
        if (s == 0) return cnt;
        if (c != 0xFFFF) cnt++;
    }
}
