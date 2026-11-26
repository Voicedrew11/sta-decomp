#include "common.h"
typedef struct { u8 pad[6]; u16 m6; u8 pad8[0x38]; u8 m40[1]; } Mdl;
typedef struct { u8 pad[0xA]; u16 xA; u8 xC; u8 padD; u16 xE; } S;
extern s32 D_00201F2C;
void sceVu0CopyVector(Vec *, void *);
void func_001315A0(s32 a, s32 b, Vec *v);
void func_001D1E80(Mdl *m, u8 id, S *s, f32 *tbl) {
    Vec v;
    f32 *p;
    s8 *base;
    p = tbl + s->xE + s->xC;
    base = (s8 *)(D_00201F2C * (m->m6 * 0x140 + 0x200) + (s32)m->m40);
    sceVu0CopyVector(&v, base + (id + 1) * 0x140 + 0xF0);
    func_001315A0(s->xA, (s32)*p, &v);
}
