#include "actor.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { u8 pad[0x40]; Vec a, b, c, d; } Ent;
typedef struct { u8 pad[0xA]; u16 hA; u8 bC; u8 pD; u16 hE; } Key;
typedef struct { Vec a, b; f32 m[4][4]; Vec pad; } Buf;
typedef struct { u8 pad[6]; u16 h6; u8 pad8[0x38]; s8 x40[1]; } Arg0;
extern s32 D_00201F2C;
typedef struct { u8 r:7; u8 b7:1; } F7;
extern F7 D_00222A51[];
extern f32 D_001F2170[];
Actor *func_001A5430(void);
Ent *func_0013DC70(Actor *, u8);
void func_00102A60(Vec *, Vec *);
void func_00102A70(f32 *, f32 *);
s32 func_0013EE30(Actor *);
s32 func_001C7A70(Vec *);
void func_001A58A0(f32, f32 *, f32 *, Vec *, Vec *);
f32 func_001C7CA0(f32);
void func_001A5790(Vec *, Vec *, s8 *, Vec *, Vec *);
void func_0013EB70(Actor *, s32);
u8 func_0013EB90(Actor *);
void func_001C79B0(f32 *);
void func_001391B0(Actor *, Ent *, void *);
void func_00156920(Buf *);
typedef struct { u8 pad[0x9A]; u8 t[1]; } A9A;
static inline Ent *getEnt(Actor *a, u8 i) { return func_0013DC70(a, a->unk82[i + 0x18]); }

void func_00139330(Arg0 *arg0, s32 arg1, u8 arg2, Key *arg3, f32 *arg4, s32 arg5) {
    Actor *a;
    Ent *e;
    Vec *v;
    f32 *p;
    s8 *base;
    f32 tmp[16];
    Buf buf;

    a = func_001A5430();
    e = func_0013DC70(a, a->unk82[arg2 + 0x18]);
    base = (s8 *)((s32)arg0 + 0x40) + D_00201F2C * (arg0->h6 * 0x140 + 0x200);
    v = &e->a;
    p = arg4 + arg3->hE + arg3->bC;
    func_00102A60(&e->c, v);
    func_00102A60(&e->d, &e->b);
    if (func_0013EE30(a) != 0) {
        if (func_001C7A70(v) == 0) {
            func_001A58A0(p[0], p + 1, p + 4, v, v + 1);
            v[1].w = func_001C7CA0(v[1].w);
        }
        func_001A5790(v, v + 1, base + ((u8)arg2 + 1) * 0x140 + 0xC0, v, v + 1);
    } else {
        func_001A58A0(p[0], p + 1, p + 4, v, v + 1);
        func_001A5790(v, v + 1, base + ((u8)arg2 + 1) * 0x140 + 0xC0, v, v + 1);
    }
    if (arg5 != 0) {
        func_0013EB70(a, 1);
    } else if (func_0013EB90(a) == 1) {
        if (func_0013EE30(a) != 0) {
            func_001C79B0(tmp);
            func_001391B0(a, e, tmp);
        } else {
            func_001391B0(a, e, a->unk4B0 + arg3->hA * 0x40 + 0x10);
        }
    }
    if (D_00222A51[0].b7) {
        func_00102A60(&buf.a, v);
        func_00102A60(&buf.b, v + 1);
        func_00102A70(&buf.m[0][0], D_001F2170);
        func_00156920(&buf);
    }
}
