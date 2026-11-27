#include "common.h"

typedef struct { unsigned char : 0; unsigned char f : 1; } B;
extern u8 *D_00201DC8;

void Bestiary_SetKilled_1_001A9FA0(s16 i)
{
    if (0 > i || i > 0x80)
        return;
    ((B *)&D_00201DC8[i])->f = 1;
}
