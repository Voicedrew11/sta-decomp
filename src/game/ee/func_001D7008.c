#include "common.h"
typedef struct { s32 a[2][4]; s32 b[2][4]; char pad[0x58]; s32 x98; } T;
extern T D_004B63B8;
s32 func_001D7008(s32 i, s32 j) {
    s32 r;
    if (D_004B63B8.b[i][j] == 0 && D_004B63B8.a[i][j] == 0) { D_004B63B8.x98 = 1; return -1; }
    r = D_004B63B8.b[i][j] - 2;
    if (r <= 0) { r = 0; D_004B63B8.x98 = 30; }
    D_004B63B8.x98 = 0;
    return r;
}
