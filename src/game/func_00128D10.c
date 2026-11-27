#include "m2c.h"
typedef struct { s32 a; s32 b; s32 c; } V3 __attribute__((aligned(8)));
typedef struct { u8 pad[6]; s16 h6; u8 pad2[2]; s32 w0C; } Z;
s32 func_0015ABD0(s32);
s32 func_0015A300(s32);
s32 func_0015A350(s32);
void func_0015AB80(s32);
void func_0015A080(s32, s8 *, s32);
void sceVu0Normalize(void *, void *);
void memset(void *, s32, s32);
void strcpy(s8 *, s8 *);
void memcpy(void *, void *, s32);
void func_001E85E0(s32, s32, void *, s8 *, s32);
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s8 D_00209700[0x470];
extern s8 D_001FAAE8[];

s32 D_001F1AF0[0x10] = { 0, 0, 0, 0, 8, 0x40, 0x20, 0 };
f32 D_001F1B30[0xC] = { 0.5f, 0.0f, 0.2f };
f32 D_001F1B60[0xC] = { 0.2509804f, 0.5019608f, 0.39215687f };
f32 D_001F1B90[4] = { 0.0627451f, 0.0627451f, 0.0627451f, 0.0f };
V3 D_001F1BA0 = { (s32)D_001FAAE8, (s32)D_001FAAE8, (s32)D_001FAAE8 };
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
    sceVu0Normalize(D_001F1B30, D_001F1B30);
    memset(buf, 0, 0x3C4);
    strcpy(buf, D_001FAAF8);
    strcpy(buf + 0xC0, D_001FAB00);
    *(s16 *)(buf + 6) = 0xE;
    *(s32 *)(buf + 0xC) = 0x60;
    memcpy(buf + 0x10, D_001F1AF0, 0x40);
    memcpy(buf + 0x50, D_001F1B30, 0x30);
    memcpy(buf + 0x80, D_001F1B60, 0x30);
    memcpy(buf + 0xB0, D_001F1B90, 0x10);
    strcpy(buf + 0x104, (s8 *)v.a);
    strcpy(buf + 0x144, (s8 *)v.b);
    strcpy(buf + 0x184, (s8 *)v.c);
    func_001E85E0(0, 0, buf, D_00209700, b);
}
