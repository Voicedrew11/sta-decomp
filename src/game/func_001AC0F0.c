#include "m2c.h"
typedef struct { u8 pad:2; u8 b:1; u8 rest:5; } BF;
typedef struct { s8 pad[0x8C]; s32 **p8C; s8 pad2[0x9C-0x90]; s16 h9C; s16 h9E; s8 pad3[0xA9-0xA0]; BF bA9; u16 hAA; s8 pad5[0xD0-0xAC]; } Obj;
void func_001029D0(s32, s8 *, s8 *, s32);
void func_00102A60(s32, s8 *);
extern s8 D_003139A0[];
extern Obj D_004AE370[2][64];

s32 func_001AC0F0(s32 arg0, u16 arg1, s32 arg2) {
    s32 i;
    Obj *p;
    s32 j;
    Obj *row;

    func_00102A60(arg2, D_003139A0);
    if (arg1 == 0) {
        return 0;
    }
    for (i = 0, row = D_004AE370[0]; i < 2; i++, row += 64) {
        for (p = row, j = 0; j < 0x40; j++, p++) {
            if (p->h9E == 0 && p->bA9.b == 0 && p->p8C != NULL && *p->p8C != NULL
                && p->h9C != -1 && **p->p8C == arg0 && p->hAA == arg1) {
                func_001029D0(arg2, (s8 *)p + 0x40, (s8 *)p + 0x70, i);
                return 1;
            }
        }
    }
    return 0;
}
