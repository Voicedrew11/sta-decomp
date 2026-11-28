#include "common.h"
extern s32 D_00201C84;
extern s32 D_00201C88;

s32 Rand_Next_3_0015ED20(void) {
    D_00201C84 = D_00201C88 + (D_00201C84 * 0x85);
    D_00201C88 = (D_00201C84 * 5) + (D_00201C88 * 7);
    return D_00201C84 ^ D_00201C88;
}
