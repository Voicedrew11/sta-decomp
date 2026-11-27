#include "m2c.h"
typedef struct { u8 p:3; u8 v:1; } BF3;
typedef struct { u8 p:2; u8 v:1; } BF2;
typedef struct { u8 p:7; u8 v:1; } BF7;
typedef struct { u8 p:2; u8 v:2; } BF2_2;
void MapObj_SetAnimFrame_0_001B87C0(s8 *, u32, s32, s32, f32, f32);
u32 Rand_Next_3_0015ED20(void);

void Trap_SetState_0_001BA850(s8 *p, u32 i, f32 dt) {
    s8 *e30;
    s8 *e;
    s8 *t;
    s8 ****pp;

    e30 = *(s8 **)(p + 0x138) + i * 0x30;
    e = *(s8 **)(p + 0x180) + (i << 7);
    t = *(s8 **)(p + 0x170) + (*(u16 *)(e30 + 0x18) << 6);
    if ((*(u8 *)(e + 0x50) & 3) && ((BF3 *)(t + 0x12))->v) {
        pp = *(s8 *****)(e + 0x44);
    } else {
        pp = *(s8 *****)(e + 0x40);
    }
    if (pp == NULL || *pp == NULL) {
        return;
    }
    if (**pp == NULL || ***pp == NULL || *(u16 *)(***pp + 0x16) <= 0) {
        return;
    }
    if (!((BF7 *)(e + 0x52))->v || ((BF2_2 *)(e30 + 0x24))->v != 2) {
        return;
    }
    if (((BF2 *)(e + 0x50))->v) {
        return;
    }
    *(f32 *)(e + 0x5C) -= dt;
    if (*(f32 *)(e + 0x5C) <= 0.0f) {
        MapObj_SetAnimFrame_0_001B87C0(p, i, 0, 0, 0.0f, 1.0f);
        *(f32 *)(e + 0x5C) = 1.0f + 2.0f * (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF));
    }
}
