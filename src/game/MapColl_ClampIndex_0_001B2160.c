#include "common.h"

void MapObj_QueryColliders_0_001B1DF0(void *a, s32 *b, s32 *c, s32 d, s32 e, void *f, s32 g, void *h);

void MapColl_ClampIndex_0_001B2160(void *a, s32 *b, s32 *c, s32 d, s32 e)
{
    if (e < -1)
        e = -1;
    MapObj_QueryColliders_0_001B1DF0(a, b, c, d, e, NULL, 0, NULL);
}
