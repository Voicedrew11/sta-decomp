#include "common.h"
typedef struct { u16 a, b, c, n; u8 pad[0x38]; s8 data[1]; } Hd;
typedef struct { u8 pad[0x2A]; u8 x2A; } Ent;
typedef struct { u8 pad[0xB0]; Hd **xB0; } Sub;
typedef struct { u8 pad[0x4B4]; Ent *x4B4[25]; Sub *x518; } A;
typedef struct { u8 pad[0x1F8]; Flags8 f; u8 rest[0x140 - 0x1F9 + 0x140]; } E;
void Enemy_ResetPartAnim_1_001A8670(A *a, u8 i) {
    Hd *h;
    s32 off;
    s32 z;
    s8 *v;
    h = *a->x518->xB0;
    v = h->data;
    off = (a->x4B4[i]->x2A + 1) * 0x140;
    z = 0;
    ((E *)(v + off))->f.f.b4 = z;
    ((E *)(v + (h->n * 0x140 + 0x200) + off))->f.f.b4 = z;
}
