/* round 3 near-miss: 5 words: register swap in case 0's D_004BAA28 update */
#include "common.h"
typedef struct {
    u8 pad0[8];
    u32 x8;
    u8 padC[4];
    s32 x10;
    u8 pad14[2];
    s16 x16;
    u8 pad18[8];
} Ent;
void FlushCache(s32);
s32 func_001D8680(s32 a, s32 b, s32 c, ...);
s32 sceSifDmaStat(u32);
u32 sceSifSetDma(void *, s32);
extern u32 D_004BA2E0[];
extern u32 D_004BA2E4[];
extern u32 D_004BA2E8[];
extern s32 D_004BA2EC[];
extern u32 D_004BA2F4[];
extern u32 D_004BA2F8[];
extern Ent D_004BA500[];
extern u32 D_004BAA28[];
typedef struct { s32 data; s32 addr; u32 size; s32 mode; } Dma;
extern Dma D_004BAA60;

s32 func_001DB020(s32 arg0, s32 arg1, s32 arg2) {
    u32 n;
    Ent *p;
    s32 ret;
    u32 x;
    u32 y;
    s32 r;

    ret = -1;
    if (D_004BA2EC[0] == 0) return ret;
    if (arg0 < 0 || arg0 >= 0x10) return -1;
    p = &D_004BA500[arg0];
    switch (D_004BA2E0[0]) {
    case 0:
        arg2 = (arg2 + 0xF) & ~0xF;
        D_004BA2E4[0] = arg2;
        p->x10 += arg2;
        if (p->x8 == 0) p->x8 = D_004BAA28[0];
        x = p->x8;
        y = D_004BAA28[0];
        if (x >= y) {
            D_004BAA28[0] = x;
            D_004BAA28[0] = D_004BAA28[0] + arg2;
        } else if (y < x + arg2) {
            D_004BAA28[0] = x + arg2;
        }
        D_004BA2E8[0] = p->x8;
        if (0x1F8800 - p->x8 >= (u32)arg2) {
            D_004BAA60.data = arg1;
            D_004BAA60.mode = 0;
            D_004BA2E0[0] = 1;
            ret = 0;
        }
        break;
    case 1:
        D_004BAA60.size = (D_004BA2E4[0] > D_004BA2F4[0]) ? D_004BA2F4[0] : D_004BA2E4[0];
        D_004BAA60.addr = D_004BA2EC[p->x16];
        D_004BA2E0[0] = 2;
    case 2:
        switch (func_001D8680(4, 1, 0x800, p->x16, 0)) {
        case 1:
            D_004BA2E0[0] = 3;
            break;
        case 0:
            return 0;
        }
    case 3:
        D_004BA2F8[0] = sceSifSetDma(&D_004BAA60, 1);
        if (D_004BA2F8[0] == 0) {
            D_004BA2E0[0] = 0;
            break;
        }
        D_004BA2E0[0] = 4;
    case 4:
        if (sceSifDmaStat(D_004BA2F8[0]) >= 0) {
            ret = 0;
            break;
        }
        D_004BA2E0[0] = 5;
    case 5:
        n = D_004BAA60.size;
        r = func_001D8680(4, 1, 0x900, p->x16, 0, D_004BA2EC[p->x16], D_004BA2E8[0], n);
        if (-(r != ((n + 0x3F) & ~0x3F)) < 0) {
            D_004BA2E0[0] = 0;
            break;
        }
        D_004BAA60.data = D_004BAA60.data + D_004BAA60.size;
        D_004BA2E8[0] += D_004BAA60.size;
        D_004BA2E4[0] -= D_004BAA60.size;
        if ((s32)D_004BA2E4[0] > 0) {
            ret = 0;
            D_004BA2E0[0] = 1;
            break;
        }
        D_004BA2E0[0] = 6;
    case 6:
        switch (func_001D8680(4, 1, 0x800, p->x16, 0)) {
        case 1:
            D_004BA2E0[0] = 7;
            break;
        case 0:
            return 0;
        }
    case 7:
    case 8:
        D_004BA2E0[0] = 0;
        ret = 1;
        break;
    }
    FlushCache(0);
    return ret;
}
