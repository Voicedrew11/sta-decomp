#include "common.h"
typedef struct { u8 pad[8]; u16 x8; u8 padA[0xE]; f32 x18; f32 p1C; f32 x20; f32 p24; f32 x28; } Arg;
extern char *D_00201FA8;
u8 *Script_GetArgPtr_2_00165130(Arg *, s32);
s32 Player_DropItem_0_001CAC30(void);
s32 Player_PlaceItem_0_001CADF0(s16, Vec *, Vec *, s32);
void Enemy_CopyPosition_2_00140470(char *, Vec *);
void Enemy_GetForwardVector_2_001403D0(char *, Vec *);
void Enemy_GetRightVector_1_00140360(char *, Vec *);
void Enemy_CopyRotation_2_00140440(char *, Vec *);

void EnemyCmd_SpawnEffectB_0_00144BE0(Arg *a0) {
    char *pl = *(char **)(D_00201FA8 + 0x154);
    u16 n = a0->x8;
    u8 *out = Script_GetArgPtr_2_00165130(a0, 1);
    f32 f22 = a0->x18;
    f32 f21 = a0->x20;
    f32 f20 = a0->x28;
    s8 r = Player_DropItem_0_001CAC30();
    if (r == -1) {
        Vec p;
        Vec d;
        Vec q;
        Enemy_CopyPosition_2_00140470(pl, &p);
        Enemy_GetForwardVector_2_001403D0(pl, &d);
        p.x += d.x * f22;
        p.z += d.z * f22;
        p.y += f21;
        Enemy_GetRightVector_1_00140360(pl, &d);
        p.x += d.x * f20;
        p.z += d.z * f20;
        Enemy_CopyRotation_2_00140440(pl, &q);
        r = Player_PlaceItem_0_001CADF0(n, &p, &q, 0);
    }
    if (r == 0) {
        *out = 0;
    } else {
        *out = 1;
    }
}
