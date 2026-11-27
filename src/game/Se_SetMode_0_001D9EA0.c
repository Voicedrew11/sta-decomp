#include "common.h"
extern s32 D_004BAA24[];
extern s32 D_004BAA28[];

void Se_SetMode_0_001D9EA0(s32 arg0) {
    (*D_004BAA28) = arg0;
    (*D_004BAA24) = arg0;
}
