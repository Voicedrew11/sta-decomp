#include "m2c.h"
typedef struct { s32 pad[3]; s32 c; } E;
typedef struct {
    s32 pad0;
    s32 ***p4;
    s32 **p8;
    s32 padc[7];
    s32 o[15]; /* 0x28.. 0x64 */
    s32 o64, o68;
    u16 n[11]; /* 0x6C..0x80 */
    u16 pad82;
    u8 pad84[0x134 - 0x84];
    s32 r[24]; /* 0x134.. */
    E *e;      /* 0x194 */
} S;

void func_001B4F20(S *a) {
    s32 base;
    s32 p;
    s32 i;
    base = *(*a->p4)[4];
    if (a->n[0]) a->r[0] = base + a->o[0];
    if (a->n[1]) a->r[1] = base + a->o[1];
    if (a->n[2]) a->r[2] = base + a->o[2];
    if (a->n[3]) a->r[3] = base + a->o[3];
    if (a->n[4]) a->r[4] = base + a->o[4];
    if (a->n[5]) a->r[5] = base + a->o[5];
    if (a->n[7]) a->r[6] = base + a->o[6];
    if (a->n[6]) a->r[7] = base + a->o[8];
    if (a->n[8]) a->r[13] = base + a->o[11];
    if (a->n[9]) a->r[14] = base + a->o[12];
    a->r[11] = a->o64 ? base + a->o64 : 0;
    a->r[12] = a->o68 ? base + a->o68 : 0;
    a->r[8] = base + a->o[9];
    a->r[9] = base + a->o[10];
    a->r[15] = base + a->o[13];
    a->r[16] = a->o[14] ? base + a->o[14] : 0;
    a->r[10] = a->r[9] + 0x36;
    p = (s32)*a->p8;
    if (a->n[0]) a->r[17] = p;
    p += a->n[0] * 8;
    if (a->n[2]) a->r[18] = p;
    p += a->n[2] * 8;
    if (a->n[3]) a->r[20] = p;
    p += a->n[3] * 8; p = (p + 0xF) & ~0xF;
    if (a->n[1]) a->r[19] = p;
    p += a->n[1] * 0x80; p = (p + 0xF) & ~0xF;
    if (a->n[4]) a->r[21] = p;
    p += a->n[4] * 0xA0;
    if (a->n[5]) a->r[22] = p;
    p += a->n[5] * 4;
    if (a->n[6]) a->r[23] = p;
    p += a->n[6] * 8;
    if (a->n[10]) a->e = (E *)p;
    for (i = 0; i < a->n[10]; i++) {
        E *q = &a->e[i];
        q->pad[2] = *(*a->p4)[4] + q->c;
    }
}
