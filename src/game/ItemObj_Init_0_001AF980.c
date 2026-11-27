#include "common.h"
void ItemMdl_Update_0_001AB690();
void Pool_Free_2_00128580(s32, s32);                    /* extern */
void Task_RunWrap_0_0014DAB0(s32);                         /* extern */
void Task_Register_0_0014DB10(void (*)());                  /* extern */
void memset(s32 *, s32, s32);            /* extern */
extern s32 D_00202288;
extern s32 D_0020228C;
extern s32 D_00202290;
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B80[];
extern s32 D_004B4B88[];

void ItemObj_Init_0_001AF980(void) {
    ItemObj_ClearTables_1_001AFA20();
    memset(D_004B4B70, 0, 0x1C);
    Task_Register_0_0014DB10(ItemMdl_Update_0_001AB690);
    if ((*D_004B4B80) != 0) {
        Pool_Free_2_00128580(D_00202290, (*D_004B4B80));
    }
    if ((*D_004B4B74) != 0) {
        Task_RunWrap_0_0014DAB0((*D_004B4B74));
        (*D_004B4B74) = 0;
    }
    (*D_004B4B80) = 0;
    D_00202288 = 0;
    (*D_004B4B74) = 0;
    D_0020228C = 0;
    (*D_004B4B70) = 0;
    (*D_004B4B88) = 0;
}
