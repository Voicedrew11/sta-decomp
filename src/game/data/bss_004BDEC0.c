#include "common.h"

/* bss_004BDEC0: the game's .bss from 0x004BDEC0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: func_001E9E10, func_001E9EA0, func_001E9EF0, func_001EA060,
   func_001EBE10, func_001EC3E0, func_001EC5E0, func_001ECAB0,
   text_001E8C50.s */

s32 D_004BDF24[0x1];
u8 D_004BDF20[0x4];
u8 D_004BDF1C[0x4];
u8 D_004BDF18[0x4];
u8 D_004BDF14[0x4];
u8 D_004BDEE0[0x34]; /* also D_004BDF0C */
s32 D_004BDED0[0x4];
s32 D_004BDECC[0x1];
s32 D_004BDEC8[0x1];
u8 *D_004BDEC4[0x1];
u8 D_004BDEC0[0x4] __attribute__((aligned(16)));
