#include "m2c.h"
extern s32 D_0030D180[];
extern s32 D_0030D184[];
extern s16 D_0030D588[];
extern s16 D_0030D60A[];
extern s16 D_0030D68C[];
extern s16 D_0030D70E[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s16 D_0030D790[0x108];
extern s16 D_0030D812[];
extern s16 D_0030D894[];
extern s16 D_0030D916[];

void Glow_Init_0_0015DD90(void) {
    s32 i;
    D_0030D180[0] = 0;
    D_0030D916[0] = 0;
    D_0030D184[0] = 0x100;
    D_0030D894[0] = 0;
    D_0030D812[0] = 0;
    D_0030D790[0] = 0;
    D_0030D70E[0] = 0;
    D_0030D68C[0] = 0;
    D_0030D60A[0] = 0;
    D_0030D588[0] = 0;
    for (i = 0; i < 0x100; i++) {
        M2C_FIELD(&D_0030D180[0xFF - i], s32 *, 8) = i;
    }
}
