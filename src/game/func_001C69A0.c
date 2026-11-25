#include "actor.h"
s32 func_001CCD90(s32);
s32 func_001CC390(s16);
void func_001C7020(f32, f32, u16, s32, f32);
void func_001AD0C0(s32, s32);
void func_001AD1C0(s32, s32);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}
#define SEL(p) ((*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) ? *(s32 *)(p + 0x3C4) : *(s32 *)(p + 0x3C0))

void func_001C69A0(u8 a0) {
    s8 *p;
    f32 g;
    f32 f;
    f32 s;
    s32 i;
    s32 n;
    u16 base;
    f32 c = 0.01f;
    s32 k;

    p = get();
    k = 0;
    f = g = 0.0f;
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
            func_001AD0C0(SEL(p), 0);
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 1;
            s -= n * c;
            func_001AD1C0(SEL(p), 2);
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 2;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            func_001AD0C0(SEL(p), 3);
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 3;
            k = 2;
            func_001AD0C0(SEL(p), 0);
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            func_001AD1C0(SEL(p), 1);
            break;
        case 5:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 6;
            func_001AD1C0(SEL(p), 3);
            break;
        case 6:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            g = 5.0f;
            k = 1;
            func_001AD0C0(SEL(p), 0);
            break;
        }
        if (s < 0.25f) {
            s = 0.25f;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        func_001C7020(f, g, base, k, s);
    }
}
