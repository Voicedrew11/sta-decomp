#include "common.h"
s32 func_001CC0C0(s32, s32);
u32 func_0015ED20(void);
void sceVu0CopyVector(Vec *, void *);
void *func_001AE900(s32, s16, Vec *, Vec *, s32, s32);

void func_001A5990(s8 *a0) {
    u16 *p;
    s32 i;
    s32 id;
    u16 v;
    Vec a;
    Vec b;
    p = (u16 *)(*(s8 **)(a0 + 0x4B0) + 0x250);
    for (i = 0; i < 4; i++) {
        id = p[8];
        v = p[0xC];
        if (id < 0x400 && v != 0 && func_001CC0C0(id, 1) && func_0015ED20() % 100 < v) {
            sceVu0CopyVector(&a, *(void **)(a0 + 0x518));
            sceVu0CopyVector(&b, *(s8 **)(a0 + 0x518) + 0x20);
            a.y -= 100.0f;
            func_001AE900(*(s32 *)(a0 + 0x4A8), id, &a, &b, 1, 1);
            return;
        }
        p++;
    }
}
