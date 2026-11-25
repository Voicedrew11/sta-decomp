#include "common.h"
extern s32 *D_00202160;

s32 func_001958A0(void) {
    if (D_00202160 != NULL) {
        return *D_00202160;
    }
    return 0;
}
