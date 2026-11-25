#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
s32 func_0013F750(void *p);
void func_0013D540(u8 a, u8 b, u16 c);

void func_00144490(u8 *o)
{
    u8 a = o[8];
    u8 b = o[0x10];
    func_0013D540(a, b, func_0013F750(D_00201FA8->p));
}
