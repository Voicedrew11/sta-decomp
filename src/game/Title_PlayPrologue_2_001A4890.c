#include "common.h"
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
s64 Strm_GetParam_0_001303C0(s32);                             /* extern */
extern s32 D_001FD8D0[];
extern s32 D_00202270;

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
