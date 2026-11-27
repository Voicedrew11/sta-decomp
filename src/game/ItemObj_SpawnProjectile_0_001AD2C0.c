#include "common.h"
#include "actor.h"
typedef struct { u8 pad[8]; u16 x8; u16 xA; } E;
typedef struct { u8 b[0x40]; } Dst;
extern Actor *D_002022E4;
void Attack_PlaySe_0_001D1E80(s32, s32, E *, s32, s32);
s8 *Attack_SpawnSfx_0_001D1F20(s32, s32, s32, s32, E *, s32, s32);
void Sfx_SetOwner_1_00167600(s8 *, Actor *);
void Player_InitAttack_0_001C79B0(Dst *);
void Sfx_GetState_0_001672B0(s8 *, Dst *);
void ItemObj_SpawnProjectile_0_001AD2C0(s32 a0, s32 a1, s32 a2, E *e, s32 t0, s32 t1) {
    Dst d;
    s8 *o;
    if (t1) {
        switch (e->x8) {
        case 0:
            Attack_PlaySe_0_001D1E80(a0, a2, e, t0, t1);
            break;
        case 1:
            o = Attack_SpawnSfx_0_001D1F20(a0, 0, a1, a2, e, t0, t1);
            if (o) {
                Sfx_SetOwner_1_00167600(o, D_002022E4);
                if (e->xA == 0xFFFF) {
                    Player_InitAttack_0_001C79B0(&d);
                    Sfx_GetState_0_001672B0(o, &d);
                }
            }
            break;
        }
    }
}
