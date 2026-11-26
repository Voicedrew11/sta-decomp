#include "actor.h"
typedef struct { u8 pad0[0x24]; f32 x24; u8 pad28[0x38]; Vec v60; u8 pad70[0x10]; Vec v80; } Q;
typedef struct { u8 pad0[0x48]; s32 x48; } R;
typedef struct { u8 pad0[0xC]; u8 c0 : 4; u8 c4 : 4; u8 d0 : 3; u8 d3 : 5; } X;
typedef struct {
    u8 pad0[0x18];
    Q *x18;
    u8 pad1C[0x40 - 0x1C];
    Vec v40;
    Vec v50;
    u8 pad60[0x154 - 0x60];
    s32 x154;
    u8 pad158[4];
    X *x15C;
    u8 pad160[0x390 - 0x160];
    R *x390;
    u8 pad394[0x39E - 0x394];
    u16 lo : 6; u16 cnt : 6; u16 b12 : 1; u16 hi3 : 3;
    u16 lo7 : 7; u16 f : 6; u16 hi : 3;
    u8 pad3A2[2];
    f32 x3A4;
} P;
typedef struct { f32 x0, x4, x8, xC, x10, x14, x18, x1C; } In;
extern Vec D_004B4D00;
extern Vec D_001F2140;
extern f32 D_002022E8;
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void func_00102870(Vec *, Vec *);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);
f32 fabsf(f32);
s32 func_001CA4A0(u32, s32);

void func_001C3EF0(Actor *a, In *in, f32 dt) {
    Vec c;
    Vec n;
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    Vec t4;
    Vec t5;
    Vec t6;
    Vec t7;
    Vec t8;
    Vec t9;
    Vec t10;
    Vec t11;
    P *p;
    s32 k;

    p = (P *)(a->unk518 + 0x180);
    if (p->cnt < 0x3F) {
        p->cnt++;
    }
    if (!(p->cnt < 15)) {
        sceVu0ScaleVector(&t0, &p->v50, -dt);
        sceVu0AddVector(&p->v40, &t0, &p->v40);
        p->v50.y = p->v50.y - 3920.0f * dt;
        sceVu0ScaleVector(&p->v50, &p->v50, 0.5f);
        sceVu0ScaleVector(&t1, &p->v50, dt);
        sceVu0AddVector(&p->v40, &t1, &p->v40);
    }
    if (p->b12) {
        if (p->cnt < 10) {
            sceVu0ScaleVector(&t2, &D_004B4D00, 120.0f);
            sceVu0AddVector(&p->v50, &t2, &p->v50);
            sceVu0ScaleVector(&t3, &D_001F2140, 150.0f);
            sceVu0AddVector(&p->v50, &t3, &p->v50);
        } else if (p->cnt < 0x30) {
            sceVu0ScaleVector(&t4, &D_004B4D00, -200.0f);
            sceVu0AddVector(&p->v50, &t4, &p->v50);
            sceVu0ScaleVector(&t5, &D_001F2140, 100.0f);
            sceVu0AddVector(&p->v50, &t5, &p->v50);
        } else {
            sceVu0ScaleVector(&t6, &D_004B4D00, -50.0f);
            sceVu0AddVector(&p->v50, &t6, &p->v50);
            if (p->cnt > 0x3C) {
                p->b12 = 0;
            }
        }
        sceVu0CopyVector(&n, &p->x18->v80);
        *(s32 *)&n.y = 0;
        func_00102870(&n, &n);
        sceVu0OuterProduct(&c, &D_004B4D00, &n);
        if (sceVu0InnerProduct(&D_004B4D00, &n) < -0.9f) {
            p->x18->x24 += 2.0f * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
        } else {
            if (c.y < -0.05f) {
                p->x18->x24 -= 2.5f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
            }
            if (c.y > 0.05f) {
                p->x18->x24 -= 2.5f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
            }
        }
    } else {
        sceVu0OuterProduct(&c, &D_004B4D00, &p->x18->v80);
        if (c.y > 0.05f) {
            p->x18->x24 -= 2.0f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
        }
        if (c.y < -0.05f) {
            p->x18->x24 -= 2.0f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
        }
        if (!(p->cnt < 15)) {
            sceVu0ScaleVector(&t7, &D_004B4D00, -400.0f);
            sceVu0AddVector(&p->v50, &t7, &p->v50);
            if (in->x8 > 0.0f) {
                p->v50.y = p->v50.y + 300.0f * -in->x8;
            }
            if (in->xC > 0.0f) {
                p->v50.y = p->v50.y + 300.0f * in->xC;
            }
            if (in->x14 > 0.4f) {
                sceVu0ScaleVector(&t8, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t8, &p->v50);
            }
            if (in->x10 > 0.4f) {
                sceVu0ScaleVector(&t9, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t9, &p->v50);
            }
            if (in->x0 > 0.4f) {
                sceVu0ScaleVector(&t10, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t10, &p->v50);
            }
            if (in->x4 > 0.4f) {
                sceVu0ScaleVector(&t11, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t11, &p->v50);
            }
        }
    }
    if (p->x154 != 0 && p->x15C->d0 == 1) {
        k = p->x15C->c0;
        if (k == 12 || k == 13) {
            D_002022E8 = D_002022E8 + fabsf(p->v50.y);
            if (D_002022E8 > 10000.0f) {
                D_002022E8 -= 10000.0f;
                if (fabsf(p->v50.y) > 100.0f) {
                    func_001CA4A0(k, 1);
                }
            }
        }
    }
    p->f = 0;
}
