#include "common.h"
s32 sceSifAllocIopHeap(u32);                        /* extern */
extern s32 D_004BA2E0[];
extern s32 D_004BA2E8[];
extern s32 D_004BA2EC[];
extern s32 D_004BA2F0[];
extern u32 D_004BA2F4[];
extern s32 D_004BA2F8[];

s32 func_001DB410(void) {
    if ((*D_004BA2EC) != 0) {
        return -1;
    }
    (*D_004BA2F4) = 0x80000;
loop_3:
    (*D_004BA2F4) = (u32) (*D_004BA2F4) >> 1;
    (*D_004BA2EC) = sceSifAllocIopHeap((*D_004BA2F4));
    if (((*D_004BA2EC) == 0) && ((u32) (*D_004BA2F4) < 0x4000U)) {
        return -1;
    }
    if ((*D_004BA2EC) != 0) {
        (*D_004BA2F0) = 0;
        (*D_004BA2F8) = -1;
        (*D_004BA2E0) = 0;
        (*D_004BA2E8) = 0;
        return 0;
    }
    goto loop_3;
}
