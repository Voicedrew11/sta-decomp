#include "common.h"
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
extern s32 D_001FD230[];

void Ending_PlayMovie_2_00194EE0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        GsPkt_EndLayer_1_00155900();
        Movie_Play_2_0017FF70((s32) D_001FD230);
        GsPkt_SetLayer_1_00154700(5, 0);
        GsPkt_EndLayer_1_00155900();
        Ending_StaffRoll_2_00194FC0();
        GsPkt_SetLayer_1_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
    }
}
