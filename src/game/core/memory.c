#include "common.h"
typedef struct { s32 off[8]; s32 sz[8]; } T;
extern T D_00222B50;
extern s32 D_00201E80;
void Mem_LayoutRegions_1_00128E80(void) {
    s32 v = D_00201E80;
    D_00222B50.off[0] = v; v += D_00222B50.sz[0];
    D_00222B50.off[1] = v; v += D_00222B50.sz[1];
    D_00222B50.off[2] = v; v += D_00222B50.sz[2];
    D_00222B50.off[3] = v; v += D_00222B50.sz[3];
    D_00222B50.off[4] = v; v += D_00222B50.sz[4];
    D_00222B50.off[5] = v; v += D_00222B50.sz[5];
    D_00222B50.off[6] = v;
}
