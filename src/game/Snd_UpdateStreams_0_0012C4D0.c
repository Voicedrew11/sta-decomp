#include "m2c.h"
void MapSe_Request_0_001E1D30(u32, s32);
void SndBank_UploadIndexed_0_0012E810(s32, s32);
void Snd_StopStream_1_0012F550(s32);
void Snd_LoadBank_1_0012E3C0(s32);
void SndEmit_SpawnFromMap_0_0012F9D0(s32);
extern s8 D_00201ED5;
extern u32 D_002022B8;
extern s32 *D_002022BC;
extern s32 D_00222B54[];
extern s8 D_0022EC17[];
extern s32 D_0022EC18[];
extern s32 D_0022EC1C[];
extern u8 D_0022EC41[];
extern u8 D_0022EC42[];
extern s32 D_0022F054[];

s32 Snd_UpdateStreams_0_0012C4D0(void) {
    s32 ret;

    ret = 0;
    if (D_002022B8 == 0) {
        if (D_0022EC18[0] > 0) {
            s32 a = D_00222B54[0];
            s32 c = D_0022F054[0];
            if (c != 0) SndBank_UploadIndexed_0_0012E810(a + c + 0x10, 1); else goto skip;
            D_00201ED5 = 0;
        }
skip:
        D_0022EC18[0] = 0;
        return 0;
    }
    if (D_002022B8 / 10 != D_0022EC18[0]) {
        Snd_RequestStopAll_1_001313A0();
        if (D_0022EC18[0] > 0) {
            SndBank_UploadIndexed_0_0012E810(D_00222B54[0] + D_0022F054[0] + 0x10, 1);
            D_00201ED5 = 0;
        }
        D_0022EC17[0] = 0;
        D_0022EC18[0] = D_002022B8 / 10;
        if (D_0022EC41[0] & 1) {
            Snd_StopStream_1_0012F550(1);
        }
        if (D_0022EC42[0] & 1) {
            Snd_StopStream_1_0012F550(2);
        }
        MapSe_Request_0_001E1D30(D_002022B8, 0);
        if (D_002022BC != NULL) {
            Snd_LoadBank_1_0012E3C0(*D_002022BC);
        }
        ret = 1;
    }
    if (D_002022B8 != D_0022EC1C[0]) {
        if (D_0022EC1C[0] > 0) {
            if (ret != 0) {
                SndEmit_KillAll_1_0012F920();
            } else {
                SndEmit_StopAllB_1_0012F880();
            }
            SndEmit_SpawnFromMap_0_0012F9D0(*D_002022BC);
        }
        D_0022EC1C[0] = D_002022B8;
        ret = (ret > 0) ? ret : 2;
    }
    return ret;
}
