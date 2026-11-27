#include "common.h"
s32 strlen(const char *);
s32 SndDrv_CallArgs_2_001D8680(s32, s32, s32, ...);
s32 SndDrv_CallWithData_1_001D8350(s32, s32, s32, s32, s32, const char *);
s32 SndDrv_Call1_1_001D84F0(s32, s32, s32, s32);
s32 Strm_DrvOpenFile_1_001D8D20(s32 a0, const char *s, s32 a2) {
    s32 n = strlen(s);
    if (!SndDrv_CallArgs_2_001D8680(5, 1, 0x3010000, a0, a2)) {
        SndDrv_CallArgs_2_001D8680(5, 1, 0x3040000, a0);
        return 0;
    }
    if (!SndDrv_CallWithData_1_001D8350(5, 1, n + 1, 0, a0 | 0x30C0000, s)) {
        SndDrv_Call1_1_001D84F0(5, 1, 0x3040000, a0);
        return 0;
    }
    return 1;
}
