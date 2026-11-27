#include "m2c.h"
typedef struct { u32 tag; u32 x4; u32 a:8; u32 b:24; u16 xC; u16 xE; u32 x10; u32 x14; u32 x18; u32 x1C; } Rec;
typedef struct { u8 pad0[0x60]; s16 x60[16]; u8 pad80[0x1C0 - 0x80]; } Grp;
typedef struct {
    Rec r0;
    u8 pad20[0xF];
    u8 x2F;
    u8 pad30[0x10C0 - 0x30];
    Rec r1;
    Grp g[0x2A];
    u8 pad5A60[0x5AA0 - 0x5A60];
    Rec r2;
    u8 pad5AC0[0x5B40 - 0x5AC0];
    Rec r3;
    u8 pad5B60[0x5BE0 - 0x5B60];
    Rec r4;
    u8 pad5C00[0x7C00 - 0x5C00];
    Rec r5;
} Big;
extern s8 D_001FD9A0[];
extern s8 D_001FD9A8[];
extern s8 D_001FD9B0[];
extern s8 D_001FD9B8[];
extern s8 D_001FD9C0[];
extern s8 D_001FD988[];
void memset(void *, s32, s32);
void Inventory_AddItem_1_001A95A0(s16, u8);
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

void Save_BuildGame_1_001AAAE0(Big *b) {
    s32 i;
    s32 j;

    memset(b, 0, 0x7C20);
    for (i = 0; i < 0x2A; i++) {
        for (j = 0; j < 16; j++) {
            b->g[i].x60[j] = -1;
        }
    }
    b->x2F = 0xFF;
    Inventory_AddItem_1_001A95A0(0x3, 1);
    Inventory_AddItem_1_001A95A0(0x4, 7);
    Inventory_AddItem_1_001A95A0(0x5, 5);
    Inventory_AddItem_1_001A95A0(0x6, 5);
    Inventory_AddItem_1_001A95A0(0x14, 2);
    Inventory_AddItem_1_001A95A0(0x3F, 2);
    Inventory_AddItem_1_001A95A0(0x40, 3);
    Inventory_AddItem_1_001A95A0(0x41, 3);
    Inventory_AddItem_1_001A95A0(0x65, 1);
    Inventory_AddItem_1_001A95A0(0x6B, 1);
    Inventory_AddItem_1_001A95A0(0x6E, 1);
    Inventory_AddItem_1_001A95A0(0x71, 1);
    Inventory_AddItem_1_001A95A0(0x82, 1);
    Inventory_AddItem_1_001A95A0(0x90, 1);
    Inventory_AddItem_1_001A95A0(0xC8, 1);
    Inventory_AddItem_1_001A95A0(0xD2, 1);
    Inventory_AddItem_1_001A95A0(0xEB, 1);
    Inventory_AddItem_1_001A95A0(0xEE, 1);
    Inventory_AddItem_1_001A95A0(0xF0, 1);
    Inventory_AddItem_1_001A95A0(0x107, 1);
    Inventory_AddItem_1_001A95A0(0x12C, 1);
    Inventory_AddItem_1_001A95A0(0x130, 1);
    Inventory_AddItem_1_001A95A0(0x136, 1);
    Inventory_AddItem_1_001A95A0(0x13F, 1);
    Inventory_AddItem_1_001A95A0(0x155, 1);
    Inventory_AddItem_1_001A95A0(0x158, 1);
    Inventory_AddItem_1_001A95A0(0x190, 1);
    Inventory_AddItem_1_001A95A0(0x1A2, 1);
    Inventory_AddItem_1_001A95A0(0x1B9, 1);
    Inventory_AddItem_1_001A95A0(0x320, 1);
    Inventory_AddItem_1_001A95A0(0x324, 1);
    Inventory_AddItem_1_001A95A0(0x325, 1);
    Inventory_AddItem_1_001A95A0(0x328, 1);
    Inventory_AddItem_1_001A95A0(0x33A, 1);
    Inventory_AddItem_1_001A95A0(0x35F, 1);
    Inventory_AddItem_1_001A95A0(0x3DA, 1);
    Inventory_AddItem_1_001A95A0(0x3E0, 1);
    Inventory_AddItem_1_001A95A0(0x3E2, 1);
    Inventory_AddItem_1_001A95A0(0x3E5, 1);
    Inventory_AddItem_1_001A95A0(0x38E, 1);
    Inventory_AddItem_1_001A95A0(0x36C, 1);
    Inventory_AddItem_1_001A95A0(0x36F, 1);
    Inventory_AddItem_1_001A95A0(0x375, 1);
    Inventory_AddItem_1_001A95A0(0x380, 1);
    Inventory_AddItem_1_001A95A0(0x3B7, 1);
    Inventory_AddItem_1_001A95A0(0x3C7, 1);
    Inventory_AddItem_1_001A95A0(0x3C9, 1);
    init(&b->r0, D_001FD9A0, 0x10C0, 0x10B0, 0x10A0);
    init(&b->r1, D_001FD9A8, 0x49E0, 0x49D0, 0x49C0);
    init(&b->r2, D_001FD9B0, 0xA0, 0x90, 0x80);
    init(&b->r3, D_001FD9B8, 0xA0, 0x90, 0x80);
    init(&b->r4, D_001FD9C0, 0x2020, 0x2010, 0x2000);
    init(&b->r5, D_001FD988, 0x20, 0x10, 0);
}
