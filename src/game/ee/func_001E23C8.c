#include "common.h"
typedef struct { s32 x0; s16 x4; s16 x6; s32 x8; s32 xC; u8 p[0x18]; s32 x28; s16 x2C; } S;
extern S *D_00201E5C;
void func_001E2148(void);
void func_001E21E0(void);
s32 func_001E23C8(void) {
    S *s = D_00201E5C;
    if (s->x28 == 0) return -1;
    if (++s->x0 != 1) return 0;
    func_001E2148();
    D_00201E5C->x2C = 0;
    D_00201E5C->x4 = 0;
    D_00201E5C->xC = D_00201E5C->x8;
    func_001E21E0();
    return 0;
}

