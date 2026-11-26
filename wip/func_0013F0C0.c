#include "actor.h"
typedef struct { u8 pad[0x15C]; u16 x15C; u8 pad2[2]; Flags8 f; u8 pad3[0x170 - 0x161]; } E;
typedef struct { u8 pad[0x20]; u16 x20; } I;
#define CLAMP(x, hi) x = (x < 0) ? 0 : x; x = (x > (hi)) ? (hi) : x

static inline void add(Actor *a, u8 k, u16 d) {
    E *e;
    s32 v;
    e = &((E *)a->unk51C)[k];
    v = e->x15C + d;
    CLAMP(v, ((I **)&a->unk4B4)[k]->x20);
    e->x15C = v;
}

void func_0013F0C0(Actor *a, u8 k) {
    E *e;
    I **ip;
    s32 v;
    s32 m;

    e = &((E *)a->unk51C)[k];
    ip = &((I **)&a->unk4B4)[k];
    e->f.f.b0 = 0;
    e->f.f.b2 = 0;
    m = (*ip)->x20;
    e = &((E *)a->unk51C)[k];
    v = e->x15C - m;
    CLAMP(v, m);
    e->x15C = v;
    add(a, k, (u16)m >> 1);
}
