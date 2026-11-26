#include "m2c.h"
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad1C[0x38]; } E;
typedef struct { u8 pad[0x70]; u16 n; u8 pad72[0x26]; u32 x98[2]; u32 xA0[39]; E *x13C; } X;
typedef struct { u8 pad[8]; u8 x8; u8 pad9[7]; u16 x10; u8 pad12[6]; u8 x18; } S;
X *func_001B19A0(u8);

void func_0017C930(S *s) {
    X *x;
    u32 i;
    u16 v;
    u32 bit;
    u32 n;
    E *e;
    x = func_001B19A0(s->x8);
    if (x) {
        i = 0;
        n = x->n;
        if (i < n) {
            e = x->x13C;
            do {
                v = e->x1A;
                if (v == s->x10) {
                    i = (u32)v >> 5;
                    bit = 1 << ((s32)v % 32);
                    if (s->x18) {
                        x->xA0[i] |= bit;
                        x->x98[i] &= ~bit;
                        return;
                    } else {
                        x->xA0[i] &= ~bit;
                        return;
                    }
                }
                i++;
                e++;
            } while (i < n);
        }
    }
}

