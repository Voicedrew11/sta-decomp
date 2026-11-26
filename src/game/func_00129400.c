#include "common.h"
void sceDevVif0Reset();                            /* extern */
void sceSdRemoteInit();                            /* extern */
void sceDevVu0Pause();                           /* extern */
void sceDmaReset(s32);                       /* extern */
void sceGsResetPath();                           /* extern */
void sceMcInit();                                /* extern */

void func_00129400(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_2;

    sceDevVif0Reset();
    sceDevVu0Pause();
    sceGsResetPath();
    sceDmaReset(1);
    temp_2 = *(s32 *)0x1000E000 | 0x303;
    *(s32 *)0x1000E000 = temp_2;
    *(s32 *)0x1000E000 = temp_2;
    func_0015CB50();
    func_0015AD00((s32 *) arg0, arg1, arg2);
    func_0015C9F0(-0x14CD88B5);
    sceMcInit();
    sceSdRemoteInit();
}
