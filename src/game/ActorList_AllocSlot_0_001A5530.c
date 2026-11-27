#include "common.h"
typedef struct { u8 pad[0x5A0]; Flags8 f; } A;
extern s32 D_00202274;
extern A **D_004A4570[];
A **ActorList_AllocSlot_0_001A5530(void) {
    s32 i;
    A ***p;
    i = D_00202274;
    if (i >= 0x81) return NULL;
    goto setup;
body:
    if (*p != NULL && ((**p)->f.f.b0 || (**p)->f.f.b1)) {
        D_00202274 = i + 1;
        return D_004A4570[i];
    }
    p++;
    i++;
cond:
    if (i < 0x81) goto body;
    return NULL;
setup:
    p = &D_004A4570[i];
    goto cond;
}

