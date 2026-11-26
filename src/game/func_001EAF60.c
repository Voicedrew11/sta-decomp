#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; u8 pad[0x24]; s32 x40; } S;
void WaitSema(s32);
void SignalSema(s32);
void func_001EAF60(S *s, s32 *a1, s32 *a2, s32 *a3, s32 *a4) {
    s32 b, a, r, n;
    WaitSema(s->x40);
    a = s->x10; b = s->x14;
    r = (s32)((u8 *)((s->xC + a) * 0x800) + b) % s->x18;
    n = (s->x8 - 2 - a) * 0x800 - b;
    if (s->x18 - r >= n) {
        *a1 = s->x0 + r;
        *a2 = n;
        *a3 = 0;
        *a4 = 0;
    } else {
        *a1 = s->x0 + r;
        *a2 = s->x18 - r;
        *a3 = s->x0;
        *a4 = n - (s->x18 - r);
    }
    SignalSema(s->x40);
}
