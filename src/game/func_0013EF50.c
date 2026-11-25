#include "actor.h"
void func_0013EF50(Actor *a0) {
    (a0->unk6B8)++;
    if (a0->unk6B8 > 0x80) {
        a0->unk6B8 = 0x80;
    }
}
