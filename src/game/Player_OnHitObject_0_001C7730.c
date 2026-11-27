#include "m2c.h"
typedef struct {
    u8 p[0x3CD]; s8 x3CD; s8 x3CE; u8 p3CF[6]; u8 x3D5;
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:2; u8 c3:5;
} S;
typedef struct { u8 p[0x30]; s32 x30; s32 x34; } A;
extern s8 *D_002022E4;
s32 MapObj_Hit_0_001B85B0(s32, A *);
u8 MapObj_IsSame_0_001B8F30(s32, s32);
void Equip_DamageOnHit_0_001CC6F0(s32, s32);
void Player_PlayHitObjectSe_0_001CA700(s32, s32);

void Player_OnHitObject_0_001C7730(A *a, s32 b) {
    s32 r;
    s32 t;
    s32 m;
    S *s;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else {
        t = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (t == 0) {
            s = NULL;
        } else {
            s = (S *)(t + 0x180);
        }
    }
    if (s != NULL) {
        s->b5 = 1;
        if (a->x34 != 0) {
            if (MapObj_Hit_0_001B85B0(b, a) != 0) {
                m = 1;
                s->b5 = 0;
            } else {
                m = 8;
            }
            r = MapObj_IsSame_0_001B8F30(a->x30, a->x34);
            Equip_DamageOnHit_0_001CC6F0(m, r);
        } else {
            r = 2;
        }
        if (s->b5) {
            Player_PlayHitObjectSe_0_001CA700(s->x3CD, r);
        }
    }
}
