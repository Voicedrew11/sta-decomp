#include "m2c.h"
void func_00167740(s32, s32);
extern s32 D_00201E80;
#define SLOT(n) (((s8 ***)&D_00201E80)[n])

static inline s32 isActive(s8 **p) {
    if (p != NULL) {
        return (((u8 *)*p)[0x1D8] & 1) != 0;
    }
    return 0;
}

static inline s8 *find(s32 id) {
    s8 *o = NULL;
    if (isActive(SLOT(2)) && *(s32 *)*SLOT(2) == id) {
        o = *SLOT(2);
    }
    if (isActive(SLOT(3)) && *(s32 *)*SLOT(3) == id) {
        o = *SLOT(3);
    }
    return o;
}

static inline s32 findIdx(s8 *p, s32 k) {
    s32 i;
    s8 *e;
    if (p == NULL) {
        return -1;
    }
    for (i = 0, e = *(s8 **)(p + 0x150); i < *(u16 *)(p + 0x78); i++, e += 0x2C) {
        if (k == *(u16 *)(e + 0x1A) % 100) {
            return i;
        }
    }
    return -1;
}

void func_001B0EB0(s32 a0, s32 a1, s32 a2) {
    s8 *o;
    s32 i;

    o = find(a0);
    i = findIdx(find(a0), a1);
    if (o != NULL && i != -1) {
        func_00167740(*(s32 *)(*(s8 **)(o + 0x190) + i * 8), a2);
    }
}
