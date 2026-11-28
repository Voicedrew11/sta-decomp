#include "common.h"
typedef struct { u8 b[4]; } B4;
typedef struct { u8 p[0x10]; u32 x10; u8 p2[0x18]; u32 x2C; u8 p3[0x18]; u32 x48; u8 p4[0x18]; u32 x64; } O;
B4 Credits_InterpColor_0_001E4D18(void *, void *);
void Credits_EvalColor_1_001E4C90(void *a0, void *a1, O *a2) {
    B4 t;
    u32 c;
    t = Credits_InterpColor_0_001E4D18(a0, a1);
    c = (t.b[3] << 24) | (t.b[0] << 16) | (t.b[1] << 8) | t.b[2];
    a2->x64 = c;
    a2->x48 = c;
    a2->x2C = c;
    a2->x10 = c;
}
