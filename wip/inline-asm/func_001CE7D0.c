#include "m2c.h"
typedef struct { u8 pad0[0x394]; s8 x394; u8 pad1; s8 x396; u8 pad2; s16 x398; } Obj;
typedef struct { u8 pad0[0x80]; s16 x80; s16 x82; u8 pad1[0x10]; u8 x94; u8 pad2[0xB]; u8 col[10][4]; } V;
typedef struct { u8 pad0[4]; u16 x4; u8 pad1[0x1A]; u16 x20; u8 pad2[0x1D]; u8 x3F; u8 pad3[0x50]; } E;
typedef struct { u8 r, g, b, a; } Col;
V *func_001C9BA0(void);
E *func_001AFC90(void);
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

void func_001CE7D0(Obj *a0, s32 a1) {
    u16 *q = (u16 *)((u8 *)a0 + 0x460);
    V *v;
    E *t;
    E *e;
    s32 idx;
    s32 m;
    u16 h;
    Col c;

    v = func_001C9BA0();
    t = func_001AFC90();
    if (a1) {
        a0->x398 = 0;
    }
    idx = (v->x94 & 1) ? v->x82 : v->x80;
    if (idx == -1 || idx == 0) {
        a0->x394 = 1;
        if (a1) {
            a0->x396 = 0;
        } else {
            if (a0->x396 < 0) {
                a0->x396 = 0;
            }
            if (a0->x394 < a0->x396) {
                a0->x396 = a0->x394;
            }
        }
        return;
    }
    e = &t[idx];
    c = ((Col *)((u8 *)v + 0xA0))[idx];
    m = cls(e->x20);
    switch (m) {
    case 0:
        h = e->x4;
        if (h >= 30) {
            a0->x394 = 1;
        } else if (h >= 15) {
            a0->x394 = 2;
        } else {
            a0->x394 = 3;
        }
        a0->x394 += (s8)(q[1] / 300);
        if (a0->x394 > 6) {
            a0->x394 = 6;
        }
        if (a1) {
            a0->x396 = 0;
        } else {
            if (a0->x396 < 0) {
                a0->x396 = 0;
            }
            if (a0->x394 < a0->x396) {
                a0->x396 = a0->x394;
            }
        }
        break;
    case 1:
        a0->x394 = e->x3F;
        a0->x396 = c.a;
        break;
    case 2:
        a0->x394 = e->x3F;
        a0->x396 = 0;
        break;
    }
}
