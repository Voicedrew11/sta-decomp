#include "m2c.h"
typedef struct { u32 tag; u32 x4; u32 a:8; u32 b:24; u16 xC; u16 xE; u32 x10; u32 x14; u32 x18; u32 x1C; } Rec;
typedef struct { Rec r0; u8 x20[0x10]; Rec r1; u8 pad[0x80]; Rec r2; } Big;
extern s8 D_001FD990[];
extern s8 D_001FD998[];
extern s8 D_001FD988[];
void memset(void *, s32, s32);
#define FCC(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline void init(Rec *p, s8 *s, u32 x4, u32 x10, u32 x14) {
    p->tag = FCC(s);
    p->x4 = x4;
    p->a = 0x43;
    p->b = 0;
    p->xC = 1;
    p->xE = 0;
    p->x10 = x10;
    p->x14 = x14;
    p->x18 = 0;
    p->x1C = 0;
}

void Save_BuildOptions_1_001AB0A0(Big *b) {
    memset(b, 0, 0xF0);
    b->x20[0] = 0x20;
    b->x20[1] = 1;
    b->x20[2] = 0;
    b->x20[3] = 1;
    b->x20[4] = 0x40;
    b->x20[5] = 0x40;
    b->x20[6] = 0x40;
    b->x20[7] = 0;
    b->x20[8] = 1;
    b->x20[9] = 1;
    init(&b->r0, D_001FD990, 0x30, 0x20, 0x10);
    init(&b->r1, D_001FD998, 0xA0, 0x90, 0x80);
    init(&b->r2, D_001FD988, 0x20, 0x10, 0);
}
