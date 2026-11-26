#include "common.h"
typedef struct { s32 x0; s32 x4; Flags8 f8; } Res;
extern Res *D_002020AC;
extern s32 D_00201CDC;
extern s32 D_00201CE0;
extern s32 D_00201CE4;
extern s32 D_00201CE8;
s32 func_00183FF0(void) {
    if (D_002020AC == NULL) return 0;
    goto test;
one:
    return 1;
test:
    if (D_002020AC->f8.f.b1) goto one;
    D_00201CDC = -1; D_00201CE0 = -1; D_00201CE4 = -1; D_00201CE8 = -1;
    return 0;
}

