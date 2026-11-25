#include "common.h"
void RotateThreadReadyQueue(s32);            /* extern */
extern s32 D_004BDEE0[];
extern s32 D_004BDF88[];

s32 func_001E9EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EB8B0(D_004BDEE0, arg1, arg2, arg3);
    RotateThreadReadyQueue(1);
    func_001EAC70(D_004BDF88);
    return 1;
}
