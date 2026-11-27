#include "common.h"

void *Tex_Lookup_1_00177BB0(s32 a, s32 b, s32 c);

void *Tex_Find_1_00177AF0(s32 a, s32 b)
{
    void *p = Tex_Lookup_1_00177BB0(a, b, -1);
    if (p)
        return p;
    return NULL;
}
