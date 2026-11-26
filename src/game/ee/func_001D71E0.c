#include "common.h"
typedef struct { u8 a, b, c, d; } T;
typedef struct { char p0[0x102]; u16 x102; char p104[0x1C]; u16 x120; u16 x122; T t[16]; char p164[0]; u16 x164; } S;
void func_001D71E0(S *s) {
    s32 i;
    u16 m;
    T *t;
    s->x122 = 0;
    for (i = 0; i < 16; i++) {
        m = 1 << i;
        if (s->x164 & m) {
            t = &s->t[i];
            if (!(s->x102 & m)) {
                t->d = 0;
            } else if (s->x120 & m) {
                s->x122 |= m;
                t->d = 1;
                t->c = t->a;
            } else if (--t->c == 0) {
                s->x122 |= m;
                t->d = 2;
                t->c = t->b;
            }
        }
    }
}
