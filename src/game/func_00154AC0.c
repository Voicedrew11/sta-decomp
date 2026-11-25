#include "common.h"

extern s32 D_002F1990[];
extern s32 D_002F19AC[];

s32 func_00154AC0(void)
{
    return (D_002F1990[0] - D_002F19AC[0]) / 16;
}
