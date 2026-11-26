#include "common.h"
typedef struct { s8 pad[6]; u16 n; s8 pad2[0x38]; s8 data[1]; } O;
typedef struct { u8 pad[0xB0]; O **pp; } S;
typedef struct { u8 pad[0x2A]; u8 k; } K;
typedef struct { u8 pad[0x4B4]; K *x4B4[25]; S *x518; } A;
extern s32 D_00201F2C;
s8 *func_0013F030(A *a, u8 i) {
    O *o = *a->x518->pp;
    u8 *cur = (u8 *)((s32)o->data + D_00201F2C * (o->n * 0x140 + 0x200));
    u8 *oth = (u8 *)((s32)o->data + !D_00201F2C * (o->n * 0x140 + 0x200));
    return (s8 *)(oth + (a->x4B4[i]->k * 0x140 + cur)[0x331] * 0x140 + 0xF0);
}
