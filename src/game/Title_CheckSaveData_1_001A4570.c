#include "m2c.h"
#include "common.h"
typedef struct { s32 pad[4]; s32 f10[7]; s32 pad2[1]; } St;
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
typedef struct { s32 x0; s32 x4; u8 b8; char p9[3]; u8 bC; } Obj;
extern s32 D_0020226C;
extern s32 D_00202268;
extern s32 D_001FD8D0[];
extern s32 D_00202270;
s32 Title_CheckSaveData_1_001A4570(void);
void Title_PlayPrologue_2_001A4890(void *arg0);
void Title_StartNewGame_0_001A4930(Obj *o);
void SaveSys_GetSlotCount_0_001E5E80(St *);
s32 SaveSys_StartRead_0_001E5F30(s32, s32);
void SaveSys_GetResult_0_001E6080(s32 *);
s32 SaveSys_StartWrite_0_001E6170(s32, s8 *, s32);
s32 SaveSys_GetPort_1_001E8290(void);
s32 SaveSys_SetPort_1_001E82A0(s32);
s8* Save_GetSlotInfo_0_00188FF0(s32);
s64 Strm_GetParam_0_001303C0(s32);
void Game_RequestMode12B_0_0012C0C0(void);

/* Title_CheckSaveData_1_001A4570 */
s32 Title_CheckSaveData_1_001A4570(void) {
    s32 r = 0;
    St st = {0};
    s32 s;
    s32 any, i, t;

    switch (D_0020226C) {
    case 0:
        D_0020226C++;
        D_00202268 = 0;
        break;
    case 1:
        if (SaveSys_SetPort_1_001E82A0(D_00202268) != 0) {
            D_0020226C++;
        } else {
            D_0020226C = 0;
            r = 1;
        }
        break;
    case 2:
        if (SaveSys_StartRead_0_001E5F30(0, 0) == 0) {
            D_0020226C++;
        } else {
            D_0020226C = 0;
            r = 1;
        }
        break;
    case 3:
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 2) {
            r = 0;
        } else if (s == 0) {
            SaveSys_GetSlotCount_0_001E5E80(&st);
            if ((st.f10[0] == 1) | (st.f10[1] == 1) | (st.f10[2] == 1) | (st.f10[3] == 1) | (st.f10[4] == 1) |
                (st.f10[5] == 1) | (st.f10[6] == 1)) {
                D_0020226C = 0;
                r = 2;
            } else {
                if (SaveSys_GetPort_1_001E8290() == 1) {
                    D_0020226C = 0;
                    r = 1;
                } else {
                    D_0020226C = 1;
                    D_00202268 = 1;
                    r = 0;
                }
            }
        } else {
            if (SaveSys_GetPort_1_001E8290() == 1) {
                D_0020226C = 0;
                r = 1;
            } else {
                D_0020226C = 1;
                D_00202268 = 1;
                r = 0;
            }
        }
        break;
    case 4:
        if (SaveSys_StartWrite_0_001E6170(7, Save_GetSlotInfo_0_00188FF0(0), 8) != -1) {
            D_0020226C++;
        } else {
            r = 1;
        }
        break;
    case 5:
        SaveSys_GetResult_0_001E6080(&s);
        if (s == 0) {
            any = 0;
            for (i = 0; i < 7; i++) {
                t = 0;
                if (st.f10[i] == 1 && !(Save_GetSlotInfo_0_00188FF0(0)[i] != 0) != 0) {
                    t = 1;
                }
                any |= t;
            }
            if (any) {
                D_0020226C = 0;
                r = 2;
            } else {
                if (SaveSys_GetPort_1_001E8290() == 1) {
                    D_0020226C = 0;
                    r = 1;
                } else {
                    D_0020226C = 1;
                    D_00202268 = 1;
                    r = 0;
                }
            }
        }
        if (s == 1) {
            r = 1;
            D_0020226C = 0;
        }
        break;
    }
    return r;
}

/* Title_PlayPrologue_2_001A4890 */
void Title_PlayPrologue_2_001A4890(void *arg0) {
    s32 temp_4;

    temp_4 = M2C_FIELD(arg0, s32 *, 0);
    if ((temp_4 == 0x16) && (D_00202270 != 0) && (((s64) (Strm_GetParam_0_001303C0(temp_4) << 0x30) >> 0x30) <= 0) && (Snd_CountActiveVoices_1_0012C1B0() == 0)) {
        GsPkt_EndLayer_1_00155900();
        Movie_Play_2_0017FF70((s32) D_001FD8D0);
        GsPkt_SetLayer_1_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
        D_00202270 = 0;
    }
}

/* Title_StartNewGame_0_001A4930 */
void Title_StartNewGame_0_001A4930(Obj *o)
{
    o->bC = 0;
    if (o->x0 == 25)
        D_00202270 = 1;
    if (o->x0 == 22 && !D_00202270) {
        o->b8 = 18;
        o->x4 = 0;
        o->x0 = 31;
        Game_RequestMode12B_0_0012C0C0();
    }
}
