#include "obj3d.h"
void func_001029D0(s32, s8 *, s8 *, s32);
void func_00102A60(s32, s8 *);
extern s8 D_003139A0[];

s32 func_001AC0F0(s32 arg0, u16 arg1, s32 arg2) {
    s32 i;
    Obj3D *p;
    s32 j;
    Obj3D *row;

    func_00102A60(arg2, D_003139A0);
    if (arg1 == 0) {
        return 0;
    }
    for (i = 0, row = D_004AE370[0]; i < 2; i++, row += 64) {
        for (p = row, j = 0; j < 0x40; j++, p++) {
            if (p->x9E == 0 && p->xA9.f.b2 == 0 && p->x8C != NULL && *p->x8C != NULL
                && p->x9C != -1 && **p->x8C == arg0 && p->xAA == arg1) {
                func_001029D0(arg2, (s8 *)p + 0x40, (s8 *)p + 0x70, i);
                return 1;
            }
        }
    }
    return 0;
}
