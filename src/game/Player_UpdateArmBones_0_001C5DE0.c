#include "actor.h"
void sceVu0CopyMatrix(void *, void *);
void sceVu0MulMatrix(void *, void *, void *);
s8 *Mdl_GetFrameData_0_001715B0(s8 **);
s32 Item_GetType_0_001CCDE0(s32);
extern f32 D_001F2170[];
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;

void Player_UpdateArmBones_0_001C5DE0(Actor *a0) {
    s8 *p;
    s32 i;
    s8 *e;
    s8 **h;
    s8 *o;
    s32 off;
    s8 **l;
    s32 c;
    f32 v[16];

    p = a0->unk518 + 0x180;
    o = *(s8 **)(a0->unk518 + 0x540);
    if (o != NULL) {
        if (Item_GetType_0_001CCDE0(*(s16 *)(o + 0x9C)) == 9 || Item_GetType_0_001CCDE0(*(s16 *)(o + 0x9C)) == 0xC) {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x14C0);
        } else {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x2640);
        }
    }
    o = *(s8 **)(p + 0x3C4);
    if (o != NULL) {
        if (*(u8 *)(p + 0x39C) == 0xA || *(u8 *)(p + 0x39C) == 0xE) {
            sceVu0CopyMatrix(v, D_001F2170);
            v[0] = -1.0f;
            sceVu0MulMatrix(o, *(s8 **)(p + 0x2C) + 0x2640, v);
        } else {
            sceVu0CopyMatrix(o, *(s8 **)(p + 0x2C) + 0x2640);
        }
    }
    o = *(s8 **)(p + 0x3C8);
    if (o != NULL) {
        l = *(s8 ***)(o + 0x84);
        if (l != NULL) {
            h = (s8 **)*l;
            e = Mdl_GetFrameData_0_001715B0(l);
            c = 0;
            i = 0;
            if (i < *(u16 *)(*(s8 **)*h + 0x14)) {
                off = 0;
                do {
                    sceVu0CopyMatrix(e + 0xC0, *(s8 **)(p + 0x2C) + off + 0xC0);
                    ((BF *)(e + 0x1F8))->b5 = c;
                    ((BF *)(e + 0x1F8))->b2 = c;
                    i++;
                    off += 0x140;
                    e += 0x140;
                } while (i < *(u16 *)(*(s8 **)*h + 0x14));
            }
            ((BF *)((s8 *)h + 0x25))->b0 = 1;
        }
    }
}
