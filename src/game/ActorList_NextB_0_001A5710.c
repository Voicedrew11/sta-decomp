#include "common.h"
extern s32 D_00202274;
extern u8 **D_004A4570[];

u8 *ActorList_NextB_0_001A5710(void) {
    s32 var_5;
    u8 ***var_4;
    u8 **temp_2;
    u8 temp_3;

    D_00202274 = 0;
    var_5 = 0;
    var_4 = (u8 ***) (D_004A4570);
loop_1:
    temp_2 = (u8 **) (*var_4);
    if (temp_2 != NULL) {
        temp_3 = M2C_FIELD(*temp_2, u8 *, 0x5A0);
        if ((temp_3 & 1) && (((u64) ((s64) temp_3 << 0x3D) >> 0x3F) != 0)) {
            D_00202274 = var_5 + 1;
            return (u8 *) (*(D_004A4570)[var_5]);
        }
    }
    var_5 += 1;
    var_4 = (u8***)((u8 *)var_4 + 4);
    if (var_5 >= 0x81) {
        return NULL;
    }
    goto loop_1;
}
