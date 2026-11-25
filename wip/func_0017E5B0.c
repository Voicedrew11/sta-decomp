#include "m2c.h"
typedef struct { s8 pad[0x1A]; u16 key; s8 pad2[0x10]; } Ent;
typedef struct { s32 a; s32 b; } Pair;
typedef struct { s32 id; s8 pad[0x74]; u16 n; s8 pad1[0x150-0x7A]; Ent *ents; s8 pad2[0x190-0x154]; Pair *tbl; s8 pad3[0x1D8-0x194]; u8 flags; } Obj;
extern s32 D_00201E80;
void func_00167290(s32, f32);
typedef struct { s32 p0, p4, id, pC, key, p14; f32 f; } Arg;
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
static inline s32 findIdx(Obj *obj, s32 key) {
    s32 i;
    if (obj == NULL) return -1;
    for (i = 0; i < obj->n; i++) {
        if (key == obj->ents[i].key % 100) return i;
    }
    return -1;
}

void func_0017E5B0(Arg *arg0) {
    f32 f = arg0->f;
    s32 id = arg0->id;
    s32 key = arg0->key;
    Obj *o = findObj(id);
    s32 i = findIdx(findObj(id), key);
    if (o != NULL && i != -1) {
        func_00167290(o->tbl[i].a, f);
    }
}
