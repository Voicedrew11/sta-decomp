#include "common.h"
extern s8 D_0022EC14[];

void Snd_SetOutputMode_1_0012DA60(s32 arg0) {
    (*D_0022EC14) = (s8) (arg0 % 3);
}
