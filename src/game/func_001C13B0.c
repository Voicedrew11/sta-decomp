#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 pad[0xC]; u8 t:4; u8 r:4; u8 padD[3]; f32 x, y, z; } Tri;
typedef struct { Vec p; u8 pad10[0x14]; s32 x24; u8 pad28[4]; Tri *x2C; u8 pad30[0x10]; } Hit;
typedef struct { u8 pad[0x18]; Vec *o; u8 pad1C[0x39E - 0x1C]; u16 a:6; u16 b:6; u16 c:1; u16 d:3; f32 f3A0; f32 f3A4; } P;
extern s32 D_00201E80;
extern MtxF D_001F2170;
extern Vec D_004B4D00;
extern Vec D_004B4CF0;
void func_00102C20(MtxF *, MtxF *, f32);
void func_00102CC8(MtxF *, MtxF *, f32);
void func_00102A60(Vec *, Vec *);
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
void func_001029E8(Vec *, Vec *, Vec *);
void func_00123C40(void *, s32, s32);
s32 func_001B3240(s8 *, Hit *, Vec *, s32, s32);
void func_00102870(Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
f32 sqrtf(f32);
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

s32 func_001C13B0(void) {
    s8 ***q;
    P *p;
    s32 i;
    Tri *t;
    Hit hit;
    Vec V[2];
    MtxF m;
    Vec d;

    p = cur();
    func_00102C20(&m, &D_001F2170, WRAP(p->f3A4 + WRAP(p->o[3].x)));
    func_00102CC8(&m, &m, WRAP(WRAP(3.1415927f + p->o[3].y)));
    func_00102A60(&V[1], (Vec *)m.m[2]);
    func_00102A18(&V[1], &V[1], 650.0f);
    func_001029D0(&V[1], &V[1], p->o);
    func_00102A60(&V[0], p->o);
    func_00123C40(&hit, 0, 0x40);
    for (i = 0, q = (s8 ***)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0) {
            func_001B3240(**q, &hit, &V[0], 2, 0);
        }
    }
    if (hit.x24 == 0) return 0;
    if (hit.x2C->t == 12 || hit.x2C->t == 13) {
        V[1].x = hit.x2C->x;
        V[1].y = hit.x2C->y;
        V[1].z = hit.x2C->z;
        V[1].w = 1.0f;
        func_00102A60(&V[0], &p->o[8]);
        V[0].y = 0.0f;
        func_00102870(&V[0], &V[0]);
        if (func_00102848(&V[1], &V[0]) > 0.8f) {
            if (hit.p.y < p->o->y + 234.99998f) {
                func_001029E8(&d, &hit.p, p->o);
                if (!(sqrtf(func_00102848(&d, &d)) <= 200.0f)) return 0;
                hit.p.y = p->o->y - 20.0f;
            }
            p->b = 1;
            p->c = 0;
            p->d = 0;
            func_00102A60(&D_004B4D00, &V[1]);
            func_00102A60(&D_004B4CF0, &hit.p);
            return 1;
        }
    }
    return 0;
}
