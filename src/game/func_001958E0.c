#include "common.h"
extern s32 *D_0020215C;

s32 func_001958E0(void) {
    if (D_0020215C != NULL) {
        return *D_0020215C;
    }
    return 0;
}
