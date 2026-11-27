#include "common.h"
typedef struct { u8 pad[0x5A0]; Flags8 f; } A;
extern A **D_004A4570[];
u8 Enemy_Get5B2b3_1_0013E830(A *);
A *ActorList_Next_2_001A5460(s32 *it) {
 A *r; s32 i; A **o;
 i = *it; r = 0;
 while (i < 0x81) { o = D_004A4570[0x80 - i]; i++; if (o != 0 && (*o)->f.f.b0 && (*o)->f.f.b2 && Enemy_Get5B2b3_1_0013E830(*o) == 0) { r = *o; break; } }
 *it = i; return r;
}
