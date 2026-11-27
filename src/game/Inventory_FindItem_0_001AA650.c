#include "common.h"
typedef struct { u8 pad[0x60]; s16 v[16]; u8 pad2[0x1C0-0x80]; } G;
extern u8 *D_00201DC0;
s32 Inventory_FindItem_0_001AA650(s16 arg0) {
    s16 *p;
    G *g;
    s32 j;
    s32 i;
    s32 n;
    n = 0;
    g = (G *)(D_00201DC0 + 0x10E0);
    for (j = 0; j < 0x2A; j++) {
        for (i = 0; i < 0x10; i++) {
            if (arg0 == g[j].v[i]) n++;
        }
    }
    return n;
}
