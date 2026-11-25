#include "common.h"

typedef struct { unsigned int : 1; unsigned int f : 1; } B;
extern u8 *D_00201DC8;

s32 func_001A9EC0(s16 i)
{
    if (0 > i || i > 0x80)
        return 0;
    return ((B *)&D_00201DC8[i])->f;
}
