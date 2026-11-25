#include "actor.h"

s32 func_0013EDE0(Actor *a0) {
    s32 r;
    if (a0->flags5A1.f.b3) {
        r = a0->unk712;
    } else if (a0->unk4A8 != 0) {
        r = **(s32 **)a0->unk4A8;
    } else {
        r = 0;
    }
    return r;
}
