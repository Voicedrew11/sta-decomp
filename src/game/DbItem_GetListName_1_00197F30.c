#include "common.h"

extern char D_001FD388[];
s32 Save_TestItemBit_1_001A9B40(s16 i);
char *DbItem_Find_1_0019D510(s32 i);

char *DbItem_GetListName_1_00197F30(s32 i)
{
    if (i < 0)
        return D_001FD388;
    if (Save_TestItemBit_1_001A9B40(i))
        return DbItem_Find_1_0019D510(i);
    return D_001FD388;
}
