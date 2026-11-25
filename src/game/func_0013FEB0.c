#include "m2c.h"
#include "common.h"
typedef struct { u8 pad[0x22]; u16 x22; u16 x24; u8 pad2[0x54-0x26]; } Ent;
typedef struct { u8 pad[0x13C]; Ent *ents; } Tbl;
typedef struct { Tbl *tbl; } Hdr;
typedef struct { u8 pad[0x4A8]; Hdr *x4A8; u16 x4AC; u8 p4AE[0xF3]; Flags8 f5A1; } O;
static inline f32 u2f(u32 x) { return x; }

void func_0013FEB0(O *o, f32 *a1, f32 *a2) {
    f32 x;
    f32 y;
    Hdr *pp;
    u16 idx;
    Ent *q;

    y = x = 4000.0f;
    if (!o->f5A1.f.b3) {
        idx = o->x4AC;
        pp = o->x4A8;
        q = pp ? &pp->tbl->ents[idx] : NULL;
        if (q) {
            x = u2f(q->x22);
            y = u2f(q->x24);
        }
    }
    if (a1) *a1 = x;
    if (a2) *a2 = y;
}
