#include "m2c.h"
typedef struct { u8 pad[0x40]; u16 on; u16 v; u8 pad2[0x90-0x44]; } E;
typedef struct { u8 pad[0x395]; s8 max; u8 p3; s8 cnt; u8 p4[2]; s16 timer; u8 p5[0x460-0x39C]; u8 sub[0x10]; } O;
s8 *func_001C9BA0(void);
E *func_001AFC90(void);

void func_001CE660(O *arg0, s32 arg1) {
    s8 *q;
    s8 *a;
    E *b;
    E *e;
    s16 idx;
    u16 v;

    q = arg0->sub;
    a = func_001C9BA0();
    b = func_001AFC90();
    idx = M2C_FIELD(a, s16 *, 0x8C);
    if (idx == -1) {
        arg0->timer = 0;
        arg0->max = 0;
        arg0->cnt = 0;
        return;
    }
    e = &b[idx];
    if (e->on == 0) {
        arg0->timer = 0;
        arg0->max = 0;
        arg0->cnt = 0;
        return;
    }
    v = e->v;
    if (v >= 100) {
        arg0->max = 1;
    } else if (v >= 50) {
        arg0->max = 2;
    } else {
        arg0->max = 3;
    }
    arg0->max += (s8)(M2C_FIELD(q, u16 *, 0xE) / 300);
    if (arg0->max > 6) {
        arg0->max = 6;
    }
    if (arg1) {
        arg0->timer = 0;
        arg0->cnt = 0;
        return;
    }
    if (arg0->cnt < 0) {
        arg0->cnt = 0;
    }
    if (arg0->max < arg0->cnt) {
        arg0->cnt = arg0->max;
    }
}
