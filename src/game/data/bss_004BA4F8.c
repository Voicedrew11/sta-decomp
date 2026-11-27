#include "common.h"

/* bss_004BA4F8: the game's .bss from 0x004BA4F8, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: func_001DA1D0, func_001DA4F0, func_001DA530, func_001DA620,
   func_001DA720, func_001DA7D0, func_001DA840, func_001DA8F0, func_001DA920,
   func_001DA9A0, func_001DAA90, func_001DAC30, func_001DAC70, func_001DACB0,
   func_001DAEF0, func_001DB020, func_001DB510, func_001DB6B0, func_001DBAC0,
   func_001DBD20, text_001D9FC0.s, text_001DB020.s */

u8 D_004BA880[0x80] __attribute__((aligned(8)));
u8 D_004BA780[0x100] __attribute__((aligned(8))); /* also D_004BA782 */
u8 D_004BA700[0x80] __attribute__((aligned(8))); /* also D_004BA70C */
u8 D_004BA500[0x200] __attribute__((aligned(8)));
s32 D_004BA4F8[0x2];
