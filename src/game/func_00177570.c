#include "common.h"
typedef struct { u8 pad[0x4C]; s32 x4C; } Q50;
typedef struct { u8 pad[0x10]; s8 **x10; u8 pad14[8]; s16 x1C; s16 x1E; u16 x20; s16 x22; s32 x24; u8 b0:3; u8 pad29[7]; } E30;
typedef struct {
    s32 x0;
    s32 x4;
    s16 x8, xA, xC, xE;
} G;
extern G D_004830C0;
extern E30 D_004800C0[];
s32 func_00176FB0(s16);

s16 func_00177570(E30 *p) {
    s16 idx = p - D_004800C0;
    Q50 *q;
    if (p->b0 == 1) {
        { u32 t = p->x20 * 0x50; q = (Q50 *)(t + (s32)(*p->x10 + p->x24)); }
        q->x4C--;
        if (q->x4C > 0) {
            return q->x4C;
        }
    }
    D_004830C0.xE--;
    if (idx == D_004800C0[idx].x1C) {
        D_004830C0.xC = -1;
    } else {
        D_004800C0[D_004800C0[idx].x1C].x1E = D_004800C0[idx].x1E;
        D_004800C0[D_004800C0[idx].x1E].x1C = D_004800C0[idx].x1C;
        if (D_004830C0.xC == idx) D_004830C0.xC = D_004800C0[idx].x1C;
    }
    D_004830C0.xA++;
    if (D_004830C0.x8 == -1) {
        D_004830C0.x8 = idx;
        D_004800C0[idx].x1C = idx;
        D_004800C0[idx].x1E = idx;
    } else {
        D_004800C0[idx].x1C = D_004830C0.x8;
        D_004800C0[idx].x1E = D_004800C0[D_004830C0.x8].x1E;
        D_004800C0[D_004800C0[idx].x1C].x1E = idx;
        D_004800C0[D_004800C0[idx].x1E].x1C = idx;
    }
    p->b0 = 0;
    if (p->x22 != -1) func_00176FB0(p->x22);
    return 0;
}
