#include "m2c.h"
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[2]; s16 h84; s16 h86; s16 h88; s16 h8A; s16 h8C; u8 pad8E[6]; u8 x94; u8 pad95[0xB]; T t[1]; } X;
X *func_001C9BA0(void);
s32 func_001CCC10(s16 id, s32 arg1);
void func_001CCF50(s16 *, s32, s32);
void func_001CEDC0(s32);
void func_00131600(s32, s32);
static inline T *getT(s32 i) {
    X *x = func_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}
static inline s16 getH(s32 i) {
    X *x = func_001C9BA0();
    if (i >= 0 && i < 10) return x->h80[i];
    return -1;
}

void func_001CC6F0(s32 a0, s32 a1) {
    X *x;
    s32 k;
    s32 i;
    T *t;

    x = func_001C9BA0();
    if (a1 == 1) k = 1;
    else if (a1 == 0) k = 2;
    else k = 4;
    a0 *= k;
    if (func_001CCC10(getH(x->x94 & 1), a0)) func_00131600(0x141, 0x7F);
    for (i = 0; i <= 6; i++) {
        t = getT(i);
        if (t && t->hp <= 0) {
            func_001CCF50(func_001C9BA0()->h80, i, -1);
            func_001CEDC0(3);
        }
    }
}
