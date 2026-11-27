#include "common.h"

/* bss_0022F040: the game's .bss from 0x0022F040, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: func_0012C4D0, func_0012C7A0, func_0012C7B0, func_0012C7C0,
   func_0012DA90, func_0012DD10, func_0012DE00, func_0012DF90, func_0012E640,
   func_0012E6B0, func_0012E810, func_0012E8F0, func_0012EA00, func_0012ED60,
   func_0012EF40, func_0012F3A0, func_0012F550, func_0012F640, func_0012F6F0,
   func_0012F7E0, func_0012F880, func_0012F920, func_0012F9D0, func_0012FB80,
   func_0012FC20, func_00130090, text_0012E810.s, text_0012F0F0.s */

u8 D_002704D0[0x80];
u8 D_0026F0D0[0x1400];
f32 D_0026F090[0x10];
u8 D_0022F090[0x40000];
u8 D_0022F08C[0x4];
u8 D_0022F088[0x4];
s32 D_0022F084[0x1];
s32 D_0022F080[0x1];
u8 D_0022F070[0x10]; /* also D_0022F074 */
u8 D_0022F060[0x10]; /* also D_0022F064 */
u8 D_0022F050[0x10]; /* also D_0022F054 */
u8 D_0022F04C[0x4];
s32 D_0022F048[0x1];
s32 D_0022F044[0x1];
u8 D_0022F040[0x4] __attribute__((aligned(16)));
