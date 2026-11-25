#include "actor.h"
void func_0013EF10(Actor *a0) {
    (a0->unk6B9)++;
    if (a0->unk6B9 > 0x80) {
        a0->unk6B9 = 0x80;
    }
}
