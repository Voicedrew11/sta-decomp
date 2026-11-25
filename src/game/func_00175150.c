#include "m2c.h"
typedef struct { u8 b[0x30]; } E30;
typedef struct { u8 b[0x2C]; } E2C;
typedef struct {
    u8 pad0[4];
    u32 n;
    u8 pad8[8];
    u16 w;
    u16 h;
    u8 pad14[0x14];
    u16 *tex;
    u8 pad2c[4];
    E30 a[8];
    E2C b[8];
} T;
extern void func_001545D0(void);
extern void func_001543E0(s32, u64);
extern void func_001544C0(void);
extern void func_00174980(T *, u32, E30 *, E2C *);

void func_00175150(T *a0) {
    u32 w = a0->w;
    u32 h = a0->h;
    u64 v = (s64)(s32)((u32)(*a0->tex & 0x3FFF) >> 5) | ((s64)(s32)((u32)w >> 6) << 16);
    u32 i;
    func_001545D0();
    func_001543E0(0x4C, v);
    func_001543E0(0x40, ((s64)(s32)((u16)w - 1) << 16) | ((s64)(s32)((u16)h - 1) << 48));
    func_001543E0(0x18, (s32)((0x800 - (w >> 1)) << 4) | ((s64)(s32)((0x800 - ((u32)(u16)h >> 1)) << 4) << 32));
    func_001543E0(8, 0);
    func_001543E0(0x47, 0x31001);
    func_001544C0();
    for (i = 0; i < a0->n; i++) {
        func_00174980(a0, i, &a0->a[i], &a0->b[i]);
    }
}
