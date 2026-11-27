#include "m2c.h"
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } BF8;
void Mdl_ResetBones_0_00171610(s8 *, s8 *);

void MapObj_ResetBones_0_001BAAA0(s8 *p) {
    s32 i;
    s8 *e;
    s8 *t;
    s8 *m;

    for (i = 0; i < *(u16 *)(p + 0x6E); i++) {
        e = *(s8 **)(p + 0x180) + (i << 7);
        t = *(s8 **)(p + 0x170) + (*(u16 *)(*(s8 **)(p + 0x138) + i * 0x30 + 0x18) << 6);
        if ((*(u8 *)(e + 0x50) & 3) && ((BF8 *)(t + 0x12))->b3) {
            m = *(s8 **)(e + 0x44);
        } else {
            m = *(s8 **)(e + 0x40);
        }
        Mdl_ResetBones_0_00171610(m, e);
    }
}
