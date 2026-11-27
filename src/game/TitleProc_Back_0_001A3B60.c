#include "common.h"

typedef struct { s32 x0; u32 flags; char p8[2]; u8 bA; char pB[3]; u8 bE; } Obj;
extern s32 D_00202250, D_0020225C, D_00202258, D_0020223C, D_00202260;
void Snd_PlaySe_3_00131600(s32 a, u8 b);

void TitleProc_Back_0_001A3B60(Obj *o)
{
    if (o->flags & 0x2000) {
        D_00202250 = 0;
        D_0020225C = 1;
        D_00202258 = -5;
        D_0020223C = 99;
        o->bA = 2;
        Snd_PlaySe_3_00131600(0x69, o->bE);
    } else if (o->flags & 0x4000) {
        Snd_PlaySe_3_00131600(0x68, o->bE);
        D_00202250 = 0;
        D_00202260 = 1;
        D_00202258 = -5;
        o->bA = 2;
        D_0020223C = 0;
    }
    o->flags = 0;
}
