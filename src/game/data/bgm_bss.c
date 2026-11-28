#include "common.h"

/* bss_004B9EF0: the game's .bss from 0x004B9EF0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: SndDrv_CallRpcSyncWait_2_001D7EC0, SndDrv_CallRpcSyncWaitB_2_001D7FD0, SndDrv_AllocIopBuffer_1_001D80E0, SndDrv_StartThread_1_001D8210,
   SndDrv_CallWithData_1_001D8350, SndDrv_Call1_1_001D84F0, SndDrv_Call_2_001D85D0, SndDrv_CallArgs_2_001D8680, SndDrv_Bind_2_001D8890,
   SndDrv_CallRpc_2_001D8960, SndDrv_SetPortParam_0_001D8EC0, SndDrv_AllocBuffer_1_001D8F30, Bgm_GetState_0_001D8FB0, Bgm_Poll_0_001D95E0,
   Bgm_SetVolume_1_001D9650, Bgm_Update_0_001D9680, Bgm_Stop_0_001D9710, Bgm_Resume_0_001D97A0, Bgm_ApplyVolume_0_001D9820,
   Bgm_SetTrackParam_0_001D98D0, Bgm_Init_0_001D99A0, Bgm_Tick_0_001D9A80, Bgm_DmaChunk_0_001D9BC0, Se_FlushQueue_0_001D9E30,
   Se_GetFlag_0_001D9F00, Se_ReadStatus_0_001D9F10, Se_WaitDma_0_001DAF80, Se_TransferBank_0_001DB020, Se_AllocIopHeap_0_001DB410,
   Se_Init_1_001DBAC0, Se_QueueCommand_1_001DBDB0, text_001D8F30.s, text_001D9FC0.s,
   text_001DB020.s */

u8 D_004BA2F8[0x8];
u32 D_004BA2F4[0x1];
s32 D_004BA2F0[0x1];
s32 D_004BA2EC[0x1];
u8 D_004BA2E8[0x4];
u32 D_004BA2E4[0x1];
u8 D_004BA2E0[0x4];
u8 D_004BA0E0[0x200]; /* also D_004BA0E1 */
u8 D_004BA040[0xa0]; /* also D_004BA044 */
u8 D_004BA000[0x40];
u8 D_004B9FC0[0x40];
u8 D_004B9FB0[0x10]; /* also D_004B9FB4 */
u8 D_004B9FAC[0x4];
u8 D_004B9FA8[0x4]; /* also D_004B9FAA */
s32 D_004B9FA4[0x1];
u8 D_004B9FA0[0x4];
u8 D_004B9F20[0x80]; /* also D_004B9F24, D_004B9F44, D_004B9F64, D_004B9F84 */
u8 D_004B9EF0[0x30]; /* also D_004B9F14 */
