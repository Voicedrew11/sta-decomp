#include "common.h"
typedef struct { u8 pad[0x38]; void *x38; void *x3C; } El;
typedef struct {
    u8 pad[0x10]; s8 **x10; u8 pad14[6]; u16 x1A; u8 pad1C[6]; s16 x22; s32 x24;
    u8 pad28[4]; void *x2C; u8 pad30[0xC]; Flags8 x3C;
} H;
void func_00128580(s32, void *);
void func_00177570(void *);
void func_001531A0(void *, H **);

void func_00170250(s32 *a0, H **a1) {
    H *h;
    s8 **q;
    El *p;
    s32 i;
    h = *a1;
    q = h->x10;
    p = (El *)(*q + h->x24);
    h->x22--;
    if ((*a1)->x22 <= 0) {
        if ((*a1)->x2C && (*a1)->x3C.f.b3) {
            func_00128580(*a0, (*a1)->x2C);
        }
        for (i = 0; i < (*a1)->x1A; i++, p++) {
            if (p->x38) func_00177570(p->x38);
            if (p->x3C) func_00177570(p->x3C);
        }
        func_001531A0(a0 + 1, a1);
        if (!(*a1)->x3C.f.b5) {
            func_00128580(*a0, q);
        }
    }
}
