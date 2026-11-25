#include "actor.h"
s32 func_001CCD90(s32);
s32 func_001CC390(s16);
void func_001C7020(f32, u16, s32, f32, f32);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

void func_001C6D40(u8 a0) {
    s8 *p;
    s32 k;
    f32 f;
    f32 s;
    s32 i;
    s32 n;
    f32 c = 0.01f;
    u16 base;

    p = get();
    k = 0;
    f = 0.0f;
    s = 1.0f;
    if (p != NULL) {
        i = (s16)func_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1);
        if (i != -1) {
            n = func_001CC390(i);
        } else {
            n = 0;
        }
        if (n > 3) {
            n += 25;
        }
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            k = 2;
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 2;
            } else {
                *(s8 *)(p + 0x3CD) = 4;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 1;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 4;
            } else {
                *(s8 *)(p + 0x3CD) = 2;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 5:
            *(s8 *)(p + 0x3D5) = 8;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            break;
        }
        if (s < 0.25f) {
            s = 0.25f;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        func_001C7020(f, base, k, 0.0f, s);
    }
}
