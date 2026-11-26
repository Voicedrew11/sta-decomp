#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s16 x14; char rest[0xA]; } E;
extern E D_004BA500[16];
s32 func_001D8680(s32 a, s32 b, s32 c, ...);
s32 func_001DAEF0(s32 v, s32 i, s32 c) {
    E *e;
    if (v < 0 || v >= 16) return -1;
    if (i < 0 || i >= 16) return -1;
    e = &D_004BA500[i];
    e->x14 = v;
    return -(func_001D8680(4, 1, 0x10100, e->x14, e->x8, e->x0, c) != 0);
}
