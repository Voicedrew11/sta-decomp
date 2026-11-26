#include "common.h"
typedef struct { u8 t:2; u8 b2:1; u8 b3:1; u8 b4:1; } EF;
typedef struct {
    f32 x, y, z;
    u8 padC[0xC];
    u16 x18;
    u16 x1A;
    u16 x1C;
    u16 x1E;
    u16 x20;
    u16 x22;
    u16 x24;
    u16 x26;
    u16 x28;
    u16 x2A;
    u8 x2C;
    u8 pad2D[3];
    EF x30;
    u8 pad31[0x23];
} E;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } AF;
typedef struct { u8 pad[0x5A0]; AF f; } A;
typedef struct { A **x0; s32 x4; } S;
typedef struct { u8 pad[0xC4]; u8 xC4; } P158;
typedef struct {
    s32 x0;
    u8 pad4[0xC];
    Vec x10;
    u8 pad20[0x50];
    u16 x70;
    u8 pad72[0x1E];
    u32 x90[2];
    u32 x98[2];
    u32 xA0[2];
    u32 xA8;
    u8 padAC[0x90];
    E *x13C;
    u8 pad140[0x18];
    P158 *x158;
    u8 pad15C[0x20];
    S *x17C;
} O;
extern O **D_00201E88[2];
u32 func_001AA1E0(s32, s16);
void func_001C9410(Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
f32 fabsf(f32);
f32 func_0015DEE0(Vec *, Vec *);
s32 func_0015C9E0(void);
A **func_001A7D90(u16);
void func_001A6FF0(A *, O **, u16);
s32 func_0013E830(A *);
void func_001A6C10(A *);
void func_001A6C90(A *);
u32 func_0015ED20(void);

static inline f32 u2f(u32 x) { return x; }

static inline s32 inr(E *e, O *o, u16 *r) {
    Vec pos;
    Vec cam;
    volatile f32 h;
    f32 d;
    s32 k;
    func_001C9410(&cam);
    for (k = 0; k < 3; k++) (&pos.x)[k] = (&e->x)[k];
    pos.w = 1.0f;
    sceVu0AddVector(&pos, &pos, &o->x10);
    h = fabsf(pos.y - cam.y);
    d = func_0015DEE0(&pos, &cam);
    if (u2f(r[0]) < d) goto no;
    if (r[1] == 0) goto yes;
    if (h <= u2f(r[1])) goto yes;
no:
    return 0;
yes:
    return 1;
}

void func_001B43A0(O *o) {
    s32 idx;
    s32 i;
    E *e;
    S *s;
    u32 k;
    u32 j;
    u32 mask;
    u32 *w;
    E *e2;
    A *a;
    u32 m2;
    u32 j2;
    S *s2;
    u32 *w2;

    idx = -1;
    if (D_00201E88[0] && *D_00201E88[0] == o) idx = 0;
    if (D_00201E88[1] && *D_00201E88[1] == o) idx = 1;
    for (i = 0; i < o->x70; i++) {
        e = &o->x13C[i];
        s = &o->x17C[i];
        k = e->x1A % 100;
        j = k >> 5;
        mask = 1 << (k & 31);
        if (func_001AA1E0(o->x0, k) < e->x2C) {
            w = &o->x90[j];
            if (!(*w & mask) && inr(e, o, &e->x1E)) {
                s->x4 = func_0015C9E0();
                s->x0 = func_001A7D90(e->x18);
                func_001A6FF0(*s->x0, D_00201E88[idx], i);
                *w |= mask;
            }
        }
    }
    for (i = 0; i < o->x70; i++) {
        e2 = &o->x13C[i];
        s2 = &o->x17C[i];
        k = e2->x1A % 100;
        j2 = k >> 5;
        m2 = 1 << (k & 31);
        if (s2->x0 == 0) continue;
        a = *s2->x0;
        if (a == 0) continue;
        if (!a->f.b0) continue;
        if (a->f.b0 && a->f.b2) {
            if ((u8)func_0013E830(a) == 1) {
                func_001A6C10(a);
                if (!e2->x30.b3 && o->xA8) o->xA8--;
                o->x98[j2] |= m2;
            } else if (!e2->x30.b3 && !inr(e2, o, &e2->x1E)) {
                func_001A6C10(a);
                if (o->xA8) o->xA8--;
                o->x98[j2] |= m2;
            }
        } else if (func_001AA1E0(o->x0, k) < e2->x2C) {
            if (e2->x30.t != 2 || (o->xA0[j2] & m2)) {
                if (inr(e2, o, &e2->x26)) {
                    if (!e2->x30.b3 && !(o->xA8 < o->x158->xC4)) {
                        if (!e2->x30.b4) o->x98[j2] |= m2;
                    } else if (e2->x30.t == 1) {
                        func_001A6C90(a);
                        if (!e2->x30.b3) o->xA8++;
                    } else {
                        w2 = &o->x98[j2];
                        if (!(*w2 & m2)) {
                            if (func_0015ED20() % 100 < e2->x2A) {
                                func_001A6C90(a);
                                if (!e2->x30.b3) o->xA8++;
                            }
                            *w2 |= m2;
                        }
                    }
                } else {
                    o->x98[j2] &= ~m2;
                }
            }
        }
    }
}
