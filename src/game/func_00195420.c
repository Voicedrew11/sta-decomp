#include "m2c.h"
extern s32 D_001F2E70[];

s32 func_00195420(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 3)) {
        return 0;
    }
    return D_001F2E70[arg0];
}
