#include "common.h"
typedef struct { u8 pad[0x8C]; s16 x8C; s16 x8E; u8 p90[0xC4]; s32 *x154; u8 p158[0x80]; u8 b0:1; } O;
extern O **D_002022BC;
s32 func_001ACD90(O **a0, s16 bit) {
    s32 m;
    s32 n;
    O *o;
    O *p;
    s16 idx;
    s32 *tbl;
    s16 a;
    m = 0;
    n = 0;
    if (a0 == 0 || (o = *a0) == 0 || !o->b0) return 0;
    if (bit == -1) return 1;
    a = o->x8E;
    idx = o->x8C;
    tbl = o->x154;
    if (a != -2) idx = a;
    if (idx != -1) m = tbl[idx];
    if (D_002022BC && (p = *D_002022BC) && p != o && p->x8C != -1) n = p->x154[p->x8C + 0x20];
    if (idx == -1) {
        if (!(n & (1 << bit))) return 0;
    } else {
        if (!(m & (1 << bit))) return 0;
    }
    return 1;
}
