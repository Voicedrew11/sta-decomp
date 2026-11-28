#include "common.h"
typedef struct { u8 b[0x1000]; } E_LightGroup_Clear_0_0015B890;
typedef struct { u8 b[0x40]; } E_LightGroup_Get_0_0015B900;
typedef struct { char pad[0x100]; E_LightGroup_Get_0_0015B900 e[0x3C]; } B;
extern E_LightGroup_Clear_0_0015B890 D_0030A2D0[];
extern u16 D_0030C3D0[];
extern u16 D_0030C3D4[];
extern char D_0030A310[];
extern char D_0030A390[];
void LightGroup_Clear_0_0015B890(s32 i);
void* LightGroup_Get_0_0015B900(s32 i);
void* memset(void *p, s32 c, u32 n);

/* LightGroup_Clear_0_0015B890 */
void LightGroup_Clear_0_0015B890(s32 i)
{
    memset(D_0030A2D0[i].b + 0x100, 0, 0x1000);
    D_0030C3D0[i] = 0;
    D_0030C3D4[i] = 0;
}

/* LightGroup_Get_0_0015B900 */
#define D_0030A2D0 D_0030A2D0__as_LightGroup_Get_0_0015B900
extern B D_0030A2D0__as_LightGroup_Get_0_0015B900[];

void *LightGroup_Get_0_0015B900(s32 i)
{
    if (i < 0) {
        if (i == -1)
            return D_0030A310;
        return D_0030A390;
    }
    return &D_0030A2D0[i / 64].e[i % 64];
}
#undef D_0030A2D0
