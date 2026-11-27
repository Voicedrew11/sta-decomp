#include "common.h"
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_00497C80[0x1f08];
s32 D_00497B80[0x40];

s32 *func_00189000(s32 arg0) {
    if (arg0 != 0) {
        return D_00497B80;
    }
    return D_00497C80;
}
