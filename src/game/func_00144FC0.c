#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
u8 func_0013E220(void *p);
void func_001A9EC0(s16 i);
void func_001A9F10(s16 i);
void func_001A9FA0(s16 i);

void func_00144FC0(void)
{
    s16 i = func_0013E220(D_00201FA8->p);
    func_001A9FA0(i);
    func_001A9EC0(i);
    func_001A9F10(i);
}
