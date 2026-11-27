#include "common.h"

/* bss_0042D7E0: the game's .bss from 0x0042D7E0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: Fx_SpawnParticle_1_00161060, Sfx_UpdateInstance_0_00168D70, Sfx_CompactPool_3_00169780, Sfx_PlanCompactPool_3_00169790,
   Sfx_RegisterList_0_00169D00, Sfx_LoadStam_1_00169D70, Sfx_InitSystem_1_0016AD10, Sfx_GetFreeSlots_1_0016B230, Mdl_EmitMeshVu1_1_0016E760,
   Mdl_EmitMeshVu1B_1_0016EB70, Mdl_EmitPolys_1_0016EF70, Mdl_Relocate_1_00170380, TexAnim_InitTables_0_001746A0, TexAnim_Update_0_001752A0,
   TexAnim_SetScroll_0_001757C0, TexAnim_GetFrame_0_00175850, TexAnim_Release_0_001758B0, TexAnim_Register_0_001759D0, TexAnim_FreeAll_0_00175B40,
   TexAnim_DrawAll_0_00175BB0, TexAnim_Init_0_00175C80, Tex_Upload_0_00175CD0, Tex_UploadQueued_1_00176350, Tex_FlushLayer_0_00176440,
   Tex_SetTex0_1_00176550, Tex_CalcVramSize_0_00176710, Vram_Reset_0_001769C0, Tex_UploadQueuedWrap_0_00176A40, Tex_BeginFrame_0_00176A60,
   Tex_Bind_1_00176B10, Vram_AllocForTex_0_00176BF0, Vram_FreeBlock_0_00177380, Tex_Release_1_00177570, Tex_FindByHash_1_00177B20,
   Tex_Lookup_1_00177BB0, Tex_ReleaseList_0_00178030, Tex_RegisterTtix_0_00178080, Vram_Init_0_001781A0, Dma_ClearBuffer_1_00178DB0,
   text_0016EF70.s, text_00176FB0.s, text_001777C0.s, text_00177BB0.s,
   text_001789E0.s */

u8 D_00483100[0x3000]; /* also D_004860FE */
u8 D_004830F0[0x10]; /* also D_004830F4 */
s32 D_004830EC[0x1];
s32 D_004830E8[0x1];
s32 D_004830E4[0x1];
s32 D_004830E0[0x1];
u8 D_004830DC[0x4]; /* also D_004830DE */
u8 D_004830D8[0x4]; /* also D_004830DA */
u8 D_004830D4[0x4]; /* also D_004830D6 */
u8 D_004830D0[0x4]; /* also D_004830D2 */
u8 D_004830CC[0x4]; /* also D_004830CE */
u8 D_004830C8[0x4]; /* also D_004830CA */
u8 D_004830C4[0x4];
u8 D_004830C0[0x4];
u8 D_00483090[0x30]; /* also D_004830AC */
u8 D_004800DC[0x2fb4] __attribute__((aligned(4))); /* also D_004800DE, D_004800E2, D_004800EA, D_004800EE */
u8 D_004800D0[0xc]; /* also D_004800D4 */
u8 D_004800C8[0x8];
u8 D_004800C0[0x8];
u8 D_004800B0[0x10];
u8 D_0047F0C8[0xfe8] __attribute__((aligned(8))); /* also D_0047F0CA, D_0047F0CC */
u8 D_0047F0C4[0x4]; /* also D_0047F0C6 */
u8 D_0047F0C0[0x4]; /* also D_0047F0C2 */
u8 D_0047F080[0x40]; /* also D_0047F084 */
u8 D_0043F080[0x40000];
u8 D_00438A70[0x6610];
u8 D_00438A30[0x40];
u8 D_00438A20[0x10]; /* also D_00438A22, D_00438A24 */
u8 D_00438A1C[0x4]; /* also D_00438A1E */
s32 D_00438A18[0x1];
s32 D_00438A14[0x1];
u8 D_00438A10[0x4];
u8 D_00437DC0[0xc50]; /* also D_00437DC8, D_004380D8, D_004383E8, D_004386F8 */
u8 D_0042DDC0[0xa000];
u8 D_0042D8C0[0x500];
s32 D_0042D8B8[0x2];
s32 D_0042D8B4[0x1];
u8 D_0042D8B0[0x4];
u8 D_0042D8AC[0x4];
u8 D_0042D8A8[0x4];
u8 D_0042D8A4[0x4];
u8 D_0042D8A0[0x4];
u8 D_0042D89C[0x4];
s32 D_0042D898[0x1];
s32 D_0042D894[0x1];
s32 D_0042D890[0x1];
s32 D_0042D88C[0x1];
s32 D_0042D888[0x1];
s32 D_0042D884[0x1];
s32 D_0042D880[0x1];
u8 D_0042D850[0x30];
u8 D_0042D7E0[0x70];
