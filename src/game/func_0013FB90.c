#include "m2c.h"
typedef struct { u8 pad[0x81]; u8 unk81; u8 unk82[0x499]; s8 *unk51C; } A;

u8 func_0013FB90(A *a0, s32 arg1, s32 *arg2, s32 *arg3) {
    u8 r = 0;
    s8 *p;
    if (a0->unk81 == 0) {
        *arg2 = 0;
        *arg3 = 0;
        return r;
    }
    p = a0->unk51C + a0->unk82[arg1 & 0xFF] * 0x170;
    *arg2 = (s32)(p + 0x90);
    *arg3 = (s32)(p + 0x80);
    if (!(((u8 *)p)[0x160] & 1)) {
        r = 1;
    }
    return r;
}
