#include "common.h"
void FlushCache(s32);                        /* extern */
void memset(s32 *, s32, s32);        /* extern */
extern s32 D_0020200C;
extern s64 D_00202010;
extern s32 D_00438A30[];
extern s32 D_00438A70[];
extern s32 D_0043F080[];
extern s32 D_004830F0[];
extern s32 D_004830F4[];

void func_00176A60(void) {
    (*D_004830F4) = 0;
    (*D_004830F0) = 1;
    FlushCache(0);
    func_00178D20();
    func_00178C00((s32) D_00438A70, 0x6610U);
    func_00178C00((s32) D_0043F080, 0x40000U);
    D_0020200C = 0;
    D_00202010 = 0;
    memset(D_00438A30, 0, 0x33);
}
