#include "common.h"

extern struct { char pad[0x20]; s32 n[30]; s32 err; } D_004B63B8;

s32 Mc_CheckRoom_4_001D70B8(s32 i, s32 j, u32 k)
{
    s32 v = D_004B63B8.n[i * 4 + j] - 2;
    if (v <= 0) {
        D_004B63B8.err = 30;
        return -1;
    }
    if ((u32)v < k) {
        D_004B63B8.err = 31;
        return -2;
    }
    return k;
}
