#include "common.h"

typedef struct { s32 x0; u32 flags; char p8[2]; u8 bA; char pB[3]; u8 bE; } Obj;
extern struct { unsigned char : 4; unsigned char f : 1; char pad[15]; } D_004A332C;
void Snd_PlaySe_3_00131600(s32 a, u8 b);

void ShopProc_BackB_0_001A13F0(Obj *o)
{
    if (o->flags & 0x2000) {
        Snd_PlaySe_3_00131600(0x68, o->bE);
        o->bA = 2;
        D_004A332C.f = 1;
    }
    o->flags = 0;
}
