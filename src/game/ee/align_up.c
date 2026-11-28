#include "common.h"
s32 AlignUp_3_001E1E50(s32 arg0, u32 arg1) {
    return ((u32) ((arg0 + arg1) - 1) / arg1) * arg1;
}
