#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define DEG(d) (3.1415927f * (d) / 180.0f)
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[7];
    u16 h10;
    u8 pad12[6];
    f32 x18; f32 pad1c;
    f32 x20; f32 pad24;
    f32 x28; f32 pad2c;
    f32 x30; f32 pad34;
    f32 x38; f32 pad3c;
    f32 x40;
} O;
extern Mtx D_001F2170;
void func_00102A70(Mtx *, Mtx *);
void func_00102B78(f32, Mtx *, Mtx *);
void func_00102C20(f32, Mtx *, Mtx *);
void func_00102CC8(f32, Mtx *, Mtx *);
void func_001B0EB0(u8, u16, Mtx *);
void func_001B11F0(u8, u16, s32);

void func_0017E390(O *o) {
    Mtx m;

    func_00102A70(&m, &D_001F2170);
    func_00102B78(WRAP(DEG(o->x30)), &m, &m);
    func_00102C20(WRAP(DEG(o->x38)), &m, &m);
    func_00102CC8(WRAP(DEG(o->x40)), &m, &m);
    m.m[3].x = o->x18;
    m.m[3].y = o->x20;
    m.m[3].z = o->x28;
    func_001B0EB0(o->b8, o->h10, &m);
    func_001B11F0(o->b8, o->h10, 1);
}
