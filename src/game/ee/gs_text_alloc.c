#include "common.h"
#include "game/data.h"

s32 GsText_Alloc_0_001E1E08(s32 arg0, s32 arg1) {
    s32 var_4;

    var_4 = D_00201E58;
    if ((arg1 << 0x18) != 0) {
        var_4 = AlignUp_3_001E1E50(var_4, 0x10U);
    }
    D_00201E58 = var_4 + arg0;
    return var_4;
}
