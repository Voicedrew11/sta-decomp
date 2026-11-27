#include "common.h"
typedef struct { s32 type; union { s32 i; f32 f; } v; } V;
typedef struct { char pad[0xD8]; V e[1]; } B;
typedef struct { char p0[8]; u8 idx; char p9[7]; s32 type; char p14[4]; union { s8 c; u8 uc; s16 h; u16 uh; s32 i; u32 u; f32 f; } v; } A;
extern B *D_00201FA8;
void ScrCmd_SetVar_1_00164DC0(A *a) {
    V *e = &D_00201FA8->e[a->idx];
    e->type = a->type;
    switch (e->type) {
    case 0: e->v.i = a->v.c; break;
    case 1: e->v.i = a->v.uc; break;
    case 2: e->v.i = a->v.h; break;
    case 3: e->v.i = a->v.uh; break;
    case 4: e->v.i = a->v.i; break;
    case 5: e->v.i = a->v.u; break;
    case 6: e->v.f = a->v.f; break;
    }
}
