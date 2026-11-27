#include "common.h"
typedef struct { s32 a; u8 b0 : 1; } R;
typedef struct { char p[8]; s32 x8; char p2[4]; s32 x10; char p3[4]; s32 x18; } A;
R *MapCmd_FindObjectNode_0_0017B930(s32, s32);
void MapCmd_SetObjectNode_0_0017B9E0(volatile A *arg0) {
    s32 v = arg0->x18;
    R *r = MapCmd_FindObjectNode_0_0017B930(arg0->x8, arg0->x10);
    if (r != 0) {
        r->b0 = v;
    }
}
