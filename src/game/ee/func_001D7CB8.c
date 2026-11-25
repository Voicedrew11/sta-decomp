#include "common.h"

typedef struct { u8 name[6]; char rest[0x1BA]; } E;
extern E D_004B6A74[];

void func_001D7CB8(s32 i, s32 j, u8 *src)
{
    s32 k;
    u8 *d = D_004B6A74[i * 4 + j].name;
    for (k = 0; k < 6; k++)
        *d++ = src[k];
}
