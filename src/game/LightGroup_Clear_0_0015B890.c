#include "common.h"

typedef struct { u8 b[0x1000]; } E;
extern E D_0030A2D0[];
extern u16 D_0030C3D0[];
extern u16 D_0030C3D4[];
void *memset(void *p, s32 c, u32 n);

void LightGroup_Clear_0_0015B890(s32 i)
{
    memset(D_0030A2D0[i].b + 0x100, 0, 0x1000);
    D_0030C3D0[i] = 0;
    D_0030C3D4[i] = 0;
}
