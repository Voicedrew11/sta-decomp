/* the FOURCC literal lives in .rodata */
#pragma readonly_strings on
#include "obj3d.h"
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H;
typedef struct { u8 pad[0x10]; H h; } Ch;
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))
extern s8 D_001FDA30[];
Ch *Node_FindById_2_0014DCD0(s32, s32);

static inline void fix(Obj3D *o) {
    Ch *c;
    if (o->x9C != -1 && o->xA8.f.b0) {
        o->x88 = 0;
        c = Node_FindById_2_0014DCD0(*((s32 **)***(s32 ****)o->x84)[4], "CAPS"[0] | ("CAPS"[1] << 8) | ("CAPS"[2] << 16) | ("CAPS"[3] << 24));
        if (c != NULL) {
            o->x88 = (s32)DATA((H *)((s32)c + 0x10));
        }
    }
}

void ItemObj_BindCaps_1_001ADD30(void) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        fix(&D_004AE370[0][i]);
        fix(&D_004AE370[1][i]);
    }
    for (i = 0; i < 0x10; i++) {
        fix(&D_004AC970[0][i]);
        fix(&D_004AC970[1][i]);
    }
    for (i = 0; i < 4; i++) {
        fix(&D_004AC630[i]);
    }
}
