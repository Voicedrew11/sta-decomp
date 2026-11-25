#include "common.h"
void DeleteThread(s32);                          /* extern */
void TerminateThread(s32);                       /* extern */
void sceSifRemoveRpc(s32 *, s32 *);      /* extern */
void sceSifRemoveRpcQueue(s32 *);            /* extern */
extern s32 D_00201E38;
extern s32 D_002022FC;
extern s32 D_00202300;
extern s32 D_004B7C40[];
extern s32 D_004B7C90[];

s32 func_001D8820(void) {
    if ((D_002022FC != 0) && (D_00202300 != 0)) {
        TerminateThread(D_00201E38);
        DeleteThread(D_00201E38);
        sceSifRemoveRpc(D_004B7C40, D_004B7C90);
        sceSifRemoveRpcQueue(D_004B7C90);
    }
    D_002022FC = 0;
    D_00202300 = 0;
    return 1;
}
