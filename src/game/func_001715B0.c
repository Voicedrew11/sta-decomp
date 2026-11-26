#include "common.h"
typedef struct { u8 pad[6]; u16 n; u8 p8[0x38]; u8 d[1]; } Hd;
typedef struct { u8 pad[0xB0]; s32 off; } E;
typedef struct { Hd *h; u8 *p; } O;
extern s32 D_00201F2C;
E *func_001715B0(O *o) {
    s32 k = D_00201F2C; Hd *h; E *e; if (o == NULL || (h = o->h) == NULL) return NULL;
    e = (E *)((s32)h + 0x40 + k * (h->n * 0x140 + 0x200)); e->off = o->p - (u8 *)h; return e;
}
