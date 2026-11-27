#include "common.h"
s32 Enemy_GetTargetHandle_0_0013EDE0(u8 *);                            /* extern */
s32 Ent_IsNull0_1_0013EE30(u8 *);                            /* extern */

s32 Event_FindEnemyByMotion_0_00179E50(s32 arg0, s32 arg1) {
    u8 *var_16;
    s32 temp_3;
    s32 temp_19;
    s32 sp5C;

    sp5C = 0;
    var_16 = (u8 *) (ActorList_Next_2_001A5460(&sp5C));
    if (var_16 != NULL) {
loop_1:
        if (Ent_IsNull0_1_0013EE30(var_16) == 0) {
            temp_19 = Enemy_GetMotionId_0_0013ED20(var_16) & 0xFF;
            temp_3 = Enemy_GetTargetHandle_0_0013EDE0(var_16) & 0xFF;
            if (((temp_19 & 0xFF) == arg1) && ((temp_3 & 0xFF) == arg0)) {
                return (s32) var_16;
            }
        }
        var_16 = (u8 *) (ActorList_Next_2_001A5460(&sp5C));
        if (var_16 == NULL) {
            goto block_7;
        }
        goto loop_1;
    }
block_7:
    return 0;
}
