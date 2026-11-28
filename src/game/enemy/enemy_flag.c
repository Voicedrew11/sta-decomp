#include "common.h"
#include "m2c.h"
typedef struct { char pad[0x2D]; unsigned char : 3; unsigned int f : 1; } Ent;
typedef struct { char pad[0x4B4]; Ent *ents[1]; } Obj;
s32 Enemy_GetPartFlagS_0_0013EC80(Obj *o, u8 i);
u8 Enemy_GetMotionFrame_0_0013ECA0(s8 *arg0);

/* Enemy_GetPartFlagS_0_0013EC80 */
s32 Enemy_GetPartFlagS_0_0013EC80(Obj *o, u8 i)
{
    return o->ents[i]->f;
}

/* Enemy_GetMotionFrame_0_0013ECA0 */
u8 Enemy_GetMotionFrame_0_0013ECA0(s8 *arg0) {
    s32 var_v0_2;
    u16 temp_a2;
    s8 **temp_a1;
    s8 *var_v0;

    temp_a1 = M2C_FIELD(arg0, s8 ***, 0x4A8);
    temp_a2 = M2C_FIELD(arg0, u16 *, 0x4AC);
    if (temp_a1 != NULL) {
        var_v0_2 = M2C_FIELD(*temp_a1, s32 *, 0x13C) + ((temp_a2 & 0xFFFF) * 0x54);
    } else {
        var_v0_2 = 0;
    }
    if (var_v0_2 != 0) {
        var_v0 = NULL;
        if (temp_a1 != NULL) {
            var_v0 = (signed char *)(M2C_FIELD(*temp_a1, s32 *, 0x13C) + ((temp_a2 & 0xFFFF) * 0x54));
        }
        return M2C_FIELD(var_v0, u8 *, 0x2F);
    }
    return 0U;
}
