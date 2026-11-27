#include "common.h"

extern s32 D_00202284;
void Arc_LoadFile_2_00159DD0(s32 id, void *p, s32 **a, s32 *b);

s32 EnemyType_LoadTable_0_001A83A0(void *p)
{
    s32 b;
    s32 *a;
    Arc_LoadFile_2_00159DD0(0x3F114AF, p, &a, &b);
    D_00202284 = *a;
    return 0;
}
