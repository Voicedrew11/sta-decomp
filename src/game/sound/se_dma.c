#include "common.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct { u32 p; s32 x4; s32 x8; u32 sz; u8 pad[0x10]; } E_Se_UploadBankB_1_001DB510;
typedef struct { s32 v; s32 pad[7]; } E_Se_FindFreeSlot_0_001DB6B0;
typedef struct { s32 x0, x4, x8, xC, x10; s16 x14; u8 p[0xA]; } A;
typedef struct { s32 x0, x4, x8, xC; } B;
typedef struct { s8 b0, b1, b2, b3; } C;
typedef struct { s32 x0, x4; s16 x8, xA; s32 xC, x10; u8 p[0xC]; } M;
typedef struct { s8 a; s8 b; s8 c; u8 d; } E;
typedef char *va_list;
extern E_Se_UploadBankB_1_001DB510 D_004BA500[16];
extern E_Se_FindFreeSlot_0_001DB6B0 D_004BA500__as_Se_FindFreeSlot_0_001DB6B0[];
extern s16 D_004BAA34[];
extern s32 D_004BAA2C[];
extern s32 D_004BAA40[];
extern s32 D_004BAA44[];
extern s32 D_004BAA48[];
extern s32 D_004BAA4C[];
extern s32 D_004BAA50[];
extern s32 D_004BAA54[];
extern s32 D_004BAA58[];
extern s32 D_004BAA60[];
extern s32 D_004BAA64[];
extern s32 D_004BAA68[];
extern s32 D_004BAA6C[];
extern u32 D_004BAA48__as_Se_DmaBegin_1_001DB9B0[];
extern u32 D_004BAA4C__as_Se_DmaBegin_1_001DB9B0[];
extern u32 D_004BAA50__as_Se_DmaBegin_1_001DB9B0[];
extern u32 D_004BAA68__as_Se_DmaBegin_1_001DB9B0[];
extern B D_004BA700[];
extern C D_004BA780[];
extern M D_004BA880[];
extern s32 D_004BAA20[];
extern s32 D_004BAA28[];
extern s32 D_004BAA30[];
extern A D_004BA500__as_Se_Init_1_001DBAC0[];
extern s16 D_004BAA36__as_Se_Init_1_001DBAC0[];
extern struct { char pad[0x280]; E e[0x68]; u8 t[16][32]; } D_004BA500__as_Se_ParseVoiceMap_0_001DBD20;
extern s8 *D_00202328__as_Se_QueueCommand_1_001DBDB0;
extern s8 D_004BA2E0__as_Se_QueueCommand_1_001DBDB0[];
extern s16 D_001F38F0[];
extern s16 D_001F38F2[];
extern s16 D_001F39EE[];
s32 Se_UploadBankB_1_001DB510(s32 i, s32 a1, u32 sz);
s32 Se_FindFreeSlot_0_001DB6B0(void);
void Se_ParseVoiceMap_0_001DBD20(u8 *a);
void Se_QueueCommand_1_001DBDB0(u8 c, s32 n, ...);
void FlushCache(s32);
u32 sceSifAllocIopHeap(u32);
s32 SndDrv_CallArgs_2_001D8680(s32, s32, s32, ...);
void SndDrv_Call_2_001D85D0(int, int, int);
s32 SndDrv_Call_2_001D85D0__as_Se_UploadBankB_1_001DB510();
s32 sceSifDmaStat(u32);
s32 sceSifSetDma(void *, s32);
void FlushCache__as_Se_DmaStep_1_001DB830(s32, s32);
s32 Se_DmaBegin_1_001DB9B0__as_Se_UploadBankB_1_001DB510_(u32, s32, s32);
u32 sceSifSetDma__as_Se_UploadBankB_1_001DB510_(void *, s32);
void FlushCache__as_Se_DmaBegin_1_001DB9B0(s32, s32);
s32 sceSifSetDma__as_Se_DmaBegin_1_001DB9B0(s32 *, s32);
void bzero(void *, s32);
void SndDrv_CallArgs_2_001D8680__as_Se_UploadBankB_1_001DB510__(s32 a, s32 b, s32 c, ...);

/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510___ */
/* Se_UploadBankB_1_001DB510__ */

/* Se_UploadBankB_1_001DB510_ */

/* Se_UploadBankB_1_001DB510_ */
/* Se_UploadBankB_1_001DB510 */

/* Se_UploadBankB_1_001DB510 */
/* Se_UploadBankB_1_001DB510 */
/* Se_UploadBankB_1_001DB510 */
s32 Se_UploadBankB_1_001DB510(s32 i, s32 a1, u32 sz)
{
    E_Se_UploadBankB_1_001DB510 *e;
    s32 ret = -1;

    if (i < 0 || i >= 16)
        return -1;
    e = &D_004BA500[i];
    switch (D_00202330) {
    case 0:
        sz = (sz + 15) & ~15;
        if (e->p == 0) {
            e->p = sceSifAllocIopHeap(sz);
            if (e->p == 0)
                break;
            if (e->p + sz > 0x1FFFFF)
                break;
        } else if (e->sz != sz) {
            break;
        }
        e->sz = sz;
        D_00202330 = 1;
    case 1:
        if (Se_DmaStep_1_001DB830() != 0) {
            D_00202330 = 2;
        } else {
            ret = 0;
            break;
        }
    case 2:
        if (Se_DmaBegin_1_001DB9B0__as_Se_UploadBankB_1_001DB510_(e->p, a1, e->sz) < 0) {
            D_00202330 = 0;
            break;
        }
        D_00202330 = 3;
    case 3:
        if (Se_DmaStep_1_001DB830() != 0) {
            D_00202330 = 0;
            ret = 1;
        } else {
            ret = 0;
        }
    }
    FlushCache(0);
    return ret;
}

/* Se_FindFreeSlot_0_001DB6B0 */
s32 Se_FindFreeSlot_0_001DB6B0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_004BA500__as_Se_FindFreeSlot_0_001DB6B0[i].v == 0) break;
    }
    if (i >= 16) return -1;
    return i;
}

/* Se_SendCommand_0_001DB700 */
void Se_SendCommand_0_001DB700(u32 a, u32 b)
{
    u32 t[2] = { 0 };
    t[a & 1] = 1 << (b % 24);
    SndDrv_CallArgs_2_001D8680__as_Se_UploadBankB_1_001DB510__(4, 1, 0x10700, t[0], t[1]);
}

/* Se_Stop_0_001DB780 */
void Se_Stop_0_001DB780(void) {
    if ((*D_004BAA36) != 0) {
        SndDrv_Call_2_001D85D0__as_Se_UploadBankB_1_001DB510(4, 1, 0x600);
    }
    (*D_004BAA34) = 0;
    SndDrv_Call1_1_001D84F0(4, 1, 0xC00, 0);
    if ((*D_004BAA36) != 0) {
        SndDrv_Call_2_001D85D0__as_Se_UploadBankB_1_001DB510(4, 1, 0x500);
    }
}

/* Se_Start_0_001DB7F0 */
/* Turn a sound channel's output on once; the same shape as Strm_DrvInit_0_001D8E30
 * and KFIV's SoundDriver_EnableOutput (kfiv-decomp src/game/sound/sound.c). */



void Se_Start_0_001DB7F0(void)
{
    if (D_004BAA36[0] != 1) {
        SndDrv_Call_2_001D85D0(4, 1, 0x500);
        D_004BAA36[0] = 1;
    }
}

/* Se_DmaStep_1_001DB830 */

s32 Se_DmaStep_1_001DB830(void) {
    if (D_004BAA58[0] == 0) return 1;
    if (sceSifDmaStat(D_004BAA54[0]) >= 0) return 0;
    SndDrv_CallArgs_2_001D8680__as_Se_UploadBankB_1_001DB510__(4, 1, 0xB00, D_004BAA40[0], D_004BAA50[0]);
    D_004BAA48[0] -= D_004BAA50[0];
    if (D_004BAA48[0] <= 0) {
        D_004BAA58[0] = 0;
        return 1;
    }
    D_004BAA44[0] += 0x4000;
    D_004BAA40[0] += 0x4000;
    if (D_004BAA48[0] > 0x4000) {
        D_004BAA4C[0] = 0x4000;
        D_004BAA50[0] = 0x4000;
    } else {
        D_004BAA4C[0] = D_004BAA48[0];
        D_004BAA50[0] = D_004BAA48[0];
        D_004BAA4C[0] = (D_004BAA4C[0] + 0xF) & ~0xF;
    }
    D_004BAA6C[0] = 0;
    D_004BAA60[0] = D_004BAA44[0];
    D_004BAA64[0] = D_004BAA2C[0];
    D_004BAA68[0] = D_004BAA4C[0];
    FlushCache__as_Se_DmaStep_1_001DB830(0, D_004BAA44[0]);
    D_004BAA54[0] = sceSifSetDma__as_Se_UploadBankB_1_001DB510_(D_004BAA60, 1);
    return 0;
}

/* Se_DmaBegin_1_001DB9B0 */

s32 Se_DmaBegin_1_001DB9B0(s32 arg0, s32 arg1, u32 arg2) {
    (*D_004BAA44) = arg1;
    (*D_004BAA40) = arg0;
    (*D_004BAA58) = 1;
    (*D_004BAA48__as_Se_DmaBegin_1_001DB9B0) = arg2;
    if (arg2 > 0x4000) {
        (*D_004BAA4C__as_Se_DmaBegin_1_001DB9B0) = 0x4000;
        (*D_004BAA50__as_Se_DmaBegin_1_001DB9B0) = 0x4000;
    } else {
        (*D_004BAA4C__as_Se_DmaBegin_1_001DB9B0) = arg2;
        (*D_004BAA50__as_Se_DmaBegin_1_001DB9B0) = arg2;
        (*D_004BAA4C__as_Se_DmaBegin_1_001DB9B0) = ((*D_004BAA4C__as_Se_DmaBegin_1_001DB9B0) + 0xF) & ~0xF;
    }
    (*D_004BAA6C) = 0;
    (*D_004BAA60) = (*D_004BAA44);
    (*D_004BAA64) = (*D_004BAA2C);
    (*D_004BAA68__as_Se_DmaBegin_1_001DB9B0) = (*D_004BAA4C__as_Se_DmaBegin_1_001DB9B0);
    FlushCache__as_Se_DmaBegin_1_001DB9B0(0, (*D_004BAA44));
    (*D_004BAA54) = sceSifSetDma__as_Se_DmaBegin_1_001DB9B0(D_004BAA60, 1);
    if ((*D_004BAA54) == 0) {
        return -1;
    }
    return 0;
}

/* Se_Init_1_001DBAC0 */

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
    D_004BAA36__as_Se_Init_1_001DBAC0[0] = 0;
    a = D_004BA500__as_Se_Init_1_001DBAC0;
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

/* Se_ParseVoiceMap_0_001DBD20 */
void Se_ParseVoiceMap_0_001DBD20(u8 *a) {
    s32 n = *a; u8 *p = a + 1; while (n--) { u8 i = p[0]; u8 j = p[1]; s8 c = p[2]; E *e = &D_004BA500__as_Se_ParseVoiceMap_0_001DBD20.e[i]; p += 3; if (c >= 0) { e->b = j; e->a = c; e->c = 1; D_004BA500__as_Se_ParseVoiceMap_0_001DBD20.t[j][e->a] = i; } else { e->c = -1; e->b = -1; } }
}

/* Se_QueueCommand_1_001DBDB0 */
void Se_QueueCommand_1_001DBDB0(u8 c, s32 n, ...) {
    s32 i;
    va_list ap;
    ap = (char *)__builtin_next_arg(n) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    *D_00202328__as_Se_QueueCommand_1_001DBDB0++ = c;
    if (c == 1) D_00201E3C += 3;
    { i = n; while (i--) { if (D_00202328__as_Se_QueueCommand_1_001DBDB0 >= D_004BA2E0__as_Se_QueueCommand_1_001DBDB0) break; ap += 8; *D_00202328__as_Se_QueueCommand_1_001DBDB0++ = *(s32 *)(ap - 8); } }
    D_004BA0E0[0]++;
}

/* Se_VolumeCurveA_0_001DBEA0 */
s16 Se_VolumeCurveA_0_001DBEA0(s32 a) {
    s32 m;
    s32 i;
    s32 f;
    s16 t;
    a += 0x200;
    if (a > 0x7FF) a -= 0x800;
    m = a & 0x1FF;
    i = m >> 2;
    f = 4 - m % 4;
    switch (a / 0x200) {
    case 0:
        if (i < 0x7F) {
            t = D_001F38F2[i];
            return t + f * (D_001F38F0[i] - t) / 4;
        }
        return *D_001F39EE;
    case 1:
        if (i > 0) {
            t = D_001F38F0[0x7F - i];
            return t + f * (D_001F38F0[0x80 - i] - t) / 4;
        }
        return *D_001F39EE;
    case 2:
        if (i < 0x7F) {
            t = D_001F38F2[i];
            return -(t + f * (D_001F38F0[i] - t) / 4);
        }
        return -*D_001F39EE;
    case 3:
        if (i > 0) {
            t = D_001F38F0[0x7F - i];
            return -(t + f * (D_001F38F0[0x80 - i] - t) / 4);
        }
        return -*D_001F39EE;
    }
    return 0;
}

/* Se_VolumeCurveB_0_001DC0F0 */
s16 Se_VolumeCurveB_0_001DC0F0(s32 a) {
    s32 m = a & 0x1FF;
    s32 i = m >> 2;
    s32 w = 4 - m % 4;
    s16 b;
    switch (a / 512) {
    case 0:
        if (i < 0x7F) {
            b = D_001F38F2[i];
            return b + w * (D_001F38F0[i] - b) / 4;
        }
        return D_001F39EE[0];
    case 1:
        if (i > 0) {
            b = D_001F38F0[0x7F - i];
            return b + w * (D_001F38F0[0x80 - i] - b) / 4;
        }
        return D_001F39EE[0];
    case 2:
        if (i < 0x7F) {
            b = D_001F38F2[i];
            return -(b + w * (D_001F38F0[i] - b) / 4);
        }
        return -D_001F39EE[0];
    case 3:
        if (i > 0) {
            b = D_001F38F0[0x7F - i];
            return -(b + w * (D_001F38F0[0x80 - i] - b) / 4);
        }
        return -D_001F39EE[0];
    }
    return 0;
}
