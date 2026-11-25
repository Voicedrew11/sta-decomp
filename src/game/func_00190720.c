#include "common.h"

extern s32 D_001F2B60[];

s32 func_00190720(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
        return D_001F2B60[x];
    }
    return 0;
}
