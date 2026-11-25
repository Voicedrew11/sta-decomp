#include "actor.h"
typedef union { u32 w; struct { u16 id; u8 f2; u8 f3; } s; } K;
typedef struct { u8 pad[0x20]; Vec a; Vec b; } M;
typedef struct { u8 m[0x40]; } MtxB;
typedef struct {
    u8 pad0[0x50];
    Vec x50;
    u8 pad60[0x30];
    M *x90;
    u8 pad94[0x14];
    K xA8;
    u8 padAC[4];
    Vec xB0;
} O;
extern f32 D_001FB738[];
extern Actor *D_002022E4;
u16 func_0013E110(s8 *);
s8 *func_00146EF0(f32, Vec *, f32, Vec *, f32, s32);
Vec *func_0013FFA0(s8 *);
void func_00102A60(Vec *, Vec *);
void func_001029E8(Vec *, Vec *, void *);
void func_00146600(Actor *, MtxB *);
void func_001027B0(Vec *, MtxB *, Vec *);
float sqrtf(float);

void func_0014D700(O *o) {
    K k;
    K k2;
    Vec b0;
    Vec a0;
    Vec v90;
    Vec v80;
    MtxB m;
    s8 *p;
    u16 id;
    f32 t;

    k.s.id = 0;
    k.s.f3 = 0;
    k.s.f2 = 1;
    o->xA8.w = k.w;
    func_00102A60(&b0, &o->x90->b);
    b0.w = 1.0f;
    func_00102A60(&a0, &o->x90->a);
    p = func_00146EF0(D_001FB738[0], &b0, 1.5707964f, &a0, 1.5707964f, 1);
    if (p != NULL) {
        func_00102A60(&v80, func_0013FFA0(p));
        func_001029E8(&v90, &v80, o);
        t = (0.05f - sqrtf(v90.x * v90.x + v90.z * v90.z)) / 0.1f;
        t *= 0.001f;
        id = func_0013E110(p);
    } else {
        o->x50.w = 1.0f;
        func_00146600(D_002022E4, &m);
        func_001027B0(&o->xB0, &m, &o->x50);
        t = 0.0f;
        id = 0;
    }
    k2.w = o->xA8.w;
    k2.s.id = id;
    k2.s.f2 = id == 0 && k2.s.f2 == 1;
    k2.s.f3 = 0;
    o->xA8.w = k2.w;
    o->xB0.w = t;
}
