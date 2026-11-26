#include "actor.h"
typedef struct { u8 pad0[0x24]; f32 x24; u8 pad28[0x38]; Vec v60; u8 pad70[0x10]; Vec v80; } Q;
typedef struct { u8 pad0[0x48]; s32 x48; } R;
typedef struct {
    u8 pad0[0x18];
    Q *x18;
    u8 pad1C[0x40 - 0x1C];
    Vec v40;
    Vec v50;
    u8 pad60[0x390 - 0x60];
    R *x390;
    u8 pad394[0x3A0 - 0x394];
    u16 lo:7; u16 f:6; u16 hi:3;
    u8 pad3A2[2];
    f32 x3A4;
} P;
typedef struct { f32 x0, x4, x8, xC, x10, x14, x18, x1C; } In;
extern Vec D_003139A0;
f32 sqrtf(f32);
f32 func_00102848(Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
void func_001029D0(Vec *, void *, Vec *);
void func_00102A18(Vec *, Vec *, f32);

void func_001C39D0(Actor *a, In *in, f32 dt) {
    P *p;
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    Vec t4;
    Vec t5;
    Vec t6;
    Vec t7;
    f32 m;

    p = (P *)(a->unk518 + 0x180);
    func_00102A18(&t0, &p->v50, -dt);
    func_001029D0(&p->v40, &t0, &p->v40);
    p->v50.y = p->v50.y - 3920.0f * dt;
    func_00102A18(&p->v50, &p->v50, 0.9f);
    if (sqrtf(func_00102848(&p->v50, &p->v50)) < 50.0f) {
        func_00102A60(&p->v50, &D_003139A0);
    }
    func_00102A18(&t1, &p->v50, dt);
    func_001029D0(&p->v40, &t1, &p->v40);
    if (in->x8 > 0.0f) {
        func_00102A18(&t2, &p->x18->v80, 250.0f * -in->x8);
        func_001029D0(&p->v50, &t2, &p->v50);
    }
    if (in->xC > 0.0f) {
        func_00102A18(&t3, &p->x18->v80, 100.0f * in->xC);
        func_001029D0(&p->v50, &t3, &p->v50);
    }
    if (in->x0 > 0.0f) {
        p->x18->x24 += in->x0 * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (in->x4 > 0.0f) {
        p->x18->x24 -= in->x4 * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (in->x14 > 0.0f) {
        if (in->x14 > 0.4f) {
            func_00102A18(&t4, &p->x18->v60, -1.0f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            func_001029D0(&p->v50, &t4, &p->v50);
        } else {
            func_00102A18(&t5, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            func_001029D0(&p->v50, &t5, &p->v50);
        }
    }
    if (in->x10 > 0.0f) {
        if (in->x10 > 0.4f) {
            func_00102A18(&t6, &p->x18->v60, 100.0f * (p->x390->x48 ? 0.5f : 1.0f));
            func_001029D0(&p->v50, &t6, &p->v50);
        } else {
            func_00102A18(&t7, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            func_001029D0(&p->v50, &t7, &p->v50);
        }
    }
    p->x3A4 *= 0.5f;
    if (in->x1C > 0.0f && in->x18 > 0.0f) {
        m = in->x18 < in->x1C ? in->x18 : in->x1C;
        p->v50.y += 200.0f * m;
    }
    if (in->x14 > 0.0f && in->x10 > 0.0f) {
        m = in->x10 < in->x14 ? in->x10 : in->x14;
        p->v50.y += -200.0f * m;
    }
    p->f = 0;
}
