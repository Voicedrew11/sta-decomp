#include "common.h"
u8 *Sjis_DecodeChar_2_001E5B18(u16 *c, u8 *s);
static inline s32 lead(u8 c) { return (u8)(c + 0x7F) < 0x1F || (u8)(c + 0x20) < 0xB; }
s32 Sjis_ToWide_2_001E5C60(u16 *d, s32 n, u8 *s, s32 len) {
    u8 *lim;
    u8 *end;
    s32 cnt = 0;
    u16 *e;
    lim = len != -1 ? s + len : (u8 *)-1;
        for (;;) {
        if (!(cnt < n)) { d[n - 1] = 0; return cnt; }
        end = lim - 1;
        if (s >= end) { if (end != s) { d[cnt] = 0; return cnt; } if (lead(*s)) { d[cnt] = 0; return cnt; } }
        s = Sjis_DecodeChar_2_001E5B18(&d[cnt], s);
        if (d[cnt] != 0xFFFF) cnt++;
        if (s == 0) return cnt;
    }
}
