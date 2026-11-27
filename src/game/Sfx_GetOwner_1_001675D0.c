#include "common.h"
s32 Sfx_GetOwner_1_001675D0(void *arg0) {
    s32 *temp_2;

    if (arg0 == NULL) {
        return 0;
    }
    temp_2 = M2C_FIELD(arg0, s32 **, 0x170);
    if (temp_2 != NULL) {
        return *temp_2;
    }
    return 0;
}
