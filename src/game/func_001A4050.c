#include "m2c.h"
extern M2C_UNK D_001F3380[];
extern M2C_UNK D_001F3390[];

M2C_UNK *func_001A4050(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return D_001F3380;
    case 1:
        return D_001F3390;
    default:
        return NULL;
    }
}
