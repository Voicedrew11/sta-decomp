#include "common.h"

typedef struct { unsigned char : 2; unsigned char f : 1; char pad[3]; } H;
void Mdl_SetLayerForMesh_0_0016B360(void *a, H h, s32 c);

s32 ItemObj_FilterTranslucent_0_001AD030(void *a, H h)
{
    if (!h.f)
        return 1;
    Mdl_SetLayerForMesh_0_0016B360(a, h, 0);
    return 0;
}
