#include "common.h"
typedef struct { char p[0x1D8]; u8 b0:1; } T;
extern T **D_00201E88;
extern T **D_00201E8C;
typedef struct { s32 x0; char p[0x8A]; s16 x8E; } U;

void func_001B0B30(s32 arg0, s16 arg1) {
    U *r = 0;
    if ((D_00201E88 ? (*D_00201E88)->b0 != 0 : 0) && ((U *)*D_00201E88)->x0 == arg0) r = (U *)*D_00201E88;
    if ((D_00201E8C ? (*D_00201E8C)->b0 != 0 : 0) && ((U *)*D_00201E8C)->x0 == arg0) r = (U *)*D_00201E8C;
    if (r) r->x8E = arg1;
}

