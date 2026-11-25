#include "m2c.h"
typedef struct {
    u8 pad[0x5B4];
    u8 a0:7;
    u8 a7:1;
    u8 lo:4;
    u8 mid:2;
    u8 hi:2;
} S;

void func_0013E4F0(S *s, u8 a) {
    s->lo |= a;
    if (a) s->a7 = 1;
    if ((u8)a & 1) s->mid = 0;
    if ((u8)a & 2) s->mid = 1;
    if ((u8)a & 4) s->mid = 2;
    if ((u8)a & 8) s->mid = 3;
}
