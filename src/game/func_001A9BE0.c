#include "common.h"
typedef struct { u8 pad[0x40]; u32 x40[8]; u8 pad2[0x160]; } G;
extern G *D_00201DC4;
extern s16 D_001F37B0[];
static inline s32 find(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 func_001A9BE0(s32 k, s16 b) {
    s32 i = find(k);
    if (i == -1) return 0;
    return (D_00201DC4[i].x40[b / 32] & (1 << (b % 32))) != 0;
}

