#include "common.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 pad2[0x14]; u16 x20; u8 pad3[0x1A]; u8 x3C; u8 pad4[0x53]; } E;
E *func_001AFC90(void);
s32 func_001848A0(s32 a) { s32 r = 0; E *e = func_001AFC90() + a; if (e == NULL || a == -1) return -1; if (e->xA == 1) { switch (e->x20) { case 5: case 6: r = 0; break; default: r = e->x3C; break; } } else if (e->xA == 2) { r = e->x3C; } return r; }
