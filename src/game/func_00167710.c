#include "common.h"
void sceVu0CopyVector(s32);                      /* extern */

void func_00167710(s32 arg0) {
    if (arg0 != 0) {
        sceVu0CopyVector(arg0 + 0x30);
    }
}
