#include "m2c.h"
extern s32 *D_00202164;
extern s32 *D_0020215C;

s32 func_001958C0(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}

s32 func_001958E0(void) {
    if (D_0020215C != NULL) {
        return *D_0020215C;
    }
    return 0;
}
