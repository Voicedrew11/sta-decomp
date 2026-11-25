#include "common.h"

typedef struct { u8 b[0x600]; } E;
extern E D_0030C420[];
extern u16 D_0030D0D4[];
void *memset(void *p, s32 c, u32 n);

void func_0015C6D0(s32 i)
{
    memset(D_0030C420[i].b + 0xB0, 0, 0x600);
    D_0030D0D4[i] = 0;
}
