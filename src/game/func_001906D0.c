#include "common.h"

extern s32 D_001F2B70[];

s32 func_001906D0(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
        return D_001F2B70[x];
    }
    return 0;
}
