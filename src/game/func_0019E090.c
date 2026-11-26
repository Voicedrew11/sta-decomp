#include "m2c.h"
typedef struct { u16 v[8]; } H;
typedef struct { f32 v[4]; } F;
extern s32 D_004A32C8[];
H *func_001C9BA0(void);
s8 *func_001C9B60(void);
s32 func_001C9BF0(void);
void func_0019A500(H *, H *, s32 *, s32 *, s32 *, s32, s32, s32);
void func_00186440(f32, H *, H *, H *, H *);
void func_00185B30(s32, s32);
void func_00185510(f32, H *);
void func_00185B40(f32, s8 *);
void func_0017F5C0(void);
void func_00185390(f32, s32, s32, s32);

void func_0019E090(f32 f) {
    s32 r8C;
    s32 r88;
    s32 r84;
    H t70;
    H a60;
    H a50;
    H a40;
    H a30;
    s8 *s;
    s32 i;

    func_001C9BA0();
    s = func_001C9B60();
    t70 = *func_001C9BA0();
    if (func_001C9BF0()) {
        a40 = *(H *)(s + 0x460);
        *(F *)&a30 = *(F *)(s + 0x470);
        func_0019A500(&a60, &a50, &r8C, &r88, &r84, -1, 0, 0);
    } else {
        return;
    }
    for (i = 0; i < 8; i++) {
        a40.v[7 - i] -= a60.v[7 - i];
        a30.v[7 - i] -= a50.v[7 - i];
    }
    func_00186440(f, &a60, &a50, &a40, &a30);
    func_00185B30(0, 0);
    func_00185510(f, &t70);
    func_00185B40(f, s);
    func_0017F5C0();
    func_00185390(f, 1, 5, D_004A32C8[0]);
}
