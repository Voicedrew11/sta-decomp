#include "common.h"

extern s32 D_004A4390[];
extern struct { unsigned char : 2; unsigned char f : 1; char pad[15]; } D_004A43AC;

void func_001A3F80(void)
{
    D_004A4390[0] = 0;
    D_004A43AC.f = 1;
}
