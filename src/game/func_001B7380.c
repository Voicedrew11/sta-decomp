#include "common.h"
typedef struct { Vec p; Vec b; Vec c; f32 x30; f32 x34; u8 x38; u8 pad[7]; } E;
typedef struct { u8 pad[0x10]; Vec pos; u8 pad20[0x5C]; u16 n; u8 pad7E[0xEA]; E *e; } O;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void func_0015B890(s32);
s32 func_0015B980(s32 idx, Vec *a, Vec *b, Vec *c, f32 f0, f32 f1, f32 f2, f32 f3);

void func_001B7380(O *o, s32 idx) {
    Vec c;
    Vec p;
    s32 i;
    E *e;
    sceVu0CopyVector(&c, &o->pos);
    func_0015B890(idx);
    for (i = 0; i < o->n; i++) {
        e = &o->e[i];
        if (!e->x38) {
            sceVu0CopyVector(&p, &e->p);
            sceVu0AddVector(&p, &p, &c);
            p.w = e->p.w;
            func_0015B980(idx, &p, &e->b, &e->c, p.w, e->b.w, e->x30, e->x34);
        }
    }
}
