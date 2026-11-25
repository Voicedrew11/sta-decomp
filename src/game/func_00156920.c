#include "m2c.h"
typedef f32 Mtx[4][4];
typedef struct { f32 x0[3]; f32 xC; f32 x10[3]; f32 x1C; Mtx x20; s32 x60; } S;
void func_00102AD8(Mtx);
void func_001027E0(Mtx, Mtx, Mtx);
void func_00102A60(f32 *, f32 *);
void func_00102828(f32 *, f32 *, f32 *);
f32 func_00102848(f32 *, f32 *);
void func_00102870(f32 *, f32 *);
void func_00156450(Mtx, f32, s32);
float sqrtf(float);
extern f32 D_001F2140[];
extern f32 D_001F2130[];
extern Mtx D_002F1840;

void func_00156920(S *s) {
    Mtx a;
    Mtx b;
    Mtx d;
    Mtx c;
    func_00102AD8(a);
    a[0][0] = s->xC;
    a[1][1] = s->xC;
    a[2][2] = s->xC;
    func_00102AD8(b);
    b[0][0] = 1.0f;
    b[1][1] = 1.0f;
    b[2][2] = 1.0f;
    func_00102A60(b[2], s->x10);
    b[2][3] = 0.0f;
    func_00102A60(b[1], D_001F2140);
    func_00102828(b[0], b[1], b[2]);
    if (sqrtf(func_00102848(b[0], b[0])) < 1e-5f) {
        func_00102A60(b[0], D_001F2130);
    } else {
        func_00102870(b[0], b[0]);
    }
    func_00102828(b[1], b[2], b[0]);
    if (sqrtf(func_00102848(b[1], b[1])) < 1e-5f) {
        func_00102A60(b[0], D_001F2140);
    } else {
        func_00102870(b[1], b[1]);
    }
    func_001027E0(a, a, b);
    func_00102A60(a[3], s->x0);
    a[3][3] = 1.0f;
    func_001027E0(c, s->x20, a);
    func_001027E0(d, D_002F1840, c);
    func_00156450(d, s->x1C / s->xC, s->x60);
}
