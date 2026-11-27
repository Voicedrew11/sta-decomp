#include "common.h"

typedef struct { s32 x0; u32 flags; u8 b8; char p9; u8 bA; char pB[3]; u8 bE; } Obj;
u8 MenuStack_Pop_1_00189EA0(void);
void Snd_PlaySe_3_00131600(s32 a, u8 b);

void MenuProc_BackOnCancel_0_0018D000(Obj *o)
{
    if (o->flags & 0x2000) {
        o->bA = 2;
        o->b8 = MenuStack_Pop_1_00189EA0();
        o->flags = 0;
        o->x0 = 0x1A;
        Snd_PlaySe_3_00131600(0x67, o->bE);
    }
}
