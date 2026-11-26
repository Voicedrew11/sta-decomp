#include "common.h"
typedef struct {
    Vec v;
    f32 x10, x14, x18;
    u8 x1C, x1D, x1E, x1F;
    u16 x20;
    u8 x22, x23;
    u8 pad[0xC];
} __attribute__((aligned(16))) S30;
typedef struct {
    u8 pad[0x20];
    S30 a;
    S30 b;
    S30 c;
    u8 pad2[0xCC0 - 0xB0];
} Big;
extern Big D_0030C420;
extern Vec D_003139A0;
void func_00123C40(void *, s32, s32);
void func_00102A60(void *, void *);

void func_0015C8D0(void) {
    func_00123C40(&D_0030C420, 0, 0xCC0);
    func_00102A60(&D_0030C420.c.v, &D_003139A0);
    D_0030C420.c.x18 = 100.0f;
    D_0030C420.c.v.w = 40000.0f;
    D_0030C420.c.x10 = 1.0f;
    D_0030C420.c.x14 = 0.1f;
    D_0030C420.c.x23 = 1;
    D_0030C420.c.x1C = 0x18;
    D_0030C420.c.x20 = 0x40;
    D_0030C420.c.x22 = 0x78;
    D_0030C420.c.x1D = 8;
    D_0030C420.c.x1E = 8;
    D_0030C420.c.x1F = 8;
    D_0030C420.a = D_0030C420.c;
    D_0030C420.b = D_0030C420.c;
}
