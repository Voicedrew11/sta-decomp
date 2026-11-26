#include "common.h"
s32 DIntr(void);
s32 EIntr(void);
s32 SignalSema(s32);
s32 WaitSema(s32);
typedef struct { u8 pad[0x1C]; s32 r[8]; s32 a; s32 sema; s32 x44; } S;
#define R(a) (*(volatile u32 *)(a))

s32 func_001EAB10(S *s) {
    WaitSema(s->sema);
    s->x44 = 0;
    DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B400) = 5;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    EIntr();
    s->r[0] = R(0x1000B410);
    s->r[1] = R(0x1000B430);
    s->r[2] = R(0x1000B420);
    s->r[3] = R(0x1000B400);
    while (R(0x10002010) & 0xF0);
    DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B000) = 0;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    EIntr();
    s->r[4] = R(0x1000B010);
    s->r[5] = R(0x1000B020);
    s->r[6] = R(0x1000B000);
    s->r[7] = R(0x10002020);
    s->a = R(0x10002010);
    SignalSema(s->sema);
    return 1;
}
