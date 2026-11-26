#include "common.h"
typedef struct { u32 t:24; u32 h:8; } T;
typedef struct { s8 pad[0x30]; T t[7]; s8 pad2[0x50 - 0x4C]; s32 c[7]; } B;
B *func_001C9BA0(void);
void func_001CE2D0(void) {
    B *b = func_001C9BA0();
    T *t;
    s32 *c;
    u32 i;
    s32 *p;
    u32 j;
    u32 n;
    u32 w;
    c = b->c;
    t = b->t;
    i = 0;
    p = c;
    do {
        if (*p != 0) *p = *p - 1;
        i++;
        p++;
    } while (i < 7);
    j = 0;
    do {
        n = t->t; w = *(u32 *)t >> 24;
        if (n != 0) {
            n--;
            *(u32 *)t = n | (w << 24);
            if (n == 0) {
                *c = 150;
                *(u32 *)t = 0;
            }
        }
        j++;
        t++;
        c++;
    } while (j < 7);
}


