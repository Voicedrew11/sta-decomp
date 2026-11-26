/* NEAR: 6 of 86 words differ (was 36). Only a0/v1 swap left in the block before the loop: retail g=&D in a0, data in v1\n   (addiu a0,s3,lo; lw v1,8(a0); lw v0,0xC(v1); daddu t1,a0; addu a2,v1,v0; addiu t2,t1,8); ours has them swapped and t2 from v1.\n   Keys: switch case order 0/default,1,2,3 + volatile D_00201B88/8C (stops reorg stealing/cross-jumping), t[2][3] 2D array\n   for x1C/x28 (single IV, -0xC store), p via D_004BC2F0.data and q via pd=&D_004BC2F0.data gives the daddu copy. */
/* round 2 near-miss: ee-gcc, s1/s2 swap, switch store merging, &g->data in own register */
#include "common.h"
typedef struct { u8 pad[4]; f32 rate; u8 *data; u8 pad0C[8]; s32 size; u8 pad18[4]; u8 *t[2][3]; u8 pad34[0x4C]; } G;
extern G D_004BC2F0;
extern volatile f32 D_00201B88;
extern volatile f32 D_00201B8C;
void *memset(void *, s32, u32);
void func_001E3DB8(u32);
void func_001E3DD8(void);
s32 func_001E3EC0(void);

s32 func_001E3B48(u8 *data, s32 size) {
    G *g;
    s32 i;
    u32 *h;
    u32 a, b;
    u8 **pd;
    memset(&D_004BC2F0, 0, 0x80);
    if (data != NULL && size != 0) {
        D_004BC2F0.size = size;
        D_004BC2F0.data = data;
        switch (data[0xB]) {
        case 0: default: D_004BC2F0.rate = D_00201B88; break;
        case 1: D_004BC2F0.rate = 20.0f; break;
        case 2: D_004BC2F0.rate = D_00201B8C; break;
        case 3: D_004BC2F0.rate = 40.0f; break;
        }
        g = &D_004BC2F0;
        if (*(u32 *)(g->data + 0xC) != 0) {
            h = (u32 *)(g->data + *(u32 *)(g->data + 0xC));
            pd = &D_004BC2F0.data;
            for (i = 0; i < 3; i++) {
                if ((a = h[i + 4]) != 0 && (b = h[i]) != 0) {
                    u8 *p = D_004BC2F0.data + a; u8 *q = *pd + b;
                    g->t[0][i] = p; g->t[1][i] = q;
                }
            }
            func_001E3DD8();
        }
        func_001E3DB8(0);
        return func_001E3EC0();
    }
    return -1;
}




