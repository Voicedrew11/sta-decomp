#include "m2c.h"
typedef struct { u8 pad[0x20]; u16 x20; u8 pad2[0x30 - 0x22]; } Ent;
typedef struct { s32 id; u8 pad[0x72]; u16 x76; u8 pad2[0x148 - 0x78]; Ent *x148; u8 pad3[0x18C - 0x14C]; u32 *x18C; u8 pad4[0x1D8 - 0x190]; u8 x1D8; } O;
extern s32 D_00201E80;
#define TB ((O ***)&D_00201E80)
static inline O *get(s32 arg0) {
    s32 var_v1;
    s32 var_v1_2;
    O *t;
    O *t2;
    O *r;
    r = NULL;
    if (TB[2] != NULL) {
        var_v1 = ((*TB[2])->x1D8 & 1) != 0;
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        t = *TB[2];
        if (t->id == arg0) {
            r = t;
        }
    }
    var_v1_2 = TB[3] != NULL ? ((*TB[3])->x1D8 & 1) != 0 : 0;
    if (var_v1_2 != 0) {
        t2 = *TB[3];
        if (t2->id == arg0) {
            r = t2;
        }
    }
    return r;
}

u16 func_001B0C70(s32 arg0, s32 arg1) {
    O *p;
    Ent *e;
    s32 i;

    p = get(arg0);
    if (p != NULL) {
        for (i = 0; i < p->x76; i++) {
            if (arg1 == p->x148[i].x20 % 100) {
                return p->x18C[i];
            }
        }
    }
    return 0;
}
