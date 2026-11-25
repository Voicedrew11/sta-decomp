#include "m2c.h"
#include "actor.h"
extern M2C_UNK D_001F3140[];

s32 func_0019E780(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 5)) {
        return 0;
    }
    return D_001F3140[arg0];
}
