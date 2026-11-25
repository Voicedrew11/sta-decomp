#include "m2c.h"
typedef struct { u8 hp; u8 rem; u8 c; u8 pad1; } T;
typedef struct { s16 h0; u8 pad[0x7E]; s16 h80[2]; s16 h84; s16 h86; s16 h88; s16 h8A; s16 h8C; u8 pad2[0x12]; T t[1]; } X;
typedef struct { u8 pad[0x3F]; u8 b3F; u8 pad2[0x50]; } S;
X *func_001C9BA0(void);
S *func_001AFC90(void);
s32 func_001CCC10(s16 id, s32 arg1);
void func_001CCF50(s16 *, s32, s32);
void func_001CEDC0(s32);
void func_00131600(s32, s32);
static inline f32 u2f(u32 x) { return x; }
static inline T *getT(s32 i) {
    X *x = func_001C9BA0();
    if (i >= 0 && i < 10 && x->h80[i] != -1) return &x->t[x->h80[i]];
    return 0;
}

void func_001CC450(u32 a0) {
    S *s;
    s32 n;
    s32 i;
    T *t;

    s = func_001AFC90();
    n = func_001C9BA0()->h8C;
    if (n > 0) {
        if (func_001CCC10(n, (1.0f - 0.0007f * u2f(a0)) * u2f(s[n].b3F))) func_00131600(0x141, 0x7F);
        for (i = 0; i <= 6; i++) {
            t = getT(i);
            if (t && t->hp <= 0) {
                func_001CCF50(func_001C9BA0()->h80, i, -1);
                func_001CEDC0(3);
            }
        }
    }
}
