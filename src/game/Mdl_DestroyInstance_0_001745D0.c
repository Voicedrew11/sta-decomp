#include "common.h"
void Mdl_DestroyInstance_0_001745D0(s32 arg0, s32 **arg1) {
    Mdl_Free_0_00170250((s32 *) arg0, (void **) **arg1);
    Pool_FreeChunk_0_001531A0(arg0 + 0x34, arg1);
}
