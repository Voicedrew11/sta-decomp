#include "m2c.h"
typedef struct { u32 tag; u32 x4; u32 a:8; u32 b:24; u16 xC; u16 xE; u32 x10; u32 x14; u32 x18; u32 x1C; } Rec;
typedef struct {
    Rec r0;
    u8 x20[0x10C0 - 0x20];
    Rec r1;
    u8 pad1[0x5AA0 - 0x10E0];
    Rec r2;
    u8 pad2[0x5B40 - 0x5AC0];
    Rec r3;
    u8 pad3[0x5BE0 - 0x5B60];
    Rec r4;
    u8 pad4[0x7C00 - 0x5C00];
    Rec r5;
} Big;
typedef struct { u8 pad0[8]; u16 x8; u8 xA; u8 xB; u8 pad[0x98 - 0xC]; u8 x98; u8 x99; u8 x9A; u8 x9B; } Src;
extern s8 D_001FD9A0[];
extern s8 D_001FD9A8[];
extern s8 D_001FD9B0[];
extern s8 D_001FD9B8[];
extern s8 D_001FD9C0[];
extern s8 D_001FD988[];
extern Big *D_00201DC0;
Src *func_001C9BA0(void);
void func_001DF930(u8 *);
void func_00123A88(void *, void *, s32);
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

void func_001A9080(void) {
    Src *s;
    Big *b;
    s = func_001C9BA0();
    func_001DF930(&s->x98);
    s->x8 = s->x9B;
    s->xA = s->x9A;
    s->xB = s->x99;
    func_00123A88(D_00201DC0->x20, s, 0x10A0);
    b = D_00201DC0; init(&b->r0, D_001FD9A0, 0x10C0, 0x10B0, 0x10A0);
    b = D_00201DC0; init(&b->r1, D_001FD9A8, 0x49E0, 0x49D0, 0x49C0);
    b = D_00201DC0; init(&b->r2, D_001FD9B0, 0xA0, 0x90, 0x80);
    b = D_00201DC0; init(&b->r3, D_001FD9B8, 0xA0, 0x90, 0x80);
    b = D_00201DC0; init(&b->r4, D_001FD9C0, 0x2020, 0x2010, 0x2000);
    b = D_00201DC0; init(&b->r5, D_001FD988, 0x20, 0x10, 0);
}
