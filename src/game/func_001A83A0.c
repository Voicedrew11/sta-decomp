#include "common.h"

extern s32 D_00202284;
void func_00159DD0(s32 id, void *p, s32 **a, s32 *b);

s32 func_001A83A0(void *p)
{
    s32 b;
    s32 *a;
    func_00159DD0(0x3F114AF, p, &a, &b);
    D_00202284 = *a;
    return 0;
}
