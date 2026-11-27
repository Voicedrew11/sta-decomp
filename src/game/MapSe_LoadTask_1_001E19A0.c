#include "common.h"
typedef struct { u8 pad[0x14]; s32 x14; u64 b0:1; u64 b1:1; u64 rest:62; } S22C4;
void FlushCache(s32);
void memcpy(s32, s32 *, s32);
void Snd_SetStreamId_0_0012C790(s32);
void Snd_StartStream1_0_0012DD10(s32);
void Task_RunWrap_0_0014DAB0(s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
void Task_AddWrap_0_0014DAD0(s32);
void Task_RemoveWrap_0_0014DAE0(s32);
s32 Task_KillWrap_0_0014DAF0(s32);
s32 Task_SetPriorityWrap_0_0014DB00(s8 *, s32, s32 *);
s32 File_HashName_3_00159D10(s8 *);
s32 File_GetSectorOrSize_0_0015A300(s32);
void File_Close_2_0015AB80(s32);
s32 Arc_FindByHash_2_0015ABD0(s32);
void Dma_SprCopy_1_001789E0(s32, s32 *, s32);
void MapSe_BindBank_0_001E1810(s32, s32);
void sprintf(s8 *, s32 *, s32);
extern s32 D_001FE8A0[];
extern S22C4 *D_002022C4;
extern s32 D_00222B54[];
extern s32 D_00270F40[];
extern s32 D_004BC2D0[];
extern s32 D_004BC2D4[];
extern s32 D_004BC2D8[];
extern s32 D_004BC2DC[];
extern s32 D_004BC2E0[];
extern u32 D_004BC2E4[];
extern u32 D_004BC2E8[];

static inline u32 umin(u32 a, u32 b) { return a > b ? b : a; }
void MapSe_LoadTask_1_001E19A0(void) {
    s8 buf[256];
    s32 rem;
    s32 q;
    s32 sz;
    s32 n;
    s32 h;
    s32 off;

    if (D_002022C4 == 0) return;
    if (D_002022C4->b1 && D_002022C4->x14 != 0) return;
    if (*D_004BC2D0 != -1) {
        if (*D_004BC2E0 != 0) {
            if ((u8)Task_KillWrap_0_0014DAF0(*D_004BC2E0)) {
                Task_AddWrap_0_0014DAD0(*D_004BC2E0);
            } else {
                Task_RunWrap_0_0014DAB0(*D_004BC2E0);
                *D_004BC2E0 = 0;
            }
        }
        if (*D_004BC2E0 == 0) {
            *D_004BC2DC = 0;
            *D_004BC2D4 = *D_004BC2D0;
            *D_004BC2D0 = -1;
            sprintf(buf, D_001FE8A0, *D_004BC2D4 / 10);
            h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf));
            sz = File_GetSectorOrSize_0_0015A300(h);
            File_Close_2_0015AB80(h);
            *D_004BC2E4 = sz;
            *D_004BC2E8 = 0;
            *D_004BC2E0 = Task_SetPriorityWrap_0_0014DB00(buf, 0x101, D_00270F40);
            if (*D_004BC2E0 == 0) {
                if (*D_004BC2E0 != 0) {
                    Task_AddWrap_0_0014DAD0(*D_004BC2E0);
                    *D_004BC2E0 = 0;
                }
                *D_004BC2D8 = 0;
                *D_004BC2E0 = 0;
                *D_004BC2D4 = -1;
                *D_004BC2D0 = -1;
                *D_004BC2DC = 0;
                return;
            }
            Task_FlushWrap_0_0014DAC0(*D_004BC2E0, 0);
        }
    } else if (*D_004BC2D4 != -1) {
        switch ((u8)Task_KillWrap_0_0014DAF0(*D_004BC2E0)) {
        case 0:
            break;
        case 5:
            n = *D_004BC2E4 - *D_004BC2E8;
            n = umin(n, 0x80000);
            q = n >> 4;
            off = q << 4;
            rem = n - off;
            FlushCache(0);
            Dma_SprCopy_1_001789E0(*D_00222B54 + *D_004BC2E8, D_00270F40, q);
            if (rem > 0) {
                memcpy(*D_00222B54 + off, (s32 *)((u8 *)D_00270F40 + off), rem);
            }
            *D_004BC2E8 += n;
            Task_RemoveWrap_0_0014DAE0(*D_004BC2E0);
            break;
        case 1:
        case 2:
        case 4:
            break;
        case 3:
        case 6:
            if (*D_004BC2DC == 0) {
                MapSe_BindBank_0_001E1810(*D_00222B54, *D_00222B54);
                Snd_SetStreamId_0_0012C790(*D_004BC2D4);
                Snd_StartStream1_0_0012DD10(*D_004BC2D4);
                *D_004BC2DC = 1;
            }
            break;
        }
    }
}
