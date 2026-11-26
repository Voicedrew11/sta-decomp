#include "common.h"
typedef struct { u8 p[0x3C0]; s32 x3C0; s32 x3C4; u8 q[0x38]; } S;
extern s32 D_002023B8;
extern s32 D_002023E4;
extern S D_004BC380[];
s32 func_001E5E80(s32 *o) {
    S *s;
    s32 i;
    s32 *a;
    s32 k;
    s32 *b;
    k = D_002023E4;
    if (D_002023B8 == 0) return -1;
    s = &D_004BC380[k];
    a = &s->x3C4;
    b = &s->x3C0;
    for (i = 0; i < 12; i++, o++) {
        if ((*a >> i) & 1) *o = 2;
        else if ((*b >> i) & 1) *o = 1;
        else *o = 0;
    }
    return 0;
}

