#include "common.h"
#include "actor.h"
typedef struct { u16 a:6; u16 v:6; u16 b:1; u16 c:3; } BF39E;
typedef struct { u16 a:7; u16 v:6; u16 p:2; u16 b15:1; } BF3A0;
typedef struct { u8 pad[0xC8]; s32 xC8; u8 padCC[0x34]; Vec x100; } Q10;
typedef struct { u8 pad[0xC]; u8 xC; u8 xD; } Q15C;
typedef struct {
    u8 pad0[0x10];
    Q10 *x10;
    u8 pad14[4];
    Vec *x18;
    u8 pad1C[0x24];
    Vec x40;
    Vec x50;
    u8 pad60[0x70];
    Vec xD0;
    u8 padE0[0x14];
    s32 xF4;
    u8 padF8[0x38];
    Vec x130;
    Vec x140;
    u8 pad150[4];
    s32 x154;
    u8 pad158[4];
    Q15C *x15C;
    u8 pad160[0x39E - 0x160];
    BF39E f39E;
    BF3A0 f3A0;
    Flags8 f3A2;
    u8 pad3A3;
    f32 x3A4;
    u8 pad3A8[4];
    u8 x3AC;
} P;
extern Vec D_004B4CF0;
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
void func_001029E8(Vec *, Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, Mtx *, Vec *);
void func_00102870(Vec *, Vec *);
s32 func_001A5AA0(Actor *, P *, Mtx *);
void func_001456B0(Vec *);
f32 func_0013FC10(Vec *);
f32 func_0011D850(f32);
f32 func_0015DF90(f32, f32, f32);
void func_001BD4E0(Actor *);
void func_001BE510(Actor *);
s32 func_001BE050(Actor *);
void func_00159500(s32);
s32 func_00169B50(s32, s32, s32, s32);
s32 func_00125538(void);
s32 func_001BE390(Actor *);
void func_001CEAA0(s32);
static inline void tail(Actor *a0, P *s1, Vec *v) {
    Mtx m;
    Vec d;
    Vec r;
    if (s1->x10->xC8 != 0) {
        func_001A5AA0(a0, s1, &m);
        func_001029E8(&d, v, &s1->x10->x100);
        d.w = 1.0f;
        func_001027B0(&r, &m, &d);
        func_001029D0(v, &s1->x10->x100, &r);
        func_001456B0(&d);
        d.w = 0.0f;
        func_001027B0(&r, &m, &d);
        *(f32 *)(a0->unk518 + 0x24) = func_0013FC10(&r);
    }
    v->y -= 220.0f;
    s1->x40.x = v->x;
    s1->x40.z = v->z;
    if (!(func_0011D850(s1->x40.y - v->y) <= 100.0f)) {
        s1->x40.y = v->y;
    } else {
        s1->x40.y = func_0015DF90(s1->x40.y, v->y, 0.5f);
    }
    func_001BD4E0(a0);
    s1->x3A4 *= 0.8f;
    if (!(s1->x3A4 <= -0.002f)) s1->x3A4 = 0.0f;
    func_001BE510(a0);
    s1->x50.y = 0.0f;
    s1->f3A2.f.b0 = 1;
    s1->f3A0.v = 0;
}
static inline void push(P *s1) {
    Vec w;
    if (!s1->f39E.b) {
        func_001029E8(&w, &D_004B4CF0, s1->x18);
        w.w = 0.0f;
        func_00102870(&w, &w);
        func_00102A18(&w, &w, 200.0f);
        func_001029D0(&s1->x50, &s1->x50, &w);
        s1->x50.y -= 196.0f;
        if (s1->x154 != 0 && (s1->x15C->xD & 7) == 1 && ((s1->x15C->xC & 0xF) == 12 || (s1->x15C->xC & 0xF) == 13)) {
            s1->f39E.v += 3;
        }
    }
}

void func_001BE7B0(Actor *a0) {
    P *s1;
    u16 n;
    s8 *t;
    Vec v;

    t = a0->unk518;
    ((Flags8 *)(t + 0x522))->f.b0 = 0;
    s1 = (P *)(t + 0x180);
    if (s1->x154 != 0 && s1->xF4 != 0) {
        func_00102A18(&v, &s1->x140, 100.0f);
        func_001029D0(&v, &v, &s1->x130);
        v.y = s1->xD0.y;
        tail(a0, s1, &v);
    } else if (s1->xF4 != 0) {
        func_00102A60(&v, &s1->xD0);
        tail(a0, s1, &v);
    } else if (s1->x154 != 0) {
        func_00102A18(&s1->x40, &s1->x140, 100.0f);
        func_001029D0(&s1->x40, &s1->x40, &s1->x130);
        s1->x40.y -= 120.0f;
    }
    if ((n = s1->f39E.v) != 0) {
        if (n < 15) {
            push(s1);
        } else if (!s1->f39E.b) {
            if (s1->xF4 != 0) {
                s1->f39E.v = 0;
            } else if (s1->x154 != 0) {
                if ((s1->x15C->xD & 7) == 1 && (s1->x15C->xC & 0xF) != 12 && (s1->x15C->xC & 0xF) != 13) {
                    s1->f39E.c++;
                }
            } else {
                s1->f39E.c++;
            }
            if (s1->f39E.c > 5) s1->f39E.v = 0;
        }
    }
    if (func_001BE050(a0)) {
        func_00159500(1);
        s1->f3A0.b15 = 1;
        if (s1->x3AC == 0) {
            func_00169B50(0x1F0, 0, 1, 0);
            s1->x3AC = func_00125538() % 30 + 30;
        } else {
            s1->x3AC--;
        }
    } else {
        func_00159500(0);
        s1->f3A0.b15 = 0;
    }
    if (!(s1->x40.x <= 29000.0f)) s1->x40.x = 29000.0f;
    if (s1->x40.x < -29000.0f) s1->x40.x = -29000.0f;
    if (!(s1->x40.y <= 18000.0f)) s1->x40.y = 18000.0f;
    if (s1->x40.y < -29000.0f) s1->x40.y = -29000.0f;
    if (!(s1->x40.z <= 29000.0f)) s1->x40.z = 29000.0f;
    if (s1->x40.z < -29000.0f) s1->x40.z = -29000.0f;
    if (!(s1->x40.y < 18000.0f) || func_001BE390(a0)) func_001CEAA0(-9999);
}
