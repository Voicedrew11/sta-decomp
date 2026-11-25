#include "common.h"
extern s32 D_001F3380[];
extern s32 D_001F3390[];

s32 *func_001A4050(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return D_001F3380;
    case 1:
        return D_001F3390;
    default:
        return NULL;
    }
}
