#include "common.h"
typedef struct { u8 pad[0x13]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 pad14[0x2C]; } E;
typedef struct { u8 pad[0x170]; E *e; } V;
typedef struct { u8 pad[0x18]; u16 x18; u16 x1A; } A;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 pad[3]; f32 x1C; s32 pad2[4]; } S;
V *MapObj_Find_1_001B19A0(s32);
s8 *Mdl_GetFrameData_0_001715B0(s32);
void Player_GetPos_1_001C9410(Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void memset(void *, s32, s32);
f32 sceVu0InnerProduct(Vec *, Vec *);
void Event_CheckTrigger_0_00179F80(S *);
f32 sqrtf(f32);

void MapObj_CheckProximity_0_001B7F90(A *a0, s32 *a1, s32 a2, s32 a3) {
    V *v;
    E *e;
    s8 *r;
    S s;
    Vec d;
    v = MapObj_Find_1_001B19A0(a2);
    if (v == NULL) return;
    if (a0->x1A % 100 == 0) return;
    e = &v->e[a0->x18];
    r = Mdl_GetFrameData_0_001715B0(a1[0x10]);
    Player_GetPos_1_001C9410(&d);
    sceVu0SubVector(&d, &d, (Vec *)(r + 0x230));
    if (!e->b3) d.y = 0.0f;
    memset(&s, 0, 0x30);
    s.x0 = 0;
    s.x4 = a0->x1A % 100;
    s.x8 = a2;
    s.xC = a3;
    s.x1C = sqrtf(sceVu0InnerProduct(&d, &d));
    Event_CheckTrigger_0_00179F80(&s);
}
