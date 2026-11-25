#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void func_0013E8F0(void *arg0, u8 arg1);

void func_00144E00(u8 *arg0)
{
    func_0013E8F0(D_00201FA8->p, arg0[8]);
}
