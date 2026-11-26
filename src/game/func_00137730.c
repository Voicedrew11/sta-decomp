#include "actor.h"
typedef struct { u8 pad[6]; u16 n; } H;
extern s32 D_00201F2C;
u8 func_0013FC00(Actor *);
s32 func_0013FB90(Actor *, u8, Vec **, Vec **);
void sceVu0AddVector(Vec *, Vec *, Vec *);

void func_00137730(Actor *a, Vec *m) {
    Vec *p[4];
    Vec *q[4];
    u8 i;
    u8 n;
    H *h;
    s8 *e;

    n = func_0013FC00(a);
    m->w = 0.0f;
    for (i = 0; i < n; i++) {
        p[0] = 0;
        q[0] = 0;
        if ((u8)func_0013FB90(a, i, p, q)) {
            sceVu0AddVector(p[0], p[0], m);
        }
    }
    h = *(H **)(a->unk518 + 0x1A8);
    e = (s8 *)((s32)h + 0x40) + D_00201F2C * (h->n * 0x140 + 0x200) + 0xC0;
    sceVu0AddVector((Vec *)(e + 0x1F0), (Vec *)(e + 0x1F0), m);
    i = 1;
    if (i < h->n + 1) {
        e += 0x140;
        do {
        if (!((Flags8 *)(e + 0x138))->f.b6) {
            sceVu0AddVector((Vec *)(e + 0x30), (Vec *)(e + 0x30), m);
        }
            e += 0x140;
            i++;
        } while (i < h->n + 1);
    }
}
