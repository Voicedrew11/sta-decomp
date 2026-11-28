#include "common.h"
void Obj_FreeTimer_0_0014DA70(s32 arg0);
void Obj_SetTimer_0_0014DA80(s32 arg0, s32 arg1);
void Obj_SetTimerEx_0_0014DA90(s32 arg0, s32 arg1, s32 arg2);

/* Obj_FreeTimer_0_0014DA70 */
void Obj_FreeTimer_0_0014DA70(s32 arg0) {
    Lz_StreamDone_0_00178FD0(arg0 + 0x20);
}

/* Obj_SetTimer_0_0014DA80 */
void Obj_SetTimer_0_0014DA80(s32 arg0, s32 arg1) {
    Lz_StreamStep_1_00178DD0(arg0 + 0x20, arg1);
}

/* Obj_SetTimerEx_0_0014DA90 */
void Obj_SetTimerEx_0_0014DA90(s32 arg0, s32 arg1, s32 arg2) {
    Lz_StreamInit_0_00178F50(arg0 + 0x20, arg1, arg2);
}
