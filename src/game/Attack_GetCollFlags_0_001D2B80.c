#include "common.h"
typedef struct { u8 pad[0xC]; Flags8 c; Flags8 d; } S;

u8 Attack_GetCollFlags_0_001D2B80(S *a) {
    u8 r = 0;
    if (a->c.f.b4) r |= 2;
    if (a->c.f.b5) r |= 4;
    if (a->c.f.b6) r |= 8;
    if (a->c.f.b7) r |= 0x10;
    if (a->d.f.b0) r |= 0x20;
    if (a->d.f.b1) r |= 0x40;
    if (a->d.f.b2) r |= 0x80;
    return r;
}
