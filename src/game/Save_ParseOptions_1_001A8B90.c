#include "m2c.h"
typedef struct { u32 tag; u32 x4; u32 x8; u32 xC; u32 x10; u32 x14; u32 x18; u32 x1C; } Rec;
typedef struct { u8 x0[0x20]; u8 x20[0x30]; u8 x50[0x10]; } Big;
extern s8 D_001FD988[];
extern Big *D_00201E00;
void memcpy(void *, void *, s32);

void Save_ParseOptions_1_001A8B90(Rec *p) {
    s32 *d;
    u8 *s;
    s8 *c1 = &D_001FD988[1];
    s8 *c2 = &D_001FD988[2];
    s8 *c3 = &D_001FD988[3];

    while (1) {
        d = (s32 *)((u8 *)p + 0x10);
        s = (u8 *)d + 0x10; s += (p->x1C + 15) & ~15;
        if (p->tag == (D_001FD988[0] | (*c1 << 8) | (*c2 << 16) | (*c3 << 24))) return;
        switch (p->tag) {
        case 0x6154504F:
            memcpy(D_00201E00->x20, s, *d);
            break;
        case 0x61535953:
            memcpy(D_00201E00->x50, s, *d);
            break;
        }
        p = (Rec *)((u8 *)p + p->x4);
    }
}
