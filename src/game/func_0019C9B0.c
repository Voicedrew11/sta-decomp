#include "m2c.h"
typedef struct { s32 idx; s32 x4; s32 x8[9]; f32 f2C; s32 x30[4]; } A;
typedef struct { s32 idx; s32 x4; s32 x8; f32 fC; s32 x10[12]; } B;
typedef struct { u32 n; A *e; } LA;
typedef struct { u32 n; B *e; } LB;
extern s8 D_004A32A0[];
s8 *func_00189050(s32);
s32 func_00189020(s32);
void func_00187B20(s32);
void func_001829B0(void *, s32, void (*)(), s32);
void func_0019CB90(s8 *, s32, u32);
void func_00186990();
s32 func_001C9BA0(void);
s32 func_001866B0(s32, s32, s32, s8 *, s32);

void func_0019C9B0(f32 f) {
    A a;
    B b;
    LB *lb;
    s32 base2;
    u32 i;
    LA *la;
    s32 t;
    s32 base;

    la = *(LA **)(func_00189050(2) + 4);
    base = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < la->n; i++) {
        a = la->e[i];
        a.f2C = f;
        func_001829B0(&a, base + la->e[i].idx * 8, (void (*)())func_0019CB90, 0);
    }
    lb = *(LB **)(func_00189050(0) + 0x2C);
    base2 = func_00189020(0);
    t = func_001C9BA0();
    func_00187B20(0);
    for (i = 0; i < lb->n; i++) {
        b = lb->e[i];
        b.fC = f;
        func_001829B0(&b, base2 + lb->e[i].idx * 8, func_00186990, func_001866B0(b.x4, t + 0x20, 0, D_004A32A0, 0));
    }
}
