#include "m2c.h"
typedef struct { u8 pad0[0x394]; s8 x394; u8 pad1; s8 x396; u8 pad2; s16 x398; u8 pad3[2]; u8 x39C; } Obj;
typedef struct { u8 pad0[0x80]; s16 x80[2]; u8 pad1[0x10]; u8 x94; } V;
typedef struct { u8 pad0[4]; u16 x4; u8 pad1[0x8A]; } E;
V *func_001C9BA0(void);
E *func_001AFC90(void);
static inline f32 u2f(u32 x) { return x; }
static inline s32 cls(s32 x) {
    u32 t;
    asm("addi %0, %1, -7" : "=r"(t) : "r"(x));
    switch (t) {
    case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        return 1;
    case 2: case 12:
        return 2;
    }
    return 0;
}

void func_001CE4B0(Obj *a0) {
    u16 *q = (u16 *)((u8 *)a0 + 0x460);
    V *v;
    E *t;
    s32 idx;
    u32 h;

    v = func_001C9BA0();
    t = func_001AFC90();
    if (cls(a0->x39C) == 0) {
        idx = v->x80[v->x94 & 1];
        if (idx == -1 || idx == 0) {
            h = (u16)3;
        } else {
            h = t[idx].x4;
        }
        if (a0->x396 < a0->x394) {
            if (a0->x398 > (s32)((0.3f + 0.05f * h - 0.00004f * (q[3] * (u16)h)) * 30.0f)) {
                a0->x396++;
                a0->x398 = 0;
            }
            a0->x398++;
        }
    }
}
