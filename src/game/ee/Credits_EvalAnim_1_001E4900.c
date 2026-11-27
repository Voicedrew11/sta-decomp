#include "common.h"
typedef struct { u32 start; u32 x4; u8 x8; u8 pad[0x17]; } E;
typedef struct { u16 cnt[2]; u8 x4; u8 x5; u8 pad6[2]; s32 off[2]; u8 pad10[4]; u32 x14; } H;
void Credits_EvalRect_1_001E4A18(u32, E *, s32, u8);
void Credits_EvalColor_1_001E4C90(u32, E *, s32);

s32 Credits_EvalAnim_1_001E4900(u32 x, H *h, s32 a2) {
    s32 i;
    s32 n;
    E *e;
    s32 o;

    if (x < h->x14) return 0;
    x -= h->x14;
    for (i = 0; i < 2; i++) {
        o = h->off[i];
        if (o == 0) continue;
        e = (E *)((u8 *)h + o);
        e++;
        n = h->cnt[i] - 1;
        while (n != 0 && x >= e->start) { n--; e++; }
        e--;
        if (n == 0) return 0;
        if (e->x8 == 1) return 0;
        if (i == 0) {
            Credits_EvalRect_1_001E4A18(x, e, a2, h->x5);
        } else {
            Credits_EvalColor_1_001E4C90(x, e, a2);
        }
    }
    return 1;
}

