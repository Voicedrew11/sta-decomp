#include "common.h"
typedef struct { s32 x0; s32 x4; u32 x8; s32 xC; s32 x10; s16 x14; char rest[0xA]; } E;
typedef struct { s32 a, b, c, d; } F;
typedef struct { E e[16]; F f[8]; char pad[0x420 - 0x280]; s8 g[8][0x20]; } T;
extern T D_004BA500;
typedef struct { s8 a, b, c, d; } G;
extern G D_004BA780[];
extern u32 D_004BAA28[];
void FlushCache(s32);
s32 sceSifFreeSysMemory(s32);
void func_001D84F0(s32, s32, s32, s32);
s32 func_001D8680(s32 a, s32 b, s32 c, ...);

s32 func_001DACB0(s32 arg0) {
    u32 t;
    s8 k;
    s32 n;
    G *g;
    E *e;
    s32 i;
    if (arg0 < 0 || arg0 >= 16) return -1;
    g = D_004BA780;
    n = 0x40;
    while (n--) {
        if (g->c != -1) {
            k = g->b;
            if (0 > k) {
            } else if (k < 8 && D_004BA500.f[k].c == arg0) {
                D_004BA500.g[k][g->a] = -1;
                g->c = -1;
                g->b = -1;
                g->a = -1;
            }
        }
        g++;
    }
    n = 8;
    while (n--) {
        if (D_004BA500.f[n].c == arg0) D_004BA500.f[n].c = -1;
    }
    e = &D_004BA500.e[arg0];
    func_001D84F0(4, 1, 0x10300, e->x14);
    func_001D8680(4, 0, 0x10A00, e->x14, 0);
    if (*D_004BAA28 == e->x8 + e->x10) *D_004BAA28 = e->x8;
    e->x8 = 0;
    e->x10 = 0;
    if (e->x4 != 0) {
        if (sceSifFreeSysMemory(e->x4) != 0) return -1;
        e->x4 = 0;
    }
    if (e->x0 != 0) {
        if (sceSifFreeSysMemory(e->x0) != 0) return -1;
        e->x0 = 0;
    }
    *D_004BAA28 = 0x5010;
    e = D_004BA500.e;
    i = 0;
    do {
        t = e->x8;
        if (*D_004BAA28 <= t) *D_004BAA28 = t + e->x10;
        i++;
        e++;
    } while (i < 16);
    FlushCache(0);
    return 0;
}

