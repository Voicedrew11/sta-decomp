#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 st:4; u8 b6:2; } BF;
typedef struct { u8 pad[0x28]; f32 b8; u8 pad2[0x14]; f32 d0; f32 d4; BF bf; u8 pad3[3]; } E;
extern E D_00486990[];

s32 func_0017F470(s32 arg0, s32 arg1, f32 val) {
    s32 i = arg0 % 24;
    BF *p = &D_00486990[i].bf;
    if (p->st == 0) {
        D_00486990[i].d0 = val;
        D_00486990[i].d4 = 0.25f * (val - D_00486990[i].b8);
        p->b1 |= arg1 & 1;
        return 1;
    } else if (p->st == 3) {
        D_00486990[i].d0 = val;
        D_00486990[i].d4 = 0.25f * (val - D_00486990[i].b8);
        p->b1 |= arg1 & 1;
        return 0;
    }
    return 0;
}
