#include "m2c.h"
typedef struct { u8 pad[0x60]; f32 a[4]; f32 b[4]; f32 c[4]; } Bone;
typedef struct {
    f32 m[8][4];
    u8 pad80[0xC];
    s32 **pp;
    u8 pad8c[0x9C - 0x90];
    s16 bone;
    s16 busy;
    u8 padA0[0xA9 - 0xA0];
    u8 f0:1; u8 local:1; u8 hide:1; u8 rest:5;
    u16 id;
    u8 padAC[0xD0 - 0xAC];
} Obj;
void func_001027E0(void *, void *, void *);
void func_001029D0(void *, void *, void *);
void func_001029E8(void *, s32, void *, u32);
void func_00173FD0(void *, void *, void *, void *);
extern Bone *D_002022B0;
extern Obj D_004AE370[2][64];
static inline void update(Obj *o) {
    f32 tmp[16] __attribute__((aligned(16)));
    Bone *bones = D_002022B0;
    if (o != NULL && o->bone != -1) {
        if (o->local) {
            func_00173FD0(o, o->m[4], o->m[5], o->m[6]);
        } else {
            Bone *b = &bones[o->bone];
            func_00173FD0(tmp, b->a, b->b, b->c);
            func_00173FD0(o, o->m[4], o->m[5], o->m[6]);
            func_001027E0(o, o, tmp);
        }
        func_001029D0(o->m[3], o->m[3], o->m[7]);
    }
}

s32 func_001ABF70(s32 key, s32 arg1, s32 arg2) {
    u32 id = arg1 & 0xFFFF;
    s32 j, i;
    Obj *o;
    Obj *row;
    if (id == 0) return 0;
    for (i = 0, row = D_004AE370[0]; i < 2; i++, row += 64) {
        for (o = row, j = 0; j < 64; j++, o++) {
            if (o->busy == 0 && o->hide == 0 && o->pp != NULL && *o->pp != NULL && o->bone != -1 && **o->pp == key && o->id == id) {
                func_001029E8(o->m[4], arg2, o->m[7], id);
                update(o);
                return 1;
            }
        }
    }
    return 0;
}
