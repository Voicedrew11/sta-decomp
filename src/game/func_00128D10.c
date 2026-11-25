#include "m2c.h"
typedef struct { s32 a; s32 b; f32 c; } V3 __attribute__((aligned(8)));
typedef struct { u8 pad[6]; s16 h6; u8 pad2[2]; s32 w0C; } Z;
s32 func_0015ABD0(s32);
s32 func_0015A300(s32);
s32 func_0015A350(s32);
void func_0015AB80(s32);
void func_0015A080(s32, s8 *, s32);
void func_00102870(s8 *, s8 *);
void func_00123C40(void *, s32, s32);
void func_00125CE8(s8 *, s8 *);
void func_00123A88(s8 *, s8 *, s32);
void func_001E85E0(s32, s32, void *, s8 *, s32);
extern s8 D_00209700[];
extern V3 D_001F1BA0;
extern s8 D_001F1B30[];
extern s8 D_001F1AF0[];
extern s8 D_001F1B60[];
extern s8 D_001F1B90[];
extern s8 D_001FAAF8[];
extern s8 D_001FAB00[];

void func_00128D10(void) {
    V3 v;
    u8 buf[0x3C4];
    s32 a; s32 h; s32 b;
    h = func_0015ABD0(0x943CDF5F);
    a = func_0015A300(h);
    b = func_0015A350(h);
    func_0015AB80(h);
    func_0015A080(0x943CDF5F, D_00209700, a);
    v = D_001F1BA0;
    func_00102870(D_001F1B30, D_001F1B30);
    func_00123C40(buf, 0, 0x3C4);
    func_00125CE8(buf, D_001FAAF8);
    func_00125CE8(buf + 0xC0, D_001FAB00);
    *(s16 *)(buf + 6) = 0xE;
    *(s32 *)(buf + 0xC) = 0x60;
    func_00123A88(buf + 0x10, D_001F1AF0, 0x40);
    func_00123A88(buf + 0x50, D_001F1B30, 0x30);
    func_00123A88(buf + 0x80, D_001F1B60, 0x30);
    func_00123A88(buf + 0xB0, D_001F1B90, 0x10);
    func_00125CE8(buf + 0x104, (s8 *)v.a);
    func_00125CE8(buf + 0x144, (s8 *)v.b);
    func_00125CE8(buf + 0x184, (s8 *)*(s32 *)&v.c);
    func_001E85E0(0, 0, buf, D_00209700, b);
}
