#include "common.h"
typedef struct { u8 p[0x52]; Flags8 f; u8 p53[0x2D]; } N;
typedef struct { u8 p[0x180]; N *n; } Obj;
s32 MapObj_GetNodeIndex_0_001B7840(u8, u16);
Obj *MapObj_Find_1_001B19A0(u8);

void MapCmd_SetObjectsAlpha_0_0017D480(s8 *a) {
    s32 i;
    Obj *o;
    N *n;
    i = MapObj_GetNodeIndex_0_001B7840(*(u8 *)(a + 8), *(u16 *)(a + 0x10));
    if (i >= 0) {
        o = MapObj_Find_1_001B19A0(*(u8 *)(a + 8));
        if (o != NULL) {
            n = &o->n[i];
            if (n != NULL) {
                if (*(u8 *)(a + 0x18) == 0) {
                    n->f.f.b3 = 0;
                    n->f.f.b4 = 0;
                }
                if (*(u8 *)(a + 0x18) == 1) {
                    n->f.f.b3 = 1;
                    n->f.f.b4 = 0;
                }
                if (*(u8 *)(a + 0x18) == 2) {
                    n->f.f.b3 = 1;
                    n->f.f.b4 = 1;
                }
            }
        }
    }
}
