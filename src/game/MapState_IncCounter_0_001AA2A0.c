#include "m2c.h"
extern s16 D_001F37B0[];
typedef struct { s8 pad[0x20]; u32 bits[(0x1C0 - 0x20) / 4]; } Rec;
extern Rec *D_00201DC4;
static inline u32 find(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
static inline u32 get(s32 id, s16 k) {
    u32 i = find(id);
    if (i == -1) {
        return 0;
    }
    return (D_00201DC4[i].bits[k / 8] >> (k % 8 * 4)) & 0xF;
}

void MapState_IncCounter_0_001AA2A0(s32 id, s16 k) {
    u32 idx = find(id);
    u32 v = get(id, k) + 1;
    if (idx != -1) {
        if (v > 16) {
            v = 16;
        }
        D_00201DC4[idx].bits[k / 8] &= ~(0xF << (k % 8 * 4));
        D_00201DC4[idx].bits[k / 8] |= v << (k % 8 * 4);
    }
}
