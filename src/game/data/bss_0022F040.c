#include "common.h"

/* bss_0022F040: the game's .bss from 0x0022F040, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Snd_UpdateStreams_0_0012C4D0, Snd_SetStreamParamF064_0_0012C7A0, Snd_SetStreamParamF054_0_0012C7B0, Snd_UpdateBgm_0_0012C7C0,
   Snd_BindMapSe_0_0012DA90, Snd_StartStream1_0_0012DD10, Snd_StartStream2_0_0012DE00, Snd_Init_2_0012DF90, SndBank_RegisterSet_0_0012E640,
   SndBank_LoadStam_1_0012E6B0, SndBank_UploadIndexed_0_0012E810, SndBank_ParseHeader_1_0012E8F0, SndBank_TransferStep_0_0012EA00, SndBank_LoadStep_1_0012ED60,
   SndBank_IopTransferA_0_0012EF40, SndBank_IopTransferC_0_0012F3A0, Snd_StopStream_1_0012F550, SndEmit_StopAllA_1_0012F640, SndEmit_Update_1_0012F6F0,
   SndEmit_OffsetPositions_1_0012F7E0, SndEmit_StopAllB_1_0012F880, SndEmit_KillAll_1_0012F920, SndEmit_SpawnFromMap_0_0012F9D0, SndEmit_Init_1_0012FB80,
   SndEmit_Update3D_1_0012FC20, SndEmit_UpdateAmbientRandom_1_00130090, text_0012E810.s, text_0012F0F0.s */

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
