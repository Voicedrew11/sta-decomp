#include "common.h"
typedef struct { u8 pad[0x22]; s16 x22; } Owner;
typedef struct { s16 prev, next, fnext, fprev; u16 off, size; Owner *owner; } Blk;
extern Blk D_0047F0C0[];
extern s16 D_004830DC[];
extern s32 D_004830E0[];
extern s32 D_004830E8[];
s32 func_00176FB0(s32);
void func_001769C0(void) {
    s32 b;
    D_004830E8[0] = 0;
    D_004830E0[0] = 0;
    b = D_004830DC[0];
    if (b != -1) {
        do {
            D_0047F0C0[b].owner->x22 = -1;
            func_00176FB0(b);
        } while ((b = D_004830DC[0]) != -1);
    }
}
