#include "common.h"
typedef struct { u8 pad[0xE]; s8 xE; u8 rest[0x71]; } E_SndCh_Stop_2_00131440;
typedef struct { s8 b0; s8 b1; char rest[0x7E]; } E_SndCh_StopNow_1_001314A0;
extern E_SndCh_Stop_2_00131440 D_0022CBC0[];
s32 SndCh_Stop_2_00131440(s32 arg0);
s32 SndCh_StopNow_1_001314A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 Se_StopVoice_0_001DA530(s32, s32, s32, s32, s32, s32, s32, s32);

/* SndCh_Stop_2_00131440 */
s32 SndCh_Stop_2_00131440(s32 arg0) {
    E_SndCh_Stop_2_00131440 *e;
    if (!(0 > arg0) && arg0 < 0x3F) e = &D_0022CBC0[arg0]; else e = NULL;
    if (e != NULL) {
        e->xE = 1;
        return 0;
    }
    return -1;
}

/* SndCh_StopNow_1_001314A0 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_StopNow_1_001314A0
extern E_SndCh_StopNow_1_001314A0 D_0022CBC0__as_SndCh_StopNow_1_001314A0[];
static inline E_SndCh_StopNow_1_001314A0 *get(s32 i) {
    E_SndCh_StopNow_1_001314A0 *p;
    if (0 <= i && i < 0x3F) p = &D_0022CBC0[i]; else p = NULL;
    return p;
}
s32 SndCh_StopNow_1_001314A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    E_SndCh_StopNow_1_001314A0 *p = get(arg0);
if (p == NULL) return -1; if (Se_StopVoice_0_001DA530(p->b1, arg1, arg2, arg3, arg4, arg5, arg6, arg7) == -1) return -1; p->b0 = 0; return 0;
}
#undef D_0022CBC0
