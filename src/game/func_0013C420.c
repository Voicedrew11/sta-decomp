#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 n:3; u8 r:2; } F;
typedef struct {
    u8 pad[0x5B0];
    F f5B0;
    u8 pad2[0x6B4 - 0x5B1];
    u16 x6B4[2];
} A;
u32 func_0015ED20(void);
void func_0013C360(A *, s16, s32, s32, s32);

void func_0013C420(A *a, u8 kind, s16 v, s32 a3) {
    s16 id = -1;

    switch (kind) {
    case 0:
        if (v == 0 && (a->x6B4[a->f5B0.b0] & 0x400)) {
            v = !((func_0015ED20() & 3) != 0);
        }
        id = (a->f5B0.b0 << 5) + (v | a->f5B0.b2);
        break;
    case 1:
        id = (a->f5B0.b0 << 5) + 2;
        break;
    case 2:
        id = (a->f5B0.b0 << 5) + 3;
        break;
    case 3:
        id = v + ((a->f5B0.b0 << 5) + 4) + a->f5B0.b1 * 2;
        break;
    case 4:
        if (a->f5B0.n < 4) {
            id = a->f5B0.n + ((a->f5B0.b0 << 5) + 8);
        } else {
            id = (a->f5B0.n - 4) + ((a->f5B0.b0 << 5) + 0x10);
        }
        break;
    case 7:
        id = (a->f5B0.b0 << 5) + 0x14;
        break;
    case 8:
        id = (a->f5B0.b0 << 5) + 0x15;
        break;
    case 9:
        id = (a->f5B0.b0 << 5) + 0x16;
        break;
    case 13:
        id = (a->f5B0.b0 << 5) + 0x1A;
        break;
    case 14:
        id = (a->f5B0.b0 << 5) + 0x1B;
        break;
    case 15:
        id = (a->f5B0.b0 << 5) + 0x1C;
        break;
    case 16:
        id = (a->f5B0.b0 + 0xA0) + v * 2;
        break;
    case 0xFF:
        id = v;
        break;
    }
    if (id != -1) func_0013C360(a, id, 5, 0, a3);
}
