#include "common.h"
void Sfx_RequestStop_1_00167240(s32);
typedef struct { char pad[0xA8]; s32 a8; } T;
void FxProc_ReleaseChild_0_0014B170(T *arg0) {
    volatile s32 sp2C;
    s32 v;

    sp2C = arg0->a8;
    v = sp2C;
    if (v != 0) {
        Sfx_RequestStop_1_00167240(v);
        arg0->a8 = 0;
    }
}
