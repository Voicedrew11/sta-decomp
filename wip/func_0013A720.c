#include "actor.h"
typedef struct { Vec s; Vec e; } Seg __attribute__((aligned(16)));
typedef struct { Vec p; u8 pad[0x14]; s32 hit; u8 pad2[0x18]; } Hit __attribute__((aligned(16)));
typedef struct { u8 pad[0xB4]; u8 xB4; u8 xB5; } Q;
typedef struct { u8 pad[0xF4]; f32 xF4; u8 pad2[0x140 - 0xF8]; } N;
typedef struct { u128 q[2]; } SegQ;
typedef struct { u128 q[4]; } HitQ;
typedef struct {
    u8 pad0[0x10];
    f32 *x10;
    u8 pad14[4];
    Q *x18;
    u8 pad1C[0x10];
    s8 *x2C;
    u8 pad30[0x10];
    Vec x40;
    u8 pad50[0x60];
    Seg xB0;
    Hit xD0;
} P;
s32 func_0013E8E0(Actor *);
void func_00102A60(Vec *, Vec *);
void func_00102A70(Mtx *, void *);
void func_00123C40(void *, s32, s32);
void func_0013D430(s32, Hit *, Seg *, s32, u8);
void func_001029E8(Vec *, void *, void *);
void func_001029D0(Vec *, Vec *, void *);
void func_0013E760(Actor *, s32);
f32 func_0013E3C0(Actor *);
s8 func_0013E290(Actor *);
s32 func_00169BB0(s32);
s32 func_00169B50(s32, s32, s32, s32);
void func_001677C0(s32, Mtx *);
void func_00167600(s32, Actor *);
void func_00137730(Actor *, Vec *);
extern s32 D_00201E80;
extern s16 D_001F1C10[];
extern Mtx D_001F2170;

void func_0013A720(Actor *a) {
    P *p;
    s32 fl;
    s32 h;
    s32 *q;
    s32 r;
    Vec tmp;
    Seg seg;
    Hit hit;
    Vec v;
    Mtx m;

    fl = 1;
    p = (P *)(a->unk518 + 0x180);
    if (!((Flags8 *)(a->unk4B0 + 0x2AC))->f.b4) return;
    if (!func_0013E8E0(a)) fl |= 2;
    func_00102A60(&p->xB0.s, &p->x40);
    p->xB0.s.w = 1.0f;
    func_00102A60(&p->xB0.e, &p->x40);
    p->xB0.e.w = 1.0f;
    p->xB0.s.y = p->x10[5];
    if (!(p->xB0.s.y <= p->xB0.e.y)) {
        func_00102A60(&tmp, &p->xB0.s);
        func_00102A60(&p->xB0.s, &p->xB0.e);
        func_00102A60(&p->xB0.e, &tmp);
    }
    {
        f32 d = *(f32 *)(&(p->x2C + 0x234)[p->x18->xB5 * 0x140 + (0x234 - 0x234)]) - *(f32 *)(&(p->x2C + 0x234)[p->x18->xB4 * 0x140 + (0x234 - 0x234)]);
        if (d < -80.0f) {
            p->xB0.s.y += d;
        } else {
            p->xB0.s.y += -80.0f;
        }
    }
    p->xB0.e.y += 1000.0f;
    func_00123C40(&p->xD0, 0, 0x40);
    if (((s32 **)&D_00201E80)[2] != NULL) {
        func_0013D430(*((s32 **)&D_00201E80)[2], &p->xD0, &p->xB0, 4, fl);
    }
    q = ((s32 **)&D_00201E80)[3];
    if (q != NULL) {
        if (p->xD0.hit == 0) {
            func_0013D430(*q, &p->xD0, &p->xB0, 4, fl);
        } else if (!(p->xD0.p.y < p->xB0.e.y - 1000.0f)) {
            *(SegQ *)&seg = *(SegQ *)&p->xB0;
            *(HitQ *)&hit = *(HitQ *)&p->xD0;
            hit.hit = 0;
            func_0013D430(*q, &hit, &seg, 4, fl);
            if (hit.hit != 0 && hit.p.y < p->xD0.p.y) {
                *(SegQ *)&p->xB0 = *(SegQ *)&seg;
                *(HitQ *)&p->xD0 = *(HitQ *)&hit;
            }
        }
    }
    if (p->xD0.hit != 0) {
        if (p->xD0.p.y < p->xB0.e.y - 1000.0f) {
            func_001029E8(&v, &p->xD0, &p->x40);
            v.x = 0.0f;
            v.z = 0.0f;
            v.w = 0.0f;
            func_001029D0(&p->x40, &p->x40, &v);
            func_0013E760(a, 1);
            if (!(func_0013E3C0(a) <= 100.0f)) {
                r = func_0013E290(a);
                if (r >= 0) {
                    h = D_001F1C10[r];
                    if (h >= 0 && func_00169BB0(h)) {
                        h = func_00169B50(h, 0, 0, 0);
                        if (h != 0) {
                            func_00102A70(&m, &D_001F2170);
                            func_00102A60(&m.m[3], &p->x40);
                            func_001677C0(h, &m);
                            func_00167600(h, a);
                        }
                    }
                }
            }
            func_00137730(a, &v);
        } else {
            func_0013E760(a, 0);
        }
    } else {
        func_0013E760(a, 0);
    }
}
