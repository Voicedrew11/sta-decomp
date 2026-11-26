#include "common.h"
extern s32 D_004BA700[];
s32 func_001DAC30(void) {
    s32 *p = D_004BA700;
    s32 r = -1;
    s32 i;
    for (i = 0; i < 8; i++, p += 4) {
        if (*p == 0) { r = i; break; }
    }
    return r;
}
