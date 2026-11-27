#include "actor.h"
void EnemyScr_Event2022_1_00140DE0(Actor *);

void Enemy_UpdateDeath_0_0013DB80(Actor *a, f32 dt) {
    f32 t;
    if (a->flags5B3.f.b3) {
        a->flags5B2.f.b3 = 1;
    }
    if (a->flags5B3.f.b2) {
        t = a->unk5C0;
        if (t > dt) t = t - dt; else t = 0.0f;
        a->unk5C0 = t;
        if (t == 0.0f && !a->flags5B3.f.b3) {
            EnemyScr_Event2022_1_00140DE0(a);
            a->flags5B3.f.b3 = 1;
        }
        a->flags5B4.f.b3 = 0;
    }
}
