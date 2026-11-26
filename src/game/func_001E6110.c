#include "common.h"
typedef struct { s32 a; s32 b; char rest[0x3F8]; } E;
extern s32 D_002023E4;
extern E D_004BC384[];
s32 func_001E6110(void) {
    s32 r;
    if (D_004BC384[D_002023E4].a == 0) { r = 1; }
    else if (D_004BC384[D_002023E4].b != 0) { r = 0; } else { r = 2; }
    return r;
}
