#include "common.h"
s32 DIntr(void);
s32 EIntr(void);
s32 SignalSema(s32);
s32 WaitSema(s32);
typedef struct { u32 x0; u32 x4; s32 x8; s32 xC; s32 x10; s32 p14[2]; u32 x1C; u32 x20; u32 x24; u32 x28; s32 x2C; s32 x30; s32 x34; u32 x38; s32 x3C; s32 sema; s32 x44; } S;
#define R(a) (*(volatile u32 *)(a))
#define OR(a, b) ((a) | (b))

s32 func_001EA750(S *s) {
    s32 v;
    u32 cmd;
    u32 madr;
    u32 qwc;
    u32 tadr;
    u32 chcr;
    u32 ctrl;
    s32 fifo;
    u32 cur;
    s32 same;
    u32 sz;
    s32 n;
    u32 base;
    s32 d;
    u32 end;
    u32 i;
    u32 j;
    u32 a;

    ctrl = s->x38;
    a = (ctrl >> 16) & 3;
    cmd = ctrl & 0x7F;
    fifo = a + ((ctrl >> 8) & 0xF);
    madr = s->x1C - fifo * 16;
    qwc = s->x24 + fifo;
    tadr = s->x20;
    chcr = OR(s->x28, 0x100);
    WaitSema(s->sema);
    if (madr < s->x0) {
        qwc = (s->x0 - madr) >> 4;
        same = 1;
        n = s->x8;
        tadr = s->x4 & 0x0FFFFFFF;
        sz = n << 11;
        madr += sz;
        if (s->x1C != s->x0 && s->x1C != s->x0 + sz) same = 0;
        chcr = (s->x28 & 0x0FFFFFFF) | ((same ? 0 : 3) << 28) | 0x100;
        d = (n - s->xC) % n;
        if (0 > d || d >= s->x10) {
            s->xC = n - 1;
            s->x10++;
        }
    } else {
        n = (*s).x8;
        base = s->x4;
        cur = s->x1C;
        end = (base + (n + 1) * 16) & 0x0FFFFFFF;
        i = (cur == end) ? 0 : (cur - s->x0) >> 11;
        j = (madr == end) ? 0 : (madr - s->x0) >> 11;
        if (i != j) {
            tadr = (base + i * 16) & 0x0FFFFFFF;
            qwc = (s->x0 + (i << 11) - madr) >> 4;
            same = (s->x0 + (cur - s->x0) % (u32)(n << 11) == s->x0 + (((s->xC + s->x10) % n) << 11)) ? 0 : 3;
            chcr = (s->x28 & 0x0FFFFFFF) | (same << 28) | 0x100;
            d = (s32)(j + n - s->xC) % n;
            if (0 > d || d >= s->x10) {
                s->xC = j;
                s->x10++;
            }
        }
    }
    if (s->x2C && s->x30) {
        R(0x1000B010) = s->x2C;
        R(0x1000B020) = s->x30;
        v = s->x34 | 0x100;
        DIntr();
        R(0x1000F590) = R(0x1000F520) | 0x10000;
        R(0x1000B000) = v;
        R(0x1000F590) = R(0x1000F520) & ~0x10000;
        EIntr();
    }
    if (s->x10) {
        while ((s32)R(0x10002010) < 0);
        R(0x10002000) = cmd;
        while ((s32)R(0x10002010) < 0);
    }
    R(0x1000B410) = madr;
    R(0x1000B430) = tadr;
    R(0x1000B420) = qwc;
    if (s->x10) {
        DIntr();
        R(0x1000F590) = R(0x1000F520) | 0x10000;
        R(0x1000B400) = chcr;
        R(0x1000F590) = R(0x1000F520) & ~0x10000;
        EIntr();
    }
    R(0x10002010) = s->x3C;
    s->x44 = 1;
    SignalSema(s->sema);
    return 1;
}
