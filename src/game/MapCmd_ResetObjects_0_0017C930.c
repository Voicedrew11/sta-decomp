#include "m2c.h"
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad1C[0x38]; } E;
typedef struct { u8 pad[0x70]; u16 n; u8 pad72[0x26]; u32 x98[2]; u32 xA0[39]; E *x13C; } X;
typedef struct { u8 pad[8]; u8 x8; u8 pad9[7]; u16 x10; u8 pad12[6]; u8 x18; } S;
X *MapObj_Find_1_001B19A0(u8);
void MapCmd_ResetObjects_0_0017C930(S *s) {
    X *x;
    u32 i;
    E *e;
    x = MapObj_Find_1_001B19A0(s->x8);
    if (x) {
        i = 0;
        if (i < x->n) {
            e = x->x13C;
            do {
                if (e->x1A == s->x10) {
                    u32 v = e->x1A;
                    u32 w = v >> 5;
                    u32 bit = 1 << ((s32)v % 32);
                    if (s->x18) {
                        x->xA0[w] |= bit;
                        x->x98[w] &= ~bit;
                        return;
                    } else {
                        x->xA0[w] &= ~bit;
                        return;
                    }
                }
                i++;
                e++;
            } while (i < x->n);
        }
    }
}

