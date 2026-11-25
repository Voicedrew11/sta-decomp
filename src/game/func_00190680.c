#include "common.h"

extern s32 D_00201CF8[2];

s32 func_00190680(s32 x)
{
    switch (x) {
    case 0:
    case 1:
        return D_00201CF8[x];
    }
    return 0;
}
