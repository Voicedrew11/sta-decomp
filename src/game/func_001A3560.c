#include "m2c.h"
#include "actor.h"
extern M2C_UNK D_001F3280[];

s32 func_001A3560(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 4)) {
        return 0;
    }
    return D_001F3280[arg0];
}
