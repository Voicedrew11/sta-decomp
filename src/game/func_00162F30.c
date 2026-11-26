#include "m2c.h"
typedef struct { u16 prev; u16 next; u16 sib; } N;
typedef struct { u8 pad[0x114]; u8 b0:1; u8 b1:1; u8 b2:1; u8 pad115[0xB]; } O;
typedef struct { u8 pad[0x14]; u8 c0:1; u8 c1:1; u8 c2:1; u8 c3:1; u8 c4:1; u8 pad15[0x2F]; f32 f44; } A;
typedef struct { u8 pad[8]; u16 x8; u16 xA; } H;
extern O *D_00201FC0;
extern N *D_00201FD4;
extern u16 D_00201FD8;
u16 func_0016B230(void);
u16 func_0016B0F0(u16, s32);
s32 func_00161060(u16, s32, s32, s32, A *, H *, s32);
void func_0016AF40(u16, u16, s32);

s32 func_00162F30(s32 p0, s32 n, s32 p2, A *a, s32 p4, H *h, s32 p6) {
    u16 prev = 0xFFFF;
    s32 m = n;
    s32 rest = 0;
    u16 k;
    s32 o;
    u16 id;
    u16 nx;
    if (n == 0) return 0;
    if (a->f44 == 0.0f && 0 < h->xA) return 0;
    if (D_00201FD8 < n) {
        rest = n - D_00201FD8;
        n = D_00201FD8;
    }
    if (func_0016B230() < n) {
        rest += n - func_0016B230();
        m = func_0016B230();
    }
    k = h->x8;
    while (k != 0xFFFF) {
        if (D_00201FC0[k].b2) {
            o = (u16)k * sizeof(N);
            nx = ((N *)((u8 *)D_00201FD4 + o))->sib;
            if (prev != 0xFFFF) {
                D_00201FD4[prev].sib = nx;
            } else {
                h->x8 = nx;
            }
            ((N *)((u8 *)D_00201FD4 + o))->sib = 0xFFFF;
            k = nx;
        } else {
            prev = k;
            k = D_00201FD4[k].sib;
        }
    }
    while (m != 0) {
        id = func_0016B0F0(h->x8, a->c4);
        if (id == 0xFFFF) {
            rest = m;
            break;
        }
        if (func_00161060(id, p6, p0, p2, a, h, p4) == 0) {
            func_0016AF40(h->x8, id, a->c4);
            rest = m;
            break;
        }
        h->x8 = id;
        h->xA++;
        D_00201FC0[id].b0 = 1;
        m--;
    }
    return rest;
}
