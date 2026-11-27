#include "common.h"
typedef struct { f32 v[8]; } M;
extern s32 D_00201E3C;
extern u8 *D_00202328;
extern u8 D_004BA0E0[];
s32 SndDrv_CallWithData_1_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, u8 *m);
s32 SndDrv_GetRecvBuffer_1_001D8340(void);
void Se_ParseVoiceMap_0_001DBD20(s32);
void Se_FlushQueue_0_001D9E30(void) {
    s32 n = D_00202328 - D_004BA0E0;
    if (n > 1) {
        SndDrv_CallWithData_1_001D8350(4, 1, n, D_00201E3C, 0x1100, D_004BA0E0);
        Se_ParseVoiceMap_0_001DBD20(SndDrv_GetRecvBuffer_1_001D8340());
    }
    D_004BA0E0[0] = 0;
    D_00202328 = D_004BA0E0 + 1;
    D_00201E3C = 1;
}

