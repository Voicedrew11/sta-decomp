#include "common.h"

extern s32 D_00202140;
extern struct { unsigned char : 1; unsigned char f : 1; char pad[15]; } D_004A1194;

void func_00193850(int v)
{
    D_00202140 = v != 0;
    D_004A1194.f = 1;
}
