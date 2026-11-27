#include "actor.h"
typedef struct { u8 pad[0x120]; Flags8 f; } S2;
void EnemyScr_Event2017OnDeath_1_00141260(Actor *, s32);
void Enemy_DropItems_0_001A5990(Actor *);
void Player_OnEnemyKilled_1_001CB980(void *);
void Enemy_Kill_1_0013EF80(Actor *a, s32 d) {
    Flags8 *f = &(*(S2 **)(a->unk518 + 0x190))->f; if (!f->f.b0) { f->f.b0 = 1; EnemyScr_Event2017OnDeath_1_00141260(a, d); if ((*(S2 **)(a->unk518 + 0x190))->f.f.b0) { if (!a->flags5B3.f.b6) Enemy_DropItems_0_001A5990(a); if (!a->flags5B6.f.b1) Player_OnEnemyKilled_1_001CB980(a->unk4B0 + 0x250); } }
}
