#include "m2c.h"
typedef struct { s32 pad0[2]; s32 n; s32 c; s32 arr[17]; s32 x54; s32 pad58[4]; s32 base; } G;
extern G D_002F1940;
extern s32 D_00201F28;
void func_001549D0(void);

void func_001548F0(s32 a0) {
    if (D_002F1940.x54 != 0) func_001549D0();
    D_002F1940.c = D_002F1940.base + (a0 * 0x220 + 0xF) * 32;
    D_002F1940.arr[D_002F1940.n] = D_002F1940.c;
    D_002F1940.n++;
    if ((u32)((D_002F1940.c - D_002F1940.base) / 32) < 0x660) D_00201F28 = 1;
    else D_00201F28 = 0;
}
