#include "m2c.h"
typedef struct { u8 pad[0x20]; f32 rot; } R;
typedef struct { u8 pad[0x48]; s32 slow; } Q;
typedef struct {
    u8 pad0[0x18]; R *r;
    u8 pad1[0x390 - 0x1C]; Q *q;
    u8 pad2[0x3A0 - 0x394]; u8 flg;
    u8 pad3[0x42C - 0x3A1]; f32 dt;
} A;
typedef struct { u8 pad[0x18]; f32 x, y; u8 pad2[0x34 - 0x20]; s32 btn; } In;
s32 func_001A9450(void);
static inline f32 spd(A *a) {
    f32 k;
    if (a->q->slow != 0) k = 0.5f; else k = 1.0f;
    return 0.06981317f * k;
}

void func_001C27C0(s8 *arg0, In *in) {
    f32 mag;
    f32 acc;
    A *a;
    s32 on;
    f32 sign;

    on = 0;
    a = (A *)(M2C_FIELD(arg0, s32 *, 0x518) + 0x180);
    acc = 0.0f;
    mag = 1.0f;
    if ((func_001A9450() & 0xFF) >= 2) {
        if (in->btn & 4) {
            mag = 0.64000005f;
            on = 1;
        }
    } else if (in->y > acc && in->x > acc) {
        f32 t;
        mag = in->y * in->y;
        t = in->x * in->x;
        on = 1;
        mag = (t < mag) ? mag : t;
    }
    if (on != 0) {
        if (!(a->flg & 1)) {
            sign = 1.0f;
            if (a->r->rot > 0.0f) sign = -1.0f;
            acc += mag * sign * spd(a);
            a->r->rot += acc * a->dt;
            if (a->r->rot * sign > 0.0f) a->r->rot = 0.0f;
        }
    } else {
        if (in->y > 0.1f) acc -= 0.4f * spd(a);
        if (in->x > 0.1f) acc += 0.4f * spd(a);
        a->r->rot += acc * a->dt;
    }
}
