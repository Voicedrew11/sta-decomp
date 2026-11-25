#include "common.h"

extern s32 D_001F2B40[];

s32 func_00190770(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
    case 3:
        return D_001F2B40[x];
    }
    return 0;
}
