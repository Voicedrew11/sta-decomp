#include "common.h"

extern struct { char pad[0x60]; s32 a[4]; s32 b[4]; char p80[8]; s32 state; s32 x8c; } D_004B63B8;
s32 sceMcInit(void);

s32 func_001D6F80(void)
{
    s32 r = sceMcInit();
    s32 i;
    if (r == 0) {
        D_004B63B8.state = 0;
        D_004B63B8.x8c = 0;
        for (i = 0; i < 4; i++) {
            D_004B63B8.a[i] = 0;
            D_004B63B8.b[i] = 0;
        }
    }
    return r;
}
