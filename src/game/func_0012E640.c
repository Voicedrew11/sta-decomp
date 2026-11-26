#include "m2c.h"
#include "actor.h"
extern M2C_UNK D_0022F040[];

s32 func_0012E640(s8 *arg0, s32 arg1) {
    s8 *temp_v1;

    temp_v1 = arg0 + 0x10;
    if ((s32) M2C_FIELD(arg0, u16 *, 0xC) < 4) {
        return -1;
    }
    if (M2C_FIELD(temp_v1, s32 *, 4) == 0) {
        return -1;
    }
    func_0012E8F0(temp_v1, arg1);
    D_0022F040[arg1 * 4] = 0;
    return 0;
}
