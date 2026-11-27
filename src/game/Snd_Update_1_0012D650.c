#include "m2c.h"
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    s16 x4; s16 x6; s16 x8; s16 xA; s16 xC; s8 xE; s8 xF;
    u8 p10[0x2C]; s16 x3C; s16 x3E;
    u8 p40[0x2D]; s8 x6D; s8 x6E; u8 p6F[0x11];
} Snd;
extern Snd D_0022CBC0[];
extern s8 D_0022EBC0[];
extern u8 D_0022EC20[];
extern s8 D_0022EC21[];
extern s8 D_0022EC22[];
extern u8 D_0022EBDA[];
extern u8 D_0022EC14[];
extern u8 D_0022EC15[];
extern u8 D_0022EC16[];
extern s32 D_0022EC3C[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_0022EC50[0xfc];
void Se_ReadStatus_0_001D9F10(void);
void Se_UpdateStatus_0_001D9FC0(void);
s32 Bgm_Poll_0_001D95E0(void);
void Bgm_SetVolume_1_001D9650(u16, u16);
void Bgm_Update_0_001D9680(void);
void Bgm_UpdateWrap_0_001D9990(void);
s32 Se_IsVoiceActive_1_001DA4F0(s32);
s32 Se_SetVoiceParams_0_001DA620(s32, s8, u8, u8, u8);
void Se_StopVoice_0_001DA530(s32);
void SndCh_Update3D_2_00130810(Snd *);
void Se_SendVoiceParams_0_001DA1D0(s32, s32 *);
void Snd_UpdateStreams_0_0012C4D0(void);
s32 Se_GetFlag_0_001D9F00(void);
void Se_SetPortParam_0_001DA8F0(s32, s16);
s32 Se_SetPortVolume_0_001DA720(s32);
void SndEmit_Update_1_0012F6F0(void);
void Se_FlushQueue_0_001D9E30(void);

void Snd_Update_1_0012D650(void) {
    s32 i;
    Snd *s;
    s32 *o;
    u16 v;
    s32 w;
    s32 j;

    Se_ReadStatus_0_001D9F10();
    Se_UpdateStatus_0_001D9FC0();
    if (D_0022EC20[0]) {
        if (D_0022EC22[0] == 1) {
            if (!Bgm_Poll_0_001D95E0()) {
                D_0022EC20[0] = 0;
            } else {
                D_0022EC21[0] -= 4;
                if (D_0022EC21[0] < 0) D_0022EC21[0] = 0;
                v = (D_0022EC21[0] * 0x81) & 0xFFFF;
                Bgm_SetVolume_1_001D9650(v, v);
                if (D_0022EC21[0] <= 0) Bgm_Update_0_001D9680();
            }
        } else if (!Bgm_Poll_0_001D95E0()) {
            D_0022EC20[0] = 0;
        }
    }
    Bgm_UpdateWrap_0_001D9990();
    s = D_0022CBC0;
    i = 0;
    o = D_0022EC50;
    for (; i < 0x3F; i++) {
        if (s->on == 1 && s->xF == 0 && Se_IsVoiceActive_1_001DA4F0(s->idx) != 1) s->on = 0;
        if (s->on) {
            if (s->xF && s->x3 && Se_IsVoiceActive_1_001DA4F0(s->idx) == 0) {
                Se_SetVoiceParams_0_001DA620(s->idx, D_0022EBC0[s->x2 + 8], s->x4, s->x6, s->xF);
                s->x3 = 0;
            }
            switch (s->xE) {
            case 0:
                break;
            case 1:
                s->x8 -= 4;
                if (s->x8 < 4) {
                    Se_StopVoice_0_001DA530(s->idx);
                    s->x8 = 0;
                    s->on = 0;
                }
                break;
            case 2:
                s->x8 -= 4;
                if (s->x8 < 4) {
                    Se_StopVoice_0_001DA530(s->idx);
                    s->x8 = 0;
                }
                break;
            case 3:
                SndCh_Update3D_2_00130810(s);
                s->x6E += 4;
                if (!(s->x6E < 0x7B)) {
                    s->x6E = 0x7F;
                    s->xE = s->x6D;
                }
                s->x8 = s->x8 * s->x6E / 127;
                break;
            case 4:
                SndCh_Update3D_2_00130810(s);
                break;
            }
            o[0] = s->x8 * D_0022EBDA[0] / 127;
            if (!D_0022EC14[0]) {
                o[1] = -0x100;
            } else {
                o[1] = s->xC;
            }
            o[3] = s->x3C;
        }
        s++;
        o += 4;
    }
    Se_SendVoiceParams_0_001DA1D0(0x3F, D_0022EC50);
    Snd_UpdateStreams_0_0012C4D0();
    if (D_0022EC15[0] && !Se_GetFlag_0_001D9F00()) {
        D_0022EC15[0] = 0;
        w = D_0022EBDA[0];
        for (j = 0; j < 4; j++) Se_SetPortParam_0_001DA8F0(j, w);
        D_0022EBDA[0] = 0x7F;
    }
    if (D_0022EC16[0] && !Se_GetFlag_0_001D9F00() && !D_0022EC20[0] && Se_SetPortVolume_0_001DA720(D_0022EC3C[0])) {
        D_0022EC16[0] = 0;
    }
    if (!D_0022EC15[0]) SndEmit_Update_1_0012F6F0();
    Se_FlushQueue_0_001D9E30();
}
