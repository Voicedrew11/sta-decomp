#include "m2c.h"
typedef struct { s8 pad[0xA]; u16 xA; s8 pad2[0x29 - 0xC]; u8 type; u8 cnt; s8 pad3[0x90 - 0x2B]; } A;
typedef struct { u8 x0, x1, hi, lo; } BE;
typedef struct { s8 pad[0xA0]; BE e[1]; } B;
A *func_001AFC90(void);
B *func_001C9BA0(void);
void func_001CCE30(void);
static inline s32 getVal(s16 idx) {
    A *a = func_001AFC90();
    B *b = func_001C9BA0();
    if (idx < 0 || idx >= 0x400) return 0;
    if (a[idx].xA == 0 && a[idx].type == 5) return b->e[idx].lo + b->e[idx].hi * a[idx].cnt;
    return 0;
}

void func_001CBA80(s16 idx, u8 n) {
    A *a = func_001AFC90();
    B *b = func_001C9BA0();
    s32 v;
    if (idx < 0 || idx >= 0x400) return;
    if (a[idx].xA == 0 && a[idx].type == 5 && a[idx].cnt > 0) {
        if (n != 0) {
            v = getVal(idx) - n;
            if (v < 0) v = 0;
            b->e[idx].hi = v / a[idx].cnt;
            b->e[idx].lo = v % a[idx].cnt;
            func_001CCE30();
        }
    }
}
