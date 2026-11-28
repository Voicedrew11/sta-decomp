#include "common.h"
s32 AlignUpB_3_001E48E0(s32 arg0, s32 arg1) {
    return ((s32) ((arg0 + arg1) - 1) / arg1) * arg1;
}
