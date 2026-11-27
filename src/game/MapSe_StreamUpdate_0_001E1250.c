#include "common.h"
typedef struct { s32 x0; s32 h; s32 x8; s32 xC; s32 *x10; s32 x14; s32 x18; char name[0x100]; } E;
typedef struct { s32 x0; s32 x4; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 4; } S;
typedef struct { u8 p0[0x14]; s32 x14; u8 b0 : 1; u8 b1 : 1; u8 b2 : 6; } P;
typedef struct { u8 b0 : 3; u8 b3 : 3; u8 b6 : 2; } G;
extern E D_004BB110[16];
extern S D_004BB050[];
extern P *D_002023B0;
extern s32 D_00201E54;
extern G D_00222A54[];
extern s32 D_00270F40[];
void *memset(void *p, s32 c, u32 n);
void memcpy(s32, s32 *, u32);
s32 *Pool_Alloc_3_001288C0(P *, s32);
void Task_RunWrap_0_0014DAB0(s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
void Task_RemoveWrap_0_0014DAE0(s32);
s32 Task_KillWrap_0_0014DAF0(s32);
s32 Task_SetPriorityWrap_0_0014DB00(char *, s32, s32 *);
s32 File_HashName_3_00159D10(char *);
s32 File_GetSectorOrSize_0_0015A300(s32);
void File_Close_2_0015AB80(s32);
s32 Arc_FindByHash_2_0015ABD0(s32);

void MapSe_StreamUpdate_0_001E1250(void) {
    S *s;
    E *e;
    s32 i;
    s32 h;
    u32 n;

    if (D_002023B0 != NULL && (!D_002023B0->b1 || D_002023B0->x14 == 0)) {
        if (D_00201E54 == -1) {
            for (i = 0; i < 16; i++) {
                if (D_004BB110[i].x0 == 0 && D_004BB110[i].x18 != 0) {
                    D_00201E54 = i;
                    return;
                }
            }
            return;
        }
        e = &D_004BB110[D_00201E54];
        s = &D_004BB050[D_00201E54];
        if (e->x10 == NULL) {
            if (&e->x8 != NULL) {
                h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(e->name));
                e->x8 = File_GetSectorOrSize_0_0015A300(h);
                File_Close_2_0015AB80(h);
            }
            e->h = Task_SetPriorityWrap_0_0014DB00(e->name, 0xFE, D_00270F40);
            e->x10 = Pool_Alloc_3_001288C0(D_002023B0, e->x8);
            Task_FlushWrap_0_0014DAC0(e->h, 0);
            e->xC = 0;
            s->b1 = 1;
            return;
        }
        switch ((u8)Task_KillWrap_0_0014DAF0(e->h)) {
        case 0:
            break;
        case 5:
            n = e->x8 - e->xC;
            n = (n > 0x80000) ? 0x80000 : n;
            memcpy(*e->x10 + e->xC, D_00270F40, n);
            e->xC += n;
            Task_RemoveWrap_0_0014DAE0(e->h);
            break;
        case 3:
        case 6:
            if (e->x0 == 0) {
                s->x0 = (s32)D_004BB110[D_00201E54].x10;
                s->b1 = 0;
                s->b0 = 1;
                i = D_00201E54;
                if (D_004BB110[i].h) {
                    Task_RunWrap_0_0014DAB0(D_004BB110[i].h);
                    D_004BB110[i].h = 0;
                }
                memset(&D_004BB110[i], 0, 0x11C);
                e->x0 = 1;
                e->x18 = 0;
                D_00201E54 = -1;
            }
            break;
        case 1:
        case 2:
        case 4:
            D_00222A54[0].b3 = 4;
            break;
        }
    }
}
