#include "actor.h"
void Enemy_UpdateTimer5C0_0_0013DB10(Actor *a, f32 dt) {
    f32 t;
    if (a->flags5B4.f.b3) {
        dt /= a->unk5C8;
        t = a->unk5C0;
        t += dt;
        if (t >= 1.0f) {
            t = 1.0f;
            a->flags5B4.f.b3 = 0;
        }
        a->unk5C0 = t;
    }
}

