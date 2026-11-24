#include "m2c.h"
typedef struct { u8 r, g, b, a; } Col;
extern Col D_002020A8;
extern s32 D_0048D0E0[];
extern s32 D_0048D0E4[];
typedef struct { s32 a; void *b; } Buf;
void func_00182C10(s8 *, Buf *);

void func_00183650(s8 *arg0) {
    Buf s __attribute__((aligned(16))) = {0};
    if (D_0048D0E4[0] != 0) {
        if (D_002020A8.a > 0xD0) {
            D_002020A8.a = 0xFF;
        } else {
            D_002020A8.a += 0x20;
        }
        s.a = 1;
        s.b = D_0048D0E0;
        *(s32 *)(arg0 + 0x34) = 0x3F800000;
        *(s32 *)(arg0 + 0x38) = 0x3F800000;
        D_002020A8.r = 0xFF;
        D_002020A8.g = 0xFF;
        D_002020A8.b = 0xFF;
        arg0[0x3C] = D_002020A8.r;
        arg0[0x3D] = D_002020A8.g;
        arg0[0x3E] = D_002020A8.b;
        arg0[0x3F] = (D_002020A8.a * (u8)arg0[0x3F]) / 128;
        func_00182C10(arg0, &s);
        return;
    }
    *(u32 *)&D_002020A8 = 0;
}
