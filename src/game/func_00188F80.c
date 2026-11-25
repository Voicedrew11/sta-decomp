#include "common.h"

extern volatile u32 D_004A0B0C[];
extern f32 D_002020D4;
void func_0018A200(void);

void func_00188F80(void)
{
    D_004A0B0C[0] = 60;
    D_002020D4 += 60.0f / D_004A0B0C[0];
    func_0018A200();
}
