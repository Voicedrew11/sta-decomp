#include "m2c.h"
typedef struct { s8 pad[0xB6]; u8 a, b, c, d; } Sub;
typedef struct { s32 id; s8 pad[0x154]; Sub *sub; s8 pad2[0x1D8-0x15C]; u8 flags; } Obj;
extern s32 D_00201E80;
#define P8 M2C_FIELD(&D_00201E80, Obj ***, 8)
#define PC M2C_FIELD(&D_00201E80, Obj ***, 0xC)
static inline s32 isAct(Obj **p) {
    if (p != NULL) return ((*p)->flags & 1) != 0;
    return 0;
}
static inline Obj *findObj(s32 id) {
    Obj *r = NULL;
    if (isAct(P8) && (*P8)->id == id) r = *P8;
    if (isAct(PC) && (*PC)->id == id) r = *PC;
    return r;
}

s32 MapObj_GetCamera_0_001B1560(s32 id, f32 *a, f32 *b, f32 *c, f32 *d) {
    Obj *o = findObj(id);
    if (o == NULL) return -1;
    *a = o->sub->a;
    *b = o->sub->b;
    *c = o->sub->c;
    *d = o->sub->d;
    return 1;
}
