#include "m2c.h"
typedef struct { u16 a, b, c, n; u8 pad[0x38]; s8 data[1]; } Hd;
typedef struct { u8 a:6; u8 en:1; u8 b:1; } Fl;
typedef struct { u8 pad[0x2A]; u8 x2A; } E;
typedef struct {
    u8 pad0[0x80];
    u8 n;
    u8 pad81[0x433];
    E *tbl[0x19];
    s8 *x518;
    u8 pad51C[4];
    u8 list[16];
} A;
extern s32 D_00201F2C;

void func_001A8510(A *a0, u8 a1) {
    Hd *h;
    s8 *d;
    s32 off;
    Fl *p;
    Fl *q;
    u8 i;
    u8 cnt;
    off = (a0->tbl[a1]->x2A + 1) * 0x140;
    h = **(Hd ***)(a0->x518 + 0xB0);
    d = h->data;
    q = (Fl *)(d + !D_00201F2C * (h->n * 0x140 + 0x200));
    p = (Fl *)(d + D_00201F2C * (h->n * 0x140 + 0x200) + off + 0x1F8);
    if (p->en || ((Fl *)((s8 *)q + off + 0x1F8))->en) {
        p->en = 0;
        ((Fl *)((s8 *)q + off + 0x1F8))->en = 0;
        cnt = a0->n;
        for (i = 0; i < cnt; i++) {
            if (a0->list[i] == a1) {
                for (; i < a0->n - 1; i++) {
                    a0->list[i] = a0->list[i + 1];
                }
                a0->n--;
                return;
            }
        }
    }
}
