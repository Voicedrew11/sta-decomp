#include "common.h"
void FlushCache(s32);
void bzero(void *, s32);
void SndDrv_Call_2_001D85D0(s32, s32, s32);
s32 SndDrv_CallArgs_2_001D8680(s32 a, s32 b, s32 c, ...);
typedef struct { s32 x0, x4, x8, xC, x10; s16 x14; u8 p[0xA]; } A;
typedef struct { s32 x0, x4, x8, xC; } B;
typedef struct { s8 b0, b1, b2, b3; } C;
typedef struct { s32 x0, x4; s16 x8, xA; s32 xC, x10; u8 p[0xC]; } M;
extern u8 *D_00202328;
extern s32 D_0020232C;
extern s32 D_00202330;
extern u8 D_004BA0E0[];
extern s32 D_004BA2E0[];
extern A D_004BA500[];
extern B D_004BA700[];
extern C D_004BA780[];
extern M D_004BA880[];
extern s8 D_004BA920[][32];
extern s32 D_004BAA20[];
extern s32 D_004BAA24[];
extern s32 D_004BAA28[];
extern s32 D_004BAA2C[];
extern s32 D_004BAA30[];
extern s16 D_004BAA34[];
extern s16 D_004BAA36[];
extern s32 D_004BAA58[];

s32 Se_Init_1_001DBAC0(void) {
    M *m;
    s32 i;
    A *a;
    B *b;
    C *c;
    s8 (*t)[32];
    s32 j;

    SndDrv_Call_2_001D85D0(4, 1, 0x100);
    D_004BAA30[0] = 0x3FFF;
    SndDrv_CallArgs_2_001D8680(4, 1, 0x400, D_004BAA30[0], D_004BAA30[0]);
    D_004BAA20[0] = 0;
    D_004BAA2C[0] = SndDrv_CallArgs_2_001D8680(4, 1, 0xA00);
    D_004BAA28[0] = 0x5010;
    D_004BAA24[0] = 0x5010;
    D_004BAA34[0] = 1;
    D_004BAA36[0] = 0;
    a = D_004BA500;
    i = 16;
    while (i--) {
        a->x0 = a->x4 = a->x8 = 0;
        a->x10 = 0;
        a->x14 = 15 - i;
        a++;
    }
    b = D_004BA700;
    i = 8;
    while (i--) {
        b->x0 = 0;
        b->x4 = b->xC = 7 - i;
        b->x8 = -1;
        b++;
    }
    c = D_004BA780;
    i = 64;
    while (i--) {
        c->b0 = c->b1 = c->b2 = -1;
        c++;
    }
    m = D_004BA880;
    i = 4;
    while (i--) {
        m->x0 = -1;
        m->x10 = 0;
        m->xC = 0;
        m->x4 = m->x8 = m->xA = 0;
        m++;
    }
    t = D_004BA920;
    i = 8;
    while (i--) {
        for (j = 0; j < 32; j++) (*t)[j] = -1;
        t++;
    }
    D_004BAA58[0] = 0;
    bzero(D_004BA2E0, 0x1C);
    D_00202328 = &D_004BA0E0[1];
    D_00202330 = 0;
    D_0020232C = 0;
    D_004BA0E0[0] = 0;
    FlushCache(0);
    return 0;
}
