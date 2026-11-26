#include "common.h"
void FlushCache(s32, s32);                   /* extern */
s32 sceSifSetDma(s32 *, s32);                   /* extern */
extern s32 D_004BAA2C[];
extern s32 D_004BAA40[];
extern s32 D_004BAA44[];
extern u32 D_004BAA48[];
extern u32 D_004BAA4C[];
extern u32 D_004BAA50[];
extern s32 D_004BAA54[];
extern s32 D_004BAA58[];
extern s32 D_004BAA60[];
extern s32 D_004BAA64[];
extern u32 D_004BAA68[];
extern s32 D_004BAA6C[];

s32 func_001DB9B0(s32 arg0, s32 arg1, u32 arg2) {
    (*D_004BAA44) = arg1;
    (*D_004BAA40) = arg0;
    (*D_004BAA58) = 1;
    (*D_004BAA48) = arg2;
    if (arg2 > 0x4000) {
        (*D_004BAA4C) = 0x4000;
        (*D_004BAA50) = 0x4000;
    } else {
        (*D_004BAA4C) = arg2;
        (*D_004BAA50) = arg2;
        (*D_004BAA4C) = ((*D_004BAA4C) + 0xF) & ~0xF;
    }
    (*D_004BAA6C) = 0;
    (*D_004BAA60) = (*D_004BAA44);
    (*D_004BAA64) = (*D_004BAA2C);
    (*D_004BAA68) = (*D_004BAA4C);
    FlushCache(0, (*D_004BAA44));
    (*D_004BAA54) = sceSifSetDma(D_004BAA60, 1);
    if ((*D_004BAA54) == 0) {
        return -1;
    }
    return 0;
}
