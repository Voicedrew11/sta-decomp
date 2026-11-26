#include "common.h"
typedef struct { s8 pad[0xA]; u16 xA; s8 pad2[0x90 - 0xC]; } A;
typedef struct { u8 x0, x1, hi, lo; } BE;
typedef struct { s8 pad[0xA0]; BE e[1]; } B;
A *func_001AFC90(void);
B *func_001C9BA0(void);
static inline s32 get(s16 i) {
    B *b = func_001C9BA0();
    s32 t;
    if (i < 0 || i >= 0x400) return 0;
    t = b->e[i].hi + 1;
    return !(t < 0) && t < 100;
}
s32 func_001CBE40(s16 i) {
    A *a = func_001AFC90();
    if (i < 0 || i >= 0x400) return 0;
    return get(i);
}

