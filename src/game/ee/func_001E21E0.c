#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct { u64 d; s32 x8; Q *xC; } S;
extern S *D_00201E5C;
#define BIT 0x1000000000000ULL
#define BIT2 0x4000000000000ULL
void func_001E21E0(void) {
    s32 n = 5;
    if (D_00201E5C->x8 != 0) {
        if (!(D_00201E5C->d & BIT)) n = 6;
        D_00201E5C->xC->q = 0;
        D_00201E5C->xC->w[0] = n | 0x20000000;
        D_00201E5C->xC->w[1] = (u32)(D_00201E5C->xC + n + 1);
        D_00201E5C->xC++;
        if (!(D_00201E5C->d & BIT)) {
            D_00201E5C->xC->q = 0;
            D_00201E5C->xC->w[3] = 0x51000005;
            D_00201E5C->xC++;
        }
        D_00201E5C->xC->d[0] = 0x1000000000008004ULL;
        D_00201E5C->xC->d[1] = 0xE;
        D_00201E5C->xC++;
        D_00201E5C->xC->d[0] = 0;
        D_00201E5C->xC->d[1] = 0x3F;
        D_00201E5C->xC++;
        D_00201E5C->xC->d[0] = 0;
        D_00201E5C->xC->d[1] = (D_00201E5C->d & BIT2) ? 9 : 8;
        D_00201E5C->xC++;
        D_00201E5C->xC->d[0] = 0x31001;
        D_00201E5C->xC->d[1] = (D_00201E5C->d & BIT2) ? 0x48 : 0x47;
        D_00201E5C->xC++;
        D_00201E5C->xC->d[0] = 0x48;
        D_00201E5C->xC->d[1] = (D_00201E5C->d & BIT2) ? 0x43 : 0x42;
        D_00201E5C->xC++;
    }
}
