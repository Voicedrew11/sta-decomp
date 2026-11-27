#include "common.h"
typedef struct { s32 x0; s32 x4; u8 p8[2]; u8 xA; u8 pB[3]; u8 xE; } O;
extern Flags8 D_004A10DC[];
void Snd_PlaySe_3_00131600(s32, s32);
void OptionProc_Back_0_00191C40(O *o) {
    if (o->x4 & 0x2000) {
        D_004A10DC[0].f.b3 = 0;
        o->xA = 2;
        o->x0 = 0x16;
        o->x4 = 0;
        Snd_PlaySe_3_00131600(0x67, o->xE);
    }
}

