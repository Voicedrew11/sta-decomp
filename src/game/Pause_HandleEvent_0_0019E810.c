#include "common.h"

typedef struct { s32 x0; u32 x4; u8 b8; char p9[5]; u8 bE; } Obj;
void PlayTime_Pause_1_001DF990(void);
void PlayTime_Resume_1_001DF960(void);
void Snd_PlaySe_3_00131600(s32 a, u8 b);

void Pause_HandleEvent_0_0019E810(Obj *o)
{
    if (o->x0 == 25)
        PlayTime_Pause_1_001DF990();
    if (o->x0 == 22 && ((o->x4 & 1) || (o->x4 & 0x4000))) {
        Snd_PlaySe_3_00131600(0x65, o->bE);
        o->b8 = 18;
        o->x4 = 0;
        o->x0 = 31;
        PlayTime_Resume_1_001DF960();
    }
}
