#include "common.h"

typedef struct { s32 v; char pad[12]; } E;
extern E D_004BA70C[];
void func_001D8680(s32 a, s32 b, s32 c, ...);

void func_001DA8F0(s32 i, s16 b)
{
    func_001D8680(4, 0, 0x20A00, D_004BA70C[i].v, b);
}
