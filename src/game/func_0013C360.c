/* func_0013C360 through func_0013CBC0: one translation unit. func_0013C360
   is static here, so CodeWarrior knows which registers it keeps and its
   callers do not reload them (func_0013C740, func_0013CBC0). */
#include "m2c.h"
#include "actor.h"
u32 func_0013E750(void *);
void func_0013E920(void *, u8);

typedef struct { u8 p[0x5B5]; Flags8_4x2 f5B5; u8 q[0x6D2 - 0x5B6]; s16 x6D2; s8 x6D4; s8 x6D5; s8 x6D6; } A360;
static void func_0013C360(void *p, s16 v, s8 b, s8 c, s32 d) {
    A360 *a = p;
    a->x6D2 = v;
    a->x6D4 = b;
    a->x6D5 = c;
    a->x6D6 = d;
    if ((v >= 8 && v < 12) || (v >= 16 && v < 19) || (v >= 40 && v < 44) || (v >= 48 && v < 51)) a->f5B5.f.b6 = 1;
    else a->f5B5.f.b6 = 0;
}

#define A A_0013C420
#define F F_0013C420
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 n:3; u8 r:2; } F;
typedef struct {
    u8 pad[0x5B0];
    F f5B0;
    u8 pad2[0x6B4 - 0x5B1];
    u16 x6B4[2];
} A;
u32 func_0015ED20(void);

void func_0013C420(A *a, u8 kind, s16 v, s32 a3) {
    s16 id = -1;

    switch (kind) {
    case 0:
        if (v == 0 && (a->x6B4[a->f5B0.b0] & 0x400)) {
            v = !((func_0015ED20() & 3) != 0);
        }
        id = (a->f5B0.b0 << 5) + (v | a->f5B0.b2);
        break;
    case 1:
        id = (a->f5B0.b0 << 5) + 2;
        break;
    case 2:
        id = (a->f5B0.b0 << 5) + 3;
        break;
    case 3:
        id = v + ((a->f5B0.b0 << 5) + 4) + a->f5B0.b1 * 2;
        break;
    case 4:
        if (a->f5B0.n < 4) {
            id = a->f5B0.n + ((a->f5B0.b0 << 5) + 8);
        } else {
            id = (a->f5B0.n - 4) + ((a->f5B0.b0 << 5) + 0x10);
        }
        break;
    case 7:
        id = (a->f5B0.b0 << 5) + 0x14;
        break;
    case 8:
        id = (a->f5B0.b0 << 5) + 0x15;
        break;
    case 9:
        id = (a->f5B0.b0 << 5) + 0x16;
        break;
    case 13:
        id = (a->f5B0.b0 << 5) + 0x1A;
        break;
    case 14:
        id = (a->f5B0.b0 << 5) + 0x1B;
        break;
    case 15:
        id = (a->f5B0.b0 << 5) + 0x1C;
        break;
    case 16:
        id = (a->f5B0.b0 + 0xA0) + v * 2;
        break;
    case 0xFF:
        id = v;
        break;
    }
    if (id != -1) func_0013C360(a, id, 5, 0, a3);
}

#undef A
#undef F

#define O O_0013C740
typedef struct { u8 pad[0x5B0]; u8 x5B0; } O;
u32 func_0013E940(O *);

s32 func_0013C740(O *o) {
    if (func_0013E940(o) == 0) {
        func_0013C360(o, (o->x5B0 & 1) * 32 + 0x13, 0, 0, 2);
        func_0013E920(o, 1);
    }
    return 0;
}

#undef O

#define Obj Obj_0013C7B0
typedef struct { char pad[0x5B0]; unsigned int f : 1; char p[2]; unsigned int : 4; unsigned int m : 2; } Obj;
s32 func_00142470(Obj *o, s16 k);

u8 func_0013C7B0(Obj *o)
{
    u8 r;
    s16 k = (o->m & 3) + (o->f * 32 + 12);
    r = func_00142470(o, k);
    if (!r)
        func_0013C360(o, k, 0, 0, 2);
    func_0013E920(o, 1);
    return r;
}

#undef Obj

u8 func_00142530(Actor *, s16);
s16 func_0013E0C0(Actor *, u8);
u8 func_001425F0(Actor *, u8, s32);

u8 func_0013C850(Actor *a) {
    u8 r;
    s16 v;
    v = (a->flags5B0.f.b0 << 5) + 0x19;
    if ((u8)func_0013E750(a) == 2) {
        v = (a->flags5B0.f.b0 << 5) + 0x17;
        a->flags5B6.f.b0 = 1;
    } else if ((u8)func_0013E750(a) == 1) {
        v = (a->flags5B0.f.b0 << 5) + 0x17;
    }
    r = func_00142530(a, v);
    if (r == 0) {
        func_0013C360(a, v, 0, 0, 2);
    }
    func_0013E920(a, 1);
    return r;
}

u8 func_0013C950(Actor *a, u8 b, u8 c) {
    u8 r;
    s16 v;
    if (b == 0xFF) {
        v = (a->flags5B0.f.b0 << 5) + 0x18;
    } else {
        v = func_0013E0C0(a, b);
        v += (s16)(a->flags5B0.f.b0 + 2 + c * 2);
    }
    r = func_001425F0(a, v, (u8)b);
    if (r == 0) {
        func_0013C360(a, v, 0, 0, 2);
    }
    func_0013E920(a, 1);
    return r;
}


s16 func_0013E0C0(Actor *, u8);
u8 func_001426C0(Actor *, s16);

u8 func_0013CA40(Actor *a, u8 b) {
    s16 v;
    u8 r;
    if ((u8)func_0013E750(a) == 2) {
        v = a->flags5B0.f.b0 * 32 + 0x17;
    } else if ((u8)func_0013E750(a) == 1) {
        v = a->flags5B0.f.b0 * 32 + 0x17;
    } else if (b == 0xFF) {
        v = a->flags5B0.f.b0 * 32 + 0x18;
    } else {
        v = func_0013E0C0(a, b);
        v += a->flags5B0.b & 1;
    }
    r = func_001426C0(a, v);
    if (r == 0) {
        func_0013C360(a, v, 0, 0, 2);
    }
    func_0013E920(a, 1);
    if ((u8)func_0013E750(a) == 2) {
        a->flags5B6.f.b0 = 1;
    }
    return r;
}


#define Actor Actor_0013CBC0
#define Ent Ent_0013CBC0
#define Q Q_0013CBC0
#define P P_0013CBC0
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
s32 func_0013E780(Actor *);
void func_0013E730(Actor *, s32);
s32 func_0013EEE0(Actor *);
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

#undef Actor
#undef Ent
#undef Q
#undef P
