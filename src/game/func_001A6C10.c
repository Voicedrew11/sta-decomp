#include "common.h"
typedef struct { u8 pad[0x5A0]; u8 b0:1; u8 b1:1; u8 b2:1; u8 r:5; } A;
void func_001A7030(A *, s32, s32);
void func_00167580(A *);
void func_001A6C10(A *a) {
    if (a != NULL) {
        if (!a->b0 || !a->b2) return;
        func_001A7030(a, 0, 1);
        func_00167580(a);
        a->b2 = 0;
    }
}

