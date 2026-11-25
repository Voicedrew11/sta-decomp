#include "common.h"

extern struct { u16 a; u16 b; char pad[12]; } D_004B9FA8;
void func_001D8680(s32 a, s32 b, s32 c, ...);

void func_001D9650(u16 a, u16 b)
{
    D_004B9FA8.a = a;
    D_004B9FA8.b = b;
    func_001D8680(3, 0, 0x2080000, D_004B9FA8.a, D_004B9FA8.b);
}
