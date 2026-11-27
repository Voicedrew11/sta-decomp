#include "m2c.h"
typedef struct { s8 pad[0x1C]; u16 key; s8 pad2[3]; s8 v; s8 pad3[0xE]; } Ent;
typedef struct { s32 id; s8 pad[0x68]; u16 n; s8 pad1[0x134-0x6E]; Ent *ents; s8 pad2[0x1D8-0x138]; u8 flags; } Obj;
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
static inline Ent *findE(Obj *obj, s32 key) {
    s32 i;
    if (obj == NULL) return NULL;
    for (i = 0; i < obj->n; i++) {
        if (key == obj->ents[i].key) return &obj->ents[i];
    }
    return NULL;
}

s32 MapObj_SetNodeFlag_0_001B16E0(s32 arg0, s32 arg1, s8 arg2) {
    Ent *e = findE(findObj(arg0), arg1);
    if (e == NULL) return -1;
    e->v = arg2;
    return 1;
}
