#include "common.h"
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } B8;
typedef struct {
    s32 x0, x4, x8, xC;
    s32 x10, x14, x18, x1C;
    u8 pad20[0x24];
    u32 col;
    u8 pad48[4];
    B8 f;
    u8 pad4D[3];
} S;
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_001544C0(void);
void func_00123C40(void *, s32, s32);
void func_00155BD0(S *);

void func_00158EE0(f32 *c) {
    S s;

    func_001545D0();
    func_001543E0(0x47, 0x31001);
    func_001543E0(0x42, 0x44);
    func_001543E0(0x40, 0x2800000 | ((u64)0x1C00000 << 32));
    func_001544C0();
    func_00123C40(&s, 0, 0x50);
    s.f.b0 = 1;
    s.f.b1 = 0;
    s.f.b2 = 1;
    s.x0 = 0x6C00;
    s.x4 = 0x7200;
    s.x8 = -1;
    s.x10 = 0x9400;
    s.x14 = 0x8E00;
    s.x18 = -1;
    s.col = ((u32)(255.0f * c[3] / 255.0f) << 24) | ((u32)(255.0f * c[2] / 255.0f) << 16) | ((u32)(255.0f * c[1] / 255.0f) << 8) | (u32)(255.0f * c[0] / 255.0f);
    func_00155BD0(&s);
}
