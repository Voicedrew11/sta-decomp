#include "common.h"
typedef struct { s32 x0; u8 p4[0x28]; s32 x2C; s32 x30; s32 x34; s32 x38; s32 x3C; s32 x40; s32 x44; s32 x48; s32 x4C; s32 x50; s32 x54; s32 x58; } S;
typedef struct { void *src; s32 dst; s32 size; s32 attr; } Dma;
void FlushCache(s32);
s32 sceSdRemote(s32, s32, s32, ...);
void memset(void *, s32, s32);
s32 sceSifAllocIopHeap(s32);
s32 sceSifDmaStat(s32);
s32 sceSifSetDma(Dma *, s32);
extern s32 D_004BD6C0[];
extern s32 D_004BE0D0[];

s32 func_001EBCC0(S *a, s32 a1, s32 a2, s32 a3) {
    Dma d;
    s32 id;
    s32 v;
    a->x0 = 0;
    a->x2C = 0;
    a->x30 = a1;
    a->x34 = 0;
    a->x38 = 0;
    a->x3C = a2;
    a->x40 = 0;
    a->x54 = 0;
    a->x48 = a3;
    a->x4C = 0;
    a->x50 = 0;
    a->x44 = sceSifAllocIopHeap(a3);
    if (a->x44 < 0) return 0;
    a->x58 = sceSifAllocIopHeap(0x800);
    if (a->x58 < 0) return 0;
    memset(D_004BD6C0, 0, 0x800);
    v = a->x58;
    d.src = D_004BD6C0;
    d.dst = v;
    d.size = 0x800;
    d.attr = 0;
    FlushCache(0);
    id = sceSifSetDma(&d, 1);
    while (sceSifDmaStat(id) >= 0) {}
    v = D_004BE0D0[0];
    for (id = 0; id < 2; id++) {
        sceSdRemote(1, 0x8010, id | 0x980, v);
        sceSdRemote(1, 0x8010, id | 0xA80, v);
    }
    return 1;
}
