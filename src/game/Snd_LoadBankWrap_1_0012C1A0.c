#include "common.h"
void Snd_LoadBankWrap_1_0012C1A0(s32 arg0);
s32 Snd_CountActiveVoices_1_0012C1B0(void);
s32 Se_IsVoiceActive_1_001DA4F0(s32 i);

/* Snd_LoadBankWrap_1_0012C1A0 */
void Snd_LoadBankWrap_1_0012C1A0(s32 arg0) {
    Snd_LoadBank_1_0012E3C0((void *) arg0);
}

/* Snd_CountActiveVoices_1_0012C1B0 */
s32 Snd_CountActiveVoices_1_0012C1B0(void)
{
    s32 i;
    s32 n = 0;
    for (i = 0; i < 64; i++) {
        if (Se_IsVoiceActive_1_001DA4F0(i) == 1)
            n++;
    }
    return n;
}
