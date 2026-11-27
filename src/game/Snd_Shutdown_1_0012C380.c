#include "common.h"
extern u8 D_0022EC20[];

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
