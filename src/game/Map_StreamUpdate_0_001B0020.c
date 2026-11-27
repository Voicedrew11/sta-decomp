#include "m2c.h"
typedef struct { u8 pad[0x14]; s32 x14; u8 b0:1; u8 b1:1; } G2C4;
typedef struct { u8 lo:3; u8 f3:3; } BF;
extern G2C4 *D_002022C4;
extern BF D_00222A54[];
extern u8 D_00270F40[];
extern f32 D_004B4B90[];
extern s32 D_004B4BB0[];
extern s32 D_004B4BB4[];
extern s16 D_004B4BBC[];
extern s16 D_004B4BBE[];
extern s32 D_004B4BC0[];
extern s32 D_004B4BC4[];
extern s32 D_004B4BC8[];
extern s32 D_004B4BCC[];
s32 Task_KillWrap_0_0014DAF0(s32);
void Task_AddWrap_0_0014DAD0(s32);
void Task_RunWrap_0_0014DAB0(s32);
void Map_GetFile_2_001B7050(s32, u8 *, s32 *);
s32 Map_AllocAreaBuf_1_001B70E0(s32);
s32 Task_SetPriorityWrap_0_0014DB00(u8 *, s32, u8 *);
s32 Obj_FreeTimer_0_0014DA70(s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
void Task_RemoveWrap_0_0014DAE0(s32);
void FlushCache(s32);
void Dma_SprCopy_1_001789E0(u8 *, u8 *, s32);
void memcpy(u8 *, u8 *, s32);
s32 Obj_SetTimerEx_0_0014DA90(s32, s32, s32, s32);
s32 Obj_SetTimer_0_0014DA80(s32, s32);
void Map_LoadTextures_0_001B6FC0(s32);
void Map_SetOrigin_1_001B4BD0(s32, f32 *);
static inline u32 umin(u32 a, u32 b) { return a > b ? b : a; }

void Map_StreamUpdate_0_001B0020(void) {
    u8 buf[0x100];
    s32 n;
    s32 q;
    s32 off;
    s32 r;
    s32 x;
    if (D_002022C4 == 0) return;
    if (D_002022C4->b1 && D_002022C4->x14 != 0) return;
    if (D_004B4BB0[0] != -1) {
        if (D_004B4BC0[0] != 0) {
            if ((u8)Task_KillWrap_0_0014DAF0(D_004B4BC0[0])) {
                Task_AddWrap_0_0014DAD0(D_004B4BC0[0]);
            } else {
                Task_RunWrap_0_0014DAB0(D_004B4BC0[0]);
                D_004B4BC0[0] = 0;
            }
        }
        if (D_004B4BC0[0] != 0) return;
        D_004B4BBC[0] = 0;
        D_004B4BB4[0] = D_004B4BB0[0];
        D_004B4B90[0] = D_004B4B90[0];
        D_004B4B90[1] = D_004B4B90[1];
        D_004B4B90[2] = D_004B4B90[2];
        D_004B4B90[3] = D_004B4B90[3];
        D_004B4BB0[0] = -1;
        Map_GetFile_2_001B7050(D_004B4BB4[0], buf, D_004B4BC8);
        D_004B4BC4[0] = Map_AllocAreaBuf_1_001B70E0(D_004B4BB4[0]);
        D_004B4BCC[0] = 0;
        D_004B4BC0[0] = Task_SetPriorityWrap_0_0014DB00(buf, 0x100, D_00270F40);
        D_004B4BCC[0] = Obj_FreeTimer_0_0014DA70(D_004B4BC0[0]);
        D_004B4BBE[0] = 0;
        Task_FlushWrap_0_0014DAC0(D_004B4BC0[0], 0);
    } else if (D_004B4BB4[0] != -1) {
        switch ((u8)Task_KillWrap_0_0014DAF0(D_004B4BC0[0])) {
        case 0:
            break;
        case 5:
            n = D_004B4BC8[0] - D_004B4BCC[0];
            n = umin(n, 0x80000);
            q = n >> 4;
            off = q << 4;
            r = n - off;
            FlushCache(0);
            Dma_SprCopy_1_001789E0((u8 *)(**(s32 **)(*(s32 *)D_004B4BC4[0] + 0x24) + D_004B4BCC[0]), D_00270F40, q);
            if (r > 0) {
                memcpy((u8 *)(**(s32 **)(*(s32 *)D_004B4BC4[0] + 0x24) + D_004B4BCC[0]) + off, D_00270F40 + off, r);
            }
            D_004B4BCC[0] += n;
            Task_RemoveWrap_0_0014DAE0(D_004B4BC0[0]);
            break;
        case 3:
        case 6:
            if (D_004B4BBC[0] == 0) {
                x = **(s32 **)(*(s32 *)D_004B4BC4[0] + 0x24);
                if (D_004B4BBE[0] == 0) {
                    if (Obj_SetTimerEx_0_0014DA90(D_004B4BC0[0], x, x, D_004B4BC8[0])) {
                        D_004B4BBE[0] = 1;
                    }
                }
                if (D_004B4BBE[0]) {
                    if (Obj_SetTimer_0_0014DA80(D_004B4BC0[0], 2)) break;
                }
                D_004B4BBE[0] = 0;
                Map_LoadTextures_0_001B6FC0(D_004B4BC4[0]);
                Map_SetOrigin_1_001B4BD0(*(s32 *)D_004B4BC4[0], D_004B4B90);
                D_004B4BBC[0] = 1;
            }
            break;
        case 1:
        case 2:
        case 4:
            D_00222A54[0].f3 = 1;
            break;
        }
    }
}
