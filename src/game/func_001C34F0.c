#include "common.h"
typedef struct { s8 pad[0x20]; f32 f20; f32 f24; s8 pad2[0x38]; Vec v60; s8 pad3[0x10]; Vec v80; } P18;
typedef struct { s8 pad[0x48]; s32 x48; } P390;
typedef struct { u8 n:4; u8 b4:1; u8 r:3; } B39D;
typedef struct { u16 pad:7; u16 cnt:6; u16 r:3; } B3A0;
typedef struct {
    s8 pad[0x18]; P18 *p18; s8 pad1[0x50 - 0x1C]; Vec v50;
    s8 pad2[0x390 - 0x60]; P390 *p390; s8 pad3[0x39D - 0x394]; B39D b39D; s8 pad4[2]; B3A0 h3A0; s8 pad5[2]; f32 f3A4;
} SS;
void func_00102A18(Vec *, Vec *, f32);
void func_001029D0(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
f32 func_0011D850(f32);
void func_001CA2C0(void);
f32 sqrtf(f32);
static inline f32 mu(f32 a, f32 b) { return a * b; }

void func_001C34F0(s8 *arg0, f32 *a) {
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    SS *s;
    f32 k;
    f32 sv;
    f32 len;
    f32 f;
    f32 r;

    s = (SS *)(*(s8 **)(arg0 + 0x518) + 0x180);
    if (s->h3A0.cnt < 0x3F) {
        s->h3A0.cnt++;
    }
    if (s->h3A0.cnt == 10) {
        func_001CA2C0();
    }
    if (s->h3A0.cnt < 4) {
        if (a[2] > 0.0f) {
            func_00102A18(&t0, &s->p18->v80, 0.2f * (250.0f * -a[2]));
            func_001029D0(&s->v50, &t0, &s->v50);
        }
        if (a[3] > 0.0f) {
            func_00102A18(&t1, &s->p18->v80, 0.2f * (100.0f * a[3]));
            func_001029D0(&s->v50, &t1, &s->v50);
        }
        if (a[5] > 0.0f) {
            k = s->p390->x48 ? 0.5f : 1.0f;
            func_00102A18(&t2, &s->p18->v60, 0.2f * (-a[5] * (100.0f * k)));
            func_001029D0(&s->v50, &t2, &s->v50);
        }
        if (a[4] > 0.0f) {
            k = s->p390->x48 ? 0.5f : 1.0f;
            func_00102A18(&t3, &s->p18->v60, 0.2f * (a[4] * (100.0f * k)));
            func_001029D0(&s->v50, &t3, &s->v50);
        }
    }
    if (a[0] > 0.0f) {
        k = s->p390->x48 ? 0.5f : 1.0f;
        s->p18->f24 = s->p18->f24 + 0.3f * (a[0] * (0.0488692187f * k));
    }
    if (a[1] > 0.0f) {
        k = s->p390->x48 ? 0.5f : 1.0f;
        s->p18->f24 = s->p18->f24 - 0.3f * (a[1] * (0.0488692187f * k));
    }
    sv = s->v50.y;
    s->v50.y = 0.0f;
    func_00102A18(&s->v50, &s->v50, 0.640000045f);
    len = func_00102848(&s->v50, &s->v50);
    s->v50.y = sv;
    len = sqrtf(len);
    if (func_0011D850(s->p18->f20) < 0.0872664675f) {
        if (s->b39D.n > 3) {
            f = len / 1000.0f;
            f = f > 1.0f ? 1.0f : f;
            r = s->v50.y > 0.0f ? 0.05f : 0.01f;
            s->f3A4 = s->f3A4 + mu((-0.7853982f - s->f3A4) * r, f);
            s->b39D.n = 5;
        }
        s->b39D.n++;
    } else {
        s->f3A4 *= 0.8f;
        s->b39D.n = 0;
    }
    s->b39D.b4 = 0;
}
