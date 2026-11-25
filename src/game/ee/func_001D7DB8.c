#include "common.h"

typedef struct { char pad[0x17F]; u8 a; s8 b; char rest[0x3F]; } E;
extern E D_004B6900[];

void func_001D7DB8(s32 i, s32 j, s8 v)
{
    E *e = &D_004B6900[i * 4 + j];
    e->b = v;
    e->a = 0;
}
