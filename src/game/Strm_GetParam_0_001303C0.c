#include "common.h"
#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; u16 vol; } St_Strm_SetVolume_2_001303D0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; s16 vol; } St_Strm_Update_1_001304C0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; u16 vol; } St_Strm_PlayFile_2_00130590;
extern s16 D_00201EE4;
extern St_Strm_SetVolume_2_001303D0 D_00201EE0;
extern s16 D_00201EE2;
extern u8 D_0022EBD9[];
extern u8 D_001FABB8[];
extern u8 D_001FABC0[];
s16 Strm_GetParam_0_001303C0(void);
void Strm_SetVolume_2_001303D0(u16 v);
void Strm_Stop_2_00130440(void);
void Strm_SetFadeStep_1_001304B0(s16 arg0);
void Strm_Update_1_001304C0(void);
s32 Strm_PlayFile_2_00130590(s32 arg0, s32 arg1, s32 arg2);
void Strm_DrvSetVolume_1_001D8CA0(s32, u16, u16);
void Strm_DrvStop_0_001D8C80(s32 a);
void Strm_DrvSetParamA_0_001D8C60(s32 a);
void Strm_DrvClose_1_001D8DF0(void);
void SndDrv_CallRpcSyncWait_2_001D7EC0(void);
s32 Strm_DrvGetStatus_1_001D8C50(void);
s32 Strm_DrvSetMode_1_001D8CC0(s32, s32);
void FlushCache(s32);
s32 sceCdSearchFile(void *, void *);
s32 sceCdGetError(void);
void memset(void *, s32, s32);
void sprintf(void *, void *, s32);
void SndDrv_CallRpcSyncWaitB_2_001D7FD0(void);
void Strm_DrvOpen_0_001D8CE0(s32, s32, s32);
void Strm_DrvOpenFile_1_001D8D20(s32, void *, s32);
void Strm_DrvInit_0_001D8E30(void);

/* Strm_GetParam_0_001303C0 */
s16 Strm_GetParam_0_001303C0(void) {
    return D_00201EE4;
}

/* Strm_SetVolume_2_001303D0 */
void Strm_SetVolume_2_001303D0(u16 v) {
    if (v < 0) v = 0;
    if (v > 0x7FFF) v = 0x7FFF;
    D_00201EE0.vol = v;
    if (D_00201EE0.b1) Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0.vol, D_00201EE0.vol);
}

/* Strm_Stop_2_00130440 */
#define D_00201EE0 D_00201EE0__as_Strm_Stop_2_00130440
extern struct { unsigned char : 1; unsigned char f : 1; } D_00201EE0__as_Strm_Stop_2_00130440;

void Strm_Stop_2_00130440(void)
{
    if (D_00201EE0.f) {
        int v = 0;
        Strm_DrvStop_0_001D8C80(1);
        Strm_DrvSetParamA_0_001D8C60(1);
        Strm_DrvClose_1_001D8DF0();
        SndDrv_CallRpcSyncWait_2_001D7EC0();
        D_00201EE0.f = v;
    }
}
#undef D_00201EE0

/* Strm_SetFadeStep_1_001304B0 */
void Strm_SetFadeStep_1_001304B0(s16 arg0) {
    D_00201EE2 = arg0;
}

/* Strm_Update_1_001304C0 */
#define D_00201EE0 D_00201EE0__as_Strm_Update_1_001304C0
extern St_Strm_Update_1_001304C0 D_00201EE0__as_Strm_Update_1_001304C0;
void Strm_Update_1_001304C0(void) {
    if (!D_00201EE0.b1) return;
    if (Strm_DrvGetStatus_1_001D8C50() == 0) return;
    if (D_00201EE0.b0) {
        Strm_DrvSetMode_1_001D8CC0(1, D_00201EE0.b2 != 0);
        D_00201EE0.b0 = 0;
    }
    if (D_00201EE0.h != 0) {
        D_00201EE0.vol += D_00201EE0.h;
        if (D_00201EE0.vol < 0) D_00201EE0.vol = 0;
        if (D_00201EE0.vol > 0x7FFF) D_00201EE0.vol = 0x7FFF;
        Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0.vol, D_00201EE0.vol);
    }
}
#undef D_00201EE0

/* Strm_PlayFile_2_00130590 */
#define D_00201EE0 D_00201EE0__as_Strm_PlayFile_2_00130590
extern St_Strm_PlayFile_2_00130590 D_00201EE0__as_Strm_PlayFile_2_00130590;

s32 Strm_PlayFile_2_00130590(s32 arg0, s32 arg1, s32 arg2) {
    s32 i = 0;
    s32 info[12];
    u8 name[0x100];
    if (D_00201EE0.b1) return -1;
    SndDrv_CallRpcSyncWaitB_2_001D7FD0();
    Strm_DrvInit_0_001D8E30();
    D_00201EE0.vol = (D_0022EBD9[0] * 0x3FFF) / 127;
    Strm_DrvSetVolume_1_001D8CA0(1, D_00201EE0.vol, D_00201EE0.vol);
    if (arg2) D_00201EE0.b2 = 1; else D_00201EE0.b2 = 0;
    if (arg1 == 0) {
        sprintf(name, D_001FABB8, arg0);
        while (sceCdSearchFile(info, name) == 0) {
            s32 r = sceCdGetError();
            i++;
            if (r == 0) {
                if (i > 10) {
                    Strm_DrvClose_1_001D8DF0();
                    return -1;
                }
                memset(info, 0, 0x24);
                break;
            }
        }
        FlushCache(0);
        Strm_DrvOpen_0_001D8CE0(1, info[0], 0x10000);
        D_00201EE0.b0 = 1;
    } else {
        sprintf(name, D_001FABC0, arg0);
        Strm_DrvOpenFile_1_001D8D20(1, name, 0x10000);
        while (Strm_DrvGetStatus_1_001D8C50() == 0) {}
        if (Strm_DrvSetMode_1_001D8CC0(1, D_00201EE0.b2 != 0) == 0) {
            Strm_DrvClose_1_001D8DF0();
            return -1;
        }
        D_00201EE0.b0 = 0;
    }
    D_00201EE0.h = 0;
    D_00201EE0.b1 = 1;
    return 0;
}
#undef D_00201EE0
