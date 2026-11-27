#include "common.h"
typedef struct { s32 v; s32 pad[7]; } E;
extern E D_004BA500[];
s32 Se_FindFreeSlot_0_001DB6B0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_004BA500[i].v == 0) break;
    }
    if (i >= 16) return -1;
    return i;
}
