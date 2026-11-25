#include "common.h"

typedef struct { u128 q; } Q;
extern Q D_001F2010;
extern s32 D_002F0F40[8];
extern char D_002F0F60[];
extern s32 D_00201F20;
void func_001E0560(s32 *p, s32 n);
void func_001E0590(void *p, s32 a, s32 b, Q *q);

void func_0014DB60(void)
{
    Q q = D_001F2010;
    s32 i;
    for (i = 7; i >= 0; i--)
        D_002F0F40[i] = 0;
    D_00201F20 = 0;
    func_001E0560(D_002F0F40, 0);
    func_001E0590(D_002F0F60, 0x38, 8, &q);
}
