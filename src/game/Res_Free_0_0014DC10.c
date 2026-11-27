#include "common.h"

typedef struct { char pad[0x1C]; void *p; } Obj;
void File_Close_2_0015AB80(void *p);

s32 Res_Free_0_0014DC10(Obj *o)
{
    if (o->p)
        File_Close_2_0015AB80(o->p);
    o->p = NULL;
    return 1;
}
