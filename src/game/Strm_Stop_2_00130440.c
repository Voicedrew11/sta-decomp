#include "common.h"

extern struct { unsigned char : 1; unsigned char f : 1; } D_00201EE0;
void Strm_DrvStop_0_001D8C80(s32 a);
void Strm_DrvSetParamA_0_001D8C60(s32 a);
void Strm_DrvClose_1_001D8DF0(void);
void SndDrv_CallRpcSyncWait_2_001D7EC0(void);

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
