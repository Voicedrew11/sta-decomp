#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { Vec s; Vec e; } Seg;
typedef struct { Vec p; u8 pad[0x14]; s32 hit; u8 pad2[0x18]; } Hit;
typedef struct { u8 pad[0xC]; f32 xC; } Q;
typedef struct { Q *p; s32 pad[2]; } QP __attribute__((aligned(16)));
s32 func_0013EDE0(s8 *);
s8 *func_001A5460(s32 *);
s32 func_0013EE30(s8 *);
s32 func_0013ED20(s8 *);
void func_00140470(s8 *, Vec *);
void func_001403D0(s8 *, Vec *);
Vec *func_00140460(s8 *);
Vec *func_00140430(s8 *);
void func_00102A60(Vec *, Vec *);
void func_00123C40(void *, s32, s32);
void func_0013D430(s32, Hit *, Seg *, s32, s32);
void func_001029E8(Vec *, void *, void *);
void func_00102A18(f32, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, void *);
s32 func_0013FC00(s8 *);
void func_0013FB90(s8 *, u8, QP *, QP *);
extern s32 D_00201E80;
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void func_00143E20(s8 *a0, s32 a1, u8 a2, s32 a3, s32 t0, s32 t1, f32 ang) {
    u8 k;
    s8 *cur;
    s32 it;
    Vec m;
    Vec p;
    Hit r;
    Seg b;
    QP q1;
    QP q2;
    f32 t;
    u8 n;
    u8 i;
    f32 fz;
    f32 fx;

    k = func_0013EDE0(a0);
    it = 0;
    cur = func_001A5460(&it);
    if (cur != NULL) {
        do {
            if (func_0013EE30(cur) == 0 && func_0013EDE0(cur) == k && (u8)func_0013ED20(cur) == a2) {
                func_00140470(a0, &p);
                func_001403D0(a0, &m);
                p.x += m.x * t1;
                p.z += m.z * t1;
                p.x -= m.z * a3;
                p.z += m.x * a3;
                p.y -= t0;
                func_00102A60(&b.s, func_00140460(a0));
                b.s.y -= 100.0f;
                b.s.w = 1.0f;
                func_00102A60(&b.e, &p);
                b.e.w = 1.0f;
                func_00123C40(&r, 0, 0x40);
                if (((s32 **)&D_00201E80)[2] != NULL) {
                    func_0013D430(*((s32 **)&D_00201E80)[2], &r, &b, 6, 3);
                }
                if (r.hit == 0 && ((s32 **)&D_00201E80)[3] != NULL) {
                    func_0013D430(*((s32 **)&D_00201E80)[3], &r, &b, 6, 3);
                }
                if (r.hit != 0) {
                    func_001029E8(&p, &r, &b);
                    func_00102A18(0.9f, &p, &p);
                    func_001029D0(&p, &p, &b);
                }
                n = func_0013FC00(cur);
                for (i = 0; i < n; i++) {
                    q1.p = NULL;
                    q2.p = NULL;
                    func_0013FB90(cur, i, &q1, &q2);
                    if (q1.p != NULL) q1.p->xC = -100.0f;
                    if (q2.p != NULL) q2.p->xC = -100.0f;
                }
                func_00102A60(func_00140460(cur), &p);
                func_00102A60((Vec *)(*(s8 **)(cur + 0x518) + 0x1C0), &p);
                t = ang + func_00140430(a0)->y;
                func_00140430(cur)->y = WRAP(t);
                return;
            }
            cur = func_001A5460(&it);
        } while (cur != NULL);
    }
}
