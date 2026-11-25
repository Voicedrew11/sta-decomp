#include "common.h"
extern s32 *D_00202164;

s32 func_001958C0(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}
