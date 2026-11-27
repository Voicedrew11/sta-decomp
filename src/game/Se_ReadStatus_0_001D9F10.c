#include "common.h"
s32 SndDrv_CallWithData_1_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *m);
u8 *SndDrv_GetRecvBuffer_1_001D8340(void);
extern u8 D_004BA040[];
s32 Se_ReadStatus_0_001D9F10(void) {
    s32 r; u8 *s; s32 i; u8 *d;
    r = SndDrv_CallWithData_1_001D8350(4, 1, 0, 0xA0, 0x810200, NULL);
    s = SndDrv_GetRecvBuffer_1_001D8340(); d = D_004BA040; for (i = 0; i < 0xA0; i++) { *d = *s; s = s + 1; d = d + 1; }
    return r;
}
