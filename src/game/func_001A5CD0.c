#include "m2c.h"
void sceVu0AddVector(s8 *, s8 *, s32);
void func_0013B960(s8 *, s32);
extern s8 **D_004A4570[];

void func_001A5CD0(s32 arg0) {
    s32 i;
    s8 **o;
    s8 ***pp;
    s8 *a;
    s8 *t;

    pp = D_004A4570;
    for (i = 0; i < 0x81; i++) {
        o = *pp;
        if (o != NULL) {
            a = *o;
            if ((M2C_FIELD(a, u8 *, 0x5A0) & 1) && ((u64)((s64)M2C_FIELD(a, u8 *, 0x5A0) << 61) >> 63)) {
                t = M2C_FIELD(a, s8 **, 0x518);
                sceVu0AddVector(t, t, arg0);
                a = M2C_FIELD(*o, s8 **, 0x518) + 0x10;
                sceVu0AddVector(a, a, arg0);
                a = M2C_FIELD(*o, s8 **, 0x518) + 0x1C0;
                sceVu0AddVector(a, a, arg0);
                a = M2C_FIELD(t, s8 **, 0x190) + 0x100;
                sceVu0AddVector(a, a, arg0);
                a = M2C_FIELD(*o, s8 **, 0x518) + 0x90;
                sceVu0AddVector(a, a, arg0);
                func_0013B960(*o, arg0);
            }
        }
        pp++;
    }
}
