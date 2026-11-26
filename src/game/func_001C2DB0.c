#include "actor.h"
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } Q;
typedef struct { u8 pad[0x48]; s32 x48; } R;
typedef struct { u8 lo4:4; u8 b4:1; u8 b5:3; } B39D;
typedef union { struct { u16 a:7; u16 f:6; u16 c:3; } h; struct { u8 lo; Flags8 hi; } b; } U3A0;
typedef struct {
    u8 pad[0x18];
    Q *x18;
    u8 pad1C[0x50 - 0x1C];
    Vec v50;
    u8 pad60[0x390 - 0x60];
    R *x390;
    u8 pad394[0x39D - 0x394];
    B39D f39D;
    u8 pad39E[2];
    U3A0 f3A0;
    u8 pad3A2[0x3CD - 0x3A2];
    s8 x3CD;
    u8 pad3CE[0x428 - 0x3CE];
    f32 f428;
    f32 f42C;
} P;
s32 func_00120570(s32);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 func_001C2640(Actor *);
void func_001C2A50(Actor *);
f32 func_0015DF90(f32, f32, f32);
f32 sqrtf(f32);
extern Vec D_003139A0;

void func_001C2DB0(Actor *a, f32 *in) {
    Vec v90;
    Vec v80;
    Vec v70;
    Vec v60;
    P *p;
    s32 n;
    f32 d;
    f32 y;
    f32 sc;
    f32 yaw;
    f32 pitch;
    f32 t;
    f32 u;
    Q *q;

    yaw = 0.0f;
    p = (P *)(a->unk518 + 0x180);
    pitch = 0.0f;
    if (!(in[2] <= 0.2f) || !(in[3] <= 0.2f)) {
        n = 0;
        if (!(in[2] < 1.0f) && p->x3CD == 0) n -= 2;
        else if (!(in[2] <= 0.2f)) n -= 1;
        if (!(in[3] < 1.0f) && p->x3CD == 0) n += 2;
        else if (!(in[3] <= 0.2f)) n += 1;
        switch (func_00120570(n)) {
        case 0:
            in[3] = 0.0f;
            in[2] = 0.0f;
            break;
        case 1:
            sceVu0ScaleVector(&v90, (Vec *)((u8 *)p->x18 + 0x80), n > 0 ? 60.000004f : -75.0f);
            sceVu0AddVector(&p->v50, &v90, &p->v50);
            break;
        case 2:
            sceVu0ScaleVector(&v80, (Vec *)((u8 *)p->x18 + 0x80), n > 0 ? 100.0f : -250.0f);
            sceVu0AddVector(&p->v50, &v80, &p->v50);
            p->f3A0.b.hi.f.b5 = 1;
            break;
        }
    }
    if (!(in[5] <= 0.2f) || !(in[4] <= 0.2f)) {
        n = 0;
        if (!(in[5] <= 0.4f) && p->x3CD == 0) n -= 2;
        else if (!(in[5] <= 0.2f)) n -= 1;
        if (!(in[4] <= 0.4f) && p->x3CD == 0) n += 2;
        else if (!(in[4] <= 0.2f)) n += 1;
        sc = n >= 0 ? 1.0f : -1.0f;
        switch (func_00120570(n)) {
        case 0:
            in[4] = 0.0f;
            in[5] = 0.0f;
            break;
        case 1:
            sceVu0ScaleVector(&v70, (Vec *)((u8 *)p->x18 + 0x60), sc * (0.6f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f))));
            sceVu0AddVector(&p->v50, &v70, &p->v50);
            break;
        case 2:
            sceVu0ScaleVector(&v60, (Vec *)((u8 *)p->x18 + 0x60), sc * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &v60, &p->v50);
            p->f3A0.b.hi.f.b5 = 1;
            break;
        }
    }
    if (!(in[0] <= 0.2f) && in[1] <= 0.2f) {
        yaw += in[0] * (0.0488692187f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (!(in[1] <= 0.2f) && in[0] <= 0.2f) {
        yaw -= in[1] * (0.0488692187f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    sc = func_001C2640(a);
    y = p->v50.y;
    p->v50.y = 0.0f;
    d = sqrtf(sceVu0InnerProduct(&p->v50, &p->v50));
    if (d < 40.0f) sceVu0CopyVector(&p->v50, &D_003139A0);
    p->f428 = func_0015DF90(p->f428, p->f3A0.b.hi.f.b5 ? 0.8f * sc : 0.5f * sc, 0.2f);
    u = 600.0f * (p->x390->x48 ? 0.5f : 1.0f);
    t = p->f428 * u;
    if (!(d <= t)) {
        sceVu0ScaleVector(&p->v50, &p->v50, t / d);
    }
    if (in[2] <= 0.05f && in[3] <= 0.05f && in[5] <= 0.05f && in[4] <= 0.05f) {
        sceVu0ScaleVector(&p->v50, &p->v50, 0.64000005f);
    }
    p->v50.y = y;
    sc = (p->x3CD == 0) ? sc : 0.5f * sc;
    p->f42C = func_0015DF90(p->f42C, sc, 0.2f);
    q = p->x18;
    q->x20 += pitch * p->f42C;
    q = p->x18;
    q->x24 += yaw * p->f42C;
    func_001C2A50(a);
    p->f39D.b4 = 1;
    p->f3A0.h.f = 0;
    p->f39D.lo4 = 0;
}
