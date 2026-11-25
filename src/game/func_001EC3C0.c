#include "common.h"
void RotateThreadReadyQueue(s32);            /* extern */

void func_001EC3C0(void) {
loop_1:
    RotateThreadReadyQueue(1);
    goto loop_1;
}
