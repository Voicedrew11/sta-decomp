#include "m2c.h"
void sceVu0CopyVector(s8 *, s8 *);
typedef struct { u16 n; u16 idx[64]; } G;
extern s32 D_00201F2C;
extern s8 D_0030D180[];
extern s8 D_0030D9A0[];

void func_0015D650(void) {
    s32 i;
    s32 j;
    G *g;
    s32 k;
    s8 *e;

    for (i = 0; i < 8; i++) {
        g = (G *)(D_0030D180 + i * 0x82 + 0x408);
        k = 0;
        for (j = 0; j < g->n; j++) {
            u16 v = g->idx[j];
            e = D_0030D9A0 + v * 0x60;
            if (k != j) g->idx[k] = v;
            if (((u64)((s64)M2C_FIELD(e, u8 *, 0x50) << 0x3E) >> 0x3F) == 0) k++;
        }
        g->n = k;
    }
    for (i = 0; i < 0x100; i++) {
        e = D_0030D9A0 + i * 0x60;
        if (M2C_FIELD(e, u8 *, 0x50) & 1) {
            sceVu0CopyVector(e + (D_00201F2C << 5), e + 0x40);
        }
    }
}
