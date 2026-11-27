#include "m2c.h"
typedef union { s8 c; u8 uc; s16 s; u16 us; s32 i; u32 u; f32 f; } Val;
typedef struct { s32 type; Val v; } Var;
extern s8 *D_00201FA8;
Val *Script_GetArgPtr_2_00165130(s8 *, u8);

void ScrCmd_GetVar_1_00164CE0(s8 *a0) {
    Var *e = (Var *)(D_00201FA8 + *(s32 *)(a0 + 8) * 8 + 0xD8);
    s32 t = e->type;
    Val *d = Script_GetArgPtr_2_00165130(a0, 2);
    switch (t) {
    case 0: d->c = e->v.c; break;
    case 1: d->uc = e->v.uc; break;
    case 2: d->s = e->v.s; break;
    case 3: d->us = e->v.us; break;
    case 4: d->i = e->v.i; break;
    case 5: d->u = e->v.u; break;
    case 6: d->f = e->v.f; break;
    }
}
