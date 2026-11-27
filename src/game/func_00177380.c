#include "m2c.h"
#include "common.h"

/* func_00177380 */
typedef struct { s16 n0; s16 p2; s16 n4; s16 p6; s32 pad8; s32 used; } L;
extern L D_0047F0C0[];
extern s16 D_004830D0[];
extern s16 D_004830D2[];
extern s16 D_004830D4[];
extern s16 D_004830D6[];
extern s16 D_004830D8[];
extern s16 D_004830DA[];

void func_00177380(s16 i) {

    if (D_0047F0C0[i].used == 0) {
        D_004830DA[0]--;
        if (i == D_0047F0C0[i].n4) {
            D_004830D8[0] = -1;
        } else {
            D_0047F0C0[D_0047F0C0[i].n4].p6 = D_0047F0C0[i].p6;
            D_0047F0C0[D_0047F0C0[i].p6].n4 = D_0047F0C0[i].n4;
            if (D_004830D8[0] == i) D_004830D8[0] = D_0047F0C0[i].n4;
        }
    }
    D_004830D6[0]--;
    if (i == D_0047F0C0[i].n0) {
        D_004830D4[0] = -1;
    } else {
        D_0047F0C0[D_0047F0C0[i].n0].p2 = D_0047F0C0[i].p2;
        D_0047F0C0[D_0047F0C0[i].p2].n0 = D_0047F0C0[i].n0;
        if (D_004830D4[0] == i) D_004830D4[0] = D_0047F0C0[i].n0;
    }
    D_004830D2[0]++;
    if (D_004830D0[0] == -1) {
        D_004830D0[0] = i;
        D_0047F0C0[i].n0 = i;
        D_0047F0C0[i].p2 = i;
    } else {
        D_0047F0C0[i].n0 = D_004830D0[0];
        D_0047F0C0[i].p2 = D_0047F0C0[D_004830D0[0]].p2;
        D_0047F0C0[D_0047F0C0[i].n0].p2 = i;
        D_0047F0C0[D_0047F0C0[i].p2].n0 = i;
        D_004830D0[0] = i;
    }
    D_0047F0C0[i].used = 0;
}

/* func_00177570 */
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
