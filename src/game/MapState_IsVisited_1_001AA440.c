#include "common.h"
typedef struct { u8 pad[0x50]; Flags8 x50; u8 pad2[0x16F]; } G;
extern G *D_00201DC4;
extern s16 D_001F37B0[];
static inline s32 find(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}
s32 MapState_IsVisited_1_001AA440(s32 k) {
    s32 i = find(k);
    if (i == -1) return 0;
    return D_00201DC4[i].x50.f.b0;
}

