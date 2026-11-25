#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
void func_0013F760(void *arg0, u8 arg1);

void func_00144FB0(u8 *arg0)
{
    func_0013F760(D_00201FA8->p, arg0[8]);
}
