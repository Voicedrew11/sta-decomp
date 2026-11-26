#include "common.h"
typedef struct { Mtx m; u8 pad[0xF0]; u8 b; u8 pad131[0xF]; } El;
typedef struct { u8 pad[0xC0]; El el[1]; } B;
typedef struct { s32 off; s32 pad[3]; } Ent;
typedef struct { u8 pad[0x10]; u8 **p; u8 pad14[0x2C]; Ent t[1]; } H;
extern Vec D_003139A0;
extern Mtx D_001F2170;
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(void *, void *);

void func_001B3710(H *h, B *base, s32 i, Vec *v, Mtx *m) {
    Ent *t;
    El *el;
    u8 *p;
    s32 e;
    u8 b;
    t = h->t;
    el = &base->el[i];
    p = *h->p;
    b = el->b;
    if (b == 0xFF) {
        sceVu0CopyVector(v, &D_003139A0);
        sceVu0CopyMatrix(m, &D_001F2170);
    } else {
        e = (s32)p + t[b].off;
        if (*(u8 *)(e + 0xF) & 1) {
            sceVu0CopyVector(v, (void *)(e + 0x10));
            sceVu0CopyMatrix(m, el);
        } else {
            sceVu0CopyVector(v, &D_003139A0);
            sceVu0CopyMatrix(m, &D_001F2170);
        }
    }
}
