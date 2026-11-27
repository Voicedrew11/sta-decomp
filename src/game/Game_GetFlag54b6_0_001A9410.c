#include "common.h"
extern u8 D_00222A54[];

u64 Game_GetFlag54b6_0_001A9410(void) {
    return (u64) ((s64) (*D_00222A54) << 0x39) >> 0x3F;
}
