#include "common.h"

typedef struct { unsigned char : 3; unsigned char f : 1; char pad[3]; } H;
void Mdl_SetLayerForMesh_0_0016B360(void *a, H h, s32 c);

s32 Map_FilterTranslucent_0_001B3F80(void *a, H h)
{
    if (h.f)
        return 1;
    Mdl_SetLayerForMesh_0_0016B360(a, h, 3);
    return 0;
}
