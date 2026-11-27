#include "obj3d.h"
void ItemObj_TestPickRay_0_001AC200(Obj3D *, Obj3D **, f32 *);
Obj3D *ItemObj_FindPickTarget_0_001AC3E0(void) {
    Obj3D *best;
    f32 dist;
    s32 i;
    best = NULL;
    dist = 1e8f;
    for (i = 0; i < 64; i++) {
        ItemObj_TestPickRay_0_001AC200(&D_004AE370[0][i], &best, &dist);
        ItemObj_TestPickRay_0_001AC200(&D_004AE370[1][i], &best, &dist);
    }
    for (i = 0; i < 16; i++) {
        ItemObj_TestPickRay_0_001AC200(&D_004AC970[0][i], &best, &dist);
        ItemObj_TestPickRay_0_001AC200(&D_004AC970[1][i], &best, &dist);
    }
    return best;
}

