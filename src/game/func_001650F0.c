#include "common.h"
void func_001650F0(u8 *o, u8 i, u8 j, u16 v)
{
    u8 *p = (u8 *)(j * 8 + (s32)(o + i * 0x258));
    *(s32 *)(p + 0x36C) = 3;
    *(s32 *)(p + 0x370) = v;
}
