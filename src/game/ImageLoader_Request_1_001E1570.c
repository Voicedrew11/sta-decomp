#include "common.h"
typedef struct { s32 x0; s32 h; u8 p8[0x10]; s32 x18; char name[0x100]; } E_ImageLoader_Request_1_001E1570;
typedef struct { s32 x0; s32 x4; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 4; } S;
typedef struct { s32 x0; s32 h; char p8[0x114]; } E_ImageLoader_Init_0_001E1770;
extern E_ImageLoader_Request_1_001E1570 D_004BB110[16];
extern S D_004BB050[];
extern s32 D_002023B0;
S* ImageLoader_Request_1_001E1570(const char *name, s32 idx);
void ImageLoader_SetFlag_0_001E1760(s32 arg0);
void ImageLoader_Init_0_001E1770(void);
void* memset(void *p, s32 c, u32 n);
char* strcpy(char *dst, const char *src);
void Task_RunWrap_0_0014DAB0(s32 h);
void Pool_Free_2_00128580(s32, s32);
void Task_Register_0_0014DB10(void (*f)(void));
void MapSe_StreamUpdate_0_001E1250(void);

/* ImageLoader_Request_1_001E1570 */
S *ImageLoader_Request_1_001E1570(const char *name, s32 idx)
{
    S *s;

    s = &D_004BB050[idx];
    if (s->x0) {
        if (s->x0 && s->b0) {
            Pool_Free_2_00128580(D_002023B0, s->x0);
            s->x0 = 0;
            s->b0 = 0;
            s->b1 = 0;
            s->b2 = 0;
            s->b3 = 1;
        }
        if (s->x0) {
            Pool_Free_2_00128580(D_002023B0, s->x0);
        }
        if (D_004BB110[idx].h) {
            Task_RunWrap_0_0014DAB0(D_004BB110[idx].h);
            D_004BB110[idx].h = 0;
        }
        memset(&D_004BB110[idx], 0, 0x11C);
    }
    strcpy(D_004BB110[idx].name, name);
    s->b0 = 0;
    s->b1 = 1;
    s->b2 = 0;
    D_004BB110[idx].x18 = 1;
    return s;
}

/* ImageLoader_SetFlag_0_001E1760 */
void ImageLoader_SetFlag_0_001E1760(s32 arg0) {
    D_002023B0 = arg0;
}

/* ImageLoader_Init_0_001E1770 */
#define D_004BB110 D_004BB110__as_ImageLoader_Init_0_001E1770
extern E_ImageLoader_Init_0_001E1770 D_004BB110__as_ImageLoader_Init_0_001E1770[16];
#define D_004BB050 D_004BB050__as_ImageLoader_Init_0_001E1770
extern char D_004BB050__as_ImageLoader_Init_0_001E1770[];

void ImageLoader_Init_0_001E1770(void)
{
    s32 i;
    E_ImageLoader_Init_0_001E1770 *e;
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
#undef D_004BB110
#undef D_004BB050
