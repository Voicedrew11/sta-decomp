#include "common.h"
typedef struct { Vec p; f32 x10; f32 x14; f32 x18; u8 x1C; u8 x1D; u8 x1E; u8 x1F; u16 x20; u8 x22; u8 p23[0xD]; } E;
typedef struct { u8 p[0x10]; Vec x10; u8 p20[0x5E]; u16 n; u8 p80[0xEC]; E *e; } O;
void func_00102A60(Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_0015C6D0(s32);
void func_0015C730(s32, Vec *, f32, f32, f32, f32, u8, u8, u8, u8, u16, u8);

void func_001B7190(O *o, s32 a) {
    Vec base;
    Vec v;
    s32 i;
    s32 off;
    E *e;
    func_00102A60(&base, &o->x10);
    func_0015C6D0(a);
    i = 0;
    if (i < o->n) {
        off = 0;
        do {
        e = (E *)((u8 *)o->e + off);
        func_00102A60(&v, &e->p);
        func_001029D0(&v, &v, &base);
        v.w = e->p.w;
        func_0015C730(a, &v, v.w, e->x18, e->x10, e->x14, e->x1C, e->x1D, e->x1E, e->x1F, e->x20, e->x22);
        i++;
        off += 0x30;
        } while (i < o->n);
    }
}
