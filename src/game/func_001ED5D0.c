#include "common.h"
void memset(s32 *, s32, s32);        /* extern */
extern s8 D_004BD310[];
extern s8 D_004BD311[];
extern s8 D_004BD312[];
extern s8 D_004BD313[];
extern s32 D_004BD314[];
extern s32 D_004BD318[];
extern s32 D_004BD31C[];

void func_001ED5D0(s8 arg0, s8 arg1, s8 arg2, s32 arg3) {
    (*D_004BD314) = arg3;
    (*D_004BD310) = arg0;
    (*D_004BD311) = arg1;
    (*D_004BD312) = arg2;
    (*D_004BD313) = 0;
    (*D_004BD318) = 0;
    memset(D_004BD31C, 0, 0x28);
}
