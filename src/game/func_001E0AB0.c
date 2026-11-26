#include "common.h"
typedef struct { u8 x0; u8 x1; u8 p2[6]; s32 x8; u8 pC[2]; u16 xE; s32 x10; s32 x14; } T;
extern s32 (*D_004BAC24[])(T *, s32);
extern s32 (*D_004BAC28[])(T *);

s32 func_001E0AB0(T *p) {
    if (p == NULL) return -1;
    if (p->x14 == 0) return -1;
    if (p->x0 != 1) return -1;
    if (p->x1 != 2) return -1;
    if (D_004BAC24[0] != NULL) {
        if (D_004BAC24[0](p, 0x20000) != 0) {
            if (p->xE != 0) {
                p->x14 += 0x20000;
                p->x8 -= 0x20000;
            } else {
                p->x14 = p->x10;
                p->x8 -= 0x20000;
                p->x0 = 4;
                p->x1 = 3;
            }
            return 0;
        }
        if (D_004BAC28[0] != NULL) {
            if (D_004BAC28[0](p) != 0) {
                p->x0 = 3;
            } else {
                p->x0 = 6;
            }
        } else {
            p->x0 = 6;
        }
        p->x1 = 0;
        p->x8 = 0;
        return 1;
    }
    return -1;
}
