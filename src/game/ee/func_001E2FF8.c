#include "common.h"
s32 func_001E2FF8(u16 c) {
    if ((u16)(c - '0') < 10) return c - '0';
    if ((u16)(c - 'a') < 6) return c - 'a' + 10;
    if ((u16)(c - 'A') < 6) return c - 'A' + 10;
    return -1;
}
