#include "common.h"

typedef struct { s32 x0; s32 h; char p8[0x114]; } E;
extern E D_004BB110[16];
extern char D_004BB050[];
void *memset(void *p, s32 c, u32 n);
void Task_Register_0_0014DB10(void (*f)(void));
void MapSe_StreamUpdate_0_001E1250(void);
void Task_RunWrap_0_0014DAB0(s32 h);

void ImageLoader_Init_0_001E1770(void)
{
    s32 i;
    E *e;
    memset(D_004BB110, 0, 0x11C0);
    memset(D_004BB050, 0, 0xC0);
    Task_Register_0_0014DB10(MapSe_StreamUpdate_0_001E1250);
    e = D_004BB110;
    for (i = 0; i < 16; i++, e++) {
        if (e->h) {
            Task_RunWrap_0_0014DAB0(e->h);
            e->h = 0;
        }
        memset(e, 0, 0x11C);
    }
}
