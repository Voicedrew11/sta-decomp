#include "common.h"

/* bss_004BDF34: the game's .bss from 0x004BDF34, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Movie_InitDisplay_1_001E9AA0, MovieCb_Image_0_001E9DC0, MovieCb_Nodata_0_001E9E40, MovieCb_Error_0_001E9E70,
   MovieCb_AudioYield_0_001E9EA0, MovieVideo_PutData_0_001EA0D0, MovieAudio_Create_1_001EBCC0, MovieCb_VideoStream_0_001EC070, Movie_Shutdown_1_001EC3E0,
   Movie_Init_1_001EC5E0, Movie_ReadLoop_1_001ECAB0, Movie_PlayFile_2_001ED070, Movie_Start_2_001ED0C0, MapSheet_Draw_0_001ED630,
   text_001E8C50.s */

u8 D_004BE11C[0x4]; /* also D_004BE11F */
u8 D_004BE110[0xc] __attribute__((aligned(4)));
u8 D_004BE10C[0x4];
u8 D_004BE0F4[0x18] __attribute__((aligned(4))); /* also D_004BE0F8 */
u8 D_004BE0E0[0x14] __attribute__((aligned(4)));
s16 D_004BE0D8[0x4] __attribute__((aligned(4)));
u8 D_004BE0D4[0x4]; /* also D_004BE0D6 */
u8 D_004BE0D0[0x4];
u8 D_004BE0A8[0x28] __attribute__((aligned(4))); /* also D_004BE0AC */
u8 D_004BE090[0x18] __attribute__((aligned(4)));
u8 D_004BE080[0x10] __attribute__((aligned(4)));
s32 D_004BE07C[0x1];
s32 D_004BE078[0x1];
u8 D_004BE040[0x38] __attribute__((aligned(4))); /* also D_004BE044, D_004BE04C */
u8 D_004BE038[0x8] __attribute__((aligned(4)));
s32 D_004BE034[0x1];
s32 D_004BE030[0x1];
u8 D_004BE02C[0x4];
s32 D_004BE028[0x1];
s32 D_004BE024[0x1];
s32 D_004BE020[0x1];
s32 D_004BE01C[0x1];
s32 D_004BE018[0x1];
s32 D_004BE014[0x1];
s32 D_004BE010[0x1];
u32 D_004BE008[0x2] __attribute__((aligned(4)));
u32 D_004BE004[0x1];
u32 D_004BE000[0x1];
u8 D_004BDFF0[0x10] __attribute__((aligned(4))); /* also D_004BDFF4 */
s32 D_004BDFE8[0x2] __attribute__((aligned(4)));
u8 D_004BDFE4[0x4];
u8 D_004BDFE0[0x4];
u8 D_004BDFDC[0x4];
u8 D_004BDFD8[0x4];
u8 D_004BDFD0[0x8] __attribute__((aligned(4)));
s32 D_004BDFC8[0x2] __attribute__((aligned(4)));
u8 D_004BDF40[0x88] __attribute__((aligned(4))); /* also D_004BDF88, D_004BDF9C */
s32 D_004BDF38[0x2] __attribute__((aligned(4)));
s32 D_004BDF34[0x1];
