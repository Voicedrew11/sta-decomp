#include "actor.h"
typedef struct { f32 f[12]; u32 x30; u32 x34; } Out;
typedef struct { u8 pad[0x39C]; u32 lo : 14; u32 m : 4; } S;
extern u16 D_00317230[];
extern u16 D_00317238[];
extern f32 D_0031723C[];
extern f32 D_00317240[];
extern f32 D_00317244[];
extern f32 D_00317248[];
extern f32 D_0031724C[];
extern f32 D_00317250[];
extern f32 D_00317254[];
extern f32 D_00317258[];
extern f32 D_0031726C[];
extern f32 D_00317270[];
extern f32 D_00317274[];
extern f32 D_00317278[];
u8 func_001A9450(void);
s32 func_001CE200(s32);
void func_00123C40(void *, s32, s32);

void func_001C4760(Actor *a, Out *o) {
    S *s;
    u8 r;
    u16 bt;

    u32 m;
    f32 v;

    s = (S *)(a->unk518 + 0x180);
    r = func_001A9450();
#define CL(x) if ((x) > 1.0f) (x) = 1.0f
#define AX(g, n, p) v = (g)[0]; if (v < 0.0f) (n) = -v; else if (v > 0.0f) (p) = v
#define BT(a, b, c, d) bt = *(volatile u16 *)D_00317230; if (bt & 0x400) (a) = 1.0f; else if (bt & 0x800) (b) = 1.0f; \
    bt = *(volatile u16 *)D_00317230; if (bt & 0x100) (c) = 1.0f; else if (bt & 0x200) (d) = 1.0f
    switch (r % 6) {
    case 0:
        o->f[2] = 7.0f * D_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(D_00317248, o->f[2], o->f[3]);
        o->f[1] = 5.0f * D_00317250[0];
        o->f[0] = 5.0f * D_0031724C[0];
        CL(o->f[1]);
        CL(o->f[0]);
        AX(D_00317244, o->f[1], o->f[0]);
        o->f[4] = D_0031726C[0];
        o->f[5] = D_00317270[0];
        o->f[6] = D_00317274[0];
        o->f[7] = D_00317278[0];
        AX(D_0031723C, o->f[9], o->f[8]);
        AX(D_00317240, o->f[10], o->f[11]);
        break;
    case 1:
        o->f[2] = 7.0f * D_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(D_00317248, o->f[2], o->f[3]);
        o->f[1] = 3.0f * D_0031726C[0];
        o->f[0] = 3.0f * D_00317270[0];
        CL(o->f[1]);
        CL(o->f[0]);
        o->f[4] = 3.0f * D_00317250[0];
        o->f[5] = 3.0f * D_0031724C[0];
        CL(o->f[4]);
        CL(o->f[5]);
        AX(D_00317244, o->f[4], o->f[5]);
        o->f[6] = D_00317274[0];
        o->f[7] = D_00317278[0];
        AX(D_0031723C, o->f[9], o->f[8]);
        AX(D_00317240, o->f[10], o->f[11]);
        break;
    case 2:
    case 3:
        o->f[2] = 7.0f * D_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(D_00317248, o->f[2], o->f[3]);
        o->f[1] = 5.0f * D_00317250[0];
        o->f[0] = 5.0f * D_0031724C[0];
        CL(o->f[1]);
        CL(o->f[0]);
        AX(D_00317244, o->f[1], o->f[0]);
        AX(D_0031723C, o->f[4], o->f[5]);
        if (r == 2) {
            AX(D_00317240, o->f[6], o->f[7]);
        } else {
            AX(D_00317240, o->f[7], o->f[6]);
        }
        BT(o->f[8], o->f[9], o->f[10], o->f[11]);
        break;
    case 4:
    case 5:
        o->f[2] = 7.0f * D_00317254[0];
        o->f[3] = 7.0f * D_00317258[0];
        CL(o->f[2]);
        CL(o->f[3]);
        AX(D_00317248, o->f[2], o->f[3]);
        AX(D_0031723C, o->f[1], o->f[0]);
        o->f[4] = 3.0f * D_00317250[0];
        o->f[5] = 3.0f * D_0031724C[0];
        CL(o->f[4]);
        CL(o->f[5]);
        AX(D_00317244, o->f[4], o->f[5]);
        if (r == 4) {
            AX(D_00317240, o->f[6], o->f[7]);
        } else {
            AX(D_00317240, o->f[7], o->f[6]);
        }
        BT(o->f[8], o->f[9], o->f[10], o->f[11]);
        break;
    }
    o->x30 = D_00317238[0];
    o->x34 = D_00317230[0];
    if (func_001CE200(1)) {
        func_00123C40(o, 0, 0x30);
        m = 0x9000;
        if (s->m == 0) m |= 0x2000;
        o->x30 &= ~m;
        o->x34 &= ~m;
    }
    if (func_001CE200(5)) {
        o->x30 &= ~0x8000;
        o->x34 &= ~0x8000;
    }
}
