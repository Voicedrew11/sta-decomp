#include "common.h"
extern s16 D_001F37B0[];
typedef struct { s8 pad[0x40]; u32 bits[(0x1C0 - 0x40) / 4]; } Rec;
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
void MapState_SetBit_0_001A9CA0(s32 id, s16 k) {
    u32 idx = find(id);
    if (idx != -1) {
        D_00201DC4[idx].bits[k / 32] |= 1 << (k % 32);
    }
}
