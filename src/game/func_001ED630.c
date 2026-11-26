#include "common.h"
typedef union { u32 w; u8 b[4]; } Buf;
typedef struct {
    u8 pad0[0x14];
    f32 x14;
    f32 x18;
    u8 pad1C[0x10];
    f32 x2C;
    f32 x30;
    u8 pad34[0x8];
    union { u32 w; u8 b[4]; } c;
} S;
extern S D_004BE0E0;
extern s32 D_001F27B0[];
extern s32 D_001F27C0[];
extern f32 D_00202404;
void func_00182080(f32, s32, void *, void *, void *, s32);
void func_00181420(void);
void func_00183650(void *);

void func_001ED630(void) {
    Buf s;
    s.w = 0;
    s.b[3] = (s32)D_00202404 / 2.0f;
    func_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
    func_00181420();
    D_004BE0E0.x2C = 150.0f;
    D_004BE0E0.x30 = 50.0f;
    D_004BE0E0.x14 = 1.34f;
    D_004BE0E0.x18 = 1.3f;
    D_004BE0E0.c.w = 0x80FFFFFF;
    D_004BE0E0.c.b[3] = (s32)D_00202404;
    func_00183650(&D_004BE0E0);
}
