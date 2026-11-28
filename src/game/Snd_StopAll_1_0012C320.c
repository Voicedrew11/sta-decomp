#include "common.h"
typedef struct { s8 b0; char p1[0xD]; s8 bE; char rest[0x71]; } E;
extern E D_0022CBC0[63];
extern u8 D_0022EC20[];
extern u8 D_00201ED4[4];
extern s8 D_0022EC17[];
void Snd_StopAll_1_0012C320(void);
void Snd_Shutdown_1_0012C380(void);
u8 Snd_GetStreamFlag_0_0012C400(u32 i);
void Snd_SetMuteFlag_0_0012C430(void);
void Snd_RequestStopAll_1_001313A0(void);
void SndEmit_StopAllB_1_0012F880(void);

/* Snd_StopAll_1_0012C320 */
void Snd_StopAll_1_0012C320(void)
{
    s32 i;
    Snd_RequestStopAll_1_001313A0();
    SndEmit_StopAllB_1_0012F880();
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0)
            D_0022CBC0[i].bE = 1;
    }
}

/* Snd_Shutdown_1_0012C380 */
void Snd_Shutdown_1_0012C380(void) {
    s32 var_16;

    if ((*D_0022EC20) != 0) {
        (*D_0022EC20) = 0;
        do {

        } while (Bgm_Stop_0_001D9710() == 0);
    }
    SndEmit_KillAll_1_0012F920();
    var_16 = 0;
    do {
        Se_StopGroup_0_001D9EE0(var_16);
        var_16 += 1;
    } while (var_16 < 4);
}

/* Snd_GetStreamFlag_0_0012C400 */
u8 Snd_GetStreamFlag_0_0012C400(u32 i) { if (i >= 4) return 0; return D_00201ED4[i]; }

/* Snd_SetMuteFlag_0_0012C430 */
void Snd_SetMuteFlag_0_0012C430(void) {
    (*D_0022EC17) = 1;
}
