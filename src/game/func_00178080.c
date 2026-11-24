#include "m2c.h"
typedef struct { s32 **a; s32 b; } Ent;
typedef struct { s32 x[4]; } H;
typedef struct { s32 h[3]; s32 size; s8 data[1]; } B;
extern s8 D_001FB908[];
extern s8 D_001FB909[];
extern s8 D_001FB90A[];
extern s8 D_001FB90B[];
extern s32 D_00201CB4;
extern Ent D_0047F080[];
H *func_0014DCD0(s32 *, s32);
static inline s32 getsz(s32 *s) {
    H *v;
    s8 *p;
    B *b;
    if (*s == (D_001FB908[0] | (D_001FB909[0] << 8) | (D_001FB90A[0] << 16) | (D_001FB90B[0] << 24))) {
        return 0;
    }
    v = func_0014DCD0(s, D_00201CB4);
    if (v != NULL) {
b = (B *)(v + 1); return ((s32)b->data + ((b->size + 0xF) & ~0xF)) - (s32)s;
    }
    return -1;
}

void func_00178080(s32 **arg0) {
    s32 n;
    s32 i;
    n = getsz(*arg0);
    if (n != -1) {
        for (i = 0; i < 8; i++) {
            if (D_0047F080[i].a == NULL) {
                D_0047F080[i].a = arg0;
                D_0047F080[i].b = n;
                return;
            }
        }
    }
}
