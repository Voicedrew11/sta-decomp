#include "actor.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { u8 b0:1; u8 f1:2; u8 r:5; } B7;
typedef struct {
    u8 pad[0x3A1]; B8 m3A1; u8 pad2[0x3D5 - 0x3A2]; u8 m3D5; B8 m3D6; B7 m3D7;
} S;
void Player_StartMagicMotion_0_001C69A0(s32);
s32 Game_GetBusy_0_0012C020(void);
void Equip_DamageAmmo_0_001CC5E0(void);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

void Player_UpdateMagicState_0_001C6250(void) {
    S *s = (S *)get();
    if (s != NULL) {
        switch (s->m3D5) {
        case 0: break;
        case 1:
            if (s->m3A1.b6) {
                Player_StartMagicMotion_0_001C69A0(2);
            } else if (s->m3D6.b3) {
                Player_StartMagicMotion_0_001C69A0(2);
            } else if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0(3);
            }
            break;
        case 2:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0(0);
            }
            break;
        case 3:
            if (Game_GetBusy_0_0012C020()) {
                Player_StartMagicMotion_0_001C69A0(5);
            } else if (s->m3A1.b6) {
                Player_StartMagicMotion_0_001C69A0(5);
            } else if (s->m3D6.b3) {
                Player_StartMagicMotion_0_001C69A0(5);
            }
            break;
        case 4:
            s->m3D6.b0 = 1;
            if (s->m3D7.f1) {
                Equip_DamageAmmo_0_001CC5E0();
                Player_StartMagicMotion_0_001C69A0(0);
            }
            break;
        case 5: break;
        case 6:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0(0);
            }
            break;
        case 7:
            if (s->m3D7.f1) {
                Player_StartMagicMotion_0_001C69A0(0);
            }
            break;
        }
    }
}
