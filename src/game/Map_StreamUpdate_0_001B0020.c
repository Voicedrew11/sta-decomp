#include "m2c.h"
#include "common.h"
#include "actor.h"
typedef struct { u8 pad[0x14]; s32 x14; u8 b0:1; u8 b1:1; } G2C4;
typedef struct { u8 lo:3; u8 f3:3; } BF;
typedef struct { f32 v[4]; s32 x10; u8 b14; char p15[3]; s32 x18; } Out;
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
extern s32 D_004B4BB8[];
extern f32 D_004B4B94[];
extern f32 D_004B4B98[];
extern s32 D_004B4B9C[];
void Map_StreamUpdate_0_001B0020(void);
void Map_StreamFlush_1_001B03E0(void);
void Map_StreamStart_0_001B0450(void);
s32 Map_StreamGetResult_1_001B0660(Out *o);
void Map_RequestArea_1_001B06E0(s32 arg0, f32 *arg1, s32 arg2);
void Map_StreamInit_0_001B07B0(void);
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
void Map_SetOrigin_1_001B4BD0(s32, void *);
void Task_InitWrap_0_0014DAA0(void);
void Map_OnAreaLoadedWrap_1_001B6FB0(s32);
void sceVu0CopyVector(f32 *v0, f32 *v1);
void Map_FreeArea_1_001B5640(s32);
void Task_Register_0_0014DB10(void (*)());
void memset(s32 *, s32, s32);

/* Map_StreamUpdate_0_001B0020 */
#define Map_SetOrigin_1_001B4BD0 Map_SetOrigin_1_001B4BD0__as_Map_StreamUpdate_0_001B0020
void Map_SetOrigin_1_001B4BD0__as_Map_StreamUpdate_0_001B0020(s32, f32 *);
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
#undef Map_SetOrigin_1_001B4BD0

/* Map_StreamFlush_1_001B03E0 */
#define Task_AddWrap_0_0014DAD0 Task_AddWrap_0_0014DAD0__as_Map_StreamFlush_1_001B03E0
int Task_AddWrap_0_0014DAD0__as_Map_StreamFlush_1_001B03E0();

void Map_StreamFlush_1_001B03E0(void) {
    if ((*D_004B4BC0) != 0) {
        Task_AddWrap_0_0014DAD0((*D_004B4BC0));
        (*D_004B4BC0) = 0;
    }
    (*D_004B4BB8) = 0;
    (*D_004B4BC0) = 0;
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
    (*D_004B4BBC) = 0;
    (*D_004B4BC4) = 0;
    (*D_004B4BBE) = 0;
}
#undef Task_AddWrap_0_0014DAD0

/* Map_StreamStart_0_001B0450 */
#define Map_SetOrigin_1_001B4BD0 Map_SetOrigin_1_001B4BD0__as_Map_StreamStart_0_001B0450
void Map_SetOrigin_1_001B4BD0__as_Map_StreamStart_0_001B0450(s32, s32 *);
#define D_004B4B90 D_004B4B90__as_Map_StreamStart_0_001B0450
extern s32 D_004B4B90__as_Map_StreamStart_0_001B0450[];
static inline void reset(void) {
    if (D_004B4BC0[0] != 0) {
        Task_AddWrap_0_0014DAD0(D_004B4BC0[0]);
        D_004B4BC0[0] = 0;
    }
    D_004B4BB8[0] = 0;
    D_004B4BC0[0] = 0;
    D_004B4BB4[0] = -1;
    D_004B4BB0[0] = -1;
    D_004B4BBC[0] = 0;
    D_004B4BC4[0] = 0;
    D_004B4BBE[0] = 0;
}
static inline s32 status(void) {
    s32 r = 0;
    if (D_004B4BC0[0] != 0) r = Task_KillWrap_0_0014DAF0(D_004B4BC0[0]);
    return r;
}

void Map_StreamStart_0_001B0450(void) {
    s8 *p;
    s32 x;
    if (D_004B4BB4[0] != -1) {
        if ((u8)status() != 3 && (u8)status() != 6) {
            while (!D_004B4BBC[0]) {
                Task_InitWrap_0_0014DAA0();
            }
        } else if (D_004B4BBC[0] == 0) {
            x = **(s32 **)(*(s8 **)D_004B4BC4[0] + 0x24);
            if (D_004B4BBE[0] == 0) {
                if (Obj_SetTimerEx_0_0014DA90(D_004B4BC0[0], x, x, D_004B4BC8[0])) {
                    D_004B4BBE[0] = 1;
                }
            }
            if (D_004B4BBE[0]) {
                while (Obj_SetTimer_0_0014DA80(D_004B4BC0[0], 2)) {
                }
            }
            Map_LoadTextures_0_001B6FC0(D_004B4BC4[0]);
            Map_SetOrigin_1_001B4BD0(*(s32 *)D_004B4BC4[0], D_004B4B90);
        }
        p = *(s8 **)D_004B4BC4[0];
        Map_OnAreaLoadedWrap_1_001B6FB0(D_004B4BC4[0]);
        ((Flags8_6x2 *)(**(s8 ***)*(s8 **)(p + 0x178) + 0x24))->f.b6 = 1;
        reset();
    }
}
#undef Map_SetOrigin_1_001B4BD0
#undef D_004B4B90

/* Map_StreamGetResult_1_001B0660 */
#define D_004B4B90 D_004B4B90__as_Map_StreamGetResult_1_001B0660
extern struct { f32 v[4]; char p10[0x14]; s32 x24; char p28[8]; s32 h; s32 x34; } D_004B4B90__as_Map_StreamGetResult_1_001B0660;


s32 Map_StreamGetResult_1_001B0660(Out *o)
{
    s32 r = 0;
    if (D_004B4B90.h)
        r = Task_KillWrap_0_0014DAF0(D_004B4B90.h);
    if (o) {
        sceVu0CopyVector(o->v, D_004B4B90.v);
        o->x10 = D_004B4B90.x24;
        o->b14 = r;
        o->x18 = D_004B4B90.x34;
    }
    return r;
}
#undef D_004B4B90

/* Map_RequestArea_1_001B06E0 */
void Map_RequestArea_1_001B06E0(s32 arg0, f32 *arg1, s32 arg2) {
    if (D_004B4BB4[0] != arg0 && (D_004B4BB8[0] == 0 || arg2 != 0)) {
        if (D_004B4BBC[0] == 0 && D_004B4BB4[0] != -1) {
            Map_FreeArea_1_001B5640(D_004B4BC4[0]);
        }
        D_004B4BB0[0] = arg0;
        D_004B4B90[0] = -arg1[0];
        D_004B4B94[0] = -arg1[1];
        D_004B4B98[0] = -arg1[2];
        D_004B4BB8[0] = arg2;
        D_004B4B9C[0] = 0;
    }
}

/* Map_StreamInit_0_001B07B0 */
#define D_004B4B90 D_004B4B90__as_Map_StreamInit_0_001B07B0
extern s32 D_004B4B90__as_Map_StreamInit_0_001B07B0[];
#define D_004B4B94 D_004B4B94__as_Map_StreamInit_0_001B07B0
extern s32 D_004B4B94__as_Map_StreamInit_0_001B07B0[];
#define D_004B4B98 D_004B4B98__as_Map_StreamInit_0_001B07B0
extern s32 D_004B4B98__as_Map_StreamInit_0_001B07B0[];

void Map_StreamInit_0_001B07B0(void) {
    if ((*D_004B4BC0) != 0) {
        Task_AddWrap_0_0014DAD0((*D_004B4BC0));
        (*D_004B4BC0) = 0;
    }
    (*D_004B4BB8) = 0;
    (*D_004B4BC0) = 0;
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
    (*D_004B4BBC) = 0;
    (*D_004B4BC4) = 0;
    (*D_004B4BBE) = 0;
    (*D_004B4B90) = 0;
    (*D_004B4B94) = 0;
    (*D_004B4B98) = 0;
    (*D_004B4B9C) = 0;
    Task_Register_0_0014DB10(Map_StreamUpdate_0_001B0020);
    memset(D_004B4B90, 0, 0x40);
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
}
#undef D_004B4B90
#undef D_004B4B94
#undef D_004B4B98
