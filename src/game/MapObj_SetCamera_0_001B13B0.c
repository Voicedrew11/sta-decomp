#include "m2c.h"
typedef struct { s32 id; u8 pad[0x154]; u8 *p; } Obj;
typedef struct { u8 pad[0x1D8]; u8 f; } Inner;
extern s32 D_00201E80;
#define C (((Obj ***)&D_00201E80)[2])
#define D (((Obj ***)&D_00201E80)[3])
static inline s32 IS(Obj **p) { if (p != NULL) return (((Inner *)*p)->f & 1) != 0; else return 0; }
static inline s32 IS2(Obj **p) { s32 r = 0; if (p != NULL) r = (((Inner *)*p)->f & 1) != 0; return r; }

s32 MapObj_SetCamera_0_001B13B0(s32 arg0, f32 a, f32 b, f32 c, f32 d) {
    Obj *v0 = NULL;
    s32 v1;
    if (C != NULL) {
        v1 = (((Inner *)*C)->f & 1) != 0;
    } else {
        v1 = 0;
    }
    if (v1 != 0) {
        if ((*C)->id == arg0) v0 = *C;
    }
    v1 = D ? (((Inner *)*D)->f & 1) != 0 : 0;
    if (v1 != 0) { if ((*D)->id == arg0) v0 = *D; }
    if (v0 == NULL) return -1;
    v0->p[0xB6] = a;
    v0->p[0xB7] = b;
    v0->p[0xB8] = c;
    v0->p[0xB9] = d;
    return 1;
}
