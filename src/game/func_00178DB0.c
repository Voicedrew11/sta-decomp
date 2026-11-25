#include "common.h"
void memset(s32 *, s32, s32);        /* extern */
extern s32 D_00483100[];

void func_00178DB0(void) {
    memset(D_00483100, 0, 0x3000);
}
