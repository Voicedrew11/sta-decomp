#include "common.h"

typedef struct { char pad[0x10]; s32 v; } T;
extern s32 D_003174F0[];
extern s32 D_00201F2C, D_00201F94, D_00201F9C, D_00201F98;
extern T *D_00201FA0;
T *func_001777C0(s32 a, s32 b, s32 c);

void func_00164350(void)
{
    D_003174F0[D_00201F2C] = 0;
    D_00201F94 = 0;
    D_00201F9C = 0;
    D_00201FA0 = func_001777C0(4, 0, 0);
    D_00201F98 = D_00201FA0->v;
}
