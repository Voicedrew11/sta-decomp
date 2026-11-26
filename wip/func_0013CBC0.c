

#include "common.h"
typedef struct {
    u8 pad0[0x7C];
    u32 x7C;
    u8 pad80[0x4B0 - 0x80];
    s8 *unk4B0;
    u8 pad4B4[0x518 - 0x4B4];
    s8 *unk518;
    u8 pad51C[0x5B0 - 0x51C];
    Flags8 flags5B0;
    u8 pad5B1[5];
    Flags8 flags5B6;
    u8 pad5B7[0x6D0 - 0x5B7];
    s16 x6D0;
    s16 x6D2;
    s8 x6D4;
    s8 x6D5;
    u8 x6D6;
} Actor;
typedef struct { u8 pad0[0x140]; u16 x140; u8 pad142[2]; f32 x144; f32 x148; u8 pad14C[4]; f32 x150; } Ent;
typedef struct { u8 pad0[0xC]; f32 xC; f32 x10; f32 x14; } Q;
typedef struct { u8 pad0[0x40]; Vec v40; Vec v50; } P;
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
u32 func_0013E750(Actor *);
s32 func_0013E780(Actor *);
void func_0013E730(Actor *, s32);
s32 func_0013EEE0(Actor *);
void func_0013E920(Actor *, s32);
void func_0013C0D0(Actor *a, u8 slot, s16 id, s8 dx, s8 dy, u8 flags);
s32 func_0013E970(Actor *);
s32 func_0013EA10(Actor *);
s32 func_0013E9C0(Actor *);
void func_0013E950(Actor *, s32);
void func_0013E9D0(Actor *, s32);
void func_0013E980(Actor *, s32);
s32 func_0013E0B0(Actor *);
f32 func_0013E090(Actor *, s32);
void func_0013E6D0(Actor *, s32);
u32 func_00142780(Actor *);
u32 func_001412E0(Actor *);
void func_0013E890(Actor *, s32);
void func_0013E7E0(Actor *, s32);
Ent *func_0013DC70(Actor *, u8);
f32 func_00173F70(s32, u16);


/* NEAR: matches only if func_0013C360 is a STATIC function defined earlier in the same file:
   MWCC then knows it preserves a0/t0 and skips reloading a0 before func_0013E920.
   This stub stands in for the real (unmatched) func_0013C360. */
static void func_0013C360(Actor *a, s16 id, s8 b, s8 c, u8 d) { /* ; */
    a->x6D2 = id;
    a->x6D4 = b;
    a->x6D5 = c;
    a->x6D6 = d;
}

static inline f32 u2f(u32 x) { return x; }

static inline void jump(Actor *a, f32 dt) {
    Vec t;
    P *p = (P *)(a->unk518 + 0x180);
    p->v50.y = 333.2f * (u2f(*(u16 *)(a->unk4B0 + 0x246)) / 4096.0f);
    sceVu0ScaleVector(&t, &p->v50, dt);
    sceVu0AddVector(&p->v40, &t, &p->v40);
    func_0013E730(a, 1);
}

void func_0013CBC0(Actor *a, f32 dt) {
    u8 i;
    u32 j;
    Ent *e;
    f32 rem;
    f32 over;
    f32 lim;
    f32 t;
    Q **s;
    f32 *pc;

    rem = dt;
    if ((u8)func_0013E750(a) == 2) {
        if (a->flags5B6.f.b0) {
            jump(a, dt);
            a->flags5B6.f.b0 = 0;
        }
    } else {
        a->flags5B6.f.b0 = 0;
    }
    if ((u8)func_0013E750(a) == 1 && func_0013E780(a)) {
        func_0013E730(a, 0);
        func_0013C360(a, func_0013EEE0(a) ? (s16)((a->flags5B0.f.b0 << 5) + 0x1F) : (s16)((a->flags5B0.f.b0 << 5) + 0x1E), 5, 0, 2);
        func_0013E920(a, 1);
    }
    for (i = 0; (rem > 0.0f) && i < 4; i++) {
        if (a->x6D2 >= 0) {
            if (a->x6D0 < 0) {
                a->x6D6 = 2;
            }
            func_0013C0D0(a, 0xFF, a->x6D2, a->x6D4, a->x6D5, a->x6D6);
            a->x6D0 = a->x6D2;
            a->x6D2 = -1;
        }
        if (func_0013E970(a)) {
            func_0013E950(a, 0);
            func_0013E9D0(a, 0);
            func_0013E980(a, 0);
        } else if (func_0013EA10(a)) {
            func_0013E950(a, 0);
            func_0013E9D0(a, 0);
            func_0013E980(a, 0);
        } else if (func_0013E9C0(a) && !a->flags5B0.f.b7) {
            func_0013E950(a, 0);
            func_0013E9D0(a, 0);
            func_0013E980(a, 0);
        } else {
            over = 0.0f;
            lim = func_0013E090(a, func_0013E0B0(a));
            s = (Q **)(a->unk518 + 0x1A8);
            (*s)->x10 = (*s)->xC;
            (*s)->xC = (*s)->xC + rem * (*s)->x14;
            pc = &(*s)->xC;
            if (!((*s)->xC <= lim)) {
                over = (*s)->xC - lim;
                (*s)->xC = lim;
            }
            rem = over;
            func_0013E950(a, 0);
            func_0013E9D0(a, 0);
            func_0013E980(a, 0);
        }
        if (!(rem <= 0.0f)) {
            func_0013E920(a, 0);
            func_0013E6D0(a, 0);
            if ((u8)func_0013E750(a) == 2) {
                jump(a, dt);
            }
            if ((u8)func_0013E750(a) == 1) {
                func_0013C360(a, (a->flags5B0.f.b0 << 5) + 0x1D, 5, 0, 1);
                func_0013E920(a, 1);
            } else if (!a->flags5B0.f.b7) {
                if (!func_0013EEE0(a) && !(u8)func_00142780(a)) {
                    rem = 0.0f;
                }
            } else {
                if (!(u8)func_001412E0(a)) {
                    rem = 0.0f;
                }
            }
        }
    }
    if (!a->flags5B0.f.b7 && !(rem <= 0.0f) && func_0013EEE0(a)) {
        func_0013E890(a, 1);
        func_0013E7E0(a, 1);
    }
    for (j = 0; j < a->x7C; j++) {
        e = func_0013DC70(a, j);
        if (e->x150 != 0.0f) {
            lim = func_00173F70(**(s32 **)(a->unk518 + 0x18C), e->x140);
            t = e->x144;
            t += dt * e->x148;
            if (!(t <= lim)) {
                t -= lim;
            }
            e->x144 = t;
        }
    }
}
