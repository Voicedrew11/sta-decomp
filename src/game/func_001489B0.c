#include "m2c.h"
typedef struct { u8 p : 5; u8 v : 1; } BF;
extern f32 D_001F2160[];
s8 *func_001A5460(s32 *);
u32 func_0013E110(s8 *);
void func_001029D0(f32 *, f32 *, f32 *);
void func_001029E8(f32 *, f32 *, f32 *);
void func_00102A60(f32 *, f32 *);
void func_00163C80(s8 *, f32 *);
void func_00146020(s8 *, f32, f32, f32);

void func_001489B0(s8 *a0) {
    f32 c[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    s32 it;
    u16 id;
    s8 *p;

    it = 0;
    id = (u32)*(f32 *)(a0 + 0x60);
    do {
        p = func_001A5460(&it);
    } while (p != NULL && *(u16 *)p != id);
    if (p != NULL) {
        *(f32 *)(a0 + 0xB8) = func_0013E110(p);
    } else {
        *(f32 *)(a0 + 0xB8) = 0.0f;
    }
    func_001029D0(a, p != NULL ? (f32 *)(*(s32 *)(p + 0x518) + 0x90) : D_001F2160, (f32 *)(a0 + 0x50));
    if (((BF *)(a0 + 0x114))->v) {
        func_00163C80(a0, m);
        func_00102A60(b, m + 12);
    } else {
        func_00102A60(b, (f32 *)a0);
    }
    func_001029E8(c, a, b);
    func_00146020(a0 + 0xC0, c[0], c[1], c[2]);
}
