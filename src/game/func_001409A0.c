#include "m2c.h"
s32 func_00166F80(void *, s32, void *);
void func_00165070(void *, u8, s32, u32);
void func_00164FF0(void *, u8, s32, f32);
s8 func_00166C10(void *, s32);
u8 func_00164FC0(void *, u8, s32);
f32 func_00164F60(void *, u8, s32);
f32 *func_00140460(void *);
f32 *func_00140430(void *);
f32 *func_00140340(void *);
f32 *func_00140320(void *);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
static inline u16 mk(u16 lo, u16 hi) { return (u8)lo | ((u8)hi << 8); }
#define H(a) (*(a)->p)

u16 func_001409A0(Obj *a0, s32 a1, f32 *px, f32 *py, f32 *pz) {
    s32 h4;
    s32 h5;
    u16 r;
    h5 = func_00166F80(H(a0), 0x2024, a0);
    h4 = func_00166F80(H(a0), 0x2020, a0);
    func_00165070(H(a0), h4, 0, 0);
    while (func_00166C10(H(a0), h4) != 0) {}
    if ((u8)func_00164FC0(H(a0), h4, 0) != 0) {
        func_00165070(H(a0), h5, 0, 1);
        func_00165070(H(a0), h5, 1, 1);
        func_00165070(H(a0), h5, 2, a1);
        func_00164FF0(H(a0), h5, 3, func_00140460(a0)[0]);
        func_00164FF0(H(a0), h5, 4, func_00140460(a0)[2]);
        func_00164FF0(H(a0), h5, 5, func_00140430(a0)[1]);
    } else {
        func_00165070(H(a0), h5, 0, 8);
        func_00165070(H(a0), h5, 1, 6);
        func_00165070(H(a0), h5, 2, a1);
        func_00164FF0(H(a0), h5, 3, func_00140340(a0)[0]);
        func_00164FF0(H(a0), h5, 4, func_00140340(a0)[2]);
        func_00164FF0(H(a0), h5, 5, func_00140320(a0)[1]);
    }
    while (func_00166C10(H(a0), h5) != 0) {}
    h4 = func_00164FC0(H(a0), h5, 0);
    r = mk(h4, func_00164FC0(H(a0), h5, 1));
    if (px) *px = func_00164F60(H(a0), h5, 3);
    if (py) *py = func_00164F60(H(a0), h5, 4);
    if (pz) *pz = func_00164F60(H(a0), h5, 5);
    return r;
}
