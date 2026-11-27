#include "common.h"
typedef struct { u8 pad[0x5A0]; Flags8 f5A0; } A;
extern s32 D_00202274;
extern A **D_004A4570[];
A *ActorList_NextTargetable_0_001A5660(void) {
    s32 i = D_00202274; A ***p; if (!(i < 0x81)) return NULL; goto setup; body: if (*p && ((**p)->f5A0.b & 1) && (**p)->f5A0.f.b2) { D_00202274 = i + 1; return *D_004A4570[i]; } p++; i++; cond: if (!(i < 0x81)) return NULL; goto body; setup: p = &D_004A4570[i]; goto cond;
}
