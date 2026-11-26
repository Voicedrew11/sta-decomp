#include "common.h"
typedef struct { char p0[8]; s32 o8; char pc[4]; s32 o10; char p14[0xC]; u16 x20, x22, x24, x26; } Hd;
typedef struct { s32 x0; Hd *h; void (*f8)(); void (*fC)(); char *p10; s32 x14; char *p18; s32 x1C; char p20[0x30]; f32 f50, f54, f58, f5C, f60, f64, f68, f6C; } S;
void func_001E41A8();
void func_001E4460();
void func_001E40D0(S *s) {
    Hd *h = s->h;
    char *a, *b;
    f32 t;
    a = (char *)h + h->o8;
    b = (char *)h + h->o10;
    s->f8 = func_001E41A8;
    s->fC = func_001E4460;
    s->x1C = 1;
    s->p10 = a;
    s->p18 = b;
    t = (f32)h->x20 / 1000.0f;
    s->f60 = t; s->f50 = t;
    t = (f32)(h->x20 + h->x24) / 1000.0f;
    s->f68 = t; s->f58 = t;
    t = (f32)h->x22 / 1000.0f;
    s->f5C = t; s->f54 = t;
    t = (f32)(h->x22 + h->x26) / 1000.0f;
    s->f6C = t; s->f64 = t;
}
