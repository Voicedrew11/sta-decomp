#include "common.h"
typedef struct { s64 x0; s64 x8; s32 x10; s32 x14; } E;
typedef struct { s32 x0; s32 p4; s32 x8; u8 pC[0x2C]; s32 x38; s32 p3C; s32 x40; u8 p44[0xC]; E *x50; s32 x54; s32 x58; s32 x5C; } P;
typedef struct { s64 x0; s64 x8; } O;
s32 WaitSema(s32);
s32 SignalSema(s32);

s32 func_001EA2E0(P *p, O *out) {
    s32 madr;
    s32 a;
    u32 ctrl;
    u32 size;
    s32 found;
    s32 cnt;
    s32 n;
    s32 i;
    s32 base;
    s32 last;
    s32 idx;
    s32 m;
    u32 pos;
    u32 t;
    found = 0;
    madr = *(volatile s32 *)0x1000B410;
    cnt = 0;
    ctrl = *(volatile u32 *)0x10002020;
    a = p->x38 & 0x7F;
    size = p->x8 << 11;
    WaitSema(p->x40);
    out->x0 = -1;
    out->x8 = -1;
    n = p->x58;
    t = ((ctrl >> 16) & 3); t += ((ctrl >> 8) & 0xF);
    madr = madr - t * 16;
    pos = (size + (madr + (a >> 3)) - p->x0) % size;
    last = p->x5C;
    if (n > 0) {
        base = last - n;
        pos += size;
        for (i = 0; i < n && found == 0; i++) {
            idx = (i + (p->x54 + base)) % p->x54;
            if ((s32)(pos - p->x50[idx].x10) % (s32)size < p->x50[idx].x14) {
                if (p->x50[idx].x0 >= 0) {
                    out->x0 = p->x50[idx].x0;
                    out->x8 = p->x50[idx].x8;
                    p->x50[idx].x0 = -1;
                    p->x50[idx].x8 = -1;
                }
                found = 1;
            } else {
                cnt++;
            }
        }
        m = p->x58;
        m = (m < cnt) ? m : cnt;
        p->x58 -= m;
    }
    SignalSema(p->x40);
    return 1;
}
