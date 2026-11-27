#include "m2c.h"
typedef union { s8 c; u8 uc; s16 s; u16 us; s32 i; u32 u; f32 f; } Val;
typedef struct { s32 type; Val v; } Var;
typedef struct { u8 pad[0xC]; u16 c; u16 e; } Hdr;

void Script_StoreLocal_0_00165260(s32 a0, Var *src, Hdr *h, s32 a3, s32 v) {
    u16 t = (a3 & 0xFFFF00) >> 8;
    u32 sz = (v + 7) & ~3;
    Val *d;
    if ((u32)h->e < sz) h->e = sz;
    d = (Val *)(v + (h->c + (s32)h) + 0x158);
    switch (t) {
    case 0: d->c = src->v.c; break;
    case 1: d->uc = src->v.uc; break;
    case 2: d->s = src->v.s; break;
    case 3: d->us = src->v.us; break;
    case 4: d->i = src->v.i; break;
    case 5: d->u = src->v.u; break;
    case 6: d->f = src->v.f; break;
    }
}
