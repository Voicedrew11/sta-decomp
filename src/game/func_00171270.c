#include "common.h"
typedef union {
    u64 w;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } f;
} F;
typedef struct {
    Mtx m;
    Mtx x40;
    Mtx x80;
    u8 padC0[0x131 - 0xC0];
    u8 x131;
    u8 pad132[2];
    f32 x134;
    F x138;
} E;
typedef struct {
    u8 pad[6];
    u16 x6;
    u8 pad8[0x24 - 8];
    u8 x24a:6;
    u8 x24b:2;
    u8 pad25[0x30 - 0x25];
    Vec x30;
    u8 x40[1];
} H;
void sceVu0CopyMatrix(E *, Mtx *);
void sceVu0AddVector(void *, void *, void *);
f32 func_00171550(E *);
void sceVu0MulMatrix(E *, void *, void *);

void func_00171270(H *h, Mtx *a1, s32 a2) {
    E *b;
    s32 i;
    E *e;
    s32 k;
    F f;
    F par;

    if (h == 0) return;
    b = (E *)((s32)((s32)h + 0x40 + a2 * (h->x6 * 0x140 + 0x200)) + 0xC0);
    k = (u8)h->x24b;
    if (k) h->x24b = k + 0xFF;
    sceVu0CopyMatrix(b, a1);
    sceVu0AddVector(&b->m.m[3], &b->m.m[3], &h->x30);
    b->x134 = func_00171550(b);
    f.w = b->x138.w;
    f.f.b5 = 0;
    f.f.b2 = 0;
    if (f.f.b4) f.f.b5 = 1;
    if (f.f.b1) f.f.b2 = 1;
    b->x138.w = f.w;
    for (i = 1; i < h->x6 + 1; i++) {
        e = &b[i];
        f.w = e->x138.w;
        par.w = b[e->x131].x138.w;
        f.f.b5 = 0;
        f.f.b2 = 0;
        if (f.f.b4) f.f.b5 = 1;
        if (f.f.b1) f.f.b2 = 1;
        if (!f.f.b6) {
            sceVu0MulMatrix(e, &b[e->x131], &e->x80);
            if (par.f.b5) f.f.b5 = 1;
            if (par.f.b2) f.f.b2 = 1;
            e->x138.w = f.w;
        } else {
            sceVu0MulMatrix(e, &e->x40, &e->x80);
            e->x138.w = f.w;
        }
        e->x134 = func_00171550(e);
    }
}
