#include "common.h"

typedef struct { char pad[0x164]; u16 flags; char rest[0x5A]; } E;
extern E D_004B6900[];

void func_001D7C80(s32 i, s32 j, u16 v)
{
    E *e = &D_004B6900[i * 4 + j];
    e->flags &= ~v;
}
