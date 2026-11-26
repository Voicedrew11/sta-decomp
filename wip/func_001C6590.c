#include "actor.h"
void func_001C7020(f32, u16, s32, f32, f32);
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

void func_001C6590(u8 a0) {
    s8 *p;
    u16 base;
    s32 k;
    f32 g;
    f32 f;
    f32 s;
    s8 *q; Flags8 *fl;

    p = get();
    k = 0;
    g = 0.0f;
    f = g;
    s = 1.0f;
    if (p != NULL) {
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            *(s8 *)(p + 0x3D4) = 0;
            k = 2;
            func_001AD0C0(SEL(p), 0);
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 1;
            func_001AD1C0(SEL(p), 2);
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            *(s8 *)(p + 0x3D4) = 0;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            func_001AD0C0(SEL(p), 0);
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
            *(s8 *)(p + 0x3CF) = 4;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 5;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                if (*(u8 *)(p + 0x39C) == 10) {
                    func_001AD1C0(*(s32 *)(p + 0x3C4), 5);
                } else {
                    func_001AD1C0(*(s32 *)(p + 0x3C4), 4);
                }
            } else {
                func_001AD1C0(*(s32 *)(p + 0x3C0), 4);
            }
            break;
        case 6:
            *(s8 *)(p + 0x3CF) = 3;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 6;
            *(s8 *)(p + 0x3D4) = 0;
            func_001AD1C0(SEL(p), 3);
            break;
        case 7:
            *(s8 *)(p + 0x3CF) = 2;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 7;
            *(s8 *)(p + 0x3D4) = 0;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            func_001AD0C0(SEL(p), 0);
            break;
        case 8:
            *(s8 *)(p + 0x3CF) = 0;
            g = 30.0f;
            *(s8 *)(p + 0x3CD) = 0;
            *(s8 *)(p + 0x3D5) = 0;
            *(s8 *)(p + 0x3D4) = 0;
            q = *(s8 **)(p + 0x3C0);
            f = -1.0f;
            s = 2.0f;
            base = 0;
            if (q != NULL) { Flags8 *fl = (Flags8 *)(q + 0xA8); if (!fl->f.b5) fl->f.b5 = 1; }
            break;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        func_001C7020(f, base, k, g, s);
    }
}
