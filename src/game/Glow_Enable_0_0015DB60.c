#include "common.h"
extern s32 D_0030D180[];
extern s32 D_0030D184[];
extern s32 D_0030D188[];
typedef struct { char pad[0x50]; unsigned char b0 : 1; unsigned char b1 : 1; char pad2[0xF]; } BF;
extern BF D_0030D9A0[];

void Glow_Enable_0_0015DB60(s32 arg0) {
    BF *t = &D_0030D9A0[arg0];
    s32 temp_5;
    t->b1 = 1;
    t->b0 = 0;
    temp_5 = *D_0030D184;
    (*D_0030D184) += 1;
    D_0030D188[temp_5] = arg0;
    (*D_0030D180) -= 1;
}
