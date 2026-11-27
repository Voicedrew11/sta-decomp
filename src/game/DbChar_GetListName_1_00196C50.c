#include "common.h"

extern char D_001FD358[];
s32 Bestiary_IsSeen_2_001A9EC0(s16 i);
char *DbChar_GetName_0_00195970(s32 i);

char *DbChar_GetListName_1_00196C50(s32 i)
{
    if (i < 0)
        return D_001FD358;
    if (Bestiary_IsSeen_2_001A9EC0(i))
        return DbChar_GetName_0_00195970(i);
    return D_001FD358;
}
