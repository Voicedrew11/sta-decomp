#include "common.h"

typedef struct { s32 x0; u32 flags; char p8[2]; u8 bA; char pB[3]; u8 bE; } Obj;
extern struct { unsigned char f : 1; char pad[15]; } D_004A1140;
void LoadMenu_CheckCard_1_00192E90(Obj *o, s32 a);
void Snd_PlaySe_3_00131600(s32 a, u8 b);

void LoadMenu_Retry_0_001937E0(Obj *o)
{
    LoadMenu_CheckCard_1_00192E90(o, 0);
    if (o->flags & 0x2000) {
        o->bA = 2;
        D_004A1140.f = 1;
        Snd_PlaySe_3_00131600(0x67, o->bE);
    }
}
