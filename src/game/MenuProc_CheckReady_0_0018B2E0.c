#include "common.h"

extern void (*D_004A0F98[])(s32);
extern s32 D_004A0FAC[];

void MenuProc_CheckReady_0_0018B2E0(s32 a)
{
    if (D_004A0F98[0] && D_004A0FAC[0] > 0x74)
        D_004A0F98[0](a);
}
