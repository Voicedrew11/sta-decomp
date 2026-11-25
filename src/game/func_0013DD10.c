#include "common.h"
s32 func_0013DD10(void *arg0) {
    void **temp_2;

    temp_2 = M2C_FIELD(arg0, void ***, 0x4A8);
    if (temp_2 != NULL) {
        return M2C_FIELD(*temp_2, s32 *, 0x174);
    }
    return 0;
}
