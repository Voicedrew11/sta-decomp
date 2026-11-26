#include "common.h"
typedef struct { s32 a; s32 b; s32 x8; s32 xC; s32 x10; u16 x14; u16 x16; u8 x18; u8 pad[7]; } E;
typedef struct { s32 x0; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; } S;
typedef struct { u32 data, addr, size, mode; } Dma;
extern E D_004B9F20[4];
extern S D_004B9FA0;
extern s32 D_004B9FA4[];
extern Dma D_004B9FC0;
extern u8 *D_00202310;
extern u32 D_00202314;
void FlushCache(s32);
u32 sceSifSetDma(Dma *, s32);
s32 func_001D9BC0(u8 *src, u32 n, u32 dst, s32 idx) {
    Dma *d = &D_004B9FC0; S *s = &D_004B9FA0;
    u32 i;
    u32 id;
    if (D_004B9FA4[0] != 0) return 0;
    if (n > D_00202314) return 0;
    for (i = 0; i < n; i++) D_00202310[i] = (src + D_004B9F20[idx].x8)[i];
    d->data = (u32)D_00202310;
    d->addr = dst;
    d->size = n;
    d->mode = 0;
    FlushCache(0);
    id = sceSifSetDma(d, 1);
    s->x4 = id;
    return id != 0;
}
